---
title: "Fun&#231;&#245;es intr&#237;nsecas _interlockedbittestandset | Microsoft Docs"
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
  - "_interlockedbittestandset_cpp"
  - "_interlockedbittestandset_HLEAcquire"
  - "_interlockedbittestandset64"
  - "_interlockedbittestandset"
  - "_interlockedbittestandset_rel"
  - "_interlockedbittestandset64_HLEAcquire"
  - "_interlockedbittestandset_HLERelease"
  - "_interlockedbittestandset_acq"
  - "_interlockedbittestandset_nf"
  - "_interlockedbittestandset64_cpp"
  - "_interlockedbittestandset64_HLERelease"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "_interlockedbittestandset intrínseco"
  - "_interlockedbittestandset64 intrínseco"
  - "instrução lock_bts"
ms.assetid: b1b7e334-53ea-48cf-ba60-5fa3ef51a1fc
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Fun&#231;&#245;es intr&#237;nsecas _interlockedbittestandset
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Gere uma instrução que examina o bit `b` do endereço `a` e retorna seu valor atual antes de defini\-la como 1.  
  
## Sintaxe  
  
```  
unsigned char _interlockedbittestandset(  
   long *a,  
   long b  
);  
unsigned char _interlockedbittestandset_acq(  
   long *a,  
   long b  
);  
unsigned char _interlockedbittestandset_HLEAcquire(  
   long *a,  
   long b  
);  
unsigned char _interlockedbittestandset_HLERelease(  
   long *a,  
   long b  
);  
unsigned char _interlockedbittestandset_nf(  
   long *a,  
   long b  
);  
unsigned char _interlockedbittestandset_rel(  
   long *a,  
   long b  
);  
unsigned char _interlockedbittestandset64(  
   __int64 *a,  
   __int64 b  
);  
unsigned char _interlockedbittestandset64_HLEAcquire(  
   __int64 *a,  
   __int64 b  
);  
unsigned char _interlockedbittestandset64_HLERelease(  
   __int64 *a,  
   __int64 b  
);  
```  
  
#### Parâmetros  
 \[in\] `a`  
 Um ponteiro para a memória a examinar.  
  
 \[in\] `b`  
 A posição de bit a testar.  
  
## Valor de retorno  
 O valor de bit na posição `b` antes que ele seja definido.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|Cabeçalho|  
|----------------|-----------------|---------------|  
|`_interlockedbittestandset`|x86, ARM, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|\<intrin.h\>|  
|`_interlockedbittestandset_acq`, `_interlockedbittestandset_nf`, `_interlockedbittestandset_rel`|ARM|\<intrin.h\>|  
|`_interlockedbittestandset_HLEAcquire`, `_interlockedbittestandset_HLERelease`|x86, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|\<immintrin.h\>|  
|`_interlockedbittestandset64`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|\<intrin.h\>|  
|`_interlockedbittestandset64_HLEAcquire`, `_interlockedbittestandset64_HLERelease`|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|\<immintrin.h\>|  
  
## Comentários  
 Em processadores x86 and [!INCLUDE[vcprx64](../Token/vcprx64_md.md)], esses intrínsecos usam a instrução `lock bts` para ler e definir o bit especificado como 1.  A operação é atômica.  
  
 Em processadores de ARM, use intrínsecos com os sufixos `_acq` e `_rel` para semântica de aquisição e liberação, como no início e no final de uma seção crítica.  Os intrínsecos de ARM com um sufixo `_nf` \("no fence"\) não funcionam como uma barreira de memória.  
  
 Em processadores Intel que suportam instruções HLE \(Elisão de Bloqueio de Hardware\), intrínsecos com os sufixos `_HLEAcquire` e `_HLERelease` incluem uma dica para o processador que pode acelerar o desempenho, eliminando uma etapa de gravação de bloqueio no hardware.  Se esses intrínsecos forem chamados em processadores que não dão suporte a HLE, a dica será ignorada.  
  
 Essas rotinas somente estão disponíveis como intrínsecos.  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [Conflitos com o compilador x86](../Topic/Conflicts%20with%20the%20x86%20Compiler.md)