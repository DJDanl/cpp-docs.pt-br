---
title: Classe promise | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- future/std::promise
dev_langs:
- C++
ms.assetid: 2931558c-d94a-4ba1-ac4f-20bf7b6e23f9
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: ad79ecc3497182a451ef85ea53c8ec5603fdca69
ms.lasthandoff: 02/25/2017

---
# <a name="promise-class"></a>Classe promise
Descreve um *provedor assíncrono*.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Ty>
class promise;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor promise::promise](#promise__promise_constructor)|Constrói um objeto `promise`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[promise::get_future](#promise__get_future_method)|Retorna um [future](../standard-library/future-class.md) associado a essa promessa.|  
|[promise::set_exception](#promise__set_exception_method)|Define atomicamente o resultado dessa promessa para indicar uma exceção.|  
|[promise::set_exception_at_thread_exit](#promise__set_exception_at_thread_exit_method)|Define o resultado desta promessa atomicamente para indicar uma exceção e entrega a notificação somente depois que todos os objetos thread-local no thread atual forem destruídos (normalmente na saída do thread).|  
|[promise::set_value](#promise__set_value_method)|Define atomicamente o resultado dessa promessa para indicar um valor.|  
|[promise::set_value_at_thread_exit](#promise__set_value_at_thread_exit_method)|Define o resultado desta promessa atomicamente para indicar um valor e entrega a notificação somente depois que todos os objetos thread-local no thread atual forem destruídos (normalmente na saída do thread).|  
|[promise::swap](#promise__swap_method)|Troca o *estado assíncrono associado* desta promessa por um de um objeto de promessa especificado.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[promise::operator=](#promise__operator_eq)|Atribuição do estado compartilhado desse objeto de promessa.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `promise`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** future  
  
 **Namespace:** std  
  
##  <a name="a-namepromisegetfuturemethoda--promisegetfuture"></a><a name="promise__get_future_method"></a>  promise::get_future  
 Retorna um objeto [future](../standard-library/future-class.md) que tem o mesmo *estado assíncrono associado* que esta promessa.  
  
```
future<Ty> get_future();
```  
  
### <a name="remarks"></a>Comentários  
 Se o objeto de promessa estiver vazio, esse método gera um [future_error](../standard-library/future-error-class.md) que tem um [error_code](../standard-library/error-code-class.md) de `no_state`.  
  
 Se esse método já foi chamado para um objeto de promessa que tem o mesmo estado assíncrono associado, o método gerará um `future_error` que tem um `error_code` de `future_already_retrieved`.  
  
##  <a name="a-namepromiseoperatoreqa--promiseoperator"></a><a name="promise__operator_eq"></a>  promise::operator=  
 Transfere o *estado assíncrono associado* de um objeto `promise` especificado.  
  
```
promise& operator=(promise&& Other) noexcept;
```  
  
### <a name="parameters"></a>Parâmetros  
 `Other`  
 Um objeto `promise`.  
  
### <a name="return-value"></a>Valor de retorno  
 `*this`  
  
### <a name="remarks"></a>Comentários  
 Este operador transfere o estado assíncrono associado de `Other`. Após a transferência, `Other` estará *empty*.  
  
##  <a name="a-namepromisepromiseconstructora--promisepromise-constructor"></a><a name="promise__promise_constructor"></a>Construtor promise::promise  
 Constrói um objeto `promise`.  
  
```
promise();
template <class Alloc>
promise(allocator_arg_t, const Alloc& Al);
promise(promise&& Other) noexcept;
```  
  
### <a name="parameters"></a>Parâmetros  
 `Al`  
 Um alocador de memória. Consulte [\<allocators>](../standard-library/allocators-header.md) para obter mais informações.  
  
 `Other`  
 Um objeto `promise`.  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor cria um objeto *empty*`promise`.  
  
 O segundo construtor cria um objeto `promise` vazio e usa `Al` para alocação de memória.  
  
 O terceiro construtor cria um objeto `promise` e transfere o estado assíncrono associado de `Other` e deixa `Other` vazio.  
  
##  <a name="a-namepromisesetexceptionmethoda--promisesetexception"></a><a name="promise__set_exception_method"></a>  promise::set_exception  
 Armazena atomicamente uma exceção como resultado desse objeto `promise` e define o *estado assíncrono associado* como *ready*.  
  
```
void set_exception(exception_ptr Exc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Exc`  
 Um [exception_ptr](../standard-library/exception-typedefs.md#exception_ptr) que é armazenado por esse método como o resultado da exceção.  
  
### <a name="remarks"></a>Comentários  
 Se o objeto `promise` não tiver nenhum estado assíncrono associado, esse método gerará um [future_error](../standard-library/future-error-class.md) com código de erro `no_state`.  
  
 Se `set_exception`, [set_exception_at_thread_exit](#promise__set_exception_at_thread_exit_method), [set_value](#promise__set_value_method) ou [set_value_at_thread_exit](#promise__set_value_at_thread_exit_method) já tiver sido chamado para um objeto `promise` que tem o mesmo estado assíncrono associado, esse método gera um `future_error` com código de erro `promise_already_satisfied`.  
  
 Como resultado desse método, os threads bloqueados no estado assíncrono associado são desbloqueados.  
  
##  <a name="a-namepromisesetexceptionatthreadexitmethoda--promisesetexceptionatthreadexit"></a><a name="promise__set_exception_at_thread_exit_method"></a>  promise::set_exception_at_thread_exit  
 Define o resultado desse `promise` atomicamente para indicar uma exceção, entregando a notificação somente depois que todos os objetos thread-local no thread atual forem destruídos (normalmente na saída do thread).  
  
```
void set_exception_at_thread_exit(exception_ptr Exc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Exc`  
 Um [exception_ptr](../standard-library/exception-typedefs.md#exception_ptr) que é armazenado por esse método como o resultado da exceção.  
  
### <a name="remarks"></a>Comentários  
 Se o objeto de promessa não tiver nenhum *estado assíncrono associado*, esse método gera um [future_error](../standard-library/future-error-class.md) com um código de erro `no_state`.  
  
 Se [set_exception](#promise__set_exception_method), `set_exception_at_thread_exit`, [set_value](#promise__set_value_method) ou [set_value_at_thread_exit](#promise__set_value_at_thread_exit_method) já tiver sido chamado para um objeto `promise` que tem o mesmo estado assíncrono associado, esse método gera um `future_error` com código de erro `promise_already_satisfied`.  
  
 Ao contrário de [set_exception](#promise__set_exception_method), esse método não define o estado assíncrono associado como pronto até todos os objetos thread-local no thread atual tenham sido destruídos. Normalmente, threads bloqueados no estado assíncrono associado não são desbloqueados até que o thread atual seja encerrado.  
  
##  <a name="a-namepromisesetvaluemethoda--promisesetvalue"></a><a name="promise__set_value_method"></a>  promise::set_value  
 Armazena atomicamente um valor como o resultado desse objeto `promise` e define o *estado assíncrono associado* como *ready*.  
  
```
void promise::set_value(const Ty& Val);
void promise::set_value(Ty&& Val);
void promise<Ty&>::set_value(Ty& Val);
void promise<void>::set_value();
```  
  
### <a name="parameters"></a>Parâmetros  
 `Val`  
 O valor a ser armazenado como o resultado.  
  
### <a name="remarks"></a>Comentários  
 Se o objeto `promise` não tiver nenhum estado assíncrono associado, esse método gerará um [future_error](../standard-library/future-error-class.md) com código de erro `no_state`.  
  
 Se [set_exception](#promise__set_exception_method), [set_exception_at_thread_exit](#promise__set_exception_at_thread_exit_method), `set_value` ou [set_value_at_thread_exit](#promise__set_value_at_thread_exit_method) já tiver sido chamado para um objeto `promise` que tem o mesmo estado assíncrono associado, esse método gera um `future_error` com código de erro `promise_already_satisfied`.  
  
 Como resultado desse método, os threads bloqueados no estado assíncrono associado são desbloqueados.  
  
 O primeiro método também gera qualquer exceção que é gerada quando `Val` é copiado para o estado assíncrono associado. Nessa situação, o estado assíncrono associado não está definido como pronto.  
  
 O segundo método também gera qualquer exceção que é gerada quando `Val` é movido para o estado assíncrono associado. Nessa situação, o estado assíncrono associado não está definido como pronto.  
  
 Para a especialização parcial `promise<Ty&>`, o valor armazenado em vigor é uma referência a `Val`.  
  
 Para a especialização `promise<void>`, não existe nenhum valor armazenado.  
  
##  <a name="a-namepromisesetvalueatthreadexitmethoda--promisesetvalueatthreadexit"></a><a name="promise__set_value_at_thread_exit_method"></a>  promise::set_value_at_thread_exit  
 Armazena atomicamente um valor como o resultado deste objeto `promise`.  
  
```
void promise::set_value_at_thread_exit(const Ty& Val);
void promise::set_value_at_thread_exit(Ty&& Val);
void promise<Ty&>::set_value_at_thread_exit(Ty& Val);
void promise<void>::set_value_at_thread_exit();
```  
  
### <a name="parameters"></a>Parâmetros  
 `Val`  
 O valor a ser armazenado como o resultado.  
  
### <a name="remarks"></a>Comentários  
 Se o objeto de promessa não tiver nenhum *estado assíncrono associado*, esse método gera um [future_error](../standard-library/future-error-class.md) com um código de erro `no_state`.  
  
 Se [set_exception](#promise__set_exception_method), [set_exception_at_thread_exit](#promise__set_exception_at_thread_exit_method), [set_value](#promise__set_value_method) ou `set_value_at_thread_exit` já tiver sido chamado para um objeto `promise` que tem o mesmo estado assíncrono associado, esse método gera um `future_error` com código de erro `promise_already_satisfied`.  
  
 Ao contrário de `set_value`, o estado assíncrono associado não é definido como pronto até que todos os objetos thread-local no thread atual tenham sido destruídos. Normalmente, threads bloqueados no estado assíncrono associado não são desbloqueados até que o thread atual seja encerrado.  
  
 O primeiro método também gera qualquer exceção que é gerada quando `Val` é copiado para o estado assíncrono associado.  
  
 O segundo método também gera qualquer exceção que é gerada quando `Val` é movido para o estado assíncrono associado.  
  
 Para a especialização parcial `promise<Ty&>`, o valor armazenado é efetivamente uma referência a `Val`.  
  
 Para a especialização `promise<void>`, não existe nenhum valor armazenado.  
  
##  <a name="a-namepromiseswapmethoda--promiseswap"></a><a name="promise__swap_method"></a>  promise::swap  
 Troca o *estado assíncrono associado* deste objeto de promessa por um de um objeto de promessa especificado.  
  
```
void swap(promise& Other) noexcept;
```  
  
### <a name="parameters"></a>Parâmetros  
 `Other`  
 Um objeto `promise`.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)




 


