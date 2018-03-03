---
title: "Posição do Item de controle de árvore | Microsoft Docs"
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
- CTreeCtrl class [MFC], item position
- item position in tree controls
- tree controls [MFC], item position
- position, CTreeCtrl items
ms.assetid: cd264344-2cf9-4d90-9ea8-c6900b6f60e7
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: db47e27ad0b556e08f51685bf84b6bd998722239
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tree-control-item-position"></a>Posição do item de controle de árvore
Posição inicial do item é definida quando o item é adicionado ao controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) usando o `InsertItem` função de membro. A chamada de função de membro Especifica o identificador do item pai e o identificador do item após o qual o novo item é inserido. O segundo identificador deve identificar um item filho do pai especificado ou um desses valores: `TVI_FIRST`, `TVI_LAST`, ou `TVI_SORT`.  
  
 Quando `TVI_FIRST` ou `TVI_LAST` for especificado, o controle de árvore coloca o novo item no início ou no final da lista do item pai específico de itens filho. Quando `TVI_SORT` for especificado, o controle de árvore insere o novo item na lista de itens filho em ordem alfabética com base no texto dos rótulos de item.  
  
 Você pode colocar a lista de um item pai de itens filho em ordem alfabética chamando o [SortChildren](../mfc/reference/ctreectrl-class.md#sortchildren) função de membro. Essa função inclui um parâmetro que especifica se todos os níveis de itens filho em ordem decrescente do item pai determinado também são classificados em ordem alfabética.  
  
 O [SortChildrenCB](../mfc/reference/ctreectrl-class.md#sortchildrencb) função membro permite classificar itens filho com base em critérios que você definir. Quando você chamar essa função, você pode especificar uma função de retorno de chamada definido pelo aplicativo que o controle de árvore pode chamar sempre que a ordem relativa dos dois itens filho precisa ser decidida. A função de retorno de chamada recebe dois valores definidos pelo aplicativo de 32 bits para os itens que estão sendo comparados e um terceiro valor de 32 bits que você especificar ao chamar `SortChildrenCB`.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTreeCtrl](../mfc/using-ctreectrl.md)   
 [Controles](../mfc/controls-mfc.md)

