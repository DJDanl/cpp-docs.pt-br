---
title: Compilador aviso (nível 1) C4218 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4218
dev_langs:
- C++
helpviewer_keywords:
- C4218
ms.assetid: d6c3cd90-4518-49e9-ae86-4ba9e2761d98
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1970dd1bd231716f59508a7cca9f82d3e13151ae
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46074039"
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