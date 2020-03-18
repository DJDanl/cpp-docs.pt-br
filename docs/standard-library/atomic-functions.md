---
title: Funções &lt;atomic&gt;
ms.date: 07/11/2018
f1_keywords:
- atomic/std::atomic_compare_exchange_strong
- atomic/std::atomic_compare_exchange_strong_explicit
- atomic/std::atomic_compare_exchange_weak
- atomic/std::atomic_compare_exchange_weak_explicit
- atomic/std::atomic_exchange
- atomic/std::atomic_exchange_explicit
- atomic/std::atomic_fetch_add
- atomic/std::atomic_fetch_add_explicit
- atomic/std::atomic_fetch_and
- atomic/std::atomic_fetch_and_explicit
- atomic/std::atomic_fetch_or
- atomic/std::atomic_fetch_or_explicit
- atomic/std::atomic_fetch_sub
- atomic/std::atomic_fetch_sub_explicit
- atomic/std::atomic_fetch_xor
- atomic/std::atomic_fetch_xor_explicit
- atomic/std::atomic_flag_clear
- atomic/std::atomic_flag_clear_explicit
- atomic/std::atomic_flag_test_and_set
- atomic/std::atomic_flag_test_and_set_explicit
- atomic/std::atomic_init
- atomic/std::atomic_is_lock_free
- atomic/std::atomic_load
- atomic/std::atomic_load_explicit
- atomic/std::atomic_signal_fence
- atomic/std::atomic_store
- atomic/std::atomic_store_explicit
- atomic/std::atomic_thread_fence
- atomic/std::kill_dependency
ms.assetid: 5c53b4f8-6ff5-47d7-beb2-2d6ee3c6ea89
helpviewer_keywords:
- std::atomic_compare_exchange_strong [C++]
- std::atomic_compare_exchange_strong_explicit [C++]
- std::atomic_compare_exchange_weak [C++]
- std::atomic_compare_exchange_weak_explicit [C++]
- std::atomic_exchange [C++]
- std::atomic_exchange_explicit [C++]
- std::atomic_fetch_add [C++]
- std::atomic_fetch_add_explicit [C++]
- std::atomic_fetch_and [C++]
- std::atomic_fetch_and_explicit [C++]
- std::atomic_fetch_or [C++]
- std::atomic_fetch_or_explicit [C++]
- std::atomic_fetch_sub [C++]
- std::atomic_fetch_sub_explicit [C++]
- std::atomic_fetch_xor [C++]
- std::atomic_fetch_xor_explicit [C++]
- std::atomic_flag_clear [C++]
- std::atomic_flag_clear_explicit [C++]
- std::atomic_flag_test_and_set [C++]
- std::atomic_flag_test_and_set_explicit [C++]
- std::atomic_init [C++]
- std::atomic_is_lock_free [C++]
- std::atomic_load [C++]
- std::atomic_load_explicit [C++]
- std::atomic_signal_fence [C++]
- std::atomic_store [C++]
- std::atomic_store_explicit [C++]
- std::atomic_thread_fence [C++]
- std::kill_dependency [C++]
ms.openlocfilehash: 5314db43bed913e801846341309513c239216887
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79421992"
---
# <a name="ltatomicgt-functions"></a>Funções &lt;atomic&gt;

||||
|-|-|-|
|[atomic_compare_exchange_strong](#atomic_compare_exchange_strong)|[atomic_compare_exchange_strong_explicit](#atomic_compare_exchange_strong_explicit)|[atomic_compare_exchange_weak](#atomic_compare_exchange_weak)|
|[atomic_compare_exchange_weak_explicit](#atomic_compare_exchange_weak_explicit)|[atomic_exchange](#atomic_exchange)|[atomic_exchange_explicit](#atomic_exchange_explicit)|
|[atomic_fetch_add](#atomic_fetch_add)|[atomic_fetch_add_explicit](#atomic_fetch_add_explicit)|[atomic_fetch_and](#atomic_fetch_and)|
|[atomic_fetch_and_explicit](#atomic_fetch_and_explicit)|[atomic_fetch_or](#atomic_fetch_or)|[atomic_fetch_or_explicit](#atomic_fetch_or_explicit)|
|[atomic_fetch_sub](#atomic_fetch_sub)|[atomic_fetch_sub_explicit](#atomic_fetch_sub_explicit)|[atomic_fetch_xor](#atomic_fetch_xor)|
|[atomic_fetch_xor_explicit](#atomic_fetch_xor_explicit)|[atomic_flag_clear](#atomic_flag_clear)|[atomic_flag_clear_explicit](#atomic_flag_clear_explicit)|
|[atomic_flag_test_and_set](#atomic_flag_test_and_set)|[atomic_flag_test_and_set_explicit](#atomic_flag_test_and_set_explicit)|[atomic_init](#atomic_init)|
|[atomic_is_lock_free](#atomic_is_lock_free)|[atomic_load](#atomic_load)|[atomic_load_explicit](#atomic_load_explicit)|
|[atomic_signal_fence](#atomic_signal_fence)|[atomic_store](#atomic_store)|[atomic_store_explicit](#atomic_store_explicit)|
|[atomic_thread_fence](#atomic_thread_fence)|[kill_dependency](#kill_dependency)|

## <a name="atomic_compare_exchange_strong"></a>  atomic_compare_exchange_strong

Executa uma operação de comparação e troca atômica.

```cpp
template <class Ty>
inline bool atomic_compare_exchange_strong(
    volatile atomic<Ty>* Atom,
    Ty* Exp,
    Value) noexcept;

template <class Ty>
inline bool atomic_compare_exchange_strong(
    atomic<Ty>* Atom,
    Ty* Exp,
    Ty Value) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *Atom*
Um ponteiro para um objeto *atômico* que armazena um valor do tipo `Ty`.

\ de *exp*
Um ponteiro para um valor do tipo `Ty`.

*Value*\
Um valor do tipo `Ty`.

### <a name="return-value"></a>Valor retornado

**true** se os valores forem iguais, caso contrário, **false**.

### <a name="remarks"></a>Comentários

Esse método executa uma operação de comparação e troca atômica usando argumentos `memory_order_seq_cst`[memory_order](../standard-library/atomic-enums.md#memory_order_enum) implícitos. Para obter mais informações, consulte [atomic_compare_exchange_strong_explicit](../standard-library/atomic-functions.md#atomic_compare_exchange_strong_explicit).

## <a name="atomic_compare_exchange_strong_explicit"></a>  atomic_compare_exchange_strong_explicit

Executa uma operação de *comparação e troca atômica*.

```cpp
template <class T>
inline bool atomic_compare_exchange_strong_explicit(
    volatile atomic<Ty>* Atom,
    Ty* Exp,
    Ty Value,
    memory_order Order1,
    memory_order Order2) noexcept;

template <class Ty>
inline bool atomic_compare_exchange_strong_explicit(
    atomic<Ty>* Atom,
    Ty* Exp,
    Ty Value,
    memory_order Order1,
    memory_order Order2) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *Atom*
Um ponteiro para um objeto `atomic` que armazena um valor do tipo `Ty`.

\ de *exp*
Um ponteiro para um valor do tipo `Ty`.

*Value*\
Um valor do tipo `Ty`.

\ *Order1*
Primeiro argumento [memory_order](../standard-library/atomic-enums.md#memory_order_enum).

\ *Order2*
Segundo argumento `memory_order`. O valor de *Order2* não pode ser `memory_order_release` ou `memory_order_acq_rel`, ele não pode ser mais forte que o valor de *Order1*.

### <a name="return-value"></a>Valor retornado

**true** se os valores forem iguais, caso contrário, **false**.

### <a name="remarks"></a>Comentários

Uma *operação atômica de comparação e do Exchange* compara o valor armazenado no objeto que é apontado pelo *Atom* em relação ao valor que é apontado por *exp*. Se os valores forem iguais, o valor que é armazenado no objeto que é apontado pelo *Atom* é substituído pelo *valor* usando uma operação `read-modify-write` e aplicando as restrições de ordem de memória que são especificadas por *Order1*. Se os valores não forem iguais, a operação substituirá o valor apontado por *exp* com o valor que é armazenado no objeto que é apontado pelo *Atom* e aplica as restrições de ordem de memória que são especificadas por *Order2*.

## <a name="atomic_compare_exchange_weak"></a>  atomic_compare_exchange_weak

Executa uma operação de *comparação e troca atômica fraca*.

```cpp
template <class Ty>
inline bool atomic_compare_exchange_strong(
    volatile atomic<Ty>* Atom,
    Ty* Exp,
    Ty Value) noexcept;

template <class Ty>
inline bool atomic_compare_exchange_strong(
    atomic<Ty>* Atom,
    Ty* Exp,
    Ty Value) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *Atom*
Um ponteiro para um objeto `atomic` que armazena um valor do tipo `Ty`.

\ de *exp*
Um ponteiro para um valor do tipo `Ty`.

*Value*\
Um valor do tipo `Ty`.

### <a name="return-value"></a>Valor retornado

**true** se os valores forem iguais, caso contrário, **false**.

### <a name="remarks"></a>Comentários

Esse método executa uma *operação de comparar e trocar atômica fraca* que tem argumentos `memory_order_seq_cst`[memory_order](../standard-library/atomic-enums.md#memory_order_enum) implícitos. Para obter mais informações, consulte [atomic_compare_exchange_weak_explicit](../standard-library/atomic-functions.md#atomic_compare_exchange_weak_explicit).

## <a name="atomic_compare_exchange_weak_explicit"></a>  atomic_compare_exchange_weak_explicit

Executa uma operação de *comparação e troca atômica fraca*.

```cpp
template <class Ty>
inline bool atomic_compare_exchange_weak_explicit(
    volatile atomic<Ty>* Atom,
    Ty* Exp,
    Ty Value,
    memory_order Order1,
    memory_order Order2) noexcept;

template <class Ty>
inline bool atomic_compare_exchange_weak_explicit(
    atomic<Ty>* Atom,
    Ty* Exp,
    Ty Value,
    memory_order Order1,
    memory_order Order2) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *Atom*
Um ponteiro para um objeto `atomic` que armazena um valor do tipo `Ty`.

\ de *exp*
Um ponteiro para um valor do tipo `Ty`.

*Value*\
Um valor do tipo `Ty`.

\ *Order1*
Primeiro argumento [memory_order](../standard-library/atomic-enums.md#memory_order_enum).

\ *Order2*
Segundo argumento `memory_order`. O valor de *Order2* não pode ser `memory_order_release` ou `memory_order_acq_rel`, nem pode ser mais forte que o valor de *Order1*.

### <a name="return-value"></a>Valor retornado

**true** se os valores forem iguais, caso contrário, **false**.

### <a name="remarks"></a>Comentários

Os tipos forte e fraco de uma *operação atômica de comparação e de troca* garantem que eles não armazenem o novo valor se os valores esperado e atual não forem iguais. O tipo forte garante que ele armazenará o novo valor se os valores esperados e atuais forem iguais. Às vezes, o tipo fraco pode retornar **false** e não armazenar o novo valor, mesmo se os valores atuais e esperados forem iguais. Em outras palavras, a função retornará **false**, mas um exame posterior do valor esperado pode revelar que ele não foi alterado e, portanto, deve ter comparado como igual.

## <a name="atomic_exchange"></a>  atomic_exchange

Usa o *valor* para substituir o valor armazenado de *Atom*.

```cpp
template <class T>
inline Ty atomic_exchange(volatile atomic<Ty>* _Atom, Ty Value) noexcept;

template <class Ty>
inline T atomic_exchange(atomic<Ty>* Atom, Ty Value) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *Atom*
Um ponteiro para um objeto `atomic` que armazena um valor do tipo `Ty`.

*Value*\
Um valor do tipo `Ty`.

### <a name="return-value"></a>Valor retornado

O valor armazenado de *Atom* antes da troca.

### <a name="remarks"></a>Comentários

A função `atomic_exchange` executa uma operação `read-modify-write` para trocar o valor que é armazenado em *Atom* com o *valor*, usando o [memory_order](../standard-library/atomic-enums.md#memory_order_enum)de `memory_order_seq_cst`.

## <a name="atomic_exchange_explicit"></a>  atomic_exchange_explicit

Substitui o valor armazenado de *Atom* por *valor*.

```cpp
template <class Ty>
inline Ty atomic_exchange_explicit(
    volatile atomic<Ty>* Atom,
    Ty Value,
    memory_order Order) noexcept;

template <class Ty>
inline Ty atomic_exchange_explicit(
    atomic<Ty>* Atom,
    Ty Value,
    memory_order Order) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *Atom*
Um ponteiro para um objeto `atomic` que armazena um valor do tipo `Ty`.

*Value*\
Um valor do tipo `Ty`.

*Ordem*\
Uma [memory_order](../standard-library/atomic-enums.md#memory_order_enum).

### <a name="return-value"></a>Valor retornado

O valor armazenado de *Atom* antes da troca.

### <a name="remarks"></a>Comentários

A função `atomic_exchange_explicit` executa uma operação `read-modify-write` para trocar o valor que é armazenado em *Atom* com o *valor*, dentro das restrições de memória que são especificadas por *ordem*.

## <a name="atomic_fetch_add"></a>  atomic_fetch_add

Adiciona um valor a um valor existente que é armazenado em um objeto `atomic`.

```cpp
template <class T>
T* atomic_fetch_add(volatile atomic<T*>* Atom, ptrdiff_t Value) noexcept;
template <class T>
T* atomic_fetch_add(atomic<T*>* Atom, ptrdiff_t Value) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *Atom*
Um ponteiro para um objeto `atomic` que armazena um ponteiro para o tipo `T`.

*Value*\
Um valor do tipo `ptrdiff_t`.

### <a name="return-value"></a>Valor retornado

O valor do ponteiro contido pelo objeto atômico imediatamente antes de a operação ter sido executada.

### <a name="remarks"></a>Comentários

A função `atomic_fetch_add` executa uma operação `read-modify-write` para adicionar o *valor* atomicamente ao valor armazenado no *Atom*, usando a restrição `memory_order_seq_cst`[memory_order](../standard-library/atomic-enums.md#memory_order_enum) .

Quando o tipo atômico é `atomic_address`, *Value* tem o tipo `ptrdiff_t` e a operação trata o ponteiro armazenado como um `char *`.

Essa operação também está sobrecarregada para tipos integrais:

```cpp
integral atomic_fetch_add(volatile atomic-integral* Atom, integral Value) noexcept;

integral atomic_fetch_add(atomic-integral* Atom, integral Value) noexcept;
```

## <a name="atomic_fetch_add_explicit"></a>  atomic_fetch_add_explicit

Adiciona um valor a um valor existente que é armazenado em um objeto `atomic`.

```cpp
template <class T>
T* atomic_fetch_add_explicit(
    volatile atomic<T*>* Atom,
    ptrdiff_t Value,
    memory_order Order) noexcept;

template <class T>
T* atomic_fetch_add_explicit(
    atomic<T*>* Atom,
    ptrdiff_t Value,
    memory_order Order) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *Atom*
Um ponteiro para um objeto `atomic` que armazena um ponteiro para o tipo `T`.

*Value*\
Um valor do tipo `ptrdiff_t`.

### <a name="return-value"></a>Valor retornado

O valor do ponteiro contido pelo objeto atômico imediatamente antes de a operação ter sido executada.

### <a name="remarks"></a>Comentários

A função `atomic_fetch_add_explicit` executa uma operação `read-modify-write` para adicionar o *valor* atomicamente ao valor armazenado no *Atom*, dentro das restrições [memory_order](../standard-library/atomic-enums.md#memory_order_enum) que são especificadas pelo `Order`.

Quando o tipo atômico é `atomic_address`, `Value` tem tipo `ptrdiff_t` e a operação trata o ponteiro armazenado como um `char *`.

Essa operação também está sobrecarregada para tipos integrais:

```cpp
integral atomic_fetch_add_explicit(
    volatile atomic-integral* Atom,
    integral Value,
    memory_order Order) noexcept;

integral atomic_fetch_add_explicit(
    atomic-integral* Atom,
    integral Value,
    memory_order Order) noexcept;
```

## <a name="atomic_fetch_and"></a>  atomic_fetch_and

Executa um `and` bit a bit em um valor e um valor existente que é armazenado em um objeto `atomic`.

```cpp
template <class T>
inline T atomic_fetch_and(volatile atomic<T>* Atom, T Value) noexcept;
template <class T>
inline T atomic_fetch_and(volatile atomic<T>* Atom, T Value) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *Atom*
Um ponteiro para um objeto `atomic` que armazena um valor do tipo `T`.

*Value*\
Um valor do tipo `T`.

### <a name="return-value"></a>Valor retornado

O valor contido pelo objeto atômico imediatamente antes de a operação ter sido executada.

### <a name="remarks"></a>Comentários

A função `atomic_fetch_and` executa uma operação de `read-modify-write` para substituir o valor armazenado do *Atom* por um bit de `and` de *valor* e o valor atual armazenado em *Atom*, usando a restrição de [memory_order](../standard-library/atomic-enums.md#memory_order_enum) `memory_order_seq_cst`.

## <a name="atomic_fetch_and_explicit"></a>  atomic_fetch_and_explicit

Executa um `and` bit a bit de um valor e um valor existente que é armazenado em um objeto `atomic`.

```cpp
template <class T>
inline T atomic_fetch_and_explicit(
    volatile atomic<T>* Atom,
    T Value,
    memory_order Order) noexcept;

template <class T>
inline T atomic_fetch_and_explicit(
    volatile atomic<T>* Atom,
    T Value,
    memory_order Order) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *Atom*
Um ponteiro para um objeto `atomic` que armazena um valor do tipo `T`.

*Value*\
Um valor do tipo `T`.

*Ordem*\
Uma [memory_order](../standard-library/atomic-enums.md#memory_order_enum).

### <a name="return-value"></a>Valor retornado

O valor contido pelo objeto atômico imediatamente antes de a operação ter sido executada.

### <a name="remarks"></a>Comentários

A função `atomic_fetch_and_explicit` executa uma operação de `read-modify-write` para substituir o valor armazenado do *Atom* por um bit de `and` de *valor* e o valor atual que é armazenado em *Atom*, dentro das restrições de memória que são especificadas por *ordem*.

## <a name="atomic_fetch_or"></a>  atomic_fetch_or

Executa um `or` bit a bit em um valor e um valor existente que é armazenado em um objeto `atomic`.

```cpp
template <class T>
inline T atomic_fetch_or (volatile atomic<T>* Atom, T Value) noexcept;
template <class T>
inline T atomic_fetch_or (volatile atomic<T>* Atom, T Value) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *Atom*
Um ponteiro para um objeto `atomic` que armazena um valor do tipo `T`.

*Value*\
Um valor do tipo `T`.

### <a name="return-value"></a>Valor retornado

O valor contido pelo objeto atômico imediatamente antes de a operação ter sido executada.

### <a name="remarks"></a>Comentários

A função `atomic_fetch_or` executa uma operação de `read-modify-write` para substituir o valor armazenado do *Atom* por um bit de `or` de *valor* e o valor atual que é armazenado no *atom*, usando o [memory_order](../standard-library/atomic-enums.md#memory_order_enum)`memory_order_seq_cst`.

## <a name="atomic_fetch_or_explicit"></a>  atomic_fetch_or_explicit

Executa um `or` bit a bit em um valor e um valor existente que é armazenado em um objeto `atomic`.

```cpp
template <class T>
inline T atomic_fetch_or_explicit(
    volatile atomic<T>* Atom,
    T Value,
    memory_order Order) noexcept;

template <class T>
inline T atomic_fetch_or_explicit(
    volatile atomic<T>* Atom,
    T Value,
    memory_order Order) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *Atom*
Um ponteiro para um objeto `atomic` que armazena um valor do tipo `T`.

*Value*\
Um valor do tipo `T`.

*Ordem*\
Uma [memory_order](../standard-library/atomic-enums.md#memory_order_enum).

### <a name="return-value"></a>Valor retornado

O valor contido pelo objeto atômico imediatamente antes de a operação ter sido executada.

### <a name="remarks"></a>Comentários

A função `atomic_fetch_or_explicit` executa uma operação de `read-modify-write` para substituir o valor armazenado do *Atom* por um bit de `or` de *valor* e o valor atual que é armazenado em *Atom*, dentro das restrições de [memory_order](../standard-library/atomic-enums.md#memory_order_enum) especificadas por *ordem*.

## <a name="atomic_fetch_sub"></a>  atomic_fetch_sub

Subtrai um valor de um valor existente que é armazenado em um objeto `atomic`.

```cpp
template <class T>
T* atomic_fetch_sub(
    volatile atomic<T*>* Atom,
    ptrdiff_t Value) noexcept;

template <class T>
T* atomic_fetch_sub(
    atomic<T*>* Atom,
    ptrdiff_t Value) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *Atom*
Um ponteiro para um objeto `atomic` que armazena um ponteiro para o tipo `T`.

*Value*\
Um valor do tipo `ptrdiff_t`.

### <a name="return-value"></a>Valor retornado

O valor do ponteiro contido pelo objeto atômico imediatamente antes de a operação ter sido executada.

### <a name="remarks"></a>Comentários

A função `atomic_fetch_sub` executa uma operação `read-modify-write` para *subtrair* atomicamente o valor do valor armazenado no *Atom*, usando a restrição `memory_order_seq_cst`[memory_order](../standard-library/atomic-enums.md#memory_order_enum) .

Quando o tipo atômico é `atomic_address`, *Value* tem o tipo `ptrdiff_t` e a operação trata o ponteiro armazenado como um `char *`.

Essa operação também está sobrecarregada para tipos integrais:

```cpp
integral atomic_fetch_sub(volatile atomic-integral* Atom, integral Value) noexcept;
integral atomic_fetch_sub(atomic-integral* Atom, integral Value) noexcept;
```

## <a name="atomic_fetch_sub_explicit"></a>  atomic_fetch_sub_explicit

Subtrai um valor de um valor existente que é armazenado em um objeto `atomic`.

```cpp
template <class T>
T* atomic_fetch_sub_explicit(
    volatile atomic<T*>* Atom,
    ptrdiff_t Value,
    memory_order Order) noexcept;

template <class T>
T* atomic_fetch_sub_explicit(
    atomic<T*>* Atom,
    ptrdiff_t Value, memory_order Order) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *Atom*
Um ponteiro para um objeto `atomic` que armazena um ponteiro para o tipo `T`.

*Value*\
Um valor do tipo `ptrdiff_t`.

### <a name="return-value"></a>Valor retornado

O valor do ponteiro contido pelo objeto atômico imediatamente antes de a operação ter sido executada.

### <a name="remarks"></a>Comentários

A função `atomic_fetch_sub_explicit` executa uma operação de `read-modify-write` para *subtrair* atomicamente o valor do valor armazenado no *Atom*, dentro das restrições de [memory_order](../standard-library/atomic-enums.md#memory_order_enum) que são especificadas pelo `Order`.

Quando o tipo atômico é `atomic_address`, *Value* tem o tipo `ptrdiff_t` e a operação trata o ponteiro armazenado como um `char *`.

Essa operação também está sobrecarregada para tipos integrais:

```cpp
integral atomic_fetch_sub_explicit(
    volatile atomic-integral* Atom,
    integral Value,
    memory_order Order) noexcept;

integral atomic_fetch_sub_explicit(
    atomic-integral* Atom,
    integral Value,
    memory_order Order) noexcept;
```

## <a name="atomic_fetch_xor"></a>  atomic_fetch_xor

Executa um `exclusive or` bit a bit em um valor e um valor existente que é armazenado em um objeto `atomic`.

```cpp
template <class T>
inline T atomic_fetch_xor(volatile atomic<T>* Atom, T Value) noexcept;

template <class T>
inline T atomic_fetch_xor(volatile atomic<T>* Atom, T Value) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *Atom*
Um ponteiro para um objeto `atomic` que armazena um valor do tipo `T`.

*Value*\
Um valor do tipo `T`.

### <a name="return-value"></a>Valor retornado

O valor contido pelo objeto atômico imediatamente antes de a operação ter sido executada.

### <a name="remarks"></a>Comentários

A função `atomic_fetch_xor` executa uma operação de `read-modify-write` para substituir o valor armazenado do *Atom* por um bit de `exclusive or` de *valor* e o valor atual que é armazenado no *atom*, usando o [memory_order](../standard-library/atomic-enums.md#memory_order_enum)`memory_order_seq_cst`.

## <a name="atomic_fetch_xor_explicit"></a>  atomic_fetch_xor_explicit

Executa um `exclusive or` bit a bit em um valor e um valor existente que é armazenado em um objeto `atomic`.

```cpp
template <class T>
inline T atomic_fetch_xor_explicit(
    volatile atomic<T>* Atom,
    T Value,
    memory_order Order) noexcept;

template <class T>
inline T atomic_fetch_xor_explicit(
    volatile atomic<T>* Atom,
    T Value,
    memory_order Order) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *Atom*
Um ponteiro para um objeto `atomic` que armazena um valor do tipo `T`.

*Value*\
Um valor do tipo `T`.

*Ordem*\
Uma [memory_order](../standard-library/atomic-enums.md#memory_order_enum).

### <a name="return-value"></a>Valor retornado

O valor contido pelo objeto atômico imediatamente antes de a operação ter sido executada.

### <a name="remarks"></a>Comentários

A função `atomic_fetch_xor_explicit` executa uma operação de `read-modify-write` para substituir o valor armazenado do *Atom* por um bit de `exclusive or` de *valor* e o valor atual que é armazenado em *Atom*, dentro das restrições de [memory_order](../standard-library/atomic-enums.md#memory_order_enum) que são especificadas por *ordem*.

## <a name="atomic_flag_clear"></a>  atomic_flag_clear

Define o sinalizador **bool** em um objeto [atomic_flag](../standard-library/atomic-flag-structure.md) como **false**, dentro do [memory_order](../standard-library/atomic-enums.md#memory_order_enum)`memory_order_seq_cst`.

```cpp
inline void atomic_flag_clear(volatile atomic_flag* Flag) noexcept;
inline void atomic_flag_clear(atomic_flag* Flag) noexcept;
```

### <a name="parameters"></a>parâmetros

*Sinalizador*\
Um ponteiro para um objeto `atomic_flag`.

## <a name="atomic_flag_clear_explicit"></a>  atomic_flag_clear_explicit

Define o sinalizador **bool** em um objeto [atomic_flag](../standard-library/atomic-flag-structure.md) como **false**, dentro das restrições de [memory_order](../standard-library/atomic-enums.md#memory_order_enum) especificadas.

```cpp
inline void atomic_flag_clear_explicit(volatile atomic_flag* Flag, memory_order Order) noexcept;
inline void atomic_flag_clear_explicit(atomic_flag* Flag, memory_order Order) noexcept;
```

### <a name="parameters"></a>parâmetros

*Sinalizador*\
Um ponteiro para um objeto `atomic_flag`.

*Ordem*\
Uma [memory_order](../standard-library/atomic-enums.md#memory_order_enum).

## <a name="atomic_flag_test_and_set"></a>  atomic_flag_test_and_set

Define o sinalizador **bool** em um objeto [atomic_flag](../standard-library/atomic-flag-structure.md) como **true**, dentro das restrições do [memory_order](../standard-library/atomic-enums.md#memory_order_enum)de `memory_order_seq_cst`.

```cpp
inline bool atomic_flag_test_and_set(volatile atomic_flag* Flag,) noexcept;
inline bool atomic_flag_test_and_set(atomic_flag* Flag,) noexcept;
```

### <a name="parameters"></a>parâmetros

*Sinalizador*\
Um ponteiro para um objeto `atomic_flag`.

### <a name="return-value"></a>Valor retornado

O valor inicial do *sinalizador*.

## <a name="atomic_flag_test_and_set_explicit"></a>  atomic_flag_test_and_set_explicit

Define o sinalizador **bool** em um objeto [atomic_flag](../standard-library/atomic-flag-structure.md) como **true**, dentro das restrições de [memory_order](../standard-library/atomic-enums.md#memory_order_enum) especificadas.

```cpp
inline bool atomic_flag_test_and_set_explicit(volatile atomic_flag* Flag, memory_order Order) noexcept;
inline bool atomic_flag_test_and_set_explicit(atomic_flag* Flag, memory_order Order) noexcept;
```

### <a name="parameters"></a>parâmetros

*Sinalizador*\
Um ponteiro para um objeto `atomic_flag`.

*Ordem*\
Uma [memory_order](../standard-library/atomic-enums.md#memory_order_enum).

### <a name="return-value"></a>Valor retornado

O valor inicial do *sinalizador*.

## <a name="atomic_init"></a>  atomic_init

Define o valor armazenado em um objeto `atomic`.

```cpp
template <class Ty>
inline void atomic_init(volatile atomic<Ty>* Atom, Ty Value) noexcept;
template <class Ty>
inline void atomic_init(atomic<Ty>* Atom, Ty Value) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *Atom*
Um ponteiro para um objeto `atomic` que armazena um valor do tipo `Ty`.

*Value*\
Um valor do tipo `Ty`.

### <a name="remarks"></a>Comentários

`atomic_init` não é uma operação atômica. Não é thread-safe.

## <a name="atomic_is_lock_free"></a>  atomic_is_lock_free

Especifica se operações atômicas em um objeto `atomic` são *livres de bloqueio*.

```cpp
template <class T>
inline bool atomic_is_lock_free(const volatile atomic<T>* Atom) noexcept;
template <class T>
inline bool atomic_is_lock_free(const atomic<T>* Atom) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *Atom*
Um ponteiro para um objeto `atomic` que armazena um valor do tipo `T`.

### <a name="return-value"></a>Valor retornado

**true** se as operações atômicas no *Atom* forem sem bloqueio; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Um tipo atômico será livre de bloqueio se nenhuma operação atômica no tipo usar bloqueios. Se essa função retornar true, o tipo será seguro para usar em manipuladores de sinal.

## <a name="atomic_load"></a>  atomic_load

Recupera o valor armazenado em um objeto `atomic`.

```cpp
template <class Ty>
inline Ty atomic_load(const volatile atomic<Ty>* Atom) noexcept;
template <class Ty>
inline Ty atomic_load(const atomic<Ty>* Atom) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *Atom*
Um ponteiro para um objeto `atomic` que contém um valor do tipo `Ty`.

### <a name="return-value"></a>Valor retornado

O valor recuperado que é armazenado no *Atom*.

### <a name="remarks"></a>Comentários

`atomic_load` usa implicitamente a `memory_order_seq_cst`[memory_order](../standard-library/atomic-enums.md#memory_order_enum).

## <a name="atomic_load_explicit"></a>  atomic_load_explicit

Recupera o valor armazenado em um objeto `atomic` dentro de uma [memory_order](../standard-library/atomic-enums.md#memory_order_enum).

```cpp
template <class Ty>
inline Ty atomic_load_explicit(const volatile atomic<Ty>* Atom, memory_order Order) noexcept;
template <class Ty>
inline Ty atomic_load_explicit(const atomic<Ty>* Atom, memory_order Order) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *Atom*
Um ponteiro para um objeto `atomic` que contém um valor do tipo `Ty`.

*Ordem*\
Uma [memory_order](../standard-library/atomic-enums.md#memory_order_enum). Não use `memory_order_release` nem `memory_order_acq_rel`.

### <a name="return-value"></a>Valor retornado

O valor recuperado que é armazenado no *Atom*.

## <a name="atomic_signal_fence"></a>  atomic_signal_fence

Atua como um *limite* (uma primitiva de sincronização de memória que impõe ordenação entre operações de carregar/armazenar) entre outros limites em um thread de chamada que tem manipuladores de sinal executados no mesmo thread.

```cpp
inline void atomic_signal_fence(memory_order Order) noexcept;
```

### <a name="parameters"></a>parâmetros

*Ordem*\
Uma restrição de ordenação de memória que determina o tipo de limite.

### <a name="remarks"></a>Comentários

O argumento *Order* determina o tipo de isolamento.

|||
|-|-|
|`memory_order_relaxed`|O limite não tem efeito.|
|`memory_order_consume`|O limite é um limite de aquisição.|
|`memory_order_acquire`|O limite é um limite de aquisição.|
|`memory_order_release`|O limite é um limite de versão.|
|`memory_order_acq_rel`|O limite é tanto um limite de aquisição quanto um limite de versão.|
|`memory_order_seq_cst`|O limite é tanto um limite de aquisição quanto um limite de versão e é sequencialmente consistente.|

## <a name="atomic_store"></a>  atomic_store

Armazena atomicamente um valor em um objeto atômico.

```cpp
template <class Ty>
inline Ty atomic_store_explicit(const volatile atomic<Ty>* Atom, Ty Value) noexcept;
template <class Ty>
inline Ty atomic_store_explicit(const atomic<Ty>* Atom, T Value) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *Atom*
Um ponteiro para um objeto atômico que contém um valor do tipo `Ty`.

*Value*\
Um valor do tipo `Ty`.

### <a name="remarks"></a>Comentários

`atomic_store` armazena o *valor* no objeto que é apontado pelo *Atom*, dentro da restrição `memory_order_seq_cst`[memory_order](../standard-library/atomic-enums.md#memory_order_enum) .

## <a name="atomic_store_explicit"></a>  atomic_store_explicit

Armazena atomicamente um valor em um objeto atômico.

```cpp
template <class Ty>
inline Ty atomic_store_explicit(
    const volatile atomic<Ty>* Atom,
    Ty Value,
    memory_order Order) noexcept;

template <class Ty>
inline Ty atomic_store_explicit(
    const atomic<Ty>* Atom,
    T Value,
    memory_order Order) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *Atom*
Um ponteiro para um objeto `atomic` que contém um valor do tipo `Ty`.

*Value*\
Um valor do tipo `Ty`.

*Ordem*\
Uma [memory_order](../standard-library/atomic-enums.md#memory_order_enum). Não use `memory_order_consume`, `memory_order_acquire` nem `memory_order_acq_rel`.

### <a name="remarks"></a>Comentários

`atomic_store` armazena o *valor* no objeto que é apontado pelo *Atom*, dentro do `memory_order` especificado pela *ordem*.

## <a name="atomic_thread_fence"></a>  atomic_thread_fence

Atua como um *limite* (uma primitiva de sincronização de memória que impõe a ordenação entre operações de carregar/armazenar) sem uma operação atômica associada.

```cpp
inline void atomic_thread_fence(memory_order Order) noexcept;
```

### <a name="parameters"></a>parâmetros

*Ordem*\
Uma restrição de ordenação de memória que determina o tipo de limite.

### <a name="remarks"></a>Comentários

O argumento *Order* determina o tipo de isolamento.

|||
|-|-|
|`memory_order_relaxed`|O limite não tem efeito.|
|`memory_order_consume`|O limite é um limite de aquisição.|
|`memory_order_acquire`|O limite é um limite de aquisição.|
|`memory_order_release`|O limite é um limite de versão.|
|`memory_order_acq_rel`|O limite é tanto um limite de aquisição quanto um limite de versão.|
|`memory_order_seq_cst`|O limite é tanto um limite de aquisição quanto um limite de versão e é sequencialmente consistente.|

## <a name="kill_dependency"></a>  kill_dependency

Remove uma dependência.

```cpp
template <class Ty>
Ty kill_dependency(Ty Arg) noexcept;
```

### <a name="parameters"></a>parâmetros

*Arg*\
Um valor do tipo `Ty`.

### <a name="return-value"></a>Valor retornado

O valor de retorno é *ARG*. A avaliação de *ARG* não carrega uma dependência para a chamada de função. Dividindo uma cadeia de dependências possível, a função pode permitir que o compilador gere código mais eficiente.

## <a name="see-also"></a>Confira também

[\<atomic>](../standard-library/atomic.md)
