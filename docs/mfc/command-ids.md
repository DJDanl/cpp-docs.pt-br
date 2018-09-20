---
title: IDs de comando | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- command IDs, MFC
- command IDs
ms.assetid: e0171a2b-45b9-41fa-945d-ec2f7602ded0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5087c271151793169cbf7350f78750044ccead0b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46446966"
---
# <a name="command-ids"></a>IDs de comando

Um comando é totalmente descrito pela sua ID de comando sozinho (codificado na **WM_COMMAND** mensagem). Essa ID é atribuída ao objeto de interface do usuário que gera o comando. Normalmente, as IDs são nomeadas para a funcionalidade do objeto de interface do usuário que estão atribuídas.

Por exemplo, um item de Limpar tudo no menu Editar pode ser atribuído a uma ID como **ID_EDIT_CLEAR_ALL**. A biblioteca de classes predefine algumas IDs, particularmente para comandos que o framework manipula em si, como **ID_EDIT_CLEAR_ALL** ou **ID_FILE_OPEN**. Você irá criar outras IDs de comando.

Quando você cria seus próprios menus no Visual C++ editor de menu, é uma boa ideia siga a biblioteca de classes da convenção de nomenclatura conforme ilustrado pela **ID_FILE_OPEN**. [Comandos padrão](../mfc/standard-commands.md) explica os comandos padrão definidos pela biblioteca de classes.

## <a name="see-also"></a>Consulte também

[Objetos da interface do usuário e IDs de comando](../mfc/user-interface-objects-and-command-ids.md)

