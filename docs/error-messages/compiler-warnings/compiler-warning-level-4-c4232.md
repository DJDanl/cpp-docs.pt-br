---
title: Compilador aviso (nível 4) C4232
ms.date: 11/04/2016
f1_keywords:
- C4232
helpviewer_keywords:
- C4232
ms.assetid: f92028a5-4ddd-43c1-97f5-4f724e5e14af
ms.openlocfilehash: dee087b73bf032a68daf0527ea584efcc7579361
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50552627"
---
# <a name="compiler-warning-level-4-c4232"></a>Compilador aviso (nível 4) C4232

extensão não padrão usada: 'identifier': endereço de dllimport 'dllimport' não é estático, identidade não garantida

Em extensões da Microsoft (/Ze), você pode fornecer um valor não estático como o endereço de uma função declarada com o **dllimport** modificador. Sob a compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)), isso faz com que um erro.

O exemplo a seguir gera C4232:

```
// C4232.c
// compile with: /W4 /Ze /c
int __declspec(dllimport) f();
int (*pfunc)() = &f;   // C4232
```