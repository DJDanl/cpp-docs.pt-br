---
title: "Alterando o valor num&#233;rico de um s&#237;mbolo | Microsoft Docs"
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
  - "vc.editors.symbol.changing.value"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "valores numéricos"
  - "valores numéricos, alterando símbolos"
  - "símbolos, valores numéricos"
ms.assetid: 468e903b-9c07-4251-ae09-3b6cb754cc2b
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Alterando o valor num&#233;rico de um s&#237;mbolo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Símbolos associados a um único recurso, você pode usar o [janela propriedades](../Topic/Properties%20Window.md) para alterar o valor do símbolo.  Você pode usar o [caixa de diálogo símbolos de recurso](../windows/resource-symbols-dialog-box.md) para alterar o valor de símbolos que não está atribuído a um recurso.  Para obter mais informações, consulte [alterando símbolos não atribuídos](../Topic/Changing%20Unassigned%20Symbols.md).  
  
### Para alterar um valor de símbolo atribuído a um único recurso ou objeto  
  
1.  Em [exibição recurso](../windows/resource-view-window.md), selecione o recurso.  
  
    > [!NOTE]
    >  Se seu projeto ainda não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  No **propriedades** janela, digite o nome do símbolo seguido por um sinal de igual e um número inteiro no **ID** caixa, por exemplo:  
  
    ```  
    IDC_EDITNAME=5100  
    ```  
  
 O novo valor é armazenado no arquivo de cabeçalho de símbolo na próxima vez que você salvar o projeto.  Somente o nome de símbolo permanece visível na caixa ID. o sinal de igual e o valor não são exibidos depois que eles sejam validados.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [Recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 Requisitos  
  
 Win32  
  
## Consulte também  
 [Restrições de valor do símbolo](../Topic/Symbol%20Value%20Restrictions.md)   
 [IDs de símbolo predefinido](../windows/predefined-symbol-ids.md)