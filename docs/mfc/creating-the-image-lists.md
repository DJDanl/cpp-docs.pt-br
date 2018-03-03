---
title: Criando as listas de imagens | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- CListCtrl class [MFC], creating image lists for
- image lists [MFC], creating for CListCtrl
- lists [MFC], image
ms.assetid: c2768515-deba-49e8-a6f3-5be6482afb19
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: bfb42dc2c14b5092aeb667ea22008abe4d581a6f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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

