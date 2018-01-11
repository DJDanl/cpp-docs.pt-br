---
title: Classe recursive_timed_mutex | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- mutex/std::recursive_timed_mutex
- mutex/std::recursive_timed_mutex::recursive_timed_mutex
- mutex/std::recursive_timed_mutex::lock
- mutex/std::recursive_timed_mutex::try_lock
- mutex/std::recursive_timed_mutex::try_lock_for
- mutex/std::recursive_timed_mutex::try_lock_until
- mutex/std::recursive_timed_mutex::unlock
dev_langs: C++
ms.assetid: 59cc2d5c-ed80-45f3-a0a8-05652a8ead7e
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
helpviewer_keywords:
- std::recursive_timed_mutex [C++]
- std::recursive_timed_mutex [C++], recursive_timed_mutex
- std::recursive_timed_mutex [C++], lock
- std::recursive_timed_mutex [C++], try_lock
- std::recursive_timed_mutex [C++], try_lock_for
- std::recursive_timed_mutex [C++], try_lock_until
- std::recursive_timed_mutex [C++], unlock
ms.workload: cplusplus
ms.openlocfilehash: 9ed5930eca492d6793ab08c39b6af8b45a9124c2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="recursivetimedmutex-class"></a>Classe recursive_timed_mutex
Representa um *tipo mutex programado*. Objetos desse tipo são usados para impor a exclusão mútua usando o tempo limite de bloqueio dentro de um programa. Ao contrário de objetos do tipo [timed_mutex](../standard-library/timed-mutex-class.md), o efeito de chamar métodos de bloqueio para objetos `recursive_timed_mutex` é bem definido.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class recursive_timed_mutex;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[recursive_timed_mutex](#recursive_timed_mutex)|Constrói um objeto `recursive_timed_mutex` que não está bloqueado.|  
|[Destruidor ~recursive_timed_mutex](#dtorrecursive_timed_mutex_destructor)|Libera todos os recursos usados pelo objeto `recursive_timed_mutex`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[lock](#lock)|Bloqueia o thread de chamada até que ele tenha obtido a propriedade do `mutex`.|  
|[try_lock](#try_lock)|Tenta obter a propriedade do `mutex` sem o bloqueio.|  
|[try_lock_for](#try_lock_for)|Tenta obter a propriedade do `mutex` por um intervalo de tempo especificado.|  
|[try_lock_until](#try_lock_until)|Tenta obter a propriedade do `mutex` até um tempo especificado.|  
|[unlock](#unlock)|Libera a propriedade do `mutex`.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<mutex >  
  
 **Namespace:** std  
  
##  <a name="lock"></a>  lock  
 Bloqueia o thread de chamada até que ele tenha obtido a propriedade do `mutex`.  
  
```cpp  
void lock();
```  
  
### <a name="remarks"></a>Comentários  
 Se o thread de chamada já possuir o `mutex`, o método retornará imediatamente e o bloqueio anterior permanece em vigor.  
  
##  <a name="recursive_timed_mutex"></a>  Construtor recursive_timed_mutex  
 Constrói um objeto `recursive_timed_mutex` que não está bloqueado.  
  
```cpp  
recursive_timed_mutex();
```  
  
##  <a name="dtorrecursive_timed_mutex_destructor"></a>  Destruidor ~recursive_timed_mutex  
 Libera todos os recursos usados pelo objeto `recursive_timed_mutex`.  
  
```cpp  
~recursive_timed_mutex();
```  
  
### <a name="remarks"></a>Comentários  
 Se o objeto estiver bloqueado quando o destruidor for executado, o comportamento será indefinido.  
  
##  <a name="try_lock"></a>  try_lock  
 Tenta obter a propriedade do `mutex` sem o bloqueio.  
  
```cpp  
bool try_lock() noexcept;
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o método obtiver a propriedade do `mutex` com êxito ou se o thread de chamada já possui o `mutex`; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Se o thread de chamada já possui o `mutex`, a função retorna `true` imediatamente e o bloqueio anterior permanece em vigor.  
  
##  <a name="try_lock_for"></a>  try_lock_for  
 Tenta obter a propriedade do `mutex` sem o bloqueio.  
  
```cpp  
template <class Rep, class Period>
bool try_lock_for(const chrono::duration<Rep, Period>& Rel_time);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Rel_time`  
 Um objeto [chrono::duration](../standard-library/duration-class.md) que especifica o tempo máximo que o método tenta obter a propriedade do `mutex`.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o método obtiver a propriedade do `mutex` com êxito ou se o thread de chamada já possui o `mutex`; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Se o thread de chamada já possui o `mutex`, o método retornará `true` imediatamente e o bloqueio anterior permanece em vigor.  
  
##  <a name="try_lock_until"></a>  try_lock_until  
 Tenta obter a propriedade do `mutex` sem o bloqueio.  
  
```cpp  
template <class Clock, class Duration>
bool try_lock_for(const chrono::time_point<Clock, Duration>& Abs_time);

bool try_lock_until(const xtime* Abs_time);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Abs_time`  
 Um ponto no tempo que especifica o limite após o qual o método não tenta mais obter a propriedade do `mutex`.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o método obtiver a propriedade do `mutex` com êxito ou se o thread de chamada já possui o `mutex`; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Se o thread de chamada já possui o `mutex`, o método retornará `true` imediatamente e o bloqueio anterior permanece em vigor.  
  
##  <a name="unlock"></a>  unlock  
 Libera a propriedade do `mutex`.  
  
```cpp  
void unlock();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método libera a propriedade do `mutex` somente depois que ele é chamado tantas vezes quanto [lock](#lock), [try_lock](#try_lock), [try_lock_for](#try_lock_for) e [try_lock_until](#try_lock_until) foram chamados com êxito no objeto `recursive_timed_mutex`.  
  
 Se o thread de chamada não for o proprietário do `mutex`, o comportamento será indefinido.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<mutex>](../standard-library/mutex.md)



