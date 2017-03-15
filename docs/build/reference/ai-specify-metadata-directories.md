---
title: "/AI (especificar diret&#243;rios de metadados) | Microsoft Docs"
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
  - "VC.Project.VCCLCompilerTool.AdditionalUsingDirectories"
  - "VC.Project.VCNMakeTool.AssemblySearchPath"
  - "/AI"
  - "VC.Project.VCCLWCECompilerTool.AdditionalUsingDirectories"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /AI (C++)"
  - "Opção de compilador AI [C++]"
  - "Opção de compilador -AI [C++]"
ms.assetid: fb9c1846-504c-4a3b-bb39-c8696de32f6f
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /AI (especificar diret&#243;rios de metadados)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica um diretório em que o compilador pesquisará para resolver referências de arquivo passadas para diretiva `#using`.  
  
## Sintaxe  
  
```  
/AIdirectory  
```  
  
## Argumentos  
 `directory`  
 O diretório ou o caminho para o compilador pesquisar.  
  
## Comentários  
 Apenas um diretório pode ser passado para uma invocação de **\/AI**.  Especifique uma opção **\/AI** para cada caminho que você deseja que o compilador pesquise.  Por exemplo, para adicionar C:\\Project\\Meta e C:\\Common\\Meta ao caminho de pesquisa do compilador para diretivas `#using`, adicione `/AI"C:\Project\Meta" /AI"C:\Common\Meta"` à linha de comando do compilador ou adicione cada diretório à propriedade **Diretórios \#using adicionais** no Visual Studio.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  No painel de navegação, selecione **Propriedades de Configuração**, **C\/C\+\+**, **Geral**.  
  
3.  Modifique a propriedade **Diretórios \#using adicionais**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalUsingDirectories%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [Diretiva \#using](../../preprocessor/hash-using-directive-cpp.md)