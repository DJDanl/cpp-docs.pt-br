---
title: Classe promise
ms.date: 10/18/2018
f1_keywords:
- future/std::promise
- future/std::promise::promise
- future/std::promise::get_future
- future/std::promise::set_exception
- future/std::promise::set_exception_at_thread_exit
- future/std::promise::set_value
- future/std::promise::set_value_at_thread_exit
- future/std::promise::swap
ms.assetid: 2931558c-d94a-4ba1-ac4f-20bf7b6e23f9
helpviewer_keywords:
- std::promise [C++]
- std::promise [C++], promise
- std::promise [C++], get_future
- std::promise [C++], set_exception
- std::promise [C++], set_exception_at_thread_exit
- std::promise [C++], set_value
- std::promise [C++], set_value_at_thread_exit
- std::promise [C++], swap
ms.openlocfilehash: a6541fefb2423853f8e59a662e1c8a37777dc14c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323034"
---
# <a name="promise-class"></a>Classe promise

Descreve um *provedor assíncrono*.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
class promise;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Prometo](#promise)|Constrói um objeto `promise`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[get_future](#get_future)|Retorna um [future](../standard-library/future-class.md) associado a essa promessa.|
|[set_exception](#set_exception)|Define atomicamente o resultado dessa promessa para indicar uma exceção.|
|[set_exception_at_thread_exit](#set_exception_at_thread_exit)|Define o resultado desta promessa atomicamente para indicar uma exceção e entrega a notificação somente depois que todos os objetos thread-local no thread atual forem destruídos (normalmente na saída do thread).|
|[Set_value](#set_value)|Define atomicamente o resultado dessa promessa para indicar um valor.|
|[set_value_at_thread_exit](#set_value_at_thread_exit)|Define o resultado desta promessa atomicamente para indicar um valor e entrega a notificação somente depois que todos os objetos thread-local no thread atual forem destruídos (normalmente na saída do thread).|
|[Trocar](#swap)|Troca o *estado assíncrono associado* desta promessa por um de um objeto de promessa especificado.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[promessa::operador=](#op_eq)|Atribuição do estado compartilhado desse objeto de promessa.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

*Prometo*

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<> futuro

**Namespace:** std

## <a name="promiseget_future"></a><a name="get_future"></a>promessa::get_future

Retorna um objeto [future](../standard-library/future-class.md) que tem o mesmo *estado assíncrono associado* que esta promessa.

```cpp
future<Ty> get_future();
```

### <a name="remarks"></a>Comentários

Se o objeto de promessa estiver vazio, esse método gera um [future_error](../standard-library/future-error-class.md) que tem um [error_code](../standard-library/error-code-class.md) de `no_state`.

Se esse método já foi chamado para um objeto de promessa que tem o mesmo estado assíncrono associado, o método gerará um `future_error` que tem um `error_code` de `future_already_retrieved`.

## <a name="promiseoperator"></a><a name="op_eq"></a>promessa::operador=

Transfere o *estado assíncrono associado* de um objeto especificado. `promise`

```cpp
promise& operator=(promise&& Other) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Outros*\
Um objeto `promise` .

### <a name="return-value"></a>Valor retornado

`*this`

### <a name="remarks"></a>Comentários

Este operador transfere o estado assíncrono associado de *Outros*. Após a transferência, *Other* está *vazio.*

## <a name="promisepromise-constructor"></a><a name="promise"></a>promessa::promise Constructor

Constrói um objeto `promise`.

```cpp
promise();
template <class Alloc>
promise(allocator_arg_t, const Alloc& Al);
promise(promise&& Other) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Al*\
Um alocador de memória. Consulte [ \<alocadores>](../standard-library/allocators-header.md) para obter mais informações.

*Outros*\
Um objeto `promise` .

### <a name="remarks"></a>Comentários

O primeiro construtor cria um objeto *empty* `promise`.

O segundo construtor constrói `promise` um objeto vazio e usa *Al* para alocação de memória.

O terceiro construtor constrói `promise` um objeto e transfere o estado assíncrono associado de *Outros*, e deixa *Outro* vazio.

## <a name="promiseset_exception"></a><a name="set_exception"></a>promessa::set_exception

Armazena atomicamente uma exceção como resultado desse objeto `promise` e define o *estado assíncrono associado* como *ready*.

```cpp
void set_exception(exception_ptr Exc);
```

### <a name="parameters"></a>Parâmetros

*Exc*\
Um [exception_ptr](../standard-library/exception-typedefs.md#exception_ptr) que é armazenado por esse método como o resultado da exceção.

### <a name="remarks"></a>Comentários

Se o objeto `promise` não tiver nenhum estado assíncrono associado, esse método gerará um [future_error](../standard-library/future-error-class.md) com código de erro `no_state`.

Se `set_exception`, [set_exception_at_thread_exit](#set_exception_at_thread_exit), [set_value](#set_value) ou [set_value_at_thread_exit](#set_value_at_thread_exit) já tiver sido chamado para um objeto `promise` que tem o mesmo estado assíncrono associado, esse método gera um `future_error` com código de erro `promise_already_satisfied`.

Como resultado desse método, os threads bloqueados no estado assíncrono associado são desbloqueados.

## <a name="promiseset_exception_at_thread_exit"></a><a name="set_exception_at_thread_exit"></a>promessa::set_exception_at_thread_exit

Define o resultado desse `promise` atomicamente para indicar uma exceção, entregando a notificação somente depois que todos os objetos thread-local no thread atual forem destruídos (normalmente na saída do thread).

```cpp
void set_exception_at_thread_exit(exception_ptr Exc);
```

### <a name="parameters"></a>Parâmetros

*Exc*\
Um [exception_ptr](../standard-library/exception-typedefs.md#exception_ptr) que é armazenado por esse método como o resultado da exceção.

### <a name="remarks"></a>Comentários

Se o objeto de promessa não tiver nenhum *estado assíncrono associado*, esse método gera um [future_error](../standard-library/future-error-class.md) com um código de erro `no_state`.

Se [set_exception](#set_exception)set_exception `set_exception_at_thread_exit`, [set_value](#set_value)ou [set_value_at_thread_exit](#set_value_at_thread_exit) já `promise` foi chamado para um objeto que tenha o `future_error` mesmo estado assíncrono associado, este método lança um que tem um código de erro de `promise_already_satisfied`.

Ao contrário de [set_exception](#set_exception), esse método não define o estado assíncrono associado como pronto até todos os objetos thread-local no thread atual tenham sido destruídos. Normalmente, threads bloqueados no estado assíncrono associado não são desbloqueados até que o thread atual seja encerrado.

## <a name="promiseset_value"></a><a name="set_value"></a>promessa::set_value

Armazena atomicamente um valor como o resultado desse objeto `promise` e define o *estado assíncrono associado* como *ready*.

```cpp
void promise::set_value(const Ty& Val);
void promise::set_value(Ty&& Val);
void promise<Ty&>::set_value(Ty& Val);
void promise<void>::set_value();
```

### <a name="parameters"></a>Parâmetros

*Val*\
O valor a ser armazenado como o resultado.

### <a name="remarks"></a>Comentários

Se o objeto `promise` não tiver nenhum estado assíncrono associado, esse método gerará um [future_error](../standard-library/future-error-class.md) com código de erro `no_state`.

Se [set_exception](#set_exception), [set_exception_at_thread_exit](#set_exception_at_thread_exit), `set_value` ou [set_value_at_thread_exit](#set_value_at_thread_exit) já tiver sido chamado para um objeto `promise` que tem o mesmo estado assíncrono associado, esse método gera um `future_error` com código de erro `promise_already_satisfied`.

Como resultado desse método, os threads bloqueados no estado assíncrono associado são desbloqueados.

O primeiro método também lança qualquer exceção que é lançada quando *Val* é copiado para o estado assíncrono associado. Nessa situação, o estado assíncrono associado não está definido como pronto.

O segundo método também lança qualquer exceção que é lançada quando *Val* é movido para o estado assíncrono associado. Nessa situação, o estado assíncrono associado não está definido como pronto.

Para a especialização `promise<Ty&>`parcial, o valor armazenado é, na verdade, uma referência a *Val*.

Para a especialização `promise<void>`, não existe nenhum valor armazenado.

## <a name="promiseset_value_at_thread_exit"></a><a name="set_value_at_thread_exit"></a>promessa::set_value_at_thread_exit

Armazena atomicamente um valor como o resultado deste objeto `promise`.

```cpp
void promise::set_value_at_thread_exit(const Ty& Val);
void promise::set_value_at_thread_exit(Ty&& Val);
void promise<Ty&>::set_value_at_thread_exit(Ty& Val);
void promise<void>::set_value_at_thread_exit();
```

### <a name="parameters"></a>Parâmetros

*Val*\
O valor a ser armazenado como o resultado.

### <a name="remarks"></a>Comentários

Se o objeto de promessa não tiver nenhum *estado assíncrono associado*, esse método gera um [future_error](../standard-library/future-error-class.md) com um código de erro `no_state`.

Se [set_exception](#set_exception), [set_exception_at_thread_exit](#set_exception_at_thread_exit), [set_value](#set_value) ou `set_value_at_thread_exit` já tiver sido chamado para um objeto `promise` que tem o mesmo estado assíncrono associado, esse método gera um `future_error` com código de erro `promise_already_satisfied`.

Ao contrário de `set_value`, o estado assíncrono associado não é definido como pronto até que todos os objetos thread-local no thread atual tenham sido destruídos. Normalmente, threads bloqueados no estado assíncrono associado não são desbloqueados até que o thread atual seja encerrado.

O primeiro método também lança qualquer exceção que é lançada quando *Val* é copiado para o estado assíncrono associado.

O segundo método também lança qualquer exceção que é lançada quando *Val* é movido para o estado assíncrono associado.

Para a especialização `promise<Ty&>`parcial, o valor armazenado é efetivamente uma referência a *Val*.

Para a especialização `promise<void>`, não existe nenhum valor armazenado.

## <a name="promiseswap"></a><a name="swap"></a>promessa::swap

Troca o *estado assíncrono associado* deste objeto de promessa por um de um objeto de promessa especificado.

```cpp
void swap(promise& Other) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Outros*\
Um objeto `promise` .

## <a name="see-also"></a>Confira também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
