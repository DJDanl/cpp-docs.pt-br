---
title: Classe packaged_task | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- future/std::packaged_task
- future/std::packaged_task::packaged_task
- future/std::packaged_task::get_future
- future/std::packaged_task::make_ready_at_thread_exit
- future/std::packaged_task::reset
- future/std::packaged_task::swap
- future/std::packaged_task::valid
- future/std::packaged_task::operator()
- future/std::packaged_task::operator bool
dev_langs:
- C++
ms.assetid: 0a72cbe3-f22a-4bfe-8e50-dcb268c98780
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
helpviewer_keywords:
- std::packaged_task [C++]
- std::packaged_task [C++], packaged_task
- std::packaged_task [C++], get_future
- std::packaged_task [C++], make_ready_at_thread_exit
- std::packaged_task [C++], reset
- std::packaged_task [C++], swap
- std::packaged_task [C++], valid
ms.workload:
- cplusplus
ms.openlocfilehash: 6ce3db6f4685d8448efd88bf2203d541cc864abd
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="packagedtask-class"></a>Classe packaged_task
Descreve um *provedor assíncrono* que é um wrapper de chamada e cuja assinatura de chamada é `Ty(ArgTypes...)`. O *estado assíncrono associado* mantém uma cópia de seu objeto que pode ser chamado, bem como o possível resultado.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class>
class packaged_task;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[packaged_task](#packaged_task)|Constrói um objeto `packaged_task`.|  
|[Destruidor packaged_task::~packaged_task](#dtorpackaged_task_destructor)|Destrói um objeto `packaged_task`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[get_future](#get_future)|Retorna um objeto [future](../standard-library/future-class.md) que tem o mesmo estado assíncrono associado.|  
|[make_ready_at_thread_exit](#make_ready_at_thread_exit)|Chama o objeto callable que é armazenado no estado assíncrono associado e armazena atomicamente o valor retornado.|  
|[reset](#reset)|Substitui o estado assíncrono associado.|  
|[swap](#swap)|Troca o estado assíncrono associado por aquele de um objeto especificado.|  
|[valid](#valid)|Especifica se o objeto tem um estado assíncrono associado.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[packaged_task::operator=](#op_eq)|Transfere o estado assíncrono associado de um objeto especificado.|  
|[packaged_task::operator()](#op_call)|Chama o objeto callable que é armazenado no estado assíncrono associado, armazena atomicamente o valor retornado e define o estado como *ready*.|  
|[packaged_task::operator bool](#op_bool)|Especifica se o objeto tem um estado assíncrono associado.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<futuro >  
  
 **Namespace:** std  
  
##  <a name="get_future"></a>  packaged_task::get_future  
 Retorna um objeto do tipo `future<Ty>` que tem o mesmo *estado assíncrono associado*.  
  
```
future<Ty> get_future();
```  
  
### <a name="remarks"></a>Comentários  
 Se o objeto `packaged_task` não tiver nenhum estado assíncrono associado, esse método gerará um [future_error](../standard-library/future-error-class.md) com código de erro `no_state`.  
  
 Se esse método já foi chamado para um objeto `packaged_task` que tem o mesmo estado assíncrono associado, o método gerará um `future_error` com código de erro `future_already_retrieved`.  
  
##  <a name="make_ready_at_thread_exit"></a>  packaged_task::make_ready_at_thread_exit  
 Chama o objeto callable que é armazenado no *estado assíncrono associado* e armazena atomicamente o valor retornado.  
  
```
void make_ready_at_thread_exit(ArgTypes... args);
```  
  
### <a name="remarks"></a>Comentários  
 Se o objeto `packaged_task` não tiver nenhum estado assíncrono associado, esse método gerará um [future_error](../standard-library/future-error-class.md) com código de erro `no_state`.  
  
 Se este método ou [make_ready_at_thread_exit](#make_ready_at_thread_exit) já tiver sido chamado para um objeto `packaged_task` que tem o mesmo estado assíncrono associado, esse método gera um `future_error` com código de erro `promise_already_satisfied`.  
  
 Caso contrário, este operador chama `INVOKE(fn, args..., Ty)`, em que *fn* é o objeto callable que é armazenado no estado assíncrono associado. Qualquer valor retornado é armazenado automaticamente como o resultado retornado do estado assíncrono associado.  
  
 Em contraste com [packaged_task::operator()](#op_call), o estado assíncrono associado não é definido como `ready` até todos os objetos thread-local no thread de chamada tenham sido destruídos. Normalmente, threads bloqueados no estado assíncrono associado não são desbloqueados até que o thread de chamada seja encerrado.  
  
##  <a name="op_eq"></a>  packaged_task::operator=  
 Transfere o *estado assíncrono associado* de um objeto especificado.  
  
```
packaged_task& operator=(packaged_task&& Right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Right`  
 Um objeto `packaged_task`.  
  
### <a name="return-value"></a>Valor de retorno  
 `*this`  
  
### <a name="remarks"></a>Comentários  
 Após a operação, `Right` não tem mais um estado assíncrono associado.  
  
##  <a name="op_call"></a>  packaged_task::operator()  
 Chama o objeto callable que é armazenado no *estado assíncrono associado*, armazena atomicamente o valor retornado e define o estado como *ready*.  
  
```
void operator()(ArgTypes... args);
```  
  
### <a name="remarks"></a>Comentários  
 Se o objeto `packaged_task` não tiver nenhum estado assíncrono associado, esse método gerará um [future_error](../standard-library/future-error-class.md) com código de erro `no_state`.  
  
 Se este método ou [make_ready_at_thread_exit](#make_ready_at_thread_exit) já tiver sido chamado para um objeto `packaged_task` que tem o mesmo estado assíncrono associado, esse método gera um `future_error` com código de erro `promise_already_satisfied`.  
  
 Caso contrário, este operador chama `INVOKE(fn, args..., Ty)`, em que *fn* é o objeto callable que é armazenado no estado assíncrono associado. Qualquer valor retornado é armazenado atomicamente como o resultado retornado do estado assíncrono associado e o estado é definido como ready. Como resultado, os threads bloqueados no estado assíncrono associado são desbloqueados.  
  
##  <a name="op_bool"></a>  packaged_task::operator bool  
 Especifica se o objeto tem um `associated asynchronous state`.  
  
```
operator bool() const noexcept;
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o objeto tiver um estado assíncrono associado; caso contrário, `false`.  
  
##  <a name="packaged_task"></a>  Construtor packaged_task::packaged_task  
 Constrói um objeto `packaged_task`.  
  
```
packaged_task() noexcept;
packaged_task(packaged_task&& Right) noexcept;
template <class Fn>
   explicit packaged_task(Fn&& fn);

template <class Fn, class Alloc>
   explicit packaged_task(
      allocator_arg_t, const Alloc& alloc, Fn&& fn);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Right`  
 Um objeto `packaged_task`.  
  
 `alloc`  
 Um alocador de memória. Para obter mais informações, consulte [\<allocators>](../standard-library/allocators-header.md).  
  
 `fn`  
 Um objeto de função.  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor cria um objeto `packaged_task` que não tem nenhum *estado assíncrono associado*.  
  
 O segundo construtor cria um objeto `packaged_task` e transfere o estado assíncrono associado de `Right`. Após a operação, `Right` não tem mais um estado assíncrono associado.  
  
 O terceiro construtor cria um objeto `packaged_task` que tem uma cópia de `fn` armazenada em seu estado assíncrono associado.  
  
 O quarto construtor cria um objeto `packaged_task` que tem uma cópia de `fn` armazenada em seu estado assíncrono associado e usa `alloc` para alocação de memória.  
  
##  <a name="dtorpackaged_task_destructor"></a>  Destruidor packaged_task::~packaged_task  
 Destrói um objeto `packaged_task`.  
  
```
~packaged_task();
```  
  
### <a name="remarks"></a>Comentários  
 Se o *estado assíncrono associado* não estiver *ready*, o destruidor armazena uma exceção [future_error](../standard-library/future-error-class.md) com um código de erro de `broken_promise` como resultado no estado assíncrono associado e os threads bloqueados no estado assíncrono associado são desbloqueados.  
  
##  <a name="reset"></a>  packaged_task::reset  
 Usa um novo *estado assíncrono associado* para substituir o estado assíncrono associado existente.  
  
```
void reset();
```  
  
### <a name="remarks"></a>Comentários  
 Na verdade, esse método executa `*this = packaged_task(move(fn))`, em que *fn* é o objeto de função que é armazenado no estado assíncrono associado a este objeto. Portanto, o estado do objeto é desmarcado e [get_future](#get_future), [operator()](#op_call) e [make_ready_at_thread_exit](#make_ready_at_thread_exit) podem ser chamados como se estivesse em um objeto recém-criado.  
  
##  <a name="swap"></a>  packaged_task::swap  
 Troca o estado assíncrono associado por aquele de um objeto especificado.  
  
```
void swap(packaged_task& Right) noexcept;
```  
  
### <a name="parameters"></a>Parâmetros  
 `Right`  
 Um objeto `packaged_task`.  
  
##  <a name="valid"></a>  packaged_task::valid  
 Especifica se o objeto tem um `associated asynchronous state`.  
  
```
bool valid() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o objeto tiver um estado assíncrono associado; caso contrário, `false`.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<future>](../standard-library/future.md)



