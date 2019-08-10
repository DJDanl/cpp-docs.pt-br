---
title: NotifyHandler
ms.date: 11/04/2016
ms.topic: reference
helpviewer_keywords:
- NotifyHandler function
ms.assetid: 5ff953ec-de35-42bc-8b3c-d384d636c139
ms.openlocfilehash: d875a039b01b7458a1df46a2539cf5c68aa67e41
ms.sourcegitcommit: 46d24d6e70c03e05484923d9efc6ed5150e96a64
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2019
ms.locfileid: "68915927"
---
# <a name="notifyhandler"></a>NotifyHandler

O nome da função identificada pelo terceiro parâmetro da macro NOTIFY_HANDLER em seu mapa de mensagens.

## <a name="syntax"></a>Sintaxe

```cpp
LRESULT NotifyHandler(
    int idCtrl,
    LPNMHDR pnmh,
    BOOL& bHandled);
```

#### <a name="parameters"></a>Parâmetros

*idCtrl*<br/>
O identificador do controle que envia a mensagem.

*pnmh*<br/>
Endereço de uma estrutura [NMHDR](/windows/desktop/api/richedit/ns-richedit-nmhdr) que contém o código de notificação e informações adicionais. Para algumas mensagens de notificação, esse parâmetro aponta para uma estrutura maior que tem `NMHDR` a estrutura como seu primeiro membro.

*bHandled*<br/>
O mapa de mensagens define *bHandled* como verdadeiro antes que *NotifyHandler* seja chamado. Se *NotifyHandler* não tratar totalmente a mensagem, ele deverá definir *bHandled* como **false** para indicar que a mensagem precisa de processamento adicional.

## <a name="return-value"></a>Valor de retorno

O resultado do processamento de mensagens. 0 se for bem-sucedido.

## <a name="remarks"></a>Comentários

Para obter um exemplo de como usar esse manipulador de mensagens em um mapa de mensagens, consulte [NOTIFY_HANDLER](reference/message-map-macros-atl.md#notify_handler)).

## <a name="see-also"></a>Consulte também

[Implementando uma janela](../atl/implementing-a-window.md)<br/>
[Mapas de mensagens](../atl/message-maps-atl.md)<br/>
[WM_NOTIFY](/windows/desktop/controls/wm-notify)
