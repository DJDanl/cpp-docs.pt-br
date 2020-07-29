---
title: _mm_cvtss_si64x
ms.date: 09/02/2019
f1_keywords:
- _mm_cvtss_si64x
helpviewer_keywords:
- cvtss2si intrinsic
- _mm_cvtss_si64x intrinsic
ms.assetid: c279aff2-ee29-4271-8829-3ec691bf7718
ms.openlocfilehash: bc6e33da5ac7b25727f6e24c3af6e6a926b29847
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230500"
---
# <a name="_mm_cvtss_si64x"></a>_mm_cvtss_si64x

**Específico da Microsoft**

Gera a versão de x64 estendida do número de ponto flutuante de conversão de precisão única escalar para instrução de inteiro de 64 bits ( `cvtss2si` ).

## <a name="syntax"></a>Sintaxe

```C
__int64 _mm_cvtss_si64x(
   __m128 value
);
```

### <a name="parameters"></a>parâmetros

*valor*\
no Uma **`__m128`** estrutura que contém valores de ponto flutuante.

## <a name="return-value"></a>Valor retornado

Um inteiro de 64 bits, o resultado da conversão do primeiro valor de ponto flutuante em um inteiro.

## <a name="requirements"></a>Requisitos

|Intrinsic|Arquitetura|
|---------------|------------------|
|`_mm_cvtss_si64x`|x64|

**Arquivo de cabeçalho** \<intrin.h>

## <a name="remarks"></a>Comentários

O primeiro elemento do valor da estrutura é convertido em um inteiro e retornado. Os bits de controle de arredondamento em MXCSR são usados para determinar o comportamento de arredondamento. O modo de arredondamento padrão é arredondado para mais próximo, arredondando para o número par se a parte decimal for 0,5. Como a **`__m128`** estrutura representa um registro de XMM, o intrínseco usa um valor do registro de XMM e o grava na memória do sistema.

Essa rotina só está disponível como função intrínseca.

## <a name="example"></a>Exemplo

```cpp
// _mm_cvtss_si64x.cpp
// processor: x64
#include <intrin.h>
#include <stdio.h>

#pragma intrinsic(_mm_cvtss_si64x)

int main()
{
    __m128 a;
    __int64 b = 54;

    // _mm_load_ps requires an aligned buffer.
    __declspec(align(16)) float af[4] =
                           { 101.25, 200.75, 300.5, 400.5 };

    // Load a with the floating point values.
    // The values will be copied to the XMM registers.
    a = _mm_load_ps(af);

    // Extract the first element of a and convert to an integer
    b = _mm_cvtss_si64x(a);

    printf_s("%I64d\n", b);
}
```

```Output
101
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[__m128d](../cpp/m128d.md)\
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
