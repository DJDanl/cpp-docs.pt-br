---
title: "Fun&#231;&#245;es intr&#237;nsecas _InterlockedCompareExchangePointer | Microsoft Docs"
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
  - "_InterlockedCompareExchangePointer_HLERelease"
  - "_InterlockedCompareExchangePointer_rel"
  - "_InterlockedCompareExchangePointer_acq_cpp"
  - "_InterlockedCompareExchangePointer"
  - "_InterlockedCompareExchangePointer_cpp"
  - "_InterlockedCompareExchangePointer_np"
  - "_InterlockedCompareExchangePointer_rel_cpp"
  - "_InterlockedCompareExchangePointer_HLEAcquire"
  - "_InterlockedCompareExchangePointer_acq"
  - "_InterlockedCompareExchangePointer_nf"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "_InterlockedCompareExchangePointer intrínseco"
  - "_InterlockedCompareExchangePointer_acq intrínseco"
  - "_InterlockedCompareExchangePointer_HLEAcquire intrínseco"
  - "_InterlockedCompareExchangePointer_HLERelease intrínseco"
  - "_InterlockedCompareExchangePointer_nf intrínseco"
  - "_InterlockedCompareExchangePointer_np intrínseco"
  - "_InterlockedCompareExchangePointer_rel intrínseco"
  - "InterlockedCompareExchangePointer intrínseco"
  - "InterlockedCompareExchangePointer_acq intrínseco"
  - "InterlockedCompareExchangePointer_rel intrínseco"
ms.assetid: 97fde59d-2bf9-42aa-a0fe-a5b6befdd44b
caps.latest.revision: 19
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Fun&#231;&#245;es intr&#237;nsecas _InterlockedCompareExchangePointer
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Executa uma operação atômica que armazena o endereço do `Exchange` no endereço `Destination` se os endereços `Comparand` e `Destination` forem iguais.  
  
## Sintaxe  
  
```  
void * _InterlockedCompareExchangePointer (    void * volatile * Destination,    void * Exchange,    void * Comparand ); void * _InterlockedCompareExchangePointer_acq (    void * volatile * Destination,    void * Exchange,    void * Comparand ); void * _InterlockedCompareExchangePointer_HLEAcquire (    void * volatile * Destination,    void * Exchange,    void * Comparand ); void * _InterlockedCompareExchangePointer_HLERelease (    void * volatile * Destination,    void * Exchange,    void * Comparand ); void * _InterlockedCompareExchangePointer_nf (    void * volatile * Destination,    void * Exchange,    void * Comparand ); void * _InterlockedCompareExchangePointer_np (    void * volatile * Destination,    void * Exchange,    void * Comparand ); long _InterlockedCompareExchangePointer_rel (    void * volatile * Destination,    void * Exchange,    void * Comparand );  
```  
  
#### Parâmetros  
 \[in, out\] `Destination`  
 Ponteiro para um ponteiro do valor de destino.  O sinal é ignorado.  
  
 \[in\] `Exchange`  
 Ponteiro do Exchange.  O sinal é ignorado.  
  
 \[in\] `Comparand`  
 Ponteiro a ser comparado ao destino.  O sinal é ignorado.  
  
## Valor de retorno  
 O valor de retorno é o valor inicial do destino.  
  
## Requisitos  
  
|Intrínseco|Arquitetura|Cabeçalho|  
|----------------|-----------------|---------------|  
|`_InterlockedCompareExchangePointer`|x86, ARM, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|\<intrin.h\>|  
|`_InterlockedCompareExchangePointer_acq`, `_InterlockedCompareExchangePointer_nf`, `_InterlockedCompareExchangePointer_rel`|ARM|\<iiintrin.h\>|  
|`_InterlockedCompareExchangePointer_HLEAcquire`, `_InterlockedCompareExchangePointer_HLERelease`|x86, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|\<immintrin.h\>|  
  
## Comentários  
 `_InterlockedCompareExchangePointer` realiza uma comparação atômica do endereço `Destination` com o endereço `Comparand`.  Se o endereço `Destination` for igual ao endereço `Comparand`, o endereço `Exchange` será armazenado no endereço especificado pelo `Destination`.  Caso contrário, nenhuma operação será executada.  
  
 `_InterlockedCompareExchangePointer` fornece suporte intrínseco ao compilador da função Win32 [!INCLUDE[winsdkshort](../atl/reference/includes/winsdkshort_md.md)] [\_InterlockedCompareExchangePointer](http://msdn.microsoft.com/library/ff547863.aspx).  
  
 Para obter um exemplo de como usar `_InterlockedCompareExchangePointer`, consulte [\_InterlockedDecrement](../intrinsics/interlockeddecrement-intrinsic-functions.md).  
  
 Em plataformas ARM, use intrínsecos com os sufixos `_acq` e `_rel` para semântica de aquisição e liberação, como no início e no final de uma seção crítica.  Os intrínsecos de ARM com um sufixo `_nf` \("no fence"\) não funcionam como uma barreira de memória.  
  
 Intrínsecos com um sufixo `_np` \("no prefetch"\) impedem que uma possível operação de pré\-busca seja inserida pelo compilador.  
  
 Em plataformas Intel que suportam instruções HLE \(Elisão de Bloqueio de Hardware\), intrínsecos com os sufixos `_HLEAcquire` e `_HLERelease` incluem uma dica para o processador que pode acelerar o desempenho, eliminando uma etapa de gravação de bloqueio no hardware.  Se esses intrínsecos forem chamados em plataformas que não dão suporte a HLE, a dica será ignorada.  
  
 Essas rotinas somente estão disponíveis como intrínsecos.  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)