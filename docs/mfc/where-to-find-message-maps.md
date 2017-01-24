---
title: "Onde encontrar mapas de mensagens | Microsoft Docs"
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
  - "localizando mapas de mensagem"
  - "Macros , mapa de mensagem"
  - "mapas de mensagem, localizando"
  - "macros de mapa de mensagem"
ms.assetid: bf59fbc8-b222-42d3-b5d3-0a79aa3cb923
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Onde encontrar mapas de mensagens
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você cria um novo aplicativo do esqueleto com o assistente de aplicativo, o assistente de aplicativo grava um mapa de mensagem para cada classe de comando\- destino criada para você.  Isso inclui seu aplicativo, o documento, exibição, e classes derivadas de quadro\- janela.  Alguns desses mapas de mensagem já têm entradas fornecidas pela mensagens do assistente do aplicativo para determinadas por comandos e predefinidos, e alguns são apenas espaços reservados para manipuladores que você adicionará.  
  
 O mapa de uma classe é localizado no arquivo de .CPP da classe.  Trabalhando com mapas básicos de mensagem que o assistente de aplicativo cria, você usa a janela Propriedades para adicionar entradas para as mensagens e comandos que tratará cada classe.  Um mapa típico da mensagem pode ter esta aparência depois que você adicionar algumas entradas:  
  
 [!CODE [NVC_MFCMessageHandling#1](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCMessageHandling#1)]  
  
 O mapa da mensagem consiste em uma coleção de macros.  Dois macros, [BEGIN\_MESSAGE\_MAP](../Topic/BEGIN_MESSAGE_MAP.md) e [END\_MESSAGE\_MAP](../Topic/END_MESSAGE_MAP.md), oferecem suporte ao mapa da mensagem.  Outros macros, como `ON_COMMAND`, preenche o conteúdo da mensagem.  
  
> [!NOTE]
>  Macros retornadas mapa não são seguidas por ponto\-e\-vírgula.  
  
 Quando você usar o assistente para adicionar classe para criar uma nova classe, fornece um mapa de mensagem da classe.  Como alternativa, você pode criar um mapa de mensagem manualmente usando o editor de origem.  
  
## Consulte também  
 [Como o Framework pesquisa mapas de mensagem](../mfc/how-the-framework-searches-message-maps.md)