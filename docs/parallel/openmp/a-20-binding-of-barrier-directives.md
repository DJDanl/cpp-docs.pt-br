---
title: "A.20   Binding of barrier Directives | Microsoft Docs"
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
ms.assetid: a3fdcc26-6873-429b-998e-de451401483b
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# A.20   Binding of barrier Directives
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Regras de ligação diretriz chamada para um  **barreira** diretiva para vincular a colocar mais próximo `parallel` diretiva.  Para obter mais informações sobre vinculação de diretiva, consulte  [seção 2.8](../../parallel/openmp/2-8-directive-binding.md) na página 32.  
  
 No exemplo a seguir, a chamada de  *principal* para  *sub2* é compatível com porque o  **barreira** \(em  *sub3*\) é vinculado à região paralela em  *sub2*.  A chamada de  *principal* para  *sub1* é compatível com porque o  **barreira** vincula\-se à região paralela na sub\-rotina  *sub2*.  A chamada de  *principal* para  *sub3* é compatível com porque o  **barreira** não se vincula a qualquer região paralela e será ignorado.  Observe também que o  **barreira** sincroniza somente a equipe de threads na região paralela delimitador e nem todos os threads criados na  *sub1*.  
  
```  
int main()  
{  
    sub1(2);  
    sub2(2);  
    sub3(2);  
}  
  
void sub1(int n)  
{  
    int i;  
    #pragma omp parallel private(i) shared(n)  
    {  
        #pragma omp for  
        for (i=0; i<n; i++)  
            sub2(i);  
    }  
}  
  
void sub2(int k)  
{  
     #pragma omp parallel shared(k)  
     sub3(k);  
}  
  
void sub3(int n)  
{  
    work(n);  
    #pragma omp barrier  
    work(n);  
}  
```