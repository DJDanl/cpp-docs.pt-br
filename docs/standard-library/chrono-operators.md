---
title: Operadores &lt;chrono&gt;
ms.date: 11/04/2016
f1_keywords:
- chrono/std::operator modulo
ms.assetid: c5a19267-4684-40c1-b7a9-cc1012b058f3
ms.openlocfilehash: 82f0b7b0f55cf4d71ef7c0ed92a55ca0fa1139e0
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230137"
---
# <a name="ltchronogt-operators"></a>Operadores &lt;chrono&gt;

## <a name="operator-"></a><a name="operator-"></a>operador

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

### <a name="parameters"></a>parâmetros

*Mantida*\
O objeto `duration` ou `time_point` à esquerda.

*Certo*\
O objeto `duration` ou `time_point` à direita.

*Momento*\
Um objeto `time_point`.

*Duração*\
Um objeto `duration`.

### <a name="return-value"></a>Valor retornado

A primeira função retorna um objeto `duration` cujo comprimento do intervalo é a diferença entre os intervalos de tempo dos dois argumentos.

A segunda função retorna um `time_point` objeto que representa um ponto no tempo que é inserido, pela negação do intervalo de tempo que é representado por *dur*, a partir do ponto no tempo especificado por *tempo*.

A terceira função retorna um `duration` objeto que representa o intervalo de tempo entre a *esquerda* e a *direita*.

## <a name="operator"></a><a name="op_neq"></a>operador! =

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

### <a name="parameters"></a>parâmetros

*Mantida*\
O objeto `duration` ou `time_point` à esquerda.

*Certo*\
O objeto `duration` ou `time_point` à direita.

### <a name="return-value"></a>Valor retornado

Cada função retorna `!(Left == Right)`.

## <a name="operator"></a><a name="op_star"></a>operador

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

### <a name="parameters"></a>parâmetros

*Duração*\
Um objeto `duration`.

*Mult*\
Um valor integral.

### <a name="return-value"></a>Valor retornado

Cada função retorna um `duration` objeto cujo comprimento de intervalo é *mult* multiplicado pelo comprimento de *dur*.

A menos que `is_convertible<Rep2, common_type<Rep1, Rep2>>`*seja verdadeiro*, a primeira função não participará da resolução de sobrecarga. Para obter mais informações, consulte [<type_traits>](../standard-library/type-traits.md).

A menos que `is_convertible<Rep1, common_type<Rep1, Rep2>>`*seja verdadeiro*, a segunda função não participará da resolução de sobrecarga. Para obter mais informações, consulte [<type_traits>](../standard-library/type-traits.md).

## <a name="operator"></a><a name="op_div"></a>operador

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

### <a name="parameters"></a>parâmetros

*Duração*\
Um objeto `duration`.

*Marca*\
Um valor integral.

*Mantida*\
O objeto `duration` à esquerda.

*Certo*\
O objeto `duration` à direita.

### <a name="return-value"></a>Valor retornado

O primeiro operador retorna um objeto Duration cujo comprimento de intervalo é o comprimento de *dur* dividido pelo valor *div*.

O segundo operador retorna a proporção dos comprimentos de intervalo da *esquerda* e da *direita*.

A menos que `is_convertible<Rep2, common_type<Rep1, Rep2>>`*seja verdadeiro* e `Rep2` não seja uma instanciação de `duration`, o primeiro operador não participará da resolução de sobrecarga. Para obter mais informações, consulte [<type_traits>](../standard-library/type-traits.md).

## <a name="operator"></a><a name="op_add"></a>operador +

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

### <a name="parameters"></a>parâmetros

*Mantida*\
O objeto `duration` ou `time_point` à esquerda.

*Certo*\
O objeto `duration` ou `time_point` à direita.

*Momento*\
Um objeto `time_point`.

*Duração*\
Um objeto `duration`.

### <a name="return-value"></a>Valor retornado

A primeira função retorna um `duration` objeto que tem um intervalo de tempo igual à soma dos intervalos da *esquerda* e da *direita*.

A segunda e terceira funções retornam um `time_point` objeto que representa um ponto no tempo que é inserido, pela *dur*de intervalo, do ponto no *tempo*.

## <a name="operatorlt"></a><a name="op_lt"></a>operador&lt;

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

### <a name="parameters"></a>parâmetros

*Mantida*\
O objeto `duration` ou `time_point` à esquerda.

*Certo*\
O objeto `duration` ou `time_point` à direita.

### <a name="return-value"></a>Valor retornado

A primeira função retorna **`true`** se o comprimento do intervalo da *esquerda* for menor que o comprimento do intervalo *à direita*. Caso contrário, a função retornará **`false`** .

A segunda função retorna **`true`** se a *esquerda* precede a *direita*. Caso contrário, a função retornará **`false`** .

## <a name="operatorlt"></a><a name="op_lt_eq"></a>operador&lt;=

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

### <a name="parameters"></a>parâmetros

*Mantida*\
O objeto `duration` ou `time_point` à esquerda.

*Certo*\
O objeto `duration` ou `time_point` à direita.

### <a name="return-value"></a>Valor retornado

Cada função retorna `!(Right < Left)`.

## <a name="operator"></a><a name="op_eq_eq"></a>operador = =

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

### <a name="parameters"></a>parâmetros

*Mantida*\
O objeto `duration` ou `time_point` à esquerda.

*Certo*\
O objeto `duration` ou `time_point` à direita.

### <a name="return-value"></a>Valor retornado

A primeira função retorna **`true`** se a *esquerda* e a *direita* representam intervalos de tempo que têm o mesmo comprimento. Caso contrário, a função retornará **`false`** .

A segunda função retorna **`true`** se a *esquerda* e a *direita* representam o mesmo ponto no tempo. Caso contrário, a função retornará **`false`** .

## <a name="operatorgt"></a><a name="op_gt"></a>operador&gt;

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

### <a name="parameters"></a>parâmetros

*Mantida*\
O objeto `duration` ou `time_point` à esquerda.

*Certo*\
O objeto `duration` ou `time_point` à direita.

### <a name="return-value"></a>Valor retornado

Cada função retorna `Right < Left`.

## <a name="operatorgt"></a><a name="op_gt_eq"></a>operador&gt;=

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

### <a name="parameters"></a>parâmetros

*Mantida*\
O objeto `duration` ou `time_point` à esquerda.

*Certo*\
O objeto `duration` ou `time_point` à direita.

### <a name="return-value"></a>Valor retornado

Cada função retorna `!(Left < Right)`.

## <a name="operator-modulo"></a><a name="op_modulo"></a>módulo do operador

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

### <a name="parameters"></a>parâmetros

*Duração*\
Um objeto `duration`.

*Marca*\
Um valor integral.

*Mantida*\
O objeto `duration` à esquerda.

*Certo*\
O objeto `duration` à direita.

### <a name="return-value"></a>Valor retornado

A primeira função retorna um `duration` objeto cujo comprimento de intervalo é a *div*do módulo *dur* .

A segunda função retorna um valor que representa o módulo *do* *lado esquerdo* direito.
