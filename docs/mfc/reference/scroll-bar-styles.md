---
title: "Estilos de barra de rolagem | Microsoft Docs"
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
  - "SBS_VERT"
  - "SBS_SIZEBOXBOTTOMRIGHTALIGN"
  - "SBS_LEFTALIGN"
  - "SBS_RIGHTALIGN"
  - "SBS_TOPALIGN"
  - "SBS_SIZEBOXTOPLEFTALIGN"
  - "SBS_BOTTOMALIGN"
  - "SBS_SIZEBOX"
  - "SBS_HORZ"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Constante SBS_BOTTOMALIGN"
  - "Constante SBS_HORZ"
  - "Constante SBS_LEFTALIGN"
  - "Constante SBS_RIGHTALIGN"
  - "Constante SBS_SIZEBOX"
  - "Constante SBS_SIZEBOXBOTTOMRIGHTALIGN"
  - "Constante SBS_SIZEBOXTOPLEFTALIGN"
  - "Constante SBS_TOPALIGN"
  - "Constante SBS_VERT"
  - "barras de rolagem, estilos"
ms.assetid: 8bcde35b-387d-49ae-bdd6-7cda9f5dae26
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estilos de barra de rolagem
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

-   **SBS\_BOTTOMALIGN** usado com o estilo de **SBS\_HORZ** .  A borda inferior da barra de rolagem é alinhada com a borda inferior do retângulo especificado na função de membro de **Criar** .  A barra de rolagem tem a altura padrão para barras de rolagem do sistema.  
  
-   **SBS\_HORZ** designa uma barra de rolagem horizontal.  Se nem o estilo de **SBS\_BOTTOMALIGN** ou de **SBS\_TOPALIGN** for especificado, a barra de rolagem tem a altura, a largura, e a posição especificada na função de membro de **Criar** .  
  
-   **SBS\_LEFTALIGN** usado com o estilo de **SBS\_VERT** .  A borda esquerda da barra de rolagem é alinhada com a borda esquerda do retângulo especificado na função de membro de **Criar** .  A barra de rolagem tem a largura padrão para barras de rolagem do sistema.  
  
-   **SBS\_RIGHTALIGN** usado com o estilo de **SBS\_VERT** .  A borda direita da barra de rolagem é alinhada com a borda direita do retângulo especificado na função de membro de **Criar** .  A barra de rolagem tem a largura padrão para barras de rolagem do sistema.  
  
-   **SBS\_SIZEBOX** designa uma caixa de tamanho.  Se nem o estilo de **SBS\_SIZEBOXBOTTOMRIGHTALIGN** ou de **SBS\_SIZEBOXTOPLEFTALIGN** for especificado, a caixa de tamanho tem a altura, a largura, e a posição especificada na função de membro de **Criar** .  
  
-   **SBS\_SIZEBOXBOTTOMRIGHTALIGN** usado com o estilo de **SBS\_SIZEBOX** .  O canto inferior direito da caixa de tamanho é alinhado com o canto direito inferior do retângulo especificado na função de membro de **Criar** .  A caixa de tamanho tem o tamanho padrão para caixas de tamanho do sistema.  
  
-   **SBS\_SIZEBOXTOPLEFTALIGN** usado com o estilo de **SBS\_SIZEBOX** .  O canto superior esquerdo da caixa de tamanho é alinhado com o canto superior esquerdo do retângulo especificado na função de membro de **Criar** .  A caixa de tamanho tem o tamanho padrão para caixas de tamanho do sistema.  
  
-   **SBS\_SIZEGRIP** mesmos que **SBS\_SIZEBOX**, mas com uma borda em alto\-relevo.  
  
-   **SBS\_TOPALIGN** usado com o estilo de **SBS\_HORZ** .  A borda superior da barra de rolagem é alinhada com a borda superior do retângulo especificado na função de membro de **Criar** .  A barra de rolagem tem a altura padrão para barras de rolagem do sistema.  
  
-   **SBS\_VERT** designa uma barra de rolagem vertical.  Se nem o estilo de **SBS\_RIGHTALIGN** ou de **SBS\_LEFTALIGN** for especificado, a barra de rolagem tem a altura, a largura, e a posição especificada na função de membro de **Criar** .  
  
## Consulte também  
 [Estilos usados pelo MFC](../../mfc/reference/styles-used-by-mfc.md)   
 [CScrollBar::Create](../Topic/CScrollBar::Create.md)   
 [Scroll Bar Control Styles](http://msdn.microsoft.com/library/windows/desktop/bb787533)