---
title: Funções &lt;thread&gt;
ms.date: 11/04/2016
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
ms.openlocfilehash: bb0a0a12ec2882701447804f9c88d1776a196cb7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375846"
---
# <a name="ltthreadgt-functions"></a>Funções &lt;thread&gt;

||||
|-|-|-|
|[get_id](#get_id)|[sleep_for](#sleep_for)|[sleep_until](#sleep_until)|
|[Trocar](#swap)|[yield](#yield)|

## <a name="get_id"></a><a name="get_id"></a>get_id

Identifica exclusivamente o thread atual de execução.

```cpp
thread::id this_thread::get_id() noexcept;
```

### <a name="return-value"></a>Valor retornado

Um objeto do tipo [thread::id](../standard-library/thread-class.md) que identifica exclusivamente o thread de execução atual.

## <a name="sleep_for"></a><a name="sleep_for"></a>sleep_for

Bloqueia o thread de chamada.

```cpp
template <class Rep,
class Period>
inline void sleep_for(const chrono::duration<Rep, Period>& Rel_time);
```

### <a name="parameters"></a>Parâmetros

*Rel_time*\
O objeto [duration](../standard-library/duration-class.md) que especifica um intervalo de tempo.

### <a name="remarks"></a>Comentários

A função bloqueia o segmento de chamada por pelo menos o tempo especificado por *Rel_time*. Essa função não gera exceções.

## <a name="sleep_until"></a><a name="sleep_until"></a>sleep_until

Bloqueia o thread de chamada, pelo menos, até o tempo especificado.

```cpp
template <class Clock, class Duration>
void sleep_until(const chrono::time_point<Clock, Duration>& Abs_time);

void sleep_until(const xtime *Abs_time);
```

### <a name="parameters"></a>Parâmetros

*Abs_time*\
Representa um ponto no tempo.

### <a name="remarks"></a>Comentários

Essa função não gera exceções.

## <a name="swap"></a><a name="swap"></a>Trocar

Troca os estados de dois objetos de **rosca.**

```cpp
void swap(thread& Left, thread& Right) noexcept;
```

### <a name="parameters"></a>Parâmetros

*Deixou*\
O objeto **da rosca** esquerda.

*Certo*\
O objeto **de rosca** direita.

### <a name="remarks"></a>Comentários

A função chama `Left.swap(Right)`.

## <a name="yield"></a><a name="yield"></a>Rendimento

Sinaliza ao sistema operacional para executar outros threads, mesmo se o thread atual continuar normalmente em execução.

```cpp
inline void yield() noexcept;
```

## <a name="see-also"></a>Confira também

[\<thread>](../standard-library/thread.md)
