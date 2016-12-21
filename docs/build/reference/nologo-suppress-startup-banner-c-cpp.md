---
title: "/nologo (suprimir faixa de inicializa&#231;&#227;o) (C++) | Microsoft Docs"
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
  - "VC.Project.VCCLWCECompilerTool.SuppressStartupBanner"
  - "VC.Project.VCCLCompilerTool.SuppressStartupBanner"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /nologo (C++)"
  - "faixas, suprimindo a inicialização"
  - "Opção de compilador nologo [C++]"
  - "Opção de compilador -nologo [C++]"
ms.assetid: 75930d8b-b11c-4db8-99e5-b52f97da0693
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /nologo (suprimir faixa de inicializa&#231;&#227;o) (C++)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Suprime a exibição da faixa de direitos autorais quando o compilador inicia e exibição de mensagens informativas durante a compilação.  
  
## Sintaxe  
  
```  
/nologo  
```  
  
## Comentários  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades **Geral**.  
  
4.  Modifique a propriedade de **Suppress Startup Banner** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.SuppressStartupBanner%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)