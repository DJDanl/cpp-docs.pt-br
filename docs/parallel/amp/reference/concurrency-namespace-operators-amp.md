---
title: Operadores do namespace de simultaneidade (AMP)
ms.date: 11/04/2016
ms.assetid: 77f1ae17-1eb2-480d-8fe5-66d4c24bb91e
ms.openlocfilehash: 03079f8899f3b13c8509e1affd10a82191b1817c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228473"
---
# <a name="concurrency-namespace-operators-amp"></a>Operadores do namespace de simultaneidade (AMP)

||||
|-|-|-|
|[operador! =](#operator_neq)|[operador](#operator_mod)|[operador](#operator_star)|
|[operador +](#operator_add)|[operador](#operator-)|[operador](#operator_div)|
|[operador = =](#operator_eq_eq)|

## <a name="operator"></a><a name="operator_eq_eq"></a>operador = =

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

### <a name="parameters"></a>parâmetros

*_Rank*<br/>
A classificação dos argumentos da tupla.

*_Lhs*<br/>
Uma das tuplas para comparar.

*_Rhs*<br/>
Uma das tuplas para comparar.

### <a name="return-value"></a>Valor retornado

**`true`** Se as tuplas forem iguais; caso contrário, **`false`** .

## <a name="operator"></a><a name="operator_neq"></a>operador! =

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

### <a name="parameters"></a>parâmetros

*_Rank*<br/>
A classificação dos argumentos da tupla.

*_Lhs*<br/>
Uma das tuplas para comparar.

*_Rhs*<br/>
Uma das tuplas para comparar.

### <a name="return-value"></a>Valor retornado

**`true`** Se as tuplas não forem iguais; caso contrário, **`false`** .

## <a name="operator"></a><a name="operator_add"></a>operador +

Computa a soma de componentes dos argumentos especificados.

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

### <a name="parameters"></a>parâmetros

*_Rank*<br/>
A classificação dos argumentos da tupla.

*_Lhs*<br/>
Um dos argumentos a serem adicionados.

*_Rhs*<br/>
Um dos argumentos a serem adicionados.

### <a name="return-value"></a>Valor retornado

A soma por componente dos argumentos especificados.

## <a name="operator-"></a><a name="operator-"></a>operador

Computa a diferença de componente entre os argumentos especificados.

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

### <a name="parameters"></a>parâmetros

*_Rank*<br/>
A classificação dos argumentos da tupla.

*_Lhs*<br/>
O argumento a ser subtraído.

*_Rhs*<br/>
O argumento a ser subtraído.

### <a name="return-value"></a>Valor retornado

A diferença de componente entre os argumentos especificados.

## <a name="operator"></a><a name="operator_star"></a>operador

Computa o produto com componente dos argumentos especificados.

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

### <a name="parameters"></a>parâmetros

*_Rank*<br/>
A classificação dos argumentos da tupla.

*_Lhs*<br/>
Uma das tuplas para multiplicar.

*_Rhs*<br/>
Uma das tuplas para multiplicar.

### <a name="return-value"></a>Valor retornado

O produto por componente dos argumentos especificados.

## <a name="operator"></a><a name="operator_div"></a>operador

Computa o quociente de componente dos argumentos especificados.

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

### <a name="parameters"></a>parâmetros

*_Rank*<br/>
A classificação dos argumentos da tupla.

*_Lhs*<br/>
A tupla a ser dividida.

*_Rhs*<br/>
A tupla pela qual dividir.

### <a name="return-value"></a>Valor retornado

O quociente de componente dos argumentos especificados.

## <a name="operator"></a><a name="operator_mod"></a>operador

Computa o módulo do primeiro argumento especificado pelo segundo argumento especificado.

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

### <a name="parameters"></a>parâmetros

*_Rank*<br/>
A classificação dos argumentos da tupla.

*_Lhs*<br/>
A tupla da qual o módulo é calculado.

*_Rhs*<br/>
A tupla pela qual o módulo será analisado.

### <a name="return-value"></a>Valor retornado

O resultado do primeiro módulo de argumento especificado é o segundo argumento especificado.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace-cpp-amp.md)
