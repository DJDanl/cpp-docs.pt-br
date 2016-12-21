---
title: "Usando listas de imagens em um controle da barra de ferramentas | Microsoft Docs"
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
  - "Classe CToolBarCtrl, listas de imagens"
  - "listas de imagens [C++], controles de barra de ferramentas"
  - "controles de barra de ferramentas [MFC], imagem"
ms.assetid: ccbe8df4-4ed9-4b54-bb93-9a1dcb3b97eb
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando listas de imagens em um controle da barra de ferramentas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Por padrão, as imagens usadas pelos botões em um controle da barra de ferramentas são armazenadas como um único bitmap.  No entanto, você também pode armazenar imagens no botão em um conjunto de listas da imagem.  O objeto control da barra de ferramentas pode usar até três listas separadas de imagem:  
  
-   A lista habilitado da imagem contém imagens para os botões da barra de ferramentas que estão habilitados no momento.  
  
-   Desabilitado na imagem à lista contêm imagens para os botões da barra de ferramentas que estão desabilitados no momento.  
  
-   A lista realçado de imagem contém imagens para os botões da barra de ferramentas que são realçados no momento.  Esta lista de imagem é usada apenas quando a barra de ferramentas usa o estilo de **TBSTYLE\_FLAT** .  
  
 Essas listas de imagem são usadas pelo controle da barra de ferramentas quando você o associa ao objeto de `CToolBarCtrl` .  Essa associação é feita fazer chamadas a [CToolBarCtrl::SetImageList](../Topic/CToolBarCtrl::SetImageList.md), a [SetDisabledImageList](../Topic/CToolBarCtrl::SetDisabledImageList.md), e a [SetHotImageList](../Topic/CToolBarCtrl::SetHotImageList.md).  
  
 Por padrão, o MFC usa a classe de `CToolBar` para implementar barras de ferramentas do aplicativo MFC.  Entretanto, a função de membro de `GetToolBarCtrl` pode ser usada para recuperar o objeto inserido de `CToolBarCtrl` .  Você pode fazer chamadas às funções de membro de `CToolBarCtrl` usando o objeto retornado.  
  
 O exemplo a seguir demonstra esta técnica atribuindo uma lista`m_ToolBarImages`habilitado \(\) e desabilitada de imagem \(de`m_ToolBarDisabledImages`\) a um objeto de `CToolBarCtrl` \(`m_ToolBarCtrl`\).  
  
 [!code-cpp[NVC_MFCControlLadenDialog#35](../mfc/codesnippet/CPP/using-image-lists-in-a-toolbar-control_1.cpp)]  
  
> [!NOTE]
>  As listas de imagem usadas pelo objeto da barra de ferramentas devem ser objetos permanentes.  Por esse motivo, geralmente são membros de dados de uma classe de MFC; neste exemplo, a classe da janela principal do quadro.  
  
 As listas de imagem são associadas uma vez com o objeto de `CToolBarCtrl` , a estrutura são exibidos automaticamente a imagem adequada do botão.  
  
## Consulte também  
 [Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)