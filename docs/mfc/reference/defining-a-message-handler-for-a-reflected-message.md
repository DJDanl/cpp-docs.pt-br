---
title: Definindo um manipulador de mensagens para uma mensagem refletida
ms.date: 09/07/2019
f1_keywords:
- vc.codewiz.defining.msg.msghandler
helpviewer_keywords:
- messages [MFC], reflected
- message handling [MFC], reflected messages
ms.assetid: 5a403528-58c5-46e7-90d5-4a77f0ab9b9c
ms.openlocfilehash: 1e38c63464cacf445688a1d431a65af21eac86f4
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70907938"
---
# <a name="defining-a-message-handler-for-a-reflected-message"></a>Definindo um manipulador de mensagens para uma mensagem refletida

Depois de criar uma nova classe de controle MFC, você pode definir manipuladores de mensagens para ela. Os manipuladores de mensagens refletidas permitem que sua classe de controle manipule suas próprias mensagens antes que a mensagem seja recebida pelo pai. Você pode usar a função MFC [CWnd:: SendMessage](../../mfc/reference/cwnd-class.md#sendmessage) para enviar mensagens do seu controle para uma janela pai.

Com essa funcionalidade, você pode, por exemplo, criar uma caixa de listagem que será redesenhada em vez de depender da janela pai para fazer isso (proprietário desenhado). Para obter mais informações sobre mensagens refletidas, consulte [lidando com mensagens refletidas](../../mfc/handling-reflected-messages.md).

Para criar um [controle ActiveX](../../mfc/activex-controls-on-the-internet.md) com a mesma funcionalidade, você deve criar um projeto para o controle ActiveX.

> [!NOTE]
>  Você não pode adicionar uma mensagem refletida (*mensagem*OCM_) para um controle ActiveX usando o assistente de classe, conforme descrito abaixo. Você deve adicionar essas mensagens manualmente.

### <a name="to-define-a-message-handler-for-a-reflected-message-from-the-class-wizard"></a>Para definir um manipulador de mensagens para uma mensagem refletida do assistente de classe

1. Adicione um controle, como uma lista, um controle rebar, uma barra de ferramentas ou um controle de árvore, ao seu projeto do MFC.

1. Em Modo de Exibição de Classe, clique no nome da classe de controle.

1. No [Assistente de classe](mfc-class-wizard.md), o nome da classe de controle aparece na lista **nome da classe** .

1. Clique na guia **mensagens** para exibir as mensagens do Windows disponíveis para adicionar ao controle.

1. Selecione a mensagem refletida para a qual você deseja definir um manipulador. As mensagens refletidas são marcadas com um sinal de igual (=).

1. Clique na célula na coluna direita no assistente de classe para exibir o nome sugerido do manipulador como \<Adicionar >*HandlerName*. (Por exemplo, o manipulador de mensagens **= WM_CTLCOLOR** sugere \<Adicionar >**CTLCOLOR**).

1. Clique no nome sugerido para aceitar. O manipulador é adicionado ao seu projeto.

1. Para editar ou excluir um manipulador de mensagens, repita as etapas 4 a 7. Clique na célula que contém o nome do manipulador para editar ou excluir e clique na tarefa apropriada.

## <a name="see-also"></a>Consulte também

[Mapeando mensagens para funções](../../mfc/reference/mapping-messages-to-functions.md)<br/>
[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)<br/>
[Adicionando uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)<br/>
[Adicionando uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)<br/>
[Substituindo uma função virtual](../../ide/overriding-a-virtual-function-visual-cpp.md)<br/>
[Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)<br/>
[Navegando pela estrutura de classe](../../ide/navigate-code-cpp.md)
