---
title: Seleção atual em um controle de edição avançada
ms.date: 11/04/2016
helpviewer_keywords:
- current selection in CRichEditCtrls
- CRichEditCtrl class [MFC], current selection in
- rich edit controls [MFC], current selection in
- selection, current in CRichEditCtrl
ms.assetid: f6b2a2b6-5481-4ad3-9720-6dd772ea6fc8
ms.openlocfilehash: 4516c4506419169ac3ab284e6c59cae71595be59
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57286858"
---
# <a name="current-selection-in-a-rich-edit-control"></a>Seleção atual em um controle de edição avançada

O usuário pode selecionar texto em um controle rich edit ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)) usando o mouse ou teclado. A seleção atual é o intervalo de caracteres selecionados ou a posição do ponto de inserção se não houver nenhum caractere estão selecionados. Um aplicativo pode obter informações sobre a seleção atual, definir a seleção atual, determinar quando as alterações de seleção atual e mostrar ou ocultar a seleção de realce.

Para determinar a seleção atual em um controle de edição rica, use o [GetSel](../mfc/reference/cricheditctrl-class.md#getsel) função de membro. Para definir a seleção atual, use o [SetSel](../mfc/reference/cricheditctrl-class.md#setsel) função de membro. O [CHARRANGE](/windows/desktop/api/richedit/ns-richedit-_charrange) estrutura é usada com essas funções para especificar um intervalo de caracteres. Para recuperar informações sobre o conteúdo da seleção atual, você pode usar o [GetSelectionType](../mfc/reference/cricheditctrl-class.md#getselectiontype) função de membro.

Por padrão, um controle rich edit mostra e oculta o realce de seleção quando ele recebe e perde o foco. Você pode mostrar ou ocultar o realce de seleção a qualquer momento usando o [HideSelection](../mfc/reference/cricheditctrl-class.md#hideselection) função de membro. Por exemplo, um aplicativo pode fornecer uma caixa de diálogo de pesquisa para localizar texto em um controle rich edit. O aplicativo pode selecionar o texto correspondente sem fechar a caixa de diálogo, caso em que ele deve usar `HideSelection` para realçar a seleção.

Para obter o texto selecionado em um controle de edição rica, use o [GetSelText](../mfc/reference/cricheditctrl-class.md#getseltext) função de membro. O texto é copiado para a matriz de caracteres especificada. Você deve garantir que a matriz é grande o suficiente para manter o texto selecionado mais de um caractere nulo de terminação.

Você pode procurar por uma cadeia de caracteres em um controle de edição rica usando o [FindText](../mfc/reference/cricheditctrl-class.md#findtext) função de membro a [FINDTEXTEX](/windows/desktop/api/richedit/ns-richedit-_findtextexa) estrutura usada com essa função especifica o intervalo de texto para pesquisa e a cadeia de caracteres a ser pesquisado. Você também pode especificar essas opções como se a pesquisa diferencia maiusculas de minúsculas.

## <a name="see-also"></a>Consulte também

[Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
