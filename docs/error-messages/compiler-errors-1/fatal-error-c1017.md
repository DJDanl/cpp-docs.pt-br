---
title: Erro fatal C1017
ms.date: 11/04/2016
f1_keywords:
- C1017
helpviewer_keywords:
- C1017
ms.assetid: 5542e604-599d-4e36-8f83-1d454c5753c9
ms.openlocfilehash: e2309b93be65b049c35abf96572e144a0a518007
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62383172"
---
# <a name="fatal-error-c1017"></a>Erro fatal C1017

expressão de constante de inteiro inválido

A expressão em um `#if` diretiva não existe ou não foi avaliada como uma constante.

Constantes definidas usando `#define` devem ter valores que são avaliadas como uma constante de inteiro se eles forem usados em um `#if`, `#elif`, ou `#else` diretiva.

O exemplo a seguir gera C1017:

```
// C1017.cpp
#define CONSTANT_NAME "YES"
#if CONSTANT_NAME   // C1017
#endif
```

Solução possível:

```
// C1017b.cpp
// compile with: /c
#define CONSTANT_NAME 1
#if CONSTANT_NAME
#endif
```

Porque `CONSTANT_NAME` for avaliada como uma cadeia de caracteres e não é um inteiro, o `#if` diretiva gera o erro fatal C1017.

Em outros casos, o pré-processador avalia uma constante não definida como zero. Isso pode causar resultados não intencionais, conforme mostrado no exemplo a seguir. `YES` é indefinido, portanto, ele será avaliado como zero. A expressão `#if` `CONSTANT_NAME` é avaliada como false e o código a ser usado em `YES` é removido pelo pré-processador. `NO` também é indefinido (zero), então `#elif` `CONSTANT_NAME==NO` é avaliada como true (`0 == 0`), fazendo com que o pré-processador deixar o código no `#elif` parte da instrução — exatamente o oposto do comportamento pretendido.

```
// C1017c.cpp
// compile with: /c
#define CONSTANT_NAME YES
#if CONSTANT_NAME
   // Code to use on YES...
#elif CONSTANT_NAME==NO
   // Code to use on NO...
#endif
```

Para ver exatamente como o compilador trata as diretivas de pré-processamento, use [/P](../../build/reference/p-preprocess-to-a-file.md), [/E](../../build/reference/e-preprocess-to-stdout.md), ou [/EP](../../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md).