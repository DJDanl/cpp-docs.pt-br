---
title: Alterando estilos de controle de lista | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- styles [MFC], CListCtrl
- CListCtrl class [MFC], styles
- CListCtrl class [MFC], changing styles
ms.assetid: be74a005-0795-417c-9056-f6342aa74b26
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f9d93511ad4f4ca835e09b6eaa3f612f0888e844
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="changing-list-control-styles"></a>Alterando estilos de controle de lista
Você pode alterar o estilo da janela de um controle de lista ([CListCtrl](../mfc/reference/clistctrl-class.md)) a qualquer momento depois de criá-lo. Ao alterar o estilo da janela, você deve alterar o tipo de exibição que usa o controle. Por exemplo, para emular o Pesquisador de objetos, você pode fornecer itens de menu ou botões de barra de ferramentas para alternar entre o controle entre diferentes modos de exibição: exibição de ícones, exibição de lista e assim por diante.  
  
 Por exemplo, quando o usuário seleciona o item de menu, você pode fazer uma chamada para [GetWindowLong](http://msdn.microsoft.com/library/windows/desktop/ms633584) para recuperar o estilo atual do controle e, em seguida, chamar [SetWindowLong](http://msdn.microsoft.com/library/windows/desktop/ms633591) para redefinir o estilo. Para obter mais informações, consulte [usando controles de exibição de lista](http://msdn.microsoft.com/library/windows/desktop/bb774736) no SDK do Windows.  
  
 Os estilos disponíveis são listados na [criar](../mfc/reference/clistctrl-class.md#create). Os estilos `LVS_ICON`, `LVS_SMALLICON`, `LVS_LIST`, e `LVS_REPORT` designar os modos de exibição de controle de lista de quatro.  
  
## <a name="extended-styles"></a>Estilos estendidos  
 Além dos estilos padrão para um controle de lista, há outro conjunto, conhecido como estilos estendidos. Esses estilos, discutidos em [estilos de exibição de lista estendido](http://msdn.microsoft.com/library/windows/desktop/bb774732) no SDK do Windows, fornecer uma variedade de recursos úteis que personalizam o comportamento do seu controle de lista. Para implementar o comportamento de um determinado estilo (por exemplo, a seleção de hover), fazer uma chamada para [CListCtrl::SetExtendedStyle](../mfc/reference/clistctrl-class.md#setextendedstyle), passando o estilo necessário. O exemplo a seguir demonstra a chamada de função:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#22](../mfc/codesnippet/cpp/changing-list-control-styles_1.cpp)]  
  
> [!NOTE]
>  Passe o mouse para seleção de trabalhar, você também deve ter um **LVS_EX_ONECLICKACTIVATE** ou **LVS_EX_TWOCLICKACTIVATE** ativado.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CListCtrl](../mfc/using-clistctrl.md)   
 [Controles](../mfc/controls-mfc.md)

