---
title: _div64
ms.date: 04/17/2019
f1_keywords:
- _div64
helpviewer_keywords:
- _div64 intrinsic
ms.openlocfilehash: a221cc7cf0655a41873c6777aecd8a9b27131b74
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62264108"
---
# <a name="div64"></a>_div64

O `_div64` intrínseco divide um inteiro de 64 bits por um inteiro de 32 bits. O valor de retorno contém o quociente e o intrínseco retorna o resto por meio de um parâmetro de ponteiro. `_div64` está **específico da Microsoft**.

## <a name="syntax"></a>Sintaxe

```C
int _div64(
   __int64 dividend,
   int divisor,
   int* remainder
);
```

### <a name="parameters"></a>Parâmetros

*dividend* \
[in] O inteiro de 64 bits para dividir.

*divisor* \
[in] O inteiro de 32 bits pelo qual dividir.

*remainder* \
[out] Os bits de inteiro de 32 bits do resto.

## <a name="return-value"></a>Valor retornado

Os 32 bits do quociente.

## <a name="remarks"></a>Comentários

O `_div64` divide intrínseco *dividendo* pela *divisor*. Ele armazena o restante no inteiro de 32 bits apontado por *restante*e retorna os 32 bits do quociente.

O `_div64` intrínseca está disponível a partir de 2019 e RTM do Visual Studio.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|Cabeçalho|
|---------------|------------------|------------|
|`_div64`|x86, x64|\<immintrin.h>|

## <a name="see-also"></a>Consulte também

[_udiv64](udiv64.md) \
[Intrínsecos do compilador](compiler-intrinsics.md)
