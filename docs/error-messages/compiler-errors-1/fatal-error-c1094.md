---
title: Erro fatal C1094
ms.date: 11/04/2016
f1_keywords:
- C1094
helpviewer_keywords:
- C1094
ms.assetid: 9e1193b2-cb95-44f9-bf6f-019e0d41dd97
ms.openlocfilehash: 99bfeea47ff46b6dadac9b32fa61306d54520d0f
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74747391"
---
# <a name="fatal-error-c1094"></a>Erro fatal C1094

'-Zmval1 ': opção de linha de comando é inconsistente com o valor usado para compilar o cabeçalho pré-compilado ('-Zmval2 ')

O valor passado para [/YC](../../build/reference/yc-create-precompiled-header-file.md) deve ser o mesmo valor passado para [/Yu](../../build/reference/yu-use-precompiled-header-file.md) (os valores de **/ZM** devem ser iguais em todas as compilações que usam ou criam o mesmo arquivo de cabeçalho pré-compilado).

O exemplo a seguir gera C1094:

```
// C1094.h
int func1();
```

E, em seguida,

```cpp
// C1094.cpp
// compile with: /Yc"C1094.h" /Zm200
int u;
int main() {
   int sd = 32;
}
#include "C1094.h"
```

E, em seguida,

```cpp
// C1094b.cpp
// compile with: /Yu"C1094.h" /Zm300 /c
#include "C1094.h"   // C1094 compile with /Zm200
void Test() {}
```
