---
title: "Seleção de Item de controle de árvore | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- tree controls [MFC], item selection
- controls [MFC], selecting items in
- CTreeCtrl class [MFC], item selection
- item selection in tree controls
ms.assetid: 7bcb3b16-b9c8-4c06-9350-7bc3c1c5009b
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: fac551ed757cf0510f0a8b61522bc969c6b6be6d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="tree-control-item-selection"></a>Seleção do item de controle de árvore
Quando a seleção é alterada de um item para outro, um controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) envia [TVN_SELCHANGING](http://msdn.microsoft.com/library/windows/desktop/bb773547) e [TVN_SELCHANGED](http://msdn.microsoft.com/library/windows/desktop/bb773544) mensagens de notificação. Ambas as notificações incluem um valor que especifica se a alteração é o resultado de um clique do mouse ou um pressionamento de tecla. As notificações também incluem informações sobre o item que está obtendo a seleção e o item que está perdendo a seleção. Você pode usar essas informações para definir atributos de itens que dependem do estado de seleção do item. Retornando **TRUE** em resposta a **TVN_SELCHANGING** impede que a seleção alteração; retornando **FALSE** permite a alteração.  
  
 Um aplicativo pode alterar a seleção chamando o [SelectItem](../mfc/reference/ctreectrl-class.md#selectitem) função de membro.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTreeCtrl](../mfc/using-ctreectrl.md)   
 [Controles](../mfc/controls-mfc.md)

