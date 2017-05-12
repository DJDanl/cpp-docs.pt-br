---
title: Classe condition_variable_any | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- condition_variable/std::condition_variable_any
- condition_variable/std::condition_variable_any::condition_variable_any
- condition_variable/std::condition_variable_any::notify_all
- condition_variable/std::condition_variable_any::notify_one
- condition_variable/std::condition_variable_any::wait
- condition_variable/std::condition_variable_any::wait_for
- condition_variable/std::condition_variable_any::wait_until
dev_langs:
- C++
ms.assetid: d8afe5db-1561-4ec2-8e85-21ea03ee4321
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 66798adc96121837b4ac2dd238b9887d3c5b7eef
ms.openlocfilehash: 0c72f22ed2962b3d1a200e99ace2c56d69194c78
ms.contentlocale: pt-br
ms.lasthandoff: 04/29/2017

---
# <a name="conditionvariableany-class"></a>Classe condition_variable_any
Use a classe `condition_variable_any` para aguardar um evento que tem qualquer tipo `mutex`.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class condition_variable_any;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[condition_variable_any](#condition_variable_any)|Constrói um objeto `condition_variable_any`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[notify_all](#notify_all)|Desbloqueia todos os threads que estão aguardando o objeto `condition_variable_any`.|  
|[notify_one](#notify_one)|Desbloqueia um dos threads que estão aguardando o objeto `condition_variable_any`.|  
|[Aguarde](#wait)|Bloqueia um thread.|  
|[wait_for](#wait_for)|Bloqueia um thread e define um intervalo de tempo após o qual o thread será desbloqueado.|  
|[wait_until](#wait_until)|Bloqueia um thread e define um ponto máximo no tempo no qual o thread será desbloqueado.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<condition_variable >  
  
 **Namespace:** std  
  
##  <a name="condition_variable_any"></a> Construtor  condition_variable_any::condition_variable_any  
 Constrói um objeto `condition_variable_any`.  
  
```
condition_variable_any();
```  
  
### <a name="remarks"></a>Comentários  
 Se não tiver memória suficiente disponível, o construtor gerará um objeto [system_error](../standard-library/system-error-class.md) que tem um código de erro `not_enough_memory`. Se o objeto não puder ser criado porque algum outro recurso não está disponível, o construtor gerará um objeto `system_error` que tem um código de erro `resource_unavailable_try_again`.  
  
##  <a name="notify_all"></a>  condition_variable_any::notify_all  
 Desbloqueia todos os threads que estão aguardando o objeto `condition_variable_any`.  
  
```
void notify_all() noexcept;
```  
  
##  <a name="notify_one"></a>  condition_variable_any::notify_one  
 Desbloqueia um dos threads que estão aguardando o objeto `condition_variable_any`.  
  
```
void notify_one() noexcept;
```  
  
##  <a name="wait"></a>  condition_variable_any::wait  
 Bloqueia um thread.  
  
```
template <class Lock>  
void wait(Lock& Lck);

template <class Lock, class Predicate>
void wait(Lock& Lck, Predicate Pred);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Lck`  
 Um objeto `mutex` de qualquer tipo.  
  
 `Pred`  
 Qualquer expressão que retorna `true` ou `false`.  
  
### <a name="remarks"></a>Comentários  
 O primeiro método bloqueia até que o objeto `condition_variable_any` seja sinalizado por uma chamada para [notify_one](../standard-library/condition-variable-class.md#notify_one) ou [notify_all](../standard-library/condition-variable-class.md#notify_all). Ela também pode ser ativada falsamente.  
  
 O segundo método, na verdade, executa o código a seguir.  
  
```
while (!Pred())
    wait(Lck);
```    
  
##  <a name="wait_for"></a>  condition_variable_any::wait_for  
 Bloqueia um thread e define um intervalo de tempo após o qual o thread será desbloqueado.  
  
```
template <class Lock, class Rep, class Period>
bool wait_for(Lock& Lck, const chrono::duration<Rep, Period>& Rel_time);

template <class Lock, class Rep, class Period, class Predicate>
bool wait_for(Lock& Lck, const chrono::duration<Rep, Period>& Rel_time, Predicate Pred);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Lck`  
 Um objeto `mutex` de qualquer tipo.  
  
 `Rel_time`  
 Um objeto `chrono::duration` que especifica a quantidade de tempo antes que o thread seja ativado.  
  
 `Pred`  
 Qualquer expressão que retorna `true` ou `false`.  
  
### <a name="return-value"></a>Valor de retorno  
 O primeiro método retornará `cv_status::timeout` se a espera terminar quando `Rel_time` tiver decorrido. Do contrário, o método retorna `cv_status::no_timeout`.  
  
 O segundo método retorna o valor de `Pred`.  
  
### <a name="remarks"></a>Comentários  
 O primeiro método bloqueia até que o objeto `condition_variable_any` seja sinalizado por uma chamada para [notify_one](../standard-library/condition-variable-class.md#notify_one) ou [notify_all](../standard-library/condition-variable-class.md#notify_all) ou até que o intervalo de tempo `Rel_time` tenha decorrido. Ela também pode ser ativada falsamente.  
  
 O segundo método, na verdade, executa o código a seguir.  
  
```cpp  
while(!Pred())
    if(wait_for(Lck, Rel_time) == cv_status::timeout)
    return Pred();

return true;
```  
  
##  <a name="wait_until"></a>  condition_variable_any::wait_until  
 Bloqueia um thread e define um ponto máximo no tempo no qual o thread será desbloqueado.  
  
```
template <class Lock, class Clock, class Duration>
void wait_until(Lock& Lck, const chrono::time_point<Clock, Duration>& Abs_time);

template <class Lock, class Clock, class Duration, class Predicate>
void wait_until(
    Lock& Lck,
    const chrono::time_point<Clock, Duration>& Abs_time,
    Predicate Pred);

template <class Lock>
void wait_until(Lock Lck, const xtime* Abs_time);

template <class Lock, class Predicate>
void wait_until(
    Lock Lck,
    const xtime* Abs_time,
    Predicate Pred);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Lck`  
 Um objeto mutex.  
  
 `Abs_time`  
 Um objeto [chrono::time_point](../standard-library/time-point-class.md).  
  
 `Pred`  
 Qualquer expressão que retorna `true` ou `false`.  
  
### <a name="return-value"></a>Valor de retorno  
 Os métodos que retornam um tipo `cv_status` retornarão `cv_status::timeout` se a espera terminar quando `Abs_time` for decorrido. Caso contrário, os métodos retornarão `cv_status::no_timeout`.  
  
 Os métodos que retornam um `bool` retornarão o valor de `Pred`.  
  
### <a name="remarks"></a>Comentários  
 O primeiro método bloqueia até que o objeto `condition_variable` seja sinalizado por uma chamada para [notify_one](../standard-library/condition-variable-class.md#notify_one) ou [notify_all](../standard-library/condition-variable-class.md#notify_all) ou até `Abs_time`. Ela também pode ser ativada falsamente.  
  
 O segundo método, na verdade, executa o código a seguir.  
  
```
while(!Pred())
    if(wait_until(Lck, Abs_time) == cv_status::timeout)
    return Pred();

return true;
```  
  
 O terceiro e o quarto métodos usam um ponteiro para um objeto do tipo `xtime` para substituir o objeto `chrono::time_point`. O objeto `xtime` especifica a quantidade máxima de tempo para esperar um sinal.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [<condition_variable>](../standard-library/condition-variable.md)




