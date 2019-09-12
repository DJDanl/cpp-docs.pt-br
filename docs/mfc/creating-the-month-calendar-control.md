---
title: Criando o controle de calendário mensal
ms.date: 11/04/2016
helpviewer_keywords:
- CMonthCalCtrl class [MFC], creating
- month calendar controls [MFC], creating
- month calendar controls [MFC]
ms.assetid: 185cc642-85e9-4365-8a4c-d90b75b010f7
ms.openlocfilehash: 9e430a86c2ac08bde0f031a4c91b9ae5c6f570f3
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70907500"
---
# <a name="creating-the-month-calendar-control"></a>Criando o controle de calendário mensal

A forma como o controle de calendário mensal é criado depende se você está usando o controle em uma caixa de diálogo ou criando-o em uma janela que não seja de caixa de diálogo.

### <a name="to-use-cmonthcalctrl-directly-in-a-dialog-box"></a>Para usar o CMonthCalCtrl diretamente em uma caixa de diálogo

1. No editor de caixa de diálogo, adicione um controle de calendário mensal ao recurso de modelo de caixa de diálogo. Especifique sua ID de controle.

1. Especifique os estilos necessários, usando a caixa de diálogo Propriedades do controle de calendário mensal.

1. Use o [Assistente para Adicionar variável de membro](../ide/adding-a-member-variable-visual-cpp.md) para adicionar uma variável de membro do tipo [CMonthCalCtrl](../mfc/reference/cmonthcalctrl-class.md) com a propriedade Control. Você pode usar esse membro para chamar `CMonthCalCtrl` funções de membro.

1. Use o [Assistente de classe](reference/mfc-class-wizard.md) para mapear funções de manipulador na classe de caixa de diálogo para qualquer mensagem de notificação de controle de calendário mensal que você precisa manipular (consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md)).

1. Em [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog), defina todos os estilos adicionais para `CMonthCalCtrl` o objeto.

### <a name="to-use-cmonthcalctrl-in-a-nondialog-window"></a>Para usar o CMonthCalCtrl em uma janela sem caixa de diálogo

1. Defina o controle na classe View ou Window.

1. Chame a função de membro [Create](../mfc/reference/cmonthcalctrl-class.md#create) do controle, possivelmente em [OnInitialUpdate](../mfc/reference/cview-class.md#oninitialupdate), possivelmente no início da função do manipulador [OnCreate](../mfc/reference/cwnd-class.md#oncreate) da janela pai (se você estiver subclassendo o controle). Defina os estilos do controle.

## <a name="see-also"></a>Consulte também

[Usando CMonthCalCtrl](../mfc/using-cmonthcalctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
