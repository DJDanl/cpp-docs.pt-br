---
title: "Fun&#231;&#245;es intr&#237;nsecas _InterlockedIncrement | Microsoft Docs"
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
  - "_InterlockedIncrement_acq"
  - "_InterlockedIncrement16_rel_cpp"
  - "_InterlockedIncrement16_cpp"
  - "_InterlockedIncrement64_rel"
  - "_InterlockedIncrement_rel"
  - "_InterlockedIncrement64_nf"
  - "_InterlockedIncrement16_acq_cpp"
  - "_InterlockedIncrement_rel_cpp"
  - "_InterlockedIncrement64"
  - "_InterlockedIncrement64_rel_cpp"
  - "_InterlockedIncrement16_nf"
  - "_InterlockedIncrement16_rel"
  - "_InterlockedIncrement16_acq"
  - "_InterlockedIncrement_nf"
  - "_InterlockedIncrement_acq_cpp"
  - "_InterlockedIncrement64_cpp"
  - "_InterlockedIncrement64_acq_cpp"
  - "_InterlockedIncrement"
  - "_InterlockedIncrement_cpp"
  - "_InterlockedIncrement64_acq"
  - "_InterlockedIncrement16"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Intrínseco _InterlockedIncrement"
  - "Intrínseco _InterlockedIncrement_acq"
  - "Intrínseco _InterlockedIncrement_nf"
  - "Intrínseco _InterlockedIncrement_rel"
  - "Intrínseco _InterlockedIncrement16"
  - "Intrínseco _InterlockedIncrement16_acq"
  - "Intrínseco _InterlockedIncrement16_nf"
  - "Intrínseco _InterlockedIncrement16_rel"
  - "Intrínseco _InterlockedIncrement64"
  - "Intrínseco _InterlockedIncrement64_acq"
  - "Intrínseco _InterlockedIncrement64_nf"
  - "Intrínseco _InterlockedIncrement64_rel"
  - "Intrínseco InterlockedIncrement"
  - "Intrínseco InterlockedIncrement_acq"
  - "Intrínseco InterlockedIncrement_rel"
  - "Intrínseco InterlockedIncrement16"
  - "Intrínseco InterlockedIncrement64"
  - "Intrínseco InterlockedIncrement64_acq"
  - "Intrínseco InterlockedIncrement64_rel"
ms.assetid: 37700615-f372-438b-bcef-d76e11839482
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Fun&#231;&#245;es intr&#237;nsecas _InterlockedIncrement
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Dá suporte a compilador intrínseco para o Win32 [!INCLUDE[winsdkshort](../atl/reference/includes/winsdkshort_md.md)] [InterlockedIncrement](http://msdn.microsoft.com/library/ms683614.aspx) função.  
  
## Sintaxe  
  
```  
long _InterlockedIncrement(  
   long * lpAddend  
);  
long _InterlockedIncrement_acq(  
   long * lpAddend  
);  
long _InterlockedIncrement_rel(  
   long * lpAddend  
);  
long _InterlockedIncrement_nf(  
   long * lpAddend  
);  
short _InterlockedIncrement16(  
   short * lpAddend  
);  
short _InterlockedIncrement16_acq(  
   short * lpAddend  
);  
short _InterlockedIncrement16_rel(  
   short * lpAddend  
);  
short _InterlockedIncrement16_nf (  
   short * lpAddend  
);  
__int64 _InterlockedIncrement64(  
   __int64 * lpAddend  
);  
__int64 _InterlockedIncrement64_acq(  
   __int64 * lpAddend  
);  
__int64 _InterlockedIncrement64_rel(  
   __int64 * lpAddend  
);   
__int64 _InterlockedIncrement64_nf(  
   __int64 * lpAddend  
);  
```  
  
#### Parâmetros  
 \[in, out\] `lpAddend`  
 Ponteiro para a variável a ser incrementada.  
  
## Valor de retorno  
 O valor retornado é o valor incrementado resultante.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|Cabeçalho|  
|----------------|-----------------|---------------|  
|`_InterlockedIncrement`, `_InterlockedIncrement16`, `_InterlockedIncrement64`|x86, ARM, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|\<intrin.h\>|  
|`_InterlockedIncrement_acq`, `_InterlockedIncrement_rel`, `_InterlockedIncrement_nf`, `_InterlockedIncrement16_acq`, `_InterlockedIncrement16_rel`, `_InterlockedIncrement16_nf`, `_InterlockedIncrement64_acq`, `_InterlockedIncrement64_rel`, `_InterlockedIncrement64_nf`|ARM|\<intrin.h\>|  
  
## Comentários  
 Há diversas variações em `_InterlockedIncrement` que têm base no tipo de dados que envolvem e se a semântica acquire ou release é usada.  
  
 Enquanto a função `_InterlockedIncrement` opera nos valores inteiros de 32 bits, `_InterlockedIncrement16` opera em valores inteiros de 16 bits `_InterlockedIncrement64` opera em valores inteiros de 64 bits.  
  
 Em plataformas ARM, use intrínsecos com os sufixos `_acq` e `_rel` para semântica de aquisição e liberação, como no início e no final de uma seção crítica.  O intrínseco com um sufixo `_nf` \("no fence"\) não funciona como uma barreira de memória.  
  
 A variável apontada para o parâmetro `lpAddend` deve estar alinhada em um limite de 32 bits; caso contrário, essa função falhará em sistemas de multiprocessor x86 e em qualquer sistema não x86.  Para obter mais informações, consulte [alinhar](../cpp/align-cpp.md).  
  
 A função Win32 é declarada no `Wdm.h` ou `Ntddk.h`.  
  
 Essas rotinas somente estão disponíveis como intrínsecos.  
  
## Exemplo  
 Para obter um exemplo de como usar `_InterlockedIncrement`, consulte [\_InterlockedDecrement](../intrinsics/interlockeddecrement-intrinsic-functions.md).  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Conflitos com o compilador x86](../Topic/Conflicts%20with%20the%20x86%20Compiler.md)