---
title: "/C (preservar coment&#225;rios durante o pr&#233;-processamento) | Microsoft Docs"
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
  - "VC.Project.VCCLCompilerTool.KeepComments"
  - "/c"
  - "VC.Project.VCCLWCECompilerTool.KeepComments"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /c (C++)"
  - "Opção de compilador c [C++]"
  - "Opção de compilador -c [C++]"
  - "comentários, sem remoção durante o pré-processamento"
  - "preservar comentários durante o pré-processamento"
ms.assetid: 944567ca-16bc-4728-befe-d414a7787f26
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /C (preservar coment&#225;rios durante o pr&#233;-processamento)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Preserva comentários durante o pré\-processamento.  
  
## Sintaxe  
  
```  
/C  
```  
  
## Comentários  
 Essa opção requer **\/E**do compilador, **\/P**, ou a opção de **\/EP** .  
  
 O exemplo de código a seguir exibirá o comentário do código\-fonte.  
  
```  
// C_compiler_option.cpp  
// compile with: /E /C /c  
int i;   // a variable  
```  
  
 Este exemplo gerará a seguinte saída.  
  
```  
#line 1 "C_compiler_option.cpp"  
int i;   // a variable  
```  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Pré\-Processador** .  
  
4.  Modifique a propriedade de **Mantenha Comentários** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.KeepComments%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [\/E \(pré\-processar em stdout\)](../../build/reference/e-preprocess-to-stdout.md)   
 [\/P \(pré\-processar em um arquivo\)](../../build/reference/p-preprocess-to-a-file.md)   
 [\/EP \(pré\-processar para stdout sem diretivas \#line\)](../../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md)