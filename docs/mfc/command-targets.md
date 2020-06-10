---
title: Destinos de comando
ms.date: 11/04/2016
helpviewer_keywords:
- command targets
- command mapping
- messages, command [MFC]
- command routing [MFC], command targets
ms.assetid: b0f784e5-c6dc-4391-9e71-aa7b7dcbe9f0
ms.openlocfilehash: 59ba197174e95e42cd237c875f39f07801cb3dbe
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619307"
---
# <a name="command-targets"></a>Destinos de comando

Os comandos de figura [na estrutura](user-interface-objects-and-command-ids.md) mostram a conexão entre um objeto de interface de usuário, como um item de menu e a função de manipulador que a estrutura chama para executar o comando resultante quando o objeto é clicado.

O Windows envia mensagens que não são mensagens de comando diretamente a uma janela cujo manipulador para a mensagem, em seguida, é chamado. No entanto, a estrutura roteia comandos para vários objetos candidatos — chamados de "destinos de comando" — um dos quais normalmente invoca um manipulador para o comando. As funções de manipulador funcionam da mesma maneira para os comandos e as mensagens padrão do Windows, mas os mecanismos pelos quais eles são chamados são diferentes, conforme explicado em [como a estrutura chama um manipulador](how-the-framework-calls-a-handler.md).

## <a name="see-also"></a>Consulte também

[Mensagens e comandos no Framework](messages-and-commands-in-the-framework.md)
