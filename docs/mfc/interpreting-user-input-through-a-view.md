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
ms.openlocfilehash: 43fb903fa169233ce532e41ecdf02c23ab6037c8
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621458"
---
# <a name="interpreting-user-input-through-a-view"></a>Interpretando a entrada do usuário por meio de uma exibição

Outras funções de membro da alça de exibição e interpretam todas as entradas do usuário. Normalmente, você definirá funções de membro de manipulador de mensagens em sua classe de exibição para processar:

- [Mensagens](messages.md) do Windows geradas por ações de mouse e teclado.

- [Comandos](user-interface-objects-and-command-ids.md) de menus, botões da barra de ferramentas e teclas de aceleração.

Essas funções de membro do manipulador de mensagens interpretam as seguintes ações como entrada, seleção ou edição de dados, incluindo a movimentação de dados de e para a área de transferência:

- Movimentos e cliques do mouse, arrasta e clica duas vezes

- Pressionamentos

- Comandos de menu

Quais mensagens do Windows seus identificadores de exibição dependem das necessidades do seu aplicativo.

[Tópicos de manipulação e mapeamento de mensagens](message-handling-and-mapping.md) explica como atribuir itens de menu e outros objetos de interface do usuário a comandos e como associar os comandos a funções de manipulador. [Tópicos de manipulação e mapeamento de mensagens](message-handling-and-mapping.md) também explica como o MFC roteia comandos e envia mensagens padrão do Windows para os objetos que contêm manipuladores para eles.

Por exemplo, seu aplicativo pode precisar implementar o desenho direto do mouse na exibição. O exemplo de rabisco mostra como lidar com as mensagens WM_LBUTTONDOWN, WM_MOUSEMOVE e WM_LBUTTONUP, respectivamente, para iniciar, continuar e encerrar o desenho de um segmento de linha. Por outro lado, às vezes você pode precisar interpretar um clique do mouse no modo de exibição como uma seleção. A função do `OnLButtonDown` manipulador de exibição determinaria se o usuário estava desenhando ou selecionando. Se você selecionar, o manipulador determinaria se o clique estava dentro dos limites de algum objeto na exibição e, em caso afirmativo, altero a exibição para mostrar o objeto como selecionado.

O modo de exibição também pode manipular certos comandos de menu, como aqueles do menu Editar para recortar, copiar, colar ou excluir dados selecionados usando a área de transferência. Esse manipulador chamaria algumas das funções de membro relacionadas à área de transferência da classe `CWnd` para transferir um item de dados selecionado para ou da área de transferência.

## <a name="see-also"></a>Consulte também

[Usando exibições](using-views.md)
