---
title: _udiv64
ms.date: 04/17/2019
f1_keywords:
- _udiv64
helpviewer_keywords:
- _udiv64 intrinsic
ms.openlocfilehash: 73a29b180eeda49a9a25e9e568d25c7563234fad
ms.sourcegitcommit: 2ce88de75e7681220ae09a0ab13056f22f357a46
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2019
ms.locfileid: "59982445"
---
# <a name="udiv64"></a>_udiv64

O `_udiv64` intrínseco divide um inteiro sem sinal de 64 bits por um inteiro sem sinal de 32 bits. O valor de retorno contém o quociente e o intrínseco retorna o resto por meio de um parâmetro de ponteiro. `_udiv64` está **específico da Microsoft**.

## <a name="syntax"></a>Sintaxe

```C
unsigned int _udiv64(
   unsigned __int64 dividend,
   unsigned int divisor,
   unsigned int* remainder
);
```

### <a name="parameters"></a>Parâmetros

*dividend*<br/>
[in] O inteiro sem sinal de 64 bits para dividir.

*divisor*<br/>
[in] O inteiro sem sinal de 32 bits pelo qual dividir.

*remainder*<br/>
[out] O restante do inteiro sem sinal de 32 bits.

## <a name="return-value"></a>Valor retornado

Os 32 bits do quociente.

## <a name="remarks"></a>Comentários

O `_udiv64` divide intrínseco *dividendo* pela *divisor*. Ele armazena o restante no inteiro sem sinal de 32 bits apontado por *restante*e retorna os 32 bits do quociente.

O `_udiv64` intrínseca está disponível a partir de 2019 e RTM do Visual Studio.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|Cabeçalho|
|---------------|------------------|------------|
|`_udiv64`|x86, x64|\<immintrin.h>|

## <a name="see-also"></a>Consulte também

[_div64](div64.md) \
[Intrínsecos do compilador](compiler-intrinsics.md)
