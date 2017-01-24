---
title: "Como procurar s&#237;mbolos em recursos | Microsoft Docs"
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
  - "recursos [Visual Studio], procurando símbolos"
  - "símbolos, localizando"
ms.assetid: 6efef8e8-d0d4-4c49-b895-314974e7791a
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como procurar s&#237;mbolos em recursos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

### Para localizar símbolos em recursos  
  
1.  Do **Editar** menu, escolha **Find Symbol**.  
  
2.  No [caixa de diálogo Find Symbol](http://msdn.microsoft.com/pt-br/63e93d9c-784f-418d-a76a-723da5ff5d96), no **localizar** caixa, selecione uma cadeia de caracteres de pesquisa anterior na lista suspensa ou digite a tecla de aceleração que você deseja localizar \(por exemplo, ID\_ACCEL1\).  
  
    > [!TIP]
    >  Usar [expressões regulares](../Topic/Using%20Regular%20Expressions%20in%20Visual%20Studio.md) de pesquisa, você deve usar o [comando Localizar nos arquivos](../Topic/Find%20Command.md) do **Editar** menu em vez do **Find Symbol** comando.  Para habilitar a expressões regulares, você deve ter o **uso: expressões regulares** na caixa de diálogo de [caixa de diálogo Localizar](http://msdn.microsoft.com/pt-br/dad03582-4931-4893-83ba-84b37f5b1600).  Em seguida, você pode clicar no botão de seta para a direita à direita do **localizar** caixa para exibir uma lista de expressões regulares de pesquisa.  Quando você seleciona uma expressão nessa lista, ele é substituído como o texto de pesquisa no **localizar** caixa.  
  
3.  Selecione qualquer uma do **localizar** opções.  
  
4.  Clique em **Localizar próximo**.  
  
    > [!NOTE]
    >  Você não pode procurar símbolos em seqüência, acelerador ou recursos binários.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [Recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 **Requisitos**  
  
 Win32  
  
## Consulte também  
 [Símbolos: Identificadores de recursos](../mfc/symbols-resource-identifiers.md)   
 [Arquivos de recursos](../mfc/resource-files-visual-studio.md)   
 [Editores de recursos](../mfc/resource-editors.md)