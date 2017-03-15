---
title: Operadores &lt;chrono&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: c5a19267-4684-40c1-b7a9-cc1012b058f3
caps.latest.revision: 8
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: c2ea4241ef1db4989caf8cdc6a16044d9c9381f6
ms.lasthandoff: 02/25/2017

---
# <a name="ltchronogt-operators"></a>Operadores &lt;chrono&gt;
||||  
|-|-|-|  
|[módulo do operador](#operator_modulo)|[operator!=](#operator_neq)|[operator&gt;](#operator_gt_)|  
|[operator&gt;=](#operator_gt__eq)|[operator&lt;](#operator_lt_)|[operator&lt;=](#operator_lt__eq)|  
|[operator*](#operator_star)|[operator+](#operator_add)|[operator-](#operator-)|  
|[operator/](#operator_)|[operator==](#operator_eq_eq)|  
  
##  <a name="a-nameoperator-a--operator-"></a><a name="operator-"></a>  operator-  
 Operador para subtração ou negação de objetos [duration](../standard-library/duration-class.md) e [time_point](../standard-library/time-point-class.md).  
  
```  
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
 `Left`  
 O objeto `duration` ou `time_point` à esquerda.  
  
 `Right`  
 O objeto `duration` ou `time_point` à direita.  
  
 `Time`  
 Um objeto `time_point`.  
  
 `Dur`  
 Um objeto `duration`.  
  
### <a name="return-value"></a>Valor retornado  
 A primeira função retorna um objeto `duration` cujo comprimento do intervalo é a diferença entre os intervalos de tempo dos dois argumentos.  
  
 A segunda função retorna um objeto `time_point` que representa um ponto no tempo que é deslocado, pela negação do intervalo de tempo representado por `Dur`, do ponto no tempo especificado por `Time`.  
  
 A terceira função retorna um objeto `duration` que representa o intervalo de tempo entre `Left` e `Right`.  
  
##  <a name="a-nameoperatorneqa--operator"></a><a name="operator_neq"></a>  operator!=  
 Operador de desigualdade para objetos [duration](../standard-library/duration-class.md) ou [time_point](../standard-library/time-point-class.md).  
  
```  
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
 `Left`  
 O objeto `duration` ou `time_point` à esquerda.  
  
 `Right`  
 O objeto `duration` ou `time_point` à direita.  
  
### <a name="return-value"></a>Valor retornado  
 Cada função retorna `!(Left == Right)`.  
  
##  <a name="a-nameoperatorstara--operator"></a><a name="operator_star"></a>  operator*  
 Operador de multiplicação para objetos [duration](../standard-library/chrono-operators.md#operator_star).  
  
```  
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
 `Dur`  
 Um objeto `duration`.  
  
 `Mult`  
 Um valor integral.  
  
### <a name="return-value"></a>Valor retornado  
 Cada função retorna um objeto `duration` cujo tamanho de intervalo é `Mult` multiplicado pelo tamanho de `Dur`.  
  
 A menos que `is_convertible<Rep2, common_type<Rep1, Rep2>>`*seja verdadeiro*, a primeira função não participará da resolução de sobrecarga. Para obter mais informações, consulte [<type_traits>](../standard-library/type-traits.md).  
  
 A menos que `is_convertible<Rep1, common_type<Rep1, Rep2>>`*seja verdadeiro*, a segunda função não participará da resolução de sobrecarga. Para obter mais informações, consulte [<type_traits>](../standard-library/type-traits.md).  
  
##  <a name="a-nameoperatora--operator"></a><a name="operator_"></a>  operator/  
 Operador de divisão para objetos [duration](../standard-library/chrono-operators.md#operator_star).  
  
```  
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
 `Dur`  
 Um objeto `duration`.  
  
 `Div`  
 Um valor integral.  
  
 `Left`  
 O objeto `duration` à esquerda.  
  
 `Right`  
 O objeto `duration` à direita.  
  
### <a name="return-value"></a>Valor retornado  
 O primeiro operador retorna um objeto duration cujo tamanho de intervalo é o tamanho de `Dur` dividido pelo valor de `Div`.  
  
 O segundo operador retorna a proporção dos tamanhos de intervalo de `Left` e `Right`.  
  
 A menos que `is_convertible<Rep2, common_type<Rep1, Rep2>>`*seja verdadeiro* e `Rep2` não seja uma instanciação de `duration`, o primeiro operador não participará da resolução de sobrecarga. Para obter mais informações, consulte [<type_traits>](../standard-library/type-traits.md).  
  
##  <a name="a-nameoperatoradda--operator"></a><a name="operator_add"></a>  operator+  
 Adiciona os objetos [duration](../standard-library/duration-class.md) e [time_point](../standard-library/time-point-class.md).  
  
```  
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
 `Left`  
 O objeto `duration` ou `time_point` à esquerda.  
  
 `Right`  
 O objeto `duration` ou `time_point` à direita.  
  
 `Time`  
 Um objeto `time_point`.  
  
 `Dur`  
 Um objeto `duration`.  
  
### <a name="return-value"></a>Valor retornado  
 A primeira função retorna um objeto `duration` que tem um intervalo de tempo igual à soma dos intervalos de `Left` e `Right`.  
  
 A segunda e a terceira funções retornam um objeto `time_point` que representa um ponto no tempo deslocado, pelo intervalo `Dur`, do ponto no tempo `Time`.  
  
##  <a name="a-nameoperatorlta--operatorlt"></a><a name="operator_lt_"></a>  operator&lt;  
 Determina se um objeto [duration](../standard-library/duration-class.md) ou [time_point](../standard-library/time-point-class.md) é menor que outro objeto `duration` ou `time_point`.  
  
```  
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
 `Left`  
 O objeto `duration` ou `time_point` à esquerda.  
  
 `Right`  
 O objeto `duration` ou `time_point` à direita.  
  
### <a name="return-value"></a>Valor retornado  
 A primeira função retornará `true` se o tamanho do intervalo de `Left` for menor que o tamanho do intervalo de `Right`. Caso contrário, a função retorna `false`.  
  
 A segunda função retornará `true` se `Left` preceder `Right`. Caso contrário, a função retorna `false`.  
  
##  <a name="a-nameoperatorlteqa--operatorlt"></a><a name="operator_lt__eq"></a>  operator&lt;=  
 Determina se um objeto [duration](../standard-library/duration-class.md) ou [time_point](../standard-library/time-point-class.md) é menor ou igual a outro objeto `duration` ou `time_point`.  
  
```  
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
 `Left`  
 O objeto `duration` ou `time_point` à esquerda.  
  
 `Right`  
 O objeto `duration` ou `time_point` à direita.  
  
### <a name="return-value"></a>Valor retornado  
 Cada função retorna `!(Right < Left)`.  
  
##  <a name="a-nameoperatoreqeqa--operator"></a><a name="operator_eq_eq"></a>  operator==  
 Determina se dois objetos `duration` representam intervalos de tempo que têm o mesmo tamanho ou se dois objetos `time_point` representam o mesmo ponto no tempo.  
  
```  
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
 `Left`  
 O objeto `duration` ou `time_point` à esquerda.  
  
 `Right`  
 O objeto `duration` ou `time_point` à direita.  
  
### <a name="return-value"></a>Valor retornado  
 A primeira função retornará `true` se `Left` e `Right` representarem intervalos de tempo de mesmo tamanho. Caso contrário, a função retorna `false`.  
  
 A segunda função retornará `true` se `Left` e `Right` representarem o mesmo ponto no tempo. Caso contrário, a função retorna `false`.  
  
##  <a name="a-nameoperatorgta--operatorgt"></a><a name="operator_gt_"></a>  operator&gt;  
 Determina se um objeto [duration](../standard-library/duration-class.md) ou [time_point](../standard-library/time-point-class.md) é maior que outro objeto `duration` ou `time_point`.  
  
```  
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
 `Left`  
 O objeto `duration` ou `time_point` à esquerda.  
  
 `Right`  
 O objeto `duration` ou `time_point` à direita.  
  
### <a name="return-value"></a>Valor retornado  
 Cada função retorna `Right < Left`.  
  
##  <a name="a-nameoperatorgteqa--operatorgt"></a><a name="operator_gt__eq"></a>  operator&gt;=  
 Determina se um objeto [duration](../standard-library/duration-class.md) ou [time_point](../standard-library/time-point-class.md) é maior ou igual a outro objeto `duration` ou `time_point`.  
  
```  
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
 `Left`  
 O objeto `duration` ou `time_point` à esquerda.  
  
 `Right`  
 O objeto `duration` ou `time_point` à direita.  
  
### <a name="return-value"></a>Valor retornado  
 Cada função retorna `!(Left < Right)`.  
  
##  <a name="a-nameoperatormoduloa--operator-modulo"></a><a name="operator_modulo"></a>  operator modulo  
 Operador para operações de módulo em objetos [duration](../standard-library/duration-class.md).  
  
```  
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
 `Dur`  
 Um objeto `duration`.  
  
 `Div`  
 Um valor integral.  
  
 `Left`  
 O objeto `duration` à esquerda.  
  
 `Right`  
 O objeto `duration` à direita.  
  
### <a name="return-value"></a>Valor retornado  
 A primeira função retorna um objeto `duration` cujo tamanho de intervalo é `Dur` módulo `Div`.  
  
 A segunda função retorna um valor que representa `Left` módulo `Right`.  
  
## <a name="see-also"></a>Consulte também  
 [\<chrono>](../standard-library/chrono.md)


