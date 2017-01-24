---
title: "/X (ignorar caminhos de inclus&#227;o padr&#227;o) | Microsoft Docs"
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
  - "/x"
  - "VC.Project.VCCLCompilerTool.IgnoreStandardIncludePath"
  - "VC.Project.VCCLWCECompilerTool.IgnoreStandardIncludePath"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /X (C++)"
  - "Opção de compilador Ignorar Caminhos de Inclusão Padrão"
  - "incluir diretórios, ignorar padrão"
  - "incluir arquivos, ignorar caminho padrão"
  - "Opção de compilador X"
  - "Opção de compilador -X [C++]"
ms.assetid: 16bdf2cc-c8dc-46e4-bdcc-f3caeba5e1ef
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /X (ignorar caminhos de inclus&#227;o padr&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Impede que o compilador pesquise por para incluir arquivos nos diretórios especificados na cláusula INCLUDE PATH e variáveis de ambiente.  
  
## Sintaxe  
  
```  
/X  
```  
  
## Comentários  
 Você pode usar essa opção com a opção de [\/I \(diretórios de inclusão adicionais\)](../../build/reference/i-additional-include-directories.md) \(**\/I**`directory`\).  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Pré\-Processador** .  
  
4.  Modifique a propriedade de **Ignorar Caminho de Inclusão Padrão** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.IgnoreStandardIncludePath%2A>.  
  
## Exemplo  
 No seguinte comando, `/X` informa o compilador para ignorar os locais especificados por PATH FOR INCLUDE e variáveis de ambiente, e `/I` especifica o diretório no qual navegar inclua arquivos:  
  
```  
CL /X /I \ALT\INCLUDE MAIN.C  
```  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)