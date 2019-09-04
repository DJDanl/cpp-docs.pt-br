---
title: _WriteBarrier
ms.date: 09/02/2019
f1_keywords:
- _WriteBarrier
helpviewer_keywords:
- WriteBarrier intrinsic
- _WriteBarrier intrinsic
ms.assetid: a5ffdad9-0ca1-4eb7-b2f3-0f092c4bf4b5
ms.openlocfilehash: a41f4c6c5cdd6b72e76a596622912e88fbd03f34
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70219319"
---
# <a name="_writebarrier"></a>_WriteBarrier

**Seção específica da Microsoft**

Limita as otimizações do compilador que podem reordenar operações de acesso à memória no ponto da chamada.

> [!CAUTION]
> Os tipos intrínsecos de compilador `_ReadBarrier`, `_WriteBarrier` e `_ReadWriteBarrier` e a macro `MemoryBarrier` foram todos preteridos e não devem ser usados. Para comunicação entre threads, use mecanismos como [atomic_thread_fence](../standard-library/atomic-functions.md#atomic_thread_fence) e [std:\<: Atomic T >](../standard-library/atomic.md), que são definidos na [ C++ biblioteca padrão](../standard-library/cpp-standard-library-reference.md). Para acesso ao hardware, use a opção de compilador [/volatile: ISO](../build/reference/volatile-volatile-keyword-interpretation.md) junto com a palavra-chave [volatile](../cpp/volatile-cpp.md) .

## <a name="syntax"></a>Sintaxe

```C
void _WriteBarrier(void);
```

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`_WriteBarrier`|x86, x64|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

O intrínseco `_WriteBarrier` limita as otimizações do compilador que podem remover e reordenar operações de acesso à memória através do ponto da chamada.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[_ReadBarrier](../intrinsics/readbarrier.md)\
[_ReadWriteBarrier](../intrinsics/readwritebarrier.md)\
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[Palavras-chave](../cpp/keywords-cpp.md)
