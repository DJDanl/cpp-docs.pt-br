---
title: Operadores do namespace de simultaneidade
ms.date: 11/04/2016
f1_keywords:
- concrt/concurrency::operator!=
- concrt/concurrency:[operator&amp;&amp
ms.assetid: 8e373f23-fc8e-49f7-82e6-ba0c57b822f8
ms.openlocfilehash: 97553276a7c4ff687dd8bea4627f943d5666b2e9
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88836005"
---
# <a name="concurrency-namespace-operators"></a>Operadores do namespace de simultaneidade

:::row:::
   :::column span="":::
      [`operator||`](#operator_lor)\
      [`operator&&`](#operator_amp_amp)
   :::column-end:::
   :::column span="":::
      [`operator==`](#operator_eq_eq)\
      [`operator!=`](#operator_neq)
   :::column-end:::
   :::column span="":::
      [`operator<`](#operator_lt)\
      [`operator<=`](#operator_lt_eq)
   :::column-end:::
   :::column span="":::
      [`operator>`](#operator_gt)\
      [`operator>=`](#operator_gt_eq)
   :::column-end:::
:::row-end:::

## <a name="operator124124-operator"></a><a name="operator_lor"></a> Operador de&#124;&#124; de operador

Cria uma tarefa que será concluída com êxito quando uma das tarefas fornecidas como argumentos for concluída com êxito.

```cpp
template<typename ReturnType>
task<ReturnType> operator||(
    const task<ReturnType>& lhs,
    const task<ReturnType>& rhs);

template<typename ReturnType>
task<std::vector<ReturnType>> operator||(
    const task<std::vector<ReturnType>>& lhs,
    const task<ReturnType>& rhs);

template<typename ReturnType>
task<std::vector<ReturnType>> operator||(
    const task<ReturnType>& lhs,
    const task<std::vector<ReturnType>>& rhs);

inline task<void> operator||(
    const task<void>& lhs,
    const task<void>& rhs);
```

### <a name="parameters"></a>parâmetros

*ReturnType*<br/>
O tipo da tarefa retornada.

*lhs*<br/>
A primeira tarefa a combinar na tarefa resultante.

*rhs*<br/>
A segunda tarefa a combinar na tarefa resultante.

### <a name="return-value"></a>Valor Retornado

Uma tarefa que é concluída com êxito quando uma das tarefas de entrada é concluída com êxito. Se as tarefas de entrada forem do tipo `T`, a saída dessa função será um `task<std::vector<T>`. Se as tarefas de entrada forem do tipo **`void`** , a tarefa de saída também será um `task<void>` .

### <a name="remarks"></a>Comentários

Se as duas tarefas forem canceladas ou lançar exceções, a tarefa retornada será concluída no estado cancelado e uma das exceções, se houver alguma, será lançada quando você chamar `get()` ou `wait()` na tarefa.

## <a name="operatorampamp-operator"></a><a name="operator_amp_amp"></a>&amp; &amp; operador operador

Cria uma tarefa que será concluída com êxito quando as duas tarefas fornecidas como argumentos forem concluídas com êxito.

```cpp
template<typename ReturnType>
task<std::vector<ReturnType>>  operator&&(
    const task<ReturnType>& lhs,
    const task<ReturnType>& rhs);

template<typename ReturnType>
task<std::vector<ReturnType>>  operator&&(
    const task<std::vector<ReturnType>>& lhs,
    const task<ReturnType>& rhs);

template<typename ReturnType>
task<std::vector<ReturnType>>  operator&&(
    const task<ReturnType>& lhs,
    const task<std::vector<ReturnType>>& rhs);

template<typename ReturnType>
task<std::vector<ReturnType>>  operator&&(
    const task<std::vector<ReturnType>>& lhs,
    const task<std::vector<ReturnType>>& rhs);

inline task<void>  operator&&(
    const task<void>& lhs,
    const task<void>& rhs);
```

### <a name="parameters"></a>parâmetros

*ReturnType*<br/>
O tipo da tarefa retornada.

*lhs*<br/>
A primeira tarefa a combinar na tarefa resultante.

*rhs*<br/>
A segunda tarefa a combinar na tarefa resultante.

### <a name="return-value"></a>Valor Retornado

Uma tarefa que foi concluída com êxito quando ambas as tarefas de entrada foram concluídas com êxito. Se as tarefas de entrada forem do tipo `T`, a saída dessa função será um `task<std::vector<T>>`. Se as tarefas de entrada forem do tipo **`void`** , a tarefa de saída também será um `task<void>` .

### <a name="remarks"></a>Comentários

Se uma das tarefas for cancelada ou lançar uma exceção, a tarefa retornada será concluída antecipadamente, no estado cancelado, e a exceção, se ocorrer, será gerada se você chamar `get()` ou `wait()` nessa tarefa.

## <a name="operator-operator"></a><a name="operator_eq_eq"></a> operador = = operador

Testa se o `concurrent_vector` objeto no lado esquerdo do operador é igual ao `concurrent_vector` objeto no lado direito.

```cpp
template<typename T, class A1, class A2>
inline bool operator== (
    const concurrent_vector<T, A1>& _A,
    const concurrent_vector<T, A2>& _B);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de dados dos elementos armazenados nos vetores simultâneos.

*A1*<br/>
O tipo de alocador do primeiro `concurrent_vector` objeto.

*A2*<br/>
O tipo de alocador do segundo `concurrent_vector` objeto.

*_A*<br/>
Um objeto do tipo `concurrent_vector`.

*_B*<br/>
Um objeto do tipo `concurrent_vector`.

### <a name="return-value"></a>Valor Retornado

**`true`** Se o vetor simultâneo no lado esquerdo do operador for igual ao vetor simultâneo no lado direito do operador;. caso contrário **`false`** .

### <a name="remarks"></a>Comentários

Dois vetores simultâneos são iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

Esse método não é seguro para simultaneidade em relação a outros métodos que podem modificar qualquer vetor simultâneo `_A` ou `_B` .

## <a name="operator-operator"></a><a name="operator_neq"></a> operador! = operador

Testa se o `concurrent_vector` objeto no lado esquerdo do operador não é igual ao `concurrent_vector` objeto no lado direito.

```cpp
template<typename T, class A1, class A2>
inline bool operator!= (
    const concurrent_vector<T, A1>& _A,
    const concurrent_vector<T, A2>& _B);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de dados dos elementos armazenados nos vetores simultâneos.

*A1*<br/>
O tipo de alocador do primeiro `concurrent_vector` objeto.

*A2*<br/>
O tipo de alocador do segundo `concurrent_vector` objeto.

*_A*<br/>
Um objeto do tipo `concurrent_vector`.

*_B*<br/>
Um objeto do tipo `concurrent_vector`.

### <a name="return-value"></a>Valor Retornado

**`true`** Se os vetores simultâneos não forem iguais; **`false`** se os vetores simultâneos forem iguais.

### <a name="remarks"></a>Comentários

Dois vetores simultâneos são iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

Esse método não é seguro para simultaneidade em relação a outros métodos que podem modificar qualquer vetor simultâneo `_A` ou `_B` .

## <a name="operatorlt-operator"></a><a name="operator_lt"></a>&lt;operador operador

Testa se o `concurrent_vector` objeto no lado esquerdo do operador é menor que o `concurrent_vector` objeto no lado direito.

```cpp
template<typename T, class A1, class A2>
inline bool operator<(
    const concurrent_vector<T, A1>& _A,
    const concurrent_vector<T, A2>& _B);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de dados dos elementos armazenados nos vetores simultâneos.

*A1*<br/>
O tipo de alocador do primeiro `concurrent_vector` objeto.

*A2*<br/>
O tipo de alocador do segundo `concurrent_vector` objeto.

*_A*<br/>
Um objeto do tipo `concurrent_vector`.

*_B*<br/>
Um objeto do tipo `concurrent_vector`.

### <a name="return-value"></a>Valor Retornado

**`true`** Se o vetor simultâneo no lado esquerdo do operador for menor que o vetor simultâneo no lado direito do operador; caso contrário **`false`** .

### <a name="remarks"></a>Comentários

O comportamento desse operador é idêntico ao operador equivalente para a `vector` classe no `std` namespace.

Esse método não é seguro para simultaneidade em relação a outros métodos que podem modificar qualquer vetor simultâneo `_A` ou `_B` .

## <a name="operatorlt-operator"></a><a name="operator_lt_eq"></a> operador &lt; = operador

Testa se o `concurrent_vector` objeto no lado esquerdo do operador é menor ou igual ao `concurrent_vector` objeto no lado direito.

```cpp
template<typename T, class A1, class A2>
inline bool operator<= (
    const concurrent_vector<T, A1>& _A,
    const concurrent_vector<T, A2>& _B);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de dados dos elementos armazenados nos vetores simultâneos.

*A1*<br/>
O tipo de alocador do primeiro `concurrent_vector` objeto.

*A2*<br/>
O tipo de alocador do segundo `concurrent_vector` objeto.

*_A*<br/>
Um objeto do tipo `concurrent_vector`.

*_B*<br/>
Um objeto do tipo `concurrent_vector`.

### <a name="return-value"></a>Valor Retornado

**`true`** Se o vetor simultâneo no lado esquerdo do operador for menor que ou igual ao vetor simultâneo no lado direito do operador;. caso contrário **`false`** .

### <a name="remarks"></a>Comentários

O comportamento desse operador é idêntico ao operador equivalente para a `vector` classe no `std` namespace.

Esse método não é seguro para simultaneidade em relação a outros métodos que podem modificar qualquer vetor simultâneo `_A` ou `_B` .

## <a name="operatorgt-operator"></a><a name="operator_gt"></a>&gt;operador operador

Testa se o `concurrent_vector` objeto no lado esquerdo do operador é maior que o `concurrent_vector` objeto no lado direito.

```cpp
template<typename T, class A1, class A2>
inline bool operator>(
    const concurrent_vector<T, A1>& _A,
    const concurrent_vector<T, A2>& _B);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de dados dos elementos armazenados nos vetores simultâneos.

*A1*<br/>
O tipo de alocador do primeiro `concurrent_vector` objeto.

*A2*<br/>
O tipo de alocador do segundo `concurrent_vector` objeto.

*_A*<br/>
Um objeto do tipo `concurrent_vector`.

*_B*<br/>
Um objeto do tipo `concurrent_vector`.

### <a name="return-value"></a>Valor Retornado

**`true`** Se o vetor simultâneo no lado esquerdo do operador for maior que o vetor simultâneo no lado direito do operador; caso contrário **`false`** .

### <a name="remarks"></a>Comentários

O comportamento desse operador é idêntico ao operador equivalente para a `vector` classe no `std` namespace.

Esse método não é seguro para simultaneidade em relação a outros métodos que podem modificar qualquer vetor simultâneo `_A` ou `_B` .

## <a name="operatorgt-operator"></a><a name="operator_gt_eq"></a> operador &gt; = operador

Testa se o `concurrent_vector` objeto no lado esquerdo do operador é maior ou igual ao `concurrent_vector` objeto no lado direito.

```cpp
template<typename T, class A1, class A2>
inline bool operator>= (
    const concurrent_vector<T, A1>& _A,
    const concurrent_vector<T, A2>& _B);
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de dados dos elementos armazenados nos vetores simultâneos.

*A1*<br/>
O tipo de alocador do primeiro `concurrent_vector` objeto.

*A2*<br/>
O tipo de alocador do segundo `concurrent_vector` objeto.

*_A*<br/>
Um objeto do tipo `concurrent_vector`.

*_B*<br/>
Um objeto do tipo `concurrent_vector`.

### <a name="return-value"></a>Valor Retornado

**`true`** Se o vetor simultâneo no lado esquerdo do operador for maior que ou igual ao vetor simultâneo no lado direito do operador;. caso contrário **`false`** .

### <a name="remarks"></a>Comentários

O comportamento desse operador é idêntico ao operador equivalente para a `vector` classe no `std` namespace.

Esse método não é seguro para simultaneidade em relação a outros métodos que podem modificar qualquer vetor simultâneo `_A` ou `_B` .

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)
