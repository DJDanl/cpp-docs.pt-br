---
title: Classe timed_mutex | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- mutex/std::timed_mutex
- mutex/std::timed_mutex::timed_mutex
- mutex/std::timed_mutex::lock
- mutex/std::timed_mutex::try_lock
- mutex/std::timed_mutex::try_lock_for
- mutex/std::timed_mutex::try_lock_until
- mutex/std::timed_mutex::unlock
dev_langs: C++
ms.assetid: cd198081-6f38-447a-9dba-e06dfbfafe59
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
helpviewer_keywords:
- std::timed_mutex [C++]
- std::timed_mutex [C++], timed_mutex
- std::timed_mutex [C++], lock
- std::timed_mutex [C++], try_lock
- std::timed_mutex [C++], try_lock_for
- std::timed_mutex [C++], try_lock_until
- std::timed_mutex [C++], unlock
ms.workload: cplusplus
ms.openlocfilehash: b8b27489ce275cde4d0493a496980afd844f2378
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="timedmutex-class"></a>Classe timed_mutex
Representa um *tipo mutex programado*. Objetos desse tipo são usados para impor a exclusão mútua por meio do bloqueio com tempo limite em um programa.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class timed_mutex;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[timed_mutex](#timed_mutex)|Constrói um objeto `timed_mutex` que não está bloqueado.|  
|[Destruidor timed_mutex::~timed_mutex](#dtortimed_mutex_destructor)|Libera todos os recursos usados pelo objeto `timed_mutex`.|  
  
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
  
##  <a name="lock"></a>timed_mutex:: Lock
 Bloqueia o thread de chamada até que ele tenha obtido a propriedade do `mutex`.  
  
```cpp  
void lock();
```  
  
### <a name="remarks"></a>Comentários  
 Se o thread de chamada já for o proprietário do `mutex`, o comportamento será indefinido.  
  
##  <a name="timed_mutex"></a>  Construtor timed_mutex::timed_mutex  
 Constrói um objeto `timed_mutex` que não está bloqueado.  
  
```cpp  
timed_mutex();
```  
  
##  <a name="dtortimed_mutex_destructor"></a>  Destruidor timed_mutex::~timed_mutex  
 Libera todos os recursos usados pelo objeto `mutex`.  
  
```cpp  
~timed_mutex();
```  
  
### <a name="remarks"></a>Comentários  
 Se o objeto estiver bloqueado quando o destruidor for executado, o comportamento será indefinido.  
  
##  <a name="try_lock"></a>timed_mutex:: try_lock
 Tenta obter a propriedade do `mutex` sem o bloqueio.  
  
```cpp  
bool try_lock();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o método obtiver a propriedade do `mutex` com êxito; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Se o thread de chamada já for o proprietário do `mutex`, o comportamento será indefinido.  
  
##  <a name="try_lock_for"></a>timed_mutex:: try_lock_for
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
  
##  <a name="try_lock_until"></a>timed_mutex:: try_lock_until
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
  
##  <a name="unlock"></a>timed_mutex:: Unlock
 Libera a propriedade do `mutex`.  
  
```cpp  
void unlock();
```  
  
### <a name="remarks"></a>Comentários  
 Se o thread de chamada não for o proprietário do `mutex`, o comportamento será indefinido.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<mutex>](../standard-library/mutex.md)



