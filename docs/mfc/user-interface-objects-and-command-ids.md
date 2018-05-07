---
title: Objetos de Interface do usuário e IDs de comando | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- keyboard shortcuts, associating with IDs
- MFC, command routing
- toolbar controls [MFC], command ID
- menu items, associating with IDs
- user interface objects [MFC], associating with IDs
- command IDs, user interface objects
- command routing [MFC], MFC
- command handling [MFC], user-interface objects
ms.assetid: 4ea19e9b-ed1e-452e-bd33-7f509107a45b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6b56babf0e42dde521a6bda3a7d9713db519182c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="user-interface-objects-and-command-ids"></a>Objetos de interface do usuário e IDs de comando
Itens de menu, botões da barra de ferramentas e teclas de aceleração são "objetos de interface do usuário" capaz de gerar comandos. Cada objeto de interface de usuário tais tem uma identificação. Você pode associar um objeto de interface do usuário com um comando atribuindo a mesma ID de objeto e o comando. Conforme explicado em [mensagens](../mfc/messages.md), comandos são implementados como mensagens especiais. A Figura "Comandos no Framework" abaixo mostra como o framework gerencia os comandos. Quando um objeto de interface do usuário gera um comando, como `ID_EDIT_CLEAR_ALL`, um dos objetos em seu aplicativo lida com o comando — na figura abaixo, o objeto de documento `OnEditClearAll` função é chamada por meio de mapa do documento da mensagem.  
  
 ![Comandos no Framework](../mfc/media/vc385p1.gif "vc385p1")  
Comandos no Framework  
  
 A Figura "Comando de atualização no Framework" abaixo mostra como o MFC atualiza os objetos de interface do usuário como itens de menu e botões de barra de ferramentas. Antes de um menu suspenso ou durante o loop ocioso no caso de botões de barra de ferramentas, MFC roteia um comando de atualização. Na figura abaixo, o objeto de documento chama seu manipulador de comando de atualização, `OnUpdateEditClearAll`, para habilitar ou desabilitar o objeto de interface do usuário.  
  
 ![Comando de atualização na estrutura](../mfc/media/vc385p2.png "vc385p2")  
Comando de atualização no Framework  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)

