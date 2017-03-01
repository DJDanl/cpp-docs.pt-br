---
title: "Classe mutex (biblioteca padrão C++)| Microsoft Docs"
ms.custom: ""
ms.date: "11/04/2016"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "mutex/std::mutex"
dev_langs: 
  - "C++"
ms.assetid: 7999d055-f74f-4303-810f-8d3c9cde2f69
caps.latest.revision: 11
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
# <a name="mutex-class-c-standard-library"></a>Classe mutex (biblioteca padrão C++)
Representa um *tipo mutex*. Objetos desse tipo podem ser usados para impor a exclusão mútua dentro de um programa.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class mutex;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor mutex::mutex](#mutex__mutex_constructor)|Constrói um objeto `mutex`.|  
|[Destruidor mutex::~mutex](#mutex___dtormutex_destructor)|Libera todos os recursos que foram usados pelo objeto `mutex`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método mutex::lock](#mutex__lock_method)|Bloqueia o thread de chamada até que ele tenha obtido a propriedade do `mutex`.|  
|[Método mutex::native_handle](#mutex__native_handle_method)|Retorna o tipo específico à implementação que representa o identificador mutex.|  
|[Método mutex::try_lock](#mutex__try_lock_method)|Tenta obter a propriedade do `mutex` sem o bloqueio.|  
|[Método mutex::unlock](#mutex__unlock_method)|Libera a propriedade do `mutex`.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** mutex  
  
 **Namespace:** std  
  
##  <a name="a-namemutexlockmethoda--mutexlock-method"></a><a name="mutex__lock_method"></a>  Método mutex::lock  
 Bloqueia o thread de chamada até que ele tenha obtido a propriedade do `mutex`.  
  
```cpp  
void lock();
```  
  
### <a name="remarks"></a>Comentários  
 Se o thread de chamada já for o proprietário do `mutex`, o comportamento será indefinido.  
  
##  <a name="a-namemutexmutexconstructora--mutexmutex-constructor"></a><a name="mutex__mutex_constructor"></a>  Construtor mutex::mutex  
 Constrói um objeto `mutex` que não está bloqueado.  
  
```cpp  
constexpr mutex() noexcept;
```  
  
##  <a name="a-namemutexdtormutexdestructora--mutexmutex-destructor"></a><a name="mutex___dtormutex_destructor"></a>  Destruidor mutex::~mutex  
 Libera todos os recursos usados pelo objeto `mutex`.  
  
```cpp  
~mutex();
```  
  
### <a name="remarks"></a>Comentários  
 Se o objeto estiver bloqueado quando o destruidor for executado, o comportamento será indefinido.  
  
##  <a name="a-namemutexnativehandlemethoda--mutexnativehandle-method"></a><a name="mutex__native_handle_method"></a>  Método mutex::native_handle  
 Retorna o tipo específico à implementação que representa o identificador mutex. O identificador mutex pode ser usado de maneiras específicas da implementação.  
  
```
native_handle_type native_handle();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `native_handle_type` é definido como um `Concurrency::critical_section *` que é convertido como `void *`.  
  
##  <a name="a-namemutextrylockmethoda--mutextrylock-method"></a><a name="mutex__try_lock_method"></a>  Método mutex::try_lock  
 Tenta obter a propriedade do `mutex` sem o bloqueio.  
  
```cpp  
bool try_lock();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o método obtiver a propriedade do `mutex` com êxito; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Se o thread de chamada já for o proprietário do `mutex`, o comportamento será indefinido.  
  
##  <a name="a-namemutexunlockmethoda--mutexunlock-method"></a><a name="mutex__unlock_method"></a>  Método mutex::unlock  
 Libera a propriedade do `mutex`.  
  
```cpp  
void unlock();
```  
  
### <a name="remarks"></a>Comentários  
 Se o thread de chamada não for o proprietário do `mutex`, o comportamento será indefinido.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<mutex>](../standard-library/mutex.md)



