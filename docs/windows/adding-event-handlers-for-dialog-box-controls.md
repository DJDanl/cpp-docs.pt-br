---
title: "Adicionando manipuladores de eventos para controles da caixa de di&#225;logo | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
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
  - "controles [C++], manipuladores de eventos"
  - "controles de caixas de diálogo, eventos"
  - "Editor de caixa de diálogo, adicionando manipuladores de evento a controles"
  - "manipuladores de eventos, para controles de caixas de diálogo"
ms.assetid: f9c70f24-ea6f-44df-82eb-78a2deaee769
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando manipuladores de eventos para controles da caixa de di&#225;logo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para caixas de diálogo do projeto que já estão associadas uma classe, você pode aproveitar alguns atalhos quando você cria manipuladores de eventos.  Você pode criar rapidamente um manipulador para o evento de notificação de controle padrão ou para qualquer mensagem aplicável do Windows.  
  
#### Para criar um manipulador para o evento de notificação de controle padrão  
  
1.  Clique duas vezes no controle.  O editor de texto abre.  
  
2.  Adicione o código do manipulador de notificações de controle no editor de texto.  
  
#### Para criar um manipulador para qualquer mensagem aplicável do Windows  
  
1.  Clique no controle para o qual você deseja manipular o evento de notificação.  
  
2.  No  [janela Propriedades do](../Topic/Properties%20Window.md), clique no  **ControlEvents** botão para exibir a lista de eventos comuns do Windows associada ao controle.  Por exemplo, o padrão  **OK** na barra de  **sobre** caixa de diálogo lista os seguintes eventos de notificação:  
  
     **BN\_CLICKED**  
  
     **BN\_DOUBLECLICKED**  
  
     **BN\_KILLFOCUS**  
  
     **BN\_SETFOCUS**  
  
    > [!NOTE]
    >  Como alternativa, marque a caixa de diálogo e clique no  **ControlEvents** botão para exibir a lista de eventos comuns do Windows para todos os controles na caixa de diálogo.  
  
3.  No  **Propriedades**  janela, clique na coluna direita próximo ao manipular o evento e selecione o nome do evento de notificação sugerido \(por exemplo,  **OnBnClickedOK** identificadores  **BN\_CLICKED**\).  
  
    > [!NOTE]
    >  Como alternativa, você pode fornecer um nome de manipulador de eventos de sua escolha, em vez de selecionar o nome do manipulador de eventos padrão.  
  
     Uma vez que você selecionou o evento, o Visual Studio abre o Editor de texto e exibe o código do manipulador de eventos.  Por exemplo, o código a seguir é adicionado para o padrão  **OnBnClickedOK**:  
  
    ```  
    void CAboutDlg::OnBnClickedOk(void)  
    {  
       // TODO: Add your control notification handler code here  
    }  
    ```  
  
 Se você deseja adicionar o manipulador de eventos a uma classe diferente de uma implementação de caixa de diálogo, use o  [o Assistente de manipulador de eventos](../ide/event-handler-wizard.md).  Para obter mais informações, consulte  [Adicionar um manipulador de eventos](../ide/adding-an-event-handler-visual-cpp.md).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
### Requisitos  
 Win32  
  
## Consulte também  
 [Eventos de controle padrão](../Topic/Default%20Control%20Events.md)   
 [Definindo variáveis de membro para controles da caixa de diálogo](../mfc/defining-member-variables-for-dialog-controls.md)   
 [Controles da caixa de diálogo e tipos de variável](../Topic/Dialog%20Box%20Controls%20and%20Variable%20Types.md)   
 [Adicionando uma classe](../Topic/Adding%20a%20Class%20\(Visual%20C++\).md)   
 [Adicionando uma função de membro](../ide/adding-a-member-function-visual-cpp.md)   
 [Adicionando uma variável de membro](../ide/adding-a-member-variable-visual-cpp.md)   
 [Substituindo uma função virtual](../Topic/Overriding%20a%20Virtual%20Function%20\(Visual%20C++\).md)   
 [Manipulador de mensagens do MFC](../mfc/reference/adding-an-mfc-message-handler.md)