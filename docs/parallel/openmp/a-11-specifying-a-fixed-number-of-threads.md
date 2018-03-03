---
title: "A. 11 especificando um número fixo de Threads | Microsoft Docs"
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
ms.assetid: 1d06b142-4c35-44b8-994b-20f2aed5462b
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 72c8aca2b90f021771ba9f9fc8a86d784ffe24a9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="a11---specifying-a-fixed-number-of-threads"></a>A.11   especificando um número fixo de threads
Alguns programas dependem de um número fixo previamente especificado de threads para executar corretamente.  Como a configuração padrão para o ajuste dinâmico do número de threads é definido pela implementação, esses programas podem optar por desativar o recurso de threads dinâmico e definir o número de threads explicitamente para garantir a portabilidade. O exemplo a seguir mostra como fazer isso usando `omp_set_dynamic` ([seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39), e `omp_set_num_threads` ([seção 3.1.1](../../parallel/openmp/3-1-1-omp-set-num-threads-function.md) na página 36):  
  
```  
omp_set_dynamic(0);  
omp_set_num_threads(16);  
#pragma omp parallel shared(x, npoints) private(iam, ipoints)  
{  
    if (omp_get_num_threads() != 16)   
      abort();  
    iam = omp_get_thread_num();  
    ipoints = npoints/16;  
    do_by_16(x, iam, ipoints);  
}  
```  
  
 Neste exemplo, o programa é executado corretamente apenas se ele for executado por 16 threads. Se a implementação não é capaz de dar suporte a 16 threads, o comportamento deste exemplo é definido pela implementação.  
  
 Observe que o número de threads de execução de uma região parallel permanece constante durante uma região parallel, independentemente dos threads dinâmicos de configuração. O mecanismo de threads dinâmico determina o número de threads a ser usado no início da região de dados paralela e mantém constante para a duração da região.