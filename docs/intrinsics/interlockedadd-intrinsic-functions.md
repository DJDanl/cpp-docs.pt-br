---
title: _InterlockedAdd funções intrínsecas
ms.date: 09/02/2019
f1_keywords:
- _InterlockedAdd64_acq_cpp
- _InterlockedAdd64_acq
- _InterlockedAdd_acq
- _InterlockedAdd_nf
- _InterlockedAdd64_rel
- _InterlockedAdd64
- _InterlockedAdd_cpp
- _InterlockedAdd_rel_cpp
- _InterlockedAdd_rel
- _InterlockedAdd64_rel_cpp
- _InterlockedAdd64_cpp
- _InterlockedAdd_acq_cpp
- _InterlockedAdd64_nf
- _InterlockedAdd
helpviewer_keywords:
- _InterlockedAdd_nf intrinsic
- _InterlockedAdd_rel intrinsic
- _InterlockedAdd intrinsic
- _InterlockedAdd64 intrinsic
- _InterlockedAdd64_acq intrinsic
- _InterlockedAdd64_nf intrinsic
- _InterlockedAdd_acq intrinsic
- _InterlockedAdd64_rel intrinsic
ms.assetid: 3d319603-ea9c-4fdd-ae61-e52430ccc3b1
ms.openlocfilehash: efe1444273f17c8f0544d2c51b98923169032e61
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90683891"
---
# <a name="_interlockedadd-intrinsic-functions"></a>_InterlockedAdd funções intrínsecas

**Específico da Microsoft**

Essas funções executam uma adição atômica, que garante que a operação seja concluída com êxito quando mais de um thread tiver acesso a uma variável compartilhada.

## <a name="syntax"></a>Sintaxe

```C
long _InterlockedAdd(
   long volatile * Addend,
   long Value
);
long _InterlockedAdd_acq(
   long volatile * Addend,
   long Value
);
long _InterlockedAdd_nf(
   long volatile * Addend,
   long Value
);
long _InterlockedAdd_rel(
   long volatile * Addend,
   long Value
);
__int64 _InterlockedAdd64(
   __int64 volatile * Addend,
   __int64 Value
);
__int64 _InterlockedAdd64_acq(
   __int64 volatile * Addend,
   __int64 Value
);
__int64 _InterlockedAdd64_nf (
   __int64 volatile * Addend,
   __int64 Value
);
__int64 _InterlockedAdd64_rel(
   __int64 volatile * Addend,
   __int64 Value
);
```

### <a name="parameters"></a>Parâmetros

*Adendo*\
[entrada, saída] Ponteiro para o número inteiro a ser adicionado; substituído pelo resultado da adição.

*Value*\
no O valor a ser adicionado.

## <a name="return-value"></a>Valor retornado

Ambas as funções retornam o resultado da adição.

## <a name="requirements"></a>Requisitos

|Intrinsic|Arquitetura|
|---------------|------------------|
|`_InterlockedAdd`|ARM, ARM64|
|`_InterlockedAdd_acq`|ARM, ARM64|
|`_InterlockedAdd_nf`|ARM, ARM64|
|`_InterlockedAdd_rel`|ARM, ARM64|
|`_InterlockedAdd64`|ARM, ARM64|
|`_InterlockedAdd64_acq`|ARM, ARM64|
|`_InterlockedAdd64_nf`|ARM, ARM64|
|`_InterlockedAdd64_rel`|ARM, ARM64|

**Arquivo de cabeçalho** \<intrin.h>

## <a name="remarks"></a>Comentários

As versões dessas funções com os sufixos `_acq` ou `_rel` executam uma adição sincronizada após a semântica de aquisição ou liberação. A *semântica de aquisição* significa que o resultado da operação é disponibilizado para todos os threads e processadores antes de qualquer leitura e gravação de memória posterior. A semântica de aquisição é útil ao inserir uma seção crítica. A *semântica de liberação* significa que todas as leituras e gravações de memória são forçadas a se tornarem visíveis para todos os threads e processadores antes que o resultado da operação seja tornado visível. A liberação é útil ao sair de uma seção crítica. Os intrínsecos com um `_nf` sufixo ("sem limite") não agem como uma barreira de memória.

Essas rotinas somente estão disponíveis como intrínsecos.

## <a name="examples"></a>Exemplos

```cpp
// interlockedadd.cpp
// Compile with: /Oi /EHsc
// processor: ARM
#include <stdio.h>
#include <intrin.h>

#pragma intrinsic(_InterlockedAdd)

int main()
{
        long data1 = 0xFF00FF00;
        long data2 = 0x00FF0000;
        long retval;
        retval = _InterlockedAdd(&data1, data2);
        printf("0x%x 0x%x 0x%x", data1, data2, retval);
}
```

## <a name="output"></a>Saída

```Output
0xffffff00 0xff0000 0xffffff00
```

```cpp
// interlockedadd64.cpp
// compile with: /Oi /EHsc
// processor: ARM
#include <iostream>
#include <intrin.h>
using namespace std;

#pragma intrinsic(_InterlockedAdd64)

int main()
{
        __int64 data1 = 0x0000FF0000000000;
        __int64 data2 = 0x00FF0000FFFFFFFF;
        __int64 retval;
        cout << hex << data1 << " + " << data2 << " = " ;
        retval = _InterlockedAdd64(&data1, data2);
        cout << data1 << endl;
        cout << "Return value: " << retval << endl;
}
```

## <a name="output"></a>Saída

```Output
ff0000000000 + ff0000ffffffff = ffff00ffffffff
Return value: ffff00ffffffff
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[conflitos com o compilador x86](../build/x64-software-conventions.md#conflicts-with-the-x86-compiler)
