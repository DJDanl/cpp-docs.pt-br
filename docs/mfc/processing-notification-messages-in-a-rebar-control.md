---
title: Processando mensagens de notificação em um controle Rebar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- RBN_ notification messages, description of
- CReBarCtrl class [MFC], notification messages sent by
- RBN_ notification messages [MFC]
- notifications [MFC], CReBarCtrl
ms.assetid: 40f43a60-0c18-4d8d-8fab-213a095624f9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a06df0bdfe8d1b81b4285fc86378f3da99882698
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33348410"
---
# <a name="processing-notification-messages-in-a-rebar-control"></a>Processando mensagens de notificação em um controle rebar
Na classe pai do controle rebar, crie um `OnChildNotify` função de manipulador com uma instrução switch para qualquer controle rebar (`CReBarCtrl`) mensagens de notificação que você deseja manipular. As notificações são enviadas para a janela pai quando o usuário arrasta objetos sobre o controle rebar, alterações de layout das bandas rebar, exclusões bandas do controle rebar e assim por diante.  
  
 As seguintes mensagens de notificação podem ser enviadas pelo objeto do controle rebar:  
  
-   **RBN_AUTOSIZE** enviado por um controle rebar (criado com o **RBS_AUTOSIZE** estilo) quando o rebar é redimensionado automaticamente.  
  
-   **RBN_BEGINDRAG** enviado por um controle rebar quando o usuário começa a arrastar uma faixa.  
  
-   **RBN_CHILDSIZE** enviado por um controle rebar quando a janela filho da banda é redimensionada.  
  
-   **RBN_DELETEDBAND** enviado por um controle rebar após a exclusão de uma faixa.  
  
-   **RBN_DELETINGBAND** enviado por um controle rebar quando uma banda está prestes a ser excluído.  
  
-   **RBN_ENDDRAG** enviado por um controle rebar quando o usuário para de arrastar uma faixa.  
  
-   **RBN_GETOBJECT** enviado por um controle rebar (criado com o **RBS_REGISTERDROP** estilo) quando um objeto é arrastado sobre uma faixa no controle.  
  
-   **RBN_HEIGHTCHANGE** enviado por um controle rebar quando sua altura é alterada.  
  
-   **RBN_LAYOUTCHANGED** enviado por um controle rebar quando o usuário altera o layout das bandas do controle.  
  
 Para obter mais informações sobre essas notificações, consulte [referência de controle Rebar](http://msdn.microsoft.com/library/windows/desktop/bb774375) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CReBarCtrl](../mfc/using-crebarctrl.md)   
 [Controles](../mfc/controls-mfc.md)

