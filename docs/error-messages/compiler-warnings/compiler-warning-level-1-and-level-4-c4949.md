---
title: Compilador aviso (nível 1 e nível 4) C4949
ms.date: 11/04/2016
f1_keywords:
- C4949
helpviewer_keywords:
- C4949
ms.assetid: 34f45a05-c115-49cb-9f67-0bd4f0735d9b
ms.openlocfilehash: 8050edbd7a653776d046bc7b4155fd43094d9a5d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50515916"
---
# <a name="compiler-warning-level-1-and-level-4-c4949"></a>Compilador aviso (nível 1 e nível 4) C4949

pragmas 'managed' e 'unmanaged' são significativos apenas quando compilado com ' / clr [: opção]'

O compilador ignora os [managed](../../preprocessor/managed-unmanaged.md) e não gerenciados pragmas, se o código-fonte não é compilado com [/clr](../../build/reference/clr-common-language-runtime-compilation.md). Esse aviso é informativo.

O exemplo a seguir gera C4949:

```
// C4949.cpp
// compile with: /LD /W1
#pragma managed   // C4949
```

Quando **#pragma não gerenciado** for usado sem **/clr**, C4949 é um aviso de nível 4.

O exemplo a seguir gera C4949:

```
// C4949b.cpp
// compile with: /LD /W4
#pragma unmanaged   // C4949
```