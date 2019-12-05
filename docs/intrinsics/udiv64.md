---
title: _udiv64
ms.date: 09/02/2019
f1_keywords:
- _udiv64
helpviewer_keywords:
- _udiv64 intrinsic
ms.openlocfilehash: ddb46f33b0fccc1cedc2a704265b096ba715b506
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857990"
---
# <a name="_udiv64"></a>_udiv64

O `_udiv64` intrínseco divide um inteiro sem sinal de 64 bits por um inteiro sem sinal de 32 bits. O valor de retorno contém o quociente e o intrínseco retorna o resto por meio de um parâmetro de ponteiro. `_udiv64` é **específica da Microsoft**.

## <a name="syntax"></a>Sintaxe

```C
unsigned int _udiv64(
   unsigned __int64 dividend,
   unsigned int divisor,
   unsigned int* remainder
);
```

### <a name="parameters"></a>Parâmetros

*dividend*\
no O inteiro sem sinal de 64 bits a ser dividido.

*divisor*\
no O inteiro sem sinal de 32 bits para dividir por.

*remainder*\
fora O resto inteiro sem sinal de 32 bits.

## <a name="return-value"></a>Valor retornado

Os 32 bits do quociente.

## <a name="remarks"></a>Comentários

O comparador `_udiv64` divide *dividendo* por *divisor*. Ele armazena o restante no número inteiro sem sinal de 32 bits apontado por *resto*e retorna os 32 bits do quociente.

O `_udiv64` intrínseco está disponível a partir do Visual Studio 2019 RTM.

## <a name="requirements"></a>Requisitos do

|Intrinsic|Arquitetura|Cabeçalho|
|---------------|------------------|------------|
|`_udiv64`|x86, x64|\<immintrin.h>|

## <a name="see-also"></a>Consulte também

[_div64](div64.md) \
[Intrínsecos do compilador](compiler-intrinsics.md)
