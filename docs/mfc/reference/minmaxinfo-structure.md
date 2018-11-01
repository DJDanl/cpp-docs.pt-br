---
title: Estrutura MINMAXINFO
ms.date: 11/04/2016
f1_keywords:
- MINMAXINFO
helpviewer_keywords:
- MINMAXINFO structure [MFC]
ms.assetid: be6fb578-f98a-4581-9ada-be9df308ed2f
ms.openlocfilehash: 11f55b1756623626769e21c006543b6993607b08
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50517833"
---
# <a name="minmaxinfo-structure"></a>Estrutura MINMAXINFO

O `MINMAXINFO` estrutura contém informações sobre seu tamanho mínimo e máximo de acompanhamento e posição e tamanho de uma janela maximizada.

## <a name="syntax"></a>Sintaxe

```
typedef struct tagMINMAXINFO {
    POINT ptReserved;
    POINT ptMaxSize;
    POINT ptMaxPosition;
    POINT ptMinTrackSize;
    POINT ptMaxTrackSize;
} MINMAXINFO;
```

#### <a name="parameters"></a>Parâmetros

*ptReserved*<br/>
Reservado para uso interno.

*ptMaxSize*<br/>
Especifica a largura maximizada (point.x) e a altura maximizada (point.y) da janela.

*ptMaxPosition*<br/>
Especifica a posição do lado esquerdo da janela maximizada (point.x) e a posição da parte superior da janela maximizada (point.y).

*ptMinTrackSize*<br/>
Especifica o mínimo de largura (point.x) de acompanhamento e o mínimo (point.y) de altura da janela de rastreamento.

*ptMaxTrackSize*<br/>
Especifica o máximo controle largura (point.x) e o máximo (point.y) de altura da janela de rastreamento.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** WinUser. h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CWnd::OnGetMinMaxInfo](../../mfc/reference/cwnd-class.md#ongetminmaxinfo)

