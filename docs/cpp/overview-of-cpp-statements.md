---
title: "Visão geral de instruções C++ | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords: statements [C++]
ms.assetid: e56996b2-b846-4b99-ac94-ac72fffc5ec7
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 62415d4dd5df14bfd2d26fdd976fe6e3c53ba95d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="overview-of-c-statements"></a>Visão geral de instruções C++
As instruções C++ são executadas sequencialmente, exceto quando uma instrução de expressão, uma instrução de seleção, uma instrução de iteração ou uma instrução de salto modificam especificamente essa sequência.  
  
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
  
 Na maioria dos casos, a sintaxe de instrução de C++ é idêntica de ANSI C. A principal diferença entre os dois é que, em C, declarações são permitidos apenas no início de um bloco; C++ adiciona o *-declaração*, que efetivamente remove essa restrição. Isso permite que você apresente variáveis em um ponto no programa onde um valor de inicialização pré-computado pode ser calculado.  
  
 Declarar variáveis dentro de blocos também permite que você controle com precisão o escopo e o tempo de vida das variáveis.  
  
 Os tópicos sobre instruções descrevem as seguintes palavras-chave de C++:  
  
|||||  
|-|-|-|-|  
|[break](../cpp/break-statement-cpp.md)|[else](../cpp/if-else-statement-cpp.md)|[if_exists](../cpp/if-exists-statement.md)|[__try](../cpp/structured-exception-handling-c-cpp.md)|  
|[case](../cpp/switch-statement-cpp.md)|[__except](../cpp/structured-exception-handling-c-cpp.md)|[if_not_exists](../cpp/if-not-exists-statement.md)|[try](../cpp/try-throw-and-catch-statements-cpp.md)|  
|[catch](../cpp/try-throw-and-catch-statements-cpp.md)|[for](../cpp/for-statement-cpp.md)|[__leave](../c-language/try-finally-statement-c.md)|[while](../cpp/while-statement-cpp.md)|  
|[continue](../cpp/continue-statement-cpp.md)|[goto](../cpp/goto-statement-cpp.md)|[return](../cpp/return-statement-cpp.md)||  
|[default](../cpp/switch-statement-cpp.md)|[__finally](../cpp/structured-exception-handling-c-cpp.md)|[switch](../cpp/switch-statement-cpp.md)||  
|[do](../cpp/do-while-statement-cpp.md)|[if](../cpp/if-else-statement-cpp.md)|[throw](../cpp/try-throw-and-catch-statements-cpp.md)||  
  
## <a name="see-also"></a>Consulte também  
 [Instruções](../cpp/statements-cpp.md)