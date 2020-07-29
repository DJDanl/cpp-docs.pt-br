---
title: Aviso do compilador (nível 4) C4211
ms.date: 11/04/2016
f1_keywords:
- C4211
helpviewer_keywords:
- C4211
ms.assetid: 3eea3455-6faa-4cdb-8730-73db7026bd1f
ms.openlocfilehash: df19f90e17d6737a2639eb1245da197881e35c96
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218098"
---
# <a name="compiler-warning-level-4-c4211"></a>Aviso do compilador (nível 4) C4211

extensão não padrão usada: extern redefinido para estático

Com as extensões padrão da Microsoft (/Ze), você pode redefinir um **`extern`** identificador como **`static`** .

## <a name="example"></a>Exemplo

```c
// C4211.c
// compile with: /W4
extern int i;
static int i;   // C4211

int main()
{
}
```

Essas redefinições são inválidas em compatibilidade com ANSI ([/za](../../build/reference/za-ze-disable-language-extensions.md)).
