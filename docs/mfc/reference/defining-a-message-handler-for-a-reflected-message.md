---
title: Definindo um manipulador de mensagens para uma mensagem refletida
ms.date: 09/07/2019
f1_keywords:
- vc.codewiz.defining.msg.msghandler
helpviewer_keywords:
- messages [MFC], reflected
- message handling [MFC], reflected messages
ms.assetid: 5a403528-58c5-46e7-90d5-4a77f0ab9b9c
ms.openlocfilehash: f7f90d3347ac61abcfcb48e77ef39aa2626ae5c8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365851"
---
# <a name="defining-a-message-handler-for-a-reflected-message"></a>Definindo um manipulador de mensagens para uma mensagem refletida

Depois de criar uma nova classe de controle MFC, você pode definir manipuladores de mensagens para ele. Os manipuladores de mensagens refletidos permitem que sua classe de controle manuseie suas próprias mensagens antes que a mensagem seja recebida pelo pai. Você pode usar a função MFC [CWnd::SendMessage](../../mfc/reference/cwnd-class.md#sendmessage) para enviar mensagens do seu controle para uma janela pai.

Com essa funcionalidade, você poderia, por exemplo, criar uma caixa de lista que se redesenhará em vez de depender da janela pai para fazê-lo (proprietário sorteado). Para obter mais informações sobre mensagens refletidas, consulte [Manipulação de mensagens refletidas](../../mfc/handling-reflected-messages.md).

Para criar um [controle ActiveX](../../mfc/activex-controls-on-the-internet.md) com a mesma funcionalidade, você deve criar um projeto para o controle ActiveX.

> [!NOTE]
> Não é possível adicionar uma mensagem refletida (OCM_*Message)* para um controle ActiveX usando o Assistente de Classe, conforme descrito abaixo. Você deve adicionar essas mensagens manualmente.

### <a name="to-define-a-message-handler-for-a-reflected-message-from-the-class-wizard"></a>Para definir um manipulador de mensagens para uma mensagem refletida do Assistente de Classe

1. Adicione um controle, como uma lista, um controle de vergalhões, uma barra de ferramentas ou um controle de árvore, ao seu projeto MFC.

1. Em Exibição de classe, clique no nome da sua classe de controle.

1. No [Assistente de Classe](mfc-class-wizard.md), o nome da classe de controle aparece na **lista Nome de classe.**

1. Clique na guia **Mensagens** para exibir as mensagens do Windows disponíveis para adicionar ao controle.

1. Selecione a mensagem refletida para a qual deseja definir um manipulador. As mensagens refletidas são marcadas com um sinal igual (=).

1. Clique na célula na coluna direita no Assistente de classe para \<exibir o nome sugerido do manipulador como adicionar>*HandlerName*. (Por exemplo, o manipulador \<de mensagens **=WM_CTLCOLOR** sugere adicionar>**CtlColor**).

1. Clique no nome sugerido para aceitar. O manipulador é adicionado ao seu projeto.

1. Para editar ou excluir um manipulador de mensagens, repita as etapas 4 a 7. Clique na célula que contém o nome do manipulador para editar ou excluir e clique na tarefa apropriada.

## <a name="see-also"></a>Confira também

[Mapeando mensagens para funções](../../mfc/reference/mapping-messages-to-functions.md)<br/>
[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)<br/>
[Adicionando uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)<br/>
[Adicionando uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)<br/>
[Substituindo uma função virtual](../../ide/overriding-a-virtual-function-visual-cpp.md)<br/>
[Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)<br/>
[Navegando pela estrutura de classe](../../ide/navigate-code-cpp.md)
