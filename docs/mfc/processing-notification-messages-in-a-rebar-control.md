---
title: Processando mensagens de notificação em um controle rebar
ms.date: 11/04/2016
helpviewer_keywords:
- RBN_ notification messages, description of
- CReBarCtrl class [MFC], notification messages sent by
- RBN_ notification messages [MFC]
- notifications [MFC], CReBarCtrl
ms.assetid: 40f43a60-0c18-4d8d-8fab-213a095624f9
ms.openlocfilehash: 948990c8597c2ccdcec496252c6801c02a78cbf5
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69507954"
---
# <a name="processing-notification-messages-in-a-rebar-control"></a>Processando mensagens de notificação em um controle rebar

Na classe pai do controle rebar, crie uma `OnChildNotify` função de manipulador com uma instrução switch para qualquer mensagem de notificação de controle rebar (`CReBarCtrl`) que você deseja manipular. As notificações são enviadas para a janela pai quando o usuário arrasta objetos sobre o controle rebar, altera o layout das bandas de rebar, exclui as faixas do controle rebar e assim por diante.

As seguintes mensagens de notificação podem ser enviadas pelo objeto de controle rebar:

- RBN_AUTOSIZE enviado por um controle rebar (criado com o estilo RBS_AUTOSIZE) quando o rebar é redimensionado automaticamente.

- RBN_BEGINDRAG enviado por um controle rebar quando o usuário começa a arrastar uma banda.

- RBN_CHILDSIZE enviado por um controle rebar quando a janela filho de uma banda é redimensionada.

- RBN_DELETEDBAND enviado por um controle rebar após a exclusão de uma banda.

- RBN_DELETINGBAND enviado por um controle rebar quando uma banda está prestes a ser excluída.

- RBN_ENDDRAG enviado por um controle rebar quando o usuário para de arrastar uma banda.

- RBN_GETOBJECT enviado por um controle rebar (criado com o estilo RBS_REGISTERDROP) quando um objeto é arrastado sobre uma banda no controle.

- RBN_HEIGHTCHANGE enviado por um controle rebar quando sua altura é alterada.

- RBN_LAYOUTCHANGED enviado por um controle rebar quando o usuário altera o layout das faixas do controle.

Para obter mais informações sobre essas notificações, consulte [referência de controle rebar](/windows/win32/controls/rebar-control-reference) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Usando CReBarCtrl](../mfc/using-crebarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
