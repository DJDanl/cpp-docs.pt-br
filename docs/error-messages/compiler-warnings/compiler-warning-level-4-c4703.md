---
title: Compilador aviso (nível 4) C4703
ms.date: 11/04/2016
f1_keywords:
- C4703
helpviewer_keywords:
- C4703
ms.assetid: 5dad454e-69e3-4931-9168-050a861c05f8
ms.openlocfilehash: 6115db7611de521d66df3b1f555349891d72cc03
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62395229"
---
# <a name="compiler-warning-level-4-c4703"></a>Compilador aviso (nível 4) C4703

Potencialmente não inicializada a variável de ponteiro local 'name' usado

A variável de ponteiro local *nome* podem ter sido usadas sem que está sendo atribuído um valor. Isso pode levar a resultados imprevisíveis.

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

[Aviso do compilador (nível 4) C4701](../../error-messages/compiler-warnings/compiler-warning-level-4-c4701.md)<br/>
[Avisos, /sdl e melhorando a detecção de variável não inicializada](https://www.microsoft.com/security/blog/2012/06/06/warnings-sdl-and-improving-uninitialized-variable-detection/)