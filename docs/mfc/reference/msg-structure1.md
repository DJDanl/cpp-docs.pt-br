---
title: Estrutura MSG 1 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- MSG
dev_langs:
- C++
helpviewer_keywords:
- MSG structure [MFC]
ms.assetid: dc166d27-9423-41f1-9599-5ba76d2f0138
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2819faa25e2dbd41d6578d60780d13011bb645c0
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46388388"
---
# <a name="msg-structure1"></a>Estrutura MSG 1

O `MSG` estrutura contém informações sobre a mensagem da fila de mensagens do thread.

## <a name="syntax"></a>Sintaxe

```
typedef struct tagMSG {     // msg
    HWND hwnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD time;
    POINT pt;
} MSG;
```

#### <a name="parameters"></a>Parâmetros

*HWND*<br/>
Identifica a janela cujo procedimento de janela recebe a mensagem.

*message*<br/>
Especifica o número da mensagem.

*wParam*<br/>
Especifica informações adicionais sobre a mensagem. O significado exato depende do valor do membro `message`.

*lParam*<br/>
Especifica informações adicionais sobre a mensagem. O significado exato depende do valor do membro `message`.

*time*<br/>
Especifica a hora em que a mensagem foi postada.

*pt*<br/>
Especifica a posição do cursor, em coordenadas da tela, quando a mensagem foi postada.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** WinUser. h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)

