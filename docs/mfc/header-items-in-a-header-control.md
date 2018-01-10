---
title: "Itens de cabeçalho em um controle de cabeçalho | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- header controls [MFC], header items in
- header items in header controls [MFC]
- CHeaderCtrl class [MFC], header items in
- controls [MFC], header
ms.assetid: ac79ef1f-a671-4ab2-93e9-b1aa016a48bf
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c2143a89d9b91c9c6db53beedce0875ee76f34cc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="header-items-in-a-header-control"></a>Itens de cabeçalho em um controle de cabeçalho
Você tem controle considerável sobre a aparência e o comportamento dos itens de cabeçalho que compõem um controle de cabeçalho ([CHeaderCtrl](../mfc/reference/cheaderctrl-class.md)). Cada item de cabeçalho pode ter uma cadeia de caracteres, uma imagem de bitmap, uma imagem de uma lista de imagens associado ou um valor de 32 bits definido pelo aplicativo associado a ele. A cadeia de caracteres, bitmap ou imagem é exibida no item de cabeçalho.  
  
 Você pode personalizar a aparência e o conteúdo de novos itens quando eles são criados, fazendo uma chamada [CHeaderCtrl::InsertItem](../mfc/reference/cheaderctrl-class.md#insertitem) ou modificando um item existente, com uma chamada para [CHeaderCtrl::GetItem](../mfc/reference/cheaderctrl-class.md#getitem) e [ CHeaderCtrl::SetItem](../mfc/reference/cheaderctrl-class.md#setitem).  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Personalizando a aparência do item de cabeçalho](../mfc/customizing-the-header-item-s-appearance.md)  
  
-   [Ordenando itens no controle de cabeçalho](../mfc/ordering-items-in-the-header-control.md)  
  
-   [Dando suporte a arrastar e soltar para itens de cabeçalho](../mfc/providing-drag-and-drop-support-for-header-items.md)  
  
-   [Usando listas de imagens com controles de cabeçalho](../mfc/using-image-lists-with-header-controls.md)  
  
## <a name="see-also"></a>Consulte também  
 [Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)

