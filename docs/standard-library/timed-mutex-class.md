---
title: Classe timed_mutex | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- mutex/std::timed_mutex
dev_langs:
- C++
ms.assetid: cd198081-6f38-447a-9dba-e06dfbfafe59
caps.latest.revision: 9
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
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 72861fe588cf038743d5c44f22a420e690f63993
ms.lasthandoff: 02/25/2017

---
# <a name="timedmutex-class"></a>Classe timed_mutex
Representa um *tipo mutex programado*. Objetos desse tipo são usados para impor a exclusão mútua por meio do bloqueio com tempo limite em um programa.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class timed_mutex;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor timed_mutex::timed_mutex](#timed_mutex__timed_mutex_constructor)|Constrói um objeto `timed_mutex` que não está bloqueado.|  
|[Destruidor timed_mutex::~timed_mutex](#timed_mutex___dtortimed_mutex_destructor)|Libera todos os recursos usados pelo objeto `timed_mutex`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método timed_mutex::lock](#timed_mutex__lock_method)|Bloqueia o thread de chamada até que ele tenha obtido a propriedade do `mutex`.|  
|[Método timed_mutex::try_lock](#timed_mutex__try_lock_method)|Tenta obter a propriedade do `mutex` sem o bloqueio.|  
|[Método timed_mutex::try_lock_for](#timed_mutex__try_lock_for_method)|Tenta obter a propriedade do `mutex` por um intervalo de tempo especificado.|  
|[Método timed_mutex::try_lock_until](#timed_mutex__try_lock_until_method)|Tenta obter a propriedade do `mutex` até um tempo especificado.|  
|[Método timed_mutex::unlock](#timed_mutex__unlock_method)|Libera a propriedade do `mutex`.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** mutex  
  
 **Namespace:** std  
  
##  <a name="timed_mutex__lock_method"></a>  Método timed_mutex::lock  
 Bloqueia o thread de chamada até que ele tenha obtido a propriedade do `mutex`.  
  
```cpp  
void lock();
```  
  
### <a name="remarks"></a>Comentários  
 Se o thread de chamada já for o proprietário do `mutex`, o comportamento será indefinido.  
  
##  <a name="timed_mutex__timed_mutex_constructor"></a>  Construtor timed_mutex::timed_mutex  
 Constrói um objeto `timed_mutex` que não está bloqueado.  
  
```cpp  
timed_mutex();
```  
  
##  <a name="timed_mutex___dtortimed_mutex_destructor"></a>  Destruidor timed_mutex::~timed_mutex  
 Libera todos os recursos usados pelo objeto `mutex`.  
  
```cpp  
~timed_mutex();
```  
  
### <a name="remarks"></a>Comentários  
 Se o objeto estiver bloqueado quando o destruidor for executado, o comportamento será indefinido.  
  
##  <a name="timed_mutex__try_lock_method"></a>  Método timed_mutex::try_lock  
 Tenta obter a propriedade do `mutex` sem o bloqueio.  
  
```cpp  
bool try_lock();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o método obtiver a propriedade do `mutex` com êxito; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Se o thread de chamada já for o proprietário do `mutex`, o comportamento será indefinido.  
  
##  <a name="timed_mutex__try_lock_for_method"></a>  Método timed_mutex::try_lock_for  
 Tenta obter a propriedade do `mutex` sem o bloqueio.  
  
```cpp  
template <class Rep, class Period>
bool try_lock_for(const chrono::duration<Rep, Period>& Rel_time);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Rel_time`  
 Um objeto [chrono::duration](../standard-library/duration-class.md) que especifica o tempo máximo que o método tenta obter a propriedade do `mutex`.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o método obtiver a propriedade do `mutex` com êxito; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Se o thread de chamada já for o proprietário do `mutex`, o comportamento será indefinido.  
  
##  <a name="timed_mutex__try_lock_until_method"></a>  Método timed_mutex::try_lock_until  
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
 `true` se o método obtiver a propriedade do `mutex` com êxito; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Se o thread de chamada já for o proprietário do `mutex`, o comportamento será indefinido.  
  
##  <a name="timed_mutex__unlock_method"></a>  Método timed_mutex::unlock  
 Libera a propriedade do `mutex`.  
  
```cpp  
void unlock();
```  
  
### <a name="remarks"></a>Comentários  
 Se o thread de chamada não for o proprietário do `mutex`, o comportamento será indefinido.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<mutex>](../standard-library/mutex.md)




