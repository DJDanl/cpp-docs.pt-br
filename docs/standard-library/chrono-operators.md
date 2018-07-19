---
title: Operadores &lt;chrono&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- chrono/std::operator modulo
ms.assetid: c5a19267-4684-40c1-b7a9-cc1012b058f3
ms.openlocfilehash: 786713f37bc8470dd5c455eae49eb4faed72b781
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38957395"
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

*Esquerda* à esquerda `duration` ou `time_point` objeto.

*À direita* direita `duration` ou `time_point` objeto.

*Tempo* um `time_point` objeto.

*Dur* um `duration` objeto.

### <a name="return-value"></a>Valor de retorno

A primeira função retorna um objeto `duration` cujo comprimento do intervalo é a diferença entre os intervalos de tempo dos dois argumentos.

A segunda função retorna um `time_point` objeto que representa um ponto no tempo deslocado, pela negação do intervalo de tempo que é representado por *Dur*, do ponto no tempo especificado pelo *tempo*.

A terceira função retorna um `duration` objeto que representa o intervalo entre *esquerda* e *direita*.

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

`Right` O direito `duration` ou `time_point` objeto.

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

*Dur* um `duration` objeto.

*MULT* um valor integral.

### <a name="return-value"></a>Valor de retorno

Cada função retorna um `duration` objeto cujo tamanho de intervalo está *Mult* multiplicado pelo comprimento do *Dur*.

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

*Dur* um `duration` objeto.

*Div* um valor integral.

*Esquerda* esquerda `duration` objeto.

*À direita* direita `duration` objeto.

### <a name="return-value"></a>Valor de retorno

O primeiro operador retorna um objeto duration cujo intervalo de comprimento é o comprimento de *Dur* dividido pelo valor *Div*.

O segundo operador retorna a proporção dos tamanhos de intervalo de *esquerda* e *direita*.

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

*Esquerda* à esquerda `duration` ou `time_point` objeto.

*À direita* direita `duration` ou `time_point` objeto.

*Tempo* um `time_point` objeto.

*Dur* um `duration` objeto.

### <a name="return-value"></a>Valor de retorno

A primeira função retorna um `duration` objeto que tem um intervalo de tempo que é igual à soma dos intervalos de *esquerda* e *direita*.

A segunda e terceira funções retornam um `time_point` objeto que representa um ponto no tempo deslocado, pelo intervalo *Dur*, do ponto no tempo *tempo*.

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

*Esquerda* à esquerda `duration` ou `time_point` objeto.

*À direita* direita `duration` ou `time_point` objeto.

### <a name="return-value"></a>Valor de retorno

A primeira função retorna **verdadeira** se o tamanho do intervalo de *esquerda* é menor que o tamanho do intervalo de *direita*. Caso contrário, a função retornará **falsos**.

A segunda função retorna **verdadeira** se *esquerda* precede *direita*. Caso contrário, a função retornará **falsos**.

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

*Esquerda* à esquerda `duration` ou `time_point` objeto.

*À direita* direita `duration` ou `time_point` objeto.

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

*Esquerda* à esquerda `duration` ou `time_point` objeto.

*À direita* direita `duration` ou `time_point` objeto.

### <a name="return-value"></a>Valor de retorno

A primeira função retorna **verdadeira** se *esquerda* e *direita* representam intervalos de tempo que têm o mesmo tamanho. Caso contrário, a função retornará **falsos**.

A segunda função retorna **verdadeira** se *esquerda* e *direita* representam o mesmo ponto no tempo. Caso contrário, a função retornará **falsos**.

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

*Esquerda* à esquerda `duration` ou `time_point` objeto.

*À direita* direita `duration` ou `time_point` objeto.

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

*Esquerda* à esquerda `duration` ou `time_point` objeto.

*À direita* direita `duration` ou `time_point` objeto.

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

*Dur* um `duration` objeto.

*Div* um valor integral.

*Esquerda* esquerda `duration` objeto.

*À direita* direita `duration` objeto.

### <a name="return-value"></a>Valor de retorno

A primeira função retorna um `duration` objeto cujo tamanho de intervalo está *Dur* módulo *Div*.

A segunda função retorna um valor que representa *esquerda* módulo *direita*.

## <a name="see-also"></a>Consulte também

[\<chrono>](../standard-library/chrono.md)<br/>
