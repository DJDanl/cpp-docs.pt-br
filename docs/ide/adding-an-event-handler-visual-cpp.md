---
title: Adicionando um manipulador de eventos (Visual C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.codewiz.eventhandler.overview
dev_langs: C++
helpviewer_keywords:
- event handlers, adding
- properties [Visual Studio], MSBuild
- MSBuild, properties
ms.assetid: 050bebf0-a9e0-474b-905c-796fe5ac8fc3
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f9a5380bf335a13bbf7b2f54840c9d1160187167
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="adding-an-event-handler-visual-c"></a>Adicionando um manipulador de eventos (Visual C++)
Do editor de recursos, você pode adicionar um novo manipulador de eventos ou editar um manipulador de eventos existente para um controle de caixa de diálogo usando o [Assistente de manipulador de eventos](../ide/event-handler-wizard.md).  
  
 Você pode adicionar um evento para a classe que implementa a caixa de diálogo usando o [janela propriedades](/visualstudio/ide/reference/properties-window). Se você deseja adicionar o evento a uma classe que não sejam a classe de caixa de diálogo, use o Assistente de manipulador de eventos.  
  
### <a name="to-add-an-event-handler-to-a-dialog-box-control"></a>Para adicionar um manipulador de eventos para um controle de caixa de diálogo  
  
1.  Clique duas vezes o recurso de caixa de diálogo no [exibição recursos](../windows/resource-view-window.md) para abrir o recurso de caixa de diálogo que contém o controle no [editor de caixa de diálogo](../windows/dialog-editor.md).  
  
2.  Clique com botão direito do controle para o qual você deseja manipular o evento de notificação.  
  
3.  No menu de atalho, clique em **Adicionar manipulador de eventos** para exibir o Assistente de manipulador de eventos.  
  
4.  Selecione o evento no **tipo de mensagem** caixa para adicionar à classe selecionada no **lista de classes** caixa.  
  
5.  Aceite o nome padrão no **nome do manipulador de função** caixa ou forneça o nome de sua escolha.  
  
6.  Clique em **adicionar e editar** para adicionar o manipulador de eventos para o projeto e abra o editor de texto na nova função para adicionar o código de manipulador de eventos apropriado.  
  
     Se o tipo de mensagem selecionado já tem um manipulador de eventos para a classe selecionada, **adicionar e editar** não estiver disponível, e **editar código** está disponível. Clique em **editar código** para abrir o editor de texto em que a função existente.  
  
 Como alternativa, você pode adicionar manipuladores de evento do [janela propriedades](/visualstudio/ide/reference/properties-window). Consulte [adicionar manipuladores de eventos para controles de caixa de diálogo](../windows/adding-event-handlers-for-dialog-box-controls.md) para obter mais informações.  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando uma classe](../ide/adding-a-class-visual-cpp.md)   
 [Adicionar uma variável de membro](../ide/adding-a-member-variable-visual-cpp.md)   
 [Adicionar uma função de membro](../ide/adding-a-member-function-visual-cpp.md)   
 [Manipulador de mensagens do MFC](../mfc/reference/adding-an-mfc-message-handler.md)   
 [Navegando na estrutura de classe](../ide/navigating-the-class-structure-visual-cpp.md)