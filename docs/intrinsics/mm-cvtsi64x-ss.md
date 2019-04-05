---
title: _mm_cvtsi64x_ss
ms.date: 11/04/2016
f1_keywords:
- _mm_cvtsi64x_ss
helpviewer_keywords:
- cvtsi2ss instruction
- _mm_cvtsi64x_ss intrinsic
ms.assetid: 01e5d321-c18a-46fd-a6f6-324364514e1f
ms.openlocfilehash: 3ba9dc56cbb027e8cf9f31d293b3f96908aff5e4
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59039774"
---
# <a name="mmcvtsi64xss"></a>_mm_cvtsi64x_ss

**Específico da Microsoft**

Gera o x64 estendido a versão do inteiro convertido de 64 bits para o valor de ponto flutuante de precisão única escalares (`cvtsi2ss`) instrução.

## <a name="syntax"></a>Sintaxe

```
__m128 _mm_cvtsi64x_ss(
   __m128 a,
   __int64 b
);
```

#### <a name="parameters"></a>Parâmetros

*a*<br/>
[in] Um `__m128` estrutura que contém quatro valores de ponto flutuante de precisão simples.

*b*<br/>
[in] Um inteiro de 64 bits a ser convertido em um valor de ponto flutuante.

## <a name="return-value"></a>Valor de retorno

Um `__m128` estrutura cujo primeiro valor de ponto flutuante é o resultado da conversão. Os três valores são copiados sem alterações de `a`.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`_mm_cvtsi64x_ss`|X64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

O `__m128` estrutura representa um registro de registros de MMX, portanto, esse intrínseco permite que o valor `b` da memória do sistema a ser movido para um XMM registrar.

Essa rotina só está disponível como função intrínseca.

## <a name="example"></a>Exemplo

```
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

**FIM de Específico da Microsoft**

## <a name="see-also"></a>Consulte também

[__m128](../cpp/m128.md)<br/>
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)