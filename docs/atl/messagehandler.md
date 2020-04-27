---
title: MessageHandler
ms.date: 11/04/2016
ms.topic: reference
helpviewer_keywords:
- MessageHandler function
ms.assetid: 8a0acf97-1b0d-4226-91b9-75446634a03c
ms.openlocfilehash: 65a8ce08e4f8606f168b101aa4daba23ef541051
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168664"
---
# <a name="messagehandler"></a>MessageHandler

`MessageHandler`é o nome da função identificada pelo segundo parâmetro da macro MESSAGE_HANDLER em seu mapa de mensagens.

## <a name="syntax"></a>Sintaxe

```cpp
LRESULT MessageHandler(
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam,
    BOOL& bHandled);
```

### <a name="parameters"></a>Parâmetros

*uMsg*<br/>
Especifica a mensagem.

*wParam*<br/>
Obter informações adicionais específicas de mensagem.

*lParam*<br/>
Obter informações adicionais específicas de mensagem.

*bHandled*<br/>
O mapa de mensagens define *bHandled* como verdadeiro `MessageHandler` antes de ser chamado. Se `MessageHandler` o não tratar totalmente a mensagem, ele deverá definir *bHandled* como false para indicar que a mensagem precisa de processamento adicional.

## <a name="return-value"></a>Valor retornado

O resultado do processamento de mensagens. 0 se for bem-sucedido.

## <a name="remarks"></a>Comentários

Para obter um exemplo de como usar esse manipulador de mensagens em um mapa de mensagens, consulte [MESSAGE_HANDLER](reference/message-map-macros-atl.md#message_handler).

## <a name="see-also"></a>Confira também

[Implementando uma janela](../atl/implementing-a-window.md)<br/>
[Mapas de mensagens](../atl/message-maps-atl.md)<br/>
[WM_NOTIFY](/windows/win32/controls/wm-notify)
