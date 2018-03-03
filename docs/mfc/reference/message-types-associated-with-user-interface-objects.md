---
title: "Os tipos associados aos objetos de Interface de usuário de mensagem | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.codewiz.uiobject.msgs
dev_langs:
- C++
helpviewer_keywords:
- message types and user interface objects [MFC]
ms.assetid: 681ee1a7-f6e6-4ea0-9fc6-1fb53a35516e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4ff4c7aac0c73406503df2f2384249279d3d7f97
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="message-types-associated-with-user-interface-objects"></a>Tipos de mensagem associados a objetos de interface do usuário
A tabela a seguir mostra os tipos de objetos com o qual trabalhar e os tipos de mensagens associadas a eles.  
  
### <a name="user-interface-objects-and-associated-messages"></a>Objetos de Interface do usuário e mensagens associadas  
  
|ID de objeto|Mensagens|  
|---------------|--------------|  
|Nome de classe, que representa a janela|Mensagens do Windows apropriadas para uma [CWnd](../../mfc/reference/cwnd-class.md)-classe derivada: uma caixa de diálogo, janela, janela filho, janela filho MDI ou quadro superior.|  
|Identificador de menu ou acelerador|-   **COMANDO** mensagem (executa a função de programa).<br />-   **UPDATE_COMMAND_UI** mensagem (atualiza dinamicamente o item de menu).|  
|Identificador de controle|Mensagens de notificação de controle para o tipo de controle selecionado.|  
  
## <a name="see-also"></a>Consulte também  
 [Mapeando mensagens para funções](../../mfc/reference/mapping-messages-to-functions.md)   
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)   
 [Adicionar uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)   
 [Adicionar uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)   
 [Substituindo uma função Virtual](../../ide/overriding-a-virtual-function-visual-cpp.md)   
 [Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)   
 [Navegando na estrutura de classe](../../ide/navigating-the-class-structure-visual-cpp.md)
