---
title: barrier | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- barrier
dev_langs:
- C++
helpviewer_keywords:
- barrier OpenMP directive
ms.assetid: 5c73ad4f-c768-443a-8f9e-4fd8bc2253c7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c220106d62bf65505c9c5b48085a9ee3e67fe0cb
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46415025"
---
# <a name="barrier"></a>barrier

Sincroniza todos os threads em uma equipe; todos os threads pausar a barreira, até que todos os threads executem a barreira.

## <a name="syntax"></a>Sintaxe

```
#pragma omp barrier
```

## <a name="remarks"></a>Comentários

O `barrier` diretiva dá suporte a nenhuma cláusulas OpenMP.

Para obter mais informações, consulte [2.6.3 diretiva barrier](../../../parallel/openmp/2-6-3-barrier-directive.md).

## <a name="example"></a>Exemplo

Para obter um exemplo de como usar `barrier`, consulte [mestre](../../../parallel/openmp/reference/master.md).

## <a name="see-also"></a>Consulte também

[Diretivas](../../../parallel/openmp/reference/openmp-directives.md)