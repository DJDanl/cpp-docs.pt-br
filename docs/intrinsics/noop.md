---
title: __noop
ms.date: 09/02/2019
f1_keywords:
- __noop_cpp
- __noop
helpviewer_keywords:
- __noop keyword [C++]
ms.assetid: 81ac6e97-7bf8-496b-b3c4-fd02837573e5
ms.openlocfilehash: aec4df98413bf34ac1e2966d012bb905edd4775e
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857925"
---
# <a name="__noop"></a>__noop

**Seção específica da Microsoft**

O `__noop` intrínseco especifica que uma função deve ser ignorada. A lista de argumentos é analisada, mas nenhum código é gerado para os argumentos. Ele é destinado ao uso em funções de depuração globais que usam um número variável de argumentos.

O compilador converte o `__noop` intrínseco para 0 no tempo de compilação.

## <a name="example"></a>Exemplo

O código a seguir mostra como você pode usar `__noop`.

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

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

\ [intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
[Palavras-chave](../cpp/keywords-cpp.md)
