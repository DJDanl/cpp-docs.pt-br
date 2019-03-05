---
title: IDs de comando
ms.date: 11/04/2016
helpviewer_keywords:
- command IDs, MFC
- command IDs
ms.assetid: e0171a2b-45b9-41fa-945d-ec2f7602ded0
ms.openlocfilehash: 76071105e72f1ca4a851b9cdb76d5f1a96f44edb
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57274564"
---
# <a name="command-ids"></a>IDs de comando

Um comando é totalmente descrito pela sua ID de comando sozinho (codificado na **WM_COMMAND** mensagem). Essa ID é atribuída ao objeto de interface do usuário que gera o comando. Normalmente, as IDs são nomeadas para a funcionalidade do objeto de interface do usuário que estão atribuídas.

Por exemplo, um item de Limpar tudo no menu Editar pode ser atribuído a uma ID como **ID_EDIT_CLEAR_ALL**. A biblioteca de classes predefine algumas IDs, particularmente para comandos que o framework manipula em si, como **ID_EDIT_CLEAR_ALL** ou **ID_FILE_OPEN**. Você irá criar outras IDs de comando.

Quando você cria seus próprios menus no Visual C++ editor de menu, é uma boa ideia siga a biblioteca de classes da convenção de nomenclatura conforme ilustrado pela **ID_FILE_OPEN**. [Comandos padrão](../mfc/standard-commands.md) explica os comandos padrão definidos pela biblioteca de classes.

## <a name="see-also"></a>Consulte também

[Objetos da interface do usuário e IDs de comando](../mfc/user-interface-objects-and-command-ids.md)
