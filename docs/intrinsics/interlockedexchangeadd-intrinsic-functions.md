---
title: "Fun&#231;&#245;es intr&#237;nsecas _InterlockedExchangeAdd | Microsoft Docs"
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
  - "_InterlockedExchangeAdd64_nf"
  - "_InterlockedExchangeAdd64_rel"
  - "_InterlockedExchangeAdd16_rel"
  - "_InterlockedExchangeAdd_acq"
  - "_InterlockedExchangeAdd_nf"
  - "_InterlockedExchangeAdd_rel"
  - "_InterlockedExchangeAdd8_acq"
  - "_InterlockedExchangeAdd16_nf"
  - "_InterlockedExchangeAdd_acq_cpp"
  - "_InterlockedExchangeAdd64_acq_cpp"
  - "_InterlockedExchangeAdd16_acq"
  - "_InterlockedExchangeAdd_HLERelease"
  - "_InterlockedExchangeAdd64_cpp"
  - "_InterlockedExchangeAdd64_HLERelease"
  - "_InterlockedExchangeAdd64_acq"
  - "_InterlockedExchangeAdd8"
  - "_InterlockedExchangeAdd64"
  - "_InterlockedExchangeAdd8_nf"
  - "_InterlockedExchangeAdd16"
  - "_InterlockedExchangeAdd64_rel_cpp"
  - "_InterlockedExchangeAdd_cpp"
  - "_InterlockedExchangeAdd8_rel"
  - "_InterlockedExchangeAdd_HLEAcquire"
  - "_InterlockedExchangeAdd64_HLEAcquire"
  - "_InterlockedExchangeAdd"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "_InterlockedExchangeAdd intrínseco"
  - "_InterlockedExchangeAdd_acq intrínseco"
  - "_InterlockedExchangeAdd_HLEAcquire intrínseco"
  - "_InterlockedExchangeAdd_HLERelease intrínseco"
  - "_InterlockedExchangeAdd_nf intrínseco"
  - "_InterlockedExchangeAdd_rel intrínseco"
  - "_InterlockedExchangeAdd16 intrínseco"
  - "_InterlockedExchangeAdd16_acq intrínseco"
  - "_InterlockedExchangeAdd16_nf intrínseco"
  - "_InterlockedExchangeAdd16_rel intrínseco"
  - "_InterlockedExchangeAdd64 intrínseco"
  - "_InterlockedExchangeAdd64_acq intrínseco"
  - "_InterlockedExchangeAdd64_HLEAcquire intrínseco"
  - "_InterlockedExchangeAdd64_HLERelease intrínseco"
  - "_InterlockedExchangeAdd64_nf intrínseco"
  - "_InterlockedExchangeAdd64_rel intrínseco"
  - "_InterlockedExchangeAdd8 intrínseco"
  - "_InterlockedExchangeAdd8_acq intrínseco"
  - "_InterlockedExchangeAdd8_nf intrínseco"
  - "_InterlockedExchangeAdd8_rel intrínseco"
  - "InterlockedExchangeAdd intrínseco"
  - "InterlockedExchangeAdd_acq intrínseco"
  - "InterlockedExchangeAdd_rel intrínseco"
  - "InterlockedExchangeAdd64 intrínseco"
  - "InterlockedExchangeAdd64_acq intrínseco"
  - "InterlockedExchangeAdd64_rel intrínseco"
ms.assetid: 25809e1f-9c60-4492-9f7c-0fb59c8d13d2
caps.latest.revision: 19
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Fun&#231;&#245;es intr&#237;nsecas _InterlockedExchangeAdd
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Fornece suporte intrínseco de compilador à função [!INCLUDE[winsdkshort](../atl/reference/includes/winsdkshort_md.md)] [\_InterlockedExchangeAdd Intrinsic Functions](../intrinsics/interlockedexchangeadd-intrinsic-functions.md) do Win32.  
  
## Sintaxe  
  
```  
long _InterlockedExchangeAdd(    long volatile * Addend,    long Value ); long _InterlockedExchangeAdd_acq(    long volatile * Addend,    long Value ); long _InterlockedExchangeAdd_rel(    long volatile * Addend,    long Value ); long _InterlockedExchangeAdd_nf(    long volatile * Addend,    long Value ); long _InterlockedExchangeAdd_HLEAcquire(    long volatile * Addend,    long Value ); long _InterlockedExchangeAdd_HLERelease(    long volatile * Addend,    long Value ); char _InterlockedExchangeAdd8(    char volatile * Addend,    char Value ); char _InterlockedExchangeAdd8_acq(    char volatile * Addend,    char Value ); char _InterlockedExchangeAdd8_rel(    char volatile * Addend,    char Value ); char _InterlockedExchangeAdd8_nf(    char volatile * Addend,    char Value ); short _InterlockedExchangeAdd16(    short volatile * Addend,    short Value ); short _InterlockedExchangeAdd16_acq(    short volatile * Addend,    short Value ); short _InterlockedExchangeAdd16_rel(    short volatile * Addend,    short Value ); short _InterlockedExchangeAdd16_nf(    short volatile * Addend,    short Value ); __int64 _InterlockedExchangeAdd64(    __int64 volatile * Addend,    __int64 Value ); __int64 _InterlockedExchangeAdd64_acq(    __int64 volatile * Addend,    __int64 Value ); __int64 _InterlockedExchangeAdd64_rel(    __int64 volatile * Addend,    __int64 Value ); __int64 _InterlockedExchangeAdd64_nf(    __int64 volatile * Addend,    __int64 Value ); __int64 _InterlockedExchangeAdd64_HLEAcquire(    __int64 volatile * Addend,    __int64 Value ); __int64 _InterlockedExchangeAdd64_HLERelease(    __int64 volatile * Addend,    __int64 Value );   
```  
  
#### Parâmetros  
 \[in, out\] `Addend`  
 O valor a ser adicionado; substituído pelo resultado da adição.  
  
 \[in\] `Value`  
 O valor a ser adicionado.  
  
## Valor de retorno  
 O valor retornado é o valor inicial da variável que aponta para o parâmetro `Addend`.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|Cabeçalho|  
|----------------|-----------------|---------------|  
|`_InterlockedExchangeAdd`, `_InterlockedExchangeAdd8`, `_InterlockedExchangeAdd16`, `_InterlockedExchangeAdd64`|x86, ARM, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|\<intrin.h\>|  
|`_InterlockedExchangeAdd_acq`, `_InterlockedExchangeAdd_rel`, `_InterlockedExchangeAdd_nf`, `_InterlockedExchangeAdd8_acq`, `_InterlockedExchangeAdd8_rel`, `_InterlockedExchangeAdd8_nf`,`_InterlockedExchangeAdd16_acq`, `_InterlockedExchangeAdd16_rel`, `_InterlockedExchangeAdd16_nf`, `_InterlockedExchangeAdd64_acq`, `_InterlockedExchangeAdd64_rel`, `_InterlockedExchangeAdd64_nf`|ARM|\<intrin.h\>|  
|`_InterlockedExchangeAdd_HLEAcquire`, `_InterlockedExchangeAdd_HLERelease`, `_InterlockedExchangeAdd64_HLEAcquire`, `_InterlockedExchangeAdd64_HLErelease`|x86, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|\<immintrin.h\>|  
  
## Comentários  
 Há diversas variações em `_InterlockedExchangeAdd` que têm base no tipo de dados que envolvem e se a semântica acquire ou release é usada.  
  
 Enquanto a função `_InterlockedExchangeAdd` opera em valores inteiros de 32 bits, `_InterlockedExchangeAdd8` opera em valores inteiros de 8 bits, `_InterlockedExchangeAdd16` opera em valores inteiros de 16 bits e `_InterlockedExchangeAdd64` opera em valores inteiros de 64 bits.  
  
 Em plataformas ARM, use intrínsecos com os sufixos `_acq` e `_rel` para semântica de aquisição e liberação, como no início e no final de uma seção crítica.  Os intrínsecos com um sufixo `_nf` \("no fence"\) não funcionam como uma barreira de memória.  
  
 Em plataformas Intel que suportam instruções HLE \(Elisão de Bloqueio de Hardware\), intrínsecos com os sufixos `_HLEAcquire` e `_HLERelease` incluem uma dica para o processador que pode acelerar o desempenho, eliminando uma etapa de gravação de bloqueio no hardware.  Se esses intrínsecos forem chamados em plataformas que não dão suporte a HLE, a dica será ignorada.  
  
 Essas rotinas somente estão disponíveis como intrínsecos.  Portanto, eles são intrínsecos, caso ou não os intrínsecos [\/Oi](../Topic/-Oi%20\(Generate%20Intrinsic%20Functions\).md) ou [\#pragma](../preprocessor/intrinsic.md) sejam usados.  Não é possível usar a [função \#pragma](../preprocessor/function-c-cpp.md) nesses intrínsecos.  
  
## Exemplo  
 Para obter um exemplo de como usar `_InterlockedExchangeAdd`, consulte [\_InterlockedDecrement](../intrinsics/interlockeddecrement-intrinsic-functions.md).  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Conflitos com o compilador x86](../Topic/Conflicts%20with%20the%20x86%20Compiler.md)