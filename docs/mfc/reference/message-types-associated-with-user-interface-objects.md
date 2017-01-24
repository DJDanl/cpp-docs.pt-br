---
title: "Tipos de mensagem associados a objetos de interface do usu&#225;rio | Microsoft Docs"
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
  - "vc.codewiz.uiobject.msgs"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tipos de mensagem e objetos de interface do usuário"
ms.assetid: 681ee1a7-f6e6-4ea0-9fc6-1fb53a35516e
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tipos de mensagem associados a objetos de interface do usu&#225;rio
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A tabela a seguir mostra os tipos de objetos com os quais você trabalha, e os tipos de mensagens associadas a eles.  
  
### Objetos de interface do usuário e mensagens associadas  
  
|ID de objeto|Mensagens|  
|------------------|---------------|  
|Nome da classe, representando a janela contentor|Mensagens apropriadas a [CWnd](../Topic/CWnd%20Class.md)\- classe derivada do windows: uma caixa de diálogo, uma janela, uma janela filho, uma janela filho MDI, ou uma janela do nível mais alto do quadro.|  
|Menu ou identificador de acelerador|-   mensagem de**COMANDO** \(executa a função do programa\).<br />-   Mensagem de**UPDATE\_COMMAND\_UI** \(atualizar dinamicamente o item de menu\).|  
|Identificador de controle|Controle notificações para o tipo selecionado do controle.|  
  
## Consulte também  
 [Mapeando mensagens para funções](../Topic/Mapping%20Messages%20to%20Functions.md)   
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando uma classe](../Topic/Adding%20a%20Class%20\(Visual%20C++\).md)   
 [Adicionando uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)   
 [Adicionando uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)   
 [Substituindo uma função virtual](../Topic/Overriding%20a%20Virtual%20Function%20\(Visual%20C++\).md)   
 [Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)   
 [Navegando na estrutura da classe](../../ide/navigating-the-class-structure-visual-cpp.md)