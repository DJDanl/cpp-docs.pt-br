---
title: "Uso A.28 de num_threads cláusula | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 26238da1-902c-49b4-9559-0fbc9eaf7f36
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 119ff2c78a90dc36baab38925b28ec6b2ff844dd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="a28---use-of-numthreads-clause"></a>A.28   Uso da cláusula num_threads
O exemplo a seguir demonstra o `num_threads` cláusula ([seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página 8). A região parallel for executado com um máximo de 10 threads.  
  
```  
#include <omp.h>  
main()  
{  
    omp_set_dynamic(1);  
    ...  
    #pragma omp parallel num_threads(10)  
    {  
        ... parallel region ...  
    }  
}  
```