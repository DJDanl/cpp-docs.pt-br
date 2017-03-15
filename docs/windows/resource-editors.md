---
title: "Editores de recursos | Microsoft Docs"
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
  - "vs.editors.resource"
  - "vc.resvw.resource.editors"
  - "vs.resvw.resource.editors"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "editores [C++], recurso"
  - "editores [C++]"
  - "editores de recursos"
  - "Janelas [C++], edição de recursos do aplicativo"
ms.assetid: e20a29ec-d6fb-4ead-98f3-431a0e23aaaf
caps.latest.revision: 16
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Editores de recursos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um editor de recursos é um ambiente especializado para criar ou modificar recursos que estão incluídos em um projeto do Visual Studio. Os editores de recursos do Visual Studio compartilham técnicas e interfaces para ajudá\-lo a criar e modificar recursos do aplicativo rapidamente e facilmente. Editores de recursos permitem que você [Exibir e editar os recursos no editor apropriado](../mfc/viewing-and-editing-resources-in-a-resource-editor.md) e [Visualizar recursos](../mfc/previewing-resources.md).  
  
 O editor apropriado será aberto automaticamente quando você cria ou abre um recurso.  
  
 **Observação** porque os projetos gerenciados não usar arquivos de script de recurso, você deve abrir seus recursos de **Solution Explorer**. Você pode usar o [editor de imagem](../mfc/image-editor-for-icons.md) e [editor binário](../mfc/binary-editor.md) para trabalhar com arquivos de recursos em projetos gerenciados. Todos os recursos gerenciados que deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não dão suporte a edição de recursos inseridos.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
|Use o...|Para editar...|  
|--------------|--------------------|  
|[Editor de aceleradores](../Topic/Accelerator%20Editor.md)|Tabelas de teclas aceleradoras em projetos do Visual C\+\+.|  
|[Editor binário](../mfc/binary-editor.md)|Informações de dados binários e recursos personalizados em projetos do Visual C\+\+, Visual Basic ou Visual c\#.|  
|[Editor de Caixa de Diálogo](../mfc/dialog-editor.md)|Caixas de diálogo em projetos do Visual C\+\+.|  
|[HTML Designer](../Topic/HTML%20Designer.md)|Páginas HTML no modo Design e modo de exibição HTML. Advertência: Você não pode fazer alterações em páginas HTML que estão em DLLs ou EXEs porque as alterações não são importadas novamente para o arquivo EXE ou DLL.|  
|[Editor de imagens](../mfc/image-editor-for-icons.md)|Bitmaps, ícones, cursores e outros arquivos de imagem em projetos do Visual C\+\+, Visual Basic ou Visual c\#.|  
|[Editor de menu](../Topic/Menu%20Editor.md)|Recursos do menu em projetos do Visual C\+\+.|  
|[Editor de faixa de opções](../mfc/ribbon-designer-mfc.md)|Recursos da faixa de opções em projetos MFC.|  
|[Editor de Cadeia de Caracteres](../mfc/string-editor.md)|Cadeia de caracteres tabelas em projetos do Visual C\+\+.|  
|[Editor de Barra de Ferramentas](../mfc/toolbar-editor.md)|Recursos da barra de ferramentas em projetos do Visual C\+\+. O editor de barra de ferramentas é parte do editor de imagem.|  
|[Editor de informações da versão](../mfc/version-information-editor.md)|Informações de versão em projetos do Visual C\+\+.|  
  
## Requisitos  
 Nenhum  
  
## Consulte também  
 [Trabalhando com arquivos de recurso](../mfc/working-with-resource-files.md)   
 [Arquivos de recursos](../mfc/resource-files-visual-studio.md)   
 [Símbolos: Identificadores de recursos](../mfc/symbols-resource-identifiers.md)   
 [Menus e outros recursos](https://msdn.microsoft.com/library/windows/desktop/ms632583.aspx)