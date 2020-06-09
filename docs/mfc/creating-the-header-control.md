---
title: Criando o controle de cabeçalho
ms.date: 11/04/2016
helpviewer_keywords:
- CHeaderCtrl class [MFC], creating
- header controls [MFC], creating
ms.assetid: 7864d9d2-4a2c-4622-b58b-7b110a1e28d2
ms.openlocfilehash: b08dd4d3f12c70ae495b20b936d44f6a695d1ae1
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84616238"
---
# <a name="creating-the-header-control"></a>Criando o controle de cabeçalho

O controle de cabeçalho não está diretamente disponível no editor da caixa de diálogo (embora você possa adicionar um controle de lista, que inclui um controle de cabeçalho).

### <a name="to-put-a-header-control-in-a-dialog-box"></a>Para colocar um controle de cabeçalho em uma caixa de diálogo

1. Insira manualmente uma variável de membro do tipo [CHeaderCtrl](reference/cheaderctrl-class.md) em sua classe de caixa de diálogo.

1. No [OnInitDialog](reference/cdialog-class.md#oninitdialog), crie e defina os estilos para o `CHeaderCtrl` , posicione-o e exiba-o.

1. Adicione itens ao controle de cabeçalho.

1. Use o [Assistente de classe](reference/mfc-class-wizard.md) para mapear funções de manipulador na classe de caixa de diálogo para qualquer mensagem de notificação de controle de cabeçalho que você precise manipular (consulte [mapeando mensagens para funções](reference/mapping-messages-to-functions.md)).

### <a name="to-put-a-header-control-in-a-view-not-a-clistview"></a>Para colocar um controle de cabeçalho em uma exibição (não um CListView)

1. Insira um objeto [CHeaderCtrl](reference/cheaderctrl-class.md) em sua classe View.

1. Estilo, posição e exibição da janela de controle de cabeçalho na função de membro [OnInitialUpdate](reference/cview-class.md#oninitialupdate) da exibição.

1. Adicione itens ao controle de cabeçalho.

1. Use o [Assistente de classe](reference/mfc-class-wizard.md) para mapear funções de manipulador na classe de exibição para qualquer mensagem de notificação de controle de cabeçalho que você precisa manipular (consulte [mapeando mensagens para funções](reference/mapping-messages-to-functions.md)).

Em ambos os casos, o objeto de controle inserido é criado quando o objeto View ou Dialog é criado. Em seguida, você deve chamar [CHeaderCtrl:: Create](reference/cheaderctrl-class.md#create) para criar a janela de controle. Para posicionar o controle, chame [CHeaderCtrl:: layout](reference/cheaderctrl-class.md#layout) para determinar o tamanho inicial do controle e a posição e [SetWindowPos](reference/cwnd-class.md#setwindowpos) para definir a posição desejada. Em seguida, adicione itens conforme descrito em [adicionando itens ao controle de cabeçalho](adding-items-to-the-header-control.md).

Para obter mais informações, consulte [criando um controle de cabeçalho](/windows/win32/Controls/header-controls) na SDK do Windows.

## <a name="see-also"></a>Consulte também

[Usando CHeaderCtrl](using-cheaderctrl.md)<br/>
[Controles](controls-mfc.md)
