---
title: Inicializando cadeias de caracteres
ms.date: 11/04/2016
helpviewer_keywords:
- character arrays, initializing
- strings [C++], initializing
- initializing arrays, strings
ms.assetid: 0ab8079d-d0d3-48f9-afd1-36a7bb439b29
ms.openlocfilehash: c9dbad72314e9ce01d022d26209e2132c29c106a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62325995"
---
# <a name="initializing-strings"></a>Inicializando cadeias de caracteres

Você pode inicializar uma matriz de caracteres (ou caracteres largos) com uma literal de cadeia de caracteres (ou literal de cadeia de caracteres largos). Por exemplo: 

```
char code[ ] = "abc";
```

inicializa `code` como uma matriz de caracteres de quatro elementos. O quarto elemento é caractere nulo, que termina todos os literais de cadeia de caracteres.

Uma lista de identificadores só pode ter o mesmo número de identificadores a serem inicializados. Se você especificar um tamanho da matriz menor do que a cadeia de caracteres; os caracteres adicionais serão ignorados. Por exemplo, a seguinte declaração inicializa `code` como uma matriz de caracteres de três elementos:

```
char code[3] = "abcd";
```

Somente os três primeiros caracteres do inicializador são atribuídos a `code`. O caractere `d` e o caractere de terminação nula da cadeia de caracteres são descartados. Observe que isso cria uma cadeia de caracteres não terminada (ou seja, sem um valor 0 para marcar seu fim) e gera uma mensagem de diagnóstico que indica essa condição.

Esta declaração

```
char s[] = "abc", t[3] = "abc";
```

é idêntica a

```
char s[]  = {'a', 'b', 'c', '\0'},
     t[3] = {'a', 'b', 'c' };
```

Se a cadeia de caracteres for menor que o tamanho de matriz especificado, os elementos restantes da matriz serão inicializados como 0.

**Específico da Microsoft**

No Microsoft C, os literais de cadeia de caracteres podem ter até 2048 bytes de comprimento.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Initialization](../c-language/initialization.md)
