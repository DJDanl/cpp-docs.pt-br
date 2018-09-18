---
title: Compilador aviso (nível 4) C4211 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4211
dev_langs:
- C++
helpviewer_keywords:
- C4211
ms.assetid: 3eea3455-6faa-4cdb-8730-73db7026bd1f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6f2c92ef68768f4a9f8ac606716d5ae53c4aa72e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46048208"
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


