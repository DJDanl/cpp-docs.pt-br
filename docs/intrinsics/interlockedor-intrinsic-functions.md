---
title: "Fun&#231;&#245;es intr&#237;nsecas _InterlockedOr | Microsoft Docs"
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
  - "_InterlockedOr8_nf"
  - "_InterlockedOr_HLEAcquire"
  - "_InterlockedOr16_nf"
  - "_InterlockedOr64"
  - "_InterlockedOr8_np"
  - "_InterlockedOr64_cpp"
  - "_InterlockedOr8_acq"
  - "_InterlockedOr_nf"
  - "_InterlockedOr64_acq"
  - "_InterlockedOr_np"
  - "_InterlockedOr8"
  - "_InterlockedOr"
  - "_InterlockedOr64_np"
  - "_InterlockedOr_acq"
  - "_InterlockedOr64_HLERelease"
  - "_InterlockedOr16_np"
  - "_InterlockedOr_cpp"
  - "_InterlockedOr8_rel"
  - "_InterlockedOr64_rel"
  - "_InterlockedOr16_acq"
  - "_InterlockedOr_rel"
  - "_InterlockedOr16_rel"
  - "_InterlockedOr_HLERelease"
  - "_InterlockedOr64_HLEAcquire"
  - "_InterlockedOr16"
  - "_InterlockedOr64_nf"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "_InterlockedOr intrínseco"
  - "_InterlockedOr_acq intrínseco"
  - "_InterlockedOr_HLEAcquire intrínseco"
  - "_InterlockedOr_HLERelease intrínseco"
  - "_InterlockedOr_nf intrínseco"
  - "_InterlockedOr_np intrínseco"
  - "_InterlockedOr_rel intrínseco"
  - "_InterlockedOr16 intrínseco"
  - "_InterlockedOr16_acq intrínseco"
  - "_InterlockedOr16_nf intrínseco"
  - "_InterlockedOr16_np intrínseco"
  - "_InterlockedOr16_rel intrínseco"
  - "_InterlockedOr64 intrínseco"
  - "_InterlockedOr64_acq intrínseco"
  - "_InterlockedOr64_HLEAcquire intrínseco"
  - "_InterlockedOr64_HLERelease intrínseco"
  - "_InterlockedOr64_nf intrínseco"
  - "_InterlockedOr64_np intrínseco"
  - "_InterlockedOr64_rel intrínseco"
  - "_InterlockedOr8 intrínseco"
  - "_InterlockedOr8_acq intrínseco"
  - "_InterlockedOr8_nf intrínseco"
  - "_InterlockedOr8_np intrínseco"
  - "_InterlockedOr8_rel intrínseco"
  - "InterlockedOr intrínseco"
  - "InterlockedOr64 intrínseco"
ms.assetid: 5f265240-7af8-44b7-b952-19f3a9c56186
caps.latest.revision: 19
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Fun&#231;&#245;es intr&#237;nsecas _InterlockedOr
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Execute um bit a bit atômico ou operação em uma variável compartilhada por vários threads.  
  
## Sintaxe  
  
```  
long _InterlockedOr(  
   long volatile * Value,  
   long Mask  
);  
long _InterlockedOr_acq(  
   long volatile * Value,  
   long Mask  
);  
long _InterlockedOr_HLEAcquire(  
   long volatile * Value,  
   long Mask  
);  
long _InterlockedOr_HLERelease(  
   long volatile * Value,  
   long Mask  
);  
long _InterlockedOr_nf(  
   long volatile * Value,  
   long Mask  
);  
long _InterlockedOr_np(  
   long volatile * Value,  
   long Mask  
);  
long _InterlockedOr_rel(  
   long volatile * Value,  
   long Mask  
);  
char _InterlockedOr8(  
   char volatile * Value,  
   long Mask  
);  
char _InterlockedOr8_acq(  
   char volatile * Value,  
   char Mask  
);  
char _InterlockedOr8_nf(  
   char volatile * Value,  
   char Mask  
);  
char _InterlockedOr8_np(  
   char volatile * Value,  
   char Mask  
);  
char _InterlockedOr8_rel(  
   char volatile * Value,  
   char Mask  
);  
short _InterlockedOr16(  
   short volatile * Value,  
   short Mask  
);  
short _InterlockedOr16_acq(  
   short volatile * Value,  
   short Mask  
);  
short _InterlockedOr16_nf(  
   short volatile * Value,  
   short Mask  
);  
short _InterlockedOr16_np(  
   short volatile * Value,  
   short Mask  
);  
short _InterlockedOr16_rel(  
   short volatile * Value,  
   short Mask  
);  
__int64 _InterlockedOr64(  
   __int64 volatile * Value,  
   __int64 Mask  
);  
__int64 _InterlockedOr64_acq(  
   __int64 volatile * Value,  
   __int64 Mask  
);   
__int64 _InterlockedOr64_HLEAcquire(  
   __int64 volatile * Value,  
   __int64 Mask  
);  
__int64 _InterlockedOr64_HLERelease(  
   __int64 volatile * Value,  
   __int64 Mask  
);   
__int64 _InterlockedOr64_nf(  
   __int64 volatile * Value,  
   __int64 Mask  
);  
__int64 _InterlockedOr64_np(  
   __int64 volatile * Value,  
   __int64 Mask  
);  
__int64 _InterlockedOr64_rel(  
   __int64 volatile * Value,  
   __int64 Mask  
);  
```  
  
#### Parâmetros  
 \[in, out\] `Value`  
 Um ponteiro para o primeiro operando a ser substituído pelo resultado.  
  
 \[in\] `Mask`  
 O segundo operando.  
  
## Valor de retorno  
 O valor original apontado pelo primeiro parâmetro.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|Cabeçalho|  
|----------------|-----------------|---------------|  
|`_InterlockedOr`, `_InterlockedOr8`, `_InterlockedOr16`, `_InterlockedOr64`|x86, ARM, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|\<intrin.h\>|  
|`_InterlockedOr_acq`, `_InterlockedOr_nf`, `_InterlockedOr_rel`, `_InterlockedOr8_acq`, `_InterlockedOr8_nf`, `_InterlockedOr8_rel`, `_InterlockedOr16_acq`, `_InterlockedOr16_nf`, `_InterlockedOr16_rel`, `_InterlockedOr64_acq`, `_InterlockedOr64_nf`, `_InterlockedOr64_rel`|ARM|\<intrin.h\>|  
|`_InterlockedOr_np`, `_InterlockedOr8_np`, `_InterlockedOr16_np`, `_InterlockedOr64_np`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|\<intrin.h\>|  
|`_InterlockedOr_HLEAcquire`, `_InterlockedOr_HLERelease`, `_InterlockedOr64_HLEAcquire`, `_InterlockedOr64_HLERelease`|x86, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|\<immintrin.h\>|  
  
## Comentários  
 O número no nome de cada função especifica o tamanho de bit dos argumentos.  
  
 Em plataformas ARM, use intrínsecos com os sufixos `_acq` e `_rel` para semântica de aquisição e liberação, como no início e no final de uma seção crítica.  Os intrínsecos de ARM com um sufixo `_nf` \("no fence"\) não funcionam como uma barreira de memória.  
  
 Intrínsecos com um sufixo `_np` \("no prefetch"\) impedem que uma possível operação de pré\-busca seja inserida pelo compilador.  
  
 Em plataformas Intel que suportam instruções HLE \(Elisão de Bloqueio de Hardware\), intrínsecos com os sufixos `_HLEAcquire` e `_HLERelease` incluem uma dica para o processador que pode acelerar o desempenho, eliminando uma etapa de gravação de bloqueio no hardware.  Se esses intrínsecos forem chamados em plataformas que não dão suporte a HLE, a dica será ignorada.  
  
## Exemplo  
  
```  
// _InterlockedOr.cpp  
#include <stdio.h>  
#include <intrin.h>  
  
#pragma intrinsic(_InterlockedOr)  
  
int main()  
{  
        long data1 = 0xFF00FF00;  
        long data2 = 0x00FFFF00;  
        long retval;  
        retval = _InterlockedOr(&data1, data2);  
        printf_s("0x%x 0x%x 0x%x", data1, data2, retval);   
}  
```  
  
  **0xffffff00 0xffff00 0xff00ff00**   
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [Conflitos com o compilador x86](../Topic/Conflicts%20with%20the%20x86%20Compiler.md)