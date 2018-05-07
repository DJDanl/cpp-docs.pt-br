---
title: Manipuladores de mensagens | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- message handlers [MFC]
- command handling [MFC], message handlers
- handlers [MFC]
- message handling [MFC], message handler functions
- handlers [MFC], command
- handlers [MFC], message
ms.assetid: 51bc4e76-dbe3-4cc2-b026-3199d56b2fa9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: be4ccf9ec33e5ddf497193c1942e9f300f8cae57
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="message-handlers"></a>Manipuladores de mensagens
Em MFC, dedicado *manipulador* função processa cada mensagem separada. Funções de manipulador de mensagens são funções de membro de uma classe. Esta documentação usa os termos *função de membro de manipulador de mensagens*, *função do manipulador de mensagens*, *manipulador de mensagens*, e *manipulador*alternadamente. Alguns tipos de manipuladores de mensagens também são chamados de "manipuladores de comando".  
  
 Gravando contas de manipuladores de mensagens para uma grande proporção de seu trabalho em escrever um aplicativo do framework. Família este artigo descreve como funciona o mecanismo de processamento de mensagens.  
  
 O que faz com que o manipulador para uma mensagem de fazê-lo faz tudo o que você deseja em resposta à mensagem. Você pode criar manipuladores usando a janela de propriedades da classe e, em seguida, preencha código o manipulador do usando o editor de código fonte.  
  
 Você pode usar todos os recursos do Microsoft Visual C++ e MFC para gravar seus manipuladores. Para obter uma lista de todas as classes, consulte [visão geral da biblioteca de classe](../mfc/class-library-overview.md) no *referência MFC*.  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)

