---
title: __shiftleft128
ms.date: 11/04/2016
f1_keywords:
- __shiftleft128
helpviewer_keywords:
- __shiftleft128 intrinsic
ms.assetid: 557b846a-8fb0-469d-91ac-1b1fad80dc2a
ms.openlocfilehash: 4fb1f9e65210ca9f9e38afd6fc13e01c7eb8f045
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51325543"
---
# <a name="shiftleft128"></a>__shiftleft128

**Seção específica da Microsoft**

Desloca uma quantidade de 128 bits, representada como duas quantidades de 64 bits `LowPart` e `HighPart`, para a esquerda por um número de bits especificado pelo `Shift` e retorna os 64 bits altos do resultado.

## <a name="syntax"></a>Sintaxe

```
unsigned __int64 __shiftleft128(
   unsigned __int64 LowPart,
   unsigned __int64 HighPart,
   unsigned char Shift
);
```

#### <a name="parameters"></a>Parâmetros

*Dinâmaico*<br/>
[in] Os 64 bits baixos da quantidade de 128 bits a deslocar.

*HighPart*<br/>
[in] Os 64 bits altos da quantidade de 128 bits a deslocar.

*Shift*<br/>
[in] O número de bits a deslocar.

## <a name="return-value"></a>Valor de retorno

64 bits altos do resultado.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__shiftleft128`|X64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

O valor `Shift` é sempre módulo 64 para que, por exemplo, se você chamar, `__shiftleft128(1, 0, 64)`, a função deslocará os bits baixos `0` para a esquerda e retornará uma parte alta de `0` e não `1` como podia ser esperado.

## <a name="example"></a>Exemplo

```
// shiftleft128.c
// processor: IPF, x64
#include <stdio.h>
#include <intrin.h>

#pragma intrinsic (__shiftleft128, __shiftright128)

int main()
{
    unsigned __int64 i = 0x1I64;
    unsigned __int64 j = 0x10I64;
    unsigned __int64 ResultLowPart;
    unsigned __int64 ResultHighPart;

    ResultLowPart = i << 1;
    ResultHighPart = __shiftleft128(i, j, 1);

    // concatenate the low and high parts padded with 0's
    // to display correct hexadecimal 128 bit values
    printf_s("0x%02I64x%016I64x << 1 = 0x%02I64x%016I64x\n",
             j, i, ResultHighPart, ResultLowPart);

    ResultHighPart = j >> 1;
    ResultLowPart = __shiftright128(i, j, 1);

    printf_s("0x%02I64x%016I64x >> 1 = 0x%02I64x%016I64x\n",
             j, i, ResultHighPart, ResultLowPart);
}
```

```Output
0x100000000000000001 << 1 = 0x200000000000000002
0x100000000000000001 >> 1 = 0x080000000000000000
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[__shiftright128](../intrinsics/shiftright128.md)<br/>
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)