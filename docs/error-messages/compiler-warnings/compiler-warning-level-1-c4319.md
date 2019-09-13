---
title: Aviso do compilador (nível 1) C4319
ms.date: 01/18/2018
f1_keywords:
- C4319
helpviewer_keywords:
- C4319
ms.assetid: 1fac8048-9bd6-4552-a21c-192c67772bb9
ms.openlocfilehash: 2d5ae8fcf5a527031c3a974b227f713675f31ffa
ms.sourcegitcommit: effb516760c0f956c6308eeded48851accc96b92
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70926110"
---
# <a name="compiler-warning-level-1-c4319"></a>Aviso do compilador (nível 1) C4319

> ' ~ ': sem estender '*type1*' para '*type2*' de tamanho maior

O resultado do **~** operador (complemento bits) é não assinado e estendido em zero quando é convertido em um tipo maior.

## <a name="example"></a>Exemplo

No exemplo a seguir, `~(a - 1)` é avaliado como uma expressão longa não assinada de 32 bits e, em seguida, convertido em 64 bits por extensão zero. Isso pode levar a resultados de operação inesperados.

```cpp
// C4319.cpp
// compile with: cl /W4 C4319.cpp
int main() {
   unsigned long a = 0;
   unsigned long long q = 42;
   q = q & ~(a - 1);    // C4319 expected
}
```
