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
ms.openlocfilehash: e8a61699ddd2c48e36bdfd5936fb4ab7aa56e0a9
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46416117"
---
# <a name="user-interface-objects-and-command-ids"></a>Objetos de interface do usuário e IDs de comando

Itens de menu, botões de barra de ferramentas e teclas de aceleração são "objetos de interface do usuário" capaz de gerar comandos. Cada objeto de interface do usuário tal possui uma ID. Você pode associar um objeto de interface do usuário com um comando atribuindo a mesma ID de objeto e o comando. Conforme explicado em [mensagens](../mfc/messages.md), comandos são implementados como mensagens especiais. A Figura "Comandos no Framework" abaixo mostra como a estrutura gerencia comandos. Quando um objeto de interface do usuário gera um comando, como `ID_EDIT_CLEAR_ALL`, um dos objetos em seu aplicativo manipula o comando — na figura abaixo, o objeto de documento `OnEditClearAll` função é chamada por meio do mapa de mensagens do documento.

![Comandos no Framework](../mfc/media/vc385p1.gif "vc385p1") comandos no Framework

A Figura "Comando Atualizar no Framework" abaixo mostra como o MFC atualiza os objetos de interface do usuário como itens de menu e botões de barra de ferramentas. Antes de um menu suspenso, ou durante o loop ocioso no caso de botões de barra de ferramentas, o MFC roteia um comando de atualização. Na figura a seguir, o objeto de documento chama seu manipulador de comando de atualização, `OnUpdateEditClearAll`, para habilitar ou desabilitar o objeto de interface do usuário.

![Comando de atualização na estrutura](../mfc/media/vc385p2.png "vc385p2") comando Atualizar no Framework

## <a name="see-also"></a>Consulte também

[Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)

