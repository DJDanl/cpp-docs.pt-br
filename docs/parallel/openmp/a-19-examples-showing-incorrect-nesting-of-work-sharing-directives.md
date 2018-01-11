---
title: Exemplos A.19 mostrando aninhamento incorreto de diretivas de compartilhamento de trabalho | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 906e900d-9259-44d6-a095-c1ba9135d269
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8a3f8a4e1ca62a77c16dafedd0921ca842d7a048
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="a19---examples-showing-incorrect-nesting-of-work-sharing-directives"></a>A.19   Exemplos que mostram o aninhamento incorreto de diretivas de compartilhamento do trabalho
Os exemplos nesta seção ilustram as regras de aninhamento de diretiva. Para obter mais informações sobre o aninhamento de diretiva, consulte [seção 2.9](../../parallel/openmp/2-9-directive-nesting.md) na página 33.  
  
 O exemplo a seguir está em conformidade porque interna e externa `for` diretivas forem aninhadas e associar ao mesmo `parallel` diretiva:  
  
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
  
 A seguinte versão dinamicamente aninhada do exemplo anterior também será incompatível:  
  
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
  
 O exemplo a seguir está em conformidade porque a `for` e `single` diretivas forem aninhadas e eles ligam à mesma região paralela:  
  
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
  
 O exemplo a seguir está em conformidade porque um `barrier` diretiva dentro de um `for` pode resultar em deadlock:  
  
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
  
 O exemplo a seguir está em conformidade porque a `barrier` resulta em deadlock devido ao fato de que apenas um thread por vez pode inserir a seção crítica:  
  
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
  
 O exemplo a seguir está em conformidade porque a `barrier` resulta em deadlock devido ao fato de que apenas um thread é executado o `single` seção:  
  
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