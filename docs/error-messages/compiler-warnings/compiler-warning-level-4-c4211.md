---
title: Compilador aviso (nível 4) C4211
ms.date: 11/04/2016
f1_keywords:
- C4211
helpviewer_keywords:
- C4211
ms.assetid: 3eea3455-6faa-4cdb-8730-73db7026bd1f
ms.openlocfilehash: f1e85591d8ec989d806eb43a6be99bdb1dc62fb4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50659323"
---
# <a name="compiler-warning-level-4-c4211"></a>Compilador aviso (nível 4) C4211

extensão não padrão usada: extern redefinido como estático

Com as extensões da Microsoft padrão (/Ze), você pode redefinir um `extern` identificador como **estático**.

## <a name="example"></a>Exemplo

```
// C4211.c
// compile with: /W4
extern int i;
static int i;   // C4211

int main()
{
}
```

Tais redefinições são inválidas para a compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).

## <a name="see-also"></a>Consulte também

