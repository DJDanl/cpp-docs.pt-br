---
title: Classe promise | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- future/std::promise
- future/std::promise::promise
- future/std::promise::get_future
- future/std::promise::set_exception
- future/std::promise::set_exception_at_thread_exit
- future/std::promise::set_value
- future/std::promise::set_value_at_thread_exit
- future/std::promise::swap
dev_langs:
- C++
ms.assetid: 2931558c-d94a-4ba1-ac4f-20bf7b6e23f9
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
helpviewer_keywords:
- std::promise [C++]
- std::promise [C++], promise
- std::promise [C++], get_future
- std::promise [C++], set_exception
- std::promise [C++], set_exception_at_thread_exit
- std::promise [C++], set_value
- std::promise [C++], set_value_at_thread_exit
- std::promise [C++], swap
ms.workload:
- cplusplus
ms.openlocfilehash: 6673483beb2552ba1b3a11b76d65e9be484c2a39
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="promise-class"></a>Classe promise
Descreve um *provedor assíncrono*.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Ty>
class promise;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[promise](#promise)|Constrói um objeto `promise`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[get_future](#get_future)|Retorna um [future](../standard-library/future-class.md) associado a essa promessa.|  
|[set_exception](#set_exception)|Define atomicamente o resultado dessa promessa para indicar uma exceção.|  
|[set_exception_at_thread_exit](#set_exception_at_thread_exit)|Define o resultado desta promessa atomicamente para indicar uma exceção e entrega a notificação somente depois que todos os objetos thread-local no thread atual forem destruídos (normalmente na saída do thread).|  
|[set_value](#set_value)|Define atomicamente o resultado dessa promessa para indicar um valor.|  
|[set_value_at_thread_exit](#set_value_at_thread_exit)|Define o resultado desta promessa atomicamente para indicar um valor e entrega a notificação somente depois que todos os objetos thread-local no thread atual forem destruídos (normalmente na saída do thread).|  
|[swap](#swap)|Troca o *estado assíncrono associado* desta promessa por um de um objeto de promessa especificado.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[promise::operator=](#op_eq)|Atribuição do estado compartilhado desse objeto de promessa.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `promise`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<futuro >  
  
 **Namespace:** std  
  
##  <a name="get_future"></a>  promise::get_future  
 Retorna um objeto [future](../standard-library/future-class.md) que tem o mesmo *estado assíncrono associado* que esta promessa.  
  
```
future<Ty> get_future();
```  
  
### <a name="remarks"></a>Comentários  
 Se o objeto de promessa estiver vazio, esse método gera um [future_error](../standard-library/future-error-class.md) que tem um [error_code](../standard-library/error-code-class.md) de `no_state`.  
  
 Se esse método já foi chamado para um objeto de promessa que tem o mesmo estado assíncrono associado, o método gerará um `future_error` que tem um `error_code` de `future_already_retrieved`.  
  
##  <a name="op_eq"></a>  promise::operator=  
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
  
##  <a name="promise"></a>Construtor promise::promise  
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
  
##  <a name="set_exception"></a>  promise::set_exception  
 Armazena atomicamente uma exceção como resultado desse objeto `promise` e define o *estado assíncrono associado* como *ready*.  
  
```
void set_exception(exception_ptr Exc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Exc`  
 Um [exception_ptr](../standard-library/exception-typedefs.md#exception_ptr) que é armazenado por esse método como o resultado da exceção.  
  
### <a name="remarks"></a>Comentários  
 Se o objeto `promise` não tiver nenhum estado assíncrono associado, esse método gerará um [future_error](../standard-library/future-error-class.md) com código de erro `no_state`.  
  
 Se `set_exception`, [set_exception_at_thread_exit](#set_exception_at_thread_exit), [set_value](#set_value) ou [set_value_at_thread_exit](#set_value_at_thread_exit) já tiver sido chamado para um objeto `promise` que tem o mesmo estado assíncrono associado, esse método gera um `future_error` com código de erro `promise_already_satisfied`.  
  
 Como resultado desse método, os threads bloqueados no estado assíncrono associado são desbloqueados.  
  
##  <a name="set_exception_at_thread_exit"></a>  promise::set_exception_at_thread_exit  
 Define o resultado desse `promise` atomicamente para indicar uma exceção, entregando a notificação somente depois que todos os objetos thread-local no thread atual forem destruídos (normalmente na saída do thread).  
  
```
void set_exception_at_thread_exit(exception_ptr Exc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Exc`  
 Um [exception_ptr](../standard-library/exception-typedefs.md#exception_ptr) que é armazenado por esse método como o resultado da exceção.  
  
### <a name="remarks"></a>Comentários  
 Se o objeto de promessa não tiver nenhum *estado assíncrono associado*, esse método gera um [future_error](../standard-library/future-error-class.md) com um código de erro `no_state`.  
  
 Se [set_exception](#set_exception), `set_exception_at_thread_exit`, [set_value](#set_value) ou [set_value_at_thread_exit](#set_value_at_thread_exit) já tiver sido chamado para um objeto `promise` que tem o mesmo estado assíncrono associado, esse método gera um `future_error` com código de erro `promise_already_satisfied`.  
  
 Ao contrário de [set_exception](#set_exception), esse método não define o estado assíncrono associado como pronto até todos os objetos thread-local no thread atual tenham sido destruídos. Normalmente, threads bloqueados no estado assíncrono associado não são desbloqueados até que o thread atual seja encerrado.  
  
##  <a name="set_value"></a>  promise::set_value  
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
  
 Se [set_exception](#set_exception), [set_exception_at_thread_exit](#set_exception_at_thread_exit), `set_value` ou [set_value_at_thread_exit](#set_value_at_thread_exit) já tiver sido chamado para um objeto `promise` que tem o mesmo estado assíncrono associado, esse método gera um `future_error` com código de erro `promise_already_satisfied`.  
  
 Como resultado desse método, os threads bloqueados no estado assíncrono associado são desbloqueados.  
  
 O primeiro método também gera qualquer exceção que é gerada quando `Val` é copiado para o estado assíncrono associado. Nessa situação, o estado assíncrono associado não está definido como pronto.  
  
 O segundo método também gera qualquer exceção que é gerada quando `Val` é movido para o estado assíncrono associado. Nessa situação, o estado assíncrono associado não está definido como pronto.  
  
 Para a especialização parcial `promise<Ty&>`, o valor armazenado em vigor é uma referência a `Val`.  
  
 Para a especialização `promise<void>`, não existe nenhum valor armazenado.  
  
##  <a name="set_value_at_thread_exit"></a>  promise::set_value_at_thread_exit  
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
  
 Se [set_exception](#set_exception), [set_exception_at_thread_exit](#set_exception_at_thread_exit), [set_value](#set_value) ou `set_value_at_thread_exit` já tiver sido chamado para um objeto `promise` que tem o mesmo estado assíncrono associado, esse método gera um `future_error` com código de erro `promise_already_satisfied`.  
  
 Ao contrário de `set_value`, o estado assíncrono associado não é definido como pronto até que todos os objetos thread-local no thread atual tenham sido destruídos. Normalmente, threads bloqueados no estado assíncrono associado não são desbloqueados até que o thread atual seja encerrado.  
  
 O primeiro método também gera qualquer exceção que é gerada quando `Val` é copiado para o estado assíncrono associado.  
  
 O segundo método também gera qualquer exceção que é gerada quando `Val` é movido para o estado assíncrono associado.  
  
 Para a especialização parcial `promise<Ty&>`, o valor armazenado é efetivamente uma referência a `Val`.  
  
 Para a especialização `promise<void>`, não existe nenhum valor armazenado.  
  
##  <a name="swap"></a>  promise::swap  
 Troca o *estado assíncrono associado* deste objeto de promessa por um de um objeto de promessa especificado.  
  
```
void swap(promise& Other) noexcept;
```  
  
### <a name="parameters"></a>Parâmetros  
 `Other`  
 Um objeto `promise`.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)




 

