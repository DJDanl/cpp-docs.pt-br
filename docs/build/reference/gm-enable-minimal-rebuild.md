---
title: "/Gm (habilitar recompila&#231;&#227;o manual) | Microsoft Docs"
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
  - "VC.Project.VCCLCompilerTool.MinimalRebuild"
  - "/Gm"
  - "/FD"
  - "VC.Project.VCCLWCECompilerTool.MinimalRebuild"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /Gm (C++)"
  - "Opção de compilador habilitar recompilação mínima [C++]"
  - "Opção de compilador Gm [C++]"
  - "Opção de compilador -Gm [C++]"
  - "recompilação mínima"
ms.assetid: d8869ce0-d2ea-40eb-8dae-6d2cdb61dd59
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Gm (habilitar recompila&#231;&#227;o manual)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Habilita recompilação mínima, que determina se os arquivos de origem C\+\+ que incluem definições de classe C\+\+ alteradas \(armazenadas nos arquivos de cabeçalho \(.h\)\) precisam ser recompilados.  
  
## Sintaxe  
  
```  
/Gm  
```  
  
## Comentários  
 O compilador armazena as informações de dependência entre arquivos de origem e definições de classe no arquivo .idb do projeto durante a primeira compilação.  \(Informações sobre dependência dizem que arquivo de origem depende da definição de classe e em qual arquivo .h a definição está localizada.\) Compilações subsequentes usam as informações armazenadas no arquivo .idb para determinar se um arquivo de origem precisa ser compilado, mesmo que inclua um arquivo .h modificado.  
  
> [!NOTE]
>  A recompilação mínima conta com definições de classe que não mudem entre os arquivos incluídos.  As definições de classe devem ser globais para um projeto \(deve haver apenas uma definição de uma determinada classe\), pois as informações de dependência no arquivo .idb são criadas para todo o projeto.  Se você tiver mais de uma definição para uma classe no seu projeto, desabilite a recompilação mínima.  
  
 Como o vinculador incremental não tem suporte para metadados do Windows incluídos em arquivos .obj usando a opção [\/ZW \(Compilação de Tempo de Execução do Windows\)](../../build/reference/zw-windows-runtime-compilation.md), a opção **\/Gm** é incompatível com **\/ZW**.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedade de **Geração de Código**.  
  
4.  Modifique a propriedade **Habilitar Recompilação Mínima**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.MinimalRebuild%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)