---
title: Alterando estilos de controle de lista
ms.date: 11/04/2016
helpviewer_keywords:
- styles [MFC], CListCtrl
- CListCtrl class [MFC], styles
- CListCtrl class [MFC], changing styles
ms.assetid: be74a005-0795-417c-9056-f6342aa74b26
ms.openlocfilehash: cfaae07d0bb96cbdf40de5afa701b73ae82485e8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50645140"
---
# <a name="changing-list-control-styles"></a>Alterando estilos de controle de lista

Você pode alterar o estilo da janela de um controle de lista ([CListCtrl](../mfc/reference/clistctrl-class.md)) a qualquer momento após criá-lo. Alterando o estilo da janela, você deve alterar o tipo de exibição que usa o controle. Por exemplo, para emular o Explorer, você pode fornecer itens de menu ou botões de barra de ferramentas para alternar entre o controle entre diferentes modos de exibição: modo de exibição de ícone, exibição de lista e assim por diante.

Por exemplo, quando o usuário seleciona o item de menu, você pode fazer uma chamada para [GetWindowLong](/windows/desktop/api/winuser/nf-winuser-getwindowlonga) para recuperar o estilo atual do controle e, em seguida, chame [SetWindowLong](/windows/desktop/api/winuser/nf-winuser-setwindowlonga) para redefinir o estilo. Para obter mais informações, consulte [controles de exibição de lista usando](/windows/desktop/Controls/using-list-view-controls) no SDK do Windows.

Estilos disponíveis são listados na [criar](../mfc/reference/clistctrl-class.md#create). Os estilos **LVS_ICON**, **LVS_SMALLICON**, **LVS_LIST**, e **LVS_REPORT** designar os modos de exibição de controle de lista de quatro.

## <a name="extended-styles"></a>Estilos estendidos

Além os estilos padrão para um controle de lista, há outro conjunto, conhecido como estilos estendidos. Esses estilos, discutidos [estilos de exibição de lista estendida](/windows/desktop/Controls/extended-list-view-styles) no SDK do Windows, fornecer uma variedade de recursos úteis que personalizam o comportamento do seu controle de lista. Para implementar o comportamento de um determinado estilo (como a seleção de em foco), fazer uma chamada para [CListCtrl::SetExtendedStyle](../mfc/reference/clistctrl-class.md#setextendedstyle), passando o estilo necessário. O exemplo a seguir demonstra a chamada de função:

[!code-cpp[NVC_MFCControlLadenDialog#22](../mfc/codesnippet/cpp/changing-list-control-styles_1.cpp)]

> [!NOTE]
>  Passe o mouse para seleção de trabalhar, você deve também ter **LVS_EX_ONECLICKACTIVATE** ou **LVS_EX_TWOCLICKACTIVATE** ativado.

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](../mfc/using-clistctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

