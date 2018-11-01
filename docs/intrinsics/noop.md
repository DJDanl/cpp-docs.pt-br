---
title: __noop
ms.date: 11/04/2016
f1_keywords:
- __noop_cpp
- __noop
helpviewer_keywords:
- __noop keyword [C++]
ms.assetid: 81ac6e97-7bf8-496b-b3c4-fd02837573e5
ms.openlocfilehash: 074ab4c6ea51c8b3a2543d9b43248a8da37567cf
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50612995"
---
# <a name="noop"></a>__noop

**Seção específica da Microsoft**

O `__noop` intrínseco Especifica que uma função deve ser ignorada e a lista de argumentos ser analisados, mas nenhum código gerado para os argumentos. Ele se destina para uso em funções de depuração global que possuem um número variável de argumentos.

O compilador converte as `__noop` intrínseco para 0 no tempo de compilação.

## <a name="example"></a>Exemplo

O código a seguir mostra como você poderia usar `__noop`.

```
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

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)