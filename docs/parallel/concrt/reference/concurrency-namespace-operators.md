---
title: Operadores do namespace de simultaneidade | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- concrt/concurrency::operator!=
- concrt/concurrency:[operator&amp;&amp
dev_langs:
- C++
ms.assetid: 8e373f23-fc8e-49f7-82e6-ba0c57b822f8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8065be6cc53cad04d5d52bea91da05bb3125dd63
ms.sourcegitcommit: 8480f16893f09911f08a58caf684405404f7ac8e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/12/2018
ms.locfileid: "49162562"
---
# <a name="concurrency-namespace-operators"></a>Operadores do namespace de simultaneidade

||||
|-|-|-|
|[operator!=](#operator_neq)|[operator&amp;&amp;](#operator_amp_amp)|[operator&gt;](#operator_gt)|
|[operator&gt;=](#operator_gt_eq)|[operator&lt;](#operator_lt)|[operator&lt;=](#operator_lt_eq)|
|[operator==](#operator_eq_eq)|[operator||](#operator_lor)|

##  <a name="operator_lor"></a>  operador&#124; &#124; operador

Cria uma tarefa que será concluída com êxito quando qualquer uma das tarefas fornecidas como argumentos forem concluídas com êxito.

```
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

*ReturnType*<br/>
O tipo da tarefa retornada.

*LHS*<br/>
A primeira tarefa a combinar na tarefa resultante.

*rhs*<br/>
A segunda tarefa a combinar na tarefa resultante.

### <a name="return-value"></a>Valor de retorno

Uma tarefa que é concluída com êxito quando qualquer uma das tarefas de entrada foi concluída com êxito. Se as tarefas de entrada forem do tipo `T`, a saída dessa função será um `task<std::vector<T>`. Se as tarefas de entrada forem do tipo `void`, a tarefa de saída também será um `task<void>`.

### <a name="remarks"></a>Comentários

Se ambas as tarefas são canceladas ou lançam exceções, a tarefa retornada será concluída no estado cancelado, e uma das exceções, se nenhum for encontrado, será gerada quando você chama `get()` ou `wait()` nessa tarefa.

##  <a name="operator_amp_amp"></a>  operador&amp; &amp; operador

Cria uma tarefa que será concluída com êxito quando ambas as tarefas fornecidas como argumentos forem concluídas com êxito.

```
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

*ReturnType*<br/>
O tipo da tarefa retornada.

*LHS*<br/>
A primeira tarefa a combinar na tarefa resultante.

*rhs*<br/>
A segunda tarefa a combinar na tarefa resultante.

### <a name="return-value"></a>Valor de retorno

Uma tarefa que foi concluída com êxito quando ambas as tarefas de entrada foram concluídas com êxito. Se as tarefas de entrada forem do tipo `T`, a saída dessa função será um `task<std::vector<T>>`. Se as tarefas de entrada forem do tipo `void`, a tarefa de saída também será um `task<void>`.

### <a name="remarks"></a>Comentários

Se uma das tarefas for cancelada ou gerar uma exceção, a tarefa retornada será concluída antecipadamente, no estado cancelado, e a exceção, se alguma for encontrada, será gerada se você chamar `get()` ou `wait()` nessa tarefa.

##  <a name="operator_eq_eq"></a>  operador Operator = =

Testa se o `concurrent_vector` objeto no lado esquerdo do operador é igual ao `concurrent_vector` objeto no lado direito.

```
template<typename T, class A1, class A2>
inline bool operator== (
    const concurrent_vector<T, A1>& _A,
    const concurrent_vector<T, A2>& _B);
```

### <a name="parameters"></a>Parâmetros

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

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o vetor simultâneo no lado esquerdo do operador é igual ao vetor simultâneo no lado direito do operador; caso contrário **falso**.

### <a name="remarks"></a>Comentários

Dois vetores simultâneas são iguais se eles tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

Esse método não é seguro em simultaneidade em relação a outros métodos que poderia modificar qualquer um dos vetores de simultâneos `_A` ou `_B`.

##  <a name="operator_neq"></a>  operador! = operador

Testa se o `concurrent_vector` objeto no lado esquerdo do operador não é igual ao `concurrent_vector` objeto no lado direito.

```
template<typename T, class A1, class A2>
inline bool operator!= (
    const concurrent_vector<T, A1>& _A,
    const concurrent_vector<T, A2>& _B);
```

### <a name="parameters"></a>Parâmetros

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

### <a name="return-value"></a>Valor de retorno

**True** se os vetores simultâneos não forem iguais; **falsos** se os vetores simultâneos são iguais.

### <a name="remarks"></a>Comentários

Dois vetores simultâneas são iguais se eles tiverem o mesmo número de elementos e seus respectivos elementos tiverem os mesmos valores. Caso contrário, são diferentes.

Esse método não é seguro em simultaneidade em relação a outros métodos que poderia modificar qualquer um dos vetores de simultâneos `_A` ou `_B`.

##  <a name="operator_lt"></a>  operador&lt; operador

Testa se o `concurrent_vector` objeto no lado esquerdo do operador é menor do que o `concurrent_vector` objeto no lado direito.

```
template<typename T, class A1, class A2>
inline bool operator<(
    const concurrent_vector<T, A1>& _A,
    const concurrent_vector<T, A2>& _B);
```

### <a name="parameters"></a>Parâmetros

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

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o vetor simultâneo no lado esquerdo do operador for menor que o vetor simultâneo no lado direito do operador; caso contrário **falso**.

### <a name="remarks"></a>Comentários

O comportamento desse operador é idêntico ao operador equivalente para o `vector` classe o `std` namespace.

Esse método não é seguro em simultaneidade em relação a outros métodos que poderia modificar qualquer um dos vetores de simultâneos `_A` ou `_B`.

##  <a name="operator_lt_eq"></a>  operador&lt;Operator =

Testa se o `concurrent_vector` objeto no lado esquerdo do operador é menor ou igual ao `concurrent_vector` objeto no lado direito.

```
template<typename T, class A1, class A2>
inline bool operator<= (
    const concurrent_vector<T, A1>& _A,
    const concurrent_vector<T, A2>& _B);
```

### <a name="parameters"></a>Parâmetros

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

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o vetor simultâneo no lado esquerdo do operador for menor que ou igual ao vetor simultâneo no lado direito do operador; caso contrário **falso**.

### <a name="remarks"></a>Comentários

O comportamento desse operador é idêntico ao operador equivalente para o `vector` classe o `std` namespace.

Esse método não é seguro em simultaneidade em relação a outros métodos que poderia modificar qualquer um dos vetores de simultâneos `_A` ou `_B`.

##  <a name="operator_gt"></a>  operador&gt; operador

Testa se o `concurrent_vector` objeto no lado esquerdo do operador é maior que o `concurrent_vector` objeto no lado direito.

```
template<typename T, class A1, class A2>
inline bool operator>(
    const concurrent_vector<T, A1>& _A,
    const concurrent_vector<T, A2>& _B);
```

### <a name="parameters"></a>Parâmetros

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

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o vetor simultâneo no lado esquerdo do operador for maior que o vetor simultâneo no lado direito do operador; caso contrário **falso**.

### <a name="remarks"></a>Comentários

O comportamento desse operador é idêntico ao operador equivalente para o `vector` classe o `std` namespace.

Esse método não é seguro em simultaneidade em relação a outros métodos que poderia modificar qualquer um dos vetores de simultâneos `_A` ou `_B`.

##  <a name="operator_gt_eq"></a>  operador&gt;Operator =

Testa se o `concurrent_vector` objeto no lado esquerdo do operador é maior que ou igual ao `concurrent_vector` objeto no lado direito.

```
template<typename T, class A1, class A2>
inline bool operator>= (
    const concurrent_vector<T, A1>& _A,
    const concurrent_vector<T, A2>& _B);
```

### <a name="parameters"></a>Parâmetros

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

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o vetor simultâneo no lado esquerdo do operador for maior que ou igual ao vetor simultâneo no lado direito do operador; caso contrário **falso**.

### <a name="remarks"></a>Comentários

O comportamento desse operador é idêntico ao operador equivalente para o `vector` classe o `std` namespace.

Esse método não é seguro em simultaneidade em relação a outros métodos que poderia modificar qualquer um dos vetores de simultâneos `_A` ou `_B`.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
