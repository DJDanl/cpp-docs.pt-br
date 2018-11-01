---
title: Compilador aviso (nível 1) C4215
ms.date: 11/04/2016
f1_keywords:
- C4215
helpviewer_keywords:
- C4215
ms.assetid: f2aab64d-1bab-4f75-95ee-89e1263047b1
ms.openlocfilehash: a45cd6cf86eb8ab1edb33ad5e0df8374972c425e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50450816"
---
# <a name="compiler-warning-level-1-c4215"></a>Compilador aviso (nível 1) C4215

extensão não padrão usada: flutuante longo

As extensões padrão da Microsoft (/Ze) tratam **flutuante longo** como **duplo**. Compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)) não faz isso. Use **duplas** para manter a compatibilidade.

O exemplo a seguir gera C4215:

```
// C4215.cpp
// compile with: /W1 /LD
long float a;   // C4215

// use the line below to resolve the warning
// double a;
```