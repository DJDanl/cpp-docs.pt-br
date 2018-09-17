---
title: Funções intrínsecas interlockedexchangepointer | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- _InterlockedExchangePointer_cpp
- _InterlockedExchangePointer_rel
- _InterlockedExchangePointer_nf
- _InterlockedExchangePointer_HLERelease
- _InterlockedExchangePointer_acq
- _InterlockedExchangePointer
- _InterlockedExchangePointer_acq_cpp
- _InterlockedExchangePointer_HLEAcquire
dev_langs:
- C++
helpviewer_keywords:
- _InterlockedExchangePointer_rel intrinsic
- _InterlockedExchangePointer_HLERelease intrinsic
- _InterlockedExchangePointer intrinsic
- _InterlockedExchangePointer_nf intrinsic
- _InterlockedExchangePointer_acq intrinsic
- _InterlockedExchangePointer_HLEAcquire intrinsic
- InterlockedExchangePointer_acq intrinsic
- InterlockedExchangePointer intrinsic
ms.assetid: 0eaca0b0-d79e-406b-892d-b3b462c50bbb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fa2aa8fb79a0590c437699bcf887f2a7e1c1bb21
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45705010"
---
# <a name="interlockedexchangepointer-intrinsic-functions"></a>Funções intrínsecas _InterlockedExchangePointer
**Seção específica da Microsoft**  
  
 Execute uma operação atômica de troca, que copia o endereço passado como o segundo argumento para o primeiro e retorna o endereço original do primeiro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void * _InterlockedExchangePointer(  
   void * volatile * Target,  
   void * Value  
);   
void * _InterlockedExchangePointer_acq(  
   void * volatile * Target,  
   void * Value  
);   
void * _InterlockedExchangePointer_rel(  
   void * volatile * Target,  
   void * Value  
);   
void * _InterlockedExchangePointer_nf(  
   void * volatile * Target,  
   void * Value  
);   
void * _InterlockedExchangePointer_HLEAcquire(  
   void * volatile * Target,  
   void * Value  
);   
void * _InterlockedExchangePointer_HLERelease(  
   void * volatile * Target,  
   void * Value  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
*Target*<br/>
[no, out] Ponteiro para o ponteiro para o valor para o exchange. A função define o valor como `Value` e retorna seu valor anterior.  
  
*Value*<br/>
[in] Valor a ser trocado com o valor apontado por `Target`.  
  
## <a name="return-value"></a>Valor de retorno  
 A função retorna o valor inicial apontado por `Target`.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|Cabeçalho|  
|---------------|------------------|------------|  
|`_InterlockedExchangePointer`|x86, ARM, x64|\<intrin.h>|  
|`_InterlockedExchangePointer_acq`, `_InterlockedExchangePointer_rel`, `_InterlockedExchangePointer_nf`|ARM|\<intrin.h>|  
|`_InterlockedExchangePointer_HLEAcquire`, `_InterlockedExchangePointer_HLERelease`|x64 com suporte a HLE|\<immintrin.h>|  
  
 Na arquitetura x86, `_InterlockedExchangePointer` é uma macro que chama `_InterlockedExchange`.  
  
## <a name="remarks"></a>Comentários  
 Em um sistema de 64 bits, os parâmetros são 64 bits e devem estar alinhados em limites de 64 bits; caso contrário, a função falhará. Em um sistema de 32 bits, os parâmetros são de 32 bits em devem estar alinhados em limites de 32 bits. Para obter mais informações, consulte [alinhar](../cpp/align-cpp.md).  
  
 Em plataformas ARM, use intrínsecos com os sufixos `_acq` e `_rel` para semântica de aquisição e liberação, como no início e no final de uma seção crítica. O intrínseco com um sufixo `_nf` ("no fence") não funciona como uma barreira de memória.  
  
 Em plataformas Intel que suportam instruções HLE (Elisão de Bloqueio de Hardware), intrínsecos com os sufixos `_HLEAcquire` e `_HLERelease` incluem uma dica para o processador que pode acelerar o desempenho, eliminando uma etapa de gravação de bloqueio no hardware. Se esses intrínsecos forem chamados em plataformas que não dão suporte a HLE, a dica será ignorada.  
  
 Essas rotinas somente estão disponíveis como intrínsecos.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [conflitos com o compilador x86](../build/conflicts-with-the-x86-compiler.md)