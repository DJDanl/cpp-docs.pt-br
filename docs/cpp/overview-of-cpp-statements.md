---
title: Visão geral de instruções C++
ms.date: 11/04/2016
helpviewer_keywords:
- statements [C++]
ms.assetid: e56996b2-b846-4b99-ac94-ac72fffc5ec7
ms.openlocfilehash: 9493860087331ee2d8ff05a5c0bd59c7a46ad51a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62325553"
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

Na maioria dos casos, a sintaxe da instrução C++ é idêntica de ANSI C. A principal diferença entre os dois é que em C, declarações são permitidas apenas no início de um bloco; C++ adiciona o *instrução de declaração*, que remove efetivamente esta restrição. Isso permite que você apresente variáveis em um ponto no programa onde um valor de inicialização pré-computado pode ser calculado.

Declarar variáveis dentro de blocos também permite que você controle com precisão o escopo e o tempo de vida das variáveis.

Os tópicos sobre instruções descrevem as seguintes palavras-chave de C++:

|||||
|-|-|-|-|
|[break](../cpp/break-statement-cpp.md)|[else](../cpp/if-else-statement-cpp.md)|[__if_exists](../cpp/if-exists-statement.md)|[__try](../cpp/structured-exception-handling-c-cpp.md)|
|[case](../cpp/switch-statement-cpp.md)|[__except](../cpp/structured-exception-handling-c-cpp.md)|[__if_not_exists](../cpp/if-not-exists-statement.md)|[try](../cpp/try-throw-and-catch-statements-cpp.md)|
|[catch](../cpp/try-throw-and-catch-statements-cpp.md)|[for](../cpp/for-statement-cpp.md)|[__leave](../c-language/try-finally-statement-c.md)|[while](../cpp/while-statement-cpp.md)|
|[continue](../cpp/continue-statement-cpp.md)|[goto](../cpp/goto-statement-cpp.md)|[return](../cpp/return-statement-cpp.md)||
|[default](../cpp/switch-statement-cpp.md)|[__finally](../cpp/structured-exception-handling-c-cpp.md)|[switch](../cpp/switch-statement-cpp.md)||
|[do](../cpp/do-while-statement-cpp.md)|[if](../cpp/if-else-statement-cpp.md)|[throw](../cpp/try-throw-and-catch-statements-cpp.md)||

## <a name="see-also"></a>Consulte também

[Instruções](../cpp/statements-cpp.md)