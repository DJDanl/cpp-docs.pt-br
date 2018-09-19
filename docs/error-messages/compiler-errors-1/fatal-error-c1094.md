---
title: Erro fatal C1094 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1094
dev_langs:
- C++
helpviewer_keywords:
- C1094
ms.assetid: 9e1193b2-cb95-44f9-bf6f-019e0d41dd97
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 15e722c6a74490a5fbb26e4e367f7f1b4cbcc932
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46109243"
---
# <a name="fatal-error-c1094"></a>Erro fatal C1094

'-Zmval1': opção de linha de comando é inconsistente com o valor usado para compilar cabeçalho pré-compilado ('-Zmval2')

O valor que é passado para [/Yc](../../build/reference/yc-create-precompiled-header-file.md) deve ser o mesmo valor que é passado para [/Yu](../../build/reference/yu-use-precompiled-header-file.md) (**/Zm** valores devem ser os mesmos em todas as compilações que usam ou criar o mesmo pré-compilado arquivo de cabeçalho).

O exemplo a seguir gera C1094:

```
// C1094.h
int func1();
```

E, em seguida,

```
// C1094.cpp
// compile with: /Yc"C1094.h" /Zm200
int u;
int main() {
   int sd = 32;
}
#include "C1094.h"
```

E, em seguida,

```
// C1094b.cpp
// compile with: /Yu"C1094.h" /Zm300 /c
#include "C1094.h"   // C1094 compile with /Zm200
void Test() {}
```