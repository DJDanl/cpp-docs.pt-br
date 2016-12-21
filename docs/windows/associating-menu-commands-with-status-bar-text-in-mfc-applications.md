---
title: "Associando comandos de menu ao texto da barra de status em aplicativos MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
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
  - "barras de status, associando itens de menu"
  - "menus, texto da barra de status"
ms.assetid: 757c0e02-bc97-493f-bccd-6cc6887ebc64
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Associando comandos de menu ao texto da barra de status em aplicativos MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O aplicativo pode exibir texto descritivo para cada um dos comandos de menu, que um usuário pode selecionar. Você pode fazer isso atribuindo uma cadeia de caracteres de texto para cada comando de menu usando o **Prompt** propriedade na janela Propriedades. Se você tiver uma cadeia de caracteres no [tabela de cadeia de caracteres](../mfc/string-editor.md) cuja ID é o mesmo que o comando, um aplicativo MFC automaticamente exibirá esse recurso de cadeia de caracteres na barra de status do aplicativo em execução quando o usuário focalizar um item de menu.  
  
### Para associar um comando de menu com um cadeia de caracteres de texto da barra de status  
  
1.  No **Menu** editor, selecione o comando de menu.  
  
2.  No [janela propriedades](../Topic/Properties%20Window.md), digite o texto da barra de status associado no **Prompt** caixa.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 **Requisitos**  
  
 MFC  
  
## Consulte também  
 [Cadeias de caracteres](../atl-mfc-shared/strings-atl-mfc.md)   
 [Adicionando comandos a um menu](../Topic/Adding%20Commands%20to%20a%20Menu.md)   
 [Editor de menu](../Topic/Menu%20Editor.md)