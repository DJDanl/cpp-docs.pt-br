---
title: "Estrutura atomic_flag | Microsoft Docs"
ms.custom: ""
ms.date: "11/04/2016"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "atomic/std::atomic_flag"
dev_langs: 
  - "C++"
ms.assetid: 17f0c2f5-fd39-4a44-873a-b569720a670e
caps.latest.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
translation.priority.ht: 
  - "cs-cz"
  - "de-de"
  - "es-es"
  - "fr-fr"
  - "it-it"
  - "ja-jp"
  - "ko-kr"
  - "pl-pl"
  - "pt-br"
  - "ru-ru"
  - "tr-tr"
  - "zh-cn"
  - "zh-tw"
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
|[Método atomic_flag::clear](#atomic_flag__clear_method)|Define o sinalizador armazenado como `false`.|  
|[Método atomic_flag::test_and_set](#atomic_flag__test_and_set_method)|Define o sinalizador armazenado como `true` e retorna o valor de sinalizador inicial.|  
  
## <a name="remarks"></a>Comentários  
 Objetos `atomic_flag` podem ser passados para as funções não membro [atomic_flag_clear](../standard-library/atomic-functions.md#atomic_flag_clear_function), [atomic_flag_clear_explicit](../standard-library/atomic-functions.md#atomic_flag_clear_explicit_function), [atomic_flag_test_and_set](../standard-library/atomic-functions.md#atomic_flag_test_and_set_function) e [atomic_flag_test_and_set_explicit](../standard-library/atomic-functions.md#atomic_flag_test_and_set_explicit_function). Eles podem ser inicializados usando o valor `ATOMIC_FLAG_INIT`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atômico  
  
 **Namespace:** std  
  
##  <a name="a-nameatomicflagclearmethoda--atomicflagclear-method"></a><a name="atomic_flag__clear_method"></a>Método atomic_flag::clear  
 Define o sinalizador `bool` que é armazenado em `*this` para `false`, dentro das restrições [memory_order](../standard-library/atomic-enums.md#memory_order_enum) especificadas.  
  
```
void atomic_flag::clear(memory_order Order = memory_order_seq_cst) volatile noexcept;
void atomic_flag::clear(memory_order Order = memory_order_seq_cst) noexcept;
```  
  
### <a name="parameters"></a>Parâmetros  
 `Order`  
 Uma [memory_order](../standard-library/atomic-enums.md#memory_order_enum).  
  
##  <a name="a-nameatomicflagtestandsetmethoda--atomicflagtestandset-method"></a><a name="atomic_flag__test_and_set_method"></a>Método atomic_flag::test_and_set  
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



