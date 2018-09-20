---
title: Envio e recebimento de mensagem | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Windows messages [MFC], handling in MFC
- control-notification messages [MFC]
- messages [MFC], receiving
- messages [MFC], MFC
- MFC, messages
- messages [MFC], sending
ms.assetid: 9ce189cb-b259-4c3b-b6f2-9cfbed18b98b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e28f35fc87b78ac4e04df0f8147d76571c51320e
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46438815"
---
# <a name="message-sending-and-receiving"></a>Envio e recebimento da mensagem

Considere o envio parte do processo e como o framework responde.

A maioria das mensagens provenientes de interação do usuário com o programa. Comandos são gerados por cliques do mouse em itens de menu ou botões da barra de ferramentas ou pressionamentos de teclas de aceleração. O usuário gera também as mensagens do Windows, em, por exemplo, mover ou redimensionar uma janela. Outras mensagens do Windows são enviadas quando ocorrem eventos, como a inicialização do programa ou o término, como o windows obterem ou perder o foco e assim por diante. Mensagens de notificação do controle são geradas por cliques do mouse ou outras interações do usuário com um controle, como um controle de botão ou caixa de listagem em uma caixa de diálogo.

O `Run` função de membro da classe `CWinApp` recupera mensagens e expede-os para a janela apropriada. A maioria das mensagens de comando são enviados para a janela de quadro principal do aplicativo. O `WindowProc` predefinida pela classe biblioteca obtém as mensagens e encaminha-as de forma diferente, dependendo da categoria de mensagem recebida.

Agora, considere a parte receptora do processo.

O receptor inicial de uma mensagem deve ser um objeto de janela. Mensagens do Windows geralmente são tratadas diretamente por esse objeto de janela. Mensagens de comando, geralmente são originadas na janela de quadro principal do aplicativo, são roteadas para a cadeia de destino do comando descrita na [roteamento de comando](../mfc/command-routing.md).

Cada objeto capaz de receber mensagens ou comandos tem sua própria mensagem mapear que emparelha uma mensagem ou o comando com o nome do seu manipulador.

Quando um objeto de destino do comando recebe uma mensagem ou um comando, ele pesquisa a seu mapa de mensagem para uma correspondência. Se ele encontrar um manipulador para a mensagem, ele chama o manipulador. Para obter mais informações sobre como os mapas de mensagem são pesquisados, consulte [como o Framework pesquisa mapas de mensagem](../mfc/how-the-framework-searches-message-maps.md). Consulte novamente a Figura [comandos no Framework](../mfc/user-interface-objects-and-command-ids.md).

## <a name="see-also"></a>Consulte também

[Como o Framework chama um manipulador](../mfc/how-the-framework-calls-a-handler.md)

