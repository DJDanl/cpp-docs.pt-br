---
title: Constantes (_locking)
ms.date: 11/04/2016
f1_keywords:
- _LK_RLCK
- _LK_NBLCK
- _LK_LOCK
- _LK_NBRLCK
- _LK_UNLCK
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
ms.openlocfilehash: 8cfc1f933179e043f464a69f3ac5cf4ca25763e0
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88830820"
---
# <a name="_locking-constants"></a>Constantes (_locking)

## <a name="syntax"></a>Sintaxe

```
#include <sys/locking.h>
```

## <a name="remarks"></a>Comentários

O argumento *mode* na chamada para a função `_locking` especifica a ação de bloqueio que será executada.

O argumento *mode* deve ser uma das constantes de manifesto a seguir.

|Valor|Descrição|
|-|-|
| `_LK_LOCK`  | Bloqueia os bytes especificados. Se os bytes não puderem ser bloqueados, a função tentará novamente após 1 segundo. Se, após 10 tentativas, os bytes não puderem ser bloqueados, a função retornará um erro.  |
| `_LK_RLCK`  | Mesmo que `_LK_LOCK`.  |
|`_LK_NBLCK`  | Bloqueia os bytes especificados. Se os bytes não puderem ser bloqueados, a função retornará um erro.  |
| `_LK_NBRLCK`  | Mesmo que `_LK_NBLCK`.  |
| `_LK_UNLCK`  | Desbloqueia os bytes especificados. (Os bytes devem ter sido protegidos anteriormente.)  |

## <a name="see-also"></a>Confira também

[_locking](../c-runtime-library/reference/locking.md)<br/>
[Constantes globais](../c-runtime-library/global-constants.md)
