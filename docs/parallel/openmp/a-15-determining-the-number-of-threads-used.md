---
title: "A.15 para determinar o número de Threads usados | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 026bb59a-f668-40db-a7cb-69a1bae83d2d
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e8b7fb8cf6218863287d582a097cb43b399cff07
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="a15---determining-the-number-of-threads-used"></a>A.15  Determinando o número de threads usados
Considere o seguinte exemplo incorreto (para [seção 3.1.2](../../parallel/openmp/3-1-2-omp-get-num-threads-function.md) na página 37):  
  
```  
np = omp_get_num_threads(); // misplaced   
#pragma omp parallel for schedule(static)  
    for (i=0; i<np; i++)  
        work(i);  
```  
  
 O `omp_get_num_threads()` chamada retorna 1 na seção serial do código, portanto *np* sempre será igual a 1 no exemplo anterior. Para determinar o número de threads que será implantado para a região paralela, a chamada deve ser dentro da região paralela.  
  
 O exemplo a seguir mostra como reconfigurar o programa sem incluir uma consulta para o número de threads:  
  
```  
#pragma omp parallel private(i)  
{  
    i = omp_get_thread_num();  
    work(i);  
}  
```