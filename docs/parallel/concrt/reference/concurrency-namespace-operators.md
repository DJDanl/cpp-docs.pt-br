---
title: Operadores do namespace de simultaneidade
ms.date: 11/04/2016
f1_keywords:
- concrt/concurrency::operator!=
- concrt/concurrency:[operator&amp;&amp
ms.assetid: 8e373f23-fc8e-49f7-82e6-ba0c57b822f8
ms.openlocfilehash: aac43a15b09bd792118fbfe7ea51493b73b8ac9d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374390"
---
# <a name="concurrency-namespace-operators"></a>Operadores do namespace de simultaneidade

||||
|-|-|-|
|[operador!=](#operator_neq)|[Operador&amp;&amp;](#operator_amp_amp)|[Operador&gt;](#operator_gt)|
|[Operador&gt;=](#operator_gt_eq)|[Operador&lt;](#operator_lt)|[Operador&lt;=](#operator_lt_eq)|
|[operador==](#operator_eq_eq)|[operador&#124;&#124;](#operator_lor)| |

## <a name="operator124124-operator"></a><a name="operator_lor"></a>operador&#124;&#124; Operador

Cria uma tarefa que será concluída com sucesso quando qualquer uma das tarefas fornecidas como argumentos for concluída com sucesso.

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

### <a name="parameters"></a>Parâmetros

*Returntype*<br/>
O tipo da tarefa retornada.

*Lhs*<br/>
A primeira tarefa a combinar na tarefa resultante.

*rhs*<br/>
A segunda tarefa a combinar na tarefa resultante.

### <a name="return-value"></a>Valor retornado

Uma tarefa que é concluída com sucesso quando qualquer uma das tarefas de entrada tiver sido concluída com sucesso. Se as tarefas de entrada forem do tipo `T`, a saída dessa função será um `task<std::vector<T>`. Se as tarefas de entrada forem do tipo `void`, a tarefa de saída também será um `task<void>`.

### <a name="remarks"></a>Comentários

Se ambas as tarefas forem canceladas ou lançarem exceções, a tarefa retornada será concluída no estado cancelado, e `get()` uma `wait()` das exceções, se alguma for encontrada, será lançada quando você chamar ou nessa tarefa.

## <a name="operatorampamp-operator"></a><a name="operator_amp_amp"></a>operador&amp; &amp; operador

Cria uma tarefa que será concluída com sucesso quando ambas as tarefas fornecidas como argumentos forem concluídas com sucesso.

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

### <a name="parameters"></a>Parâmetros

*Returntype*<br/>
O tipo da tarefa retornada.

*Lhs*<br/>
A primeira tarefa a combinar na tarefa resultante.

*rhs*<br/>
A segunda tarefa a combinar na tarefa resultante.

### <a name="return-value"></a>Valor retornado

Uma tarefa que foi concluída com êxito quando ambas as tarefas de entrada foram concluídas com êxito. Se as tarefas de entrada forem do tipo `T`, a saída dessa função será um `task<std::vector<T>>`. Se as tarefas de entrada forem do tipo `void`, a tarefa de saída também será um `task<void>`.

### <a name="remarks"></a>Comentários

Se uma das tarefas for cancelada ou for uma exceção, a tarefa retornada será concluída mais cedo, no `get()` estado `wait()` cancelado, e a exceção, se ocorrer, será lançada se você ligar ou nessa tarefa.

## <a name="operator-operator"></a><a name="operator_eq_eq"></a>operador== Operador

Teste se `concurrent_vector` o objeto no lado esquerdo do `concurrent_vector` operador é igual ao objeto do lado direito.

```cpp
template<typename T, class A1, class A2>
inline bool operator== (
    const concurrent_vector<T, A1>& _A,
    const concurrent_vector<T, A2>& _B);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados dos elementos armazenados nos vetores simultâneos.

*A1*<br/>
O tipo alocador do `concurrent_vector` primeiro objeto.

*A2*<br/>
O tipo alocador do `concurrent_vector` segundo objeto.

*_A*<br/>
Um objeto do tipo `concurrent_vector`.

*_B*<br/>
Um objeto do tipo `concurrent_vector`.

### <a name="return-value"></a>Valor retornado

**verdade** se o vetor simultâneo do lado esquerdo do operador for igual ao vetor simultâneo do lado direito do operador; caso **contrário, falso**.

### <a name="remarks"></a>Comentários

Dois vetores simultâneos são iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

Este método não é simultâneo em relação a outros `_A` métodos que poderiam modificar qualquer um dos vetores simultâneos ou `_B`.

## <a name="operator-operator"></a><a name="operator_neq"></a>operador!= Operador

Teste se `concurrent_vector` o objeto do lado esquerdo do `concurrent_vector` operador não é igual ao objeto do lado direito.

```cpp
template<typename T, class A1, class A2>
inline bool operator!= (
    const concurrent_vector<T, A1>& _A,
    const concurrent_vector<T, A2>& _B);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados dos elementos armazenados nos vetores simultâneos.

*A1*<br/>
O tipo alocador do `concurrent_vector` primeiro objeto.

*A2*<br/>
O tipo alocador do `concurrent_vector` segundo objeto.

*_A*<br/>
Um objeto do tipo `concurrent_vector`.

*_B*<br/>
Um objeto do tipo `concurrent_vector`.

### <a name="return-value"></a>Valor retornado

**verdade** se os vetores simultâneos não forem iguais; **falso** se os vetores simultâneos são iguais.

### <a name="remarks"></a>Comentários

Dois vetores simultâneos são iguais se tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

Este método não é simultâneo em relação a outros `_A` métodos que poderiam modificar qualquer um dos vetores simultâneos ou `_B`.

## <a name="operatorlt-operator"></a><a name="operator_lt"></a>operador&lt; operador

Teste se `concurrent_vector` o objeto do lado esquerdo do `concurrent_vector` operador é menor que o objeto do lado direito.

```cpp
template<typename T, class A1, class A2>
inline bool operator<(
    const concurrent_vector<T, A1>& _A,
    const concurrent_vector<T, A2>& _B);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados dos elementos armazenados nos vetores simultâneos.

*A1*<br/>
O tipo alocador do `concurrent_vector` primeiro objeto.

*A2*<br/>
O tipo alocador do `concurrent_vector` segundo objeto.

*_A*<br/>
Um objeto do tipo `concurrent_vector`.

*_B*<br/>
Um objeto do tipo `concurrent_vector`.

### <a name="return-value"></a>Valor retornado

**verdade** se o vetor simultâneo do lado esquerdo do operador for menor que o vetor simultâneo no lado direito do operador; caso **contrário, falso**.

### <a name="remarks"></a>Comentários

O comportamento deste operador é idêntico ao `vector` operador `std` equivalente para a classe no namespace.

Este método não é simultâneo em relação a outros `_A` métodos que poderiam modificar qualquer um dos vetores simultâneos ou `_B`.

## <a name="operatorlt-operator"></a><a name="operator_lt_eq"></a>operador&lt;= Operador

Teste se `concurrent_vector` o objeto do lado esquerdo do operador `concurrent_vector` é menor ou igual ao objeto do lado direito.

```cpp
template<typename T, class A1, class A2>
inline bool operator<= (
    const concurrent_vector<T, A1>& _A,
    const concurrent_vector<T, A2>& _B);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados dos elementos armazenados nos vetores simultâneos.

*A1*<br/>
O tipo alocador do `concurrent_vector` primeiro objeto.

*A2*<br/>
O tipo alocador do `concurrent_vector` segundo objeto.

*_A*<br/>
Um objeto do tipo `concurrent_vector`.

*_B*<br/>
Um objeto do tipo `concurrent_vector`.

### <a name="return-value"></a>Valor retornado

**verdade** se o vetor simultâneo do lado esquerdo do operador for menor ou igual ao vetor simultâneo do lado direito do operador; caso **contrário, falso**.

### <a name="remarks"></a>Comentários

O comportamento deste operador é idêntico ao `vector` operador `std` equivalente para a classe no namespace.

Este método não é simultâneo em relação a outros `_A` métodos que poderiam modificar qualquer um dos vetores simultâneos ou `_B`.

## <a name="operatorgt-operator"></a><a name="operator_gt"></a>operador&gt; operador

Teste se `concurrent_vector` o objeto do lado esquerdo do `concurrent_vector` operador é maior que o objeto do lado direito.

```cpp
template<typename T, class A1, class A2>
inline bool operator>(
    const concurrent_vector<T, A1>& _A,
    const concurrent_vector<T, A2>& _B);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados dos elementos armazenados nos vetores simultâneos.

*A1*<br/>
O tipo alocador do `concurrent_vector` primeiro objeto.

*A2*<br/>
O tipo alocador do `concurrent_vector` segundo objeto.

*_A*<br/>
Um objeto do tipo `concurrent_vector`.

*_B*<br/>
Um objeto do tipo `concurrent_vector`.

### <a name="return-value"></a>Valor retornado

**verdade** se o vetor simultâneo do lado esquerdo do operador for maior do que o vetor simultâneo no lado direito do operador; caso **contrário, falso**.

### <a name="remarks"></a>Comentários

O comportamento deste operador é idêntico ao `vector` operador `std` equivalente para a classe no namespace.

Este método não é simultâneo em relação a outros `_A` métodos que poderiam modificar qualquer um dos vetores simultâneos ou `_B`.

## <a name="operatorgt-operator"></a><a name="operator_gt_eq"></a>operador&gt;= Operador

Teste se `concurrent_vector` o objeto do lado esquerdo do operador `concurrent_vector` é maior ou igual ao objeto do lado direito.

```cpp
template<typename T, class A1, class A2>
inline bool operator>= (
    const concurrent_vector<T, A1>& _A,
    const concurrent_vector<T, A2>& _B);
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados dos elementos armazenados nos vetores simultâneos.

*A1*<br/>
O tipo alocador do `concurrent_vector` primeiro objeto.

*A2*<br/>
O tipo alocador do `concurrent_vector` segundo objeto.

*_A*<br/>
Um objeto do tipo `concurrent_vector`.

*_B*<br/>
Um objeto do tipo `concurrent_vector`.

### <a name="return-value"></a>Valor retornado

**verdade** se o vetor simultâneo do lado esquerdo do operador for maior ou igual ao vetor simultâneo no lado direito do operador; caso **contrário, falso**.

### <a name="remarks"></a>Comentários

O comportamento deste operador é idêntico ao `vector` operador `std` equivalente para a classe no namespace.

Este método não é simultâneo em relação a outros `_A` métodos que poderiam modificar qualquer um dos vetores simultâneos ou `_B`.

## <a name="see-also"></a>Confira também

[namespace de concorrência](concurrency-namespace.md)
