---
title: 3.2.4 funções omp_unset_lock e omp_unset_nest_lock funções | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 5357e43e-a7c0-41d7-b529-3f7d15da8b11
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 426ac0a5ff974e486f70eed2965fdc27d5acc941
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46419096"
---
# <a name="324-ompunsetlock-and-ompunsetnestlock-functions"></a>3.2.4 funções omp_unset_lock e omp_unset_nest_lock

Essas funções fornecem os meios de propriedade de um bloqueio de liberação. O formato é o seguinte:

```
#include <omp.h>
void omp_unset_lock(omp_lock_t *lock);
void omp_unset_nest_lock(omp_nest_lock_t *lock);
```

O argumento para cada uma dessas funções deve apontar para uma variável de bloqueio inicializado pelo thread de execução da função de propriedade. O comportamento será indefinido se o thread possui o bloqueio.

Para obter um bloqueio simple, o `omp_unset_lock` função libera o thread de execução da função de propriedade do bloqueio.

Para obter um bloqueio empilhável, o `omp_unset_nest_lock` função diminui a contagem de aninhamento e versões, o thread de execução da função de propriedade do bloqueio, se a contagem resultante é zero.