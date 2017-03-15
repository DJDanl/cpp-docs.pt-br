---
title: "Objetos de interface do usu&#225;rio e IDs de comando | Microsoft Docs"
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
  - "tratamento de comandos, objetos de interface do usuário"
  - "IDs de comando, objetos de interface do usuário"
  - "roteamento de comando, MFC"
  - "atalhos de teclado, associando a IDs"
  - "itens de menu, associando a IDs"
  - "MFC, roteamento de comando"
  - "controles de barra de ferramentas [MFC], ID de comando"
  - "objetos de interface do usuário, associando a IDs"
ms.assetid: 4ea19e9b-ed1e-452e-bd33-7f509107a45b
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Objetos de interface do usu&#225;rio e IDs de comando
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os itens de menu, os botões da barra de ferramentas, e teclas de aceleração “são objetos de interface do usuário” capazes de gerar comandos.  Cada um objeto da interface do usuário possui uma ID  Você associa um objeto da interface do usuário com um comando atribuindo a mesma ID do objeto e o comando.  Como explicado em [Mensagens](../mfc/messages.md), comandos são implementados como mensagens especiais.  A figura “comandos na estrutura” abaixo mostra como a estrutura gerencia comandos.  Quando um objeto da interface do usuário gerencie um comando, como `ID_EDIT_CLEAR_ALL`, um dos objetos em seu aplicativo trata o comando — na figura a seguir, a função de `OnEditClearAll` do objeto de documento é chamada através da mensagem do documento.  
  
 ![Estrutura Vc&#95;commands](../mfc/media/vc385p1.png "vc385P1")  
Comandos na estrutura  
  
 A figura “comando que atualiza na estrutura” abaixo mostra como o MFC atualiza objetos de interface do usuário como itens de menu e botões da barra de ferramentas.  Antes que um menu suspensa, ou durante o loop ocioso no caso de botões da barra de ferramentas, rotas MFC um comando de atualização.  Na figura abaixo, o objeto de documento chama o manipulador de comando de atualização, `OnUpdateEditClearAll`, para habilitar ou desabilitar o objeto da interface do usuário.  
  
 ![Estrutura de atualização de comando](../Image/vc385P2.png "vc385P2")  
Comando que atualiza na estrutura  
  
## Consulte também  
 [Mensagens e comandos no Framework](../mfc/messages-and-commands-in-the-framework.md)