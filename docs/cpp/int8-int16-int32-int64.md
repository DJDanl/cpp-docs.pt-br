---
title: __int8, __int16, __int32, __int64
ms.date: 10/09/2018
f1_keywords:
- __int8_cpp
- __int16_cpp
- __int32_cpp
- __int64_cpp
- __int8
- __int16
- __int32
- __int64
- _int8
- _int16
- _int32
- _int64
helpviewer_keywords:
- __int16 keyword [C++]
- integer data type [C++], integer types in C++
- __int32 keyword [C++]
- integer types [C++]
- __int8 keyword [C++]
- __int64 keyword [C++]
ms.assetid: 8e384602-2578-4980-8cc8-da63842356b2
ms.openlocfilehash: 7888a282fffbaa2a23783c3875e02838fd0b1826
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227394"
---
# <a name="__int8-__int16-__int32-__int64"></a>__int8, __int16, __int32, __int64

**Específico da Microsoft**

O Microsoft C/C++ tem suporte para tipos de inteiros dimensionados. Você pode declarar variáveis de inteiro de 8, 16, 32-ou 64 bits usando o **`__intN`** especificador de tipo, em que ***`N`*** é 8, 16, 32 ou 64.

O exemplo a seguir declara uma variável para cada um desses tipos de inteiros dimensionados:

```cpp
__int8 nSmall;      // Declares 8-bit integer
__int16 nMedium;    // Declares 16-bit integer
__int32 nLarge;     // Declares 32-bit integer
__int64 nHuge;      // Declares 64-bit integer
```

Os tipos **`__int8`** , **`__int16`** , e **`__int32`** são sinônimos para os tipos ANSI que têm o mesmo tamanho e são úteis para escrever código portátil que se comporta de forma idêntica em várias plataformas. O **`__int8`** tipo de dados é sinônimo de tipo **`char`** , **`__int16`** é sinônimo de tipo **`short`** e **`__int32`** é sinônimo de tipo **`int`** . O **`__int64`** tipo é sinônimo de tipo **`long long`** .

Para compatibilidade com versões anteriores,,,, **`_int8`** **`_int16`** **`_int32`** e **`_int64`** são sinônimos para **`__int8`** , **`__int16`** , **`__int32`** , e **`__int64`** a menos que a opção do compilador [ `/Za` \( desabilite extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra que um `__intN` parâmetro será promovido para **`int`** :

```cpp
// sized_int_types.cpp

#include <stdio.h>

void func(int i) {
    printf_s("%s\n", __FUNCTION__);
}

int main()
{
    __int8 i8 = 100;
    func(i8);   // no void func(__int8 i8) function
                // __int8 will be promoted to int
}
```

```Output
func
```

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Tipos internos](../cpp/fundamental-types-cpp.md)<br/>
[Intervalos de tipos de dados](../cpp/data-type-ranges.md)<br/>
