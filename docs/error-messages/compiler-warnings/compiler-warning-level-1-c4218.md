---
title: Compilador aviso (nível 1) C4218
ms.date: 11/04/2016
f1_keywords:
- C4218
helpviewer_keywords:
- C4218
ms.assetid: d6c3cd90-4518-49e9-ae86-4ba9e2761d98
ms.openlocfilehash: 36d5de3b1270b41edfc391df960a556aca207709
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386467"
---
# <a name="compiler-warning-level-1-c4218"></a>Compilador aviso (nível 1) C4218

extensão não padrão usada: deve especificar pelo menos uma classe de armazenamento ou um tipo

Com as extensões da Microsoft padrão (/Ze), você pode declarar uma variável sem especificar uma classe de armazenamento ou do tipo. O tipo padrão é `int`.

## <a name="example"></a>Exemplo

```
// C4218.c
// compile with: /W4
i;  // C4218

int main()
{
}
```

Essas declarações são inválidas para a compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).