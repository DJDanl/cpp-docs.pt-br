---
title: Erro do compilador C2164
ms.date: 11/04/2016
f1_keywords:
- C2164
helpviewer_keywords:
- C2164
ms.assetid: 55df5024-68a8-45a8-ae6c-e6dba35318a2
ms.openlocfilehash: 3b1c7a94dfca1c2767e14f96204ecda670c8a586
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50460808"
---
# <a name="compiler-error-c2164"></a>Erro do compilador C2164

'function': função intrínseca não declarada

Uma `intrinsic` pragma usa uma função não declarada (ocorre apenas com **/Oi**). Ou, um dos intrínsecos do compilador foi usado sem a inclusão de seu arquivo de cabeçalho.

O exemplo a seguir gera C2164:

```
// C2164.c
// compile with: /c
// processor: x86
// Uncomment the following line to resolve.
// #include "xmmintrin.h"
void b(float *p) {
   _mm_load_ss(p);   // C2164
}
```