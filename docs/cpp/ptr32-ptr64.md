---
title: ptr32, ptr64 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- __ptr32_cpp
- __ptr64_cpp
dev_langs:
- C++
helpviewer_keywords:
- __ptr64 keyword [C++]
- _ptr32 keyword [C++]
- ptr32 keyword [C++]
- ptr64 keyword [C++]
- _ptr64 keyword [C++]
- __ptr32 keyword [C++]
ms.assetid: afb563d8-7458-4fe7-9c30-bd4b5385a59f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5746c8f54a51e24bad23dcb66f6648266e2e4b56
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34704809"
---
# <a name="ptr32-ptr64"></a>__ptr32, __ptr64

**Seção específica da Microsoft**

`__ptr32` representa um ponteiro nativo em um sistema de 32 bits, enquanto `__ptr64` representa um ponteiro nativo em um sistema de 64 bits.

O exemplo a seguir mostra como declarar cada um desses tipos de ponteiro:

```cpp
int * __ptr32 p32;
int * __ptr64 p64;
```

 Em um sistema de 32 bits, um ponteiro declarado com `__ptr64` é truncado em um ponteiro de 32 bits. Em um sistema de 64 bits, um ponteiro declarado com `__ptr32` é imposto a um ponteiro de 64 bits.

> [!NOTE]
> Não é possível usar `__ptr32` ou `__ptr64` ao compilar com **/clr: pure**. Caso contrário, será gerado C2472 de erro do compilador. O **/clr: pure** e **/CLR: safe** opções do compilador são substituídas no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como declarar e alocar ponteiros com as palavras-chave `__ptr32` e `__ptr64`.

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

- [Tipos fundamentais](../cpp/fundamental-types-cpp.md)