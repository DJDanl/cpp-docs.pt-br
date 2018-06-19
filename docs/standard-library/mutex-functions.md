---
title: Funções e variáveis &lt;mutex&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
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
ms.openlocfilehash: 85ed95250b5563cd8a7c1ef9cfc0ee048cb3bc60
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33858206"
---
# <a name="ltmutexgt-functions-and-variables"></a>Funções e variáveis &lt;mutex&gt;

||||
|-|-|-|
|[adopt_lock](#adopt_lock)|[call_once](#call_once)|[defer_lock](#defer_lock)|
|[lock](#lock)|[try_to_lock](#try_to_lock)|

## <a name="adopt_lock"></a>  Variável adopt_lock

Representa um objeto que pode ser passado para construtores para [lock_guard](../standard-library/lock-guard-class.md) e [unique_lock](../standard-library/unique-lock-class.md) para indicar que o objeto mutex que também está sendo passado para o construtor está bloqueado.

```cpp
const adopt_lock_t adopt_lock;
```

## <a name="call_once"></a>  call_once

Fornece um mecanismo para chamar um objeto especificado que pode ser chamado apenas uma vez durante a execução.

```cpp
template <class Callable, class... Args>
void call_once(once_flag& Flag,
    Callable F&&, Args&&... A);
```

### <a name="parameters"></a>Parâmetros

`Flag` Um [once_flag](../standard-library/once-flag-structure.md) objeto que garante que o objeto pode ser chamado somente é chamado uma vez.

`F` Um objeto que pode ser chamado.

`A` Uma lista de argumentos.

### <a name="remarks"></a>Comentários

Se `Flag` não for válido, a função lançará um [system_error](../standard-library/system-error-class.md) com o código de erro `invalid_argument`. Caso contrário, a função de modelo usará seu argumento `Flag` para garantir que chame `F(A...)` com êxito exatamente uma vez, independentemente de quantas vezes o modelo de função for chamado. Se `F(A...)` sai ao lançar uma exceção, a chamada não foi bem-sucedida.

## <a name="defer_lock"></a>  Variável defer_lock

Representa um objeto que pode ser passado para o construtor para [unique_lock](../standard-library/unique-lock-class.md). Isso indica que o construtor não deve bloquear o objeto mutex que também está sendo passado para ele.

```cpp
const defer_lock_t defer_lock;
```

## <a name="lock"></a>  lock

Tenta bloquear todos os argumentos sem deadlock.

```cpp
template <class L1, class L2, class... L3>
void lock(L1&, L2&, L3&...);
```

### <a name="remarks"></a>Comentários

Os argumentos para a função de modelo devem ser *tipos mutex*, exceto as chamadas para `try_lock` que podem lançar exceções.

A função bloqueia todos os argumentos sem deadlock por chamadas para `lock`, `try_lock` e `unlock`. Se uma chamada para `lock` ou `try_lock` lançar uma exceção, a função chamará `unlock` em qualquer objeto mutex que foi bloqueado com êxito antes do relançamento da exceção.

## <a name="try_to_lock"></a>  Variável try_to_lock

Representa um objeto que pode ser passado para construtores para [unique_lock](../standard-library/unique-lock-class.md) para indicar que o construtor deve tentar desbloquear o `mutex` que também está sendo passado para ele sem bloqueio.

```cpp
const try_to_lock_t try_to_lock;
```

## <a name="see-also"></a>Consulte também

[\<mutex>](../standard-library/mutex.md)<br/>
