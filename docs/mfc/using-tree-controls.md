---
title: Usando controles de árvore
ms.date: 11/04/2016
helpviewer_keywords:
- CTreeCtrl class [MFC], using
- tree controls [MFC], about tree controls
ms.assetid: 4e92941a-e477-4fb1-b1ce-4abeafbef1c1
ms.openlocfilehash: 9cff48018d728ef9578be38c0d94300011265fa1
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57258314"
---
# <a name="using-tree-controls"></a>Usando controles de árvore

Um uso típico de um controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) segue o padrão abaixo:

- O controle é criado. Se o controle for especificado em um modelo de caixa de diálogo ou se você estiver usando `CTreeView`, criação é automática quando a caixa de diálogo ou uma exibição é criada. Se você deseja criar o controle de árvore como uma janela filho de alguma outra janela, use o [criar](../mfc/reference/ctreectrl-class.md#create) função de membro.

- Se você quiser que o controle de árvore para usar imagens, defina uma lista de imagens, chamando [SetImageList](../mfc/reference/ctreectrl-class.md#setimagelist). Você também pode alterar o recuo chamando [SetIndent](../mfc/reference/ctreectrl-class.md#setindent). Um bom momento para fazer isso está em [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog) (para controles em caixas de diálogo) ou [OnInitialUpdate](../mfc/reference/cview-class.md#oninitialupdate) (para exibições).

- Colocar dados no controle, chamando o `CTreeCtrl`do [InsertItem](../mfc/reference/ctreectrl-class.md#insertitem) função uma vez para cada item de dados. `InsertItem` Retorna um identificador para o item que você pode usar para fazer referência a ele mais tarde, por exemplo, ao adicionar itens filho. Um bom momento para inicializar os dados está em `OnInitDialog` (para controles em caixas de diálogo) ou `OnInitialUpdate` (para exibições).

- Conforme o usuário interage com o controle, ele envia várias mensagens de notificação. Você pode especificar uma função para lidar com cada uma das mensagens que você deseja manipular, adicionando uma macro ON_NOTIFY_REFLECT no mapa de mensagens da janela de controle ou pela adição de uma macro ON_NOTIFY ao mapa de mensagem da sua janela pai. Ver [mensagens de notificação de controle de árvore](../mfc/tree-control-notification-messages.md) mais adiante neste tópico para obter uma lista de notificações possíveis.

- Chame várias funções de membro de conjunto para definir valores para o controle. As alterações que você pode fazer incluem definir o recuo e alterar o texto, imagem ou associados a um item de dados.

- Use as várias funções de Get para examinar o conteúdo do controle. Você também pode percorrer o conteúdo do controle de árvore com funções que permitem que você recupere os identificadores para os pais, filhos e irmãos de um item especificado. Você pode até mesmo classificar os filhos de um nó específico.

- Quando você terminar com o controle, certifique-se de que ser destruído corretamente. Se o controle de árvore está em uma caixa de diálogo ou se ele é um modo de exibição, ele e o `CTreeCtrl` objeto será destruído automaticamente. Se não, você precisa garantir que os dois o controle e o `CTreeCtrl` objeto são destruídos corretamente.

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](../mfc/using-ctreectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
