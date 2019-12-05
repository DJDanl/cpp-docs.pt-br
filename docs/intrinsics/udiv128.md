---
title: _udiv128
ms.date: 04/17/2019
f1_keywords:
- _udiv128
helpviewer_keywords:
- _udiv128 intrinsic
ms.openlocfilehash: 5e8cc9ca3dbf19a04d07edb1d73df84f2e29a5c3
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857977"
---
# <a name="_udiv128"></a>_udiv128

O `_udiv128` intrínseco divide um inteiro sem sinal de 128 bits por um inteiro sem sinal de 64 bits. O valor de retorno contém o quociente e o intrínseco retorna o resto por meio de um parâmetro de ponteiro. `_udiv128` é **específica da Microsoft**.

## <a name="syntax"></a>Sintaxe

```C
unsigned __int64 _udiv128(
   unsigned __int64 highDividend,
   unsigned __int64 lowDividend,
   unsigned __int64 divisor,
   unsigned __int64 *remainder
);
```

### <a name="parameters"></a>Parâmetros

*highDividend* \
no Os bits de 64 altos do dividendo.

*lowDividend* \
no Os bits de 64 baixos do dividendo.

*divisor* \
no O inteiro de 64 bits pelo qual dividir.

*remainder* \
fora Os bits inteiros de 64 bits do resto.

## <a name="return-value"></a>Valor retornado

Os 64 bits do quociente.

## <a name="remarks"></a>Comentários

Passe os 64 bits superiores do dividendo de 128 bits em *highDividend*e os 64 bits inferiores em *lowDividend*. O intrínseco divide esse valor por *divisor*. Ele armazena o restante no número inteiro sem sinal de 64 bits apontado por *resto*e retorna os 64 bits do quociente.

O `_udiv128` intrínseco está disponível a partir do Visual Studio 2019 RTM.

## <a name="requirements"></a>Requisitos do

|Intrinsic|Arquitetura|Cabeçalho|
|---------------|------------------|------------|
|`_udiv128`|x64|\<immintrin.h>|

## <a name="see-also"></a>Consulte também

[_div128](div128.md) \
[Intrínsecos do compilador](compiler-intrinsics.md)
