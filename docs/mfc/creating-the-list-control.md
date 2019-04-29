---
title: Criando o controle de lista
ms.date: 11/04/2016
helpviewer_keywords:
- CListCtrl class [MFC], creating control
- list controls [MFC]
ms.assetid: a4cb1729-31b6-4d2b-a44b-367474848a39
ms.openlocfilehash: 7b2cb47699339dd413dc1bfae7623069da56e7a4
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62242244"
---
# <a name="creating-the-list-control"></a>Criando o controle de lista

Como controlar a lista ([CListCtrl](../mfc/reference/clistctrl-class.md)) é criada depende se você estiver usando o controle diretamente ou usando a classe [CListView](../mfc/reference/clistview-class.md) em vez disso. Se você usar `CListView`, o framework constrói o modo de exibição como parte de sua sequência de criação de documento/exibição. Criando a exibição de lista cria o controle de lista também (os dois são a mesma coisa). O controle é criado no modo de exibição [OnCreate](../mfc/reference/cwnd-class.md#oncreate) função do manipulador. Nesse caso, o controle estiver pronto para adicionar itens, por meio de uma chamada para [GetListCtrl](../mfc/reference/clistview-class.md#getlistctrl).

### <a name="to-use-clistctrl-directly-in-a-dialog-box"></a>Usar CListCtrl diretamente em uma caixa de diálogo

1. No editor de caixa de diálogo, adicione um controle de lista para o recurso de modelo de caixa de diálogo. Especifique sua ID de controle.

1. Use o [Assistente para adição de variável de membro](../ide/adding-a-member-variable-visual-cpp.md) para adicionar uma variável de membro de tipo `CListCtrl` com a propriedade de controle. Você pode usar esse membro para chamar `CListCtrl` funções de membro.

1. Use a janela de propriedades para mapear as funções do manipulador da classe de caixa de diálogo para qualquer notificação de controle de lista mensagens que você precisa manipular (consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md)).

1. Na [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog), definir os estilos para o `CListCtrl`. Ver [alterando estilos de controle de lista](../mfc/changing-list-control-styles.md). Isso determina o tipo de "view" obter no controle, embora você possa alterar o modo de exibição mais tarde.

### <a name="to-use-clistctrl-in-a-nondialog-window"></a>Para usar CListCtrl em uma janela de nondialog

1. Defina o controle na classe de janela ou exibição.

1. Chame o controle [Create](../mfc/reference/clistctrl-class.md#create) função de membro, possivelmente em [OnInitialUpdate](../mfc/reference/cview-class.md#oninitialupdate), possivelmente como antecipada como da janela pai [OnCreate](../mfc/reference/cwnd-class.md#oncreate) função do manipulador (se você estiver Criando subclasses de controle). Defina os estilos para o controle.

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](../mfc/using-clistctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
