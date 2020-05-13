---
title: Operadores do namespace de simultaneidade (AMP)
ms.date: 11/04/2016
ms.assetid: 77f1ae17-1eb2-480d-8fe5-66d4c24bb91e
ms.openlocfilehash: c4086029b71d71091a12b9b6023cc6098faf2f85
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376302"
---
# <a name="concurrency-namespace-operators-amp"></a>Operadores do namespace de simultaneidade (AMP)

||||
|-|-|-|
|[operador!=](#operator_neq)|[operador%](#operator_mod)|[operador*](#operator_star)|
|[operador+](#operator_add)|[operador-](#operator-)|[operador/](#operator_div)|
|[operador==](#operator_eq_eq)|

## <a name="operator"></a><a name="operator_eq_eq"></a>operador==

Determina se os argumentos especificados são iguais.

```cpp
template <
    int _Rank,
    template <int> class _Tuple_type
>
bool operator== (
    const _Tuple_type<_Rank>& _Lhs,
    const _Tuple_type<_Rank>& _Rhs) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Rank*<br/>
A classificação dos argumentos tuplos.

*_Lhs*<br/>
Uma das tuplas para comparar.

*_Rhs*<br/>
Uma das tuplas para comparar.

### <a name="return-value"></a>Valor retornado

**verdade** se as tuplas são iguais; caso contrário, **falso**.

## <a name="operator"></a><a name="operator_neq"></a>operador!=

Determina se os argumentos especificados não são iguais.

```cpp
template <
    int _Rank,
    template <int> class _Tuple_type
>
bool operator!= (
    const _Tuple_type<_Rank>& _Lhs,
    const _Tuple_type<_Rank>& _Rhs) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Rank*<br/>
A classificação dos argumentos tuplos.

*_Lhs*<br/>
Uma das tuplas para comparar.

*_Rhs*<br/>
Uma das tuplas para comparar.

### <a name="return-value"></a>Valor retornado

**verdade** se as tuplas não são iguais; caso contrário, **falso**.

## <a name="operator"></a><a name="operator_add"></a>operador+

Calcula a soma dos argumentos especificados.

```cpp
template <
    int _Rank,
    template <int> class _Tuple_type
>
class _Tuple_type> _Tuple_type<_Rank>   operator+(
    const _Tuple_type<_Rank>& _Lhs,
    const _Tuple_type<_Rank>& _Rhs) restrict(amp,cpu);

template <
    int _Rank,
    template <int> class _Tuple_type
>
class _Tuple_type> _Tuple_type<_Rank>   operator+(
    const _Tuple_type<_Rank>& _Lhs,
    typename _Tuple_type<_Rank>::value_type _Rhs) restrict(amp,cpu);

template <
    int _Rank,
    template <int> class _Tuple_type
>
class _Tuple_type> _Tuple_type<_Rank>   operator+(
    typename _Tuple_type<_Rank>::value_type _Lhs,
    const _Tuple_type<_Rank>& _Rhs) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Rank*<br/>
A classificação dos argumentos tuplos.

*_Lhs*<br/>
Um dos argumentos a acrescentar.

*_Rhs*<br/>
Um dos argumentos a acrescentar.

### <a name="return-value"></a>Valor retornado

A soma em termos de componentes dos argumentos especificados.

## <a name="operator-"></a><a name="operator-"></a>operador-

Calcula a diferença em termos de componentes entre os argumentos especificados.

```cpp
template <
    int _Rank,
    template <int> class _Tuple_type
>
_Tuple_type<_Rank>   operator-(
    const _Tuple_type<_Rank>& _Lhs,
    const _Tuple_type<_Rank>& _Rhs) restrict(amp,cpu);

template <
    int _Rank,
    template <int> class _Tuple_type
>
_Tuple_type<_Rank>   operator-(
    const _Tuple_type<_Rank>& _Lhs,
    typename _Tuple_type<_Rank>::value_type _Rhs) restrict(amp,cpu);

template <
    int _Rank,
    template <int> class _Tuple_type
>
_Tuple_type<_Rank>   operator-(
    typename _Tuple_type<_Rank>::value_type _Lhs,
    const _Tuple_type<_Rank>& _Rhs) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Rank*<br/>
A classificação dos argumentos tuplos.

*_Lhs*<br/>
O argumento a ser subtraído.

*_Rhs*<br/>
O argumento para subtrair.

### <a name="return-value"></a>Valor retornado

A diferença em termos de componentes entre os argumentos especificados.

## <a name="operator"></a><a name="operator_star"></a>operador*

Calcula o produto em termos de componentes dos argumentos especificados.

```cpp
template <
    int _Rank,
    template <int> class _Tuple_type
>
_Tuple_type<_Rank>   operator*(
    const _Tuple_type<_Rank>& _Lhs,
    typename _Tuple_type<_Rank>::value_type _Rhs) restrict(amp,cpu);

template <
    int _Rank,
    template <int> class _Tuple_type
>
_Tuple_type<_Rank>   operator*(
    typename _Tuple_type<_Rank>::value_type _Lhs,
    const _Tuple_type<_Rank>& _Rhs) restrict(amp, cpu);
```

### <a name="parameters"></a>Parâmetros

*_Rank*<br/>
A classificação dos argumentos tuplos.

*_Lhs*<br/>
Uma das tuplas para se multiplicar.

*_Rhs*<br/>
Uma das tuplas para se multiplicar.

### <a name="return-value"></a>Valor retornado

O produto em termos de componentes dos argumentos especificados.

## <a name="operator"></a><a name="operator_div"></a>operador/

Calcula o quociente em termos de componentes dos argumentos especificados.

```cpp
template <
    int _Rank,
    template <int> class _Tuple_type
>
_Tuple_type<_Rank>   operator/(
    const _Tuple_type<_Rank>& _Lhs,
    typename _Tuple_type<_Rank>::value_type _Rhs) restrict(amp,cpu);

template <
    int _Rank,
    template <int> class _Tuple_type
>
_Tuple_type<_Rank>   operator/(
    typename _Tuple_type<_Rank>::value_type _Lhs,
    const _Tuple_type<_Rank>& _Rhs) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Rank*<br/>
A classificação dos argumentos tuplos.

*_Lhs*<br/>
A tuple a ser dividida.

*_Rhs*<br/>
A tuple para dividir.

### <a name="return-value"></a>Valor retornado

O quociente em termos de componentes dos argumentos especificados.

## <a name="operator"></a><a name="operator_mod"></a>operador%

Calcula o módulo do primeiro argumento especificado pelo segundo argumento especificado.

```cpp
template <
    int _Rank,
    template <int> class _Tuple_type
>
_Tuple_type<_Rank>   operator%(
    const _Tuple_type<_Rank>& _Lhs,
    typename _Tuple_type<_Rank>::value_type _Rhs) restrict(amp,cpu);

template <
    int _Rank,
    template <int> class _Tuple_type
>
_Tuple_type<_Rank>   operator%(
    typename _Tuple_type<_Rank>::value_type _Lhs,
    const _Tuple_type<_Rank>& _Rhs) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Rank*<br/>
A classificação dos argumentos tuplos.

*_Lhs*<br/>
A tupla da qual o modulo é calculado.

*_Rhs*<br/>
A tupla para modulo por.

### <a name="return-value"></a>Valor retornado

O resultado do primeiro argumento especificado modulus o segundo argumento especificado.

## <a name="see-also"></a>Confira também

[Namespace de concorrência](concurrency-namespace-cpp-amp.md)
