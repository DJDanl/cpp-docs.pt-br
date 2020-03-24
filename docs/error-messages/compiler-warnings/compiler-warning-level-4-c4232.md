---
title: Aviso do compilador (nível 4) C4232
ms.date: 11/04/2016
f1_keywords:
- C4232
helpviewer_keywords:
- C4232
ms.assetid: f92028a5-4ddd-43c1-97f5-4f724e5e14af
ms.openlocfilehash: c0e79dfa4564960a5660f0932b142b436370ac05
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80173914"
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
