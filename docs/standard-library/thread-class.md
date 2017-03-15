---
title: Classe thread | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- thread/std::thread
dev_langs:
- C++
ms.assetid: df249bc7-ff81-4ff9-a6d6-5e3d9a8f56a1
caps.latest.revision: 16
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
ms.openlocfilehash: 848a51faa24498dd1505483894aa47ce959240a7
ms.lasthandoff: 02/25/2017

---
# <a name="thread-class"></a>Classe thread
Define um objeto que é usado para observar e gerenciar um thread de execução em um aplicativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class thread;
```  
  
## <a name="remarks"></a>Comentários  
 É possível usar um objeto `thread` para observar e gerenciar um thread de execução em um aplicativo. Um objeto de thread criado usando o construtor padrão não é associado a nenhum thread de execução. Um objeto de thread construído usando um objeto que pode ser chamado cria um novo thread de execução e chama o objeto que pode ser chamado nesse thread. Os objetos de thread podem ser movidos, mas não copiados. Portanto, um thread de execução pode ser associado apenas a um objeto de thread.  
  
 Cada thread de execução tem um identificador exclusivo do tipo `thread::id`. A função `this_thread::get_id` retorna o identificador do thread de chamada. A função membro `thread::get_id` retorna o identificador do thread gerenciado por um objeto de thread. Para um objeto de thread construído por padrão, o método `thread::get_id` retorna um objeto que tem um valor que é igual para todos os objetos de thread construídos por padrão e diferente do valor retornado por `this_thread::get_id` para qualquer thread de execução que poderá ser unido no momento da chamada.  
  
## <a name="members"></a>Membros  
  
### <a name="public-classes"></a>Classes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Classe thread::id](#thread__id_class)|Identifica exclusivamente o thread associado.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor thread::thread](#thread__thread_constructor)|Constrói um objeto `thread`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método thread::detach](#thread__detach_method)|Desanexa o thread associado do objeto `thread`.|  
|[Método thread::get_id](#thread__get_id_method)|Retorna o identificador exclusivo do thread associado.|  
|[Método thread::hardware_concurrency](#thread__hardware_concurrency_method)|Estático. Retorna uma estimativa do número de contextos de thread de hardware.|  
|[Método thread::join](#thread__join_method)|Bloqueia até que o thread associado seja concluído.|  
|[Método thread::joinable](#thread__joinable_method)|Especifica se o thread associado permite junções.|  
|[Método thread::native_handle](#thread__native_handle_method)|Retorna o tipo específico à implementação que representa o identificador de thread.|  
|[Método thread::swap](#thread__swap_method)|Troca o estado do objeto por um objeto `thread` especificado.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[thread::operator=](#thread__operator_eq)|Associa um thread ao objeto `thread` atual.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** thread  
  
 **Namespace:** std  
  
##  <a name="a-namethreaddetachmethoda--threaddetach-method"></a><a name="thread__detach_method"></a>  Método thread::detach  
 Desanexa o thread associado. O sistema operacional fica responsável por liberar recursos de thread após o encerramento.  
  
```
void detach();
```  
  
### <a name="remarks"></a>Comentários  
 Após uma chamada a `detach`, chamadas posteriores a [get_id](#thread__get_id_method) retornam [id](#thread__id_class).  
  
 Se o thread associado ao objeto de chamada não estiver disponível, a função gerará um [system_error](../standard-library/system-error-class.md) que tem um código de erro `invalid_argument`.  
  
 Se o thread associado ao objeto de chamada for inválido, a função gerará um `system_error` que tem um código de erro `no_such_process`.  
  
##  <a name="a-namethreadgetidmethoda--threadgetid-method"></a><a name="thread__get_id_method"></a>  Método thread::get_id  
 Retorna um identificador exclusivo para o thread associado.  
  
```
id get_id() const noexcept;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um objeto [thread::id](#thread__id_class) que identifica exclusivamente o thread associado ou `thread::id()` se nenhum thread estiver associado ao objeto.  
  
##  <a name="a-namethreadhardwareconcurrencymethoda--threadhardwareconcurrency-method"></a><a name="thread__hardware_concurrency_method"></a>  Método thread::hardware_concurrency  
 Método estático que retorna uma estimativa do número de contextos de thread de hardware.  
  
```
static unsigned int hardware_concurrency() noexcept;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma estimativa do número de contextos de thread de hardware. Se o valor não puder ser calculado ou não estiver bem definido, esse método retornará 0.  
  
##  <a name="a-namethreadidclassa--threadid-class"></a><a name="thread__id_class"></a>  Classe thread::id  
 Fornece um identificador exclusivo para cada thread de execução no processo.  
  
```
class thread::id {
    id() noexcept;
};
```  
  
### <a name="remarks"></a>Comentários  
 O construtor padrão cria um objeto que não é comparado como igual ao objeto `thread::id` em qualquer thread existente.  
  
 Todos os objetos `thread::id` construídos por padrão são comparados como iguais.  
  
##  <a name="a-namethreadjoinmethoda--threadjoin-method"></a><a name="thread__join_method"></a>  Método thread::join  
 Bloqueia até que o thread de execução associado ao objeto de chamada seja concluído.  
  
```
void join();
```  
  
### <a name="remarks"></a>Comentários  
 Se a chamada tiver êxito, as chamadas posteriores a [get_id](#thread__get_id_method) do objeto de chamada retornarão um [thread::id](#thread__id_class) padrão que não é comparado como igual ao `thread::id` de qualquer thread existente; se a chamada não tiver êxito, o valor retornado por `get_id` ficará inalterado.  
  
##  <a name="a-namethreadjoinablemethoda--threadjoinable-method"></a><a name="thread__joinable_method"></a>  Método thread::joinable  
 Especifica se o thread associado *permite junções*.  
  
```
bool joinable() const noexcept;
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o thread associado *permitir junções*; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Um objeto de thread *permitirá junções* se `get_id() != id()`.  
  
##  <a name="a-namethreadnativehandlemethoda--threadnativehandle-method"></a><a name="thread__native_handle_method"></a>  Método thread::native_handle  
 Retorna o tipo específico à implementação que representa o identificador de thread. O identificador de thread pode ser usado de maneiras específicas à implementação.  
  
```
native_handle_type native_handle();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `native_handle_type` é definido como `HANDLE` Win32, que é convertido como `void *`.  
  
##  <a name="a-namethreadoperatoreqa--threadoperator"></a><a name="thread__operator_eq"></a>  thread::operator=  
 Associa o thread de um objeto especificado ao objeto atual.  
  
```
thread& operator=(thread&& Other) noexcept;
```  
  
### <a name="parameters"></a>Parâmetros  
 `Other`  
 Um objeto `thread`.  
  
### <a name="return-value"></a>Valor de retorno  
 `*this`  
  
### <a name="remarks"></a>Comentários  
 As chamadas de método serão desanexadas se o objeto de chamada permitir junções.  
  
 Depois que a associação é feita, `Other` é definido com um estado construído por padrão.  
  
##  <a name="a-namethreadswapmethoda--threadswap-method"></a><a name="thread__swap_method"></a>  Método thread::swap  
 Troca o estado do objeto pelo estado de um objeto `thread` especificado.  
  
```
void swap(thread& Other) noexcept;
```  
  
### <a name="parameters"></a>Parâmetros  
 `Other`  
 Um objeto `thread`.  
  
##  <a name="a-namethreadthreadconstructora--threadthread-constructor"></a><a name="thread__thread_constructor"></a>  Construtor thread::thread  
 Constrói um objeto `thread`.  
  
```
thread() noexcept;
template <class Fn, class... Args>
explicit thread(Fn&& F, Args&&... A);

thread(thread&& Other) noexcept;
```  
  
### <a name="parameters"></a>Parâmetros  
 `F`  
 Uma função definida pelo aplicativo a ser executada pelo thread.  
  
 `A`  
 Uma lista de argumentos a ser passada para `F`.  
  
 `Other`  
 Um objeto `thread` existente.  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor constrói um objeto que não está associado a nenhum thread de execução. O valor retornado por uma chamada a `get_id` do objeto construído é `thread::id()`.  
  
 O segundo construtor constrói um objeto que está associado a um novo thread de execução e executa a pseudofunção `INVOKE` definida em [\<functional>](../standard-library/functional.md). Se não houver recursos suficientes disponíveis para iniciar um novo thread, a função gerará um objeto [system_error](../standard-library/system-error-class.md) que tem um código de erro `resource_unavailable_try_again`. Se a chamada a `F` for encerrada com uma exceção não capturada, [terminate](../standard-library/exception-functions.md#terminate) será chamado.  
  
 O terceiro construtor constrói um objeto que está associado ao thread associado a `Other`. `Other` é então definido com um estado construído por padrão.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<thread>](../standard-library/thread.md)




