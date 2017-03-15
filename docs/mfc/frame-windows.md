---
title: "Janelas com moldura | Microsoft Docs"
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
  - "Classe CFrameWnd, janelas com moldura"
  - "janelas de documento com moldura"
  - "janelas com moldura [C++]"
  - "janelas com moldura [C++], sobre janelas com moldura"
  - "MDI [C++], janelas com moldura"
  - "MFC [C++], janelas com moldura"
  - "single document interface (SDI)"
  - "single document interface (SDI), janelas com moldura"
  - "janelas separadoras, e janelas com moldura"
  - "exibições [C++], e janelas com moldura"
  - "classes de janela [C++], moldura"
  - "janelas [C++], MDI"
ms.assetid: 40677339-8135-4f5e-aba6-3fced3078077
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Janelas com moldura
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando um aplicativo executa no windows, o usuário interage com os documentos exibidos no windows do quadro.  Uma janela do quadro do documento tem dois componentes principais: o quadro e o conteúdo que enquadram.  Uma janela do quadro de documento pode ser uma janela do quadro de [interface de um único documento](../mfc/sdi-and-mdi.md) \(SDI\) ou uma janela filho de [ambiente MDI](../mfc/sdi-and-mdi.md) \(MDI\).  O windows gerencia a maioria da interação do usuário com a janela do quadro: mover e redimensionar a janela, fechar a, e minimizar\-la e maximizar.  Você gerencia o conteúdo dentro do quadro.  
  
## O windows e exibições do quadro  
 As janelas do quadro do da estrutura de MFC para conter exibições.  Os dois componentes — quadro e conteúdo — são representados e gerenciados por duas classes diferentes em MFC.  Uma classe de quadro\- janela gerencia o quadro, e uma classe de exibição gerencia o conteúdo.  A janela de exibição é um filho da janela do quadro.  Desenhando interação e outra do usuário com o documento ocorre na área de cliente da exibição, não a área de cliente da janela do quadro.  A janela do quadro fornece um quadro visível em torno de uma exibição, termina com uma barra de legenda e controles como um menu de controle, botões da janela de padrão para minimizar e maximizar a janela, e controles para redimensionar a janela.  Os “conteúdo” consistem na área de cliente da janela do, que é completamente ocupada por uma janela filho — a exibição.  A figura a seguir mostra a relação entre uma janela do quadro e uma exibição.  
  
 ![Modo de exibição de janela de quadro](../mfc/media/vc37fx1.png "vc37FX1")  
Janela e exibição do quadro  
  
## Janelas de quadro e janelas do separador  
 Outra organização comum é que a janela do quadro frame várias exibições, normalmente usando [janela do separador](../mfc/multiple-document-types-views-and-frame-windows.md).  Em uma janela do divisor, a área de cliente da janela do quadro é ocupada por uma janela do divisor, por sua vez que tenha várias janelas filho, os painéis, que são chamadas exibições.  
  
### Que você deseja saber mais?  
 **Tópicos gerais da janela do quadro**  
  
-   [Objetos da janela](../mfc/window-objects.md)  
  
-   [Classes da janela do quadro](../mfc/frame-window-classes.md)  
  
-   [As classes de Quadro\- janela criadas pelo assistente de aplicativo](../mfc/frame-window-classes-created-by-the-application-wizard.md)  
  
-   [Estilos da janela do quadro](../Topic/Frame-Window%20Styles%20\(C++\).md)  
  
-   [Que fazem o windows do quadro](../mfc/what-frame-windows-do.md)  
  
 **Tópicos em usar as janelas do quadro**  
  
-   [Usando o windows do quadro](../Topic/Using%20Frame%20Windows.md)  
  
-   [Criando o windows do quadro do documento](../Topic/Creating%20Document%20Frame%20Windows.md)  
  
-   [Janelas de destruição do quadro](../mfc/destroying-frame-windows.md)  
  
-   [Gerenciando janelas filho MDI](../mfc/managing-mdi-child-windows.md)  
  
-   [Gerenciando a exibição atual](../mfc/managing-the-current-view.md) em uma janela do tableau que contém mais de uma exibição  
  
-   [Gerenciando menus, barras de controle, e aceleradores \(outros objetos que compartilham o espaço da janela do quadro\)](../mfc/managing-menus-control-bars-and-accelerators.md)  
  
 **Tópicos sobre recursos especiais da janela do quadro**  
  
-   [Arrastando e removendo arquivos](../Topic/Dragging%20and%20Dropping%20Files%20in%20a%20Frame%20Window.md) do Explorador de Arquivos ou o gerenciador de arquivos em uma janela do quadro  
  
-   [Respondendo a troca dinâmicas de dados \(DDE\)](../mfc/responding-to-dynamic-data-exchange-dde.md)  
  
-   [Estados de Semimodal: Ajuda contextual do windows \(que orquestra outras ações da janela\)](../mfc/orchestrating-other-window-actions.md)  
  
-   [Estados de Semimodal: impressão e visualização de impressão \(que orquestram outras ações da janela\)](../mfc/orchestrating-other-window-actions.md)  
  
 **Tópicos em outros tipos do windows**  
  
-   [Usando exibições](../mfc/using-views.md)  
  
-   [Caixas de diálogo](../mfc/dialog-boxes.md)  
  
-   [Controles](../mfc/controls-mfc.md)  
  
## Consulte também  
 [Janelas](../mfc/windows.md)