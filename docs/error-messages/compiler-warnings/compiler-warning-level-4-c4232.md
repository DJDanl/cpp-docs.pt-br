---
title: Aviso do compilador (nível 4) C4232
ms.date: 11/04/2016
f1_keywords:
- C4232
helpviewer_keywords:
- C4232
ms.assetid: f92028a5-4ddd-43c1-97f5-4f724e5e14af
ms.openlocfilehash: 6081acc4a64394c9122650da8b7f4147f724e5de
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219918"
---
# <a name="compiler-warning-level-4-c4232"></a>Aviso do compilador (nível 4) C4232

extensão não padrão usada: ' identifier ': o endereço de dllimport ' dllimport ' não é estático, identidade não garantida

Em extensões da Microsoft (/Ze), você pode dar um valor não estático como o endereço de uma função declarada com o **`dllimport`** modificador. Em compatibilidade com ANSI ([/za](../../build/reference/za-ze-disable-language-extensions.md)), isso causa um erro.

O exemplo a seguir gera C4232:

```c
// C4232.c
// compile with: /W4 /Ze /c
int __declspec(dllimport) f();
int (*pfunc)() = &f;   // C4232
```
