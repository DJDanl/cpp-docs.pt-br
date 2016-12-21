---
title: "_ReadWriteBarrier | Microsoft Docs"
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
  - "_ReadWriteBarrier"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Intrínseco _ReadWriteBarrier"
  - "Intrínseco ReadWriteBarrier"
ms.assetid: dd9f58b5-8bb6-494e-bb0f-9fe184f3908d
caps.latest.revision: 27
caps.handback.revision: 27
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _ReadWriteBarrier
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Limita as otimizações do compilador que podem reordenar os acessos à memória através do ponto da chamada.  
  
> [!CAUTION]
>  Os tipos intrínsecos de compilador `_ReadBarrier`, `_WriteBarrier` e `_ReadWriteBarrier` e a macro `MemoryBarrier` foram todos preteridos e não devem ser usados.  Para a comunicação entre threads, use mecanismos como [atomic\_thread\_fence](../Topic/atomic_thread_fence%20Function.md) e [std::atomic\<T\>](../standard-library/atomic.md) definidos no [Biblioteca Padrão C\+\+](../standard-library/cpp-standard-library-reference.md).  Para obter acesso de hardware, use a opção do compilador [\/volatile:iso](../build/reference/volatile-volatile-keyword-interpretation.md) junto com a palavra\-chave [volatile](../cpp/volatile-cpp.md).  
  
## Sintaxe  
  
```  
void _ReadWriteBarrier(void);  
```  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`_ReadWriteBarrier`|x86, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 O tipo intrínseco do `_ReadWriteBarrier` limita as otimizações do compilador que podem remover e reordenar acessos à memória através do ponto da chamada.  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [\_ReadBarrier](../intrinsics/readbarrier.md)   
 [\_WriteBarrier](../intrinsics/writebarrier.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)