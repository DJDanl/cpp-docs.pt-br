---
title: "Processando mensagens de notificação em estendidos controles de caixa de combinação | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- extended combo boxes [MFC], notifications
- notifications [MFC], extended combo box controls
ms.assetid: 4e442758-d054-4746-bb1a-6ff84accb127
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a78e7b9fd8f9c67f14a4bb51088866785d372cca
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="processing-notification-messages-in-extended-combo-box-controls"></a>Processando mensagens de notificação em controles de caixa de combinação estendida
Como os usuários interagem com a caixa de combinação estendido, o controle (`CComboBoxEx`) envia mensagens de notificação para sua janela pai, geralmente um objeto de exibição ou a caixa de diálogo. Se você quiser fazer algo em resposta, lidar com essas mensagens. Por exemplo, quando o usuário ativa a lista suspensa ou cliques no controle de caixa de edição de **CBEN_BEGINEDIT** notificação é enviada.  
  
 Use a janela Propriedades para adicionar manipuladores de notificação para a classe pai para as mensagens que você deseja implementar.  
  
 A lista a seguir descreve as várias notificações enviadas pelo controle da caixa de combinação estendidas.  
  
-   **CBEN_BEGINEDIT** enviado quando o usuário ativa a lista suspensa ou cliques no controle de caixa de edição.  
  
-   **CBEN_DELETEITEM** enviado quando um item foi excluído.  
  
-   **CBEN_DRAGBEGIN** enviado quando o usuário começa a arrastar a imagem do item exibido na parte de edição do controle.  
  
-   **CBEN_ENDEDIT** enviado quando o usuário concluiu uma operação dentro da caixa de edição ou tem um item selecionado da lista do menu suspenso do controle.  
  
-   **CBEN_GETDISPINFO** enviada para recuperar informações de exibição sobre um item de retorno de chamada.  
  
-   **CBEN_INSERTITEM** enviada quando um novo item foi inserido no controle.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CComboBoxEx](../mfc/using-ccomboboxex.md)   
 [Controles](../mfc/controls-mfc.md)

