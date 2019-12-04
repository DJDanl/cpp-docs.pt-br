---
title: Erro fatal C1017
ms.date: 11/04/2016
f1_keywords:
- C1017
helpviewer_keywords:
- C1017
ms.assetid: 5542e604-599d-4e36-8f83-1d454c5753c9
ms.openlocfilehash: 0feda3bc4c3729d3101be356220aa0124ba85190
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756936"
---
# <a name="fatal-error-c1017"></a>Erro fatal C1017

expressão de constante de inteiro inválida

A expressão em uma diretiva de `#if` não existia ou não foi avaliada como uma constante.

As constantes definidas usando `#define` devem ter valores que são avaliados como uma constante de inteiro se forem usados em uma diretiva `#if`, `#elif`ou `#else`.

O exemplo a seguir gera C1017:

```cpp
// C1017.cpp
#define CONSTANT_NAME "YES"
#if CONSTANT_NAME   // C1017
#endif
```

Resolução possível:

```cpp
// C1017b.cpp
// compile with: /c
#define CONSTANT_NAME 1
#if CONSTANT_NAME
#endif
```

Como `CONSTANT_NAME` é avaliada como uma cadeia de caracteres e não como um inteiro, a diretiva `#if` gera um erro fatal C1017.

Em outros casos, o pré-processador avalia uma constante indefinida como zero. Isso pode causar resultados não intencionais, conforme mostrado no exemplo a seguir. `YES` é indefinido, portanto, ele é avaliado como zero. A expressão `#if` `CONSTANT_NAME` é avaliada como false e o código a ser usado em `YES` é removido pelo pré-processador. `NO` também é indefinido (zero); portanto, `#elif` `CONSTANT_NAME==NO` é avaliado como true (`0 == 0`), fazendo com que o pré-processador deixe o código na parte `#elif` da instrução — exatamente o oposto do comportamento pretendido.

```cpp
// C1017c.cpp
// compile with: /c
#define CONSTANT_NAME YES
#if CONSTANT_NAME
   // Code to use on YES...
#elif CONSTANT_NAME==NO
   // Code to use on NO...
#endif
```

Para ver exatamente como o compilador manipula as diretivas de pré-processador, use [/p](../../build/reference/p-preprocess-to-a-file.md), [/e](../../build/reference/e-preprocess-to-stdout.md)ou [/EP](../../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md).
