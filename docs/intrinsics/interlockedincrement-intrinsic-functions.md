---
title: _InterlockedIncrement funções intrínsecas
description: Funções intrínsecas do compilador C/C++ da Microsoft para incremento intercadeado.
ms.date: 09/03/2020
f1_keywords:
- _InterlockedIncrement_acq
- _InterlockedIncrement16_rel_cpp
- _InterlockedIncrement16_cpp
- _InterlockedIncrement64_rel
- _InterlockedIncrement_rel
- _InterlockedIncrement64_nf
- _InterlockedIncrement16_acq_cpp
- _InterlockedIncrement_rel_cpp
- _InterlockedIncrement64
- _InterlockedIncrement64_rel_cpp
- _InterlockedIncrement16_nf
- _InterlockedIncrement16_rel
- _InterlockedIncrement16_acq
- _InterlockedIncrement_nf
- _InterlockedIncrement_acq_cpp
- _InterlockedIncrement64_cpp
- _InterlockedIncrement64_acq_cpp
- _InterlockedIncrement
- _InterlockedIncrement_cpp
- _InterlockedIncrement64_acq
- _InterlockedIncrement16
helpviewer_keywords:
- _InterlockedIncrement64_rel intrinsic
- _InterlockedIncrement16_rel intrinsic
- InterlockedIncrement64_acq intrinsic
- _InterlockedIncrement16 intrinsic
- _InterlockedIncrement16_acq intrinsic
- _InterlockedIncrement_nf intrinsic
- _InterlockedIncrement_rel intrinsic
- _InterlockedIncrement64_nf intrinsic
- InterlockedIncrement_rel intrinsic
- InterlockedIncrement_acq intrinsic
- _InterlockedIncrement64_acq intrinsic
- _InterlockedIncrement16_nf intrinsic
- _InterlockedIncrement intrinsic
- _InterlockedIncrement64 intrinsic
- InterlockedIncrement64_rel intrinsic
- InterlockedIncrement64 intrinsic
- InterlockedIncrement16 intrinsic
- _InterlockedIncrement_acq intrinsic
- InterlockedIncrement intrinsic
ms.assetid: 37700615-f372-438b-bcef-d76e11839482
ms.openlocfilehash: 2148ae31f3eb03e398372db3bf15fc64e4857dd1
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89556315"
---
# <a name="_interlockedincrement-intrinsic-functions"></a>`_InterlockedIncrement` funções intrínsecas

Forneça suporte intrínseco ao compilador para a função [InterlockedIncrement](/windows/win32/api/winnt/nf-winnt-interlockedincrement) do Win32 SDK do Windows. As `_InterlockedIncrement` funções intrínsecas são **específicas da Microsoft**.

## <a name="syntax"></a>Sintaxe

```C
long _InterlockedIncrement(
   long volatile * lpAddend
);
long _InterlockedIncrement_acq(
   long volatile * lpAddend
);
long _InterlockedIncrement_rel(
   long volatile * lpAddend
);
long _InterlockedIncrement_nf(
   long volatile * lpAddend
);
short _InterlockedIncrement16(
   short volatile * lpAddend
);
short _InterlockedIncrement16_acq(
   short volatile * lpAddend
);
short _InterlockedIncrement16_rel(
   short volatile * lpAddend
);
short _InterlockedIncrement16_nf (
   short volatile * lpAddend
);
__int64 _InterlockedIncrement64(
   __int64 volatile * lpAddend
);
__int64 _InterlockedIncrement64_acq(
   __int64 volatile * lpAddend
);
__int64 _InterlockedIncrement64_rel(
   __int64 volatile * lpAddend
);
__int64 _InterlockedIncrement64_nf(
   __int64 volatile * lpAddend
);
```

### <a name="parameters"></a>Parâmetros

*lpAddend*\
[entrada, saída] Ponteiro para a variável a ser incrementada.

## <a name="return-value"></a>Retornar valor

O valor retornado é o valor incrementado resultante.

## <a name="requirements"></a>Requisitos

|Intrinsic|Arquitetura|Cabeçalho|
|---------------|------------------|------------|
|`_InterlockedIncrement`, `_InterlockedIncrement16`|x86, ARM, x64, ARM64|\<intrin.h>|
|`_InterlockedIncrement64`|ARM, x64, ARM64|\<intrin.h>|
|`_InterlockedIncrement_acq`, `_InterlockedIncrement_rel`, `_InterlockedIncrement_nf`, `_InterlockedIncrement16_acq`, `_InterlockedIncrement16_rel`, `_InterlockedIncrement16_nf`, `_InterlockedIncrement64_acq`, `_InterlockedIncrement64_rel`, `_InterlockedIncrement64_nf`|ARM, ARM64|\<intrin.h>|

## <a name="remarks"></a>Comentários

Há diversas variações em `_InterlockedIncrement` que têm base no tipo de dados que envolvem e se a semântica acquire ou release é usada.

Enquanto a função `_InterlockedIncrement` opera nos valores inteiros de 32 bits, `_InterlockedIncrement16` opera em valores inteiros de 16 bits `_InterlockedIncrement64` opera em valores inteiros de 64 bits.

Em plataformas ARM, use intrínsecos com os sufixos `_acq` e `_rel` para semântica de aquisição e liberação, como no início e no final de uma seção crítica. O intrínseco com um `_nf` sufixo ("sem limite") não funciona como uma barreira de memória.

A variável apontada para o parâmetro `lpAddend` deve estar alinhada em um limite de 32 bits; caso contrário, essa função falhará em sistemas de multiprocessor x86 e em qualquer sistema não x86. Para obter mais informações, consulte [alinhar](../cpp/align-cpp.md).

A função Win32 é declarada no `Wdm.h` ou `Ntddk.h`.

Essas rotinas somente estão disponíveis como intrínsecos.

## <a name="example"></a>Exemplo

Para obter uma amostra de como usar o `_InterlockedIncrement` , consulte [_InterlockedDecrement](../intrinsics/interlockeddecrement-intrinsic-functions.md).

## <a name="see-also"></a>Confira também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[Palavras-chave](../cpp/keywords-cpp.md)\
[conflitos com o compilador x86](../build/x64-software-conventions.md#conflicts-with-the-x86-compiler)
