---
title: Usando CImageList
ms.date: 11/04/2016
f1_keywords:
- CImageList
helpviewer_keywords:
- image list control
- CImageList class [MFC], using
ms.assetid: 3d2a909e-d641-46b7-aada-81cab1a29b41
ms.openlocfilehash: c3e4cec75ce23beb2a617d672170f86c608ca0a2
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57294584"
---
# <a name="using-cimagelist"></a>Usando CImageList

Uma lista de imagens, representada pela classe [CImageList](../mfc/reference/cimagelist-class.md), é uma coleção de imagens do mesmo tamanho, cada um dos quais pode ser referenciada por seu índice. Listas de imagens são usadas para gerenciar com eficiência grandes conjuntos de ícones ou bitmaps. Listas de imagem são por si próprios controles desde que eles não sejam windows; No entanto, eles são usados com vários tipos diferentes de controles, incluindo controles de lista ([CListCtrl](../mfc/reference/clistctrl-class.md)), controles de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) e controles de guia ([CTabCtrl](../mfc/reference/ctabctrl-class.md)).

Todas as imagens em uma lista de imagens estão contidas em um bitmap único e amplo no formato de dispositivo da tela. Uma lista de imagens também pode incluir um bitmap monocromático que contém as máscaras usadas para desenhar imagens de maneira transparente (estilo de ícone). `CImageList` fornece funções de membro que permitem que você desenhar imagens, criar e destruir a listas de imagens, adicionar e remover imagens, substitua imagens, imagens de mesclagem e arrastar imagens.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Tipos de listas de imagens](../mfc/types-of-image-lists.md)

- [Usando uma lista de imagens](../mfc/using-an-image-list.md)

- [Manipulando listas de imagens](../mfc/manipulating-image-lists.md)

- [Desenhando imagens de uma lista de imagens](../mfc/drawing-images-from-an-image-list.md)

- [Sobreposições de imagem em listas de imagens](../mfc/image-overlays-in-image-lists.md)

- [Arrastando imagens de uma lista de imagens](../mfc/dragging-images-from-an-image-list.md)

- [Informações da imagem em listas de imagens](../mfc/image-information-in-image-lists.md)

## <a name="see-also"></a>Consulte também

[Controles](../mfc/controls-mfc.md)
