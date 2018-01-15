---
title: Diretivas OpenMP | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 0562c263-344c-466d-843e-de830d918940
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 51d501139d0610d670f7d646dc985a694a5b741c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="openmp-directives"></a>Diretivas (OpenMP)
Fornece links para as diretivas usadas na API do OpenMP.  
  
 As seguintes diretivas OpenMP pela linguagem Visual C++:  
  
|Diretiva|Descrição|  
|---------------|-----------------|  
|[atomic](../../../parallel/openmp/reference/atomic.md)|Especifica que um local de memória que será atualizado de forma atômica.|  
|[barrier](../../../parallel/openmp/reference/barrier.md)|Sincroniza todos os threads em uma equipe; todos os threads pausar a barreira, até que todos os threads executem a barreira.|  
|[critical](../../../parallel/openmp/reference/critical.md)|Especifica o código só é executado em um segmento por vez.|  
|[flush](../../../parallel/openmp/reference/flush-openmp.md)|Especifica que todos os threads têm a mesma exibição de memória para todos os objetos compartilhados.|  
|[for](../../../parallel/openmp/reference/for-openmp.md)|Faz com que o trabalho feito um loop dentro de uma região parallel podem ser divididas entre threads.|  
|[master](../../../parallel/openmp/reference/master.md)|Especifica que somente o mestre threadshould executar uma seção do programa.|  
|[ordenados](../../../parallel/openmp/reference/ordered-openmp-directives.md)|Especifica que o código em um em paralelo para loop deve ser executado como um loop sequencial.|  
|[parallel](../../../parallel/openmp/reference/parallel.md)|Define uma região parallel, que é o código que será executado por vários threads em paralelo.|  
|[seções](../../../parallel/openmp/reference/sections-openmp.md)|Identifica as seções de código para ser dividida entre todos os threads.|  
|[single](../../../parallel/openmp/reference/single.md)|Permite que você especifique que uma seção de código deve ser executada em um único thread, não necessariamente o thread principal.|  
|[threadprivate](../../../parallel/openmp/reference/threadprivate.md)|Especifica que uma variável privada para um thread.|  
  
## <a name="see-also"></a>Consulte também  
 [OpenMP](../../../parallel/openmp/openmp-in-visual-cpp.md)   
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)