---
title: "Ordenando itens no controle de cabeçalho | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- DS_DRAGDROP
dev_langs:
- C++
helpviewer_keywords:
- sequence [MFC]
- sequence [MFC], header control items
- OrderToIndex method [MFC]
- DS_DRAGDROP notification [MFC]
- GetOrderArray method [MFC]
- SetOrderArray method [MFC]
- header controls [MFC], ordering items
ms.assetid: 5aaef872-75b5-49c5-8fed-6f9a81fca812
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 48adbc53ad0e4974edd86d3f8a96d74214093dda
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ordering-items-in-the-header-control"></a>Ordenando itens no controle de cabeçalho
Depois que você [adicionar itens a um controle de cabeçalho](../mfc/adding-items-to-the-header-control.md), você pode manipular ou obter informações sobre sua ordem com as seguintes funções:  
  
-   [CHeaderCtrl::GetOrderArray](../mfc/reference/cheaderctrl-class.md#getorderarray) e [CHeaderCtrl::SetOrderArray](../mfc/reference/cheaderctrl-class.md#setorderarray)  
  
     Recupera e define a ordem da esquerda para a direita de itens de cabeçalho.  
  
-   [CHeaderCtrl::OrderToIndex](../mfc/reference/cheaderctrl-class.md#ordertoindex).  
  
     Recupera o valor de índice de um item de cabeçalho específico.  
  
 Além das funções de membro anterior, o `HDS_DRAGDROP` estilo permite ao usuário arrastar e soltar itens de cabeçalho dentro do controle de cabeçalho. Para obter mais informações, consulte [dando suporte a arrastar e soltar para itens de cabeçalho](../mfc/providing-drag-and-drop-support-for-header-items.md).  
  
## <a name="see-also"></a>Consulte também  
 [Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)

