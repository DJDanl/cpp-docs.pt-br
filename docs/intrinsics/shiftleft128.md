---
title: __shiftleft128
ms.date: 09/02/2019
f1_keywords:
- __shiftleft128
helpviewer_keywords:
- __shiftleft128 intrinsic
ms.assetid: 557b846a-8fb0-469d-91ac-1b1fad80dc2a
ms.openlocfilehash: 5da9ac81cedbdd24e10eb438892f88510c32ca24
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70218010"
---
# <a name="__shiftleft128"></a>__shiftleft128

**Seção específica da Microsoft**

Desloca uma quantidade de 128 bits, representada como duas quantidades de 64 bits `LowPart` e `HighPart`, para a esquerda por um número de bits especificado pelo `Shift` e retorna os 64 bits altos do resultado.

## <a name="syntax"></a>Sintaxe

```C
unsigned __int64 __shiftleft128(
   unsigned __int64 LowPart,
   unsigned __int64 HighPart,
   unsigned char Shift
);
```

### <a name="parameters"></a>Parâmetros

*LowPart*\
no Os poucos 64 bits da quantidade de 128 bits a serem deslocados.

*HighPart*\
no Os bits de 64 altos da quantidade de 128 bits a serem deslocados.

*Alternância*\
no O número de bits a ser deslocado.

## <a name="return-value"></a>Valor retornado

64 bits altos do resultado.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__shiftleft128`|X64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

O valor de *deslocamento* sempre é o módulo 64, de modo que, por exemplo `__shiftleft128(1, 0, 64)`, se você chamar, a função mudará os bits de parte `0` inferior para a `0` esquerda e retornará uma parte superior de, e não `1` como seria esperado.

## <a name="example"></a>Exemplo

```C
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

[__shiftright128](../intrinsics/shiftright128.md)\
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
