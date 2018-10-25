---
title: Ordenando itens no controle de cabeçalho | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 60139821c1b15673fac0fb8f9ec3925cbfa6dc31
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50052091"
---
# <a name="ordering-items-in-the-header-control"></a>Ordenando itens no controle de cabeçalho

Depois que você tiver [adicionou itens para um controle de cabeçalho](../mfc/adding-items-to-the-header-control.md), você pode manipular ou obter informações sobre seus pedidos com as seguintes funções:

- [CHeaderCtrl::GetOrderArray](../mfc/reference/cheaderctrl-class.md#getorderarray) e [CHeaderCtrl::SetOrderArray](../mfc/reference/cheaderctrl-class.md#setorderarray)

   Recupera e define a ordem da esquerda para a direita dos itens de cabeçalho.

- [CHeaderCtrl::OrderToIndex](../mfc/reference/cheaderctrl-class.md#ordertoindex).

   Recupera o valor de índice para um item de cabeçalho específico.

Além das funções de membro anterior, o estilo HDS_DRAGDROP permite ao usuário arrastar e soltar itens de cabeçalho dentro do controle de cabeçalho. Para obter mais informações, consulte [fornecendo suporte de arrastar e soltar para itens de cabeçalho](../mfc/providing-drag-and-drop-support-for-header-items.md).

## <a name="see-also"></a>Consulte também

[Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)

