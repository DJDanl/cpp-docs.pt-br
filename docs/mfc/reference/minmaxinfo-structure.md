---
title: Estrutura MINMAXINFO | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- MINMAXINFO
dev_langs:
- C++
helpviewer_keywords:
- MINMAXINFO structure [MFC]
ms.assetid: be6fb578-f98a-4581-9ada-be9df308ed2f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b63589edbe47aa09b8a6be92b5b7eb7e29077c96
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46402285"
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

