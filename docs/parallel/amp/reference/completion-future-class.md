---
title: Classe completion_future
ms.date: 11/04/2016
f1_keywords:
- completion_future
- AMPRT/completion_future
- AMPRT/Concurrency::completion_future::completion_future
- AMPRT/Concurrency::completion_future::get
- AMPRT/Concurrency::completion_future::then
- AMPRT/Concurrency::completion_future::to_task
- AMPRT/Concurrency::completion_future::valid
- AMPRT/Concurrency::completion_future::wait
- AMPRT/Concurrency::completion_future::wait_for
- AMPRT/Concurrency::completion_future::wait_until
ms.assetid: 1303c62e-546d-4b02-a578-251ed3fc0b6b
ms.openlocfilehash: 1863f0908753fb05abb01cf1bd2e34dc6649e0a4
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228486"
---
# <a name="completion_future-class"></a>Classe completion_future

Representa um futuro correspondente a uma operação assíncrona C++ AMP.

## <a name="syntax"></a>Sintaxe

```cpp
class completion_future;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor de completion_future](#ctor)|Inicializa uma nova instância da classe `completion_future`.|
|[~ completion_future destruidor](#dtor)|Destrói o `completion_future` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[get](#get)|Aguarda até que a operação assíncrona associada seja concluída.|
|[Clique](#then)|Encadeia um objeto de função de retorno de chamada para o `completion_future` objeto a ser executado quando a operação assíncrona associada concluir a execução.|
|[to_task](#to_task)|Retorna um `task` objeto correspondente à operação assíncrona associada.|
|[válido](#valid)|Obtém um valor booliano que indica se o objeto está associado a uma operação assíncrona.|
|[esperado](#wait)|Bloqueia até que a operação assíncrona associada seja concluída.|
|[wait_for](#wait_for)|Bloqueia até que a operação assíncrona associada seja concluída ou a hora especificada por `_Rel_time` tenha decorrido.|
|[wait_until](#wait_until)|Bloqueia até que a operação assíncrona associada seja concluída ou até que a hora atual exceda o valor especificado por `_Abs_time` .|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operador std:: shared_future\<void>](#operator_shared_future)|Converte implicitamente o `completion_future` objeto em um `std::shared_future` objeto.|
|[operador =](#operator_eq)|Copia o conteúdo do objeto especificado `completion_future` para este.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`completion_future`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amprt. h

**Namespace:** simultaneidade

## <a name="completion_future"></a><a name="ctor"></a>completion_future

Inicializa uma nova instância da classe `completion_future`.

### <a name="syntax"></a>Sintaxe

```cpp
completion_future();

completion_future(
    const completion_future& _Other );

completion_future(
    completion_future&& _Other );
```

### <a name="parameters"></a>parâmetros

*_Other*<br/>
O `completion_future` objeto a ser copiado ou movido.

### <a name="overloads-list"></a>Lista de sobrecargas

|Nome|Descrição|
|----------|-----------------|
|`completion_future();`|Inicializa uma nova instância da `completion_future` classe|
|`completion_future(const completion_future& _Other);`|Inicializa uma nova instância da `completion_future` classe copiando um construtor.|
|`completion_future(completion_future&& _Other);`|Inicializa uma nova instância da `completion_future` classe movendo um construtor.|

## <a name="get"></a><a name="get"></a>Obter

Aguarda até que a operação assíncrona associada seja concluída. Gera a exceção armazenada se uma encontrada durante a operação assíncrona.

### <a name="syntax"></a>Sintaxe

```cpp
void get() const;
```

## <a name="operator-stdshared_futurevoid"></a><a name="operator_shared_future"></a>operador std:: shared_future\<void>

Converte implicitamente o `completion_future` objeto em um `std::shared_future` objeto.

### <a name="syntax"></a>Sintaxe

```cpp
operator std::shared_future<void>() const;
```

### <a name="return-value"></a>Valor retornado

Um objeto `std::shared_future`.

## <a name="operator"></a><a name="operator_eq"></a>operador =

Copia o conteúdo do objeto especificado `completion_future` para este.

### <a name="syntax"></a>Sintaxe

```cpp
completion_future&  operator= (const completion_future& _Other );
completion_future&  operator= (completion_future&& _Other );
```

### <a name="parameters"></a>parâmetros

*_Other*<br/>
O objeto do qual copiar.

### <a name="return-value"></a>Valor retornado

Uma referência a este `completion_future` objeto.

## <a name="overloads-list"></a>Lista de sobrecargas

|Nome|Descrição|
|----------|-----------------|
|`completion_future& operator=(const completion_future& _Other);`|Copia o conteúdo do objeto especificado `completion_future` para este, usando uma cópia profunda.|
|`completion_future& operator=(completion_future&& _Other);`|Copia o conteúdo do objeto especificado `completion_future` para este, usando uma atribuição de movimentação.|

## <a name="then"></a><a name="then"></a>Clique

Encadeia um objeto de função de retorno de chamada para o `completion_future` objeto a ser executado quando a operação assíncrona associada concluir a execução.

### <a name="syntax"></a>Sintaxe

```cpp
template <typename _Functor>
void then(const _Functor & _Func ) const;
```

### <a name="parameters"></a>parâmetros

*_Functor*<br/>
O retorno de chamada functor.

*_Func*<br/>
O objeto de função de retorno de chamada.

## <a name="to_task"></a><a name="to_task"></a>to_task

Retorna um `task` objeto correspondente à operação assíncrona associada.

### <a name="syntax"></a>Sintaxe

```cpp
concurrency::task<void> to_task() const;
```

### <a name="return-value"></a>Valor retornado

Um `task` objeto correspondente à operação assíncrona associada.

## <a name="valid"></a><a name="valid"></a>válido

Obtém um valor booliano que indica se o objeto está associado a uma operação assíncrona.

### <a name="syntax"></a>Sintaxe

```cpp
bool valid() const;
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o objeto estiver associado a uma operação assíncrona; caso contrário, **`false`** .

## <a name="wait"></a><a name="wait"></a>esperado

Bloqueia até que a operação assíncrona associada seja concluída.

### <a name="syntax"></a>Sintaxe

```cpp
void wait() const;
```

## <a name="wait_for"></a><a name="wait_for"></a>wait_for

Bloqueia até que a operação assíncrona associada seja concluída ou a hora especificada pelo `_Rel_time` tenha decorrido.

### <a name="syntax"></a>Sintaxe

```cpp
template <
    class _Rep,
    class _Period
>
std::future_status::future_status wait_for(
    const std::chrono::duration< _Rep, _Period>& _Rel_time ) const;
```

### <a name="parameters"></a>parâmetros

*_Rep*<br/>
Um tipo aritmético que representa o número de tiques.

*_Period*<br/>
Uma taxa std:: que representa o número de segundos decorridos por tique.

*_Rel_time*<br/>
O tempo máximo de espera para a operação ser concluída.

### <a name="return-value"></a>Valor retornado

Retorna:

- `std::future_status::deferred`se a operação assíncrona associada não estiver em execução.

- `std::future_status::ready`se a operação assíncrona associada for concluída.

- `std::future_status::timeout`Se o período de tempo especificado tiver decorrido.

## <a name="wait_until"></a><a name="wait_until"></a>wait_until

Bloqueia até que a operação assíncrona associada seja concluída ou até que a hora atual exceda o valor especificado por `_Abs_time` .

### <a name="syntax"></a>Sintaxe

```cpp
template <
    class _Clock,
    class _Duration
>
std::future_status::future_status wait_until(
    const std::chrono::time_point< _Clock, _Duration>& _Abs_time ) const;
```

### <a name="parameters"></a>parâmetros

*_Clock*<br/>
O relógio no qual esse ponto de tempo é medido.

*_Duration*<br/>
O intervalo de tempo desde o início da `_Clock` época, após o qual a função atingirá o tempo limite.

*_Abs_time*<br/>
O ponto no tempo após o qual a função atingirá o tempo limite.

### <a name="return-value"></a>Valor retornado

Retorna:

1. `std::future_status::deferred`se a operação assíncrona associada não estiver em execução.

1. `std::future_status::ready`se a operação assíncrona associada for concluída.

1. `std::future_status::timeout`Se o período de tempo especificado tiver decorrido.

## <a name="completion_future"></a><a name="dtor"></a>~ completion_future

Destrói o `completion_future` objeto.

### <a name="syntax"></a>Sintaxe

```cpp
~completion_future();
```

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
