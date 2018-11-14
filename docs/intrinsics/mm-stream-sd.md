---
title: _mm_stream_sd
ms.date: 11/04/2016
f1_keywords:
- _mm_stream_sd
helpviewer_keywords:
- _mm_stream_sd intrinsic
- movntsd instruction
ms.assetid: 2b4bea5e-e64e-45fa-9afc-88a2e4b82cfc
ms.openlocfilehash: cf57d485ab3dd268d217b2ef44ff53bcec3d2e63
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51518132"
---
# <a name="mmstreamsd"></a>_mm_stream_sd

**Seção específica da Microsoft**

Grava dados de 64 bits em um local de memória sem poluir os caches.

## <a name="syntax"></a>Sintaxe

```
void _mm_stream_sd(
   double * Dest,
   __m128d Source
);
```

#### <a name="parameters"></a>Parâmetros

*dest*<br/>
[out] Um ponteiro para o local onde os dados de origem serão gravados.

*Source*<br/>
[in] Um valor de 128 bits que contém o `double` valor a ser gravado em sua parte inferior de 64 bits...

## <a name="return-value"></a>Valor de retorno

nenhuma.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`_mm_stream_sd`|SSE4a|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

Esse intrínseco gera o `movntsd` instrução. Para determinar o suporte de hardware para essa instrução, chame o `__cpuid` intrínseco com `InfoType=0x80000001` e marque 6 bits de `CPUInfo[2] (ECX)`. Esse bit for 1, se o hardware dá suporte a essa instrução e 0 caso contrário.

Se você executar o código que usa o `_mm_stream_sd` intrínseco no hardware que não oferece suporte a `movntsd` instrução, os resultados serão imprevisíveis.

## <a name="example"></a>Exemplo

```
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

Copyright 2007 por dispositivos Micro avançada, Inc. Todos os direitos reservados. Reproduzido com a permissão do Advanced Micro dispositivos, Inc.

## <a name="see-also"></a>Consulte também

[_mm_stream_ss](../intrinsics/mm-stream-ss.md)<br/>
[_mm_store_sd](https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_store_sd)<br/>
[_mm_sfence](https://software.intel.com/sites/landingpage/IntrinsicsGuide/#text=_mm_sfence)<br/>
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)