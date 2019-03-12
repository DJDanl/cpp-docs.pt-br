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
ms.openlocfilehash: eef065ac4fcedf13f3a5d54d4df0563fd04ef965
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57750670"
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
