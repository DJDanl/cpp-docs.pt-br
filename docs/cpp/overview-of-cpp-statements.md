---
title: Visão geral de instruções C++
ms.date: 11/04/2016
helpviewer_keywords:
- statements [C++]
ms.assetid: e56996b2-b846-4b99-ac94-ac72fffc5ec7
ms.openlocfilehash: 9aba5deddca6fbf480cd9d573606b16b7ab047db
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80188422"
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

Na maioria dos casos, C++ a sintaxe da instrução é idêntica à do ANSI C. A principal diferença entre os dois é que, em C, as declarações são permitidas apenas no início de um bloco; C++ adiciona a *instrução de declaração*, que efetivamente remove essa restrição. Isso permite que você apresente variáveis em um ponto no programa onde um valor de inicialização pré-computado pode ser calculado.

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

## <a name="see-also"></a>Confira também

[Instruções](../cpp/statements-cpp.md)
