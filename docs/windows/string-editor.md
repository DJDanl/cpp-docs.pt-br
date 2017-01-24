---
title: "Editor de Cadeia de Caracteres | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.editors.string.F1"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Editor de Cadeias de Caracteres"
  - "tabelas de cadeias de caracteres"
  - "tabelas de cadeia de caracteres, o editor de cadeia de caracteres"
  - "edição de cadeia de caracteres"
  - "editando tabelas de cadeia de caracteres de cadeia de caracteres"
  - "editores de recursos do editor de cadeia de caracteres"
  - "cadeias de caracteres [C++], edição"
ms.assetid: f71ab8de-3068-4e29-8e28-5a33d18dd416
caps.latest.revision: 15
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Editor de Cadeia de Caracteres
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma tabela de cadeia de caracteres é um recurso do Windows que contém uma lista de IDs, valores e legendas para todas as cadeias de caracteres de seu aplicativo. Por exemplo, os prompts de barra de status estão localizados na tabela de cadeia de caracteres.  
  
 Ao desenvolver um aplicativo, você pode ter várias tabelas de cadeia de caracteres — um para cada linguagem ou a condição. No entanto, um módulo executável tem apenas uma tabela de cadeia de caracteres. Um aplicativo em execução pode fazer referência a várias tabelas de cadeia de caracteres se você colocar as tabelas em DLLs diferentes.  
  
 Tabelas de cadeia de caracteres mais fácil localizar seu aplicativo em diferentes idiomas. Se todas as cadeias de caracteres estão em uma tabela de cadeia de caracteres, você pode localizar o aplicativo, convertendo as cadeias de caracteres \(e outros recursos\) sem alterar o código\-fonte. Isso é geralmente mais desejável do que manualmente, localizando e substituindo várias cadeias de caracteres em arquivos de origem.  
  
 Usando o editor de cadeia de caracteres, você pode:  
  
-   [Pesquisar cadeias de caracteres de um ou mais](../mfc/finding-a-string.md).  
  
-   Rapidamente [Inserir novas entradas](../mfc/adding-or-deleting-a-string.md) na tabela de cadeia de caracteres.  
  
-   [Mover uma cadeia de caracteres de um arquivo de recurso para outro](../mfc/moving-a-string-from-one-resource-file-to-another.md)  
  
-   [Usar edição in\-loco para as propriedades de identificação, o valor e a legenda](../mfc/changing-the-properties-of-a-string.md) e exibir as alterações imediatamente.  
  
-   [Alterar a propriedade de legenda de várias cadeias de caracteres](../mfc/changing-the-caption-property-of-multiple-strings.md)  
  
-   [Adicionar formatação ou caracteres especiais em uma cadeia de caracteres](../mfc/adding-formatting-or-special-characters-to-a-string.md)  
  
    > [!NOTE]
    >  Windows não permite a criação de tabelas de cadeia de caracteres vazia. Se você criar uma tabela de cadeia de caracteres sem entradas, ele é excluído automaticamente quando você salvar o arquivo de recurso.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados \(aquelas que se destinam a common language runtime\), consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
## Requisitos  
 Win32  
  
## Consulte também  
 [Editores de recursos](../mfc/resource-editors.md)   
 [Cadeias de caracteres](http://msdn.microsoft.com/library/windows/desktop/ms646979.aspx)   
 [Sobre cadeias de caracteres](http://msdn.microsoft.com/library/windows/desktop/ms647465.aspx)