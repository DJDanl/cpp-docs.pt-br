---
title: Executar função membro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- WinMain method [MFC]
ms.assetid: 24ab7597-2354-495b-9a20-2c8ccc7385b3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 446b1b6fc2a5265e2c4eb8a608ff8b4f0028c57d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46408226"
---
# <a name="run-member-function"></a>Executar função membro

Um aplicativo do framework passa a maior parte de seu tempo a [executados](../mfc/reference/cwinapp-class.md#run) função de membro da classe [CWinApp](../mfc/reference/cwinapp-class.md). Após a inicialização, `WinMain` chamadas `Run` para processar o loop de mensagem.

`Run` ciclos por meio de um loop de mensagem, verificando a fila de mensagens para mensagens disponíveis. Se uma mensagem estiver disponível, `Run` a envia para a ação. Se nenhuma mensagem estiver disponível, que geralmente é true, `Run` chamadas `OnIdle` fazer qualquer processamento de tempo ocioso que você ou à estrutura, talvez seja necessário feito. Se não houver nenhuma mensagem e nenhum processamento ocioso a fazer, o aplicativo aguarda até que algo aconteça. Quando o aplicativo é encerrado, `Run` chamadas `ExitInstance`. A figura no [função de membro OnIdle](../mfc/onidle-member-function.md) mostra a sequência de ações no loop de mensagem.

Despacho de mensagens depende do tipo de mensagem. Para obter mais informações, consulte [mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md).

## <a name="see-also"></a>Consulte também

[CWinApp: a classe do aplicativo](../mfc/cwinapp-the-application-class.md)
