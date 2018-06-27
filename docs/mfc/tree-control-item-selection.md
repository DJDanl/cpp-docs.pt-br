---
title: Seleção de Item de controle de árvore | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- tree controls [MFC], item selection
- controls [MFC], selecting items in
- CTreeCtrl class [MFC], item selection
- item selection in tree controls
ms.assetid: 7bcb3b16-b9c8-4c06-9350-7bc3c1c5009b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fc533046695db409067ff603e30cedbe11ad5ca4
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36953551"
---
# <a name="tree-control-item-selection"></a>Seleção do item de controle de árvore
Quando a seleção é alterada de um item para outro, um controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) envia [TVN_SELCHANGING](http://msdn.microsoft.com/library/windows/desktop/bb773547) e [TVN_SELCHANGED](http://msdn.microsoft.com/library/windows/desktop/bb773544) mensagens de notificação. Ambas as notificações incluem um valor que especifica se a alteração é o resultado de um clique do mouse ou um pressionamento de tecla. As notificações também incluem informações sobre o item que está obtendo a seleção e o item que está perdendo a seleção. Você pode usar essas informações para definir atributos de itens que dependem do estado de seleção do item. Retornando **TRUE** em resposta a `TVN_SELCHANGING` impede que a seleção alteração; retornando **FALSE** permite a alteração.  
  
 Um aplicativo pode alterar a seleção chamando o [SelectItem](../mfc/reference/ctreectrl-class.md#selectitem) função de membro.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTreeCtrl](../mfc/using-ctreectrl.md)   
 [Controles](../mfc/controls-mfc.md)

