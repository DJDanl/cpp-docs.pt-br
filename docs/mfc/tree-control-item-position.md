---
title: Posição do item de controle de árvore
ms.date: 11/04/2016
helpviewer_keywords:
- CTreeCtrl class [MFC], item position
- item position in tree controls
- tree controls [MFC], item position
- position, CTreeCtrl items
ms.assetid: cd264344-2cf9-4d90-9ea8-c6900b6f60e7
ms.openlocfilehash: 238cb40319d28a53592a594a72947f400720f935
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62392473"
---
# <a name="tree-control-item-position"></a>Posição do item de controle de árvore

Posição inicial de um item é definida quando o item é adicionado ao controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) usando o `InsertItem` função de membro. A chamada de função de membro Especifica o identificador do item pai e o identificador do item após o qual o novo item deve ser inserido. O segundo identificador deve identificar um item filho do pai especificado ou um desses valores: `TVI_FIRST`, `TVI_LAST`, ou `TVI_SORT`.

Quando `TVI_FIRST` ou `TVI_LAST` for especificado, o controle de árvore coloca o novo item no início ou no final da lista do item pai fornecido dos itens filhos. Quando `TVI_SORT` for especificado, o controle de árvore insere o novo item na lista de itens filho em ordem alfabética com base no texto dos rótulos de item.

Você pode colocar lista de um item pai dos itens filhos em ordem alfabética por meio da chamada a [SortChildren](../mfc/reference/ctreectrl-class.md#sortchildren) função de membro. Essa função inclui um parâmetro que especifica se todos os níveis de itens filho em ordem decrescente do item pai de determinado também são classificados em ordem alfabética.

O [SortChildrenCB](../mfc/reference/ctreectrl-class.md#sortchildrencb) função de membro permite que você classifique os itens filhos com base nos critérios que você definir. Quando você chama essa função, você pode especificar uma função de retorno de chamada definida pelo aplicativo que o controle de árvore pode chamar sempre que a ordem relativa de dois itens filho precisa ser decidida. A função de retorno de chamada recebe dois valores definidos pelo aplicativo de 32 bits para os itens que estão sendo comparados e um terceiro valor de 32 bits que você especificar ao chamar `SortChildrenCB`.

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](../mfc/using-ctreectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
