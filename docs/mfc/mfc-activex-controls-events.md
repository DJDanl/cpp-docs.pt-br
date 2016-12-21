---
title: "Controles ActiveX MFC: eventos | Microsoft Docs"
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
  - "Classe COleControl, tratamento de eventos"
  - "eventos de contêiner"
  - "eventos personalizados, Adicionando aos controles ActiveX"
  - "eventos [C++], Controles ActiveX"
  - "eventos [C++], mapeamento"
  - "mapeamentos, eventos"
  - "Controles ActiveX MFC, eventos"
  - "notificações [C++], notificando contêineres de eventos"
  - "Eventos OLE"
  - "eventos de estoque"
ms.assetid: e1e57e0c-206b-4923-a0b5-682c26564f74
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC: eventos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os controles ActiveX usam eventos para notificar um contêiner que algo ocorra ao controle.  Os exemplos comuns de eventos incluem clique no controle, dados inseridos usando o teclado, e as alterações no estado do controle.  Quando essas ações ocorrerem, o controle dispara um evento para alertar o contêiner.  
  
 Os eventos também são chamadas de mensagens.  
  
 MFC O oferece suporte a dois tipos de eventos: estoque e personalizados.  Os eventos de estoque são os eventos que classificam as alças de [COleControl](../mfc/reference/colecontrol-class.md) automaticamente.  Para obter uma lista completa dos eventos de estoque, consulte o artigo [Controles ActiveX MFC: Para adicionar os eventos de estoque](../Topic/MFC%20ActiveX%20Controls:%20Adding%20Stock%20Events%20to%20an%20ActiveX%20Control.md).  Os eventos personalizados permitem a um controle a capacidade de notificar o contêiner quando um específico de ação ocorre ao controle.  Alguns exemplos são uma alteração no estado interno de um controle ou de um recebimento de uma determinada mensagem da janela.  
  
 Para que o controle seja acionado eventos corretamente, a sua classe de controle deve mapear cada evento de controle para uma função de membro que deve ser chamada quando o evento relacionado ocorre.  Esse mecanismo de mapeamento \(chamado em um mapa de evento\) é centralizada informações sobre o evento e permite que o Visual Studio facilmente acessar e manipular os eventos do controle.  Esse mapa de evento é declarado pela macro, localizado em \(cabeçalho. H\) arquivo de declaração da classe de controle:  
  
 [!code-cpp[NVC_MFC_AxUI#2](../mfc/codesnippet/CPP/mfc-activex-controls-events_1.h)]  
  
 Depois que o mapa de evento foi declarado, deve ser definido no arquivo de implementação do controle .CPP \(\).  As seguintes linhas de código definem o mapa de evento, permitindo que o controle seja acionado eventos específicos:  
  
 [!code-cpp[NVC_MFC_AxUI#3](../mfc/codesnippet/CPP/mfc-activex-controls-events_2.cpp)]  
[!code-cpp[NVC_MFC_AxUI#4](../mfc/codesnippet/CPP/mfc-activex-controls-events_3.cpp)]  
  
 Se você usar o assistente de controle ActiveX de MFC para criar o projeto, o adiciona automaticamente essas linhas.  Se você não usar o assistente de controle ActiveX de MFC, você deve adicionar essas linhas manualmente.  
  
 A exibição da classe, você pode adicionar os eventos de estoque suportados pela classe `COleControl` ou eventos personalizados que você definir.  Para cada novo evento, a exibição da classe adiciona automaticamente a entrada apropriada para o mapa do evento de controle e arquivo de .IDL do controle.  
  
 Outros dois artigos a seguir discutem eventos em detalhes:  
  
-   [Controles ActiveX MFC: Para adicionar os eventos de estoque](../Topic/MFC%20ActiveX%20Controls:%20Adding%20Stock%20Events%20to%20an%20ActiveX%20Control.md)  
  
-   [Controles ActiveX MFC: Adicionando eventos personalizados](../Topic/MFC%20ActiveX%20Controls:%20Adding%20Custom%20Events.md)  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Controles ActiveX MFC: métodos](../mfc/mfc-activex-controls-methods.md)   
 [Classe de COleControl](../mfc/reference/colecontrol-class.md)