---
title: "Envio e recebimento da mensagem | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "mensagens de notificação de controle"
  - "mensagens [C++], MFC"
  - "mensagens [C++], recebendo"
  - "mensagens [C++], enviando"
  - "MFC [C++], mensagens"
  - "mensagens do Windows [C++], tratamento em MFC"
ms.assetid: 9ce189cb-b259-4c3b-b6f2-9cfbed18b98b
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Envio e recebimento da mensagem
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Considere a parte do processo e enviando como a estrutura responde.  
  
 A maioria de mensagens resultam de interação do usuário com o programa.  Os comandos são gerados por cliques do mouse nos itens de menu ou nos botões da barra de ferramentas ou por teclas de acelerador.  O usuário também gerencia mensagens do windows, por exemplo, mover ou redimensionar uma janela.  Outras mensagens do windows são enviados quando os eventos como a inicialização ou encerramento do programa ocorrerem, como as janelas obter ou perdem o foco, e assim por diante.  As mensagens de notificação Controle\- são produzidas por cliques do mouse ou outras interações do usuário com um controle, como um controle de botão ou na caixa de listagem em uma caixa de diálogo.  
  
 A função de membro de **Executar** da classe `CWinApp` recupera mensagens e despacha\-as a janela apropriada.  A maioria das mensagens de comando são enviadas à janela principal do quadro do aplicativo.  `WindowProc` predefinido pela biblioteca de classes recebe as mensagens e roteá\-las de forma diferente, dependendo da categoria de mensagem recebida.  
  
 Agora considere a parte receptora do processo.  
  
 O destinatário inicial de uma mensagem deve ser um objeto da janela.  As mensagens do windows são tratadas geralmente diretamente por esse objeto da janela.  O comando as mensagens, originando normalmente na janela principal do quadro do aplicativo, obter\-las direcionadas para a cadeia de comando\- destino descrita em [Roteamento de comando](../mfc/command-routing.md).  
  
 Cada objeto capaz de receber mensagens ou comandos tem seu próprio mapa de mensagem que combina uma mensagem ou um comando com o nome do seu manipulador.  
  
 Quando um objeto de comando\- destino recebe uma mensagem ou um comando, pesquisa seu mapa de mensagem por uma correspondência.  Se encontrar um manipulador para a mensagem, chama o manipulador.  Para obter mais informações sobre como os mapas de mensagem são pesquisados, consulte [Como a estrutura pesquisa mapas da mensagem](../mfc/how-the-framework-searches-message-maps.md).  Consulte novamente a figura [Comandos na estrutura](../mfc/user-interface-objects-and-command-ids.md).  
  
## Consulte também  
 [Como o Framework chama um identificador](../mfc/how-the-framework-calls-a-handler.md)