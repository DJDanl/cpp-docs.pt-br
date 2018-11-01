---
title: Estrutura SYSTEMTIME
ms.date: 11/04/2016
f1_keywords:
- SYSTEMTIME
helpviewer_keywords:
- SYSTEMTIME structure [MFC]
ms.assetid: 9aaef4d6-de79-4fa1-8158-86b245ef5bff
ms.openlocfilehash: b46482a9f4eb0165b72d74cb7d69e96e2a15e953
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50559036"
---
# <a name="systemtime-structure"></a>Estrutura SYSTEMTIME

O `SYSTEMTIME` estrutura representa uma data e hora usando membros individuais para o mês, dia, ano, dia da semana, hora, minuto, segundo e milissegundo.

## <a name="syntax"></a>Sintaxe

```
typedef struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME;
```

#### <a name="parameters"></a>Parâmetros

*wYear*<br/>
O ano atual.

*. Wano*<br/>
O mês atual; Janeiro é 1.

*Wmês*<br/>
O dia atual da semana; Domingo é 0, segunda-feira é 1 e assim por diante.

*Wdiadasemana*<br/>
Dia do mês atual.

*Whora*<br/>
A hora atual.

*Wminuto*<br/>
O minuto atual.

*Wsegundo*<br/>
O segundo atual.

*Wmilissegundos*<br/>
O milissegundo atual.

## <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_Utilities#39](../../mfc/codesnippet/cpp/systemtime-structure1_1.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** WinBase

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CTime::CTime](../../atl-mfc-shared/reference/ctime-class.md#ctime)

