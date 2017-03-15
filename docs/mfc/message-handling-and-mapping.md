---
title: "Manipula&#231;&#227;o e mapeamento de mensagem | Microsoft Docs"
ms.custom: ""
ms.date: "12/13/2016"
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
  - "lidando com erros"
  - "mapas de mensagem"
  - "MFC, mensagens"
ms.assetid: 62fe2a1b-944c-449d-a0f0-63c11ee0a3cb
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipula&#231;&#227;o e mapeamento de mensagem
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Esta família do artigo descreve como as mensagens e os comandos são processados pela estrutura de MFC e como você se conectar às suas funções do manipulador.  
  
 Em programas tradicionais no windows, as mensagens do windows são tratadas em uma grande instrução switch em um procedimento de janela.  O MFC usa em vez [mapas da mensagem](../mfc/message-categories.md) para mapear mensagens diretas para as funções de membro distintas da classe.  Os mapas da mensagem é mais eficiente do que funções virtuais para essa finalidade, e permitem que as mensagens sejam tratadas pela maioria objeto apropriado C\+\+ — o aplicativo, documenta, exibição, e assim por diante.  Você pode mapear uma única mensagem ou um intervalo de mensagens, IDs de comando, ou para controlar IDs.  
  
 As mensagens de**WM\_COMMAND** — geralmente geradas por menus, por botões da barra de ferramentas, ou por aceleradores — também usam o mecanismo retornadas mapa.  O MFC define um padrão [rotear](../mfc/command-routing.md) de mensagens do comando entre o aplicativo, a janela do quadro, a exibição, e os documentos ativos em seu programa.  Você pode substituir o roteamento se você precisa.  
  
 Os mapas de mensagens também fornecem uma maneira de atualizar objetos de interface de usuário \(como menus e botões da barra de ferramentas\), habilitando ou desabilitando o para adequar ao contexto atual.  
  
 Para obter informações gerais sobre as mensagens e as filas de mensagens no windows, consulte [Mensagens e filas de mensagens](http://msdn.microsoft.com/library/windows/desktop/ms632590) em [!INCLUDE[winSDK](../atl/includes/winsdk_md.md)].  
  
## Que você deseja saber mais?  
  
-   [Mensagens e comandos na estrutura](../mfc/messages-and-commands-in-the-framework.md)  
  
-   [Como a estrutura chama um manipulador de mensagens](../mfc/how-the-framework-calls-a-handler.md)  
  
-   [Como a estrutura pesquisa mapas da mensagem](../mfc/how-the-framework-searches-message-maps.md)  
  
-   [Declarando funções do manipulador de mensagens](../mfc/declaring-message-handler-functions.md)  
  
-   [Mensagens de mapeamento a funções](../Topic/Mapping%20Messages%20to%20Functions.md)  
  
-   [Como exibir informações de comando na barra de status](../Topic/How%20to:%20Display%20Command%20Information%20in%20the%20Status%20Bar.md)  
  
-   [Atualização dinâmica dos objetos de interface do usuário](../mfc/how-to-update-user-interface-objects.md)  
  
-   [Como criar um mapa de mensagem para uma classe de modelo](../mfc/how-to-create-a-message-map-for-a-template-class.md)  
  
## Consulte também  
 [Conceitos](../mfc/mfc-concepts.md)   
 [Tópicos MFC gerais](../mfc/general-mfc-topics.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Classe de CCmdTarget](../Topic/CCmdTarget%20Class.md)