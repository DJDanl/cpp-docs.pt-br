---
title: Diretivas OpenMP | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
dev_langs:
- C++
ms.assetid: 0562c263-344c-466d-843e-de830d918940
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 983a71920e9e7ce390ab8c64e81886db0d459450
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46389441"
---
# <a name="openmp-directives"></a>Diretivas (OpenMP)

Fornece links para as diretivas usadas na API OpenMP.

Visual C++ suporta as seguintes diretivas OpenMP:

|Diretiva|Descrição|
|---------------|-----------------|
|[atomic](../../../parallel/openmp/reference/atomic.md)|Especifica que um local de memória que será atualizado atomicamente.|
|[barrier](../../../parallel/openmp/reference/barrier.md)|Sincroniza todos os threads em uma equipe; todos os threads pausar a barreira, até que todos os threads executem a barreira.|
|[critical](../../../parallel/openmp/reference/critical.md)|Especifica que o código só é executado em um thread por vez.|
|[flush](../../../parallel/openmp/reference/flush-openmp.md)|Especifica que todos os threads têm a mesma exibição de memória para todos os objetos compartilhados.|
|[for](../../../parallel/openmp/reference/for-openmp.md)|Faz com que o trabalho feito um loop for dentro de uma região paralela para ser dividido entre threads.|
|[master](../../../parallel/openmp/reference/master.md)|Especifica que somente o mestre threadshould executar uma seção do programa.|
|[Ordenado](../../../parallel/openmp/reference/ordered-openmp-directives.md)|Especifica que o código em um em paralelo para loop deve ser executado como um loop sequencial.|
|[parallel](../../../parallel/openmp/reference/parallel.md)|Define uma região paralela, que é um código que será executado por vários threads em paralelo.|
|[Seções](../../../parallel/openmp/reference/sections-openmp.md)|Identifica as seções de código a ser dividida entre todos os threads.|
|[single](../../../parallel/openmp/reference/single.md)|Permite que você especifique que uma seção de código deve ser executada em um único thread, não necessariamente o thread mestre.|
|[threadprivate](../../../parallel/openmp/reference/threadprivate.md)|Especifica que uma variável privada em um thread.|

## <a name="see-also"></a>Consulte também

[OpenMP](../../../parallel/openmp/openmp-in-visual-cpp.md)<br/>
[Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)