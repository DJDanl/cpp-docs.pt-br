---
title: IDs de comando
ms.date: 11/04/2016
helpviewer_keywords:
- command IDs, MFC
- command IDs
ms.assetid: e0171a2b-45b9-41fa-945d-ec2f7602ded0
ms.openlocfilehash: f7d675891904301b16aafe3acb2c294eede6d8d8
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619035"
---
# <a name="command-ids"></a>IDs de comando

Um comando é totalmente descrito por sua ID de comando sozinha (codificada na mensagem de **WM_COMMAND** ). Essa ID é atribuída ao objeto user-interface que gera o comando. Normalmente, as IDs são nomeadas para a funcionalidade do objeto de interface de usuário à qual são atribuídas.

Por exemplo, um item apagar tudo no menu Editar pode receber uma ID, como **ID_EDIT_CLEAR_ALL**. A biblioteca de classes predefine algumas IDs, especialmente para comandos que a estrutura manipula em si, como **ID_EDIT_CLEAR_ALL** ou **ID_FILE_OPEN**. Você mesmo criará outras IDs de comando.

Quando você cria seus próprios menus no editor de menu Visual C++, é uma boa ideia seguir a Convenção de nomenclatura da biblioteca de classes, conforme ilustrado por **ID_FILE_OPEN**. [Comandos padrão](standard-commands.md) explica os comandos padrão definidos pela biblioteca de classes.

## <a name="see-also"></a>Consulte também

[Objetos de interface do usuário e IDs de comando](user-interface-objects-and-command-ids.md)
