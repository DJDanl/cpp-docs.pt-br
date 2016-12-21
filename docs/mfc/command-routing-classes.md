---
title: "Classes de roteamento do comando | Microsoft Docs"
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
  - "vc.classes.command"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "roteamento de comando, Classes "
  - "MFC, roteamento de comando"
ms.assetid: 4b50e689-2c54-4e6c-90f0-37333e22b2a1
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de roteamento do comando
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

à medida que o usuário interage com o aplicativo escolhendo menus ou botões da barra de controle com o mouse, as mensagens dos envios de aplicativo do objeto da interface do usuário afetado comando\- a um destino satisfatório objeto.  As classes de Comando\- destino derivadas de `CCmdTarget` incluem [CWinApp](../mfc/reference/cwinapp-class.md), [CWnd](../Topic/CWnd%20Class.md), [CDocTemplate](../mfc/reference/cdoctemplate-class.md), [CDocument](../Topic/CDocument%20Class.md), [CView](../Topic/CView%20Class.md), e as classes derivadas deless.  O roteamento automático de comando da suporte à estrutura de forma que os comandos possam ser tratados pela maioria objeto apropriado atualmente ativo no aplicativo.  
  
 Um objeto da classe `CCmdUI` é passado para manipuladores de interface de usuário do comando de atualização de seus destinos de comando \(\)[ON\_UPDATE\_COMMAND\_UI](../Topic/ON_UPDATE_COMMAND_UI.md)para permitir que você atualiza o estado da interface do usuário para um comando específico \(por exemplo, para verificar ou remover a verificação dos itens de menu\).  Você chamar funções de membro do objeto de `CCmdUI` para atualizar o estado do objeto da interface do usuário.  Esse processo é o mesmo que o objeto da interface do usuário associado a um comando específico é um item de menu ou botão ou ambos.  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
 Serve como a classe base para todas as classes de objetos que podem receber e responder a mensagens do.  
  
 [CCmdUI](../Topic/CCmdUI%20Class.md)  
 Fornece uma interface programática para atualizar objetos de interface do usuário como itens de menu ou botões da barra de controle.  O objeto de destino do comando habilitar, desabilitar, verifica, e\/ou limpa o objeto da interface do usuário com esse objeto.  
  
## Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)