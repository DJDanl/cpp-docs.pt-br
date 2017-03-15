---
title: "Alterando um s&#237;mbolo ou um nome de s&#237;mbolo (ID) | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.editors.symbol.changing"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "nomes de símbolos"
  - "símbolos, nomes"
ms.assetid: 26541832-8dba-4177-b642-e08f94502ea7
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Alterando um s&#237;mbolo ou um nome de s&#237;mbolo (ID)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você cria um novo recurso ou objeto de recurso, o ambiente de desenvolvimento atribui a ele um nome de símbolo padrão, por exemplo, IDD\_DIALOG1.  Você pode usar o [janela propriedades](../Topic/Properties%20Window.md) para alterar o nome de símbolo padrão ou para alterar o nome de qualquer símbolo já está associado com um recurso.  
  
### Para alterar o nome do símbolo do recurso  
  
1.  Em [exibição recurso](../windows/resource-view-window.md), selecione o recurso.  
  
    > [!NOTE]
    >  Se seu projeto ainda não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  No **propriedades** janela, digite um novo nome de símbolo, ou selecione da lista de símbolos existentes no **ID** caixa.  
  
     Se você digitar um novo nome de símbolo, ele é automaticamente atribuído um valor.  
  
 Você pode usar o [caixa de diálogo símbolos de recurso](../windows/resource-symbols-dialog-box.md) para alterar os nomes de símbolos que não está atribuídos a um recurso.  Para obter mais informações, consulte [alterando símbolos não atribuídos](../Topic/Changing%20Unassigned%20Symbols.md).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [Recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos para propriedades, consulte [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 Requisitos  
  
 Win32  
  
## Consulte também  
 [Restrições de nome do símbolo](../windows/symbol-name-restrictions.md)   
 [IDs de símbolo predefinido](../windows/predefined-symbol-ids.md)