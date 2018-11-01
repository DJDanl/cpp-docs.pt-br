---
title: Definindo um manipulador de mensagens para uma mensagem refletida
ms.date: 11/04/2016
f1_keywords:
- vc.codewiz.defining.msg.msghandler
helpviewer_keywords:
- messages [MFC], reflected
- message handling [MFC], reflected messages
ms.assetid: 5a403528-58c5-46e7-90d5-4a77f0ab9b9c
ms.openlocfilehash: 89cb1631be7b8588d02518eacbc93b466a275828
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50531870"
---
# <a name="defining-a-message-handler-for-a-reflected-message"></a>Definindo um manipulador de mensagens para uma mensagem refletida

Depois de criar uma nova classe de controle do MFC, você pode definir manipuladores de mensagens para ela. Manipuladores de mensagens refletidas permitem que sua classe de controle lidar com suas próprias mensagens antes que a mensagem é recebida pelo pai. Você pode usar o MFC [CWnd::SendMessage](../../mfc/reference/cwnd-class.md#sendmessage) função para enviar mensagens de seu controle para uma janela pai.

Com essa funcionalidade, por exemplo, você poderia criar uma caixa de listagem que redesenhar a mesmo em vez de confiar na janela pai fazer então (desenhados pelo proprietário). Para obter mais informações sobre mensagens refletidas, consulte [Manipulando mensagens refletidas](../../mfc/handling-reflected-messages.md).

Para criar uma [controle ActiveX](../../mfc/activex-controls-on-the-internet.md) com a mesma funcionalidade, você deve criar um projeto para o controle ActiveX.

> [!NOTE]
>  Não é possível adicionar uma mensagem refletida (OCM _*mensagem*) para um controle ActiveX controle usando a janela Propriedades, conforme descrito abaixo. Você deve adicionar manualmente essas mensagens.

### <a name="to-define-a-message-handler-for-a-reflected-message-from-the-properties-window"></a>Para definir um manipulador de mensagens para uma mensagem refletida na janela Propriedades

1. Adicione um controle, como uma lista, um controle rebar, uma barra de ferramentas ou um controle de árvore, ao seu projeto MFC.

1. No modo de exibição de classe, clique no nome da sua classe de controle.

1. No [janela de propriedades](/visualstudio/ide/reference/properties-window), o nome de classe do controle aparece no **nome da classe** lista.

1. Clique o **mensagens** botão para exibir as mensagens do Windows disponíveis para adicionar ao controle.

1. Role para baixo a lista de mensagens na janela Propriedades, até você ver o cabeçalho **refletido**. Como alternativa, clique o **categorias** botão e recolher a exibição para ver as **refletido** título.

1. Selecione a mensagem refletida para o qual você deseja definir um manipulador. Mensagens refletidas são marcadas com um sinal de igual (=).

1. Clique na célula na coluna à direita na janela Propriedades para exibir o nome sugerido do manipulador de como \<Adicionar >*HandlerName*. (Por exemplo, o **= WM_CTLCOLOR** sugere do manipulador de mensagens \<Adicionar >**CtlColor**).

1. Clique no nome sugerido para aceitar. O manipulador é adicionado ao seu projeto.

   Nomes de manipulador de mensagem que você adicionou aparecem na coluna à direita da janela de mensagens refletidas.

9. Para editar ou excluir um manipulador de mensagens, repita as etapas 4 a 7. Clique na célula que contém o nome do manipulador para editar ou excluir e clique na tarefa apropriada.

## <a name="see-also"></a>Consulte também

[Mapeando mensagens para funções](../../mfc/reference/mapping-messages-to-functions.md)<br/>
[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)<br/>
[Adicionando uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)<br/>
[Adicionando uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)<br/>
[Substituindo uma função virtual](../../ide/overriding-a-virtual-function-visual-cpp.md)<br/>
[Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)<br/>
[Navegando pela estrutura de classe](../../ide/navigating-the-class-structure-visual-cpp.md)
