---
title: Classe recursive_mutex | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- mutex/std::recursive_mutex
dev_langs:
- C++
ms.assetid: eb5ffd1b-7e78-4559-8391-bb220ead42fc
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
ms.openlocfilehash: c82c8302be5d3e01de90adda2049a022100b8443
ms.lasthandoff: 02/25/2017

---
# <a name="recursivemutex-class"></a>Classe recursive_mutex
Representa um *tipo mutex*. Em contraste com [mutex](../standard-library/mutex-class-stl.md), o comportamento de chamadas para métodos de bloqueio para objetos que já estão bloqueados é bem definido.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class recursive_mutex;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor recursive_mutex](#recursive_mutex__recursive_mutex_constructor)|Constrói um objeto `recursive_mutex`.|  
|[Destruidor ~recursive_mutex](#recursive_mutex___dtorrecursive_mutex_destructor)|Libera todos os recursos usados pelo objeto `recursive_mutex`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[lock](#recursive_mutex__lock_method)|Bloqueia o thread de chamada até que ele tenha obtido a propriedade do mutex.|  
|[try_lock](#recursive_mutex__try_lock_method)|Tenta obter a propriedade do mutex sem bloquear.|  
|[unlock](#recursive_mutex__unlock_method)|Libera a propriedade do mutex.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** mutex  
  
 **Namespace:** std  
  
##  <a name="a-namerecursivemutexlockmethoda--lock"></a><a name="recursive_mutex__lock_method"></a>  lock  
 Bloqueia o thread de chamada até que ele tenha obtido a propriedade do `mutex`.  
  
```cpp  
void lock();
```  
  
### <a name="remarks"></a>Comentários  
 Se o thread de chamada já possuir o `mutex`, o método retornará imediatamente e o bloqueio anterior permanece em vigor.  
  
##  <a name="a-namerecursivemutexrecursivemutexconstructora--recursivemutex"></a><a name="recursive_mutex__recursive_mutex_constructor"></a>  recursive_mutex  
 Constrói um objeto `recursive_mutex` que não está bloqueado.  
  
```cpp  
recursive_mutex();
```  
  
##  <a name="a-namerecursivemutexdtorrecursivemutexdestructora--recursivemutex"></a><a name="recursive_mutex___dtorrecursive_mutex_destructor"></a>  ~recursive_mutex  
 Libera todos os recursos que são usados pelo objeto.  
  
```cpp  
~recursive_mutex();
```  
  
### <a name="remarks"></a>Comentários  
 Se o objeto estiver bloqueado quando o destruidor for executado, o comportamento será indefinido.  
  
##  <a name="a-namerecursivemutextrylockmethoda--trylock"></a><a name="recursive_mutex__try_lock_method"></a>  try_lock  
 Tenta obter a propriedade do `mutex` sem o bloqueio.  
  
```cpp  
bool try_lock() noexcept;
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o método obtiver a propriedade do `mutex` com êxito ou se o thread de chamada já possui o `mutex`; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Se o thread de chamada já possui o `mutex`, a função retorna `true` imediatamente e o bloqueio anterior permanece em vigor.  
  
##  <a name="a-namerecursivemutexunlockmethoda--unlock"></a><a name="recursive_mutex__unlock_method"></a>  unlock  
 Libera a propriedade do mutex.  
  
```cpp  
void unlock();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método libera a propriedade do `mutex` somente depois que ele é chamado tantas vezes quanto [lock](#recursive_mutex__lock_method) e [try_lock](#recursive_mutex__try_lock_method) foram chamados com êxito no objeto `recursive_mutex`.  
  
 Se o thread de chamada não for o proprietário do `mutex`, o comportamento será indefinido.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<mutex>](../standard-library/mutex.md)




