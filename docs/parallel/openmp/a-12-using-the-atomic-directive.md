---
title: "12, usando a diretiva atômica | Microsoft Docs"
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
ms.assetid: d3ba3c87-413d-4efa-8a45-8a7f28ab0164
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9aa619d9bbe635a41d15a39d6c05780a4416520e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="a12---using-the-atomic-directive"></a>A.12   Usando a diretiva atomic
O exemplo a seguir evita as condições de corrida (atualizações simultâneas de um elemento de *x* por vários threads) usando o `atomic` diretiva ([seção 2.6.4](../../parallel/openmp/2-6-4-atomic-construct.md) na página 19):  
  
```  
#pragma omp parallel for shared(x, y, index, n)  
    for (i=0; i<n; i++)   
    {  
        #pragma omp atomic  
            x[index[i]] += work1(i);  
        y[i] += work2(i);  
    }  
```  
  
 A vantagem de usar o `atomic` diretiva neste exemplo é que ele permite que as atualizações de dois elementos diferentes de x para ocorrer em paralelo. Se um `critical` diretiva ([seção 2.6.2](../../parallel/openmp/2-6-2-critical-construct.md) na página 18) foram usadas em vez disso, em seguida, todas as atualizações para os elementos de *x* seria executado em série (mas não em qualquer garantia de ordem).  
  
 Observe que o `atomic` diretiva se aplica somente à instrução C ou C++ imediatamente após ele.  Como resultado, os elementos de *y* não são atualizadas atomicamente neste exemplo.