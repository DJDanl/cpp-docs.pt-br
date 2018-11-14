---
title: Compilador aviso (nível 4) C4701
ms.date: 11/04/2016
f1_keywords:
- C4701
helpviewer_keywords:
- C4701
ms.assetid: d7c76c66-1f3f-4d3c-abe4-5d94c84a5a1f
ms.openlocfilehash: d2f95b9b2f4357d9719785880706c41f68fdfea0
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51519770"
---
# <a name="compiler-warning-level-4-c4701"></a>Compilador aviso (nível 4) C4701

variável local possivelmente não inicializada 'name' usado

A variável local *nome* podem ter sido usadas sem que está sendo atribuído um valor. Isso pode levar a resultados imprevisíveis.

## <a name="example"></a>Exemplo

O código a seguir gera C4701 e C4703.

```cpp
#include <malloc.h>

void func(int size)
{
    void* p;
    if (size < 256) {
        p = malloc(size);
    }

    if (p != nullptr) // C4701 and C4703
        free(p);
}

void main()
{
    func(9);
}
```

```Output
c:\src\test.cpp(10) : warning C4701: potentially uninitialized local variable 'p' used
c:\src\test.cpp(10) : warning C4703: potentially uninitialized local pointer variable 'p' used
```

Para corrigir este aviso, inicialize a variável, conforme mostrado neste exemplo:

```cpp
#include <malloc.h>

void func(int size)
{
    void* p = nullptr;
    if (size < 256) {
        p = malloc(size);
    }

    if (p != nullptr)
        free(p);
}

void main()
{
    func(9);
}
```

## <a name="see-also"></a>Consulte também

[Aviso do compilador (nível 4) C4703](../../error-messages/compiler-warnings/compiler-warning-level-4-c4703.md)<br/>
[Avisos, /sdl e melhorando a detecção de variável não inicializada](http://blogs.msdn.com/b/sdl/archive/2012/06/06/warnings-sdl-and-improving-uninitialized-variable-detection.aspx)