---
title: MessageHandler
ms.date: 11/04/2016
ms.topic: reference
helpviewer_keywords:
- MessageHandler function
ms.assetid: 8a0acf97-1b0d-4226-91b9-75446634a03c
ms.openlocfilehash: 1acd56357f9ce234e3c479fd8fa88c1ed8407878
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57818226"
---
# <a name="messagehandler"></a>MessageHandler

`MessageHandler` é o nome da função identificada pelo segundo parâmetro da macro MESSAGE_HANDLER no seu mapa de mensagem.

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
Os conjuntos de mapa de mensagem *bHandled* como TRUE antes `MessageHandler` é chamado. Se `MessageHandler` não consegue tratar por completo a mensagem, ela deverá definir *bHandled* como FALSE para indicar que a mensagem precisa de processamento adicional.

## <a name="return-value"></a>Valor de retorno

O resultado do processamento de mensagens. 0 se for bem-sucedido.

## <a name="remarks"></a>Comentários

Para obter um exemplo de como usar este manipulador de mensagens em um mapa de mensagem, consulte [MESSAGE_HANDLER](reference/message-map-macros-atl.md#message_handler).

## <a name="see-also"></a>Consulte também

[Implementando uma janela](../atl/implementing-a-window.md)<br/>
[Mapas de mensagens](../atl/message-maps-atl.md)<br/>
[WM_NOTIFY](/windows/desktop/controls/wm-notify)
