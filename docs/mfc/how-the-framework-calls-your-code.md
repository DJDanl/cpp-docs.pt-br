---
title: Como o Framework chama o código | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- control flow [MFC], MFC framework and your code
- events [MFC], command routing in MFC
- command routing [MFC], framework
- command handling [MFC], calling handlers and code in MFC
- events [MFC], event-driven programming
- MFC, calling code from
- MFC, calling code
- application-specific events [MFC]
- command routing [MFC], MFC
ms.assetid: 39e68189-a580-40d0-9e35-bf5cd24a8ecf
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 68db9107a8d2d113e9118c9cf125acb2798edcd4
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46373864"
---
# <a name="how-the-framework-calls-your-code"></a>Como o Framework chama o código

É crucial entender a relação entre o código-fonte e o código na estrutura MFC. Quando seu aplicativo é executado, a maioria do fluxo de controle reside no código da estrutura. A estrutura gerencia o loop de mensagem que obtém as mensagens do Windows como o usuário escolhe comandos e edita dados em uma exibição. Eventos que o framework pode manipular por si só não dependem de seu código em todos os. Por exemplo, a estrutura sabe como fechar janelas e como sair do aplicativo em resposta a comandos do usuário. Como ele lida com essas tarefas, a estrutura usa manipuladores de mensagens e funções virtuais do C++ para dar a você oportunidades para responder a esses eventos também. Seu código é não está no controle, no entanto; a estrutura é.

O framework chama o código para eventos específicos do aplicativo. Por exemplo, quando o usuário escolhe um comando de menu, o framework roteia o comando ao longo de uma sequência de objetos C++: a janela de exibição e o quadro atual, o documento associado com o modo de exibição, o modelo de documento do documento e o objeto de aplicativo. Se um desses objetos pode lidar com o comando, ele faz isso, chamando a função de manipulador de mensagens apropriado. Para qualquer comando, o código de chamada pode ser seu ou pode ser a estrutura.

Essa disposição é um pouco familiar para os programadores têm experientes com programação tradicional para Windows ou programação controlada por evento.

Tópicos relacionados, você lerá o que a estrutura de como ela inicializa e executa o aplicativo e, em seguida, limpa conforme o aplicativo será encerrado. Você saberá onde o código que você escreve se encaixa.

Para obter mais informações, consulte [classe CWinApp: A classe de aplicativo](../mfc/cwinapp-the-application-class.md) e [modelos de documento e o processo de criação de documento/exibição](../mfc/document-templates-and-the-document-view-creation-process.md).

## <a name="see-also"></a>Consulte também

[Compilando no Framework](../mfc/building-on-the-framework.md)

