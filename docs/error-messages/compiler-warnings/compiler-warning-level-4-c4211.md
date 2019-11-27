---
title: Aviso do compilador (nível 4) C4211
ms.date: 11/04/2016
f1_keywords:
- C4211
helpviewer_keywords:
- C4211
ms.assetid: 3eea3455-6faa-4cdb-8730-73db7026bd1f
ms.openlocfilehash: 6387f58430098e49e7add25e8915bf6b181634e9
ms.sourcegitcommit: 3ee06ec53153cf21910fc8cfef78a4f25f9633f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/26/2019
ms.locfileid: "74541837"
---
# <a name="compiler-warning-level-4-c4211"></a>Aviso do compilador (nível 4) C4211

extensão não padrão usada: extern redefinido para estático

Com as extensões padrão da Microsoft (/Ze), você pode redefinir um identificador de `extern` como **estático**.

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
