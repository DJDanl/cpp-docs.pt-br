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
ms.openlocfilehash: e1e03f10199c1b582a1a8603a6ea6c93e1d55473
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36931226"
---
# <a name="command-ids"></a>IDs de comando
Um comando é totalmente descrito por sua ID de comando apenas (codificado no **WM_COMMAND** mensagem). Essa ID é atribuída ao objeto de interface do usuário que gera o comando. Normalmente, as IDs são nomeados para a funcionalidade do objeto de interface de usuário que são atribuídos ao.  
  
 Por exemplo, um item de Limpar tudo no menu Editar pode ser atribuído um ID como **ID_EDIT_CLEAR_ALL**. A biblioteca de classes predefine algumas IDs, particularmente para comandos que o framework controla, como **ID_EDIT_CLEAR_ALL** ou **ID_FILE_OPEN**. Você irá criar outras IDs de comando.  
  
 Quando você cria seus próprios menus no Visual C++ editor de menu, é recomendável que você siga a biblioteca de classes da convenção de nomenclatura conforme ilustrado pelo **ID_FILE_OPEN**. [Comandos padrão](../mfc/standard-commands.md) explica os comandos padrão definidos pela biblioteca de classe.  
  
## <a name="see-also"></a>Consulte também  
 [Objetos da interface do usuário e IDs de comando](../mfc/user-interface-objects-and-command-ids.md)

