---
title: Estrutura atomic_flag | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- atomic/std::atomic_flag
- atomic/std::atomic_flag::clear
- atomic/std::atomic_flag::test_and_set
dev_langs:
- C++
ms.assetid: 17f0c2f5-fd39-4a44-873a-b569720a670e
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8774bcc4b95e2b5c0160843100405f33010b98b6
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="atomicflag-structure"></a>Estrutura atomic_flag
Descreve um objeto que define e limpa atomicamente um sinalizador `bool`. Operações em sinalizadores atômicos são sempre livres de bloqueio.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct atomic_flag;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[clear](#clear)|Define o sinalizador armazenado como `false`.|  
|[test_and_set](#test_and_set)|Define o sinalizador armazenado como `true` e retorna o valor de sinalizador inicial.|  
  
## <a name="remarks"></a>Comentários  
 Objetos `atomic_flag` podem ser passados para as funções não membro [atomic_flag_clear](../standard-library/atomic-functions.md#atomic_flag_clear), [atomic_flag_clear_explicit](../standard-library/atomic-functions.md#atomic_flag_clear_explicit), [atomic_flag_test_and_set](../standard-library/atomic-functions.md#atomic_flag_test_and_set) e [atomic_flag_test_and_set_explicit](../standard-library/atomic-functions.md#atomic_flag_test_and_set_explicit). Eles podem ser inicializados usando o valor `ATOMIC_FLAG_INIT`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<atômico >  
  
 **Namespace:** std  
  
##  <a name="clear"></a>  atomic_flag::clear
 Define o sinalizador `bool` que é armazenado em `*this` para `false`, dentro das restrições [memory_order](../standard-library/atomic-enums.md#memory_order_enum) especificadas.  
  
```
void atomic_flag::clear(memory_order Order = memory_order_seq_cst) volatile noexcept;
void atomic_flag::clear(memory_order Order = memory_order_seq_cst) noexcept;
```  
  
### <a name="parameters"></a>Parâmetros  
 `Order`  
 Uma [memory_order](../standard-library/atomic-enums.md#memory_order_enum).  
  
##  <a name="test_and_set"></a>  atomic_flag::test_and_set
 Define o sinalizador `bool` que é armazenado em `*this` para `true`, dentro das restrições [memory_order](../standard-library/atomic-enums.md#memory_order_enum) especificadas.  
  
```
bool atomic_flag::test_and_set(memory_order Order = memory_order_seq_cst) volatile noexcept;
bool atomic_flag::test_and_set(memory_order Order = memory_order_seq_cst) noexcept;
```  
  
### <a name="parameters"></a>Parâmetros  
 `Order`  
 Uma [memory_order](../standard-library/atomic-enums.md#memory_order_enum).  
  
### <a name="return-value"></a>Valor de retorno  
 O valor inicial do sinalizador armazenado em `*this`.  
  
## <a name="see-also"></a>Consulte também  
 [\<atomic>](../standard-library/atomic.md)



