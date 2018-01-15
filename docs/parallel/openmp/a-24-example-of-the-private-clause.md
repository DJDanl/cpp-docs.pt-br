---
title: "Exemplo A.24 da cláusula privada | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: f90a5b49-81ff-4746-ae03-37bbd33f6c08
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1e0abd7aa296a16e54e2ec5e5ce7b2c49a93c45e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="a24---example-of-the-private-clause"></a>A.24   Exemplo da cláusula private
O `private` cláusula ([seção 2.7.2.1](../../parallel/openmp/2-7-2-1-private.md) na página 25) de uma região parallel tem efeito somente para a extensão de léxica da região, e não para a extensão dinâmica da região.  Portanto, no exemplo a seguir, quaisquer usos da variável *um* dentro a `for` loop na rotina *f* refere-se a uma cópia privada de *um*, enquanto um uso em rotina *g* refere-se ao global *um*.  
  
```  
int a;  
  
void f(int n)   
{  
    a = 0;  
  
    #pragma omp parallel for private(a)  
    for (int i=1; i<n; i++)   
    {  
        a = i;  
        g(i, n);  
        d(a);     // Private copy of "a"  
        ...  
    }  
    ...  
  
void g(int k, int n)   
{  
    h(k,a); // The global "a", not the private "a" in f  
}  
```