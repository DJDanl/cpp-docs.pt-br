---
title: _InterlockedAddLargeStatistic | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- _InterlockedAddLargeStatistic
- _InterlockedAddLargeStatistic_cpp
dev_langs:
- C++
helpviewer_keywords:
- _InterlockedAddLargeStatistic intrinsic
- InterlockedAddLargeStatistic intrinsic
ms.assetid: 2802e74b-bcee-46e4-b562-894908d44409
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: fa3a9a88520516051b067d45f4e18a92946c1346
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="interlockedaddlargestatistic"></a>_InterlockedAddLargeStatistic
**Seção específica da Microsoft**  
  
 Executa uma adição interlocked em que o primeiro operando é um valor de 64 bits.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
long _InterlockedAddLargeStatistic(  
   __int64 volatile * Addend,  
   long Value  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in, out] `Addend`  
 Um ponteiro para o primeiro operando com a operação de adição. O valor apontado é substituído pelo resultado da adição.  
  
 [in] `Value`  
 O segundo operando; valor a ser adicionado para o primeiro operando.  
  
## <a name="return-value"></a>Valor de retorno  
 O valor do segundo operando.  
  
## <a name="requirements"></a>Requisitos  
  
|Intrínseco|Arquitetura|  
|---------------|------------------|  
|`_InterlockedAddLargeStatistic`|x86|  
  
 **Arquivo de cabeçalho** \<intrin.h >  
  
## <a name="remarks"></a>Comentários  
 Nesse intrínseco não é atômico porque ele é implementado como dois separam instruções bloqueadas. Uma leitura de 64 bits atômica que ocorre em outro thread durante a execução deste intrínseco pode resultar em um valor inconsistente sendo lido.  
  
 Essa função se comporta como uma barreira de leitura / gravação. Para obter mais informações, consulte [readwritebarrier](../intrinsics/readwritebarrier.md).  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [conflitos com o compilador x86](../build/conflicts-with-the-x86-compiler.md)