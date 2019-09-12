---
title: Criando um controle de caixa de combinação estendido
ms.date: 11/04/2016
helpviewer_keywords:
- extended combo boxes
- CComboBoxEx class [MFC], creating extended combo box controls
- extended combo boxes [MFC], creating
ms.assetid: a964267e-97b6-4e77-9f89-55bb5c68913f
ms.openlocfilehash: 87e2e1cd3c29ba838a17c24ece4a89adda21db0c
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70907734"
---
# <a name="creating-an-extended-combo-box-control"></a>Criando um controle de caixa de combinação estendido

A forma como o controle de caixa de combinação estendida é criado depende se você está usando o controle em uma caixa de diálogo ou criando-o em uma janela que não seja de caixa de diálogo.

### <a name="to-use-ccomboboxex-directly-in-a-dialog-box"></a>Para usar o CComboBoxEx diretamente em uma caixa de diálogo

1. No editor de diálogo, adicione um controle de caixa de combinação estendida ao recurso de modelo de caixa de diálogo. Especifique sua ID de controle.

1. Especifique os estilos necessários, usando a caixa de diálogo Propriedades do controle caixa de combinação estendida.

1. Use o [Assistente para Adicionar variável de membro](../ide/adding-a-member-variable-visual-cpp.md) para adicionar uma variável de membro do tipo [CComboBoxEx](../mfc/reference/ccomboboxex-class.md) com a propriedade Control. Você pode usar esse membro para chamar `CComboBoxEx` funções de membro.

1. Use o [Assistente de classe](reference/mfc-class-wizard.md) para mapear funções de manipulador na classe de diálogo para qualquer mensagem de notificação de controle de caixa de combinação estendida que você precise manipular (consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md)).

1. Em [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog), defina todos os estilos adicionais para `CComboBoxEx` o objeto.

### <a name="to-use-ccomboboxex-in-a-nondialog-window"></a>Para usar o CComboBoxEx em uma janela sem caixa de diálogo

1. Defina o controle na classe View ou Window.

1. Chame a função de membro [Create](../mfc/reference/ctabctrl-class.md#create) do controle, possivelmente em [OnInitialUpdate](../mfc/reference/cview-class.md#oninitialupdate), possivelmente no início da função do manipulador [OnCreate](../mfc/reference/cwnd-class.md#oncreate) da janela pai. Defina os estilos do controle.

## <a name="see-also"></a>Consulte também

[Usando CComboBoxEx](../mfc/using-ccomboboxex.md)<br/>
[Controles](../mfc/controls-mfc.md)
