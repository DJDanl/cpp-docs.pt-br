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
ms.openlocfilehash: b765eabcac3f9643c0cae78fefb6ce8231669ffc
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62183448"
---
# <a name="int8-int16-int32-int64"></a>__int8, __int16, __int32, __int64

**Seção específica da Microsoft**

O Microsoft C/C++ tem suporte para tipos de inteiros dimensionados. Você pode declarar 8, 16, 32 ou variáveis de inteiro de 64 bits usando o **int**<em>n</em> especificador de tipo em que *n* é 8, 16, 32 ou 64.

O exemplo a seguir declara uma variável para cada um desses tipos de inteiros dimensionados:

```cpp
__int8 nSmall;      // Declares 8-bit integer
__int16 nMedium;    // Declares 16-bit integer
__int32 nLarge;     // Declares 32-bit integer
__int64 nHuge;      // Declares 64-bit integer
```

Os tipos **__int8**, **__int16**, e **__int32** são sinônimos dos tipos ANSI que têm o mesmo tamanho e são úteis para escrever código portátil que se comporta de forma idêntica em várias plataformas. O **__int8** tipo de dados é sinônimo do tipo **char**, **__int16** é sinônimo do tipo **curto**, e **__int32**  é sinônimo do tipo **int**. O **__int64** o tipo é sinônimo do tipo **long long**.

Para compatibilidade com versões anteriores, **_int8**, **_int16**, **_int32**, e **_int64** são sinônimos do **__int8** , **__int16**, **__int32**, e **__int64** , a menos que a opção de compilador [/Za \(desativar idioma extensões)](../build/reference/za-ze-disable-language-extensions.md) for especificado.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra que um int*xx* parâmetro será promovido **int**:

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

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Tipos fundamentais](../cpp/fundamental-types-cpp.md)<br/>
[Intervalos de tipos de dados](../cpp/data-type-ranges.md)<br/>
