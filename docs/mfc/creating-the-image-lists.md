---
title: Criando as listas de imagens | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CListCtrl class [MFC], creating image lists for
- image lists [MFC], creating for CListCtrl
- lists [MFC], image
ms.assetid: c2768515-deba-49e8-a6f3-5be6482afb19
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 53cf33a551dc95e7ed282b599673f627ff8a7b21
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43220931"
---
# <a name="creating-the-image-lists"></a>Criando as listas de imagens
Criando listas de imagens é o mesmo se você usar [CListView](../mfc/reference/clistview-class.md) ou [CListCtrl](../mfc/reference/clistctrl-class.md).  
  
> [!NOTE]
>  Você só precisa imagem listas se seu controle lista inclui o `LVS_ICON` estilo.  
  
 Use a classe `CImageList` para criar um ou mais listas de imagens (para os ícones em tamanho normal, ícones pequenos e estados). Ver [CImageList](../mfc/reference/cimagelist-class.md)e veja [listas de imagens do modo de exibição de lista](/windows/desktop/Controls/using-list-view-controls) no SDK do Windows.  
  
 Chame [CListCtrl::SetImageList](../mfc/reference/clistctrl-class.md#setimagelist) para cada lista de imagem; passar um ponteiro para o apropriada `CImageList` objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CListCtrl](../mfc/using-clistctrl.md)   
 [Controles](../mfc/controls-mfc.md)

