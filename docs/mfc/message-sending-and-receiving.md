---
title: Envio e recebimento da mensagem
ms.date: 11/04/2016
helpviewer_keywords:
- Windows messages [MFC], handling in MFC
- control-notification messages [MFC]
- messages [MFC], receiving
- messages [MFC], MFC
- MFC, messages
- messages [MFC], sending
ms.assetid: 9ce189cb-b259-4c3b-b6f2-9cfbed18b98b
ms.openlocfilehash: 4da2fce68c1b6fd3827bc8b5d2a40dea5e5f117c
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626169"
---
# <a name="message-sending-and-receiving"></a>Envio e recebimento da mensagem

Considere a parte de envio do processo e como a estrutura responde.

A maioria das mensagens resulta da interação do usuário com o programa. Os comandos são gerados por cliques do mouse em itens de menu ou botões da barra de ferramentas ou por pressionamentos de teclas do acelerador. O usuário também gera mensagens do Windows, por exemplo, movendo ou redimensionando uma janela. Outras mensagens do Windows são enviadas quando eventos como a inicialização ou o encerramento do programa ocorrem, à medida que o Windows Obtém ou perde o foco e assim por diante. As mensagens de notificação de controle são geradas por cliques do mouse ou por outras interações de usuário com um controle, como um botão ou controle de caixa de listagem em uma caixa de diálogo.

A `Run` função membro da classe `CWinApp` recupera mensagens e as envia para a janela apropriada. A maioria das mensagens de comando são enviadas para a janela principal do quadro do aplicativo. O `WindowProc` predefinido pela biblioteca de classes Obtém as mensagens e as roteia de forma diferente, dependendo da categoria de mensagem recebida.

Agora, considere a parte de recebimento do processo.

O receptor inicial de uma mensagem deve ser um objeto de janela. As mensagens do Windows geralmente são tratadas diretamente por esse objeto de janela. Mensagens de comando, geralmente originadas na janela do quadro principal do aplicativo, são roteadas para a cadeia de destino de comando descrita no [Roteamento de comando](command-routing.md).

Cada objeto capaz de receber mensagens ou comandos tem seu próprio mapa de mensagens que emparelha uma mensagem ou um comando com o nome de seu manipulador.

Quando um objeto de destino de comando recebe uma mensagem ou um comando, ele pesquisa seu mapa de mensagens para uma correspondência. Se encontrar um manipulador para a mensagem, ele chamará o manipulador. Para obter mais informações sobre como os mapas de mensagens são pesquisados, consulte [como a estrutura pesquisa mapas de mensagens](how-the-framework-searches-message-maps.md). Consulte novamente os comandos de figura [na estrutura](user-interface-objects-and-command-ids.md).

## <a name="see-also"></a>Consulte também

[Como o Framework chama um manipulador](how-the-framework-calls-a-handler.md)
