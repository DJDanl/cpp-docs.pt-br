---
title: Funções do namespace Concurrency::precise_math
ms.date: 11/04/2016
f1_keywords:
- amp_math/Concurrency::precise_math::acos
- amp_math/Concurrency::precise_math::acosh
- amp_math/Concurrency::precise_math::acoshf
- amp_math/Concurrency::precise_math::asinf
- amp_math/Concurrency::precise_math::asinh
- amp_math/Concurrency::precise_math::atan
- amp_math/Concurrency::precise_math::atan2
- amp_math/Concurrency::precise_math::atanf
- amp_math/Concurrency::precise_math::atanh
- amp_math/Concurrency::precise_math::cbrt
- amp_math/Concurrency::precise_math::cbrtf
- amp_math/Concurrency::precise_math::ceilf
- amp_math/Concurrency::precise_math::copysign
- amp_math/Concurrency::precise_math::cos
- amp_math/Concurrency::precise_math::cosf
- amp_math/Concurrency::precise_math::coshf
- amp_math/Concurrency::precise_math::cospi
- amp_math/Concurrency::precise_math::erf
- amp_math/Concurrency::precise_math::erfc
- amp_math/Concurrency::precise_math::erfcinv
- amp_math/Concurrency::precise_math::erfcinvf
- amp_math/Concurrency::precise_math::erfinv
- amp_math/Concurrency::precise_math::erfinvf
- amp_math/Concurrency::precise_math::exp10
- amp_math/Concurrency::precise_math::exp10f
- amp_math/Concurrency::precise_math::exp2f
- amp_math/Concurrency::precise_math::expf
- amp_math/Concurrency::precise_math::expm1f
- amp_math/Concurrency::precise_math::fabs
- amp_math/Concurrency::precise_math::floor
- amp_math/Concurrency::precise_math::fdim
- amp_math/Concurrency::precise_math::floorf
- amp_math/Concurrency::precise_math::fmaf
- amp_math/Concurrency::precise_math::fmaxf
- amp_math/Concurrency::precise_math::fmin
- amp_math/Concurrency::precise_math::fmod
- amp_math/Concurrency::precise_math::fmodf
- amp_math/Concurrency::precise_math::frexp
- amp_math/Concurrency::precise_math::frexpf
- amp_math/Concurrency::precise_math::hypotf
- amp_math/Concurrency::precise_math::ilogb
- amp_math/Concurrency::precise_math::isfinite
- amp_math/Concurrency::precise_math::isinf
- amp_math/Concurrency::precise_math::isnormal
- amp_math/Concurrency::precise_math::ldexp
- amp_math/Concurrency::precise_math::lgamma
- amp_math/Concurrency::precise_math::lgammaf
- amp_math/Concurrency::precise_math::log10
- amp_math/Concurrency::precise_math::log10f
- amp_math/Concurrency::precise_math::log1pf
- amp_math/Concurrency::precise_math::log2
- amp_math/Concurrency::precise_math::logb
- amp_math/Concurrency::precise_math::logbf
- amp_math/Concurrency::precise_math::modf
- amp_math/Concurrency::precise_math::modff
- amp_math/Concurrency::precise_math::nanf
- amp_math/Concurrency::precise_math::nearbyint
- amp_math/Concurrency::precise_math::nextafter
- amp_math/Concurrency::precise_math::nextafterf
- amp_math/Concurrency::precise_math::phif
- amp_math/Concurrency::precise_math::pow
- amp_math/Concurrency::precise_math::probit
- amp_math/Concurrency::precise_math::probitf
- amp_math/Concurrency::precise_math::rcbrtf
- amp_math/Concurrency::precise_math::remainder
- amp_math/Concurrency::precise_math::remquo
- amp_math/Concurrency::precise_math::remquof
- amp_math/Concurrency::precise_math::roundf
- amp_math/Concurrency::precise_math::rsqrt
- amp_math/Concurrency::precise_math::scalb
- amp_math/Concurrency::precise_math::scalbf
- amp_math/Concurrency::precise_math::scalbnf
- amp_math/Concurrency::precise_math::signbit
- amp_math/Concurrency::precise_math::sin
- amp_math/Concurrency::precise_math::sincos
- amp_math/Concurrency::precise_math::sinf
- amp_math/Concurrency::precise_math::sinh
- amp_math/Concurrency::precise_math::sinpi
- amp_math/Concurrency::precise_math::sinpif
- amp_math/Concurrency::precise_math::sqrtf
- amp_math/Concurrency::precise_math::tan
- amp_math/Concurrency::precise_math::tanh
- amp_math/Concurrency::precise_math::tanhf
- amp_math/Concurrency::precise_math::tanpif
- amp_math/Concurrency::precise_math::tgamma
- amp_math/Concurrency::precise_math::trunc
- amp_math/Concurrency::precise_math::truncf
ms.assetid: fae53ab4-d1c5-45bb-a6a0-a74258e9aea3
ms.openlocfilehash: 53ebaf8d9cc1bca53b1fe51464668d6df8e08424
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77126936"
---
# <a name="concurrencyprecise_math-namespace-functions"></a>Funções do namespace Concurrency::precise_math

||||
|-|-|-|
|[acos](#acos)|[acosf](#acosf)|[acosh](#acosh)|
|[acoshf](#acoshf)|[asin](#asin)|[asinf](#asinf)|
|[asinh](#asinh)|[asinhf](#asinhf)|[atan](#atan)|
|[atan2](#atan2)|[atan2f](#atan2f)|[atanf](#atanf)|
|[atanh](#atanh)|[atanhf](#atanhf)|[cbrt](#cbrt)|
|[cbrtf](#cbrtf)|[ceil](#ceil)|[ceilf](#ceilf)|
|[copysign](#copysign)|[copysignf](#copysignf)|[cos](#cos)|
|[cosf](#cosf)|[cosh](#cosh)|[coshf](#coshf)|
|[cospi](#cospi)|[cospif](#cospif)|[erf](#erf)|
|[erfc](#erfc)|[erfcf](#erfcf)|[erfcinv](#erfcinv)|
|[erfcinvf](#erfcinvf)|[erff](#erff)|[erfinv](#erfinv)|
|[erfinvf](#erfinvf)|[exp](#exp)|[exp10](#exp10)|
|[exp10f](#exp10f)|[exp2](#exp2)|[exp2f](#exp2f)|
|[expf](#expf)|[expm1](#expm1)|[expm1f](#expm1f)|
|[fabs](#fabs)|[fabsf](#fabsf)|[floor](#floor)|
|[fdim](#fdim)|[fdimf](#fdimf)||
|[floorf](#floorf)|[fma](#fma)|[fmaf](#fmaf)|
[fmax](#fmax)|[fmaxf](#fmaxf)||
|[fmin](#fmin)|[fminf](#fminf)|[fmod](#fmod)|
|[fmodf](#fmodf)|[fpclassify](#fpclassify)|[frexp](#frexp)|
|[frexpf](#frexpf)|[hypot](#hypot)|[hypotf](#hypotf)|
|[ilogb](#ilogb)|[ilogbf](#ilogbf)|[isfinito](#isfinite)|
|[isinf](#isinf)|[isnan](#isnan)|[isnormal](#isnormal)|
|[ldexp](#ldexp)|[ldexpf](#ldexpf)|[lgamma](#lgamma)|
|[lgammaf](#lgammaf)|[log](#log)|[log10](#log10)|
|[log10f](#log10f)|[log1p](#log1p)|[log1pf](#log1pf)|
|[log2](#log2)|[log2f](#log2f)|[logb](#logb)|
|[logbf](#logbf)|[logf](#logf)|[modf](#modf)|
|[modff](#modff)|[nan](#nan)|[nanf](#nanf)|
|[nearbyint](#nearbyint)|[nearbyintf](#nearbyintf)|[nextafter](#nextafter)|
|[nextafterf](#nextafterf)|[PI](#phi)|[phif](#phif)|
|[pow](#pow)|[powf](#powf)|[probit](#probit)|
|[probitf](#probitf)|[rcbrt](#rcbrt)|[rcbrtf](#rcbrtf)|
|[remainder](#remainder)|[remainderf](#remainderf)|[remquo](#remquo)|
|[remquof](#remquof)|[round](#round)|[roundf](#roundf)|
|[rsqrt](#rsqrt)|[rsqrtf](#rsqrtf)|[scalb](#scalb)|
|[scalbf](#scalbf)|[scalbn](#scalbn)|[scalbnf](#scalbnf)|
|[signbit](#signbit)|[signbitf](#signbitf)|[sin](#sin)|
|[sincos](#sincos)|[sincosf](#sincosf)|[sinf](#sinf)|
|[sinh](#sinh)|[sinhf](#sinhf)|[sinpi](#sinpi)|
|[sinpif](#sinpif)|[sqrt](#sqrt)|[sqrtf](#sqrtf)|
|[tan](#tan)|[tanf](#tanf)|[tanh](#tanh)|
|[tanhf](#tanhf)|[tanpi](#tanpi)|[tanpif](#tanpif)|
|[tgamma](#tgamma)|[tgammaf](#tgammaf)|[trunc](#trunc)|
|[truncf](#truncf)|

## <a name="acos"></a> acos

Calcula o arco cosseno do argumento

```cpp
inline float acos(float _X) restrict(amp);

inline double acos(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor do arco cosseno do argumento

## <a name="acosf"></a>acosf

Calcula o arco cosseno do argumento

```cpp
inline float acosf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor do arco cosseno do argumento

## <a name="acosh"></a>acosh

Calcula o cosseno hiperbólico inverso do argumento

```cpp
inline float acosh(float _X) restrict(amp);

inline double acosh(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor cosseno hiperbólico inverso do argumento

## <a name="acoshf"></a>acoshf

Calcula o cosseno hiperbólico inverso do argumento

```cpp
inline float acoshf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor cosseno hiperbólico inverso do argumento

## <a name="asin"></a> asin

Calcula o arco seno do argumento

```cpp
inline float asin(float _X) restrict(amp);

inline double asin(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor do arco seno do argumento

## <a name="asinf"></a>asinf

Calcula o arco seno do argumento

```cpp
inline float asinf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor do arco seno do argumento

## <a name="asinh"></a>asinh

Calcula o seno hiperbólico inverso do argumento

```cpp
inline float asinh(float _X) restrict(amp);

inline double asinh(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor seno hiperbólico inverso do argumento

## <a name="asinhf"></a>asinhf

Calcula o seno hiperbólico inverso do argumento

```cpp
inline float asinhf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor seno hiperbólico inverso do argumento

## <a name="atan"></a> atan

Calcula o tangente do arco do argumento

```cpp
inline float atan(float _X) restrict(amp);

inline double atan(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor do arco tangente do argumento

## <a name="atan2"></a> atan2

Calcula o arco tangente de _Y/_X

```cpp
inline float atan2(
    float _Y,
    float _X) restrict(amp);

inline double atan2(
    double _Y,
    double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Y*<br/>
Valor de ponto flutuante

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor do arco tangente de _Y/_X

## <a name="atan2f"></a>atan2f

Calcula o arco tangente de _Y/_X

```cpp
inline float atan2f(
    float _Y,
    float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Y*<br/>
Valor de ponto flutuante

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor do arco tangente de _Y/_X

## <a name="atanf"></a>atanf

Calcula o tangente do arco do argumento

```cpp
inline float atanf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor do arco tangente do argumento

## <a name="atanh"></a>atanh

Calcula a tangente hiperbólica inversa do argumento

```cpp
inline float atanh(float _X) restrict(amp);

inline double atanh(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor tangente hiperbólico inverso do argumento

## <a name="atanhf"></a>atanhf

Calcula a tangente hiperbólica inversa do argumento

```cpp
inline float atanhf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor tangente hiperbólico inverso do argumento

## <a name="cbrt"></a>cbrt

Computa a raiz do cubo real do argumento

```cpp
inline float cbrt(float _X) restrict(amp);

inline double cbrt(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna a raiz do cubo real do argumento

## <a name="cbrtf"></a>cbrtf

Computa a raiz do cubo real do argumento

```cpp
inline float cbrtf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna a raiz do cubo real do argumento

## <a name="ceil"></a>ceil

Calcula o teto do argumento

```cpp
inline float ceil(float _X) restrict(amp);

inline double ceil(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o teto do argumento

## <a name="ceilf"></a>ceilf

Calcula o teto do argumento

```cpp
inline float ceilf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o teto do argumento

## <a name="copysign"></a>copysign

Produz um valor com a magnitude de _X e o sinal de _Y

```cpp
inline float copysign(
    float _X,
    float _Y) restrict(amp);

inline double copysign(
    double _X,
    double _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna um valor com a magnitude de _X e o sinal de _Y

## <a name="copysignf"></a>copysignf

Produz um valor com a magnitude de _X e o sinal de _Y

```cpp
inline float copysignf(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna um valor com a magnitude de _X e o sinal de _Y

## <a name="cos"></a>  cos

Calcula o cosseno do argumento

```cpp
inline float cos(float _X) restrict(amp);

inline double cos(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor cosseno do argumento

## <a name="cosf"></a>cosf

Calcula o cosseno do argumento

```cpp
inline float cosf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor cosseno do argumento

## <a name="cosh"></a>  cosh

Calcula o valor cosseno hiperbólico do argumento

```cpp
inline float cosh(float _X) restrict(amp);

inline double cosh(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor cosseno hiperbólico do argumento

## <a name="coshf"></a>coshf

Calcula o valor cosseno hiperbólico do argumento

```cpp
inline float coshf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor cosseno hiperbólico do argumento

## <a name="cospi"></a>cospi

Calcula o valor do cosseno de PI \* _X

```cpp
inline float cospi(float _X) restrict(amp);

inline double cospi(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor do cosseno de PI \* _X

## <a name="cospif"></a>cospif

Calcula o valor do cosseno de PI \* _X

```cpp
inline float cospif(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor do cosseno de PI \* _X

## <a name="erf"></a>ERF

Computa a função Error de _X

```cpp
inline float erf(float _X) restrict(amp);

inline double erf(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna a função de erro de _X

## <a name="erfc"></a>ERFC

Computa a função de erro complementar do _X

```cpp
inline float erfc(float _X) restrict(amp);

inline double erfc(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna a função de erro complementar de _X

## <a name="erfcf"></a>erfcf

Computa a função de erro complementar do _X

```cpp
inline float erfcf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna a função de erro complementar de _X

## <a name="erfcinv"></a>erfcinv

Computa a função de erro complementar inverso de _X

```cpp
inline float erfcinv(float _X) restrict(amp);

inline double erfcinv(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna a função de erro complementar inverso de _X

## <a name="erfcinvf"></a>erfcinvf

Computa a função de erro complementar inverso de _X

```cpp
inline float erfcinvf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna a função de erro complementar inverso de _X

## <a name="erff"></a>erff

Computa a função Error de _X

```cpp
inline float erff(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna a função de erro de _X

## <a name="erfinv"></a>erfinv

Calcula a função de erro inverso de _X

```cpp
inline float erfinv(float _X) restrict(amp);

inline double erfinv(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna a função de erro inverso de _X

## <a name="erfinvf"></a>erfinvf

Calcula a função de erro inverso de _X

```cpp
inline float erfinvf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna a função de erro inverso de _X

## <a name="exp10"></a>exp10

Calcula o exponencial de base 10 do argumento

```cpp
inline float exp10(float _X) restrict(amp);

inline double exp10(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o exponencial de base 10 do argumento

## <a name="exp10f"></a>exp10f

Calcula o exponencial de base 10 do argumento

```cpp
inline float exp10f(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o exponencial de base 10 do argumento

## <a name="expm1"></a>expm1

Calcula a exponencial de base e do argumento, menos 1

```cpp
inline float expm1(float exponent) restrict(amp);

inline double expm1(double exponent) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*lado*<br/>
O termo exponencial *n* da expressão matemática `e`<sup>n</sup>, em que `e` é a base do logaritmo natural.

### <a name="return-value"></a>Valor retornado

Retorna a exponencial de base e do argumento, menos 1

## <a name="expm1f"></a>expm1f

Calcula a exponencial de base e do argumento, menos 1

```cpp
inline float expm1f(float exponent) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*lado*<br/>
O termo exponencial *n* da expressão matemática `e`<sup>n</sup>, em que `e` é a base do logaritmo natural.

### <a name="return-value"></a>Valor retornado

Retorna a exponencial de base e do argumento, menos 1

## <a name="exp"></a>  exp

Calcula o exponencial de base e do argumento

```cpp
inline float exp(float _X) restrict(amp);

inline double exp(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o exponencial de base e do argumento

## <a name="expf"></a>expf

Calcula o exponencial de base e do argumento

```cpp
inline float expf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o exponencial de base e do argumento

## <a name="exp2"></a>exp2

Calcula o exponencial de base 2 do argumento

```cpp
inline float exp2(float _X) restrict(amp);

inline double exp2(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o exponencial 2 base do argumento

## <a name="exp2f"></a>exp2f

Calcula o exponencial de base 2 do argumento

```cpp
inline float exp2f(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o exponencial 2 base do argumento

## <a name="fabs"></a>fabs

Retorna o valor absoluto do argumento

```cpp
inline float fabs(float _X) restrict(amp);

inline double fabs(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor absoluto do argumento

## <a name="fabsf"></a>fabsf

Retorna o valor absoluto do argumento

```cpp
inline float fabsf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor absoluto do argumento

## <a name="fdim"></a>fdim

Computa a diferença positiva entre os argumentos.

```cpp
inline float fdim(
   float _X,
   float _Y
) restrict(amp);
inline double fdim(
   double _X,
   double _Y
) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
*_Y* de valor de ponto flutuante<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

A diferença entre _X e _Y se _X for maior que _Y; caso contrário, + 0.

## <a name="fdimf"></a>fdimf

Computa a diferença positiva entre os argumentos.

```cpp
inline float fdimf(
   float _X,
   float _Y
) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
*_Y* de valor de ponto flutuante<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

A diferença entre _X e _Y se _X for maior que _Y; caso contrário, + 0.

## <a name="floor"></a>Floor

Calcula o piso do argumento

```cpp
inline float floor(float _X) restrict(amp);

inline double floor(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o piso do argumento

## <a name="floorf"></a>floorf

Calcula o piso do argumento

```cpp
inline float floorf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o piso do argumento

## <a name="a-namefma-fma"></a><a name="fma"> FMA

Computa o produto do primeiro e segundo argumentos especificados, em seguida, adiciona o terceiro argumento especificado ao resultado; todo o cálculo é executado como uma única operação.

```cpp
inline float fma(
   float _X,
   float _Y,
   float _Z
) restrict(amp);

inline double fma(
   double _X,
   double _Y,
   double _Z
) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
O primeiro argumento de ponto flutuante.
*_Y*<br/>
O segundo argumento de ponto flutuante.
*_Z*<br/>
O terceiro argumento de ponto flutuante.

### <a name="return-value"></a>Valor retornado

O resultado da expressão (_X \* _Y) + _Z. Todo o cálculo é executado como uma única operação; ou seja, as subexpressão são calculadas para precisão infinita e apenas o resultado final é arredondado.

## <a name="fmaf"></a>fmaf

Computa o produto do primeiro e segundo argumentos especificados, em seguida, adiciona o terceiro argumento especificado ao resultado; todo o cálculo é executado como uma única operação.

```cpp
inline float fmaf(
   float _X,
   float _Y,
   float _Z
) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
O primeiro argumento de ponto flutuante.
*_Y*<br/>
O segundo argumento de ponto flutuante.
*_Z*<br/>
O terceiro argumento de ponto flutuante.

### <a name="return-value"></a>Valor retornado

O resultado da expressão (_X \* _Y) + _Z. Todo o cálculo é executado como uma única operação; ou seja, as subexpressão são calculadas para precisão infinita e apenas o resultado final é arredondado.

## <a name="fmax"></a>fmax

Determinar o valor numérico máximo dos argumentos

```cpp
inline float fmax(
    float _X,
    float _Y) restrict(amp);

inline double fmax(
    double _X,
    double _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retornar o valor numérico máximo dos argumentos

## <a name="fmaxf"></a>fmaxf

Determinar o valor numérico máximo dos argumentos

```cpp
inline float fmaxf(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retornar o valor numérico máximo dos argumentos

## <a name="fmin"></a>fmin

Determinar o valor numérico mínimo dos argumentos

```cpp
inline float fmin(
    float _X,
    float _Y) restrict(amp);

inline double fmin(
    double _X,
    double _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retornar o valor numérico mínimo dos argumentos

## <a name="fminf"></a>fminf

Determinar o valor numérico mínimo dos argumentos

```cpp
inline float fminf(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retornar o valor numérico mínimo dos argumentos

## <a name="fmod"></a>Função fmod (C++ amp)

Computa o restante do primeiro argumento especificado dividido pelo segundo argumento especificado.

```cpp
inline float fmod(
    float _X,
    float _Y) restrict(amp);

inline double fmod(
    double _X,
    double _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
O primeiro argumento de ponto flutuante.

*_Y*<br/>
O segundo argumento de ponto flutuante.

### <a name="return-value"></a>Valor retornado

O restante do `_X` dividido por `_Y`; ou seja, o valor de `_X` - `_Y`*n*, em que *n* é um inteiro, de forma que a magnitude do `_X` - `_Y`*n* seja menor que a magnitude da `_Y`.

## <a name="fmodf"></a>fmodf

Computa o restante do primeiro argumento especificado dividido pelo segundo argumento especificado.

```cpp
inline float fmodf(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
O primeiro argumento de ponto flutuante.

*_Y*<br/>
O segundo argumento de ponto flutuante.

### <a name="return-value"></a>Valor retornado

O restante do `_X` dividido por `_Y`; ou seja, o valor de `_X` - `_Y`*n*, em que *n* é um inteiro, de forma que a magnitude do `_X` - `_Y`*n* seja menor que a magnitude da `_Y`.

## <a name="fpclassify"></a>fpclassify

Classifica o valor do argumento como NaN, infinito, normal, subnormal, zero

```cpp
inline int fpclassify(float _X) restrict(amp);

inline int fpclassify(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor da macro de classificação de número apropriada ao valor do argumento.

## <a name="frexp"></a>frexp

Obtém o mantissa e o expoente de _X

```cpp
inline float frexp(
    float _X,
    _Out_ int* _Exp) restrict(amp);

inline double frexp(
    double _X,
    _Out_ int* _Exp) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Exp*<br/>
Retorna o expoente inteiro de _X no valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o _X mantissa

## <a name="frexpf"></a>frexpf

Obtém o mantissa e o expoente de _X

```cpp
inline float frexpf(
    float _X,
    _Out_ int* _Exp) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Exp*<br/>
Retorna o expoente inteiro de _X no valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o _X mantissa

## <a name="hypot"></a>hypot

Computa a raiz quadrada da soma dos quadrados de _X e _Y

```cpp
inline float hypot(
    float _X,
    float _Y) restrict(amp);

inline double hypot(
    double _X,
    double _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna a raiz quadrada da soma dos quadrados de _X e _Y

## <a name="hypotf"></a>hypotf

Computa a raiz quadrada da soma dos quadrados de _X e _Y

```cpp
inline float hypotf(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna a raiz quadrada da soma dos quadrados de _X e _Y

## <a name="ilogb"></a>ilogb

Extrair o expoente de _X como um valor int assinado

```cpp
inline int ilogb(float _X) restrict(amp);

inline int ilogb(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o expoente de _X como um valor int assinado

## <a name="ilogbf"></a>ilogbf

Extrair o expoente de _X como um valor int assinado

```cpp
inline int ilogbf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o expoente de _X como um valor int assinado

## <a name="isfinite"></a>isfinito

Determina se o argumento tem um valor finito

```cpp
inline int isfinite(float _X) restrict(amp);

inline int isfinite(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna um valor diferente de zero se e somente se o argumento tiver um valor finito

## <a name="isinf"></a>isinf

Determina se o argumento é um infinito

```cpp
inline int isinf(float _X) restrict(amp);

inline int isinf(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna um valor diferente de zero se e somente se o argumento tiver um valor infinito

## <a name="isnan"></a>IsNaN

Determina se o argumento é um NaN

```cpp
inline int isnan(float _X) restrict(amp);

inline int isnan(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna um valor diferente de zero se e somente se o argumento tiver um valor NaN

## <a name="isnormal"></a>IsNormal

Determina se o argumento é um normal

```cpp
inline int isnormal(float _X) restrict(amp);

inline int isnormal(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna um valor diferente de zero se e somente se o argumento tiver um valor normal

## <a name="ldexp"></a>ldexp

Computa um número real do mantissa e do expoente especificados.

```cpp
inline float ldexp(
    float _X,
    int _Exp) restrict(amp);

inline double ldexp(
    double _X,
    double _Exp) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante, mantissa

*_Exp*<br/>
Valor inteiro, expoente

### <a name="return-value"></a>Valor retornado

Retorna _X \* 2 ^ _Exp

## <a name="ldexpf"></a>ldexpf

Computa um número real do mantissa e do expoente especificados.

```cpp
inline float ldexpf(
    float _X,
    int _Exp) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante, mantissa

*_Exp*<br/>
Valor inteiro, expoente

### <a name="return-value"></a>Valor retornado

Retorna _X \* 2 ^ _Exp

## <a name="lgamma"></a>lgamma

Computa o logaritmo natural do valor absoluto do gama do argumento

```cpp
inline float lgamma(
    float _X,
    _Out_ int* _Sign) restrict(amp);

inline double lgamma(
    double _X,
    _Out_ int* _Sign) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Sign*<br/>
Retorna o sinal

### <a name="return-value"></a>Valor retornado

Retorna o logaritmo natural do valor absoluto do gama do argumento

## <a name="lgammaf"></a>lgammaf

Computa o logaritmo natural do valor absoluto do gama do argumento

```cpp
inline float lgammaf(
    float _X,
    _Out_ int* _Sign) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Sign*<br/>
Retorna o sinal

### <a name="return-value"></a>Valor retornado

Retorna o logaritmo natural do valor absoluto do gama do argumento

## <a name="log"></a>  log

Calcula o logaritmo de base-e do argumento

```cpp
inline float log(float _X) restrict(amp);

inline double log(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o logaritmo de base-e do argumento

## <a name="log10"></a>  log10

Calcula o logaritmo de base 10 do argumento

```cpp
inline float log10(float _X) restrict(amp);

inline double log10(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o logaritmo de base 10 do argumento

## <a name="log10f"></a>log10f

Calcula o logaritmo de base 10 do argumento

```cpp
inline float log10f(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o logaritmo de base 10 do argumento

## <a name="log1p"></a>log1p

Calcula o logaritmo de base e de 1 mais o argumento

```cpp
inline float log1p(float _X) restrict(amp);

inline double log1p(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o logaritmo de base e de 1 mais o argumento

## <a name="log1pf"></a>log1pf

Calcula o logaritmo de base e de 1 mais o argumento

```cpp
inline float log1pf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o logaritmo de base e de 1 mais o argumento

## <a name="log2"></a>log2

Calcula o logaritmo de base 2 do argumento

```cpp
inline float log2(float _X) restrict(amp);

inline double log2(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o logaritmo de base 10 do argumento

## <a name="log2f"></a>log2f

Calcula o logaritmo de base 2 do argumento

```cpp
inline float log2f(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o logaritmo de base 10 do argumento

## <a name="logb"></a>logb

Extrai o expoente de _X, como um valor inteiro assinado no formato de ponto flutuante

```cpp
inline float logb(float _X) restrict(amp);

inline double logb(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o expoente assinado de _X

## <a name="logbf"></a>logbf

Extrai o expoente de _X, como um valor inteiro assinado no formato de ponto flutuante

```cpp
inline float logbf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o expoente assinado de _X

## <a name="logf"></a>logf

Calcula o logaritmo de base-e do argumento

```cpp
inline float logf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o logaritmo de base-e do argumento

## <a name="modf"></a>modf

Divide o argumento especificado em partes fracionárias e de números inteiros.

```cpp
inline float modf(
    float _X,
    _Out_ float* _Iptr) restrict(amp);

inline double modf(
    double _X,
    _Out_ double* _Iptr) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Iptr*<br/>
fora A parte inteira de `_X`, como um valor de ponto flutuante.

### <a name="return-value"></a>Valor retornado

A parte fracionária assinada do `_X`.

## <a name="modff"></a>modff

Divide o argumento especificado em partes fracionárias e de números inteiros.

```cpp
inline float modff(
    float _X,
    _Out_ float* _Iptr) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Iptr*<br/>
A parte inteira de `_X`, como um valor de ponto flutuante.

### <a name="return-value"></a>Valor retornado

Retorna a parte fracionária assinada de `_X`.

## <a name="nan"></a>Nan

Retorna um NaN silencioso

```cpp
inline double nan(int _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor inteiro

### <a name="return-value"></a>Valor retornado

Retorna um NaN silencioso, se disponível, com o conteúdo indicado em _X

## <a name="nanf"></a>nanf

Retorna um NaN silencioso

```cpp
inline float nanf(int _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor inteiro

### <a name="return-value"></a>Valor retornado

Retorna um NaN silencioso, se disponível, com o conteúdo indicado em _X

## <a name="nearbyint"></a>nearbyint

Arredonda o argumento para um valor inteiro no formato de ponto flutuante, usando a direção de arredondamento atual.

```cpp
inline float nearbyint(float _X) restrict(amp);

inline double nearbyint(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor inteiro arredondado.

## <a name="nearbyintf"></a>nearbyintf

Arredonda o argumento para um valor inteiro no formato de ponto flutuante, usando a direção de arredondamento atual.

```cpp
inline float nearbyintf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor inteiro arredondado.

## <a name="nextafter"></a>nextafter

Determina o próximo valor representável, no tipo da função, após _X na direção de _Y

```cpp
inline float nextafter(
    float _X,
    float _Y) restrict(amp);

inline double nextafter(
    double _X,
    double _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o próximo valor representável, no tipo da função, depois de _X na direção de _Y

## <a name="nextafterf"></a>nextafterf

Determina o próximo valor representável, no tipo da função, após _X na direção de _Y

```cpp
inline float nextafterf(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o próximo valor representável, no tipo da função, depois de _X na direção de _Y

## <a name="phi"></a>PI

Retorna a função de distribuição cumulativa do argumento

```cpp
inline float phi(float _X) restrict(amp);

inline double phi(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna a função de distribuição cumulativa do argumento

## <a name="phif"></a>phif

Retorna a função de distribuição cumulativa do argumento

```cpp
inline float phif(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna a função de distribuição cumulativa do argumento

## <a name="pow"></a>  pow

Calcula _X elevado à potência de _Y

```cpp
inline float pow(
    float _X,
    float _Y) restrict(amp);

inline double pow(
    double _X,
    double _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante, base

*_Y*<br/>
Valor de ponto flutuante, expoente

### <a name="return-value"></a>Valor retornado

## <a name="powf"></a>powf

Calcula _X elevado à potência de _Y

```cpp
inline float powf(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante, base

*_Y*<br/>
Valor de ponto flutuante, expoente

### <a name="return-value"></a>Valor retornado

## <a name="probit"></a>probit

Retorna a função de distribuição cumulativa inversa do argumento

```cpp
inline float probit(float _X) restrict(amp);

inline double probit(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna a função de distribuição cumulativa inversa do argumento

## <a name="probitf"></a>probitf

Retorna a função de distribuição cumulativa inversa do argumento

```cpp
inline float probitf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna a função de distribuição cumulativa inversa do argumento

## <a name="rcbrt"></a>rcbrt

Retorna o recíproco da raiz do cubo do argumento

```cpp
inline float rcbrt(float _X) restrict(amp);

inline double rcbrt(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o recíproco da raiz do cubo do argumento

## <a name="rcbrtf"></a>rcbrtf

Retorna o recíproco da raiz do cubo do argumento

```cpp
inline float rcbrtf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o recíproco da raiz do cubo do argumento

## <a name="remainder"></a>final

Calcula o restante: _X REM _Y

```cpp
inline float remainder(
    float _X,
    float _Y) restrict(amp);

inline double remainder(
    double _X,
    double _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Returns _X REM _Y

## <a name="remainderf"></a>remainderf

Calcula o restante: _X REM _Y

```cpp
inline float remainderf(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Returns _X REM _Y

## <a name="remquo"></a>remquo

Computa o restante do primeiro argumento especificado dividido pelo segundo argumento especificado. Também computa o quociente do significante do primeiro argumento especificado dividido pelo significante do segundo argumento especificado e retorna o quociente usando o local especificado no terceiro argumento.

```cpp
inline float remquo(
    float _X,
    float _Y,
    _Out_ int* _Quo) restrict(amp);

inline double remquo(
    double _X,
    double _Y,
    _Out_ int* _Quo) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
O primeiro argumento de ponto flutuante.

*_Y*<br/>
O segundo argumento de ponto flutuante.

*_Quo*<br/>
fora O endereço de um inteiro que é usado para retornar o quociente dos bits fracionários de `_X` dividido pelos bits fracionários de `_Y`.

### <a name="return-value"></a>Valor retornado

Retorna o resto do `_X` dividido por `_Y`.

## <a name="remquof"></a>remquof

Computa o restante do primeiro argumento especificado dividido pelo segundo argumento especificado. Também computa o quociente do significante do primeiro argumento especificado dividido pelo significante do segundo argumento especificado e retorna o quociente usando o local especificado no terceiro argumento.

```cpp
inline float remquof(
    float _X,
    float _Y,
    _Out_ int* _Quo) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
O primeiro argumento de ponto flutuante.

*_Y*<br/>
O segundo argumento de ponto flutuante.

*_Quo*<br/>
fora O endereço de um inteiro que é usado para retornar o quociente dos bits fracionários de `_X` dividido pelos bits fracionários de `_Y`.

### <a name="return-value"></a>Valor retornado

Retorna o resto do `_X` dividido por `_Y`.

## <a name="round"></a>idas

Arredonda _X para o número inteiro mais próximo

```cpp
inline float round(float _X) restrict(amp);

inline double round(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o número inteiro mais próximo de _X

## <a name="roundf"></a>roundf

Arredonda _X para o número inteiro mais próximo

```cpp
inline float roundf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o número inteiro mais próximo de _X

## <a name="rsqrt"></a>rsqrt

Retorna o recíproco da raiz quadrada do argumento

```cpp
inline float rsqrt(float _X) restrict(amp);

inline double rsqrt(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o recíproco da raiz quadrada do argumento

## <a name="rsqrtf"></a>rsqrtf

Retorna o recíproco da raiz quadrada do argumento

```cpp
inline float rsqrtf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o recíproco da raiz quadrada do argumento

## <a name="scalb"></a>scalb

Multiplica _X por FLT_RADIX à potência _Y

```cpp
inline float scalb(
    float _X,
    float _Y) restrict(amp);

inline double scalb(
    double _X,
    double _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna _X \* (FLT_RADIX ^ _Y)

## <a name="scalbf"></a>scalbf

Multiplica _X por FLT_RADIX à potência _Y

```cpp
inline float scalbf(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna _X \* (FLT_RADIX ^ _Y)

## <a name="scalbn"></a>scalbn

Multiplica _X por FLT_RADIX à potência _Y

```cpp
inline float scalbn(
    float _X,
    int _Y) restrict(amp);

inline double scalbn(
    double _X,
    int _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor inteiro

### <a name="return-value"></a>Valor retornado

Retorna _X \* (FLT_RADIX ^ _Y)

## <a name="scalbnf"></a>scalbnf

Multiplica _X por FLT_RADIX à potência _Y

```cpp
inline float scalbnf(
    float _X,
    int _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor inteiro

### <a name="return-value"></a>Valor retornado

Retorna _X \* (FLT_RADIX ^ _Y)

## <a name="signbit"></a>signbit

Determina se o sinal de _X é negativo

```cpp
inline int signbit(float _X) restrict(amp);

inline int signbit(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna um valor diferente de zero se e somente se o sinal de _X for negativo

## <a name="signbitf"></a>signbitf

Determina se o sinal de _X é negativo

```cpp
inline int signbitf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna um valor diferente de zero se e somente se o sinal de _X for negativo

## <a name="sin"></a>  sin

Calcula o valor do seno do argumento

```cpp
inline float sin(float _X) restrict(amp);

inline double sin(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor do seno do argumento

## <a name="sinf"></a>sinf

Calcula o valor do seno do argumento

```cpp
inline float sinf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor do seno do argumento

## <a name="sincos"></a>sincos

Calcula o valor do seno e do cosseno de _X

```cpp
inline void sincos(
    float _X,
    _Out_ float* _S,
    _Out_ float* _C) restrict(amp);

inline void sincos(
    double _X,
    _Out_ double* _S,
    _Out_ double* _C) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_S*<br/>
Retorna o valor do seno de _X

*_C*<br/>
Retorna o valor do cosseno de _X

## <a name="sincosf"></a>sincosf

Calcula o valor do seno e do cosseno de _X

```cpp
inline void sincosf(
    float _X,
    _Out_ float* _S,
    _Out_ float* _C) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_S*<br/>
Retorna o valor do seno de _X

*_C*<br/>
Retorna o valor do cosseno de _X

## <a name="sinh"></a>  sinh

Calcula o valor seno hiperbólico do argumento

```cpp
inline float sinh(float _X) restrict(amp);

inline double sinh(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor seno hiperbólico do argumento

## <a name="sinhf"></a>sinhf

Calcula o valor seno hiperbólico do argumento

```cpp
inline float sinhf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor seno hiperbólico do argumento

## <a name="sinpi"></a>sinpi

Calcula o valor do seno de PI \* _X

```cpp
inline float sinpi(float _X) restrict(amp);

inline double sinpi(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor do seno de PI \* _X

## <a name="sinpif"></a>sinpif

Calcula o valor do seno de PI \* _X

```cpp
inline float sinpif(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor do seno de PI \* _X

## <a name="sqrt"></a>  sqrt

Calcula a raiz squre do argumento

```cpp
inline float sqrt(float _X) restrict(amp);

inline double sqrt(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna a raiz squre do argumento

## <a name="sqrtf"></a>sqrtf

Calcula a raiz squre do argumento

```cpp
inline float sqrtf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna a raiz squre do argumento

## <a name="tan"></a> tan

Calcula o valor da tangente do argumento

```cpp
inline float tan(float _X) restrict(amp);

inline double tan(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor da tangente do argumento

## <a name="tanf"></a>tanf

Calcula o valor da tangente do argumento

```cpp
inline float tanf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor da tangente do argumento

## <a name="tanh"></a>  tanh

Calcula o valor tangente hiperbólico do argumento

```cpp
inline float tanh(float _X) restrict(amp);

inline double tanh(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor tangente hiperbólico do argumento

## <a name="tanhf"></a>tanhf

Calcula o valor tangente hiperbólico do argumento

```cpp
inline float tanhf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor tangente hiperbólico do argumento

## <a name="tanpi"></a>tanpi

Calcula o valor da tangente de PI \* _X

```cpp
inline float tanpi(float _X) restrict(amp);

inline double tanpi(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor tangente de PI \* _X

## <a name="tanpif"></a>tanpif

Calcula o valor da tangente de PI \* _X

```cpp
inline float tanpif(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o valor tangente de PI \* _X

## <a name="tgamma"></a>tgamma

Computa a função gama do _X

```cpp
inline float tgamma(float _X) restrict(amp);

inline double tgamma(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o resultado da função gama do _X

## <a name="tgammaf"></a>tgammaf

Computa a função gama do _X

```cpp
inline float tgammaf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o resultado da função gama do _X

## <a name="trunc"></a>trunc

Trunca o argumento para o componente de inteiro

```cpp
inline float trunc(float _X) restrict(amp);

inline double trunc(double _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o componente de inteiro do argumento

## <a name="truncf"></a>truncf

Trunca o argumento para o componente de inteiro

```cpp
inline float truncf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor retornado

Retorna o componente de inteiro do argumento

## <a name="see-also"></a>Consulte também

[Namespace Concurrency::precise_math](concurrency-precise-math-namespace.md)
