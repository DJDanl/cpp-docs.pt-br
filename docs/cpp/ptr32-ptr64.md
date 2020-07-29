---
title: __ptr32, __ptr64
ms.date: 10/09/2018
f1_keywords:
- __ptr32_cpp
- __ptr64_cpp
- __ptr32
- __ptr64
- _ptr32
- _ptr64
helpviewer_keywords:
- __ptr64 keyword [C++]
- _ptr32 keyword [C++]
- ptr32 keyword [C++]
- ptr64 keyword [C++]
- _ptr64 keyword [C++]
- __ptr32 keyword [C++]
ms.assetid: afb563d8-7458-4fe7-9c30-bd4b5385a59f
ms.openlocfilehash: 5ff2fa22c8a466252cfaf8b80dc8d56774aff58e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227147"
---
# <a name="__ptr32-__ptr64"></a>__ptr32, __ptr64

**Específico da Microsoft**

**`__ptr32`** representa um ponteiro nativo em um sistema de 32 bits, enquanto **`__ptr64`** representa um ponteiro nativo em um sistema de 64 bits.

O exemplo a seguir mostra como declarar cada um desses tipos de ponteiro:

```cpp
int * __ptr32 p32;
int * __ptr64 p64;
```

Em um sistema de 32 bits, um ponteiro declarado com **`__ptr64`** é truncado para um ponteiro de 32 bits. Em um sistema de 64 bits, um ponteiro declarado com **`__ptr32`** é forçado a um ponteiro de 64 bits.

> [!NOTE]
> Você não pode usar **`__ptr32`** ou **`__ptr64`** ao compilar com **/CLR: Pure**. Caso contrário, o erro do compilador C2472 será gerado. As opções de compilador **/CLR: Pure** e **/CLR: safe** são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Para compatibilidade com versões anteriores, **_ptr32** e **_ptr64** são sinônimos de **`__ptr32`** e **`__ptr64`** , a menos que a opção do compilador [/za \( desabilitar extensões de idioma)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como declarar e alocar ponteiros com as **`__ptr32`** **`__ptr64`** palavras-chave e.

```cpp
#include <cstdlib>
#include <iostream>

int main()
{
    using namespace std;

    int * __ptr32 p32;
    int * __ptr64 p64;

    p32 = (int * __ptr32)malloc(4);
    *p32 = 32;
    cout << *p32 << endl;

    p64 = (int * __ptr64)malloc(4);
    *p64 = 64;
    cout << *p64 << endl;
}
```

```Output
32
64
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Tipos internos](../cpp/fundamental-types-cpp.md)
