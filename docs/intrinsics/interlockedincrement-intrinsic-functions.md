---
title: Funções intrínsecas _InterlockedIncrement
ms.date: 12/17/2018
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
ms.openlocfilehash: 91e9c6dac1b6f13997bb7e4f2727a743a9177083
ms.sourcegitcommit: c1f646c8b72f330fa8cf5ddb0f8f261ba10d16f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2019
ms.locfileid: "58328604"
---
# <a name="interlockedincrement-intrinsic-functions"></a>Funções intrínsecas _InterlockedIncrement

**Seção específica da Microsoft**

Fornece suporte intrínseco ao compilador para o SDK do Windows Win32 [InterlockedIncrement](/windows/desktop/api/winnt/nf-winnt-interlockedincrement) função.

## <a name="syntax"></a>Sintaxe

```
long _InterlockedIncrement(
   long * lpAddend
);
long _InterlockedIncrement_acq(
   long * lpAddend
);
long _InterlockedIncrement_rel(
   long * lpAddend
);
long _InterlockedIncrement_nf(
   long * lpAddend
);
short _InterlockedIncrement16(
   short * lpAddend
);
short _InterlockedIncrement16_acq(
   short * lpAddend
);
short _InterlockedIncrement16_rel(
   short * lpAddend
);
short _InterlockedIncrement16_nf (
   short * lpAddend
);
__int64 _InterlockedIncrement64(
   __int64 * lpAddend
);
__int64 _InterlockedIncrement64_acq(
   __int64 * lpAddend
);
__int64 _InterlockedIncrement64_rel(
   __int64 * lpAddend
);
__int64 _InterlockedIncrement64_nf(
   __int64 * lpAddend
);
```

#### <a name="parameters"></a>Parâmetros

*lpAddend*<br/>
[no, out] Ponteiro para a variável a ser incrementado.

## <a name="return-value"></a>Valor de retorno

O valor retornado é o valor incrementado resultante.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|Cabeçalho|
|---------------|------------------|------------|
|`_InterlockedIncrement`, `_InterlockedIncrement16`, `_InterlockedIncrement64`|x86, ARM, x64|\<intrin.h>|
|`_InterlockedIncrement_acq`, `_InterlockedIncrement_rel`, `_InterlockedIncrement_nf`, `_InterlockedIncrement16_acq`, `_InterlockedIncrement16_rel`, `_InterlockedIncrement16_nf`, `_InterlockedIncrement64_acq`, `_InterlockedIncrement64_rel`, `_InterlockedIncrement64_nf`|ARM|\<intrin.h>|

## <a name="remarks"></a>Comentários

Há diversas variações em `_InterlockedIncrement` que têm base no tipo de dados que envolvem e se a semântica acquire ou release é usada.

Enquanto a função `_InterlockedIncrement` opera nos valores inteiros de 32 bits, `_InterlockedIncrement16` opera em valores inteiros de 16 bits `_InterlockedIncrement64` opera em valores inteiros de 64 bits.

Em plataformas ARM, use intrínsecos com os sufixos `_acq` e `_rel` para semântica de aquisição e liberação, como no início e no final de uma seção crítica. O intrínseco com um sufixo `_nf` ("no fence") não funciona como uma barreira de memória.

A variável apontada para o parâmetro `lpAddend` deve estar alinhada em um limite de 32 bits; caso contrário, essa função falhará em sistemas de multiprocessor x86 e em qualquer sistema não x86. Para obter mais informações, consulte [alinhar](../cpp/align-cpp.md).

A função Win32 é declarada no `Wdm.h` ou `Ntddk.h`.

Essas rotinas somente estão disponíveis como intrínsecos.

## <a name="example"></a>Exemplo

Para obter um exemplo de como usar `_InterlockedIncrement`, consulte [interlockeddecrement](../intrinsics/interlockeddecrement-intrinsic-functions.md).

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[conflitos com o compilador x86](../build/x64-software-conventions.md#conflicts-with-the-x86-compiler)