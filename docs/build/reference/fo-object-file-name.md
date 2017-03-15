---
title: "/Fo (Nome do arquivo de objeto) | Microsoft Docs"
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
  - "/Fo"
  - "VC.Project.VCCLCompilerTool.ObjectFile"
  - "VC.Project.VCCLWCECompilerTool.ObjectFile"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /Fo (C++)"
  - "opção do compilador Fo [C++]"
  - "opção do compilador -Fo [C++]"
  - "arquivos de objeto, nomenclatura"
ms.assetid: 0e6d593e-4e7f-4990-9e6e-92e1dcbcf6e6
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Fo (Nome do arquivo de objeto)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica um nome de arquivo ou um diretório do objeto \(.obj\) a ser usada em vez da opção.  
  
## Sintaxe  
  
```  
/Fopathname  
```  
  
## Comentários  
 Se você não usar essa opção, o arquivo de objeto usa o nome de arquivo de origem e a extensão de .obj.  Você pode usar qualquer nome e extensão que desejar, mas a convenção recomendada é usar .obj.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **ARQUIVOS DE SAÍDA** .  
  
4.  Modifique a propriedade de **Nome de Arquivo Objeto** .  No ambiente de desenvolvimento, o arquivo de objeto deve ter uma extensão de .obj.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ObjectFile%2A>.  
  
## Exemplo  
 A linha de comando a seguir cria um arquivo de THIS.obj em um objeto denominado, existente do diretório \\ OBJECT, na unidade B.  
  
```  
CL /FoB:\OBJECT\ THIS.C  
```  
  
## Consulte também  
 [Opções do arquivo de saída \(\/F\)](../../build/reference/output-file-f-options.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [Especificando o nome de caminho](../Topic/Specifying%20the%20Pathname.md)