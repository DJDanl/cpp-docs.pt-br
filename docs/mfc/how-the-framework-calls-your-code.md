---
title: "Como o Framework chama o c&#243;digo | Microsoft Docs"
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
  - "eventos específicos de aplicativo [C++]"
  - "tratamento de comandos, chamando manipuladores e código em MFC"
  - "roteamento de comando, estrutura"
  - "roteamento de comando, MFC"
  - "fluxo de controle [C++], Estrutura MFC e seu código"
  - "eventos [C++], roteamento de comando em MFC"
  - "eventos [C++], programação controlada por evento"
  - "MFC [C++], chamando código"
  - "MFC [C++], chamando código a partir de"
ms.assetid: 39e68189-a580-40d0-9e35-bf5cd24a8ecf
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como o Framework chama o c&#243;digo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Também é essencial compreender a relação entre o código\-fonte e o código na estrutura de MFC.  Quando o aplicativo executa, a maior parte do fluxo de controle reside no código da estrutura.  A estrutura gerencia o loop de mensagem que recebe mensagens do windows como o usuário escolhe comandos e edita dados em uma exibição.  Os eventos que a estrutura pode manipular o sozinho não dependem de seu código de todos eles.  Por exemplo, a estrutura aprenderá como fechar janelas e sair do aplicativo em resposta aos comandos do usuário.  Como trata essas tarefas, a estrutura usar manipuladores de mensagem e funções virtuais C\+\+ para proporcionar oportunidades de responder a esses eventos também.  Seu código não está no controle; porém, a estrutura é.  
  
 A estrutura chama seu código para eventos específicos do aplicativo.  Por exemplo, quando o usuário escolhe um comando de menu a estrutura, roteia o comando ao longo de uma sequência de objetos C\+\+: a janela de exibição atual e do quadro, o documento associado à exibição, o documento documenta o modelo, e o objeto do aplicativo.  Se um desses objetos pode tratar o comando, faz isso, chamando a função apropriada retornadas a.  Para qualquer comando específico, o código chamado pode ser o vosso ou pode ser a estrutura.  
  
 Esse arranjo é um pouco familiar aos desenvolvedores experientes com a programação tradicional do windows ou a programação controlada por eventos.  
  
 Em tópicos relacionados, você leia o que faz inicializa a estrutura como e executa o aplicativo e limpa então enquanto o aplicativo termina.  Você também integrará o código onde você grava ajustes no.  
  
 Para obter mais informações, consulte [Classe CWinApp: A classe do aplicativo](../Topic/CWinApp:%20The%20Application%20Class.md) e [Modelos do documento e o processo de criação do documento\/exibição](../mfc/document-templates-and-the-document-view-creation-process.md).  
  
## Consulte também  
 [Aproveitando o Framework](../mfc/building-on-the-framework.md)