---
title: "/Q Op&#231;&#245;es (opera&#231;&#245;es de n&#237;vel baixo) | Microsoft Docs"
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
  - "/q"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador Q [C++]"
  - "Opção de compilador -Q [C++]"
  - "Opção de compilador /Q (C++)"
ms.assetid: 9fa738b9-630a-4bde-bc87-bdfa30552be4
caps.latest.revision: 24
caps.handback.revision: 24
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Q Op&#231;&#245;es (opera&#231;&#245;es de n&#237;vel baixo)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Você pode usar as opções do compilador de **\/Q** executar as seguintes operações de nível baixo do compilador:  
  
-   [\/Qfast\_transcendentals \(forçar transcendentais rápidos\)](../../build/reference/qfast-transcendentals-force-fast-transcendentals.md): Gerenciar transcendentals rápidos.  
  
-   [\/QIfist \(suprimir \_ftol\)](../../build/reference/qifist-suppress-ftol.md): Suprime `_ftol` quando uma conversão de um tipo de ponto flutuante a um tipo inteiro é necessária \(somente x86\).  
  
-   [\/Qimprecise\_fwaits \(remover fwaits dentro de blocos Try\)](../../build/reference/qimprecise-fwaits-remove-fwaits-inside-try-blocks.md): Remove os comandos de `fwait` nos blocos de `try` .  
  
-   [\/Qpar \(paralelizador automático\)](../Topic/-Qpar%20\(Auto-Parallelizer\).md): Habilita o parallelization automática de loop que são marcados com a política de [loops de \#pragma \(\)](../../preprocessor/loop.md) .  
  
-   [\/Qpar\-report \(nível de relatórios do paralelizador automático\)](../../build/reference/qpar-report-auto-parallelizer-reporting-level.md): Habilita os níveis de relatório para o parallelization automático.  
  
-   [\/Qsafe\_fp\_loads](../../build/reference/qsafe-fp-loads.md): Suprime otimizações para cargas do registro de ponto flutuante e para move entre a memória e MMX registros.  
  
-   [\/Qvec\-report \(nível de relatórios do vetorizador automático\)](../../build/reference/qvec-report-auto-vectorizer-reporting-level.md): Habilita os níveis de relatório para o vectorization automático.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)