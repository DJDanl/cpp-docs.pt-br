---
title: Readwritebarrier | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- _ReadWriteBarrier
dev_langs:
- C++
helpviewer_keywords:
- ReadWriteBarrier intrinsic
- _ReadWriteBarrier intrinsic
ms.assetid: dd9f58b5-8bb6-494e-bb0f-9fe184f3908d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 450f8d94510212a430fb5d5a6b4ece061fa8a59c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33333532"
---
# <a name="readwritebarrier"></a>_ReadWriteBarrier
**Seção específica da Microsoft**  
  
 Limita as otimizações do compilador que podem reordenar os acessos à memória através do ponto da chamada.  
  
> [!CAUTION]
>  Os tipos intrínsecos de compilador `_ReadBarrier`, `_WriteBarrier` e `_ReadWriteBarrier` e a macro `MemoryBarrier` foram todos preteridos e não devem ser usados. Para comunicação entre thread, usar mecanismos como [atomic_thread_fence](../standard-library/atomic-functions.md#atomic_thread_fence) e [std::atomic\<T >](../standard-library/atomic.md), que é definido no [biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md). Para acessar de hardware, use o [/volatile:iso](../build/reference/volatile-volatile-keyword-interpretation.md) opção de compilador junto com o [volátil](../cpp/volatile-cpp.md) palavra-chave.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void _ReadWriteBarrier(void);  
```  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`_ReadWriteBarrier`|x86, [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
## <a name="remarks"></a>Comentários  
 O tipo intrínseco do `_ReadWriteBarrier` limita as otimizações do compilador que podem remover e reordenar acessos à memória através do ponto da chamada.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [_ReadBarrier](../intrinsics/readbarrier.md)   
 [_WriteBarrier](../intrinsics/writebarrier.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)