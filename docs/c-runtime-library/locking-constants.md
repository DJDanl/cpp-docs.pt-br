---
title: Constantes _locking | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- _LK_RLCK
- _LK_NBLCK
- _LK_LOCK
- _LK_NBRLCK
- _LK_UNLCK
dev_langs:
- C++
helpviewer_keywords:
- LK_UNLCK constant
- LK_NBRLCK constant
- _LK_NBRLCK constant
- _LK_NBLCK constant
- _LK_LOCK constant
- LK_NBLCK constant
- _LK_UNLCK constant
- LK_RLCK constant
- _LK_RLCK constant
- LK_LOCK constant
ms.assetid: c3dc92c8-60e3-4d29-9f50-5d217627c8ad
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: abf776ab72d692be6d573803353f35946df145ec
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46031904"
---
# <a name="locking-constants"></a>Constantes (_locking)

## <a name="syntax"></a>Sintaxe

```
#include <sys/locking.h>
```

## <a name="remarks"></a>Comentários

O argumento *mode* na chamada para a função `_locking` especifica a ação de bloqueio que será executada.

O argumento *mode* deve ser uma das constantes de manifesto a seguir.

|||
|-|-|
| `_LK_LOCK`  | Bloqueia os bytes especificados. Se os bytes não puderem ser bloqueados, a função tentará novamente após 1 segundo. Se, após 10 tentativas, os bytes não puderem ser bloqueados, a função retornará um erro.  |
| `_LK_RLCK`  | Mesmo que `_LK_LOCK`.  |
|`_LK_NBLCK`  | Bloqueia os bytes especificados. Se os bytes não puderem ser bloqueados, a função retornará um erro.  |
| `_LK_NBRLCK`  | Mesmo que `_LK_NBLCK`.  |
| `_LK_UNLCK`  | Desbloqueia os bytes especificados. (Os bytes devem ter sido protegidos anteriormente.)  |

## <a name="see-also"></a>Consulte também

[_locking](../c-runtime-library/reference/locking.md)<br/>
[Constantes globais](../c-runtime-library/global-constants.md)