---
title: HUGE_VAL, _HUGE
ms.date: 11/04/2016
apiname:
- _HUGE
apilocation:
- msvcrt.dll
apitype: DLLExport
f1_keywords:
- _HUGE
- HUGE_VAL
helpviewer_keywords:
- _HUGE constant
- HUGE_VAL constant
- double value
ms.assetid: 3f044b45-02cd-46b2-b1de-87fd0441dd6a
ms.openlocfilehash: 96b05bc2f7b608c31a12493a4f1b71535b13dc4f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50630003"
---
# <a name="hugeval-huge"></a>HUGE_VAL, _HUGE

## <a name="syntax"></a>Sintaxe

```

#include <math.h>

```

## <a name="remarks"></a>Comentários

`HUGE_VAL` é o maior valor duplo representável. Esse valor é retornado por muitas funções matemáticas do tempo de execução quando ocorre um erro. Para algumas funções, é retornado -`HUGE_VAL`. `HUGE_VAL` é definido como `_HUGE`, mas as funções matemáticas do tempo de execução retornam `HUGE_VAL`. Você também deve usar `HUGE_VAL` em seu código para manter a consistência.

## <a name="see-also"></a>Consulte também

[Constantes globais](../c-runtime-library/global-constants.md)