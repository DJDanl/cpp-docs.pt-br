---
title: Usando CImageList
ms.date: 11/04/2016
helpviewer_keywords:
- image list control
- CImageList class [MFC], using
ms.assetid: 3d2a909e-d641-46b7-aada-81cab1a29b41
ms.openlocfilehash: 09fd0e95ce2981afbebbfe10d87b26f88a7b5e13
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447231"
---
# <a name="using-cimagelist"></a>Usando CImageList

Uma lista de imagens, representada pela classe [CImageList](../mfc/reference/cimagelist-class.md), é uma coleção de imagens de mesmo tamanho, cada uma das quais pode ser referenciada por seu índice. As listas de imagens são usadas para gerenciar com eficiência grandes conjuntos de ícones ou bitmaps. As listas de imagens não são controles propriamente ditos, pois não são janelas; no entanto, eles são usados com vários tipos diferentes de controles, incluindo controles de lista ([CListCtrl](../mfc/reference/clistctrl-class.md)), controles de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) e controles de guia ([CTabCtrl](../mfc/reference/ctabctrl-class.md)).

Todas as imagens em uma lista de imagens estão contidas em um único bitmap largo no formato de dispositivo de tela. Uma lista de imagens também pode incluir um bitmap monocromático que contém máscaras usadas para desenhar imagens de forma transparente (estilo de ícone). `CImageList` fornece funções de membro que permitem desenhar imagens, criar e destruir listas de imagens, adicionar e remover imagens, substituir imagens, mesclar imagens e arrastar imagens.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Tipos de listas de imagens](../mfc/types-of-image-lists.md)

- [Usando uma lista de imagens](../mfc/using-an-image-list.md)

- [Manipulando listas de imagens](../mfc/manipulating-image-lists.md)

- [Desenhando imagens de uma lista de imagens](../mfc/drawing-images-from-an-image-list.md)

- [Sobreposições de imagem em listas de imagens](../mfc/image-overlays-in-image-lists.md)

- [Arrastando imagens de uma lista de imagens](../mfc/dragging-images-from-an-image-list.md)

- [Informações da imagem em listas de imagens](../mfc/image-information-in-image-lists.md)

## <a name="see-also"></a>Consulte também

[Controles](../mfc/controls-mfc.md)
