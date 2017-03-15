---
title: "Destruindo objetos de janela | Microsoft Docs"
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
  - "janelas com moldura, destruindo"
  - "objetos de janela, excluindo"
  - "objetos de janela, destruindo"
  - "objetos de janela, removendo"
ms.assetid: 3241fea0-c614-4a25-957d-20f21bd5fd0c
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Destruindo objetos de janela
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Deve ser feito com suas próprias janelas filho para destruir o objeto da janela C\+\+ quando o usuário for concluído com a janela.  Se esses objetos não são destruídos, o aplicativo não recuperará sua memória.  Felizmente, a estrutura gerencia a destruição bem como a criação da janela para o windows do quadro, exibições, e caixas de diálogo.  Se você criar janelas adicionais, você é responsável por destrui\-las.  
  
## Que você deseja saber mais?  
  
-   [Sequência de destruição da janela](../mfc/window-destruction-sequence.md)  
  
-   [Atribuindo e desalocando a memória da janela](../mfc/allocating-and-deallocating-window-memory.md)  
  
-   [Desanexando um CWnd do HWND](../Topic/Detaching%20a%20CWnd%20from%20Its%20HWND.md)  
  
-   [Sequência geral de criação da janela](../mfc/general-window-creation-sequence.md)  
  
-   [Janelas de destruição do quadro](../mfc/destroying-frame-windows.md)  
  
## Consulte também  
 [Objetos de janela](../mfc/window-objects.md)