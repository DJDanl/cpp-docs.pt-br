---
title: Aviso do compilador (nível 1) C4218
ms.date: 11/04/2016
f1_keywords:
- C4218
helpviewer_keywords:
- C4218
ms.assetid: d6c3cd90-4518-49e9-ae86-4ba9e2761d98
ms.openlocfilehash: f7553b30a17f50f559351353552fd656fceb8657
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80199791"
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
