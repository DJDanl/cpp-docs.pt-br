---
title: Processando mensagens de notificação em controles de caixa de combinação estendida
ms.date: 11/04/2016
helpviewer_keywords:
- extended combo boxes [MFC], notifications
- notifications [MFC], extended combo box controls
ms.assetid: 4e442758-d054-4746-bb1a-6ff84accb127
ms.openlocfilehash: 044cef644f746f7cb70944805882bd8e2f2806b4
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70908103"
---
# <a name="processing-notification-messages-in-extended-combo-box-controls"></a>Processando mensagens de notificação em controles de caixa de combinação estendida

À medida que os usuários interagem com a caixa de combinação`CComboBoxEx`estendida, o controle () envia mensagens de notificação para sua janela pai, geralmente um objeto View ou Dialog. Manipule essas mensagens se desejar fazer algo em resposta. Por exemplo, quando o usuário ativa a lista suspensa ou clica na caixa de edição do controle, a notificação CBEN_BEGINEDIT é enviada.

Use o [Assistente de classe](reference/mfc-class-wizard.md) para adicionar manipuladores de notificação à classe pai para as mensagens que você deseja implementar.

A lista a seguir descreve as várias notificações enviadas pelo controle de caixa de combinação estendida.

- CBEN_BEGINEDIT enviado quando o usuário ativa a lista suspensa ou clica na caixa de edição do controle.

- CBEN_DELETEITEM enviado quando um item foi excluído.

- CBEN_DRAGBEGIN Enviado quando o usuário começa a arrastar a imagem do item exibido na parte de edição do controle.

- CBEN_ENDEDIT enviado quando o usuário concluiu uma operação dentro da caixa de edição ou selecionou um item na lista suspensa do controle.

- CBEN_GETDISPINFO enviado para recuperar informações de exibição sobre um item de retorno de chamada.

- CBEN_INSERTITEM enviado quando um novo item foi inserido no controle.

## <a name="see-also"></a>Consulte também

[Usando CComboBoxEx](../mfc/using-ccomboboxex.md)<br/>
[Controles](../mfc/controls-mfc.md)
