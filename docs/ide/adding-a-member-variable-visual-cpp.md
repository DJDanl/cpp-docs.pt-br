---
title: "Adicionando uma vari&#225;vel de membro (Visual C++) | Microsoft Docs"
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
  - "vc.codewiz.classes.member.variable"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "variáveis de membro"
  - "variáveis de membro, adicionando"
ms.assetid: 437783bd-8eb4-4508-8b73-7380116e9d71
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando uma vari&#225;vel de membro (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode adicionar uma variável de membro a uma classe usando o modo de exibição de classe.  Variáveis de membro podem ser apenas para  [troca de dados e validação de dados](../mfc/dialog-data-exchange-and-validation.md), ou podem ser genéricos.  O Assistente de variável de membro de dados é projetado especificamente para levar as informações relevantes e usá\-lo para inserir elementos em seus arquivos de origem nos locais apropriados.  Você pode adicionar uma variável de membro do  [editor de diálogo](../mfc/dialog-editor.md) na  [Exibição de recurso](../windows/resource-view-window.md), ou a partir de  [Class View](http://msdn.microsoft.com/pt-br/8d7430a9-3e33-454c-a9e1-a85e3d2db925).  
  
> [!NOTE]
>  Quando você está projetando e implementando uma caixa de diálogo, talvez seja mais eficiente usar a caixa de diálogo editor para adicionar os controles de caixa de diálogo e, em seguida, para implementar as variáveis de membro dos controles.  
  
### Para adicionar uma variável de membro para um controle de caixa de diálogo no modo de exibição de recurso usando o Assistente para Adicionar variável de membro  
  
1.  No modo de exibição de recursos, expanda o nó do projeto e o nó de diálogo para exibir a lista das caixas de diálogo do projeto.  
  
2.  Clique duas vezes na caixa de diálogo ao qual você deseja adicionar a variável de membro para abri\-lo no editor de diálogo.  
  
3.  Na caixa de diálogo exibida no editor de diálogo, clique com o botão direito no controle ao qual você deseja adicionar a variável de membro.  
  
4.  No menu de atalho, clique em  **Adicionar variável** para exibir o  [O Assistente de variável de membro adicionar](../ide/add-member-variable-wizard.md).  
  
    > [!NOTE]
    >  Um valor padrão já é fornecido em  **ID de controle de**.  
  
5.  Forneça as informações nas caixas do assistente apropriado.  Consulte  [controles de caixa de diálogo e tipos de variáveis](../Topic/Dialog%20Box%20Controls%20and%20Variable%20Types.md) para obter mais informações.  
  
6.  Clique em  **Concluir** para adicionar o código de definição e implementação para o projeto e fechar o assistente.  
  
### Para adicionar uma variável de membro do modo de exibição de classe usando o Assistente para Adicionar variável de membro  
  
1.  Em  [Class View](http://msdn.microsoft.com/pt-br/8d7430a9-3e33-454c-a9e1-a85e3d2db925), expanda o nó do projeto para exibir as classes no projeto.  
  
2.  A classe à qual você deseja adicionar uma variável de atalho.  
  
3.  No menu de atalho, clique em  **Add**e, em seguida, clique em  **Adicionar variável** para exibir o Assistente de variável de membro adicionar.  
  
4.  Forneça as informações nas caixas do assistente apropriado.  Consulte  [O Assistente de variável de membro adicionar](../ide/add-member-variable-wizard.md) para obter detalhes.  
  
5.  Clique em  **Concluir** para adicionar o código de definição e implementação para o projeto e fechar o assistente.  
  
## Consulte também  
 [Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando uma classe](../Topic/Adding%20a%20Class%20\(Visual%20C++\).md)   
 [Adicionando uma função de membro](../ide/adding-a-member-function-visual-cpp.md)   
 [Manipulador de mensagens do MFC](../mfc/reference/adding-an-mfc-message-handler.md)   
 [Navegando na estrutura da classe](../ide/navigating-the-class-structure-visual-cpp.md)