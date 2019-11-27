---
title: Aviso do compilador (nível 4) C4232
ms.date: 11/04/2016
f1_keywords:
- C4232
helpviewer_keywords:
- C4232
ms.assetid: f92028a5-4ddd-43c1-97f5-4f724e5e14af
ms.openlocfilehash: 9d328b1b5e4c3875f29b48eab77cd6f6d49d447f
ms.sourcegitcommit: 3ee06ec53153cf21910fc8cfef78a4f25f9633f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/26/2019
ms.locfileid: "74541888"
---
# <a name="compiler-warning-level-4-c4232"></a>Aviso do compilador (nível 4) C4232

extensão não padrão usada: ' identifier ': o endereço de dllimport ' dllimport ' não é estático, identidade não garantida

Em extensões da Microsoft (/Ze), você pode dar um valor não estático como o endereço de uma função declarada com o modificador **DllImport** . Em compatibilidade com ANSI ([/za](../../build/reference/za-ze-disable-language-extensions.md)), isso causa um erro.

O exemplo a seguir gera C4232:

```c
// C4232.c
// compile with: /W4 /Ze /c
int __declspec(dllimport) f();
int (*pfunc)() = &f;   // C4232
```