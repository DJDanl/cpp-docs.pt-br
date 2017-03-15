---
title: "Vis&#227;o geral de instru&#231;&#245;es C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "instruções, C++"
ms.assetid: e56996b2-b846-4b99-ac94-ac72fffc5ec7
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Vis&#227;o geral de instru&#231;&#245;es C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As instruções C\+\+ são executadas sequencialmente, exceto quando uma instrução de expressão, uma instrução de seleção, uma instrução de iteração ou uma instrução de salto modificam especificamente essa sequência.  
  
 As instruções podem ter os seguintes tipos:  
  
```  
  
        labeled-statement  
expression-statement  
compound-statement  
selection-statement  
iteration-statement  
jump-statement  
declaration-statement  
try-throw-catch  
```  
  
 Na maioria dos casos, a sintaxe da instrução C\+\+ é idêntica à de ANSI C.  A principal diferença entre os dois é que, em C, as declarações são permitidas apenas no começo de um bloco; C\+\+ adiciona a *instrução de declaração*, que remove efetivamente esta restrição.  Isso permite que você apresente variáveis em um ponto no programa onde um valor de inicialização pré\-computado pode ser calculado.  
  
 Declarar variáveis dentro de blocos também permite que você controle com precisão o escopo e o tempo de vida das variáveis.  
  
 Os tópicos sobre instruções descrevem as seguintes palavras\-chave de C\+\+:  
  
|||||  
|-|-|-|-|  
|[break](../cpp/break-statement-cpp.md)|[else](../cpp/if-else-statement-cpp.md)|[\_\_if\_exists](../cpp/if-exists-statement.md)|[\_\_try](../cpp/structured-exception-handling-c-cpp.md)|  
|[case](../cpp/switch-statement-cpp.md)|[\_\_except](../cpp/structured-exception-handling-c-cpp.md)|[\_\_if\_not\_exists](../cpp/if-not-exists-statement.md)|[try](../cpp/try-throw-and-catch-statements-cpp.md)|  
|[catch](../cpp/try-throw-and-catch-statements-cpp.md)|[for](../cpp/for-statement-cpp.md)|[\_\_leave](../c-language/try-finally-statement-c.md)|[while](../cpp/while-statement-cpp.md)|  
|[continue](../cpp/continue-statement-cpp.md)|[goto](../cpp/goto-statement-cpp.md)|[return](../Topic/return%20Statement%20\(C++\).md)||  
|[default](../cpp/switch-statement-cpp.md)|[\_\_finally](../cpp/structured-exception-handling-c-cpp.md)|[switch](../cpp/switch-statement-cpp.md)||  
|[do](../cpp/do-while-statement-cpp.md)|[if](../cpp/if-else-statement-cpp.md)|[throw](../cpp/try-throw-and-catch-statements-cpp.md)||  
  
## Consulte também  
 [Instruções](../cpp/statements-cpp.md)