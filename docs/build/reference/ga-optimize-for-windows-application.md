---
title: "/GA (otimizar para aplicativo do Windows) | Microsoft Docs"
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
  - "VC.Project.VCCLCompilerTool.OptimizeForWindowsApplication"
  - "/ga"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /GA (C++)"
  - "Opção de compilador GA [C++]"
  - "Opção de compilador -GA [C++]"
  - "opções de compilador Otimizar para Windows"
ms.assetid: be97323e-15a0-4836-862c-95980b51926a
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /GA (otimizar para aplicativo do Windows)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Resultados no código mais eficiente para um arquivo .exe para acessar variáveis \(TLS\) de armazenamento de thread local.  
  
## Sintaxe  
  
```  
/GA  
```  
  
## Comentários  
 **\/GA** apressa o acesso a dados declarado com [\_\_declspec \(thread\)](../../cpp/declspec.md) em um programa baseado no Windows.  Quando esta opção for definida, a macro de [\_\_tls\_index](http://msdn.microsoft.com/library/windows/desktop/ms686749) será presumido como 0.  
  
 Usar **\/GA** para uma DLL pode resultar na geração de código incorreto.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção de compilador na caixa **Opções Adicionais**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)