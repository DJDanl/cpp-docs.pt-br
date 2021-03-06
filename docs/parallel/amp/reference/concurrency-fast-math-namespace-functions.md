---
title: Funções do namespace Concurrency::fast_math
ms.date: 11/04/2016
f1_keywords:
- amp_math/Concurrency::fast_math::acos
- amp_math/Concurrency::fast_math::asin
- amp_math/Concurrency::fast_math::asinf
- amp_math/Concurrency::fast_math::atan2
- amp_math/Concurrency::fast_math::atan2f
- amp_math/Concurrency::fast_math::ceil
- amp_math/Concurrency::fast_math::ceilf
- amp_math/Concurrency::fast_math::cosf
- amp_math/Concurrency::fast_math::cosh
- amp_math/Concurrency::fast_math::exp
- amp_math/Concurrency::fast_math::exp2
- amp_math/Concurrency::fast_math::expf
- amp_math/Concurrency::fast_math::fabs
- amp_math/Concurrency::fast_math::floor
- amp_math/Concurrency::fast_math::floorf
- amp_math/Concurrency::fast_math::fmaxf
- amp_math/Concurrency::fast_math::fmin
- amp_math/Concurrency::fast_math::fmod
- amp_math/Concurrency::fast_math::fmodf
- amp_math/Concurrency::fast_math::frexpf
- amp_math/Concurrency::fast_math::isfinite
- amp_math/Concurrency::fast_math::isnan
- amp_math/Concurrency::fast_math::ldexp
- amp_math/Concurrency::fast_math::log
- amp_math/Concurrency::fast_math::log10
- amp_math/Concurrency::fast_math::log2
- amp_math/Concurrency::fast_math::log2f
- amp_math/Concurrency::fast_math::modf
- amp_math/Concurrency::fast_math::modff
- amp_math/Concurrency::fast_math::powf
- amp_math/Concurrency::fast_math::round
- amp_math/Concurrency::fast_math::rsqrt
- amp_math/Concurrency::fast_math::rsqrtf
- amp_math/Concurrency::fast_math::signbitf
- amp_math/Concurrency::fast_math::sin
- amp_math/Concurrency::fast_math::sincosf
- amp_math/Concurrency::fast_math::sinf
- amp_math/Concurrency::fast_math::sinhf
- amp_math/Concurrency::fast_math::sqrt
- amp_math/Concurrency::fast_math::tan
- amp_math/Concurrency::fast_math::tanf
- amp_math/Concurrency::fast_math::tanhf
- amp_math/Concurrency::fast_math::trunc
ms.assetid: f5763d62-795b-4de6-a7a5-c7115f158708
ms.openlocfilehash: ff919016449723ad67e029a249ec222ccf1fe6a4
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88831054"
---
# <a name="concurrencyfast_math-namespace-functions"></a>Funções do namespace Concurrency::fast_math

:::row:::
   :::column span="":::
      [`acos`](#acos)\
      [`acosf`](#acosf)\
      [`asin`](#asin)\
      [`asinf`](#asinf)\
      [`atan`](#atan)\
      [`atan2`](#atan2)\
      [`atan2f`](#atan2f)\
      [`atanf`](#atanf)\
      [`ceil`](#ceil)\
      [`ceilf`](#ceilf)\
      [`cos`](#cos)\
      [`cosf`](#cosf)\
      [`cosh`](#cosh)\
      [`coshf`](#coshf)\
      [`exp`](#exp)\
      [`exp2`](#exp2)\
      [`exp2f`](#exp2f)
   :::column-end:::
   :::column span="":::
      [`expf`](#expf)\
      [`fabs`](#fabs)\
      [`fabsf`](#fabsf)\
      [`floor`](#floor)\
      [`floorf`](#floorf)\
      [`fmax`](#fmax)\
      [`fmaxf`](#fmaxf)\
      [`fmin`](#fmin)\
      [`fminf`](#fminf)\
      [`fmod`](#fmod)\
      [`fmodf`](#fmodf)\
      [`frexp`](#frexp)\
      [`frexpf`](#frexpf)\
      [`isfinite`](#isfinite)\
      [`isinf`](#isinf)\
      [`isnan`](#isnan)
   :::column-end:::
   :::column span="":::
      [`ldexp`](#ldexp)\
      [`ldexpf`](#ldexpf)\
      [`log`](#log)\
      [`log10`](#log10)\
      [`log10f`](#log10f)\
      [`log2`](#log2)\
      [`log2f`](#log2f)\
      [`logf`](#logf)\
      [`modf`](#modf)\
      [`modff`](#modff)\
      [`pow`](#pow)\
      [`powf`](#powf)\
      [`round`](#round)\
      [`roundf`](#roundf)\
      [`rsqrt`](#rsqrt)\
      [`rsqrtf`](#rsqrtf)
   :::column-end:::
   :::column span="":::
      [`signbit`](#signbit)\
      [`signbitf`](#signbitf)\
      [`sin`](#sin)\
      [`sincos`](#sincos)\
      [`sincosf`](#sincosf)\
      [`sinf`](#sinf)\
      [`sinh`](#sinh)\
      [`sinhf`](#sinhf)\
      [`sqrt`](#sqrt)\
      [`sqrtf`](#sqrtf)\
      [`tan`](#tan)\
      [`tanf`](#tanf)\
      [`tanh`](#tanh)\
      [`tanhf`](#tanhf)\
      [`trunc`](#trunc)\
      [`truncf`](#truncf)
   :::column-end:::
:::row-end:::

## <a name="acos"></a><a name="acos"></a> acos

Calcula o arco cosseno do argumento

```cpp
inline float acos(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o valor do arco cosseno do argumento

## <a name="acosf"></a><a name="acosf"></a> acosf

Calcula o arco cosseno do argumento

```cpp
inline float acosf(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o valor do arco cosseno do argumento

## <a name="asin"></a><a name="asin"></a> ASIN

Calcula o arco seno do argumento

```cpp
inline float asin(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o valor do arco seno do argumento

## <a name="asinf"></a><a name="asinf"></a> asinf

Calcula o arco seno do argumento

```cpp
inline float asinf(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o valor do arco seno do argumento

## <a name="atan"></a><a name="atan"></a> ATAN

Calcula o tangente do arco do argumento

```cpp
inline float atan(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o valor do arco tangente do argumento

## <a name="atan2"></a><a name="atan2"></a> atan2

Calcula o arco tangente de _Y/_X

```cpp
inline float atan2(
    float _Y,
    float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_Y*<br/>
Valor de ponto flutuante

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o valor do arco tangente de _Y/_X

## <a name="atan2f"></a><a name="atan2f"></a> atan2f

Calcula o arco tangente de _Y/_X

```cpp
inline float atan2f(
    float _Y,
    float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_Y*<br/>
Valor de ponto flutuante

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o valor do arco tangente de _Y/_X

## <a name="atanf"></a><a name="atanf"></a> atanf

Calcula o tangente do arco do argumento

```cpp
inline float atanf(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o valor do arco tangente do argumento

## <a name="ceil"></a><a name="ceil"></a> ceil

Calcula o teto do argumento

```cpp
inline float ceil(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o teto do argumento

## <a name="ceilf"></a><a name="ceilf"></a> ceilf

Calcula o teto do argumento

```cpp
inline float ceilf(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o teto do argumento

## <a name="cosf"></a><a name="cosf"></a> cosf

Calcula o cosseno do argumento

```cpp
inline float cosf(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o valor cosseno do argumento

## <a name="coshf"></a><a name="coshf"></a> coshf

Calcula o valor cosseno hiperbólico do argumento

```cpp
inline float coshf(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o valor cosseno hiperbólico do argumento

## <a name="cos"></a><a name="cos"></a> exibi

Calcula o cosseno do argumento

```cpp
inline float cos(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o valor cosseno do argumento

## <a name="cosh"></a><a name="cosh"></a> cosh

Calcula o valor cosseno hiperbólico do argumento

```cpp
inline float cosh(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o valor cosseno hiperbólico do argumento

## <a name="exp"></a><a name="exp"></a> exp

Calcula o exponencial de base e do argumento

```cpp
inline float exp(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o exponencial de base e do argumento

## <a name="exp2"></a><a name="exp2"></a> exp2

Calcula o exponencial de base 2 do argumento

```cpp
inline float exp2(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o exponencial 2 base do argumento

## <a name="exp2f"></a><a name="exp2f"></a> exp2f

Calcula o exponencial de base 2 do argumento

```cpp
inline float exp2f(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o exponencial 2 base do argumento

## <a name="expf"></a><a name="expf"></a> expf

Calcula o exponencial de base e do argumento

```cpp
inline float expf(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o exponencial de base e do argumento

## <a name="fabs"></a><a name="fabs"></a> fabs

Retorna o valor absoluto do argumento

```cpp
inline float fabs(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor inteiro

### <a name="return-value"></a>Valor Retornado

Retorna o valor absoluto do argumento

## <a name="fabsf"></a><a name="fabsf"></a> fabsf

Retorna o valor absoluto do argumento

```cpp
inline float fabsf(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o valor absoluto do argumento

## <a name="floor"></a><a name="floor"></a> Floor

Calcula o piso do argumento

```cpp
inline float floor(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o piso do argumento

## <a name="floorf"></a><a name="floorf"></a> floorf

Calcula o piso do argumento

```cpp
inline float floorf(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o piso do argumento

## <a name="fmax"></a><a name="fmax"></a> fmax

Determinar o valor numérico máximo dos argumentos

```cpp
inline float max(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor inteiro

*_Y*<br/>
Valor inteiro

### <a name="return-value"></a>Valor Retornado

Retornar o valor numérico máximo dos argumentos

## <a name="fmaxf"></a><a name="fmaxf"></a> fmaxf

Determinar o valor numérico máximo dos argumentos

```cpp
inline float fmaxf(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retornar o valor numérico máximo dos argumentos

## <a name="fmin"></a><a name="fmin"></a> fmin

Determinar o valor numérico mínimo dos argumentos

```cpp
inline float min(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor inteiro

*_Y*<br/>
Valor inteiro

### <a name="return-value"></a>Valor Retornado

Retornar o valor numérico mínimo dos argumentos

## <a name="fminf"></a><a name="fminf"></a> fminf

Determinar o valor numérico mínimo dos argumentos

```cpp
inline float fminf(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retornar o valor numérico mínimo dos argumentos

## <a name="fmod"></a><a name="fmod"></a> fmod

Calcula o restante de ponto flutuante de _X/_Y

```cpp
inline float fmod(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o restante de ponto flutuante de _X/_Y

## <a name="fmodf"></a><a name="fmodf"></a> fmodf

Calcula o restante de ponto flutuante de _X/_Y.

```cpp
inline float fmodf(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o restante de ponto flutuante de _X/_Y

## <a name="frexp"></a><a name="frexp"></a> frexp

Obtém o mantissa e o expoente de _X

```cpp
inline float frexp(
    float _X,
    _Out_ int* _Exp) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Exp*<br/>
Retorna o expoente inteiro de _X no valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o _X mantissa

## <a name="frexpf"></a><a name="frexpf"></a> frexpf

Obtém o mantissa e o expoente de _X

```cpp
inline float frexpf(
    float _X,
    _Out_ int* _Exp) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Exp*<br/>
Retorna o expoente inteiro de _X no valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o _X mantissa

## <a name="isfinite"></a><a name="isfinite"></a> isfinito

Determina se o argumento tem um valor finito

```cpp
inline int isfinite(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna um valor diferente de zero se e somente se o argumento tiver um valor finito

## <a name="isinf"></a><a name="isinf"></a> isinf

Determina se o argumento é um infinito

```cpp
inline int isinf(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna um valor diferente de zero se e somente se o argumento tiver um valor infinito

## <a name="isnan"></a><a name="isnan"></a> IsNaN

Determina se o argumento é um NaN

```cpp
inline int isnan(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna um valor diferente de zero se e somente se o argumento tiver um valor NaN

## <a name="ldexp"></a><a name="ldexp"></a> ldexp

Computa um número real do mantissa e do expoente

```cpp
inline float ldexp(
    float _X,
    int _Exp) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante, mentissa

*_Exp*<br/>
Expoente de inteiro

### <a name="return-value"></a>Valor Retornado

Retorna _X \* 2 ^ _Exp

## <a name="ldexpf"></a><a name="ldexpf"></a> ldexpf

Computa um número real do mantissa e do expoente

```cpp
inline float ldexpf(
    float _X,
    int _Exp) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante, mentissa

*_Exp*<br/>
Expoente de inteiro

### <a name="return-value"></a>Valor Retornado

Retorna _X \* 2 ^ _Exp

## <a name="log"></a><a name="log"></a> Façam

Calcula o logaritmo de base-e do argumento

```cpp
inline float log(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o logaritmo de base-e do argumento

## <a name="log10"></a><a name="log10"></a> log10

Calcula o logaritmo de base 10 do argumento

```cpp
inline float log10(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o logaritmo de base 10 do argumento

## <a name="log10f"></a><a name="log10f"></a> log10f

Calcula o logaritmo de base 10 do argumento

```cpp
inline float log10f(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o logaritmo de base 10 do argumento

## <a name="log2"></a><a name="log2"></a> log2

Calcula o logaritmo de base 2 do argumento

```cpp
inline float log2(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o logaritmo de base 2 do argumento

## <a name="log2f"></a><a name="log2f"></a> log2f

Calcula o logaritmo de base 2 do argumento

```cpp
inline float log2f(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o logaritmo de base 10 do argumento

## <a name="logf"></a><a name="logf"></a> logf

Calcula o logaritmo de base-e do argumento

```cpp
inline float logf(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o logaritmo de base-e do argumento

## <a name="modf"></a><a name="modf"></a> modf

Divide _X em partes fracionárias e de inteiros.

```cpp
inline float modf(
    float _X,
    float* _Ip) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Ip*<br/>
Recebe a parte inteira do valor

### <a name="return-value"></a>Valor Retornado

Retorna a parte fracionária assinada do _X

## <a name="modff"></a><a name="modff"></a> modff

Divide _X em partes fracionárias e de inteiros.

```cpp
inline float modff(
    float _X,
    float* _Ip) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Ip*<br/>
Recebe a parte inteira do valor

### <a name="return-value"></a>Valor Retornado

Retorna a parte fracionária assinada do _X

## <a name="pow"></a><a name="pow"></a> pow

Calcula _X elevado à potência de _Y

```cpp
inline float pow(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante, base

*_Y*<br/>
Valor de ponto flutuante, expoente

### <a name="return-value"></a>Valor Retornado

Retorna o valor de _X elevado à potência de _Y

## <a name="powf"></a><a name="powf"></a> powf

Calcula _X elevado à potência de _Y

```cpp
inline float powf(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante, base

*_Y*<br/>
Valor de ponto flutuante, expoente

### <a name="return-value"></a>Valor Retornado

## <a name="round"></a><a name="round"></a> idas

Arredonda _X para o número inteiro mais próximo

```cpp
inline float round(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o número inteiro mais próximo de _X

## <a name="roundf"></a><a name="roundf"></a> roundf

Arredonda _X para o número inteiro mais próximo

```cpp
inline float roundf(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o número inteiro mais próximo de _X

## <a name="rsqrt"></a><a name="rsqrt"></a> rsqrt

Retorna o recíproco da raiz quadrada do argumento

```cpp
inline float rsqrt(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o recíproco da raiz quadrada do argumento

## <a name="rsqrtf"></a><a name="rsqrtf"></a> rsqrtf

Retorna o recíproco da raiz quadrada do argumento

```cpp
inline float rsqrtf(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o recíproco da raiz quadrada do argumento

## <a name="signbit"></a><a name="signbit"></a> signbit

Determina se o sinal de _X é negativo

```cpp
inline int signbit(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna um valor diferente de zero se e somente se o sinal de _X for negativo

## <a name="signbitf"></a><a name="signbitf"></a> signbitf

Determina se o sinal de _X é negativo

```cpp
inline int signbitf(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna um valor diferente de zero se e somente se o sinal de _X for negativo

## <a name="sin"></a><a name="sin"></a> Sin

Calcula o valor do seno do argumento

```cpp
inline float sin(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o valor do seno do argumento

## <a name="sinf"></a><a name="sinf"></a> sinf

Calcula o valor do seno do argumento

```cpp
inline float sinf(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o valor do seno do argumento

## <a name="sincos"></a><a name="sincos"></a> sincos

Calcula o valor do seno e do cosseno de _X

```cpp
inline void sincos(
    float _X,
    float* _S,
    float* _C) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

*_S*<br/>
Retorna o valor do seno de _X

*_C*<br/>
Retorna o valor do cosseno de _X

## <a name="sincosf"></a><a name="sincosf"></a> sincosf

Calcula o valor do seno e do cosseno de _X

```cpp
inline void sincosf(
    float _X,
    float* _S,
    float* _C) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

*_S*<br/>
Retorna o valor do seno de _X

*_C*<br/>
Retorna o valor do cosseno de _X

## <a name="sinh"></a><a name="sinh"></a> sinh

Calcula o valor seno hiperbólico do argumento

```cpp
inline float sinh(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o valor seno hiperbólico do argumento

## <a name="sinhf"></a><a name="sinhf"></a> sinhf

Calcula o valor seno hiperbólico do argumento

```cpp
inline float sinhf(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o valor seno hiperbólico do argumento

## <a name="sqrt"></a><a name="sqrt"></a> sqrt

Calcula a raiz squre do argumento

```cpp
inline float sqrt(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna a raiz squre do argumento

## <a name="sqrtf"></a><a name="sqrtf"></a> sqrtf

Calcula a raiz squre do argumento

```cpp
inline float sqrtf(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna a raiz squre do argumento

## <a name="tan"></a><a name="tan"></a> queimado

Calcula o valor da tangente do argumento

```cpp
inline float tan(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o valor da tangente do argumento

## <a name="tanf"></a><a name="tanf"></a> tanf

Calcula o valor da tangente do argumento

```cpp
inline float tanf(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o valor da tangente do argumento

## <a name="tanh"></a><a name="tanh"></a> Tanh

Calcula o valor tangente hiperbólico do argumento

```cpp
inline float tanh(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o valor tangente hiperbólico do argumento

## <a name="tanhf"></a><a name="tanhf"></a> tanhf

Calcula o valor tangente hiperbólico do argumento

```cpp
inline float tanhf(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o valor tangente hiperbólico do argumento

## <a name="trunc"></a><a name="trunc"></a> trunc

Trunca o argumento para o componente de inteiro

```cpp
inline float trunc(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o componente de inteiro do argumento

## <a name="truncf"></a><a name="truncf"></a> truncf

Trunca o argumento para o componente de inteiro

```cpp
inline float truncf(float _X) restrict(amp);
```

### <a name="parameters"></a>parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor Retornado

Retorna o componente de inteiro do argumento

## <a name="requirements"></a>Requisitos

**Cabeçalho:** namespace amp_math. h **:** Concurrency:: fast_math

## <a name="see-also"></a>Confira também

[Namespace Concurrency::fast_math](concurrency-fast-math-namespace.md)
