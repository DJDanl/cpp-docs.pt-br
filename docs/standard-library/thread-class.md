---
title: Classe thread
ms.date: 11/04/2016
f1_keywords:
- thread/std::thread
- thread/std::thread::id Class
- thread/std::thread::thread
- thread/std::thread::detach
- thread/std::thread::get_id
- thread/std::thread::hardware_concurrency
- thread/std::thread::join
- thread/std::thread::joinable
- thread/std::thread::native_handle
- thread/std::thread::swap
ms.assetid: df249bc7-ff81-4ff9-a6d6-5e3d9a8f56a1
helpviewer_keywords:
- std::thread [C++]
- std::thread [C++], thread
- std::thread [C++], detach
- std::thread [C++], get_id
- std::thread [C++], hardware_concurrency
- std::thread [C++], join
- std::thread [C++], joinable
- std::thread [C++], native_handle
- std::thread [C++], swap
ms.openlocfilehash: 19f7ae1fc95f531f509273f0eb9998c73fe7d47b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215576"
---
# <a name="thread-class"></a>Classe thread

Define um objeto que é usado para observar e gerenciar um thread de execução em um aplicativo.

## <a name="syntax"></a>Sintaxe

```cpp
class thread;
```

## <a name="remarks"></a>Comentários

É possível usar um objeto `thread` para observar e gerenciar um thread de execução em um aplicativo. Um objeto de thread criado usando o construtor padrão não é associado a nenhum thread de execução. Um objeto de thread construído usando um objeto que pode ser chamado cria um novo thread de execução e chama o objeto que pode ser chamado nesse thread. Os objetos de thread podem ser movidos, mas não copiados. Portanto, um thread de execução pode ser associado apenas a um objeto de thread.

Cada thread de execução tem um identificador exclusivo do tipo `thread::id`. A função `this_thread::get_id` retorna o identificador do thread de chamada. A função membro `thread::get_id` retorna o identificador do thread gerenciado por um objeto de thread. Para um objeto de thread construído por padrão, o método `thread::get_id` retorna um objeto que tem um valor que é igual para todos os objetos de thread construídos por padrão e diferente do valor retornado por `this_thread::get_id` para qualquer thread de execução que poderá ser unido no momento da chamada.

## <a name="members"></a>Membros

### <a name="public-classes"></a>Classes públicas

|Nome|Descrição|
|----------|-----------------|
|[Classe thread::id](#id_class)|Identifica exclusivamente o thread associado.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[thread](#thread)|Constrói um objeto `thread`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[remover](#detach)|Desanexa o thread associado do objeto `thread`.|
|[get_id](#get_id)|Retorna o identificador exclusivo do thread associado.|
|[hardware_concurrency](#hardware_concurrency)|Estático. Retorna uma estimativa do número de contextos de thread de hardware.|
|[join](#join)|Bloqueia até que o thread associado seja concluído.|
|[junção](#joinable)|Especifica se o thread associado permite junções.|
|[native_handle](#native_handle)|Retorna o tipo específico à implementação que representa o identificador de thread.|
|[permuta](#swap)|Troca o estado do objeto por um objeto `thread` especificado.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Thread:: operador =](#op_eq)|Associa um thread ao objeto `thread` atual.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<thread>

**Namespace:** std

## <a name="threaddetach"></a><a name="detach"></a>Thread::d Etach

Desanexa o thread associado. O sistema operacional fica responsável por liberar recursos de thread após o encerramento.

```cpp
void detach();
```

### <a name="remarks"></a>Comentários

Após uma chamada a `detach`, chamadas posteriores a [get_id](#get_id) retornam [id](#id_class).

Se o thread associado ao objeto de chamada não estiver disponível, a função gerará um [system_error](../standard-library/system-error-class.md) que tem um código de erro `invalid_argument`.

Se o thread associado ao objeto de chamada for inválido, a função gerará um `system_error` que tem um código de erro `no_such_process`.

## <a name="threadget_id"></a><a name="get_id"></a>Thread:: get_id

Retorna um identificador exclusivo para o thread associado.

```cpp
id get_id() const noexcept;
```

### <a name="return-value"></a>Valor retornado

Um objeto [thread::id](#id_class) que identifica exclusivamente o thread associado ou `thread::id()` se nenhum thread estiver associado ao objeto.

## <a name="threadhardware_concurrency"></a><a name="hardware_concurrency"></a>Thread:: hardware_concurrency

Método estático que retorna uma estimativa do número de contextos de thread de hardware.

```cpp
static unsigned int hardware_concurrency() noexcept;
```

### <a name="return-value"></a>Valor retornado

Uma estimativa do número de contextos de thread de hardware. Se o valor não puder ser calculado ou não estiver bem definido, esse método retornará 0.

## <a name="threadid-class"></a><a name="id_class"></a>Classe Thread:: ID

Fornece um identificador exclusivo para cada thread de execução no processo.

```cpp
class thread::id {
    id() noexcept;
};
```

### <a name="remarks"></a>Comentários

O construtor padrão cria um objeto que não é comparado como igual ao objeto `thread::id` em qualquer thread existente.

Todos os objetos `thread::id` construídos por padrão são comparados como iguais.

## <a name="threadjoin"></a><a name="join"></a>Thread:: join

Bloqueia até que o thread de execução associado ao objeto de chamada seja concluído.

```cpp
void join();
```

### <a name="remarks"></a>Comentários

Se a chamada tiver êxito, as chamadas posteriores a [get_id](#get_id) do objeto de chamada retornarão um [thread::id](#id_class) padrão que não é comparado como igual ao `thread::id` de qualquer thread existente; se a chamada não tiver êxito, o valor retornado por `get_id` ficará inalterado.

## <a name="threadjoinable"></a><a name="joinable"></a>Thread:: joinável

Especifica se o thread associado é *Join*.

```cpp
bool joinable() const noexcept;
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o thread associado for *Join*; caso contrário, **`false`** .

### <a name="remarks"></a>Comentários

Um objeto de thread *permitirá junções* se `get_id() != id()`.

## <a name="threadnative_handle"></a><a name="native_handle"></a>Thread:: native_handle

Retorna o tipo específico à implementação que representa o identificador de thread. O identificador de thread pode ser usado de maneiras específicas à implementação.

```cpp
native_handle_type native_handle();
```

### <a name="return-value"></a>Valor retornado

`native_handle_type` é definido como `HANDLE` Win32, que é convertido como `void *`.

## <a name="threadoperator"></a><a name="op_eq"></a>Thread:: operador =

Associa o thread de um objeto especificado ao objeto atual.

```cpp
thread& operator=(thread&& Other) noexcept;
```

### <a name="parameters"></a>parâmetros

*Outros*\
Um objeto `thread`.

### <a name="return-value"></a>Valor retornado

`*this`

### <a name="remarks"></a>Comentários

As chamadas de método serão desanexadas se o objeto de chamada permitir junções.

Depois que a associação é feita, `Other` é definido com um estado construído por padrão.

## <a name="threadswap"></a><a name="swap"></a>Thread:: permuta

Troca o estado do objeto pelo estado de um objeto `thread` especificado.

```cpp
void swap(thread& Other) noexcept;
```

### <a name="parameters"></a>parâmetros

*Outros*\
Um objeto `thread`.

## <a name="threadthread-constructor"></a><a name="thread"></a>Construtor Thread:: thread

Constrói um objeto `thread`.

```cpp
thread() noexcept;
template <class Fn, class... Args>
explicit thread(Fn&& F, Args&&... A);

thread(thread&& Other) noexcept;
```

### <a name="parameters"></a>parâmetros

*Fixo*\
Uma função definida pelo aplicativo a ser executada pelo thread.

*Um*\
Uma lista de argumentos a serem passados para *F*.

*Outros*\
Um objeto `thread` existente.

### <a name="remarks"></a>Comentários

O primeiro construtor constrói um objeto que não está associado a nenhum thread de execução. O valor retornado por uma chamada a `get_id` do objeto construído é `thread::id()`.

O segundo construtor constrói um objeto que está associado a um novo thread de execução e executa a pseudo função `INVOKE` definida no [\<functional>](../standard-library/functional.md) . Se não houver recursos suficientes disponíveis para iniciar um novo thread, a função gerará um objeto [system_error](../standard-library/system-error-class.md) que tem um código de erro `resource_unavailable_try_again`. Se a chamada para *F* terminar com uma exceção não capturada, [Terminate](../standard-library/exception-functions.md#terminate) será chamado.

O terceiro construtor constrói um objeto que está associado ao thread associado a `Other`. `Other` é então definido com um estado construído por padrão.

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[\<thread>](../standard-library/thread.md)
