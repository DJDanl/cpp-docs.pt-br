---
title: Enviando e recebendo mensagens | Microsoft Docs
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
ms.openlocfilehash: 3b7ded8dd0c818b95d6f45a722bd7b8516d48ff1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="message-sending-and-receiving"></a>Envio e recebimento da mensagem
Considere a enviar parte do processo e como o framework responde.  
  
 A maioria das mensagens resultantes da interação do usuário com o programa. Comandos são gerados por cliques do mouse em itens de menu ou botões da barra de ferramentas ou pressionamentos de teclas de aceleração. O usuário gera também mensagens do Windows, em, por exemplo, mover ou redimensionar uma janela. Outras mensagens do Windows são enviadas quando ocorrem eventos, como inicialização de programa ou encerramento, como windows obter ou perder o foco e assim por diante. Mensagens de notificação de controle são geradas por cliques do mouse ou outras interações do usuário com um controle, como um controle de botão ou caixa de listagem na caixa de diálogo.  
  
 O **executar** função de membro de classe `CWinApp` recupera mensagens e expede para a janela apropriada. A maioria das mensagens de comando são enviados para a janela do quadro principal do aplicativo. O `WindowProc` predefinida pelo obtém de biblioteca de classe as mensagens e direciona-os de forma diferente, dependendo da categoria de mensagem recebida.  
  
 Agora, considere a parte receptora do processo.  
  
 O receptor inicial de uma mensagem deve ser um objeto de janela. Mensagens do Windows geralmente são tratadas diretamente por esse objeto de janela. Mensagens de comando, geralmente de origem na janela do quadro principal do aplicativo, são roteadas para a cadeia de destino do comando descrita em [roteamento de comando](../mfc/command-routing.md).  
  
 Cada objeto capaz de receber mensagens ou comandos tem sua própria mensagem mapear esse pares de uma mensagem ou comando com o nome do seu manipulador.  
  
 Quando um objeto de destino do comando recebe uma mensagem ou um comando, ele pesquisa seu mapa de mensagem para uma correspondência. Se ele localizar um manipulador para a mensagem, ele chama o manipulador. Para obter mais informações sobre como mapas de mensagem são pesquisados, consulte [como o Framework pesquisa mapas de mensagem](../mfc/how-the-framework-searches-message-maps.md). Consulte a figura novamente [comandos no Framework](../mfc/user-interface-objects-and-command-ids.md).  
  
## <a name="see-also"></a>Consulte também  
 [Como o Framework chama um manipulador](../mfc/how-the-framework-calls-a-handler.md)

