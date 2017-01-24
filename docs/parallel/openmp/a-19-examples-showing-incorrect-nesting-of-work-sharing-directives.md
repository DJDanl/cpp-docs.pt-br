---
title: "A.19   Examples Showing Incorrect Nesting of Work-sharing Directives | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 906e900d-9259-44d6-a095-c1ba9135d269
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# A.19   Examples Showing Incorrect Nesting of Work-sharing Directives
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os exemplos nesta seção ilustram as regras de diretivas de aninhamento.  Para obter mais informações sobre o aninhamento de diretiva, consulte  [seção 2,9](../../parallel/openmp/2-9-directive-nesting.md) na página 33.  
  
 O exemplo a seguir é incompatível porque internas e externas `for` diretivas estão aninhadas e ligar para o mesmo `parallel` diretiva:  
  
```  
void wrong1(int n)  
{  
  #pragma omp parallel default(shared)  
  {  
      int i, j;  
      #pragma omp for  
      for (i=0; i<n; i++) {  
          #pragma omp for  
              for (j=0; j<n; j++)  
                 work(i, j);  
     }  
   }  
}  
```  
  
 A seguinte versão dinamicamente aninhada do exemplo anterior também é incompatível:  
  
```  
void wrong2(int n)  
{  
  #pragma omp parallel default(shared)  
  {  
    int i;  
    #pragma omp for  
      for (i=0; i<n; i++)  
        work1(i, n);  
  }  
}  
  
void work1(int i, int n)  
{  
  int j;  
  #pragma omp for  
    for (j=0; j<n; j++)  
      work2(i, j);  
}  
```  
  
 O exemplo a seguir é incompatível porque a `for` e `single` diretivas estão aninhadas e eles ligam para a mesma região paralela:  
  
```  
void wrong3(int n)  
{  
  #pragma omp parallel default(shared)  
  {  
    int i;  
    #pragma omp for  
      for (i=0; i<n; i++) {  
        #pragma omp single  
          work(i);  
      }  
  }  
}  
```  
  
 O exemplo a seguir é incompatível porque um `barrier` diretiva dentro de um `for` pode resultar em um deadlock:  
  
```  
void wrong4(int n)  
{  
  #pragma omp parallel default(shared)  
  {  
    int i;  
    #pragma omp for  
      for (i=0; i<n; i++) {  
        work1(i);  
        #pragma omp barrier  
        work2(i);  
      }  
  }  
}  
```  
  
 O exemplo a seguir é incompatível porque a `barrier` resulta em deadlock devido ao fato de que apenas um thread por vez pode inserir a seção crítica:  
  
```  
void wrong5()  
{  
  #pragma omp parallel  
  {  
    #pragma omp critical  
    {  
       work1();  
       #pragma omp barrier  
       work2();  
    }  
  }  
}  
```  
  
 O exemplo a seguir é incompatível porque a `barrier` resulta em deadlock devido ao fato de que apenas um segmento executa o `single` seção:  
  
```  
void wrong6()  
{  
  #pragma omp parallel  
  {  
    setup();  
    #pragma omp single  
    {  
      work1();  
      #pragma omp barrier  
      work2();  
    }  
    finish();  
  }  
}  
```