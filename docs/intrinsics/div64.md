---
title: _div64
ms.date: 09/02/2019
f1_keywords:
- _div64
helpviewer_keywords:
- _div64 intrinsic
ms.openlocfilehash: 1d05c5d6e25540a5de1b2f8231697c9a738759ce
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216770"
---
# <a name="_div64"></a>_div64

O `_div64` intrínseco divide um inteiro de 64 bits por um inteiro de 32 bits. O valor de retorno contém o quociente e o intrínseco retorna o resto por meio de um parâmetro de ponteiro. `_div64`é **específico da Microsoft**.

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
no O inteiro de 64 bits a ser dividido.

*divisor* \
no O inteiro de 32 bits pelo qual dividir.

*remainder* \
fora Os bits inteiros de 32 bits do resto.

## <a name="return-value"></a>Valor retornado

Os 32 bits do quociente.

## <a name="remarks"></a>Comentários

O `_div64` intrínseco divide *dividendo* por *divisor*. Ele armazena o restante no número inteiro de 32 bits apontado por *resto*e retorna os 32 bits do quociente.

O `_div64` intrínseco está disponível a partir do Visual Studio 2019 RTM.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|Cabeçalho|
|---------------|------------------|------------|
|`_div64`|x86, x64|\<immintrin.h>|

## <a name="see-also"></a>Consulte também

[_udiv64](udiv64.md) \
[Intrínsecos do compilador](compiler-intrinsics.md)
