---
title: "A classe CCmdUI | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CCmdUI"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CCmdUI, atualização de menu"
  - "barras de ferramentas [C++], atualizando"
  - "atualizar manipuladores"
  - "atualizando objetos de interface do usuário"
  - "objetos de interface do usuário, atualizando"
ms.assetid: 2f2bae62-8c29-45a4-bbce-490eb01907d5
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# A classe CCmdUI
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando roteiam um comando de atualização a seu manipulador, a estrutura passa o manipulador um ponteiro para um objeto de `CCmdUI` \(ou um objeto de `CCmdUI`\- classe derivada\).  Esse objeto representa o item de menu ou no botão da barra de ferramentas ou outro objeto da interface do usuário que geraram o comando.  O manipulador de atualização chama funções de membro da estrutura de `CCmdUI` pelo ponteiro para atualizar o objeto da interface do usuário.  Por exemplo, aqui está um manipulador de atualização para o espaço livre qualquer item de menu:  
  
 [!code-cpp[NVC_MFCDocView#3](../mfc/codesnippet/CPP/the-ccmdui-class_1.cpp)]  
  
 Este manipulador chama a função de membro de **Habilitar** de um objeto com acesso ao item de menu.  **Habilitar** faz o item disponível para uso.  
  
## Consulte também  
 [Como atualizar objetos de interface do usuário](../mfc/how-to-update-user-interface-objects.md)