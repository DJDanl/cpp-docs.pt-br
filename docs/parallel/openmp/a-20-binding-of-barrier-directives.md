---
title: "Associação de A.20 das diretivas de barreira | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: a3fdcc26-6873-429b-998e-de451401483b
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5b8cc2799f0aea9e75b3aad44d3cfa9e3f5e7de4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="a20---binding-of-barrier-directives"></a>A.20  Vinculação de diretivas barrier
A associação de diretiva regras chamada para um **barreira** diretiva para ligar para o mais próximo de circunscrição `parallel` diretiva. Para obter mais informações sobre associação de diretiva, consulte [seção 2.8](../../parallel/openmp/2-8-directive-binding.md) na página 32.  
  
 No exemplo a seguir, a chamada de *principal* para *sub2* é compatível porque o **barreira** (em *sub3*) vincula a região parallel em *sub2*. A chamada de *principal* para *sub1* é compatível porque o **barreira** associa a região parallel na sub-rotina *sub2*.  A chamada de *principal* para *sub3* é compatível porque o **barreira** não associar a qualquer região paralela e será ignorado. Observe também que o **barreira** sincroniza apenas a equipe de threads na região parallel delimitador e não todos os threads criados no *sub1*.  
  
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