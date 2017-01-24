---
title: "IDs de comando | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "IDs de comando"
  - "IDs de comando, MFC"
ms.assetid: e0171a2b-45b9-41fa-945d-ec2f7602ded0
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IDs de comando
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um comando é descrito completamente por sua ID de comando \(codificado na mensagem de **WM\_COMMAND** \).  Essa ID é atribuída ao objeto da interface do usuário que gerencia o comando.  Normalmente, os IDs são nomeados para a funcionalidade do objeto da interface do usuário que são atribuídos a.  
  
 Por exemplo, um espaço livre qualquer item do menu editar pode ser atribuído um ID como **ID\_EDIT\_CLEAR\_ALL**.  A biblioteca de classes predefine alguns IDs, particularmente para os comandos que a estrutura controla própria, como **ID\_EDIT\_CLEAR\_ALL** ou `ID_FILE_OPEN`.  Você criará outros IDs de comando você mesmo.  
  
 Quando você criar seus próprios menus no publicador no menu do Visual C\+\+, é uma boa ideia seguir a convenção de nomenclatura de biblioteca de classe como ilustrado por `ID_FILE_OPEN`.  [Comandos padrão](../mfc/standard-commands.md) explica os comandos padrão definidos pela biblioteca da classe.  
  
## Consulte também  
 [Objetos de interface do usuário e IDs de comando](../mfc/user-interface-objects-and-command-ids.md)