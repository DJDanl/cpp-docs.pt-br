---
title: _InterlockedAddLargeStatistic
ms.date: 11/04/2016
f1_keywords:
- _InterlockedAddLargeStatistic
- _InterlockedAddLargeStatistic_cpp
helpviewer_keywords:
- _InterlockedAddLargeStatistic intrinsic
- InterlockedAddLargeStatistic intrinsic
ms.assetid: 2802e74b-bcee-46e4-b562-894908d44409
ms.openlocfilehash: 6f9d599a8d7668c6c8a37846275e8338002589d1
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59033408"
---
# <a name="interlockedaddlargestatistic"></a>_InterlockedAddLargeStatistic

**Específico da Microsoft**

Executa uma adição sincronizada em que o primeiro operando é um valor de 64 bits.

## <a name="syntax"></a>Sintaxe

```
long _InterlockedAddLargeStatistic(
   __int64 volatile * Addend,
   long Value
);
```

#### <a name="parameters"></a>Parâmetros

*Adendo*<br/>
[no, out] Um ponteiro para o primeiro operando com a operação de adição. O valor apontado é substituído pelo resultado da adição.

*Valor*<br/>
[in] O segundo operando; valor a ser adicionado para o primeiro operando.

## <a name="return-value"></a>Valor de retorno

O valor do segundo operando.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`_InterlockedAddLargeStatistic`|x86|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

Esse intrínseco não é atômico porque ele é implementado como dois separados instruções bloqueadas. Uma leitura de 64-bit atômica que ocorre em outro thread durante a execução desse intrínseco pode resultar em um valor inconsistente que está sendo lido.

Essa função se comporta como uma barreira de leitura / gravação. Para obter mais informações, consulte [readwritebarrier](../intrinsics/readwritebarrier.md).

**FIM de Específico da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[Conflitos com o compilador x86](../build/x64-software-conventions.md#conflicts-with-the-x86-compiler)