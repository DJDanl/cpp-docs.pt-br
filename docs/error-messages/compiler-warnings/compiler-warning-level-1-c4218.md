---
title: Aviso do compilador (nível 1) C4218
ms.date: 11/04/2016
f1_keywords:
- C4218
helpviewer_keywords:
- C4218
ms.assetid: d6c3cd90-4518-49e9-ae86-4ba9e2761d98
ms.openlocfilehash: f1db3eabc3b614019676dc4494e83104c62fe579
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73627302"
---
# <a name="compiler-warning-level-1-c4218"></a>Aviso do compilador (nível 1) C4218

extensão não padrão usada: deve especificar pelo menos uma classe de armazenamento ou um tipo

Com as extensões padrão da Microsoft (/Ze), você pode declarar uma variável sem especificar um tipo ou classe de armazenamento. O tipo padrão é `int`.

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