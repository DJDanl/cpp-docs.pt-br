---
title: "Definindo vari&#225;veis de membro para controles da caixa de di&#225;logo | Microsoft Docs"
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
  - "C++"
helpviewer_keywords: 
  - "controles [C++], variáveis de membro"
  - "Editor de caixa de diálogo, definindo variáveis de membro para controles"
  - "variáveis de membro, definindo para controles"
  - "variáveis, variáveis de membro de controle de caixa de diálogo"
ms.assetid: 84347c63-c33c-4b04-91f5-6d008c45ba58
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Definindo vari&#225;veis de membro para controles da caixa de di&#225;logo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para definir uma variável de membro de qualquer controle de caixa de diálogo exceto botões, você pode usar o método a seguir.  
  
> [!NOTE]
>  Este artigo se aplica somente a controles de caixa de diálogo dentro de um projeto MFC.  Projetos ATL devem usar o **novas mensagens do Windows e manipuladores de eventos** caixa de diálogo.  
  
### Para definir uma variável de membro para um controle de caixa de diálogo \(não\-botão\)  
  
1.  No [editor de diálogo](../mfc/dialog-editor.md), selecione um controle.  
  
2.  Ao pressionar o **CTRL** chave, clique duas vezes no controle de caixa de diálogo.  
  
     O [Assistente Adicionar variável membro](../ide/add-member-variable-wizard.md) é exibida.  
  
3.  Digite as informações apropriadas de **Adicionar variável membro** assistente.  Para obter mais informações, consulte [troca de dados de caixa de diálogo](../mfc/dialog-data-exchange.md).  
  
4.  Clique em **OK** para retornar ao editor de caixa de diálogo.  
  
    > [!TIP]
    >  Para saltar de qualquer controle de caixa de diálogo para seu manipulador existente, clique duas vezes no controle.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [Recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos para propriedades, consulte [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 Você também pode usar o **variáveis de membro** guia **MFC Class Wizard** para adicionar novas variáveis de membro de uma classe especificada e exibir as que já foi definido.  
  
 Requisitos  
  
 MFC  
  
## Consulte também  
 [Mapeando mensagens para funções](../Topic/Mapping%20Messages%20to%20Functions.md)   
 [Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Assistente de classe MFC](../mfc/reference/mfc-class-wizard.md)   
 [Adicionando uma classe](../Topic/Adding%20a%20Class%20\(Visual%20C++\).md)   
 [Adicionando uma função de membro](../ide/adding-a-member-function-visual-cpp.md)   
 [Adicionando uma variável de membro](../ide/adding-a-member-variable-visual-cpp.md)   
 [Substituindo uma função virtual](../Topic/Overriding%20a%20Virtual%20Function%20\(Visual%20C++\).md)   
 [Manipulador de mensagens do MFC](../mfc/reference/adding-an-mfc-message-handler.md)