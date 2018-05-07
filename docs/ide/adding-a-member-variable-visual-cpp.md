---
title: Adicionar uma variável de membro (Visual C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vc.codewiz.classes.member.variable
dev_langs:
- C++
helpviewer_keywords:
- member variables, adding
- member variables
ms.assetid: 437783bd-8eb4-4508-8b73-7380116e9d71
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fa2a8ef8f7bcdc2d90893acdad98705c9588a5d5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="adding-a-member-variable--visual-c"></a>Adicionando uma variável de membro (Visual C++)
Você pode adicionar uma variável de membro para uma classe usando o modo de exibição de classe. Variáveis de membro podem ser para [troca de dados e validação de dados](../mfc/dialog-data-exchange-and-validation.md), ou podem ser genéricos. O Assistente de variável de membro de dados é projetado especificamente para tomar as informações relevantes e usá-lo para inserir elementos nos arquivos de origem nos locais apropriados. Você pode adicionar uma variável de membro do [editor de caixa de diálogo](../windows/dialog-editor.md) na [exibição recursos](../windows/resource-view-window.md), ou de [exibição de classe](http://msdn.microsoft.com/en-us/8d7430a9-3e33-454c-a9e1-a85e3d2db925).  
  
> [!NOTE]
>  Quando você está projetando e implementando uma caixa de diálogo, talvez seja mais eficiente usar a caixa de diálogo editor para adicionar os controles de caixa de diálogo e, em seguida, para implementar a variáveis de membro dos controles.  
  
### <a name="to-add-a-member-variable-for-a-dialog-control-in-resource-view-using-the-add-member-variable-wizard"></a>Para adicionar uma variável de membro para um controle de caixa de diálogo no modo de exibição de recursos usando o Assistente para adição de variável de membro  
  
1.  No modo de exibição de recursos, expanda o nó do projeto e o nó de caixa de diálogo para exibir a lista de caixas de diálogo do projeto.  
  
2.  Clique duas vezes a caixa de diálogo na qual você deseja adicionar a variável de membro para abri-lo no editor de caixa de diálogo.  
  
3.  Na caixa de diálogo exibida no editor de caixa de diálogo, clique o controle para o qual você deseja adicionar a variável de membro.  
  
4.  No menu de atalho, clique em **Adicionar variável** para exibir o [Adicionar Assistente de variável de membro](../ide/add-member-variable-wizard.md).  
  
    > [!NOTE]
    >  Um valor padrão já é fornecido no **ID de controle**.  
  
5.  Forneça as informações nas caixas apropriadas do assistente. Consulte [controles de caixa de diálogo e tipos de variáveis](../ide/dialog-box-controls-and-variable-types.md) para obter mais informações.  
  
6.  Clique em **concluir** para adicionar o código de implementação e a definição para o projeto e fechar o assistente.  
  
### <a name="to-add-a-member-variable-from-class-view-using-the-add-member-variable-wizard"></a>Para adicionar uma variável de membro de classe de exibição usando o Assistente para adição de variável de membro  
  
1.  Em [exibição de classe](http://msdn.microsoft.com/en-us/8d7430a9-3e33-454c-a9e1-a85e3d2db925), expanda o nó do projeto para exibir as classes no projeto.  
  
2.  Clique com botão direito a classe à qual você deseja adicionar uma variável.  
  
3.  No menu de atalho, clique em **adicionar**e, em seguida, clique em **Adicionar variável** para exibir o Assistente de variável de membro adicionar.  
  
4.  Forneça as informações nas caixas apropriadas do assistente. Consulte [Adicionar Assistente de variável de membro](../ide/add-member-variable-wizard.md) para obter detalhes.  
  
5.  Clique em **concluir** para adicionar o código de implementação e a definição para o projeto e fechar o assistente.  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando uma classe](../ide/adding-a-class-visual-cpp.md)   
 [Adicionar uma função de membro](../ide/adding-a-member-function-visual-cpp.md)   
 [Manipulador de mensagens do MFC](../mfc/reference/adding-an-mfc-message-handler.md)   
 [Navegando na estrutura de classe](../ide/navigating-the-class-structure-visual-cpp.md)