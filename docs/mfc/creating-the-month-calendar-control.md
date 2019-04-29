---
title: Criando o controle de calendário mensal
ms.date: 11/04/2016
helpviewer_keywords:
- CMonthCalCtrl class [MFC], creating
- month calendar controls [MFC], creating
- month calendar controls [MFC]
ms.assetid: 185cc642-85e9-4365-8a4c-d90b75b010f7
ms.openlocfilehash: 809bc9fdf6b4477363d0a43d007a2884bb43a049
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62242179"
---
# <a name="creating-the-month-calendar-control"></a>Criando o controle de calendário mensal

Como o controle de calendário mensal é criado depende se você estiver usando o controle em uma caixa de diálogo ou criá-lo em uma janela nondialog.

### <a name="to-use-cmonthcalctrl-directly-in-a-dialog-box"></a>Usar CMonthCalCtrl diretamente em uma caixa de diálogo

1. No editor de caixa de diálogo, adicione um controle de calendário mensal ao recurso de modelo de caixa de diálogo. Especifique sua ID de controle.

1. Especifique todos os estilos necessários, usando a caixa de diálogo Propriedades do controle de calendário mensal.

1. Use o [Assistente para adição de variável de membro](../ide/adding-a-member-variable-visual-cpp.md) para adicionar uma variável de membro do tipo [CMonthCalCtrl](../mfc/reference/cmonthcalctrl-class.md) com a propriedade de controle. Você pode usar esse membro para chamar `CMonthCalCtrl` funções de membro.

1. Use a janela de propriedades para mapear as funções do manipulador da classe de caixa de diálogo para qualquer notificação de controle de calendário do mês mensagens que você precisa manipular (consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md)).

1. Na [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog), defina todos os estilos adicionais para o `CMonthCalCtrl` objeto.

### <a name="to-use-cmonthcalctrl-in-a-nondialog-window"></a>Para usar CMonthCalCtrl em uma janela de nondialog

1. Defina o controle na classe de janela ou exibição.

1. Chame o controle [Create](../mfc/reference/cmonthcalctrl-class.md#create) função de membro, possivelmente em [OnInitialUpdate](../mfc/reference/cview-class.md#oninitialupdate), possivelmente como antecipada como da janela pai [OnCreate](../mfc/reference/cwnd-class.md#oncreate) função do manipulador (se você estiver Criando subclasses de controle). Defina os estilos para o controle.

## <a name="see-also"></a>Consulte também

[Usando CMonthCalCtrl](../mfc/using-cmonthcalctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
