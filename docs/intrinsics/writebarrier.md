---
title: "_WriteBarrier | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "_WriteBarrier"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Intrínseco _WriteBarrier"
  - "Intrínseco WriteBarrier"
ms.assetid: a5ffdad9-0ca1-4eb7-b2f3-0f092c4bf4b5
caps.latest.revision: 23
caps.handback.revision: 23
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _WriteBarrier
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Limita as otimizações do compilador que podem reordenar operações de acesso à memória no ponto da chamada.  
  
> [!CAUTION]
>  Os tipos intrínsecos de compilador `_ReadBarrier`, `_WriteBarrier` e `_ReadWriteBarrier` e a macro `MemoryBarrier` foram todos preteridos e não devem ser usados.  Para a comunicação entre threads, use mecanismos como [atomic\_thread\_fence](../Topic/atomic_thread_fence%20Function.md) e [std::atomic\<T\>](../standard-library/atomic.md) definidos no [Biblioteca Padrão C\+\+](../standard-library/cpp-standard-library-reference.md).  Para obter acesso de hardware, use a opção do compilador [\/volatile:iso](../build/reference/volatile-volatile-keyword-interpretation.md) junto com a palavra\-chave [volatile](../cpp/volatile-cpp.md).  
  
## Sintaxe  
  
```  
void _WriteBarrier(void);  
```  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`_WriteBarrier`|x86, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 O intrínseco `_WriteBarrier` limita as otimizações do compilador que podem remover e reordenar operações de acesso à memória através do ponto da chamada.  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [\_ReadBarrier](../intrinsics/readbarrier.md)   
 [\_ReadWriteBarrier](../intrinsics/readwritebarrier.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)