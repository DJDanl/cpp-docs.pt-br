---
title: "Quando inicializar objetos CWnd | Microsoft Docs"
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
  - "Objetos CWnd, quando HWND está anexado"
  - "Objetos CWnd, quando inicializar"
  - "HWND, quando anexado a objeto CWnd"
  - "inicializando objetos CWnd"
  - "inicializando objetos, CWnd"
  - "objetos de janela, quando inicializar CWnd"
ms.assetid: 4d31bcb1-73db-4f2f-b71c-89b087569a10
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Quando inicializar objetos CWnd
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você não pode criar suas próprias janelas filho ou chamar qualquer função de API do windows no construtor de `CWnd`\- objeto derivada.  Isso ocorre porque `HWND` para o objeto de `CWnd` ainda não foi criado.  A maioria de inicialização o específica, como adicionar janelas filho, deve ser feita em um manipulador de mensagens de [OnCreate](../Topic/CWnd::OnCreate.md) .  
  
## Que você deseja saber mais?  
  
-   [Criando o windows do quadro do documento](../Topic/Creating%20Document%20Frame%20Windows.md)  
  
-   [Criação de documento\/exibição](../mfc/document-view-creation.md)  
  
## Consulte também  
 [Usando janelas com moldura](../Topic/Using%20Frame%20Windows.md)