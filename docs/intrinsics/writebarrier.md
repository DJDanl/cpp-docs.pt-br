---
title: Writebarrier | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- _WriteBarrier
dev_langs:
- C++
helpviewer_keywords:
- WriteBarrier intrinsic
- _WriteBarrier intrinsic
ms.assetid: a5ffdad9-0ca1-4eb7-b2f3-0f092c4bf4b5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8197fd38886c887684c3f5f4eb3594088190304d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33339300"
---
# <a name="writebarrier"></a>_WriteBarrier
**Seção específica da Microsoft**  
  
 Limita as otimizações do compilador que podem reordenar operações de acesso à memória no ponto da chamada.  
  
> [!CAUTION]
>  Os tipos intrínsecos de compilador `_ReadBarrier`, `_WriteBarrier` e `_ReadWriteBarrier` e a macro `MemoryBarrier` foram todos preteridos e não devem ser usados. Para comunicação entre thread, usar mecanismos como [atomic_thread_fence](../standard-library/atomic-functions.md#atomic_thread_fence) e [std::atomic\<T >](../standard-library/atomic.md), que é definido no [biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md). Para acessar de hardware, use o [/volatile:iso](../build/reference/volatile-volatile-keyword-interpretation.md) opção de compilador junto com o [volátil](../cpp/volatile-cpp.md) palavra-chave.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void _WriteBarrier(void);  
```  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`_WriteBarrier`|x86, [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
## <a name="remarks"></a>Comentários  
 O intrínseco `_WriteBarrier` limita as otimizações do compilador que podem remover e reordenar operações de acesso à memória através do ponto da chamada.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [_ReadBarrier](../intrinsics/readbarrier.md)   
 [_ReadWriteBarrier](../intrinsics/readwritebarrier.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)