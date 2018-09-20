---
title: _InterlockedAddLargeStatistic | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- _InterlockedAddLargeStatistic
- _InterlockedAddLargeStatistic_cpp
dev_langs:
- C++
helpviewer_keywords:
- _InterlockedAddLargeStatistic intrinsic
- InterlockedAddLargeStatistic intrinsic
ms.assetid: 2802e74b-bcee-46e4-b562-894908d44409
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6698a58ec2a5363700f7751565f1dde8e25c2bcf
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46415974"
---
# <a name="interlockedaddlargestatistic"></a>_InterlockedAddLargeStatistic

**Seção específica da Microsoft**

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

*Value*<br/>
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

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[conflitos com o compilador x86](../build/conflicts-with-the-x86-compiler.md)