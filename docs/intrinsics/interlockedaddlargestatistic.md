---
title: _InterlockedAddLargeStatistic
ms.date: 09/02/2019
f1_keywords:
- _InterlockedAddLargeStatistic
- _InterlockedAddLargeStatistic_cpp
helpviewer_keywords:
- _InterlockedAddLargeStatistic intrinsic
- InterlockedAddLargeStatistic intrinsic
ms.assetid: 2802e74b-bcee-46e4-b562-894908d44409
ms.openlocfilehash: de8c5b7dfd2462dddcb98324ebacc44c8148d85e
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70222093"
---
# <a name="_interlockedaddlargestatistic"></a>_InterlockedAddLargeStatistic

**Seção específica da Microsoft**

Executa uma adição interbloqueada na qual o primeiro operando é um valor de 64 bits.

## <a name="syntax"></a>Sintaxe

```C
long _InterlockedAddLargeStatistic(
   __int64 volatile * Addend,
   long Value
);
```

### <a name="parameters"></a>Parâmetros

*Adendo*\
[entrada, saída] Um ponteiro para o primeiro operando para a operação de adição. O valor apontado para é substituído pelo resultado da adição.

*Valor*\
no O segundo operando; valor a ser adicionado ao primeiro operando.

## <a name="return-value"></a>Valor retornado

O valor do segundo operando.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`_InterlockedAddLargeStatistic`|x86|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

O `_InterlockedAddLargeStatistic` intrínseco não é atômico, pois é implementado como duas instruções bloqueadas separadas. Uma leitura atômica de 64 bits que ocorre em outro thread durante a execução do intrínseco pode resultar em uma leitura de um valor inconsistente.

`_InterlockedAddLargeStatistic`comporta-se como uma barreira de leitura/gravação. Para obter mais informações, consulte [_ReadWriteBarrier](../intrinsics/readwritebarrier.md).

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[conflitos com o compilador x86](../build/x64-software-conventions.md#conflicts-with-the-x86-compiler)
