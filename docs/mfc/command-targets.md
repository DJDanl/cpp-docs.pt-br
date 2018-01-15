---
title: Destinos de comando | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- command targets
- command mapping
- messages, command [MFC]
- command routing [MFC], command targets
ms.assetid: b0f784e5-c6dc-4391-9e71-aa7b7dcbe9f0
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: bb8d2bff69e95a089827c85ade6dc4bcd67eb7ff
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="command-targets"></a>Destinos de comando
A Figura [comandos no Framework](../mfc/user-interface-objects-and-command-ids.md) mostra a conexão entre um objeto de interface do usuário, como um item de menu e a função do manipulador que o framework chama para executar o comando resultante quando o objeto é clicado.  
  
 O Windows envia mensagens que não são mensagens de comando diretamente para uma janela cujo manipulador para a mensagem é chamado. No entanto, a estrutura roteia comandos para um número de objetos de candidato, chamado "destinos de comando" — um dos quais normalmente invoca um manipulador para o comando. As funções do manipulador funcionam da mesma forma para comandos e mensagens padrão do Windows, mas os mecanismos pelos quais eles são chamados são diferentes, conforme explicado em [como o Framework chama um manipulador](../mfc/how-the-framework-calls-a-handler.md).  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)

