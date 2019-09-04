---
title: _mm_cvtss_si64x
ms.date: 09/02/2019
f1_keywords:
- _mm_cvtss_si64x
helpviewer_keywords:
- cvtss2si intrinsic
- _mm_cvtss_si64x intrinsic
ms.assetid: c279aff2-ee29-4271-8829-3ec691bf7718
ms.openlocfilehash: 6079ed7846a35ff16355f0341d63430f9846057f
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70217429"
---
# <a name="_mm_cvtss_si64x"></a>_mm_cvtss_si64x

**Seção específica da Microsoft**

Gera a versão de x64 estendida do número de ponto flutuante de conversão de precisão única escalar para instrução`cvtss2si`de inteiro de 64 bits ().

## <a name="syntax"></a>Sintaxe

```C
__int64 _mm_cvtss_si64x(
   __m128 value
);
```

### <a name="parameters"></a>Parâmetros

*value*\
no Uma `__m128` estrutura que contém valores de ponto flutuante.

## <a name="return-value"></a>Valor retornado

Um inteiro de 64 bits, o resultado da conversão do primeiro valor de ponto flutuante em um inteiro.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`_mm_cvtss_si64x`|X64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

O primeiro elemento do valor da estrutura é convertido em um inteiro e retornado. Os bits de controle de arredondamento em MXCSR são usados para determinar o comportamento de arredondamento. O modo de arredondamento padrão é arredondado para mais próximo, arredondando para o número par se a parte decimal for 0,5. Como a `__m128` estrutura representa um registro de XMM, o intrínseco usa um valor do registro de XMM e o grava na memória do sistema.

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

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[__m128d](../cpp/m128d.md)\
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
