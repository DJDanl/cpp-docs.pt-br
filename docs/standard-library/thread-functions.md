---
title: Funções de &lt;thread&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- thread/std::get_id
- thread/std::sleep_for
- thread/std::sleep_until
- thread/std::swap
- thread/std::yield
ms.assetid: bb1aa1ef-fe3f-4e2c-8b6e-e22dbf2f5a19
helpviewer_keywords:
- std::get_id [C++]
- std::sleep_for [C++]
- std::sleep_until [C++]
- std::swap [C++]
- std::yield [C++]
ms.openlocfilehash: 948c00f7c0b773bf366f4ea9e102c832e9878d9b
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38960444"
---
# <a name="ltthreadgt-functions"></a>Funções &lt;thread&gt;

||||
|-|-|-|
|[get_id](#get_id)|[sleep_for](#sleep_for)|[sleep_until](#sleep_until)|
|[swap](#swap)|[yield](#yield)|

## <a name="get_id"></a>  get_id

Identifica exclusivamente o thread atual de execução.

```cpp
thread::id this_thread::get_id() noexcept;
```

### <a name="return-value"></a>Valor de retorno

Um objeto do tipo [thread::id](../standard-library/thread-class.md) que identifica exclusivamente o thread de execução atual.

## <a name="sleep_for"></a>  sleep_for

Bloqueia o thread de chamada.

```cpp
template <class Rep,
class Period>
inline void sleep_for(const chrono::duration<Rep, Period>& Rel_time);
```

### <a name="parameters"></a>Parâmetros

*Rel_time*  
 O objeto [duration](../standard-library/duration-class.md) que especifica um intervalo de tempo.

### <a name="remarks"></a>Comentários

A função bloqueia o thread de chamada pelo menos o tempo especificado por *Rel_time*. Essa função não gera exceções.

## <a name="sleep_until"></a>  sleep_until

Bloqueia o thread de chamada, pelo menos, até o tempo especificado.

```cpp
template <class Clock, class Duration>
void sleep_until(const chrono::time_point<Clock, Duration>& Abs_time);

void sleep_until(const xtime *Abs_time);
```

### <a name="parameters"></a>Parâmetros

*Abs_time*  
 Representa um ponto no tempo.

### <a name="remarks"></a>Comentários

Essa função não gera exceções.

## <a name="swap"></a>  swap

Troca os estados de dois **thread** objetos.

```cpp
void swap(thread& Left, thread& Right) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Esquerda*  
 À esquerda **thread** objeto.

*Direita*  
 O direito **thread** objeto.

### <a name="remarks"></a>Comentários

A função chama `Left.swap(Right)`.

## <a name="yield"></a>  yield

Sinaliza ao sistema operacional para executar outros threads, mesmo se o thread atual continuar normalmente em execução.

```cpp
inline void yield() noexcept;
```

## <a name="see-also"></a>Consulte também

[\<thread>](../standard-library/thread.md)<br/>
