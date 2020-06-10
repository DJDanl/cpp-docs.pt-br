---
title: Criando o controle de lista
ms.date: 11/04/2016
helpviewer_keywords:
- CListCtrl class [MFC], creating control
- list controls [MFC]
ms.assetid: a4cb1729-31b6-4d2b-a44b-367474848a39
ms.openlocfilehash: c9ba379611c44b5eae8d02b908ba71e3dbd66481
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84617106"
---
# <a name="creating-the-list-control"></a>Criando o controle de lista

O modo como o controle de lista ([CListCtrl](reference/clistctrl-class.md)) é criado depende se você está usando o controle diretamente ou usando a classe [CListView](reference/clistview-class.md) em vez disso. Se você usar `CListView` , a estrutura construirá a exibição como parte de sua sequência de criação de documento/exibição. Criar o modo de exibição de lista também cria o controle de lista (os dois são a mesma coisa). O controle é criado na função do manipulador [OnCreate](reference/cwnd-class.md#oncreate) da exibição. Nesse caso, o controle está pronto para você adicionar itens, por meio de uma chamada para [GetListCtrl](reference/clistview-class.md#getlistctrl).

### <a name="to-use-clistctrl-directly-in-a-dialog-box"></a>Para usar o CListCtrl diretamente em uma caixa de diálogo

1. No editor de caixa de diálogo, adicione um controle de lista ao recurso de modelo de caixa de diálogo. Especifique sua ID de controle.

1. Use o [Assistente para Adicionar variável de membro](../ide/adding-a-member-variable-visual-cpp.md) para adicionar uma variável de membro do tipo `CListCtrl` com a propriedade de controle. Você pode usar esse membro para chamar `CListCtrl` funções de membro.

1. Use o [Assistente de classe](reference/mfc-class-wizard.md) para mapear funções de manipulador na classe de caixa de diálogo para qualquer mensagem de notificação de controle de lista que você precise manipular (consulte [mapeando mensagens para funções](reference/mapping-messages-to-functions.md)).

1. Em [OnInitDialog](reference/cdialog-class.md#oninitdialog), defina os estilos para o `CListCtrl` . Consulte [alterando os estilos de controle de lista](changing-list-control-styles.md). Isso determina o tipo de "exibição" que você obtém no controle, embora você possa alterar a exibição mais tarde.

### <a name="to-use-clistctrl-in-a-nondialog-window"></a>Para usar o CListCtrl em uma janela sem caixa de diálogo

1. Defina o controle na classe View ou Window.

1. Chame a função de membro [Create](reference/clistctrl-class.md#create) do controle, possivelmente em [OnInitialUpdate](reference/cview-class.md#oninitialupdate), possivelmente no início da função do manipulador [OnCreate](reference/cwnd-class.md#oncreate) da janela pai (se você estiver subclassendo o controle). Defina os estilos do controle.

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](using-clistctrl.md)<br/>
[Controles](controls-mfc.md)
