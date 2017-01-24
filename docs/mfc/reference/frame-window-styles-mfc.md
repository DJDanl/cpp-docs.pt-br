---
title: "Estilos de janela com moldura (MFC) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "FWS_ADDTOTITLE"
  - "FWS_SNAPTOBARS"
  - "FWS_PREFIXTITLE"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "janelas com moldura, estilos"
  - "Constante FWS_ADDTOTITLE"
  - "Constante FWS_PREFIXTITLE"
  - "Constante FWS_SNAPTOBARS"
  - "estilos, janelas"
ms.assetid: d21f270e-a088-4962-a2ae-8c03334b5a06
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estilos de janela com moldura (MFC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

-   **FWS\_ADDTOTITLE** especifique as informações para anexar ao final de um título da janela do quadro.  Por exemplo, “descompasso Microsoft \- desenho em Document1”.  Você pode especificar as cadeias de caracteres exibidas na guia de cadeias de caracteres de modelo de documento no assistente do aplicativo.  Se você precisar desligar essa opção, substitua a função de membro de `CWnd::PreCreateWindow` .  
  
-   **FWS\_PREFIXTITLE** mostra o nome do documento antes que o nome do aplicativo em um título da janela do quadro.  Por exemplo, “documento \- WordPad”.  Você pode especificar as cadeias de caracteres exibidas na guia de cadeias de caracteres de modelo de documento no assistente do aplicativo.  Se você precisar desligar essa opção, substitua a função de membro de `CWnd::PreCreateWindow` .  
  
-   Dimensionamento dos controles de**FWS\_SNAPTOBARS**da janela do tableau que inclui uma barra de controle quando está em uma janela flutuante em vez de entrada para uma janela do quadro.  Esse estilo faz dimensionar a janela para caber na barra de controle.  
  
## Consulte também  
 [Estilos usados pelo MFC](../../mfc/reference/styles-used-by-mfc.md)