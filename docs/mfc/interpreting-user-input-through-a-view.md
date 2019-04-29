---
title: Interpretando a entrada do usuário por meio de uma exibição
ms.date: 11/04/2016
helpviewer_keywords:
- interpreting user input through views [MFC]
- views [MFC], user interface and input
- input [MFC], view class [MFC]
- CView class [MFC], interpreting user input
- user input [MFC], interpreting through view class [MFC]
ms.assetid: f0302a70-661f-4781-8fe7-78f082bef2a5
ms.openlocfilehash: 3ef23ad74e1ff53d947453faa5682c5ecc1f4e43
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62310910"
---
# <a name="interpreting-user-input-through-a-view"></a>Interpretando a entrada do usuário por meio de uma exibição

Outras funções de membro do modo de exibição manipularem e interpretam todas as entrada do usuário. Normalmente, você definirá funções de membro de manipulador de mensagens em sua classe de exibição para processar:

- Windows [mensagens](../mfc/messages.md) gerado pelas ações de mouse e teclado.

- [Comandos](../mfc/user-interface-objects-and-command-ids.md) de menus, botões de barra de ferramentas e teclas de aceleração.

Essas funções de membro de manipulador de mensagens interpretam as ações a seguir como a entrada de dados, a seleção ou a edição, incluindo a movimentação de dados de e para a área de transferência:

- Os movimentos do mouse e cliques, arrasta e cliques duplos

- Pressionamentos de teclas

- Comandos de menu

Quais mensagens do Windows seus identificadores de exibição depende das necessidades do seu aplicativo.

[Manipulação e mapeamento de tópicos de mensagem](../mfc/message-handling-and-mapping.md) explica como atribuir itens de menu e outros objetos de interface do usuário para comandos e como associar os comandos a funções do manipulador. [Manipulação e mapeamento de tópicos de mensagem](../mfc/message-handling-and-mapping.md) também explica como o MFC roteia comandos e envia mensagens padrão do Windows para os objetos que contêm os manipuladores para eles.

Por exemplo, seu aplicativo talvez precise implementar direto do mouse no modo de exibição de desenho. O exemplo de Scribble mostra como tratar as mensagens WM_LBUTTONDOWN, WM_MOUSEMOVE e WM_LBUTTONUP, respectivamente, para começar, continuar e finalizar o desenho de um segmento de linha. Por outro lado, às vezes, talvez seja necessário interpretar um clique do mouse no modo de exibição como uma seleção. O modo de exibição `OnLButtonDown` função do manipulador determina se o usuário foi de desenho ou a seleção. Se você selecionar, o manipulador poderia determinar se o clique foi dentro dos limites de um objeto no modo de exibição e, nesse caso, altere a exibição para mostrar o objeto como selecionado.

O modo de exibição também pode tratar certos comandos de menu, como aqueles no menu Editar para recortar, copiar, colar ou excluir os dados selecionados usando a área de transferência. Um manipulador desse tipo chamaria alguns do membro relacionadas à área de transferência de funções da classe `CWnd` para transferir um item de dados selecionada ou para a área de transferência.

## <a name="see-also"></a>Consulte também

[Usando exibições](../mfc/using-views.md)
