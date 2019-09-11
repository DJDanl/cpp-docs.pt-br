---
title: Manipuladores de mensagens
ms.date: 11/04/2016
helpviewer_keywords:
- message handlers [MFC]
- command handling [MFC], message handlers
- handlers [MFC]
- message handling [MFC], message handler functions
- handlers [MFC], command
- handlers [MFC], message
ms.assetid: 51bc4e76-dbe3-4cc2-b026-3199d56b2fa9
ms.openlocfilehash: 25805187f88c5423ea41cd7cbe346e44e7d7d36a
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70907456"
---
# <a name="message-handlers"></a>Manipuladores de mensagens

No MFC, uma função de *manipulador* dedicada processa cada mensagem separada. As funções de manipulador de mensagens são funções membro de uma classe. Esta documentação usa os termos *função de membro de manipulador de mensagens*, *função de manipulador de mensagens*, manipulador de *mensagens*e *manipulador* intercambiáveis. Alguns tipos de manipuladores de mensagens também são chamados de "manipuladores de comandos".

Escrever contas de manipuladores de mensagens para uma grande proporção do seu trabalho em escrever um aplicativo de estrutura. Esta família de artigos descreve como funciona o mecanismo de processamento de mensagens.

O que faz o manipulador de uma mensagem fazer tudo o que você deseja fazer em resposta a essa mensagem. Você pode criar os manipuladores usando o [Assistente de classe](reference/mfc-class-wizard.md) da classe e, em seguida, preencher o código do manipulador usando o editor de código-fonte.

Você pode usar todos os recursos do Microsoft Visual C++ e do MFC para escrever seus manipuladores. Para obter uma lista de todas as classes, consulte [visão geral da biblioteca de classes](../mfc/class-library-overview.md) na *referência do MFC*.

## <a name="see-also"></a>Consulte também

[Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)
