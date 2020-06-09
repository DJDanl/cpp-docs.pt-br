---
title: Seleção atual em um controle de edição avançada
ms.date: 11/04/2016
helpviewer_keywords:
- current selection in CRichEditCtrls
- CRichEditCtrl class [MFC], current selection in
- rich edit controls [MFC], current selection in
- selection, current in CRichEditCtrl
ms.assetid: f6b2a2b6-5481-4ad3-9720-6dd772ea6fc8
ms.openlocfilehash: 9591f1aeb4e159b9b4f70945d6248a3b8d1dc827
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626499"
---
# <a name="current-selection-in-a-rich-edit-control"></a>Seleção atual em um controle de edição avançada

O usuário pode selecionar o texto em um[CRichEditCtrl](reference/cricheditctrl-class.md)(controle de edição rico) usando o mouse ou o teclado. A seleção atual é o intervalo de caracteres selecionados ou a posição do ponto de inserção se nenhum caractere for selecionado. Um aplicativo pode obter informações sobre a seleção atual, definir a seleção atual, determinar quando a seleção atual é alterada e mostrar ou ocultar o realce de seleção.

Para determinar a seleção atual em um controle de edição rico, use a função de membro [GetSel](reference/cricheditctrl-class.md#getsel) . Para definir a seleção atual, use a função de membro [SetSel](reference/cricheditctrl-class.md#setsel) . A estrutura [CHARRANGE](/windows/win32/api/richedit/ns-richedit-charrange) é usada com essas funções para especificar um intervalo de caracteres. Para recuperar informações sobre o conteúdo da seleção atual, você pode usar a função de membro [GetSelectionType](reference/cricheditctrl-class.md#getselectiontype) .

Por padrão, um controle rich edit mostra e oculta o realce de seleção quando ele ganha e perde o foco. Você pode mostrar ou ocultar o realce de seleção a qualquer momento usando a função de membro [HideSelection](reference/cricheditctrl-class.md#hideselection) . Por exemplo, um aplicativo pode fornecer uma caixa de diálogo de pesquisa para localizar texto em um controle de edição rico. O aplicativo pode selecionar texto correspondente sem fechar a caixa de diálogo; nesse caso, ele deve usar `HideSelection` para realçar a seleção.

Para obter o texto selecionado em um controle de edição rico, use a função de membro [GetSelText](reference/cricheditctrl-class.md#getseltext) . O texto é copiado para a matriz de caracteres especificada. Você deve garantir que a matriz seja grande o suficiente para manter o texto selecionado mais um caractere nulo de terminação.

Você pode pesquisar uma cadeia de caracteres em um controle de edição rico usando a função de membro [LocalizarTexto](reference/cricheditctrl-class.md#findtext) a estrutura [FINDTEXTEX](/windows/win32/api/richedit/ns-richedit-findtextexw) usada com essa função especifica o intervalo de texto a ser pesquisado e a cadeia de caracteres a ser pesquisada. Você também pode especificar essas opções como se a pesquisa diferencia maiúsculas de minúsculas.

## <a name="see-also"></a>Consulte também

[Usando CRichEditCtrl](using-cricheditctrl.md)<br/>
[Controles](controls-mfc.md)
