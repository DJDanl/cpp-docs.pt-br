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
ms.openlocfilehash: 663122c2d8cd430e921773e75dfd7975e4a41516
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62405567"
---
# <a name="completionfuture-class"></a>Classe completion_future

Representa um futuro correspondente à operação assíncrona de C++ AMP.

### <a name="syntax"></a>Sintaxe

```
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
|[get](#get)|Aguarda até que a operação assíncrona associada é concluída.|
|[then](#then)|Encadeia um objeto de função de retorno de chamada para o `completion_future` objeto a ser executado quando a operação assíncrona associada conclui a execução.|
|[to_task](#to_task)|Retorna um `task` objeto correspondente para a operação assíncrona associada.|
|[valid](#valid)|Obtém um valor booliano que indica se o objeto está associado uma operação assíncrona.|
|[wait](#wait)|Bloqueia até que a operação assíncrona associada é concluída.|
|[wait_for](#wait_for)|Bloqueia até que a operação assíncrona associada seja concluída ou o tempo especificado pelo `_Rel_time` tiver decorrido.|
|[wait_until](#wait_until)|Bloqueia até que a operação assíncrona associada termine ou até o momento atual exceder o valor especificado pelo `_Abs_time`.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operador completion_future\<void >](#operator_shared_future)|Converte implicitamente a `completion_future` do objeto para um `std::shared_future` objeto.|
|[operator=](#operator_eq)|Copia o conteúdo especificado `completion_future` esse objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`completion_future`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amprt. h

**Namespace:** simultaneidade

## <a name="ctor"></a> completion_future

Inicializa uma nova instância da classe `completion_future`.

### <a name="syntax"></a>Sintaxe

```
completion_future();

completion_future(
    const completion_future& _Other );

completion_future(
    completion_future&& _Other );
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O `completion_future` objeto a ser copiado ou movido.

### <a name="overloads-list"></a>Lista de sobrecargas

|Nome|Descrição|
|----------|-----------------|
|`completion_future();`|Inicializa uma nova instância do `completion_future` classe|
|`completion_future(const completion_future& _Other);`|Inicializa uma nova instância do `completion_future` classe por meio da cópia de um construtor.|
|`completion_future(completion_future&& _Other);`|Inicializa uma nova instância do `completion_future` classe movendo um construtor.|

## <a name="get"></a> Obter

Aguarda até que a operação assíncrona associada é concluída. Gera a exceção armazenada se um foi encontrado durante a operação assíncrona.

### <a name="syntax"></a>Sintaxe

```
void get() const;
```

## <a name="operator_shared_future"></a> operador completion_future<void>

Converte implicitamente a `completion_future` do objeto para um `std::shared_future` objeto.

### <a name="syntax"></a>Sintaxe

```
operator std::shared_future<void>() const;
```

### <a name="return-value"></a>Valor de retorno

Um objeto `std::shared_future`.

## <a name="operator_eq"></a> operator=

Copia o conteúdo especificado `completion_future` esse objeto.

### <a name="syntax"></a>Sintaxe

```
completion_future&  operator= (const completion_future& _Other );
completion_future&  operator= (completion_future&& _Other );
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O objeto do qual copiar.

### <a name="return-value"></a>Valor de retorno

Uma referência a este `completion_future` objeto.

## <a name="overloads-list"></a>Lista de sobrecargas

|Nome|Descrição|
|----------|-----------------|
|`completion_future& operator=(const completion_future& _Other);`|Copia o conteúdo especificado `completion_future` objeto para esse outro, usando uma cópia profunda.|
|`completion_future& operator=(completion_future&& _Other);`|Copia o conteúdo especificado `completion_future` objeto para esse outro, usando uma atribuição de movimentação.|

## <a name="then"></a> Em seguida

Encadeia um objeto de função de retorno de chamada para o `completion_future` objeto a ser executado quando a operação assíncrona associada conclui a execução.

### <a name="syntax"></a>Sintaxe

```
template <typename _Functor>
void then(const _Functor & _Func ) const;
```

### <a name="parameters"></a>Parâmetros

*_Functor*<br/>
O functor de retorno de chamada.

*_Func*<br/>
O objeto de função de retorno de chamada.

## <a name="to_task"></a> to_task

Retorna um `task` objeto correspondente para a operação assíncrona associada.

### <a name="syntax"></a>Sintaxe

```
concurrency::task<void> to_task() const;
```

### <a name="return-value"></a>Valor de retorno

Um `task` objeto correspondente para a operação assíncrona associada.

## <a name="valid"></a> válido

Obtém um valor booliano que indica se o objeto está associado uma operação assíncrona.

### <a name="syntax"></a>Sintaxe

```
bool valid() const;
```

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o objeto é associado uma operação assíncrona; caso contrário, **falso**.

## <a name="wait"></a> Aguarde

Bloqueia até que a operação assíncrona associada é concluída.

### <a name="syntax"></a>Sintaxe

```
void wait() const;
```

## <a name="wait_for"></a> wait_for

Bloqueia até que a operação assíncrona associada seja concluída ou o tempo especificado pelo `_Rel_time` tiver decorrido.

### <a name="syntax"></a>Sintaxe

```
template <
    class _Rep,
    class _Period
>
std::future_status::future_status wait_for(
    const std::chrono::duration< _Rep, _Period>& _Rel_time ) const;
```

### <a name="parameters"></a>Parâmetros

*_Rep*<br/>
Um tipo aritmético que representa o número de tiques.

*_Period*<br/>
Um std:: ratio que representa o número de segundos decorridos por marcação.

*_Rel_time*<br/>
O tempo máximo de espera para a operação ser concluída.

### <a name="return-value"></a>Valor de retorno

Retorna:

- `std::future_status::deferred` Se a operação assíncrona associada não está em execução.

- `std::future_status::ready` Se a operação assíncrona associada estiver concluída.

- `std::future_status::timeout` Se especificado tiver decorrido o período de tempo.

## <a name="wait_until"></a> wait_until

Bloqueia até que a operação assíncrona associada termine ou até o momento atual exceder o valor especificado pelo `_Abs_time`.

### <a name="syntax"></a>Sintaxe

```
template <
    class _Clock,
    class _Duration
>
std::future_status::future_status wait_until(
    const std::chrono::time_point< _Clock, _Duration>& _Abs_time ) const;
```

### <a name="parameters"></a>Parâmetros

*_Clock*<br/>
O relógio em que esse ponto de tempo é medido.

*_Duration*<br/>
O intervalo de tempo desde o início do `_Clock`da época, após o qual a função atingirá o tempo limite.

*_Abs_time*<br/>
O ponto no tempo após o qual a função atingirá o tempo limite.

### <a name="return-value"></a>Valor de retorno

Retorna:

1. `std::future_status::deferred` Se a operação assíncrona associada não está em execução.

1. `std::future_status::ready` Se a operação assíncrona associada estiver concluída.

1. `std::future_status::timeout` Se o período de tempo especificado tiver decorrido.

## <a name="dtor"></a> ~completion_future

Destrói o `completion_future` objeto.

### <a name="syntax"></a>Sintaxe

```
~completion_future();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
