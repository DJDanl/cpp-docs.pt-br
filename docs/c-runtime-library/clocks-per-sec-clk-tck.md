---
title: CLOCKS_PER_SEC, CLK_TCK
ms.date: 11/04/2016
f1_keywords:
- CLOCKS_PER_SEC
- CLK_TCK
helpviewer_keywords:
- CLOCKS_PER_SEC
- CLK_TCK constant
ms.assetid: bc285106-383d-44cb-91bf-276ad7de57bf
ms.openlocfilehash: a604425809f43be238cbcc7b9148782bb937e00f
ms.sourcegitcommit: a1fad0a266b20b313364a74b16c9ac45d089b1e9
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/11/2019
ms.locfileid: "54220355"
---
# <a name="clockspersec-clktck"></a>CLOCKS_PER_SEC, CLK_TCK

## <a name="syntax"></a>Sintaxe

```
#include <time.h>
```

## <a name="remarks"></a>Comentários

O tempo em segundos é o valor retornado pela função `clock`, dividido por `CLOCKS_PER_SEC`. `CLK_TCK` é equivalente, mas considerada obsoleta.

## <a name="see-also"></a>Consulte também

[clock](../c-runtime-library/reference/clock.md)<br/>
[Constantes globais](../c-runtime-library/global-constants.md)
