---
title: Itens de cabeçalho em um controle de cabeçalho
ms.date: 11/04/2016
helpviewer_keywords:
- header controls [MFC], header items in
- header items in header controls [MFC]
- CHeaderCtrl class [MFC], header items in
- controls [MFC], header
ms.assetid: ac79ef1f-a671-4ab2-93e9-b1aa016a48bf
ms.openlocfilehash: a70d1d9225d2ac8ef2f7ed3ad9f603a64a937bc7
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620096"
---
# <a name="header-items-in-a-header-control"></a>Itens de cabeçalho em um controle de cabeçalho

Você tem um controle considerável sobre a aparência e o comportamento dos itens de cabeçalho que compõem um controle de cabeçalho ([CHeaderCtrl](reference/cheaderctrl-class.md)). Cada item de cabeçalho pode ter uma cadeia de caracteres, uma imagem de bitmap, uma imagem de uma lista de imagens associada ou um valor de 32 bits definido pelo aplicativo associado a ela. A cadeia de caracteres, bitmap ou imagem é exibida no item de cabeçalho.

Você pode personalizar a aparência e o conteúdo de novos itens quando eles são criados fazendo uma chamada [CHeaderCtrl:: InsertItem](reference/cheaderctrl-class.md#insertitem) ou modificando um item existente, com uma chamada para [CHeaderCtrl:: GetItem](reference/cheaderctrl-class.md#getitem) e [CHeaderCtrl:: SetItem](reference/cheaderctrl-class.md#setitem).

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Personalizando a aparência do item de cabeçalho](customizing-the-header-item-s-appearance.md)

- [Ordenando itens no controle de cabeçalho](ordering-items-in-the-header-control.md)

- [Fornecendo suporte a arrastar e soltar para os itens de cabeçalho](providing-drag-and-drop-support-for-header-items.md)

- [Usando listas de imagens com controles de cabeçalho](using-image-lists-with-header-controls.md)

## <a name="see-also"></a>Consulte também

[Usando CHeaderCtrl](using-cheaderctrl.md)
