---
title: _ReadBarrier
ms.date: 11/04/2016
f1_keywords:
- _ReadBarrier
helpviewer_keywords:
- _ReadBarrier intrinsic
ms.assetid: f9e54a92-61bc-4f55-8195-b8932065a796
ms.openlocfilehash: f31293b2bef0304bcdc58f0a8dbfce0436df9843
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62396543"
---
# <a name="readbarrier"></a>_ReadBarrier

**Seção específica da Microsoft**

Limita as otimizações do compilador que podem reordenar operações de acesso à memória no ponto da chamada.

> [!CAUTION]
>  Os tipos intrínsecos de compilador `_ReadBarrier`, `_WriteBarrier` e `_ReadWriteBarrier` e a macro `MemoryBarrier` foram todos preteridos e não devem ser usados. Para comunicação entre threads, use mecanismos como [atomic_thread_fence](../standard-library/atomic-functions.md#atomic_thread_fence) e [std:: Atomic\<T >](../standard-library/atomic.md) que estão definidos na [ C++ debibliotecapadrão](../standard-library/cpp-standard-library-reference.md). Para obter acesso de hardware, use o [/volatile: ISO](../build/reference/volatile-volatile-keyword-interpretation.md) opção de compilador junto com o [volátil](../cpp/volatile-cpp.md) palavra-chave.

## <a name="syntax"></a>Sintaxe

```
void _ReadBarrier(void);
```

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`_ReadBarrier`|x86, x64|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

O intrínseco `_ReadBarrier` limita as otimizações do compilador que podem remover e reordenar operações de acesso à memória através do ponto da chamada.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)