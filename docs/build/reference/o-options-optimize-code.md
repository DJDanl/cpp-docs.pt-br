---
title: "/O op&#231;&#245;es (otimizar c&#243;digo) | Microsoft Docs"
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
  - "VC.Project.VCCLCompilerTool.Optimization"
  - "/o"
  - "VC.Project.VCCLWCECompilerTool.Optimization"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Compilador cl.exe, desempenho"
  - "desempenho, Compilador cle.exe"
ms.assetid: 77997af9-5555-4b3d-aa57-6615b27d4d5d
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /O op&#231;&#245;es (otimizar c&#243;digo)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As opções de **\/O** controlam as várias otimizações que o ajudam a criar o código da velocidade máxima ou o tamanho mínimo.  
  
-   [\/O1](../../build/reference/o1-o2-minimize-size-maximize-speed.md) otimiza o código para o tamanho mínimo.  
  
-   [\/O2](../../build/reference/o1-o2-minimize-size-maximize-speed.md) otimiza o código da velocidade máxima.  
  
-   expansão da função embutida dos controles de[\/Ob](../../build/reference/ob-inline-function-expansion.md) .  
  
-   [\/Od](../../build/reference/od-disable-debug.md) desabilita a otimização, compilação de pressa e depuração de simplificação.  
  
-   [\/Og](../../build/reference/og-global-optimizations.md) habilita otimizações globais.  
  
-   [\/Oi](../Topic/-Oi%20\(Generate%20Intrinsic%20Functions\).md) gerenciar funções intrínsecas para chamadas de função apropriadas.  
  
-   [\/Os](../../build/reference/os-ot-favor-small-code-favor-fast-code.md) informa o compilador favorecem otimizações para o tamanho em otimizações para a velocidade.  
  
-   [\/Ot](../../build/reference/os-ot-favor-small-code-favor-fast-code.md) \(uma configuração padrão\) avisa ao compilador favorecem otimizações para a velocidade sobre otimizações para o tamanho.  
  
-   [\/Ox](../../build/reference/ox-full-optimization.md) seleciona a otimização completa.  
  
-   [\/Oy](../../build/reference/oy-frame-pointer-omission.md) suprime a criação de ponteiros do quadro na pilha de chamadas para uma chamada de função mais rápidos.  
  
## Comentários  
 Também é possível combinar várias opções de **\/O** em uma única instrução da opção.  Por exemplo, `/Odi` é o mesmo que `/Od /Oi`.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)