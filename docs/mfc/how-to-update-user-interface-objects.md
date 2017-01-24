---
title: "Como atualizar objetos de interface do usu&#225;rio | Microsoft Docs"
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
  - "comandos, atualizando IU"
  - "desabilitando menus"
  - "desabilitando elementos de IU"
  - "habilitando menus"
  - "habilitando elementos de IU"
  - "menus, atualizando como alterações de contexto"
  - "atualizar manipuladores"
  - "atualizando objetos de interface do usuário"
  - "objetos de interface do usuário"
  - "objetos de interface do usuário, atualizando"
ms.assetid: 82f09773-c978-427b-b321-05a6143b7369
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como atualizar objetos de interface do usu&#225;rio
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Normalmente, os itens de menu e os botões da barra de ferramentas têm mais de um estado.  Por exemplo, um item de menu estiver acinzentada \(esmaecido\) se não estiver disponível no contexto atual.  Os itens de menu também podem ser verificados ou desmarcadas.  Um botão da barra de ferramentas também pode ser desabilitado se não estiver disponível, ou pode ser verificado.  
  
 Quem atualiza o estado desses itens conforme as condições mudam de programa?  Logicamente, se um item de menu gerencie um comando que é tratado por exemplo por um documento, faz sentido que o documento atualizar o item de menu.  O documento contém informações que provavelmente na atualização é baseada.  
  
 Se um comando tiver vários objetos de interface do usuário \(talvez um item de menu e um botão da barra de ferramentas\), ambos são encaminhadas para a mesma função do manipulador.  Isso encapsula seu código de atualização da interface do usuário para todos os objetos de interface do usuário equivalentes em um único local.  
  
 A estrutura fornece uma interface conveniente para atualizar automaticamente objetos de interface do usuário.  Você pode escolher fazer a atualização de outra forma, mas a interface fornecida é eficiente e fácil usar.  
  
 Os tópicos seguintes explicam o uso de manipuladores de atualização:  
  
-   [Quando os manipuladores de atualização são chamados](../mfc/when-update-handlers-are-called.md)  
  
-   [A macro de ON\_UPDATE\_COMMAND\_UI](../mfc/on-update-command-ui-macro.md)  
  
-   [A classe de CCmdUI](../mfc/the-ccmdui-class.md)  
  
## Consulte também  
 [Menus](../mfc/menus-mfc.md)