---
title: __noop
ms.date: 09/02/2019
f1_keywords:
- __noop_cpp
- __noop
helpviewer_keywords:
- __noop keyword [C++]
ms.assetid: 81ac6e97-7bf8-496b-b3c4-fd02837573e5
ms.openlocfilehash: 24ba85b1fbbba4491c03d5a81afae345228db3bd
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70217189"
---
# <a name="__noop"></a>__noop

**Seção específica da Microsoft**

O `__noop` intrínseco especifica que uma função deve ser ignorada. A lista de argumentos é analisada, mas nenhum código é gerado para os argumentos. Ele é destinado ao uso em funções de depuração globais que usam um número variável de argumentos.

O compilador converte o `__noop` intrínseco em 0 no tempo de compilação.

## <a name="example"></a>Exemplo

O código a seguir mostra como você pode `__noop`usar.

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

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[Palavras-chave](../cpp/keywords-cpp.md)
