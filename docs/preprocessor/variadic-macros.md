---
title: Variadic macros
ms.date: 10/17/2019
helpviewer_keywords:
- variadic macros [C++]
- __VA_ARGS__ variadic macro specifier
ms.assetid: 51e757dc-0134-4bb2-bb74-64ea5ad75134
ms.openlocfilehash: de4d3a7f03f613cb058e564664f01837df23aefb
ms.sourcegitcommit: 8178d22701047d24f69f10d01ba37490e3d67241
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/18/2019
ms.locfileid: "72587889"
---
# <a name="variadic-macros"></a>Variadic macros

Macros variadic são macros do tipo função que contêm um número variável de argumentos.

## <a name="remarks"></a>Comentários

Para usar Macros Variadic, as reticências podem ser especificadas como o argumento formal final em uma definição de macro e o identificador de substituição `__VA_ARGS__` pode ser usado na definição para inserir os argumentos extras.  `__VA_ARGS__` é substituído por todos os argumentos que correspondem às reticências, incluindo vírgulas entre eles.

O padrão C especifica que pelo menos um argumento deve ser passado para as reticências, para garantir que a macro não seja resolvida para uma expressão com uma vírgula à direita. A implementação tradicional C++ da Microsoft suprime uma vírgula à direita se nenhum argumento for passado para as reticências. Quando a opção de compilador `/experimental:preprocessor` é definida, a vírgula à direita não é suprimida.

## <a name="example"></a>Exemplo

```cpp
// variadic_macros.cpp
#include <stdio.h>
#define EMPTY

#define CHECK1(x, ...) if (!(x)) { printf(__VA_ARGS__); }
#define CHECK2(x, ...) if ((x)) { printf(__VA_ARGS__); }
#define CHECK3(...) { printf(__VA_ARGS__); }
#define MACRO(s, ...) printf(s, __VA_ARGS__)

int main() {
    CHECK1(0, "here %s %s %s", "are", "some", "varargs1(1)\n");
    CHECK1(1, "here %s %s %s", "are", "some", "varargs1(2)\n");   // won't print

    CHECK2(0, "here %s %s %s", "are", "some", "varargs2(3)\n");   // won't print
    CHECK2(1, "here %s %s %s", "are", "some", "varargs2(4)\n");

    // always invokes printf in the macro
    CHECK3("here %s %s %s", "are", "some", "varargs3(5)\n");

    MACRO("hello, world\n");

    MACRO("error\n", EMPTY); // would cause error C2059, except VC++
                             // suppresses the trailing comma
}
```

```Output
here are some varargs1(1)
here are some varargs2(4)
here are some varargs3(5)
hello, world
error
```

## <a name="see-also"></a>Consulte também

[Macros (C/C++)](../preprocessor/macros-c-cpp.md)
