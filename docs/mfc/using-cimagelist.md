---
title: Usando CImageList | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- CImageList
dev_langs:
- C++
helpviewer_keywords:
- image list control
- CImageList class [MFC], using
ms.assetid: 3d2a909e-d641-46b7-aada-81cab1a29b41
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8dd30b21b1ec635c6d5b5f2f5c6c6d9eb6fc3fa7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33385785"
---
# <a name="using-cimagelist"></a>Usando CImageList
Uma lista de imagens, representada pela classe [CImageList](../mfc/reference/cimagelist-class.md), é uma coleção de imagens do mesmo tamanho, cada um deles pode ser referenciada por seu índice. Listas de imagens são usadas para gerenciar de maneira eficiente grandes conjuntos de ícones ou bitmaps. Listas de imagens são não controles já que não são windows. No entanto, eles são usados com vários tipos diferentes de controles, incluindo controles de lista ([CListCtrl](../mfc/reference/clistctrl-class.md)), controles de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) e controles de guia ([CTabCtrl](../mfc/reference/ctabctrl-class.md)).  
  
 Todas as imagens em uma lista de imagens estão contidas em um bitmap único de largura no formato de tela de dispositivo. Uma lista de imagens também pode incluir um bitmap monocromático que contém as máscaras usadas para desenhar as imagens de forma transparente (estilo do ícone). `CImageList` fornece funções de membro que permitem que você desenhar imagens, criar e destruir listas de imagens, adicionar e remover imagens, substituir as imagens, imagens de mesclagem e arraste imagens.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Tipos de listas de imagens](../mfc/types-of-image-lists.md)  
  
-   [Usando uma lista de imagens](../mfc/using-an-image-list.md)  
  
-   [Manipulando listas de imagens](../mfc/manipulating-image-lists.md)  
  
-   [Desenhando imagens de uma lista de imagens](../mfc/drawing-images-from-an-image-list.md)  
  
-   [Sobreposições de imagem em listas de imagens](../mfc/image-overlays-in-image-lists.md)  
  
-   [Arrastando imagens de uma lista de imagens](../mfc/dragging-images-from-an-image-list.md)  
  
-   [Informações da imagem em listas de imagens](../mfc/image-information-in-image-lists.md)  
  
## <a name="see-also"></a>Consulte também  
 [Controles](../mfc/controls-mfc.md)

