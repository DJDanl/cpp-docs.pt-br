---
title: CommandHandler
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- CommandHandler
helpviewer_keywords:
- CommandHandler function
ms.assetid: 662bc7bf-4a10-42b3-986d-d8bae4f63551
ms.openlocfilehash: fe0871f9778d7a1f74bf74af6030d7f8162d3b79
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50611842"
---
# <a name="commandhandler"></a>CommandHandler

`CommandHandler` a função é identificada pelo terceiro parâmetro da macro COMMAND_HANDLER no seu mapa de mensagem.

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
O identificador do controle, item de menu ou acelerador.

*hWndCtl*<br/>
Um identificador para um controle de janela.

*bHandled*<br/>
Os conjuntos de mapa de mensagem *bHandled* como TRUE antes `CommandHandler` é chamado. Se `CommandHandler` não consegue tratar por completo a mensagem, ela deverá definir *bHandled* como FALSE para indicar que a mensagem precisa de processamento adicional.

## <a name="return-value"></a>Valor de retorno

O resultado do processamento de mensagens. 0 se for bem-sucedido.

## <a name="remarks"></a>Comentários

Para obter um exemplo de como usar este manipulador de mensagens em um mapa de mensagem, consulte [COMMAND_HANDLER](reference/message-map-macros-atl.md#command_handler).

## <a name="see-also"></a>Consulte também

[Implementando uma janela](../atl/implementing-a-window.md)<br/>
[Mapas de mensagens](../atl/message-maps-atl.md)<br/>
[WM_NOTIFY](https://msdn.microsoft.com/library/windows/desktop/bb775583)

