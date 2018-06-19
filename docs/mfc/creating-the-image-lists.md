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
ms.openlocfilehash: 8e5f5ac8396c32e56e4c0f2f951f45bb33714822
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33341519"
---
# <a name="creating-the-image-lists"></a>Criando as listas de imagens
Criar listas de imagens é o mesmo se você usar [CListView](../mfc/reference/clistview-class.md) ou [CListCtrl](../mfc/reference/clistctrl-class.md).  
  
> [!NOTE]
>  Você só precisa de imagem listas se o controle de lista inclui o `LVS_ICON` estilo.  
  
 Use a classe `CImageList` para criar uma ou mais listas de imagens (para estados, ícones pequenos e ícones em tamanho normal). Consulte [CImageList](../mfc/reference/cimagelist-class.md)e consulte [listas de imagens de exibição de lista](http://msdn.microsoft.com/library/windows/desktop/bb774736) no SDK do Windows.  
  
 Chamar [CListCtrl::SetImageList](../mfc/reference/clistctrl-class.md#setimagelist) para cada lista de imagem; transmitir um ponteiro para apropriada `CImageList` objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CListCtrl](../mfc/using-clistctrl.md)   
 [Controles](../mfc/controls-mfc.md)

