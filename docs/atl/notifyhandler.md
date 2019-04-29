---
title: NotifyHandler
ms.date: 11/04/2016
ms.topic: reference
helpviewer_keywords:
- NotifyHandler function
ms.assetid: 5ff953ec-de35-42bc-8b3c-d384d636c139
ms.openlocfilehash: 292a1c6606585dc0694ee678ba8bc9b5fbc42681
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62261440"
---
# <a name="notifyhandler"></a>NotifyHandler

O nome da função identificado pelo terceiro parâmetro da macro NOTIFY_HANDLER no seu mapa de mensagem.

## <a name="syntax"></a>Sintaxe

```cpp
LRESULT NotifyHandler(
    int idCtrl,
    LPNMHDR pnmh,
    BOOL& bHandled);
```

#### <a name="parameters"></a>Parâmetros

*idCtrl*<br/>
O identificador do controle que está enviando a mensagem.

*pnmh*<br/>
Endereço de um [NMHDR](/windows/desktop/api/richedit/ns-richedit-_nmhdr) estrutura que contém o código de notificação e informações adicionais. Para algumas mensagens de notificação, este parâmetro aponta para uma estrutura maior que tem o `NMHDR` estrutura como seu primeiro membro.

*bHandled*<br/>
Os conjuntos de mapa de mensagem *bHandled* como TRUE antes *NotifyHandler* é chamado. Se *NotifyHandler* totalmente não manipular a mensagem, ela deverá definir *bHandled* para **FALSE** para indicar que a mensagem precisa de processamento adicional.

## <a name="return-value"></a>Valor de retorno

O resultado do processamento de mensagens. 0 se for bem-sucedido.

## <a name="remarks"></a>Comentários

Para obter um exemplo de como usar este manipulador de mensagens em um mapa de mensagem, consulte [NOTIFY_HANDLER](reference/message-map-macros-atl.md#notify_handler)).

## <a name="see-also"></a>Consulte também

[Implementando uma janela](../atl/implementing-a-window.md)<br/>
[Mapas de mensagens](../atl/message-maps-atl.md)<br/>
[WM_NOTIFY](/windows/desktop/controls/wm-notify)
