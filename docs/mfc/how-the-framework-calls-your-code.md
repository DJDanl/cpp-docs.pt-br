---
title: Como o Framework chama o código
ms.date: 11/04/2016
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
ms.openlocfilehash: 318ca9558d705ca483d41867a1fe2ad46c36666f
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84622602"
---
# <a name="how-the-framework-calls-your-code"></a>Como o Framework chama o código

É crucial entender a relação entre o código-fonte e o código na estrutura do MFC. Quando seu aplicativo é executado, a maior parte do fluxo de controle reside no código da estrutura. A estrutura gerencia o loop de mensagem que recebe mensagens do Windows à medida que o usuário escolhe comandos e edita dados em uma exibição. Eventos que a estrutura pode manipular por si só não dependem de seu código. Por exemplo, a estrutura sabe como fechar o Windows e como sair do aplicativo em resposta aos comandos do usuário. Como ele manipula essas tarefas, a estrutura usa manipuladores de mensagens e funções virtuais do C++ para dar a você oportunidades de responder a esses eventos também. No entanto, o código não está no controle; a estrutura é.

A estrutura chama seu código para eventos específicos do aplicativo. Por exemplo, quando o usuário escolhe um comando de menu, a estrutura roteia o comando ao longo de uma sequência de objetos C++: a exibição atual e a janela de quadro, o documento associado à exibição, o modelo de documento do documento e o objeto de aplicativo. Se um desses objetos puder manipular o comando, ele fará isso, chamando a função apropriada do manipulador de mensagens. Para qualquer comando fornecido, o código chamado pode ser seu ou pode ser o da estrutura.

Essa organização é um pouco familiar para os programadores experientes na programação tradicional para Windows ou em programação orientada a eventos.

Nos tópicos relacionados, você lerá o que a estrutura faz quando Inicializa e executa o aplicativo e, em seguida, limpa conforme o aplicativo é encerrado. Você também entenderá onde o código que você escreve se encaixa.

Para obter mais informações, consulte [Class CWinApp: a classe Application](cwinapp-the-application-class.md) e [modelos de documento e o processo de criação de documento/exibição](document-templates-and-the-document-view-creation-process.md).

## <a name="see-also"></a>Consulte também

[Criando na estrutura](building-on-the-framework.md)
