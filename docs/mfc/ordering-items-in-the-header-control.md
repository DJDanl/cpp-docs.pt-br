---
title: Ordenando itens no controle de cabeçalho
ms.date: 11/04/2016
f1_keywords:
- DS_DRAGDROP
helpviewer_keywords:
- sequence [MFC]
- sequence [MFC], header control items
- OrderToIndex method [MFC]
- DS_DRAGDROP notification [MFC]
- GetOrderArray method [MFC]
- SetOrderArray method [MFC]
- header controls [MFC], ordering items
ms.assetid: 5aaef872-75b5-49c5-8fed-6f9a81fca812
ms.openlocfilehash: c4b4711729c6c3a4b63d4ad05252a5c49df98a0c
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84622130"
---
# <a name="ordering-items-in-the-header-control"></a>Ordenando itens no controle de cabeçalho

Depois de [Adicionar itens a um controle de cabeçalho](adding-items-to-the-header-control.md), você pode manipular ou obter informações sobre seu pedido com as seguintes funções:

- [CHeaderCtrl:: GetOrderArray](reference/cheaderctrl-class.md#getorderarray) e [CHeaderCtrl:: SetOrderArray](reference/cheaderctrl-class.md#setorderarray)

   Recupera e define a ordem da esquerda para a direita dos itens de cabeçalho.

- [CHeaderCtrl:: OrderToIndex](reference/cheaderctrl-class.md#ordertoindex).

   Recupera o valor de índice para um item de cabeçalho específico.

Além das funções de membro anteriores, o estilo de HDS_DRAGDROP permite que o usuário arraste e solte itens de cabeçalho dentro do controle de cabeçalho. Para obter mais informações, consulte [fornecendo suporte ao arrastar e soltar para itens de cabeçalho](providing-drag-and-drop-support-for-header-items.md).

## <a name="see-also"></a>Consulte também

[Usando CHeaderCtrl](using-cheaderctrl.md)
