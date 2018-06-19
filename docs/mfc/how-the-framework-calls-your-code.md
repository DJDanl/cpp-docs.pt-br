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
ms.openlocfilehash: f746ce3c3d658ab1dccc098939410b52d91b1188
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33348173"
---
# <a name="how-the-framework-calls-your-code"></a>Como o Framework chama o código
É fundamental compreender a relação entre seu código-fonte e o código do Framework do MFC. Quando seu aplicativo é executado, a maioria do fluxo de controle reside no código do framework. A estrutura gerencia o loop de mensagem que obtém as mensagens do Windows que o usuário escolhe comandos e edita dados em uma exibição. Eventos que a estrutura pode manipular por si só não confiam no seu código em todos os. Por exemplo, o framework sabe como fechar janelas e como sair do aplicativo em resposta aos comandos do usuário. Como ele trata essas tarefas, a estrutura usa manipuladores de mensagens e funções virtuais do C++ para lhe dar oportunidades para responder a esses eventos também. Seu código é não no controle, no entanto; a estrutura é.  
  
 O framework chama o código para eventos específicos de aplicativos. Por exemplo, quando o usuário escolhe um comando de menu, o framework roteia o comando ao longo de uma sequência de objetos C++: a janela de exibição e o quadro atual, o documento associado com o modo de exibição, o modelo de documento do documento e o objeto de aplicativo. Se um desses objetos pode lidar com o comando, ele faz isso, chamando a função de manipulador de mensagem apropriado. Para qualquer comando fornecido, o código de chamada pode ser sua ou pode ser a estrutura.  
  
 Essa organização é um pouco familiarizada aos programadores experientes com programação tradicional do Windows ou programação controlada por evento.  
  
 Tópicos relacionados, você lerá o que a estrutura de como ela inicia e executa o aplicativo e, em seguida, limpa conforme o encerramento do aplicativo. Você também entenderá onde o código que você escreve se encaixa no.  
  
 Para obter mais informações, consulte [classe CWinApp: A classe do aplicativo](../mfc/cwinapp-the-application-class.md) e [modelos de documento e o processo de criação de documento/exibição](../mfc/document-templates-and-the-document-view-creation-process.md).  
  
## <a name="see-also"></a>Consulte também  
 [Compilando no Framework](../mfc/building-on-the-framework.md)

