---
title: __noop
ms.date: 09/02/2019
f1_keywords:
- __noop_cpp
- __noop
helpviewer_keywords:
- __noop keyword [C++]
ms.assetid: 81ac6e97-7bf8-496b-b3c4-fd02837573e5
ms.openlocfilehash: e12855127e417472eb88c951b71881240b808013
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214198"
---
# <a name="__noop"></a>__noop

**Específico da Microsoft**

O **`__noop`** intrínseco especifica que uma função deve ser ignorada. A lista de argumentos é analisada, mas nenhum código é gerado para os argumentos. Ele é destinado ao uso em funções de depuração globais que usam um número variável de argumentos.

O compilador converte o **`__noop`** intrínseco em 0 no tempo de compilação.

## <a name="example"></a>Exemplo

O código a seguir mostra como você pode usar **`__noop`** .

```cpp
// compiler_intrinsics__noop.cpp
// compile with or without /DDEBUG
#include <stdio.h>

#if DEBUG
   #define PRINT   printf_s
#else
   #define PRINT   __noop
#endif

int main() {
   PRINT("\nhello\n");
}
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[Palavras-chave](../cpp/keywords-cpp.md)
