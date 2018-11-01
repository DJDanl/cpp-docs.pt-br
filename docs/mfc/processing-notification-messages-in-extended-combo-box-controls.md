---
title: Processando mensagens de notificação em controles de caixa de combinação estendida
ms.date: 11/04/2016
helpviewer_keywords:
- extended combo boxes [MFC], notifications
- notifications [MFC], extended combo box controls
ms.assetid: 4e442758-d054-4746-bb1a-6ff84accb127
ms.openlocfilehash: 6a007af9bf92868049edba99943e080d509a40da
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50430986"
---
# <a name="processing-notification-messages-in-extended-combo-box-controls"></a>Processando mensagens de notificação em controles de caixa de combinação estendida

Conforme os usuários interagem com a caixa de combinação estendido, o controle (`CComboBoxEx`) envia mensagens de notificação à sua janela pai, normalmente, um objeto de exibição ou a caixa de diálogo. Se você quiser fazer algo em resposta, lidar com essas mensagens. Por exemplo, quando o usuário ativa a lista suspensa ou clica na caixa de edição do controle, a notificação de CBEN_BEGINEDIT é enviada.

Use a janela Propriedades para adicionar manipuladores de notificação para a classe pai para essas mensagens que você deseja implementar.

A seguinte lista descreve várias notificações enviadas pelo controle de caixa de combinação estendido.

- CBEN_BEGINEDIT enviado quando o usuário ativa a lista suspensa ou clica na caixa de edição do controle.

- CBEN_DELETEITEM enviado quando um item foi excluído.

- CBEN_DRAGBEGIN enviado quando o usuário começa a arrastar a imagem do item exibido na parte de edição do controle.

- CBEN_ENDEDIT enviado quando o usuário concluiu uma operação dentro da caixa de edição ou se tiver selecionado um item da lista de lista suspensa do controle.

- CBEN_GETDISPINFO enviada para recuperar informações de exibição sobre um item de retorno de chamada.

- CBEN_INSERTITEM enviado quando um novo item foi inserido no controle.

## <a name="see-also"></a>Consulte também

[Usando CComboBoxEx](../mfc/using-ccomboboxex.md)<br/>
[Controles](../mfc/controls-mfc.md)

