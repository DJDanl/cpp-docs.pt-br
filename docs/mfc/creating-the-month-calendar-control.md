---
title: Criando o controle de calendário mensal
ms.date: 11/04/2016
helpviewer_keywords:
- CMonthCalCtrl class [MFC], creating
- month calendar controls [MFC], creating
- month calendar controls [MFC]
ms.assetid: 185cc642-85e9-4365-8a4c-d90b75b010f7
ms.openlocfilehash: 49d21bd4ce5aae23d5fc4c74567bc1c1d5a43570
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84616232"
---
# <a name="creating-the-month-calendar-control"></a>Criando o controle de calendário mensal

A forma como o controle de calendário mensal é criado depende se você está usando o controle em uma caixa de diálogo ou criando-o em uma janela que não seja de caixa de diálogo.

### <a name="to-use-cmonthcalctrl-directly-in-a-dialog-box"></a>Para usar o CMonthCalCtrl diretamente em uma caixa de diálogo

1. No editor de caixa de diálogo, adicione um controle de calendário mensal ao recurso de modelo de caixa de diálogo. Especifique sua ID de controle.

1. Especifique os estilos necessários, usando a caixa de diálogo Propriedades do controle de calendário mensal.

1. Use o [Assistente para Adicionar variável de membro](../ide/adding-a-member-variable-visual-cpp.md) para adicionar uma variável de membro do tipo [CMonthCalCtrl](reference/cmonthcalctrl-class.md) com a propriedade Control. Você pode usar esse membro para chamar `CMonthCalCtrl` funções de membro.

1. Use o [Assistente de classe](reference/mfc-class-wizard.md) para mapear funções de manipulador na classe de caixa de diálogo para qualquer mensagem de notificação de controle de calendário mensal que você precisa manipular (consulte [mapeando mensagens para funções](reference/mapping-messages-to-functions.md)).

1. Em [OnInitDialog](reference/cdialog-class.md#oninitdialog), defina todos os estilos adicionais para o `CMonthCalCtrl` objeto.

### <a name="to-use-cmonthcalctrl-in-a-nondialog-window"></a>Para usar o CMonthCalCtrl em uma janela sem caixa de diálogo

1. Defina o controle na classe View ou Window.

1. Chame a função de membro [Create](reference/cmonthcalctrl-class.md#create) do controle, possivelmente em [OnInitialUpdate](reference/cview-class.md#oninitialupdate), possivelmente no início da função do manipulador [OnCreate](reference/cwnd-class.md#oncreate) da janela pai (se você estiver subclassendo o controle). Defina os estilos do controle.

## <a name="see-also"></a>Consulte também

[Usando CMonthCalCtrl](using-cmonthcalctrl.md)<br/>
[Controles](controls-mfc.md)
