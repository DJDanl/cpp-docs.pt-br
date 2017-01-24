---
title: "Localizando uma cadeia de caracteres | Microsoft Docs"
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
  - "vc.editors.string"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "cadeias de caracteres [C++]"
  - "cadeias de caracteres [C++], procurando"
ms.assetid: c2497173-f356-4f77-97d6-f0ac41782510
caps.latest.revision: 12
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Localizando uma cadeia de caracteres
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode procurar por um ou mais seqüências de caracteres na tabela de cadeia de caracteres e usar  [expressões regulares](../Topic/Using%20Regular%20Expressions%20in%20Visual%20Studio.md) com o  **Find in Files** comando \(**Editar** menu\) para localizar todas as ocorrências de seqüências de caracteres que correspondem um padrão.  
  
### Para localizar uma seqüência de caracteres da tabela de cadeia de caracteres  
  
1.  Abra a tabela de cadeia de caracteres clicando duas vezes no ícone correspondente na  [Exibição de recurso](../windows/resource-view-window.md).  
  
    > [!NOTE]
    >  Se o seu projeto já não contém um arquivo. rc, consulte  [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  Sobre o  **Editar** menu, clique em  **Localizar e substituir**, em seguida, escolha  **Localizar**.  
  
3.  No  **Localizar** caixa, selecione uma seqüência de pesquisa anterior na lista suspensa ou digite o identificador de recurso ou de texto de legenda da seqüência de caracteres que deseja localizar.  
  
4.  Selecione qualquer uma da  **Localizar** opções.  
  
5.  Clique em  **Localizar próxima**.  
  
    > [!TIP]
    >  Para usar expressões regulares ao pesquisar arquivos, use o  **Find in Files** comando.  Digite uma expressão regular para corresponder a um padrão ou clique no botão à direita da  **Localizar** caixa para exibir uma lista de expressões regulares de pesquisa.  Quando você seleciona uma expressão dessa lista, ela é substituída como o texto de pesquisa no  **Localizar**  caixa.  Se você usar expressões regulares, certifique\-se a  **usar: expressões regulares** caixa de seleção está selecionada.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados \(aquelas que visam common language runtime\), consulte  [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) na  *.Guia. do desenvolvedor do NET Framework* Para informações sobre como adicionar manualmente os arquivos de recursos para projetos gerenciados, acesso a recursos, exibindo recursos estáticos e a atribuição de seqüências de caracteres de recursos a propriedades, consulte  [Walkthrough: Localizing Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 **Requisitos**  
  
 Win32  
  
## Consulte também  
 [Editor de Cadeia de Caracteres](../mfc/string-editor.md)   
 [Seqüências de caracteres](_win32_Strings)   
 [sobre seqüências de caracteres](_win32_About_Strings_cpp)