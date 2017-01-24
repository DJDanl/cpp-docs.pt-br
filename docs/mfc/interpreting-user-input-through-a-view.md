---
title: "Interpretando a entrada do usu&#225;rio por meio de uma exibi&#231;&#227;o | Microsoft Docs"
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
  - "Classe CView, interpretando entrada de usuário"
  - "entrada, classe de exibição"
  - "interpretando entrada do usuário por meio de exibições"
  - "entrada do usuário, interpretando por meio de classe de exibição"
  - "modos de exibição, interface de usuário e entrada"
ms.assetid: f0302a70-661f-4781-8fe7-78f082bef2a5
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Interpretando a entrada do usu&#225;rio por meio de uma exibi&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Outras funções de membro de exibição e interpretam controlam toda a entrada de usuário.  Geralmente você definirá funções de membro retornadas a em sua classe de exibição para processar:  
  
-   O windows [mensagens](../mfc/messages.md) gerado por ações do mouse no teclado.  
  
-   [Comandos](../mfc/user-interface-objects-and-command-ids.md) menus, os botões da barra de ferramentas, e as teclas de aceleração.  
  
 Essas funções de membro retornadas ao interpretam as seguintes ações como a entrada de dados, a seleção, ou editar, incluindo a movimentação de dados e da área de transferência:  
  
-   Move e os cliques do mouse em, arraste, e clique duas vezes em  
  
-   Teclas  
  
-   Comandos de menu  
  
 O windows que as mensagens sua exibição tratam depende das necessidades de seu aplicativo.  
  
 [Tópicos de manipulação e o mapeamento de mensagem](../mfc/message-handling-and-mapping.md) explica como atribuir itens de menu e outros objetos de interface do usuário aos comandos e como associar os comandos para as funções do manipulador.  [Tópicos de manipulação e o mapeamento de mensagem](../mfc/message-handling-and-mapping.md) também explica como MFC o roteia comandos e envia mensagens padrão do windows para objetos que contêm manipuladores para eles.  
  
 Por exemplo, o aplicativo pode precisar implementar o desenho direto do mouse na exibição.  O exemplo de garrancho mostra como tratar respectivamente `WM_LBUTTONDOWN`, `WM_MOUSEMOVE`, e mensagens de `WM_LBUTTONUP` para iniciar, continuar, e encerre o desenho de um segmento de linha.  Por outro lado, às vezes você pode precisar interpretar um clique do mouse na exibição como uma seleção.  A função de manipulador de `OnLButtonDown` de sua exibição determinaria se o usuário estava desenhando ou estava selecionando.  Se, selecionando o manipulador determinaria se o estava clique dentro dos limites de qualquer objeto na exibição e, nesse caso, altera a exibição para mostrar o objeto selecionado como.  
  
 Sua exibição também pode tratar certos comandos de menu, como aquelas do menu editar a divisão, copiar, colar, ou excluir dados selecionados usando a área de transferência.  Como manipulador chamaria qualquer uma das funções de membro Área de transferência\- relacionados da classe `CWnd` para transferir um item de dados selecionado ou da área de transferência.  
  
## Consulte também  
 [Usando exibições](../mfc/using-views.md)