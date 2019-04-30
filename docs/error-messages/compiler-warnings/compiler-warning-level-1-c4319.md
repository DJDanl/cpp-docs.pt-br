---
title: Compilador aviso (nível 1) C4319
ms.date: 1/18/2018
f1_keywords:
- C4319
helpviewer_keywords:
- C4319
ms.assetid: 1fac8048-9bd6-4552-a21c-192c67772bb9
ms.openlocfilehash: 20b268bacd6e7e259e9b4fa1c9e98fa6fd353718
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62385466"
---
# <a name="compiler-warning-level-1-c4319"></a>Compilador aviso (nível 1) C4319

> ' ~': estendendo o zero '*type1*'para'*type2*' de tamanho maior

O resultado do **~** operador (complemento bit a bit) é não assinado e, em seguida, estendido em zero quando ele é convertido em um tipo maior.

## <a name="example"></a>Exemplo

No exemplo a seguir, `~(a - 1)` é avaliada como uma expressão longo sem sinal de 32 bits e, em seguida, convertido em 64 bits pela extensão de zero. Isso pode levar a resultados de operação inesperado.

```cpp
// C4319.cpp
// compile with: cl /W4 C4319.cpp
int main() {
   unsigned long a = 0;
   unsigned long long q = 42;
   q = q & ~(a - 1);    // C4319 expected
}
```
