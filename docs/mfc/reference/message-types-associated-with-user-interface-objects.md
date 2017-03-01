---
title: "Tipos associados aos objetos de Interface do usuário de mensagem | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.codewiz.uiobject.msgs
dev_langs:
- C++
helpviewer_keywords:
- message types and user interface objects
ms.assetid: 681ee1a7-f6e6-4ea0-9fc6-1fb53a35516e
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: ef4021c7d64f6753e43e3b8f8c61c022fef9913c
ms.lasthandoff: 02/25/2017

---
# <a name="message-types-associated-with-user-interface-objects"></a>Tipos de mensagem associados a objetos de interface do usuário
A tabela a seguir mostra os tipos de objetos com os quais você trabalha e os tipos de mensagens associadas a eles.  
  
### <a name="user-interface-objects-and-associated-messages"></a>Objetos de Interface do usuário e mensagens associadas  
  
|ID do Objeto|Mensagens|  
|---------------|--------------|  
|Nome da classe, que representa a janela|Mensagens do Windows apropriada para um [CWnd](../../mfc/reference/cwnd-class.md)-classe derivada: uma caixa de diálogo, janela, janela filho, janela filho MDI ou quadro superior.|  
|Identificador de menu ou acelerador|-   **COMANDO** mensagem (executa o programa funcionar).<br />-   **UPDATE_COMMAND_UI** mensagem (atualiza dinamicamente o item de menu).|  
|Identificador de controle|Mensagens de notificação do controle para o tipo de controle selecionado.|  
  
## <a name="see-also"></a>Consulte também  
 [Mapeando mensagens para funções](../../mfc/reference/mapping-messages-to-functions.md)   
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)   
 [Adicionando uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)   
 [Adicionando uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)   
 [Substituindo uma função Virtual](../../ide/overriding-a-virtual-function-visual-cpp.md)   
 [Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)   
 [Navegando na estrutura da classe](../../ide/navigating-the-class-structure-visual-cpp.md)

