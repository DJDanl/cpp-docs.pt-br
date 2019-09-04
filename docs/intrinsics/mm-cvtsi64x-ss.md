---
title: _mm_cvtsi64x_ss
ms.date: 09/02/2019
f1_keywords:
- _mm_cvtsi64x_ss
helpviewer_keywords:
- cvtsi2ss instruction
- _mm_cvtsi64x_ss intrinsic
ms.assetid: 01e5d321-c18a-46fd-a6f6-324364514e1f
ms.openlocfilehash: 0e9bacc56f212e804467d1c6e0159a1749235976
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70217460"
---
# <a name="_mm_cvtsi64x_ss"></a>_mm_cvtsi64x_ss

**Seção específica da Microsoft**

Gera a versão do x64 estendida do inteiro de 64 bits para a instrução de valor de ponto flutuante de precisão`cvtsi2ss`única () escalar.

## <a name="syntax"></a>Sintaxe

```C
__m128 _mm_cvtsi64x_ss(
   __m128 a,
   __int64 b
);
```

### <a name="parameters"></a>Parâmetros

*um*\
no Uma `__m128` estrutura que contém quatro valores de ponto flutuante de precisão simples.

*b*\
no Um inteiro de 64 bits a ser convertido em um valor de ponto flutuante.

## <a name="return-value"></a>Valor retornado

Uma `__m128` estrutura cujo primeiro valor de ponto flutuante é o resultado da conversão. Os outros três valores são copiados inalterados de *um*.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`_mm_cvtsi64x_ss`|X64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

A `__m128` estrutura representa um registro XMM, portanto, o intrínseco permite que o valor *b* da memória do sistema seja movido para um registro XMM.

Essa rotina só está disponível como função intrínseca.

## <a name="example"></a>Exemplo

```cpp
// _mm_cvtsi64x_ss.cpp
// processor: x64

#include <intrin.h>
#include <stdio.h>

#pragma intrinsic(_mm_cvtsi64x_ss)

int main()
{
    __m128 a;
    __int64 b = 54;

    a.m128_f32[0] = 0;
    a.m128_f32[1] = 0;
    a.m128_f32[2] = 0;
    a.m128_f32[3] = 0;
    a = _mm_cvtsi64x_ss(a, b);

    printf_s( "%lf %lf %lf %lf\n",
              a.m128_f32[0], a.m128_f32[1],
              a.m128_f32[2], a.m128_f32[3] );
}
```

```Output
54.000000 0.000000 0.000000 0.000000
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[__m128](../cpp/m128.md)\
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
