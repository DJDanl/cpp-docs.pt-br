---
title: Funções e variáveis &lt;mutex&gt;
ms.date: 11/04/2016
f1_keywords:
- mutex/std::adopt_lock
- mutex/std::call_once
- mutex/std::defer_lock
- mutex/std::lock
- mutex/std::try_to_lock
ms.assetid: 78ab3c8b-c7db-4226-ac93-e2e78ff8b964
helpviewer_keywords:
- std::adopt_lock [C++]
- std::call_once [C++]
- std::defer_lock [C++]
- std::lock [C++]
- std::try_to_lock [C++]
ms.openlocfilehash: f6bd6a86e91c2d59fec2083dcf0ec6314d7c41ab
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68240572"
---
# <a name="ltmutexgt-functions-and-variables"></a>Funções e variáveis &lt;mutex&gt;

## <a name="adopt_lock"></a> adopt_lock

Representa um objeto que pode ser passado para construtores para [lock_guard](../standard-library/lock-guard-class.md) e [unique_lock](../standard-library/unique-lock-class.md) para indicar que o objeto mutex que também está sendo passado para o construtor está bloqueado.

```cpp
const adopt_lock_t adopt_lock;
```

## <a name="call_once"></a> call_once

Fornece um mecanismo para chamar um objeto especificado que pode ser chamado apenas uma vez durante a execução.

```cpp
template <class Callable, class... Args>
void call_once(once_flag& Flag,
    Callable F&&, Args&&... A);
```

### <a name="parameters"></a>Parâmetros

*Sinalizador*\
Um objeto [once_flag](../standard-library/once-flag-structure.md) que garante que o objeto que pode ser chamado seja chamado apenas uma vez.

*F*\
Um objeto que pode ser chamado.

*UM*\
Uma lista de argumentos.

### <a name="remarks"></a>Comentários

Se *sinalizador* não é válido, a função lançará um [system_error](../standard-library/system-error-class.md) que tem um código de erro `invalid_argument`. Caso contrário, a função de modelo usará seu *sinalizador* argumento para garantir que ele chama `F(A...)` com êxito exatamente uma vez, independentemente de quantas vezes a função de modelo é chamada. Se `F(A...)` sai ao lançar uma exceção, a chamada não foi bem-sucedida.

## <a name="defer_lock"></a> defer_lock

Representa um objeto que pode ser passado para o construtor para [unique_lock](../standard-library/unique-lock-class.md). Isso indica que o construtor não deve bloquear o objeto mutex que também está sendo passado para ele.

```cpp
const defer_lock_t defer_lock;
```

## <a name="lock"></a> Bloqueio

Tenta bloquear todos os argumentos sem deadlock.

```cpp
template <class L1, class L2, class... L3>
void lock(L1&, L2&, L3&...);
```

### <a name="remarks"></a>Comentários

Os argumentos para a função de modelo devem ser *tipos mutex*, exceto as chamadas para `try_lock` que podem lançar exceções.

A função bloqueia todos os argumentos sem deadlock por chamadas para `lock`, `try_lock` e `unlock`. Se uma chamada para `lock` ou `try_lock` lançar uma exceção, a função chamará `unlock` em qualquer objeto mutex que foi bloqueado com êxito antes do relançamento da exceção.

## <a name="swap"></a> troca

```cpp
template <class Mutex>
void swap(unique_lock<Mutex>& x, unique_lock<Mutex>& y) noexcept;
```

## <a name="try_lock"></a> try_lock

```cpp
template <class L1, class L2, class... L3> int try_lock(L1&, L2&, L3&...);
```

## <a name="try_to_lock"></a> try_to_lock

Representa um objeto que pode ser passado para construtores para [unique_lock](../standard-library/unique-lock-class.md) para indicar que o construtor deve tentar desbloquear o `mutex` que também está sendo passado para ele sem bloqueio.

```cpp
const try_to_lock_t try_to_lock;
```
