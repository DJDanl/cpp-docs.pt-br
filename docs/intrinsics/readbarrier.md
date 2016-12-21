---
title: "_ReadBarrier | Microsoft Docs"
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
  - "_ReadBarrier"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Intrínseco _ReadBarrier"
ms.assetid: f9e54a92-61bc-4f55-8195-b8932065a796
caps.latest.revision: 25
caps.handback.revision: 25
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _ReadBarrier
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Limita as otimizações do compilador que podem reordenar operações de acesso à memória no ponto da chamada.  
  
> [!CAUTION]
>  Os tipos intrínsecos de compilador `_ReadBarrier`, `_WriteBarrier` e `_ReadWriteBarrier` e a macro `MemoryBarrier` foram todos preteridos e não devem ser usados.  Para comunicação interthread, use mecanismos como [atomic\_thread\_fence](../Topic/atomic_thread_fence%20Function.md) e [std::atomic\<T\>](../standard-library/atomic.md) definidos no [Biblioteca Padrão C\+\+](../standard-library/cpp-standard-library-reference.md).  Para obter acesso de hardware, use a opção do compilador [\/volatile:iso](../build/reference/volatile-volatile-keyword-interpretation.md) junto com a palavra\-chave [volatile](../cpp/volatile-cpp.md).  
  
## Sintaxe  
  
```  
void _ReadBarrier(void);  
```  
  
## Requisitos  
  
|Intrínseco|Arquitetura|  
|----------------|-----------------|  
|`_ReadBarrier`|x86, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 O intrínseco `_ReadBarrier` limita as otimizações do compilador que podem remover e reordenar operações de acesso à memória através do ponto da chamada.  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)