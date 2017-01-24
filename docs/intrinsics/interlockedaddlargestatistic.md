---
title: "_InterlockedAddLargeStatistic | Microsoft Docs"
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
  - "_InterlockedAddLargeStatistic"
  - "_InterlockedAddLargeStatistic_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "_InterlockedAddLargeStatistic intrínseco"
  - "InterlockedAddLargeStatistic intrínseco"
ms.assetid: 2802e74b-bcee-46e4-b562-894908d44409
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _InterlockedAddLargeStatistic
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específicos do Microsoft**  
  
 Executa uma adição interligada em que o primeiro operando é um valor de 64 bits.  
  
## Sintaxe  
  
```  
long _InterlockedAddLargeStatistic(  
   __int64 volatile * Addend,  
   long Value  
);  
```  
  
#### Parâmetros  
 \[in, out\]`Addend`  
 Um ponteiro para o primeiro operando para a operação de adição.  O valor apontado é substituído pelo resultado da adição.  
  
 \[in\]`Value`  
 O segundo operando; valor para adicionar o primeiro operando.  
  
## Valor de retorno  
 O valor do segundo operando.  
  
## Requisitos  
  
|Intrínseca|Arquitetura|  
|----------------|-----------------|  
|`_InterlockedAddLargeStatistic`|x86|  
  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Comentários  
 Nesse intrínseca não é atômica porque ela é implementada como dois separados instruções bloqueadas.  Uma leitura de 64\-bit atômica que ocorre em outro thread durante a execução desta intrínseca pode resultar em um valor inconsistente que está sendo lido.  
  
 Esta função se comporta como uma barreira de leitura\-gravação.  Para obter mais informações, consulte  [\_ReadWriteBarrier](../intrinsics/readwritebarrier.md).  
  
## END Microsoft específicos  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [Conflitos com o compilador x86](../Topic/Conflicts%20with%20the%20x86%20Compiler.md)