---
title: Funções intrínsecas interlockedexchangeadd | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- _InterlockedExchangeAdd64_nf
- _InterlockedExchangeAdd64_rel
- _InterlockedExchangeAdd16_rel
- _InterlockedExchangeAdd_acq
- _InterlockedExchangeAdd_nf
- _InterlockedExchangeAdd_rel
- _InterlockedExchangeAdd8_acq
- _InterlockedExchangeAdd16_nf
- _InterlockedExchangeAdd_acq_cpp
- _InterlockedExchangeAdd64_acq_cpp
- _InterlockedExchangeAdd16_acq
- _InterlockedExchangeAdd_HLERelease
- _InterlockedExchangeAdd64_cpp
- _InterlockedExchangeAdd64_HLERelease
- _InterlockedExchangeAdd64_acq
- _InterlockedExchangeAdd8
- _InterlockedExchangeAdd64
- _InterlockedExchangeAdd8_nf
- _InterlockedExchangeAdd16
- _InterlockedExchangeAdd64_rel_cpp
- _InterlockedExchangeAdd_cpp
- _InterlockedExchangeAdd8_rel
- _InterlockedExchangeAdd_HLEAcquire
- _InterlockedExchangeAdd64_HLEAcquire
- _InterlockedExchangeAdd
dev_langs:
- C++
helpviewer_keywords:
- _InterlockedExchangeAdd8_nf intrinsic
- InterlockedExchangeAdd64_acq intrinsic
- _InterlockedExchangeAdd8_acq intrinsic
- _InterlockedExchangeAdd64 intrinsic
- _InterlockedExchangeAdd intrinsic
- _InterlockedExchangeAdd8_rel intrinsic
- _InterlockedExchangeAdd_acq intrinsic
- _InterlockedExchangeAdd_HLEAcquire intrinsic
- _InterlockedExchangeAdd8 intrinsic
- _InterlockedExchangeAdd_rel intrinsic
- _InterlockedExchangeAdd64_HLERelease intrinsic
- _InterlockedExchangeAdd64_nf intrinsic
- InterlockedExchangeAdd_rel intrinsic
- InterlockedExchangeAdd intrinsic
- _InterlockedExchangeAdd_nf intrinsic
- _InterlockedExchangeAdd16_rel intrinsic
- InterlockedExchangeAdd_acq intrinsic
- _InterlockedExchangeAdd64_HLEAcquire intrinsic
- _InterlockedExchangeAdd16 intrinsic
- _InterlockedExchangeAdd64_acq intrinsic
- InterlockedExchangeAdd64_rel intrinsic
- _InterlockedExchangeAdd16_acq intrinsic
- InterlockedExchangeAdd64 intrinsic
- _InterlockedExchangeAdd_HLERelease intrinsic
- _InterlockedExchangeAdd16_nf intrinsic
- _InterlockedExchangeAdd64_rel intrinsic
ms.assetid: 25809e1f-9c60-4492-9f7c-0fb59c8d13d2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2d25fccd56522d420a96b589796ef77cc30148d3
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42600886"
---
# <a name="interlockedexchangeadd-intrinsic-functions"></a>Funções intrínsecas _InterlockedExchangeAdd
**Seção específica da Microsoft**  
  
 Fornece suporte intrínseco ao compilador para o SDK do Windows Win32 [interlockedexchangeadd funções intrínsecas](../intrinsics/interlockedexchangeadd-intrinsic-functions.md) função.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
long _InterlockedExchangeAdd(  
   long volatile * Addend,  
   long Value  
);  
long _InterlockedExchangeAdd_acq(  
   long volatile * Addend,  
   long Value  
);  
long _InterlockedExchangeAdd_rel(  
   long volatile * Addend,  
   long Value  
);  
long _InterlockedExchangeAdd_nf(  
   long volatile * Addend,  
   long Value  
);  
long _InterlockedExchangeAdd_HLEAcquire(  
   long volatile * Addend,  
   long Value  
);  
long _InterlockedExchangeAdd_HLERelease(  
   long volatile * Addend,  
   long Value  
);  
char _InterlockedExchangeAdd8(  
   char volatile * Addend,  
   char Value  
);  
char _InterlockedExchangeAdd8_acq(  
   char volatile * Addend,  
   char Value  
);  
char _InterlockedExchangeAdd8_rel(  
   char volatile * Addend,  
   char Value  
);  
char _InterlockedExchangeAdd8_nf(  
   char volatile * Addend,  
   char Value  
);  
short _InterlockedExchangeAdd16(  
   short volatile * Addend,  
   short Value  
);  
short _InterlockedExchangeAdd16_acq(  
   short volatile * Addend,  
   short Value  
);  
short _InterlockedExchangeAdd16_rel(  
   short volatile * Addend,  
   short Value  
);  
short _InterlockedExchangeAdd16_nf(  
   short volatile * Addend,  
   short Value  
);  
__int64 _InterlockedExchangeAdd64(  
   __int64 volatile * Addend,  
   __int64 Value  
);  
__int64 _InterlockedExchangeAdd64_acq(  
   __int64 volatile * Addend,  
   __int64 Value  
);  
__int64 _InterlockedExchangeAdd64_rel(  
   __int64 volatile * Addend,  
   __int64 Value  
);  
__int64 _InterlockedExchangeAdd64_nf(  
   __int64 volatile * Addend,  
   __int64 Value  
);  
__int64 _InterlockedExchangeAdd64_HLEAcquire(  
   __int64 volatile * Addend,  
   __int64 Value  
);  
__int64 _InterlockedExchangeAdd64_HLERelease(  
   __int64 volatile * Addend,  
   __int64 Value  
);  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in, out] `Addend`  
 O valor a ser adicionado; substituído pelo resultado da adição.  
  
 [in] `Value`  
 O valor a ser adicionado.  
  
## <a name="return-value"></a>Valor de retorno  
 O valor retornado é o valor inicial da variável que aponta para o parâmetro `Addend`.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|Cabeçalho|  
|---------------|------------------|------------|  
|`_InterlockedExchangeAdd`, `_InterlockedExchangeAdd8`, `_InterlockedExchangeAdd16`, `_InterlockedExchangeAdd64`|x86, ARM, x64|\<intrin.h>|  
|`_InterlockedExchangeAdd_acq`, `_InterlockedExchangeAdd_rel`, `_InterlockedExchangeAdd_nf`, `_InterlockedExchangeAdd8_acq`, `_InterlockedExchangeAdd8_rel`, `_InterlockedExchangeAdd8_nf`,`_InterlockedExchangeAdd16_acq`, `_InterlockedExchangeAdd16_rel`, `_InterlockedExchangeAdd16_nf`, `_InterlockedExchangeAdd64_acq`, `_InterlockedExchangeAdd64_rel`, `_InterlockedExchangeAdd64_nf`|ARM|\<intrin.h>|  
|`_InterlockedExchangeAdd_HLEAcquire`, `_InterlockedExchangeAdd_HLERelease`, `_InterlockedExchangeAdd64_HLEAcquire`, `_InterlockedExchangeAdd64_HLErelease`|x86, x64|\<immintrin.h>|  
  
## <a name="remarks"></a>Comentários  
 Há diversas variações em `_InterlockedExchangeAdd` que têm base no tipo de dados que envolvem e se a semântica acquire ou release é usada.  
  
 Enquanto a função `_InterlockedExchangeAdd` opera em valores inteiros de 32 bits, `_InterlockedExchangeAdd8` opera em valores inteiros de 8 bits, `_InterlockedExchangeAdd16` opera em valores inteiros de 16 bits e `_InterlockedExchangeAdd64` opera em valores inteiros de 64 bits.  
  
 Em plataformas ARM, use intrínsecos com os sufixos `_acq` e `_rel` para semântica de aquisição e liberação, como no início e no final de uma seção crítica. Os intrínsecos com um sufixo `_nf` ("no fence") não funcionam como uma barreira de memória.  
  
 Em plataformas Intel que suportam instruções HLE (Elisão de Bloqueio de Hardware), intrínsecos com os sufixos `_HLEAcquire` e `_HLERelease` incluem uma dica para o processador que pode acelerar o desempenho, eliminando uma etapa de gravação de bloqueio no hardware. Se esses intrínsecos forem chamados em plataformas que não dão suporte a HLE, a dica será ignorada.  
  
 Essas rotinas somente estão disponíveis como intrínsecos. Assim, eles são intrínsecos se ou não [/Oi](../build/reference/oi-generate-intrinsic-functions.md) ou [#pragma intrínseco](../preprocessor/intrinsic.md) é usado. Não é possível usar [#pragma função](../preprocessor/function-c-cpp.md) nesses intrínsecos.  
  
## <a name="example"></a>Exemplo  
 Para obter um exemplo de como usar `_InterlockedExchangeAdd`, consulte [interlockeddecrement](../intrinsics/interlockeddecrement-intrinsic-functions.md).  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [conflitos com o compilador x86](../build/conflicts-with-the-x86-compiler.md)