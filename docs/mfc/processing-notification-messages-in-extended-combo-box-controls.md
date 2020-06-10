---
title: Processando mensagens de notificação em controles de caixa de combinação estendida
ms.date: 11/04/2016
helpviewer_keywords:
- extended combo boxes [MFC], notifications
- notifications [MFC], extended combo box controls
ms.assetid: 4e442758-d054-4746-bb1a-6ff84accb127
ms.openlocfilehash: 58a7c5ec36807489d24014055c39775b4552be03
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620995"
---
# <a name="processing-notification-messages-in-extended-combo-box-controls"></a>Processando mensagens de notificação em controles de caixa de combinação estendida

À medida que os usuários interagem com a caixa de combinação estendida, o controle ( `CComboBoxEx` ) envia mensagens de notificação para sua janela pai, geralmente um objeto View ou Dialog. Manipule essas mensagens se desejar fazer algo em resposta. Por exemplo, quando o usuário ativa a lista suspensa ou clica na caixa de edição do controle, a notificação de CBEN_BEGINEDIT é enviada.

Use o [Assistente de classe](reference/mfc-class-wizard.md) para adicionar manipuladores de notificação à classe pai para as mensagens que você deseja implementar.

A lista a seguir descreve as várias notificações enviadas pelo controle de caixa de combinação estendida.

- CBEN_BEGINEDIT enviado quando o usuário ativa a lista suspensa ou clica na caixa de edição do controle.

- CBEN_DELETEITEM enviado quando um item tiver sido excluído.

- CBEN_DRAGBEGIN Enviado quando o usuário começa a arrastar a imagem do item exibido na parte de edição do controle.

- CBEN_ENDEDIT enviado quando o usuário concluiu uma operação dentro da caixa de edição ou selecionou um item na lista suspensa do controle.

- CBEN_GETDISPINFO enviado para recuperar informações de exibição sobre um item de retorno de chamada.

- CBEN_INSERTITEM enviado quando um novo item foi inserido no controle.

## <a name="see-also"></a>Consulte também

[Usando CComboBoxEx](using-ccomboboxex.md)<br/>
[Controles](controls-mfc.md)
