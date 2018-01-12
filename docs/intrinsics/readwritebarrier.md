---
title: Readwritebarrier | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: _ReadWriteBarrier
dev_langs: C++
helpviewer_keywords:
- ReadWriteBarrier intrinsic
- _ReadWriteBarrier intrinsic
ms.assetid: dd9f58b5-8bb6-494e-bb0f-9fe184f3908d
caps.latest.revision: "27"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2235c2089dd23a0572e960b995958c9e1740e108
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
 [Readbarrier](../intrinsics/readbarrier.md)   
 [Writebarrier](../intrinsics/writebarrier.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)