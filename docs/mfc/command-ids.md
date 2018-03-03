---
title: IDs de comando | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- command IDs, MFC
- command IDs
ms.assetid: e0171a2b-45b9-41fa-945d-ec2f7602ded0
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b651c734fbd7098705801aefcaa490293a4d661d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="command-ids"></a>IDs de comando
Um comando é totalmente descrito por sua ID de comando apenas (codificado no **WM_COMMAND** mensagem). Essa ID é atribuída ao objeto de interface do usuário que gera o comando. Normalmente, as IDs são nomeados para a funcionalidade do objeto de interface de usuário que são atribuídos ao.  
  
 Por exemplo, um item de Limpar tudo no menu Editar pode ser atribuído um ID como **ID_EDIT_CLEAR_ALL**. A biblioteca de classes predefine algumas IDs, particularmente para comandos que o framework controla, como **ID_EDIT_CLEAR_ALL** ou `ID_FILE_OPEN`. Você irá criar outras IDs de comando.  
  
 Quando você cria seus próprios menus no Visual C++ editor de menu, é recomendável que você siga a biblioteca de classes da convenção de nomenclatura conforme ilustrado pelo `ID_FILE_OPEN`. [Comandos padrão](../mfc/standard-commands.md) explica os comandos padrão definidos pela biblioteca de classe.  
  
## <a name="see-also"></a>Consulte também  
 [Objetos da interface do usuário e IDs de comando](../mfc/user-interface-objects-and-command-ids.md)

