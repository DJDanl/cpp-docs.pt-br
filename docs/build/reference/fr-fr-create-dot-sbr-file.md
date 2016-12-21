---
title: "-Fr -FR, (criar. Arquivo SBR) | Microsoft Docs"
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
  - "VC.Project.VCCLWCECompilerTool.BrowseInformation"
  - "VC.Project.VCCLCompilerTool.BrowseInformation"
  - "/fr"
  - "VC.Project.VCCLCompilerTool.BrowseInformationFile"
  - "VC.Project.VCCLWCECompilerTool.BrowseInformationFile"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /FR (C++)"
  - "Opção de compilador -FR [C++]"
  - "Opção de compilador FR [C++]"
  - "informações de navegador simbólicas"
ms.assetid: 3fd8f88b-3924-4feb-9393-287036a28896
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /FR, /Fr (criar arquivo .Sbr)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cria arquivos. SBR.  
  
## Sintaxe  
  
```  
/FR[pathname[\filename]]  
/Fr[pathname[\filename]]  
```  
  
## Comentários  
 Durante o processo de compilação, a Microsoft procurar informações arquivo manutenção Utility \(BSCMAKE\) usa esses arquivos para criar um. Arquivo BSC, que é usado para exibir informações de procura.  
  
 **\/FR** cria um arquivo. SBR com informações simbólicas completas.  
  
 **\/Fr** cria um arquivo. SBR sem informações em variáveis locais.  
  
 Se você não especificar `filename`, o arquivo. SBR obtém o mesmo nome base do arquivo de origem.  
  
 **\/Fr** foi preterido; use **\/FR** em vez disso. Para obter mais informações, consulte preteridos e removidos opções do compilador no [Opções de compilador listadas por categoria](../../build/reference/compiler-options-listed-by-category.md).  
  
> [!NOTE]
>  Não altere a extensão. SBR. BSCMAKE requer os arquivos intermediários tenham essa extensão.  
  
### Para definir essa opção de compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  No painel de navegação, escolha o **C\/C\+\+**, **Procurar informações** página de propriedades.  
  
3.  Modificar o **Procurar informações de arquivo** ou **permitem procurar informações** propriedade.  
  
### Para definir essa opção de compilador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.BrowseInformation%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.BrowseInformationFile%2A>.  
  
## Consulte também  
 [Opções do arquivo de saída \(\/F\)](../../build/reference/output-file-f-options.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [Especificando o nome de caminho](../Topic/Specifying%20the%20Pathname.md)