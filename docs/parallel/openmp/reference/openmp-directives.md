---
title: Diretivas OpenMP | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
ms.assetid: 0562c263-344c-466d-843e-de830d918940
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2e8d47e6376b3786b27305e65bdb55f0c292995d
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
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
|[ordered](../../../parallel/openmp/reference/ordered-openmp-directives.md)|Especifica que o código em um em paralelo para loop deve ser executado como um loop sequencial.|  
|[parallel](../../../parallel/openmp/reference/parallel.md)|Define uma região parallel, que é o código que será executado por vários threads em paralelo.|  
|[sections](../../../parallel/openmp/reference/sections-openmp.md)|Identifica as seções de código para ser dividida entre todos os threads.|  
|[single](../../../parallel/openmp/reference/single.md)|Permite que você especifique que uma seção de código deve ser executada em um único thread, não necessariamente o thread principal.|  
|[threadprivate](../../../parallel/openmp/reference/threadprivate.md)|Especifica que uma variável privada para um thread.|  
  
## <a name="see-also"></a>Consulte também  
 [OpenMP](../../../parallel/openmp/openmp-in-visual-cpp.md)   
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)