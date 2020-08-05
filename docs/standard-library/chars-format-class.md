---
title: chars_format enum
ms.date: 08/03/2020
f1_keywords:
- charconv/std::chars_format
helpviewer_keywords:
- std::chars_format
ms.openlocfilehash: d7f95d9bd1522fa0896ccdbac6c1dbc770f2b272
ms.sourcegitcommit: 4eda68a0b3c23d8cefa56b7ba11583412459b32f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/04/2020
ms.locfileid: "87565930"
---
# <a name="chars_format-enum"></a>chars_format enum

Usado com a [\<charconv>](charconv.md) biblioteca para especificar o formato de ponto flutuante para conversões numéricas primitivas.

## <a name="syntax"></a>Syntax

```cpp
enum class chars_format {
    scientific = unspecified,
    fixed = unspecified,
    hex = unspecified,
    general = fixed | scientific
};
```

### <a name="members"></a>Membros

|Elemento|Descrição|
|-|-|
| `scientific` | Faz com que `from_chars()` o espere e analise um expoente. É como o `printf()` especificador de formato `'e'` , que formata para notação científica, como `"1.729e+01"` . |
| `fixed` | Faz com que `from_chars()` o não espere nem analise um expoente. É como o `printf()` especificador de formato `'f'` , que formata para ponto flutuante, como `"17.29"` .|
| `hex` | Faz com que `from_chars()` o número seja esperado em formato hexadecimal, mas sem uma entrelinha `0x` . |
| `general` | Faz com que `from_chars()` o aceite (mas não requeira) um expoente. Para `to_chars()` o, é como o `printf()` especificador de formato `'g'` , que alterna entre notação científica ou fixo. Leva em consideração o que será o expoente para que ele possa gerar uma saída de compactação razoavelmente. Por exemplo: `1e-5` resulta em `"1e-05"` , mas `1e-4` resulta em `"0.001"` . `1e5`resulta em `100000` , enquanto `1e6` resulta em `1e+06` . `1e0`produz `1` .|

## <a name="remarks"></a>Comentários

Para as funções de [from_chars](charconv-functions.md#from_chars) , essa enumeração descreve que tipo de entrada espera.
Para as funções de [to_chars](charconv-functions.md#to_chars) , ele descreve o tipo de saída a ser emitido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<charconv>

**Namespace:** std

/std: c++ 17 ou posterior, é necessário.

## <a name="see-also"></a>Confira também

[\<charconv>](../standard-library/charconv.md)  
[especificadores de formato printf ()](..\c-runtime-library\format-specification-syntax-printf-and-wprintf-functions.md)
