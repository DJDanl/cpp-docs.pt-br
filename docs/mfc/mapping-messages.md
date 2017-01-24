---
title: "Mapeando mensagens | Microsoft Docs"
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
  - "mapeamento de comando"
  - "comandos, conectando a funções de manipulador"
  - "comandos, mapeamento"
  - "mapeamentos, comandos"
  - "mapeamentos, mensagens"
  - "lidando com erros, conectando a funções de manipulador"
  - "mapas de mensagem, sobre mapas de mensagem"
  - "mensagens, mapeamento"
ms.assetid: 996f0652-0698-4b8c-b893-cdaa836d9d0f
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Mapeando mensagens
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cada classe da estrutura que pode receber mensagens ou comandos tem seus próprios do mapa mensagem “.” A estrutura usa mapas de mensagem para mensagens e comandos se conectar às suas funções do manipulador.  Qualquer classe derivada da classe `CCmdTarget` pode ter um mapa da mensagem.  Outros artigos explicam mapas de mensagem em detalhes e descrevem como usá\-los.  
  
 Apesar do nome do mapa mensagem “,” mapas de mensagem controla as mensagens e os comandos — todas as três categorias de mensagens listadas em [Categorias de mensagem](../mfc/message-categories.md).  
  
## Consulte também  
 [Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)