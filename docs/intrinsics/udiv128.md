---
title: _udiv128
ms.date: 04/17/2019
f1_keywords:
- _udiv128
helpviewer_keywords:
- _udiv128 intrinsic
ms.openlocfilehash: 0e66bbe978199f47134aa288bdd2bac4eb3e332a
ms.sourcegitcommit: 2ce88de75e7681220ae09a0ab13056f22f357a46
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2019
ms.locfileid: "59982435"
---
# <a name="udiv128"></a>_udiv128

O `_udiv128` intrínseco divide um inteiro sem sinal de 128 bits por um inteiro sem sinal de 64 bits. O valor de retorno contém o quociente e o intrínseco retorna o resto por meio de um parâmetro de ponteiro. `_udiv128` está **específico da Microsoft**.

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
[in] Os 64 bits altos do dividendo.

*lowDividend* \
[in] Os 64 bits baixos do dividendo.

*divisor* \
[in] O inteiro de 64 bits pelo qual dividir.

*remainder* \
[out] Os bits de inteiro de 64 bits do resto.

## <a name="return-value"></a>Valor retornado

Os 64 bits do quociente.

## <a name="remarks"></a>Comentários

Passar de 64 bits superiores do dividendo 128 bits na *highDividend*e 64 bits inferiores na *lowDividend*. O intrínseco divide esse valor por *divisor*. Ele armazena o restante no inteiro sem sinal de 64 bits apontado por *restante*e retorna os 64 bits do quociente.

O `_udiv128` intrínseca está disponível a partir de 2019 e RTM do Visual Studio.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|Cabeçalho|
|---------------|------------------|------------|
|`_udiv128`|X64|\<immintrin.h>|

## <a name="see-also"></a>Consulte também

[_div128](div128.md) \
[Intrínsecos do compilador](compiler-intrinsics.md)
