---
title: _mm_stream_sd
ms.date: 09/02/2019
f1_keywords:
- _mm_stream_sd
helpviewer_keywords:
- _mm_stream_sd intrinsic
- movntsd instruction
ms.assetid: 2b4bea5e-e64e-45fa-9afc-88a2e4b82cfc
ms.openlocfilehash: ec639004884d022fe6a827c2ec31d3201ea04657
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214211"
---
# <a name="_mm_stream_sd"></a>_mm_stream_sd

**Específico da Microsoft**

Grava dados de 64 bits em um local de memória sem poluir os caches.

## <a name="syntax"></a>Sintaxe

```C
void _mm_stream_sd(
   double * Dest,
   __m128d Source
);
```

### <a name="parameters"></a>parâmetros

*Dest*\
fora Um ponteiro para o local onde os dados de origem serão gravados.

*Original*\
no Um valor de 128 bits que contém o **`double`** valor a ser gravado em seus últimos 64 bits.

## <a name="return-value"></a>Valor retornado

Nenhum.

## <a name="requirements"></a>Requisitos

|Intrinsic|Arquitetura|
|---------------|------------------|
|`_mm_stream_sd`|SSE4a|

**Arquivo de cabeçalho** \<intrin.h>

## <a name="remarks"></a>Comentários

O intrínseco gera a `movntsd` instrução. Para determinar o suporte de hardware para essa instrução, chame o `__cpuid` intrínseco `InfoType=0x80000001` e verifique o bit 6 de `CPUInfo[2] (ECX)` . Esse bit será 1 se o hardware oferecer suporte a essa instrução e 0 caso contrário.

Se você executar o código que usa o `_mm_stream_sd` intrínseco em hardware que não oferece suporte à `movntsd` instrução, os resultados serão imprevisíveis.

## <a name="example"></a>Exemplo

```cpp
// Compile this sample with: /EHsc
#include <iostream>
#include <intrin.h>
using namespace std;

int main()
{
    __m128d vals;
    double d[2];

    d[0] = -1.;
    d[1] = -2.;
    vals.m128d_f64[0] = 0.;
    vals.m128d_f64[1] = 1.;
    _mm_stream_sd(&d[1], vals);
    cout << "d[0] = " << d[0] << ", d[1] = " << d[1] << endl;
}
```

```Output
d[0] = -1, d[1] = 1
```

**FINAL específico da Microsoft**

Partes de Copyright 2007 da Advanced Micro Devices, Inc. Todos os direitos reservados. Reproduzida com a permissão da Advanced Micro Devices, Inc.

## <a name="see-also"></a>Confira também

[_mm_stream_ss](../intrinsics/mm-stream-ss.md)\
[_mm_store_sd](https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_store_sd)\
[_mm_sfence](https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_sfence)\
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
