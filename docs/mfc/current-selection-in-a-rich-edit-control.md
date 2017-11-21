---
title: "A seleção atual em um controle de edição avançada | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- current selection in CRichEditCtrls
- CRichEditCtrl class [MFC], current selection in
- rich edit controls [MFC], current selection in
- selection, current in CRichEditCtrl
ms.assetid: f6b2a2b6-5481-4ad3-9720-6dd772ea6fc8
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 8b41b99ca515cb91c097cb20c3ef0cd0e5dccb64
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="current-selection-in-a-rich-edit-control"></a>Seleção atual em um controle de edição avançada
O usuário pode selecionar o texto em um controle de edição avançada ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)) usando o mouse ou o teclado. A seleção atual é o intervalo de caracteres selecionados ou a posição do ponto de inserção se nenhum caractere são selecionados. Um aplicativo pode obter informações sobre a seleção atual, definir a seleção atual, determine quando as alterações de seleção atual e mostrar ou ocultar a seleção de realce.  
  
 Para determinar a seleção atual em um controle de edição rica, use o [GetSel](../mfc/reference/cricheditctrl-class.md#getsel) função de membro. Para definir a seleção atual, use o [SetSel](../mfc/reference/cricheditctrl-class.md#setsel) função de membro. O [CHARRANGE](http://msdn.microsoft.com/library/windows/desktop/bb787885) estrutura é usada com essas funções para especificar um intervalo de caracteres. Para recuperar informações sobre o conteúdo da seleção atual, você pode usar o [GetSelectionType](../mfc/reference/cricheditctrl-class.md#getselectiontype) função de membro.  
  
 Por padrão, um controle de edição rica mostra e oculta o realce de seleção quando ele recebe e perde o foco. Você pode mostrar ou ocultar o realce de seleção a qualquer momento usando o [HideSelection](../mfc/reference/cricheditctrl-class.md#hideselection) função de membro. Por exemplo, um aplicativo pode fornecer uma caixa de diálogo de pesquisa para localizar texto em um controle de edição com formato. O aplicativo pode selecionar o texto correspondente sem fechar a caixa de diálogo, caso em que ele deve usar `HideSelection` para realçar a seleção.  
  
 Para obter o texto selecionado em um controle de edição rica, use o [GetSelText](../mfc/reference/cricheditctrl-class.md#getseltext) função de membro. O texto será copiado para a matriz de caractere especificado. Certifique-se de que a matriz é grande o suficiente para manter o texto selecionado mais de um caractere null de terminação.  
  
 Você pode procurar uma cadeia de caracteres em um controle de edição com formato usando o [FindText](../mfc/reference/cricheditctrl-class.md#findtext) função de membro de [FINDTEXTEX](http://msdn.microsoft.com/library/windows/desktop/bb787909) estrutura usada com esta função especifica o intervalo de texto para pesquisa e a cadeia de caracteres a ser pesquisado. Você também pode especificar essas opções como se a pesquisa diferencia maiusculas de minúsculas.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)

