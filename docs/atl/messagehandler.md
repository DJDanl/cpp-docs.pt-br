---
title: MessageHandler
ms.date: 11/04/2016
ms.topic: reference
helpviewer_keywords:
- MessageHandler function
ms.assetid: 8a0acf97-1b0d-4226-91b9-75446634a03c
ms.openlocfilehash: aa044ef88ba3c872c2652cd774ac50024e52c68c
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492320"
---
# <a name="messagehandler"></a>MessageHandler

`MessageHandler`é o nome da função identificada pelo segundo parâmetro da macro MESSAGE_HANDLER em seu mapa de mensagens.

## <a name="syntax"></a>Sintaxe

```
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

## <a name="return-value"></a>Valor de retorno

O resultado do processamento de mensagens. 0 se for bem-sucedido.

## <a name="remarks"></a>Comentários

Para obter um exemplo de como usar esse manipulador de mensagens em um mapa de mensagens, consulte [MESSAGE_HANDLER](reference/message-map-macros-atl.md#message_handler).

## <a name="see-also"></a>Consulte também

[Implementando uma janela](../atl/implementing-a-window.md)<br/>
[Mapas de mensagens](../atl/message-maps-atl.md)<br/>
[WM_NOTIFY](/windows/win32/controls/wm-notify)
