---
title: Criando o controle de seletor de data e hora
ms.date: 11/04/2016
helpviewer_keywords:
- DateTimePicker control [MFC], creating
- CDateTimeCtrl class [MFC], creating
ms.assetid: 764ec2fb-98cd-478b-a5f2-d63f0bb12279
ms.openlocfilehash: 5d753b166454b795932ec8f47b0897829fab9b8e
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620464"
---
# <a name="creating-the-date-and-time-picker-control"></a>Criando o controle de seletor de data e hora

Como o controle seletor de data e hora é criado depende se você está usando o controle em uma caixa de diálogo ou criando-o em uma janela sem caixa de diálogo.

### <a name="to-use-cdatetimectrl-directly-in-a-dialog-box"></a>Para usar o CDateTimeCtrl diretamente em uma caixa de diálogo

1. No editor de caixa de diálogo, adicione um controle de seletor de data e hora ao recurso de modelo de caixa de diálogo. Especifique sua ID de controle.

1. Especifique os estilos necessários, usando a caixa de diálogo Propriedades do controle seletor de data e hora.

1. Use o [Assistente para Adicionar variável de membro](../ide/adding-a-member-variable-visual-cpp.md) para adicionar uma variável de membro do tipo [CDateTimeCtrl](reference/cdatetimectrl-class.md) com a propriedade Control. Você pode usar esse membro para chamar `CDateTimeCtrl` funções de membro.

1. Use o [Assistente de classe](reference/mfc-class-wizard.md) para mapear funções de manipulador na classe de caixa de diálogo para qualquer mensagem de [notificação](processing-notification-messages-in-date-and-time-picker-controls.md) de controle do seletor de data e hora que você precisa manipular (consulte [mapeando mensagens para funções](reference/mapping-messages-to-functions.md)).

1. Em [OnInitDialog](reference/cdialog-class.md#oninitdialog), defina todos os estilos adicionais para o `CDateTimeCtrl` objeto.

### <a name="to-use-cdatetimectrl-in-a-nondialog-window"></a>Para usar o CDateTimeCtrl em uma janela sem caixa de diálogo

1. Declare o controle na classe View ou Window.

1. Chame a função de membro [Create](reference/ctabctrl-class.md#create) do controle, possivelmente em [OnInitialUpdate](reference/cview-class.md#oninitialupdate), possivelmente no início da função do manipulador [OnCreate](reference/cwnd-class.md#oncreate) da janela pai (se você estiver subclassendo o controle). Defina os estilos do controle.

## <a name="see-also"></a>Consulte também

[Usando CDateTimeCtrl](using-cdatetimectrl.md)<br/>
[Controles](controls-mfc.md)
