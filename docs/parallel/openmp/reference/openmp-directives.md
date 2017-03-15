---
title: Diretivas (OpenMP) | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 0562c263-344c-466d-843e-de830d918940
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: e84a0c28ba5db783b3de131351b65172095999d5
ms.lasthandoff: 02/25/2017

---
# <a name="openmp-directives"></a>Diretivas (OpenMP)
Fornece links para diretivas usadas na API do OpenMP.  
  
 Visual C++ suporta as seguintes diretivas OpenMP:  
  
|Diretiva|Descrição|  
|---------------|-----------------|  
|[atomic](../../../parallel/openmp/reference/atomic.md)|Especifica que um local de memória que será atualizado automaticamente.|  
|[barreira](../../../parallel/openmp/reference/barrier.md)|Sincroniza todos os threads em uma equipe; todos os threads pausar a barreira, até que todos os threads executem a barreira.|  
|[crítico](../../../parallel/openmp/reference/critical.md)|Especifica que o código somente é executado em um thread por vez.|  
|[flush](../../../parallel/openmp/reference/flush-openmp.md)|Especifica que todos os threads têm a mesma exibição de memória para todos os objetos compartilhados.|  
|[for](../../../parallel/openmp/reference/for-openmp.md)|Faz com que o trabalho feito um loop for dentro de uma região paralela seja dividido entre threads.|  
|[mestre](../../../parallel/openmp/reference/master.md)|Especifica que somente o mestre threadshould executar uma seção do programa.|  
|[ordenado](../../../parallel/openmp/reference/ordered-openmp-directives.md)|Especifica o código em um em paralelo para loop deve ser executado como um loop sequencial.|  
|[paralelo](../../../parallel/openmp/reference/parallel.md)|Define uma região paralela, que é o código que será executado por vários threads em paralelo.|  
|[seções](../../../parallel/openmp/reference/sections-openmp.md)|Identifica as seções de código para ser dividida entre todos os threads.|  
|[único](../../../parallel/openmp/reference/single.md)|Permite especificar que uma seção de código deve ser executada em um único thread, não necessariamente o thread principal.|  
|[threadprivate](../../../parallel/openmp/reference/threadprivate.md)|Especifica que uma variável privada para um thread.|  
  
## <a name="see-also"></a>Consulte também  
 [OpenMP](../../../parallel/openmp/openmp-in-visual-cpp.md)   
 [Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)
