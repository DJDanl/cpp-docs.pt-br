---
title: "/FU (nome for&#231;ado #usando arquivo) | Microsoft Docs"
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
  - "VC.Project.VCCLCompilerTool.ForcedUsingFiles"
  - "/FU"
  - "VC.Project.VCNMakeTool.ForcedUsingAssemblies"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /FU (C++)"
  - "Opção de compilador FU [C++]"
  - "Opção de compilador -FU [C++]"
ms.assetid: 698f8603-457f-435a-baff-5ac9243d6ca1
caps.latest.revision: 15
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /FU (nome for&#231;ado #usando arquivo)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma opção de compilador que você pode usar como uma alternativa para transmitir um nome de arquivo a [Diretiva \#using](../../preprocessor/hash-using-directive-cpp.md) no código\-fonte.  
  
## Sintaxe  
  
```  
/FU file  
```  
  
## Arguments  
 `file`  
 Especifica os metadados para referenciar o arquivo nesta compilação.  
  
## Comentários  
 A opção \/FU usa apenas o nome do arquivo.  Para especificar vários arquivos, use \/FU com cada um.  
  
 Se você estiver usando [!INCLUDE[cppcli](../../build/reference/includes/cppcli_md.md)] e está referenciando metadados para usar o recurso de [Assemblies de amigo](../../dotnet/friend-assemblies-cpp.md) , você não pode usar **\/FU**.  Você deve fazer referência aos metadados no código usando `#using`— junto com o atributo de `[as friend]` .  Os assemblies de amigo não têm suporte em [!INCLUDE[cppwrt](../../build/reference/includes/cppwrt_md.md)] \([!INCLUDE[cppwrt_short](../Token/cppwrt_short_md.md)]\).  
  
 Para obter informações sobre como criar um assembly ou em um módulo para Common Language Runtime \(CLR\), consulte [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md).  Para obter informações sobre como criar em [!INCLUDE[cppwrt_short](../Token/cppwrt_short_md.md)], consulte [Compilando aplicativos e bibliotecas](../Topic/Building%20apps%20and%20libraries%20\(C++-CX\).md).  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Selecione a pasta **C\/C\+\+**.  
  
3.  Selecione a página de propriedades **Avançadas**.  
  
4.  Modifique a propriedade de **Forçar \#using** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ForcedUsingFiles%2A>.  
  
## Consulte também  
 [Opções do arquivo de saída \(\/F\)](../../build/reference/output-file-f-options.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)