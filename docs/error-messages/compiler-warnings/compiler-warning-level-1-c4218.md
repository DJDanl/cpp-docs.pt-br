---
title: Aviso do compilador (nível 1) C4218
ms.date: 11/04/2016
f1_keywords:
- C4218
helpviewer_keywords:
- C4218
ms.assetid: d6c3cd90-4518-49e9-ae86-4ba9e2761d98
ms.openlocfilehash: 226bc91c272ff62ebe127aa190384d30a214b05d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223246"
---
# <a name="compiler-warning-level-1-c4218"></a>Aviso do compilador (nível 1) C4218

extensão não padrão usada: deve especificar pelo menos uma classe de armazenamento ou um tipo

Com as extensões padrão da Microsoft (/Ze), você pode declarar uma variável sem especificar um tipo ou classe de armazenamento. O tipo padrão é **`int`** .

## <a name="example"></a>Exemplo

```cpp
// C4218.c
// compile with: /W4
i;  // C4218

int main()
{
}
```

Essas declarações são inválidas sob compatibilidade com ANSI ([/za](../../build/reference/za-ze-disable-language-extensions.md)).
