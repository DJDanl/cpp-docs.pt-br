---
title: "Mapas de mensagens (ATL) | Microsoft Docs"
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
  - "ATL, manipuladores de mensagem"
  - "mapas de mensagem, ATL"
ms.assetid: 9e100400-65c7-4a85-8857-4e6cb6dd7340
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Mapas de mensagens (ATL)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um mapa de mensagem associa uma função do manipulador com uma mensagem específica, um comando, ou uma notificação.  Usando [macros do mapa de mensagem](../atl/reference/message-map-macros-atl.md)de ATL, você pode especificar um mapa de mensagem para uma janela.  Os procedimentos da janela em `CWindowImpl`, em `CDialogImpl`, e em `CContainedWindowT` direcionam as mensagens de uma janela para seu mapa de mensagem.  
  
 [funções do manipulador de mensagem](../atl/message-handler-functions.md) aceita um argumento adicional do tipo `BOOL&`.  Esse argumento indica se uma mensagem foi processada, e é definida como `TRUE` por padrão.  Uma função do manipulador pode então definir o argumento para `FALSE` para indicar que tratou a mensagem.  Em esse caso, ATL continuará a procurar uma função do manipulador mais no mapa de mensagem.  Definindo este argumento para `FALSE`primeiro, você pode executar alguma ação em resposta a uma mensagem e então permitir o processamento padrão ou outra função do manipulador para o botão que manipula a mensagem.  
  
## Mapas encadeados de mensagem  
 ATL também permite que você encadee mapas de mensagem, que direciona tratamento de mensagem para um mapa de mensagem definida em outra classe.  Por exemplo, você pode implementar tratamento de mensagem comuns em uma classe separada para fornecer um comportamento uniforme para todas as janelas que encadea a classe.  Você pode encadear a uma classe base ou a um membro de dados de sua classe.  
  
 ATL também suporta encadeamento dinâmico, que permite que você encadee no mapa da mensagem de outro objeto em tempo de execução.  Para implementar encadeamento dinâmico, você deve derivar sua classe de [CDynamicChain](../atl/reference/cdynamicchain-class.md).  Declarar na macro de [CHAIN\_MSG\_MAP\_DYNAMIC](../Topic/CHAIN_MSG_MAP_DYNAMIC.md) no mapa de mensagem.  `CHAIN_MSG_MAP_DYNAMIC` requer um número exclusivo que identifica o objeto e o mapa da mensagem que você está encadeando.  Você deve definir esse valor exclusivo com uma chamada a `CDynamicChain::SetChainEntry`.  
  
 Você pode encadear a qualquer classe que declarar um mapa de mensagem, desde que a classe deriva de [CMessageMap](../atl/reference/cmessagemap-class.md).  `CMessageMap` permite que um objeto expõe seus mapeamentos de mensagem para outros objetos.  Observe que `CWindowImpl` já deriva de `CMessageMap`.  
  
## Alternar mapas de mensagem  
 Finalmente, mapas alternativas de mensagem dos meios de ATL, declarados com a macro de [ALT\_MSG\_MAP](../Topic/ALT_MSG_MAP.md) .  Cada mapa alternativo de mensagem é identificada por um número exclusivo, que você passe a `ALT_MSG_MAP`.  Usando alternativas mapas de mensagem, você pode manipular mensagens de várias janelas em um mapa.  Observe que por padrão, `CWindowImpl` não usa mapeamentos alternativas de mensagem.  Para adicionar esse suporte, substituir o método de `WindowProc` em seu `CWindowImpl`\- classe derivada e chamar `ProcessWindowMessage` com o identificador do mapa de mensagem.  
  
## Consulte também  
 [Implementando uma janela](../atl/implementing-a-window.md)