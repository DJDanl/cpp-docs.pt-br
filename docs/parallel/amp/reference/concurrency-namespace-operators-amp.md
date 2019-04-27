---
title: Operadores do namespace de simultaneidade (AMP)
ms.date: 11/04/2016
ms.assetid: 77f1ae17-1eb2-480d-8fe5-66d4c24bb91e
ms.openlocfilehash: e2957aa84ffbf420dcf2672359a442b754866649
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62180408"
---
# <a name="concurrency-namespace-operators-amp"></a>Operadores do namespace de simultaneidade (AMP)

||||
|-|-|-|
|[operator!=](#operator_neq)|[operator%](#operator_mod)|[operator*](#operator_star)|
|[operator+](#operator_add)|[operator-](#operator-)|[operator/](#operator_div)|
|[operator==](#operator_eq_eq)|

##  <a name="operator_eq_eq"></a>  operator==

Determina se os argumentos especificados são iguais.

```
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
A classificação dos argumentos de tuple.

*_Lhs*<br/>
Um dos tuples para comparar.

*_Rhs*<br/>
Um dos tuples para comparar.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se os tuples forem iguais; caso contrário, **falso**.

##  <a name="operator_neq"></a>  operator!=

Determina se os argumentos especificados não são iguais.

```
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
A classificação dos argumentos de tuple.

*_Lhs*<br/>
Um dos tuples para comparar.

*_Rhs*<br/>
Um dos tuples para comparar.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se os tuples não forem iguais; caso contrário, **falso**.

##  <a name="operator_add"></a>  operator+

Calcula a soma em todo componente dos argumentos especificados.

```
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
A classificação dos argumentos de tuple.

*_Lhs*<br/>
Um dos argumentos a serem adicionados.

*_Rhs*<br/>
Um dos argumentos a serem adicionados.

### <a name="return-value"></a>Valor de retorno

A soma em todo componente dos argumentos especificados.

##  <a name="operator-"></a>  operator-

Calcula a diferença em entre os argumentos especificados.

```
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
A classificação dos argumentos de tuple.

*_Lhs*<br/>
O argumento a ser subtraído.

*_Rhs*<br/>
O argumento a ser subtraído.

### <a name="return-value"></a>Valor de retorno

A diferença em todo componente entre os argumentos especificados.

##  <a name="operator_star"></a>  operator*

Calcula o produto em todo componente dos argumentos especificados.

```
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
A classificação dos argumentos de tuple.

*_Lhs*<br/>
Um dos tuples para multiplicar.

*_Rhs*<br/>
Um dos tuples para multiplicar.

### <a name="return-value"></a>Valor de retorno

O produto em todo componente dos argumentos especificados.

##  <a name="operator_div"></a>  operator/

Calcula o quociente em todo componente dos argumentos especificados.

```
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
A classificação dos argumentos de tuple.

*_Lhs*<br/>
A tupla a ser dividida.

*_Rhs*<br/>
A tupla pela qual dividir.

### <a name="return-value"></a>Valor de retorno

O quociente em todo componente dos argumentos especificados.

##  <a name="operator_mod"></a> operator%

Calcula o módulo do primeiro argumento especificado pelo segundo argumento especificado.

```
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
A classificação dos argumentos de tuple.

*_Lhs*<br/>
A tupla da qual o modulo é calculado.

*_Rhs*<br/>
A tupla a módulo por.

### <a name="return-value"></a>Valor de retorno

O resultado do primeiro argumento especificado modula o segundo argumento especificado.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade ](concurrency-namespace-cpp-amp.md)
