---
title: Operadores &lt;chrono&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- chrono/std::operator modulo
ms.assetid: c5a19267-4684-40c1-b7a9-cc1012b058f3
ms.openlocfilehash: 1ac1051ddaa67dc1970119586ecb9e937583c58a
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33847394"
---
# <a name="ltchronogt-operators"></a>Operadores &lt;chrono&gt;

||||
|-|-|-|
|[módulo do operador](#op_modulo)|[operator!=](#op_neq)|[operator&gt;](#op_gt)|
|[operator&gt;=](#op_gt_eq)|[operator&lt;](#op_lt)|[operator&lt;=](#op_lt_eq)|
|[operator*](#op_star)|[operator+](#op_add)|[operator-](#operator-)|
|[operator/](#op_div)|[operator==](#op_eq_eq)|

## <a name="operator-"></a>  operator-

Operador para subtração ou negação de objetos [duration](../standard-library/duration-class.md) e [time_point](../standard-library/time-point-class.md).

```cpp
template <class Rep1, class Period1, class Rep2, class Period2>
constexpr typename common_type<duration<Rep1, Period1>, duration<Rep2, Period2>>::type
   operator-(
       const duration<Rep1, Period1>& Left,
       cconst duration<Rep2, Period2>& Right);

template <class Clock, class Duration1, class Rep2, class Period2>
constexpr time_point<Clock, typename common_type<Duration1, duration<Rep2, Period2>>::type
   operator-(
       const time_point<Clock, Duration1>& Time,
       const duration<Rep2, Period2>& Dur);


template <class Clock, class Duration1, class Duration2>
constexpr typename common_type<Duration1, Duration2>::type
   operator-(
       const time_point<Clock, Duration1>& Left,
       const time_point<Clock, Duration2>& Right);
```

### <a name="parameters"></a>Parâmetros

`Left` À esquerda `duration` ou `time_point` objeto.

`Right` O direito de `duration` ou `time_point` objeto.

`Time` Um `time_point` objeto.

`Dur` Um `duration` objeto.

### <a name="return-value"></a>Valor de retorno

A primeira função retorna um objeto `duration` cujo comprimento do intervalo é a diferença entre os intervalos de tempo dos dois argumentos.

A segunda função retorna um objeto `time_point` que representa um ponto no tempo que é deslocado, pela negação do intervalo de tempo representado por `Dur`, do ponto no tempo especificado por `Time`.

A terceira função retorna um objeto `duration` que representa o intervalo de tempo entre `Left` e `Right`.

## <a name="op_neq"></a>  operator!=

Operador de desigualdade para objetos [duration](../standard-library/duration-class.md) ou [time_point](../standard-library/time-point-class.md).

```cpp
template <class Rep1, class Period1, class Rep2, class Period2>
constexpr bool operator!=(
    const duration<Rep1, Period1>& Left,
    const duration<Rep2, Period2>& Right);


template <class Clock, class Duration1, class Duration2>
constexpr bool operator!=(
    const time_point<Clock, Duration1>& Left,
    const time_point<Clock, Duration2>& Right);
```

### <a name="parameters"></a>Parâmetros

`Left` À esquerda `duration` ou `time_point` objeto.

`Right` O direito de `duration` ou `time_point` objeto.

### <a name="return-value"></a>Valor de retorno

Cada função retorna `!(Left == Right)`.

## <a name="op_star"></a>  operator*

Operador de multiplicação para objetos [duration](../standard-library/chrono-operators.md#op_star).

```cpp
template <class Rep1, class Period1, class Rep2>
constexpr duration<typename common_type<Rep1, Rep2>::type, Period1>
   operator*(
      const duration<Rep1, Period1>& Dur,
      const Rep2& Mult);


template <class Rep1, class Rep2, class Period2>
constexpr duration<typename common_type<Rep1, Rep2>::type, Period2>
   operator*(
       const Rep1& Mult,
       const duration<Rep2,
       Period2>& Dur);
```

### <a name="parameters"></a>Parâmetros

`Dur` Um `duration` objeto.

`Mult` Um valor inteiro.

### <a name="return-value"></a>Valor de retorno

Cada função retorna um objeto `duration` cujo tamanho de intervalo é `Mult` multiplicado pelo tamanho de `Dur`.

A menos que `is_convertible<Rep2, common_type<Rep1, Rep2>>`*seja verdadeiro*, a primeira função não participará da resolução de sobrecarga. Para obter mais informações, consulte [<type_traits>](../standard-library/type-traits.md).

A menos que `is_convertible<Rep1, common_type<Rep1, Rep2>>`*seja verdadeiro*, a segunda função não participará da resolução de sobrecarga. Para obter mais informações, consulte [<type_traits>](../standard-library/type-traits.md).

## <a name="op_div"></a>  operator/

Operador de divisão para objetos [duration](../standard-library/chrono-operators.md#op_star).

```cpp
template <class Rep1, class Period1, class Rep2>
constexpr duration<typename common_type<Rep1, Rep2>::type, Period1>
   operator/(
     const duration<Rep1, Period1>& Dur,
     const Rep2& Div);


template <class Rep1, class Period1, class Rep2, class Period2>
constexpr typename common_type<Rep1, Rep2>::type
   operator/(
     const duration<Rep1, Period1>& Left,
     const duration<Rep2, Period2>& Right);
```

### <a name="parameters"></a>Parâmetros

`Dur` Um `duration` objeto.

`Div` Um valor inteiro.

`Left` À esquerda `duration` objeto.

`Right` Direita `duration` objeto.

### <a name="return-value"></a>Valor de retorno

O primeiro operador retorna um objeto duration cujo tamanho de intervalo é o tamanho de `Dur` dividido pelo valor de `Div`.

O segundo operador retorna a proporção dos tamanhos de intervalo de `Left` e `Right`.

A menos que `is_convertible<Rep2, common_type<Rep1, Rep2>>`*seja verdadeiro* e `Rep2` não seja uma instanciação de `duration`, o primeiro operador não participará da resolução de sobrecarga. Para obter mais informações, consulte [<type_traits>](../standard-library/type-traits.md).

## <a name="op_add"></a>  operator+

Adiciona os objetos [duration](../standard-library/duration-class.md) e [time_point](../standard-library/time-point-class.md).

```cpp
template <class Rep1, class Period1, class Rep2, class Period2>
constexpr typename common_type<duration<Rep1, Period1>, duration<Rep2, Period2>>::type
   operator+(
      const duration<Rep1, Period1>& Left,
      const duration<Rep2, Period2>& Right);


template <class Clock, class Duration1, class Rep2, class Period2>
constexpr time_point<Clock, typename common_type<Duration1, duration<Rep2, Period2>>::type>
   operator+(
      const time_point<Clock, Duration1>& Time,
      const duration<Rep2, Period2>& Dur);


template <class Rep1, class Period1, class Clock, class Duration2>
time_point<Clock, constexpr typename common_type<duration<Rep1, Period1>, Duration2>::type>
   operator+(
      const duration<Rep1, Period1>& Dur,
      const time_point<Clock, Duration2>& Time);
```

### <a name="parameters"></a>Parâmetros

`Left` À esquerda `duration` ou `time_point` objeto.

`Right` O direito de `duration` ou `time_point` objeto.

`Time` Um `time_point` objeto.

`Dur` Um `duration` objeto.

### <a name="return-value"></a>Valor de retorno

A primeira função retorna um objeto `duration` que tem um intervalo de tempo igual à soma dos intervalos de `Left` e `Right`.

A segunda e a terceira funções retornam um objeto `time_point` que representa um ponto no tempo deslocado, pelo intervalo `Dur`, do ponto no tempo `Time`.

## <a name="op_lt"></a>  operator&lt;

Determina se um objeto [duration](../standard-library/duration-class.md) ou [time_point](../standard-library/time-point-class.md) é menor que outro objeto `duration` ou `time_point`.

```cpp
template <class Rep1, class Period1, class Rep2, class Period2>
constexpr bool operator<(
    const duration<Rep1, Period1>& Left,
    const duration<Rep2, Period2>& Right);


template <class Clock, class Duration1, class Duration2>
constexpr bool operator<(
    const time_point<Clock, Duration1>& Left,
    const time_point<Clock, Duration2>& Right);
```

### <a name="parameters"></a>Parâmetros

`Left` À esquerda `duration` ou `time_point` objeto.

`Right` O direito de `duration` ou `time_point` objeto.

### <a name="return-value"></a>Valor de retorno

A primeira função retornará `true` se o tamanho do intervalo de `Left` for menor que o tamanho do intervalo de `Right`. Caso contrário, a função retorna `false`.

A segunda função retornará `true` se `Left` preceder `Right`. Caso contrário, a função retorna `false`.

## <a name="op_lt_eq"></a>  operator&lt;=

Determina se um objeto [duration](../standard-library/duration-class.md) ou [time_point](../standard-library/time-point-class.md) é menor ou igual a outro objeto `duration` ou `time_point`.

```cpp
template <class Rep1, class Period1, class Rep2, class Period2>
constexpr bool operator<=(
    const duration<Rep1, Period1>& Left,
    const duration<Rep2, Period2>& Right);

template <class Clock, class Duration1, class Duration2>
constexpr bool operator<=(
    const time_point<Clock, Duration1>& Left,
    const time_point<Clock, Duration2>& Right);
```

### <a name="parameters"></a>Parâmetros

`Left` À esquerda `duration` ou `time_point` objeto.

`Right` O direito de `duration` ou `time_point` objeto.

### <a name="return-value"></a>Valor de retorno

Cada função retorna `!(Right < Left)`.

## <a name="op_eq_eq"></a>  operator==

Determina se dois objetos `duration` representam intervalos de tempo que têm o mesmo tamanho ou se dois objetos `time_point` representam o mesmo ponto no tempo.

```cpp
template <class Rep1, class Period1, class Rep2, class Period2>
constexpr bool operator==(
    const duration<Rep1, Period1>& Left,
    const duration<Rep2, Period2>& Right);

template <class Clock, class Duration1, class Duration2>
constexpr bool operator==(
    const time_point<Clock, Duration1>& Left,
    const time_point<Clock, Duration2>& Right);
```

### <a name="parameters"></a>Parâmetros

`Left` À esquerda `duration` ou `time_point` objeto.

`Right` O direito de `duration` ou `time_point` objeto.

### <a name="return-value"></a>Valor de retorno

A primeira função retornará `true` se `Left` e `Right` representarem intervalos de tempo de mesmo tamanho. Caso contrário, a função retorna `false`.

A segunda função retornará `true` se `Left` e `Right` representarem o mesmo ponto no tempo. Caso contrário, a função retorna `false`.

## <a name="op_gt"></a>  operator&gt;

Determina se um objeto [duration](../standard-library/duration-class.md) ou [time_point](../standard-library/time-point-class.md) é maior que outro objeto `duration` ou `time_point`.

```cpp
template <class Rep1, class Period1, class Rep2, class Period2>
constexpr bool operator>(
    const duration<Rep1, Period1>& Left,
    const duration<Rep2, Period2>& Right);

template <class Clock, class Duration1, class Duration2>
constexpr bool operator>(
    const time_point<Clock, Duration1>& Left,
    const time_point<Clock, Duration2>& Right);
```

### <a name="parameters"></a>Parâmetros

`Left` À esquerda `duration` ou `time_point` objeto.

`Right` O direito de `duration` ou `time_point` objeto.

### <a name="return-value"></a>Valor de retorno

Cada função retorna `Right < Left`.

## <a name="op_gt_eq"></a>  operator&gt;=

Determina se um objeto [duration](../standard-library/duration-class.md) ou [time_point](../standard-library/time-point-class.md) é maior ou igual a outro objeto `duration` ou `time_point`.

```cpp
template <class Rep1, class Period1, class Rep2, class Period2>
constexpr bool operator>=(
    const duration<Rep1, Period1>& Left,
    const duration<Rep2, Period2>& Right);

template <class Clock, class Duration1, class Duration2>
constexpr bool operator>=(
    const time_point<Clock, Duration1>& Left,
    const time_point<Clock, Duration2>& Right);
```

### <a name="parameters"></a>Parâmetros

`Left` À esquerda `duration` ou `time_point` objeto.

`Right` O direito de `duration` ou `time_point` objeto.

### <a name="return-value"></a>Valor de retorno

Cada função retorna `!(Left < Right)`.

## <a name="op_modulo"></a>  operator modulo

Operador para operações de módulo em objetos [duration](../standard-library/duration-class.md).

```cpp
template <class Rep1, class Period1, class Rep2>
constexpr duration<Rep1, Period1, Rep2>::type
   operator%(
      const duration<Rep1, Period1>& Dur,
      const Rep2& Div);

template <class Rep1, class Period1, class Rep2, class Period2>
constexpr typename common_type<duration<Rep1, _Period1>, duration<Rep2, Period2>>::type
   operator%(
     const duration<Rep1, Period1>& Left,
     const duration<Rep2, Period2>& Right);
```

### <a name="parameters"></a>Parâmetros

`Dur` Um `duration` objeto.

`Div` Um valor inteiro.

`Left` À esquerda `duration` objeto.

`Right` Direita `duration` objeto.

### <a name="return-value"></a>Valor de retorno

A primeira função retorna um objeto `duration` cujo tamanho de intervalo é `Dur` módulo `Div`.

A segunda função retorna um valor que representa `Left` módulo `Right`.

## <a name="see-also"></a>Consulte também

[\<chrono>](../standard-library/chrono.md)<br/>
