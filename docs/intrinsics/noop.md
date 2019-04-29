---
title: __noop
ms.date: 11/04/2016
f1_keywords:
- __noop_cpp
- __noop
helpviewer_keywords:
- __noop keyword [C++]
ms.assetid: 81ac6e97-7bf8-496b-b3c4-fd02837573e5
ms.openlocfilehash: 674b5170dd2bba7038dfe11af906e31540acd993
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62262977"
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