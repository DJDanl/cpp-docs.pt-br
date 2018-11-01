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
ms.openlocfilehash: d1405062ef553dbfea3b60b5f39e0546707343b6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50519490"
---
# <a name="thread-class"></a>Classe thread

Define um objeto que é usado para observar e gerenciar um thread de execução em um aplicativo.

## <a name="syntax"></a>Sintaxe

```cpp
class thread;
```

## <a name="remarks"></a>Comentários

Você pode usar um **thread** objeto para observar e gerenciar um thread de execução dentro de um aplicativo. Um objeto de thread criado usando o construtor padrão não é associado a nenhum thread de execução. Um objeto de thread construído usando um objeto que pode ser chamado cria um novo thread de execução e chama o objeto que pode ser chamado nesse thread. Os objetos de thread podem ser movidos, mas não copiados. Portanto, um thread de execução pode ser associado apenas a um objeto de thread.

Cada thread de execução tem um identificador exclusivo do tipo `thread::id`. A função `this_thread::get_id` retorna o identificador do thread de chamada. A função membro `thread::get_id` retorna o identificador do thread gerenciado por um objeto de thread. Para um objeto de thread construído por padrão, o método `thread::get_id` retorna um objeto que tem um valor que é igual para todos os objetos de thread construídos por padrão e diferente do valor retornado por `this_thread::get_id` para qualquer thread de execução que poderá ser unido no momento da chamada.

## <a name="members"></a>Membros

### <a name="public-classes"></a>Classes públicas

|Nome|Descrição|
|----------|-----------------|
|[Classe thread::id](#id_class)|Identifica exclusivamente o thread associado.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[thread](#thread)|Constrói uma **thread** objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[detach](#detach)|Desanexa o thread associado a partir de **thread** objeto.|
|[get_id](#get_id)|Retorna o identificador exclusivo do thread associado.|
|[hardware_concurrency](#hardware_concurrency)|Estático. Retorna uma estimativa do número de contextos de thread de hardware.|
|[join](#join)|Bloqueia até que o thread associado seja concluído.|
|[joinable](#joinable)|Especifica se o thread associado permite junções.|
|[native_handle](#native_handle)|Retorna o tipo específico à implementação que representa o identificador de thread.|
|[swap](#swap)|Alterna o estado do objeto com especificado **thread** objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[thread::operator=](#op_eq)|Associa um thread atual **thread** objeto.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<thread >

**Namespace:** std

## <a name="detach"></a>  thread::detach

Desanexa o thread associado. O sistema operacional fica responsável por liberar recursos de thread após o encerramento.

```cpp
void detach();
```

### <a name="remarks"></a>Comentários

Após uma chamada a `detach`, chamadas posteriores a [get_id](#get_id) retornam [id](#id_class).

Se o thread associado ao objeto de chamada não estiver disponível, a função gerará um [system_error](../standard-library/system-error-class.md) que tem um código de erro `invalid_argument`.

Se o thread associado ao objeto de chamada for inválido, a função gerará um `system_error` que tem um código de erro `no_such_process`.

## <a name="get_id"></a>  thread::get_id

Retorna um identificador exclusivo para o thread associado.

```cpp
id get_id() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

Um objeto [thread::id](#id_class) que identifica exclusivamente o thread associado ou `thread::id()` se nenhum thread estiver associado ao objeto.

## <a name="hardware_concurrency"></a>  thread::hardware_concurrency

Método estático que retorna uma estimativa do número de contextos de thread de hardware.

```cpp
static unsigned int hardware_concurrency() noexcept;
```

### <a name="return-value"></a>Valor de retorno

Uma estimativa do número de contextos de thread de hardware. Se o valor não puder ser calculado ou não estiver bem definido, esse método retornará 0.

## <a name="id_class"></a>  Classe thread::id

Fornece um identificador exclusivo para cada thread de execução no processo.

```cpp
class thread::id {
    id() noexcept;
};
```

### <a name="remarks"></a>Comentários

O construtor padrão cria um objeto que não é comparado como igual ao objeto `thread::id` em qualquer thread existente.

Todos os objetos `thread::id` construídos por padrão são comparados como iguais.

## <a name="join"></a>  thread::join

Bloqueia até que o thread de execução associado ao objeto de chamada seja concluído.

```cpp
void join();
```

### <a name="remarks"></a>Comentários

Se a chamada tiver êxito, as chamadas posteriores a [get_id](#get_id) do objeto de chamada retornarão um [thread::id](#id_class) padrão que não é comparado como igual ao `thread::id` de qualquer thread existente; se a chamada não tiver êxito, o valor retornado por `get_id` ficará inalterado.

## <a name="joinable"></a>  thread:: joinable

Especifica se o thread associado *permite junções*.

```cpp
bool joinable() const noexcept;
```

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o thread associado *permite junções*; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Um objeto de thread *permitirá junções* se `get_id() != id()`.

## <a name="native_handle"></a>  thread:: native_handle

Retorna o tipo específico à implementação que representa o identificador de thread. O identificador de thread pode ser usado de maneiras específicas à implementação.

```cpp
native_handle_type native_handle();
```

### <a name="return-value"></a>Valor de retorno

`native_handle_type` é definido como `HANDLE` Win32, que é convertido como `void *`.

## <a name="op_eq"></a>  thread::operator=

Associa o thread de um objeto especificado ao objeto atual.

```cpp
thread& operator=(thread&& Other) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
Um **thread** objeto.

### <a name="return-value"></a>Valor de retorno

`*this`

### <a name="remarks"></a>Comentários

As chamadas de método serão desanexadas se o objeto de chamada permitir junções.

Depois que a associação é feita, `Other` é definido com um estado construído por padrão.

## <a name="swap"></a>  thread::swap

Alterna o estado do objeto com do especificado **thread** objeto.

```cpp
void swap(thread& Other) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
Um **thread** objeto.

## <a name="thread"></a>  Construtor thread::thread

Constrói uma **thread** objeto.

```cpp
thread() noexcept;
template <class Fn, class... Args>
explicit thread(Fn&& F, Args&&... A);

thread(thread&& Other) noexcept;
```

### <a name="parameters"></a>Parâmetros

*F*<br/>
Uma função definida pelo aplicativo a ser executada pelo thread.

*A*<br/>
Uma lista de argumentos a serem passados para *F*.

*Outros*<br/>
Um existente **thread** objeto.

### <a name="remarks"></a>Comentários

O primeiro construtor constrói um objeto que não está associado a nenhum thread de execução. O valor retornado por uma chamada a `get_id` do objeto construído é `thread::id()`.

O segundo construtor constrói um objeto que está associado a um novo thread de execução e executa a pseudofunção `INVOKE` definida em [\<functional>](../standard-library/functional.md). Se não houver recursos suficientes disponíveis para iniciar um novo thread, a função gerará um objeto [system_error](../standard-library/system-error-class.md) que tem um código de erro `resource_unavailable_try_again`. Se a chamada para *F* termina com uma exceção não percebida, [encerrar](../standard-library/exception-functions.md#terminate) é chamado.

O terceiro construtor constrói um objeto que está associado ao thread associado a `Other`. `Other` é então definido com um estado construído por padrão.

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[\<thread>](../standard-library/thread.md)<br/>
