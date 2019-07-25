---
title: '&lt;shared_mutex&gt;'
ms.date: 03/27/2019
f1_keywords:
- <shared_mutex>
- shared_mutex/std::swap
- shared_mutex/std::shared_lock
- shared_mutex/std::shared_lock::shared_lock
- shared_mutex/std::shared_lock::operator=
- shared_mutex/std::shared_lock::operator =
- shared_mutex/std::shared_lock::lock
- shared_mutex/std::shared_lock::try_lock
- shared_mutex/std::shared_lock::try_lock_for
- shared_mutex/std::shared_lock::try_lock_until
- shared_mutex/std::shared_lock::unlock
- shared_mutex/std::shared_lock::swap
- shared_mutex/std::shared_lock::release
- shared_mutex/std::shared_lock::owns_lock
- shared_mutex/std::shared_lock::operator bool
- shared_mutex/std::shared_lock::mutex
- shared_mutex/std::shared_mutex
- shared_mutex/std::shared_mutex::native_handle_type
- shared_mutex/std::shared_mutex::shared_mutex
- shared_mutex/std::shared_mutex::operator=
- shared_mutex/std::shared_mutex::operator =
- shared_mutex/std::shared_mutex::lock
- shared_mutex/std::shared_mutex::try_lock
- shared_mutex/std::shared_mutex::unlock
- shared_mutex/std::shared_mutex::lock_shared
- shared_mutex/std::shared_mutex::try_lock_shared
- shared_mutex/std::shared_mutex::unlock_shared
- shared_mutex/std::shared_mutex::native_handle
- shared_mutex/std::shared_timed_mutex
- shared_mutex/std::shared_timed_mutex::shared_timed_mutex
- shared_mutex/std::shared_timed_mutex::operator=
- shared_mutex/std::shared_timed_mutex::operator =
- shared_mutex/std::shared_timed_mutex::lock
- shared_mutex/std::shared_timed_mutex::try_lock
- shared_mutex/std::shared_timed_mutex::try_lock_for
- shared_mutex/std::shared_timed_mutex::try_lock_until
- shared_mutex/std::shared_timed_mutex::unlock
- shared_mutex/std::shared_timed_mutex::lock_shared
- shared_mutex/std::shared_timed_mutex::try_lock_shared
- shared_mutex/std::shared_timed_mutex::try_lock_shared_for
- shared_mutex/std::shared_timed_mutex::try_lock_shared_until
- shared_mutex/std::shared_timed_mutex::unlock_shared
ms.assetid: 0b37a97d-ee5d-4050-b29f-09db9f76beb3
ms.openlocfilehash: 7dd72550bc8658158b399e88573526269202f8f4
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68450429"
---
# <a name="ltsharedmutex"></a>&lt;shared_mutex>

O &lt;cabeçalho de > shared_mutex fornece primitivos de sincronização para proteção de dados compartilhados que podem ser acessados por vários threads. Além do controle de acesso exclusivo fornecido pelas classes mutex, as classes shared mutex também permitem propriedade compartilhada por vários segmentos para acesso não exclusivo. Classes shared mutex podem ser usadas para controlar os recursos que podem ser lidos por vários threads sem causar uma condição de corrida, mas devem ser escritos exclusivamente por um único thread.

O cabeçalho &lt;shared_mutex > define as classes `shared_mutex` e `shared_timed_mutex`, a classe `shared_lock`de modelo e a função `swap` de modelo para o suporte a mutex compartilhado.

|Classes|Descrição|
|-------------|-----------------|
|[shared_mutex Class](#class_shared_mutex)|Um tipo shared mutex que pode ser bloqueado exclusivamente por um agente ou compartilhado não exclusivamente por vários agentes.|
|[shared_timed_mutex Class](#class_shared_timed_mutex)|Um tipo shared timed mutex que pode ser bloqueado exclusivamente por um agente ou compartilhado não exclusivamente por vários agentes.|
|[shared_lock Class](#class_shared_lock)|Uma classe de modelo que encapsula um shared mutex para dar suporte a operações de tempo limite de bloqueio e compartilhamento não exclusivo por vários agentes.|

|Funções|Descrição|
|---------------|-----------------|
|[swap](#function_swap)|Troca o conteúdo dos objetos shared mutex referenciados pelos parâmetros da função.|

## <a name="syntax"></a>Sintaxe

```cpp
namespace std {
    class shared_mutex;
    class shared_timed_mutex;
    template <class Mutex>
class shared_lock;
    template <class Mutex>
void swap(shared_lock<Mutex>& x, shared_lock<Mutex>& y) noexcept;
}
```

## <a name="remarks"></a>Comentários

Uma instância da classe `shared_mutex` é um *tipo shared mutex*, um tipo que controla a propriedade compartilhada de um mutex em um escopo. Um tipo shared mutex atende a todos os requisitos de um tipo mutex bem como de membros para dar suporte à propriedade não exclusiva compartilhada.

Um tipo shared mutex dá suporte aos métodos adicionais `lock_shared`, `unlock_shared` e `try_lock_shared`:

- O método `lock_shared` bloqueia o thread de chamada até que ele tenha obtido a propriedade compartilhada do mutex.

- O método `unlock_shared` libera a propriedade compartilhada do mutex retida pelo thread de chamada.

- O método `try_lock_shared` tenta obter a propriedade compartilhada do mutex sem bloquear. Seu tipo de retorno será convertido em **bool** e será **true** se o método obtiver a propriedade, mas, caso contrário, será **false**.

A classe `shared_timed_mutex` é um *tipo shared timed mutex*, um tipo que atende aos requisitos tanto do tipo shared mutex quanto de um tipo timed mutex.

Um tipo shared timed mutex dá suporte aos métodos adicionais `try_lock_shared_for` e `try_lock_shared_until`:

- O método `try_lock_shared_for` tenta obter a propriedade compartilhada do mutex até que a duração especificada pelo parâmetro tenha passado. Se a duração não for positiva, o método será equivalente a `try_lock_shared`. O método não retorna dentro da duração especificada, a menos que a propriedade compartilhada seja obtida. Seu valor de retorno será **true** se o método obtiver a propriedade, mas, caso contrário, será **false**.

- O método `try_lock_shared_until` tenta obter a propriedade compartilhada do mutex até que o tempo absoluto especificado tenha passado. Se o tempo especificado já tiver passado, o método será equivalente a `try_lock_shared`. O método não retorna antes do tempo especificado, a menos que a propriedade compartilhada seja obtida. Seu valor de retorno será **true** se o método obtiver a propriedade, mas, caso contrário, será **false**.

A classe de modelo `shared_lock` estende o suporte para bloqueio e transferência de propriedade temporizados para um shared mutex. A propriedade do mutex podem ser obtida em ou após a construção e pode ser transferida para outro objeto `shared_lock`. Objetos do tipo `shared_lock` podem ser movidos, mas não copiados.

> [!WARNING]
> A partir do Visual Studio 2015, C++ os tipos de sincronização de biblioteca padrão são baseados em primitivos de sincronização do Windows e não usam mais ConcRT (exceto quando a plataforma de destino é o Windows XP). Os tipos definidos em &lt;shared_mutex > não devem ser usados com tipos ou funções ConcRT.

## <a name="classes"></a>Classes

###  <a name="class_shared_mutex"></a> Classe shared_mutex

A classe `shared_mutex` implementa um mutex não recursivo com semântica de propriedade compartilhada.

```cpp
class shared_mutex {
public:
   shared_mutex();
   ~shared_mutex();
   shared_mutex(const shared_mutex&) = delete;
   shared_mutex& operator=(const shared_mutex&) = delete;
   // Exclusive ownership
   void lock();
   // blocking
   bool try_lock();
   void unlock();
   // Shared ownership
   void lock_shared();
   // blocking
   bool try_lock_shared();
   void unlock_shared();
   // Getters
   typedef void** native_handle_type; // implementation defined
   native_handle_type native_handle();
   };
```

###  <a name="class_shared_timed_mutex"></a> Classe shared_timed_mutex

A classe `shared_timed_mutex` implementa um mutex não recursivo com semântica de propriedade compartilhada que atende aos requisitos de um tipo timed mutex.

```cpp
class shared_timed_mutex {
public:
   shared_timed_mutex();
   ~shared_timed_mutex();
   shared_timed_mutex(const shared_timed_mutex&) = delete;
   shared_timed_mutex& operator=(const shared_timed_mutex&) = delete;
   // Exclusive ownership
   void lock();
   // blocking
   bool try_lock();
   template <class Rep, class Period>
   bool try_lock_for(const chrono::duration<Rep, Period>& rel_time);
   template <class Clock, class Duration>
   bool try_lock_until(const chrono::time_point<Clock, Duration>& abs_time);
   void unlock();
   // Shared ownership
   void lock_shared();
   // blocking
   bool try_lock_shared();
   template <class Rep, class Period>
   bool try_lock_shared_for(const chrono::duration<Rep, Period>& rel_time);
   template <class Clock, class Duration>
   bool try_lock_shared_until(const chrono::time_point<Clock, Duration>& abs_time);
   void unlock_shared();
   };
```

###  <a name="class_shared_lock"></a> Classe shared_lock

A classe de modelo `shared_lock` controla a propriedade compartilhada de um objeto shared mutex dentro de um escopo. O parâmetro de modelo deve ser de um tipo shared mutex.

```cpp
class shared_lock {
public:
   typedef Mutex mutex_type;
   shared_lock() noexcept;
   explicit shared_lock(mutex_type& m);
   // blocking
   shared_lock(mutex_type& m, defer_lock_t) noexcept;
   shared_lock(mutex_type& m, try_to_lock_t);
   shared_lock(mutex_type& m, adopt_lock_t);
   template <class Clock, class Duration>
   shared_lock(mutex_type& m,
   const chrono::time_point<Clock, Duration>& abs_time);
   template <class Rep, class Period>
   shared_lock(mutex_type& m,
   const chrono::duration<Rep, Period>& rel_time);
   ~shared_lock();
   shared_lock(shared_lock const&) = delete;
   shared_lock& operator=(shared_lock const&) = delete;
   shared_lock(shared_lock&& u) noexcept;
   shared_lock& operator=(shared_lock&& u) noexcept;
   void lock();
   // blocking
   bool try_lock();
   template <class Rep, class Period>
   bool try_lock_for(const chrono::duration<Rep, Period>& rel_time);
   template <class Clock, class Duration>
   bool try_lock_until(const chrono::time_point<Clock, Duration>& abs_time);
   void unlock();
   // Setters
   void swap(shared_lock& u) noexcept;
   mutex_type* release() noexcept;
   // Getters
   bool owns_lock() const noexcept;
   explicit operator bool () const noexcept;
   mutex_type* mutex() const noexcept;
private:
   mutex_type* pm; // exposition only
   bool owns; // exposition only
   };
```

## <a name="functions"></a>Funções

###  <a name="function_swap"></a>permuta

Troca os objetos `shared_lock`.

```cpp
template <class Mutex>
void swap(shared_lock<Mutex>& x, shared_lock<Mutex>& y) noexcept;
```

Troca o conteúdo de dois objetos `shared_lock`. Efetivamente o mesmo que `x.swap(y)`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** &lt;shared_mutex>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[&lt;mutex>](../standard-library/mutex.md)
