---
title: Alterando estilos de controle de lista
ms.date: 11/04/2016
helpviewer_keywords:
- styles [MFC], CListCtrl
- CListCtrl class [MFC], styles
- CListCtrl class [MFC], changing styles
ms.assetid: be74a005-0795-417c-9056-f6342aa74b26
ms.openlocfilehash: b3cc65ce6ef0e84eaa2f6738cb18b6b862a6473a
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69509042"
---
# <a name="changing-list-control-styles"></a>Alterando estilos de controle de lista

Você pode alterar o estilo de janela de um controle de lista ([CListCtrl](../mfc/reference/clistctrl-class.md)) a qualquer momento depois de criá-lo. Ao alterar o estilo da janela, você altera o tipo de exibição que o controle usa. Por exemplo, para emular o Gerenciador, você pode fornecer itens de menu ou botões da barra de ferramentas para alternar o controle entre diferentes exibições: exibição de ícones, exibição de lista e assim por diante.

Por exemplo, quando o usuário seleciona o item de menu, você pode fazer uma chamada para [GetWindowLong](/windows/win32/api/winuser/nf-winuser-getwindowlongw) para recuperar o estilo atual do controle e, em seguida, chamar [SetWindowLong](/windows/win32/api/winuser/nf-winuser-setwindowlongw) para redefinir o estilo. Para obter mais informações, consulte [usando controles de exibição de lista](/windows/win32/Controls/using-list-view-controls) no SDK do Windows.

Os estilos disponíveis são listados em [criar](../mfc/reference/clistctrl-class.md#create). Os estilos **LVS_ICON**, **LVS_SMALLICON**, **LVS_LIST**e **LVS_REPORT** designam as quatro exibições de controle de lista.

## <a name="extended-styles"></a>Estilos estendidos

Além dos estilos padrão de um controle de lista, há outro conjunto, conhecido como estilos estendidos. Esses estilos, discutidos em [estilos de exibição de lista estendida](/windows/win32/Controls/extended-list-view-styles) no SDK do Windows, fornecem uma variedade de recursos úteis que personalizam o comportamento do seu controle de lista. Para implementar o comportamento de um determinado estilo (como seleção de foco), faça uma chamada para [CListCtrl::](../mfc/reference/clistctrl-class.md#setextendedstyle)Extended, passando o estilo necessário. O exemplo a seguir demonstra a chamada de função:

[!code-cpp[NVC_MFCControlLadenDialog#22](../mfc/codesnippet/cpp/changing-list-control-styles_1.cpp)]

> [!NOTE]
>  Para que a seleção em foco funcione, você também deve ter o **LVS_EX_ONECLICKACTIVATE** ou o **LVS_EX_TWOCLICKACTIVATE** ativado.

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](../mfc/using-clistctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
