---
title: "Usando CImageList | Microsoft Docs"
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
  - "CImageList"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CImageList, usando"
  - "controle de lista de imagens"
ms.assetid: 3d2a909e-d641-46b7-aada-81cab1a29b41
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando CImageList
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma lista de imagem, representada pela classe [CImageList](../Topic/CImageList%20Class.md), é uma coleção das imagens mesmo feitas em cada medida, que podem ser referidas por seu índice.  As listas de imagem são usadas para gerenciar bem grandes conjuntos de ícones ou de bitmaps.  As listas não são próprias de imagem controles desde que não são windows; no entanto, eles são usados com vários tipos diferentes de controles, inclusive controles da lista[CListCtrl](../Topic/CListCtrl%20Class.md)\(\), controles de árvore \([CTreeCtrl](../mfc/reference/ctreectrl-class.md)\), e controles da guia \([CTabCtrl](../Topic/CTabCtrl%20Class.md)\).  
  
 Todas as imagens em uma lista de imagens são contidas em um único, bitmap amplo no formato do dispositivo em tela.  Uma lista de imagem também pode incluir um bitmap monocromático que contém as máscaras usadas para desenhar transparente imagens \(estilo de ícone\).  `CImageList` fornece as funções de membro que permitem para desenhar imagens, criar e destruir listas da imagem, para adicionar e remover imagens, para substituir imagens, para mesclar imagens, e para arrastar imagens.  
  
## Que você deseja saber mais?  
  
-   [Tipos de listas de imagem](../Topic/Types%20of%20Image%20Lists.md)  
  
-   [Usando uma lista de imagem](../mfc/using-an-image-list.md)  
  
-   [Listas de manipulação de imagem](../mfc/manipulating-image-lists.md)  
  
-   [Desenhando imagens de uma lista de imagem](../mfc/drawing-images-from-an-image-list.md)  
  
-   [Sobreposições de imagem em listas de imagem](../mfc/image-overlays-in-image-lists.md)  
  
-   [Arrastando imagens de uma lista de imagem](../Topic/Dragging%20Images%20from%20an%20Image%20List.md)  
  
-   [Informações de imagem em listas de imagem](../mfc/image-information-in-image-lists.md)  
  
## Consulte também  
 [Controles](../mfc/controls-mfc.md)