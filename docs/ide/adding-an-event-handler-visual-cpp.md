---
title: "Adicionando um manipulador de eventos (Visual C++) | Microsoft Docs"
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
  - "vc.codewiz.eventhandler.overview"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "manipuladores de eventos, adicionando"
  - "MSBuild, propriedades"
  - "propriedades [Visual Studio], MSBuild"
ms.assetid: 050bebf0-a9e0-474b-905c-796fe5ac8fc3
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando um manipulador de eventos (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A partir do editor de recursos, você pode adicionar um novo manipulador de eventos ou editar um manipulador de eventos existente para um controle de caixa de diálogo usando o  [Assistente de manipulador de eventos](../ide/event-handler-wizard.md).  
  
 Você pode adicionar um evento para a classe que implementa a caixa de diálogo usando o  [janela Propriedades do](../Topic/Properties%20Window.md).  Se você quiser adicionar o evento a uma classe diferente, por exemplo, a classe da caixa de diálogo, use o Assistente de manipulador de eventos.  
  
### Para adicionar um manipulador de eventos a um controle de caixa de diálogo  
  
1.  Clique duas vezes no recurso de caixa de diálogo na  [Exibição de recurso](../windows/resource-view-window.md) para abrir o recurso de caixa de diálogo que contém o controle no  [editor de diálogo](../mfc/dialog-editor.md).  
  
2.  Clique com o botão direito no controle desejado manipular o evento de notificação.  
  
3.  No menu de atalho, clique em  **Adicionar o manipulador de eventos** para exibir o Assistente de manipulador de eventos.  
  
4.  Selecione o evento no  **tipo de mensagem** caixa para adicionar a classe selecionada no  **a lista de classe** caixa.  
  
5.  Aceite o nome padrão na  **nome de função do manipulador** caixa ou forneça o nome de sua escolha.  
  
6.  Clique em  **Adicionar e editar** para adicionar o manipulador de eventos para o projeto e abrir o editor de texto com a nova função para adicionar o código de manipulador de eventos apropriado.  
  
     Se o tipo de mensagem selecionada já tiver um manipulador de eventos para a classe selecionada,  **Adicionar e editar** não estiver disponível, e  **Editar código** está disponível.  Clique em  **Editar código** para abrir o editor de texto em que a função existente.  
  
 Como alternativa, você pode adicionar manipuladores de eventos a partir do  [janela Propriedades do](../Topic/Properties%20Window.md).  Consulte  [Adicionando manipuladores de eventos para controles de caixa de diálogo](../mfc/adding-event-handlers-for-dialog-box-controls.md) para obter mais informações.  
  
## Consulte também  
 [Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando uma classe](../Topic/Adding%20a%20Class%20\(Visual%20C++\).md)   
 [Adicionando uma variável de membro](../ide/adding-a-member-variable-visual-cpp.md)   
 [Adicionando uma função de membro](../ide/adding-a-member-function-visual-cpp.md)   
 [Manipulador de mensagens do MFC](../mfc/reference/adding-an-mfc-message-handler.md)   
 [Navegando na estrutura da classe](../ide/navigating-the-class-structure-visual-cpp.md)