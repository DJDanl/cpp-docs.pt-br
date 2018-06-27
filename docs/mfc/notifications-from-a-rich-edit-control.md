---
title: Notificações de um conjunto avançado de controle de edição | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- messages [MFC], notification [MFC]
- CRichEditCtrl class [MFC], notifications
- rich edit controls [MFC], notifications
- notifications [MFC], from CRichEditCtrl
ms.assetid: eb5304fe-f4f3-4557-9ebf-3095dea383c4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 928728093ff6e2150578c4ba48f2d8081620a48d
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36931138"
---
# <a name="notifications-from-a-rich-edit-control"></a>Notificações de um controle de edição avançada
Mensagens de notificação de eventos que afetam um conjunto avançado de controle de edição de relatório ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)). Eles podem ser processados pela janela pai ou, usando a reflexão de mensagem, o sofisticado Editar controle em si. Controles de edição avançada oferecem suporte a todas as mensagens de notificação usadas com controles de edição, bem como vários outros adicionais. Você pode determinar quais mensagens de notificação de um controle de edição rica envia sua janela pai, definindo seu "máscara de evento".  
  
 Para definir a máscara de evento para o controle de edição de um conjunto avançado, use o [SetEventMask](../mfc/reference/cricheditctrl-class.md#seteventmask) função de membro. Você pode recuperar a máscara de evento atual para o controle de edição de um conjunto avançado usando o [GetEventMask](../mfc/reference/cricheditctrl-class.md#geteventmask) função de membro.  
  
 Os parágrafos a seguir listam várias notificações específicas e seus usos:  
  
-   EN_MSGFILTER manipulando a notificação EN_MSGFILTER permite que uma classe ou o controle rich edit ou sua janela pai, todos os teclado e mouse a entrada para o controle de filtro. O manipulador pode impedir que a mensagem do teclado ou mouse sendo processada ou pode alterar a mensagem modificando especificado [filtro de mensagens](http://msdn.microsoft.com/library/windows/desktop/bb787936) estrutura.  
  
-   EN_PROTECTED lidar com a mensagem de notificação EN_PROTECTED para detectar quando o usuário tenta modificar texto protegido. Para marcar um intervalo de texto como protegido, você pode definir o efeito de caractere protegido. Para obter mais informações, consulte [formatação de caracteres em controles de edição avançada](../mfc/character-formatting-in-rich-edit-controls.md).  
  
-   EN_DROPFILES você pode habilitar o usuário solta arquivos em um controle de edição rica processando a mensagem de notificação EN_DROPFILES. Especificado [ENDROPFILES](http://msdn.microsoft.com/library/windows/desktop/bb787895) estrutura contém informações sobre os arquivos que está sendo descartado.  
  
-   EN_SELCHANGE um aplicativo pode detectar quando a seleção atual é alterada por processar a mensagem de notificação EN_SELCHANGE. Especifica a mensagem de notificação um [SELCHANGE](http://msdn.microsoft.com/library/windows/desktop/bb787952) estrutura que contém informações sobre a nova seleção.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)

