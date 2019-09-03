---
title: _mm_stream_sd
ms.date: 09/02/2019
f1_keywords:
- _mm_stream_sd
helpviewer_keywords:
- _mm_stream_sd intrinsic
- movntsd instruction
ms.assetid: 2b4bea5e-e64e-45fa-9afc-88a2e4b82cfc
ms.openlocfilehash: 7f0c6457cc0806a0f1764300cffa1c9878b8a600
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70217367"
---
# <a name="_mm_stream_sd"></a>_mm_stream_sd

**Seção específica da Microsoft**

Grava dados de 64 bits em um local de memória sem poluir os caches.

## <a name="syntax"></a>Sintaxe

```C
void _mm_stream_sd(
   double * Dest,
   __m128d Source
);
```

### <a name="parameters"></a>Parâmetros

*Dest*\
fora Um ponteiro para o local onde os dados de origem serão gravados.

*Source*\
no Um valor de 128 bits que contém `double` o valor a ser gravado em seus últimos 64 bits.

## <a name="return-value"></a>Valor retornado

nenhuma.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`_mm_stream_sd`|SSE4a|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

O intrínseco gera a `movntsd` instrução. Para determinar o suporte de hardware para essa instrução, `__cpuid` chame o `InfoType=0x80000001` intrínseco e verifique o bit `CPUInfo[2] (ECX)`6 de. Esse bit será 1 se o hardware oferecer suporte a essa instrução e 0 caso contrário.

Se você executar o código que usa `_mm_stream_sd` o intrínseco em hardware que não oferece `movntsd` suporte à instrução, os resultados serão imprevisíveis.

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

**Fim da seção específica da Microsoft**

Partes de Copyright 2007 da Advanced Micro Devices, Inc. Todos os direitos reservados. Reproduzida com a permissão da Advanced Micro Devices, Inc.

## <a name="see-also"></a>Consulte também

[_mm_stream_ss](../intrinsics/mm-stream-ss.md)\
[_mm_store_sd](https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_store_sd)\
[_mm_sfence](https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_sfence)\
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
