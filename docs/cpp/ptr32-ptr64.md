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
ms.openlocfilehash: 0e979ed51f9c34700cef75113018c23e69a304f9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50588468"
---
# <a name="ptr32-ptr64"></a>__ptr32, __ptr64

**Seção específica da Microsoft**

**__ptr32** representa um ponteiro nativo em um sistema de 32 bits, enquanto **__ptr64** representa um ponteiro nativo em um sistema de 64 bits.

O exemplo a seguir mostra como declarar cada um desses tipos de ponteiro:

```cpp
int * __ptr32 p32;
int * __ptr64 p64;
```

Em um sistema de 32 bits, um ponteiro declarado com **__ptr64** será truncado para um ponteiro de 32 bits. Em um sistema de 64 bits, um ponteiro declarado com **__ptr32** é forçado para um ponteiro de 64 bits.

> [!NOTE]
> Não é possível usar **__ptr32** ou **__ptr64** durante a compilação com **/clr: pure**. Caso contrário, o erro do compilador C2472 será gerado. O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Para compatibilidade com versões anteriores, **_ptr32** e **_ptr64** são sinônimos do **__ptr32** e **__ptr64** , a menos que a opção de compilador [/Za \(desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) for especificado.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como declarar e alocar ponteiros com o **__ptr32** e **__ptr64** palavras-chave.

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

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Tipos fundamentais](../cpp/fundamental-types-cpp.md)