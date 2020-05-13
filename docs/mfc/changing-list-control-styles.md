---
title: Alterando estilos de controle de lista
ms.date: 11/04/2016
helpviewer_keywords:
- styles [MFC], CListCtrl
- CListCtrl class [MFC], styles
- CListCtrl class [MFC], changing styles
ms.assetid: be74a005-0795-417c-9056-f6342aa74b26
ms.openlocfilehash: 5f45e0549c3fc0f5747f8dd12a6310fafd7dd7bb
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370811"
---
# <a name="changing-list-control-styles"></a>Alterando estilos de controle de lista

Você pode alterar o estilo de janela de um controle de lista[(CListCtrl)](../mfc/reference/clistctrl-class.md)a qualquer momento depois de criá-lo. Ao alterar o estilo da janela, você altera o tipo de visão que o controle usa. Por exemplo, para imitar o Explorer, você pode fornecer itens de menu ou botões de barra de ferramentas para alternar o controle entre diferentes pontos de vista: exibição de ícones, exibição de lista e assim por diante.

Por exemplo, quando o usuário seleciona o item do menu, você pode fazer uma chamada para [GetWindowLong](/windows/win32/api/winuser/nf-winuser-getwindowlongw) para recuperar o estilo atual do controle e, em seguida, chamar [SetWindowLong](/windows/win32/api/winuser/nf-winuser-setwindowlongw) para redefinir o estilo. Para obter mais informações, consulte [Usando controles de exibição de lista](/windows/win32/Controls/using-list-view-controls) no SDK do Windows.

Os estilos disponíveis estão listados em [Criar](../mfc/reference/clistctrl-class.md#create). Os estilos **LVS_ICON**, **LVS_SMALLICON**, **LVS_LIST**e **LVS_REPORT** designam as quatro visualizações de controle de lista.

## <a name="extended-styles"></a>Estilos estendidos

Além dos estilos padrão para um controle de lista, há outro conjunto, referido como estilos estendidos. Esses estilos, discutidos em [Estilos de exibição de lista estendida](/windows/win32/Controls/extended-list-view-styles) no SDK do Windows, fornecem uma variedade de recursos úteis que personalizam o comportamento do controle de sua lista. Para implementar o comportamento de um determinado estilo (como a seleção hover), faça uma chamada para [CListCtrl::SetExtendedStyle](../mfc/reference/clistctrl-class.md#setextendedstyle), passando o estilo necessário. O exemplo a seguir demonstra a chamada de função:

[!code-cpp[NVC_MFCControlLadenDialog#22](../mfc/codesnippet/cpp/changing-list-control-styles_1.cpp)]

> [!NOTE]
> Para que a seleção de hover funcione, você também deve ter **LVS_EX_ONECLICKACTIVATE** ou **LVS_EX_TWOCLICKACTIVATE** ligado.

## <a name="see-also"></a>Confira também

[Usando CListCtrl](../mfc/using-clistctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
