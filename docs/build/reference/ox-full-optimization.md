---
title: "/Ox (otimiza&#231;&#227;o total) | Microsoft Docs"
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
  - "VC.Project.VCCLCompilerTool.ToolOptimization"
  - "/ox"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /Ox (C++)"
  - "código rápido"
  - "otimização total"
  - "Opção de compilador Ox [C++]"
  - "Opção de compilador -Ox [C++]"
ms.assetid: 3ad7c30b-c615-428c-b1d0-2e024f81c760
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Ox (otimiza&#231;&#227;o total)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A opção do compilador de **\/Ox** gerencia o código a velocidade de execução de favorece sobre o tamanho menor.  
  
## Sintaxe  
  
```  
/Ox  
```  
  
## Comentários  
 Especificar a opção de compilador de **\/Ox** é o mesmo que o uso das seguintes opções:  
  
-   [\/Ob \(expansão de função embutida\)](../../build/reference/ob-inline-function-expansion.md), onde o parâmetro de opção é 2 \(**\/Ob2**\)  
  
-   [\/Og \(otimizações globais\)](../../build/reference/og-global-optimizations.md)  
  
-   [\/Oi \(gerar funções intrínsecas\)](../Topic/-Oi%20\(Generate%20Intrinsic%20Functions\).md)  
  
-   [\/Ot \(Código rápido em detrimento\)](../../build/reference/os-ot-favor-small-code-favor-fast-code.md)  
  
-   [\/Oy \(omissão do ponteiro de quadro\)](../../build/reference/oy-frame-pointer-omission.md)  
  
 **\/Ox** é mutuamente exclusiva de:  
  
-   [\/O1 \(Minimize o tamanho\)](../../build/reference/o1-o2-minimize-size-maximize-speed.md)  
  
-   [\/O2 \(Maximizar a velocidade\)](../../build/reference/o1-o2-minimize-size-maximize-speed.md)  
  
-   [\/Od \(desabilitar\)](../../build/reference/od-disable-debug.md)  
  
 A opção do compilador de **\/Ox** também permite que a otimização nomeada do valor de retorno, o que elimina o construtor de cópia e o destruidor de um valor de retorno baseado pilha.  Para obter mais informações, consulte [\/O1, \/O2 \(minimizar tamanho, maximizar velocidade\)](../../build/reference/o1-o2-minimize-size-maximize-speed.md).  
  
 Você pode cancelar para substituir a opção do compilador de **\/Ox** se você especificar **\/Oxs**, que combina a opção do compilador de **\/Ox** com [\/Os \(Código em detrimento pequeno\)](../../build/reference/os-ot-favor-small-code-favor-fast-code.md).  As opções combinadas favorecem o tamanho de código menor.  
  
 Geralmente, especifique [\/O2 \(Maximizar a velocidade\)](../../build/reference/o1-o2-minimize-size-maximize-speed.md) em vez de **\/Ox**, e [\/O1 \(Minimize o tamanho\)](../../build/reference/o1-o2-minimize-size-maximize-speed.md) em vez de **\/Oxs**.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Otimização** .  
  
4.  Modifique a propriedade de **Otimização** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.Optimization%2A>.  
  
## Consulte também  
 [\/O opções \(otimizar código\)](../../build/reference/o-options-optimize-code.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)