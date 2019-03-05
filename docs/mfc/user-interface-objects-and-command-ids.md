---
title: Objetos de interface do usuário e IDs de comando
ms.date: 11/19/2018
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
ms.openlocfilehash: 54372facc51062add122c1db2e01e3081127512e
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57278412"
---
# <a name="user-interface-objects-and-command-ids"></a>Objetos de interface do usuário e IDs de comando

Itens de menu, botões de barra de ferramentas e teclas de aceleração são "objetos de interface do usuário" capaz de gerar comandos. Cada objeto de interface do usuário tal possui uma ID. Você pode associar um objeto de interface do usuário com um comando atribuindo a mesma ID de objeto e o comando. Conforme explicado em [mensagens](../mfc/messages.md), comandos são implementados como mensagens especiais. A Figura "Comandos no Framework" abaixo mostra como a estrutura gerencia comandos. Quando um objeto de interface do usuário gera um comando, como `ID_EDIT_CLEAR_ALL`, um dos objetos em seu aplicativo manipula o comando — na figura abaixo, o objeto de documento `OnEditClearAll` função é chamada por meio do mapa de mensagens do documento.

![Comandos no Framework](../mfc/media/vc385p1.gif "comandos no Framework") <br/>
Comandos no Framework

A Figura "Comando Atualizar no Framework" abaixo mostra como o MFC atualiza os objetos de interface do usuário como itens de menu e botões de barra de ferramentas. Antes de um menu suspenso, ou durante o loop ocioso no caso de botões de barra de ferramentas, o MFC roteia um comando de atualização. Na figura a seguir, o objeto de documento chama seu manipulador de comando de atualização, `OnUpdateEditClearAll`, para habilitar ou desabilitar o objeto de interface do usuário.

![Comando de atualização na estrutura](../mfc/media/vc385p2.png "atualização na estrutura de comando") <br/>
Atualizando o comando no Framework

## <a name="see-also"></a>Consulte também

[Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)
