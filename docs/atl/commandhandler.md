---
title: CommandHandler
ms.date: 11/04/2016
ms.topic: reference
helpviewer_keywords:
- CommandHandler function
ms.assetid: 662bc7bf-4a10-42b3-986d-d8bae4f63551
ms.openlocfilehash: 99a95228f6036e5f391395be367cdef39ca3dc3b
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492462"
---
# <a name="commandhandler"></a>CommandHandler

`CommandHandler`é a função identificada pelo terceiro parâmetro da macro COMMAND_HANDLER em seu mapa de mensagens.

## <a name="syntax"></a>Sintaxe

```cpp
LRESULT CommandHandler(
    WORD wNotifyCode,
    WORD wID,
    HWND hWndCtl,
    BOOL& bHandled);
```

#### <a name="parameters"></a>Parâmetros

*wNotifyCode*<br/>
O código de notificação.

*wID*<br/>
O identificador do item de menu, controle ou acelerador.

*hWndCtl*<br/>
Um identificador para um controle de janela.

*bHandled*<br/>
O mapa de mensagens define *bHandled* como verdadeiro `CommandHandler` antes de ser chamado. Se `CommandHandler` o não tratar totalmente a mensagem, ele deverá definir *bHandled* como false para indicar que a mensagem precisa de processamento adicional.

## <a name="return-value"></a>Valor de retorno

O resultado do processamento de mensagens. 0 se for bem-sucedido.

## <a name="remarks"></a>Comentários

Para obter um exemplo de como usar esse manipulador de mensagens em um mapa de mensagens, consulte [COMMAND_HANDLER](reference/message-map-macros-atl.md#command_handler).

## <a name="see-also"></a>Consulte também

[Implementando uma janela](../atl/implementing-a-window.md)<br/>
[Mapas de mensagens](../atl/message-maps-atl.md)<br/>
[WM_NOTIFY](/windows/win32/controls/wm-notify)
