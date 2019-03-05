---
title: Destinos de comando
ms.date: 11/04/2016
helpviewer_keywords:
- command targets
- command mapping
- messages, command [MFC]
- command routing [MFC], command targets
ms.assetid: b0f784e5-c6dc-4391-9e71-aa7b7dcbe9f0
ms.openlocfilehash: ed3d6a68967dc7f4244f887ae34760fdb99fa7f5
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57274434"
---
# <a name="command-targets"></a>Destinos de comando

A Figura [comandos no Framework](../mfc/user-interface-objects-and-command-ids.md) mostra a conexão entre um objeto de interface do usuário, como um item de menu e a função de manipulador que o framework chama para executar o comando resultante quando o objeto é clicado.

Windows envia mensagens que não são mensagens de comando diretamente para uma janela cujo manipulador para a mensagem, em seguida, é chamado. No entanto, o framework roteia comandos para um número de objetos de release candidate — chamado "destinos de comando" — um dos quais normalmente invoca um manipulador para o comando. As funções do manipulador funcionam da mesma maneira para comandos e mensagens padrão do Windows, mas os mecanismos pelos quais eles são chamados são diferentes, conforme explicado em [como o Framework chama um manipulador](../mfc/how-the-framework-calls-a-handler.md).

## <a name="see-also"></a>Consulte também

[Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)
