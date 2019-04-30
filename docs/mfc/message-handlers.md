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
ms.openlocfilehash: 0d3ed6239b638a0e161cd7e3580f4fe6e1b4a7e7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62383746"
---
# <a name="message-handlers"></a>Manipuladores de mensagens

No MFC, dedicado *manipulador* função processa cada mensagem separada. Funções de manipulador de mensagens são funções de membro de uma classe. Esta documentação usa os termos *função de membro de manipulador de mensagens*, *função de manipulador de mensagens*, *manipulador de mensagens*, e *manipulador*alternadamente. Alguns tipos de manipuladores de mensagens também são chamados de "manipuladores de comandos".

Gravando as contas de manipuladores de mensagens para uma grande proporção de seu trabalho em escrever um aplicativo de estrutura. Família este artigo descreve como funciona o mecanismo de processamento de mensagens.

O que faz com que o manipulador para uma mensagem de fazê-lo faz tudo o que você pretende fazer em resposta a essa mensagem. Você pode criar os manipuladores usando a janela de propriedades da classe e, em seguida, preencha código o manipulador do usando o editor de código fonte.

Você pode usar todos os recursos do Microsoft Visual C++ e MFC para gravar seus manipuladores. Para obter uma lista de todas as classes, consulte [visão geral da biblioteca de classes](../mfc/class-library-overview.md) na *referência da MFC*.

## <a name="see-also"></a>Consulte também

[Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)
