---
title: "Mapas de mensagem derivados | Microsoft Docs"
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
  - "mapas de mensagem derivados"
  - "lidando com erros, manipuladores de mensagens derivados"
  - "mapas de mensagem, derivado"
  - "mensagens, roteamento"
ms.assetid: 21829556-6e64-40c3-8279-fed85d99de77
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Mapas de mensagem derivados
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Durante a manipulação de mensagens, verifique o mapa de uma classe em si não é o final de história retornadas mapa.  O que acontece se a classe `CMyView` \(derivado de `CView`\) não tem nenhuma entrada correspondente para uma mensagem?  
  
 Lembre\-se de que `CView`, a classe base de `CMyView`, é derivado por sua vez de `CWnd`.  Assim `CMyView` *é*`CView` e *é*`CWnd`.  Cada uma dessas classes tem seu próprio mapa da mensagem.  A figura “uma hierarquia de exibição” abaixo mostra a relação hierárquica das classes, mas tenha em mente que um objeto de `CMyView` é um único objeto que possui as características das três classes.  
  
 ![Hierarquia de exibição VC](../mfc/media/vc38621.png "vc38621")  
Uma hierarquia de exibição  
  
 Isso se uma mensagem não pode ser correspondida da mensagem de `CMyView` da classe, a estrutura também procura o mapa da mensagem da sua classe base imediata.  A macro de `BEGIN_MESSAGE_MAP` no início da mensagem especifica dois nomes da classe como argumentos:  
  
 [!CODE [NVC_MFCMessageHandling#2](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCMessageHandling#2)]  
  
 Os primeiros nomes de argumento a classe na qual o mapa da mensagem pertence.  O segundo argumento fornecerá uma conexão com a classe base imediata — `CView` aqui — assim que a estrutura pode procurar seu mapa da mensagem, também.  
  
 Os manipuladores de mensagem fornecidos em uma classe base e são herdados pela classe derivada.  Isso é muito semelhante às funções de membro virtuais normais sem precisar fazer todas as funções de membro do manipulador virtuais.  
  
 Se nenhum manipulador é encontrado em qualquer um dos mapas da mensagem da classe base, o processamento padrão da mensagem é executado.  Se a mensagem for um comando, a estrutura rotear\-la no próximo destino de comando.  Se for uma mensagem padrão do windows, a mensagem será passado ao procedimento de janela padrão apropriado.  
  
 Para acelerar a correspondência retornadas mapa, a estrutura armazena em cachê correspondências recentes na probabilidade que receberá a mesma mensagem novamente.  Uma resultado dessa é a estrutura que processa mensagens não manipulado suficiente eficiente.  Os mapas de mensagem também são espaço mais eficientes do que as implementações que usam funções virtuais.  
  
## Consulte também  
 [Como o Framework pesquisa mapas de mensagem](../mfc/how-the-framework-searches-message-maps.md)