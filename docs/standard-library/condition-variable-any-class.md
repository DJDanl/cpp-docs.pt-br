---
title: Classe condition_variable_any
ms.date: 11/04/2016
f1_keywords:
- condition_variable/std::condition_variable_any
- condition_variable/std::condition_variable_any::condition_variable_any
- condition_variable/std::condition_variable_any::notify_all
- condition_variable/std::condition_variable_any::notify_one
- condition_variable/std::condition_variable_any::wait
- condition_variable/std::condition_variable_any::wait_for
- condition_variable/std::condition_variable_any::wait_until
ms.assetid: d8afe5db-1561-4ec2-8e85-21ea03ee4321
helpviewer_keywords:
- std::condition_variable_any
- std::condition_variable_any::condition_variable_any
- std::condition_variable_any::notify_all
- std::condition_variable_any::notify_one
- std::condition_variable_any::wait
- std::condition_variable_any::wait_for
- std::condition_variable_any::wait_until
ms.openlocfilehash: 9187bddef456f131982d39fd64dacea5953b959b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222557"
---
# <a name="condition_variable_any-class"></a>Classe condition_variable_any

Use a classe `condition_variable_any` para aguardar um evento que tem qualquer tipo `mutex`.

## <a name="syntax"></a>Sintaxe

```cpp
class condition_variable_any;
```

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|||
|-|-|
|[condition_variable_any](#condition_variable_any)|Constrói um objeto `condition_variable_any`.|

### <a name="functions"></a>Funções

|||
|-|-|
|[notify_all](#notify_all)|Desbloqueia todos os threads que estão aguardando o objeto `condition_variable_any`.|
|[notify_one](#notify_one)|Desbloqueia um dos threads que estão aguardando o objeto `condition_variable_any`.|
|[esperado](#wait)|Bloqueia um thread.|
|[wait_for](#wait_for)|Bloqueia um thread e define um intervalo de tempo após o qual o thread será desbloqueado.|
|[wait_until](#wait_until)|Bloqueia um thread e define um ponto máximo no tempo no qual o thread será desbloqueado.|

## <a name="condition_variable_any"></a><a name="condition_variable_any"></a>condition_variable_any

Constrói um objeto `condition_variable_any`.

```cpp
condition_variable_any();
```

### <a name="remarks"></a>Comentários

Se não tiver memória suficiente disponível, o construtor gerará um objeto [system_error](../standard-library/system-error-class.md) que tem um código de erro `not_enough_memory`. Se o objeto não puder ser criado porque algum outro recurso não está disponível, o construtor gerará um objeto `system_error` que tem um código de erro `resource_unavailable_try_again`.

## <a name="notify_all"></a><a name="notify_all"></a>notify_all

Desbloqueia todos os threads que estão aguardando o objeto `condition_variable_any`.

```cpp
void notify_all() noexcept;
```

## <a name="notify_one"></a><a name="notify_one"></a>notify_one

Desbloqueia um dos threads que estão aguardando o objeto `condition_variable_any`.

```cpp
void notify_one() noexcept;
```

## <a name="wait"></a><a name="wait"></a>esperado

Bloqueia um thread.

```cpp
template <class Lock>
void wait(Lock& Lck);

template <class Lock, class Predicate>
void wait(Lock& Lck, Predicate Pred);
```

### <a name="parameters"></a>parâmetros

*Lck*\
Um objeto `mutex` de qualquer tipo.

*Pred*\
Qualquer expressão que retorne **`true`** ou **`false`** .

### <a name="remarks"></a>Comentários

O primeiro método bloqueia até que o objeto `condition_variable_any` seja sinalizado por uma chamada para [notify_one](../standard-library/condition-variable-class.md#notify_one) ou [notify_all](../standard-library/condition-variable-class.md#notify_all). Ela também pode ser ativada falsamente.

O segundo método, na verdade, executa o código a seguir.

```cpp
while (!Pred())
    wait(Lck);
```

## <a name="wait_for"></a><a name="wait_for"></a>wait_for

Bloqueia um thread e define um intervalo de tempo após o qual o thread será desbloqueado.

```cpp
template <class Lock, class Rep, class Period>
bool wait_for(Lock& Lck, const chrono::duration<Rep, Period>& Rel_time);

template <class Lock, class Rep, class Period, class Predicate>
bool wait_for(Lock& Lck, const chrono::duration<Rep, Period>& Rel_time, Predicate Pred);
```

### <a name="parameters"></a>parâmetros

*Lck*\
Um objeto `mutex` de qualquer tipo.

*Rel_time*\
Um objeto `chrono::duration` que especifica a quantidade de tempo antes que o thread seja ativado.

*Pred*\
Qualquer expressão que retorne **`true`** ou **`false`** .

### <a name="return-value"></a>Valor retornado

O primeiro método retornará `cv_status::timeout` se a espera for encerrada quando *Rel_time* tiver decorrido. Do contrário, o método retorna `cv_status::no_timeout`.

O segundo método retorna o valor de *Pred*.

### <a name="remarks"></a>Comentários

O primeiro método é bloqueado até que o `condition_variable_any` objeto seja sinalizado por uma chamada para [notify_one](../standard-library/condition-variable-class.md#notify_one) ou [notify_all](../standard-library/condition-variable-class.md#notify_all)ou até que o intervalo de tempo *Rel_time* tenha decorrido. Ela também pode ser ativada falsamente.

O segundo método, na verdade, executa o código a seguir.

```cpp
while(!Pred())
    if(wait_for(Lck, Rel_time) == cv_status::timeout)
    return Pred();

return true;
```

## <a name="wait_until"></a><a name="wait_until"></a>wait_until

Bloqueia um thread e define um ponto máximo no tempo no qual o thread será desbloqueado.

```cpp
template <class Lock, class Clock, class Duration>
void wait_until(Lock& Lck, const chrono::time_point<Clock, Duration>& Abs_time);

template <class Lock, class Clock, class Duration, class Predicate>
void wait_until(
    Lock& Lck,
    const chrono::time_point<Clock, Duration>& Abs_time,
    Predicate Pred);

template <class Lock>
void wait_until(Lock Lck, const xtime* Abs_time);

template <class Lock, class Predicate>
void wait_until(
    Lock Lck,
    const xtime* Abs_time,
    Predicate Pred);
```

### <a name="parameters"></a>parâmetros

*Lck*\
Um objeto mutex.

*Abs_time*\
Um objeto [chrono::time_point](../standard-library/time-point-class.md).

*Pred*\
Qualquer expressão que retorne **`true`** ou **`false`** .

### <a name="return-value"></a>Valor retornado

Métodos que retornam um `cv_status` tipo retornam `cv_status::timeout` se a espera termina quando *Abs_time* decorre. Caso contrário, os métodos retornarão `cv_status::no_timeout`.

Métodos que retornam um **`bool`** retornam o valor de *Pred*.

### <a name="remarks"></a>Comentários

O primeiro método é bloqueado até que o `condition_variable` objeto seja sinalizado por uma chamada para [notify_one](../standard-library/condition-variable-class.md#notify_one) ou [notify_all](../standard-library/condition-variable-class.md#notify_all)ou até *Abs_time*. Ela também pode ser ativada falsamente.

O segundo método, na verdade, executa o código a seguir.

```cpp
while(!Pred())
    if(wait_until(Lck, Abs_time) == cv_status::timeout)
    return Pred();

return true;
```

O terceiro e o quarto métodos usam um ponteiro para um objeto do tipo `xtime` para substituir o objeto `chrono::time_point`. O objeto `xtime` especifica a quantidade máxima de tempo para esperar um sinal.
