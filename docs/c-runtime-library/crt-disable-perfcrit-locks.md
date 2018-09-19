---
title: _CRT_DISABLE_PERFCRIT_LOCKS | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- _CRT_DISABLE_PERFCRIT_LOCKS
- CRT_DISABLE_PERFCRIT_LOCKS
dev_langs:
- C++
helpviewer_keywords:
- CRT_DISABLE_PERFCRIT_LOCKS constant
- _CRT_DISABLE_PERFCRIT_LOCKS constant
ms.assetid: 36cc2d86-cdb1-4b2b-a03c-c0d3818e7c6f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bd01cbddac128e2369971d07320ff95986d822f9
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46053889"
---
# <a name="crtdisableperfcritlocks"></a>_CRT_DISABLE_PERFCRIT_LOCKS

Desabilita o bloqueio de desempenho crítico em operações de E/S.

## <a name="syntax"></a>Sintaxe

```
#define _CRT_DISABLE_PERFCRIT_LOCKS
```

## <a name="remarks"></a>Comentários

A definição desse símbolo pode melhorar o desempenho em programas delimitados por E/S de single-thread, forçando todas as operações de E/S a assumir um modelo de single-thread. Para obter mais informações, consulte [Desempenho de bibliotecas multithread](../c-runtime-library/multithreaded-libraries-performance.md).

## <a name="see-also"></a>Consulte também

[Constantes globais](../c-runtime-library/global-constants.md)