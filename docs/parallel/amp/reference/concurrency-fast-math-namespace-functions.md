---
title: 'Funções do namespace Concurrency:: fast_math'
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
ms.openlocfilehash: 96178ee72073e5063fc009f17ab21565f3cf1ab5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62405609"
---
# <a name="concurrencyfastmath-namespace-functions"></a>Funções do namespace Concurrency:: fast_math

||||
|-|-|-|
|[acos](#acos)|[acosf](#acosf)|[asin](#asin)|
|[asinf](#asinf)|[atan](#atan)|[atan2](#atan2)|
|[atan2f](#atan2f)|[atanf](#atanf)|[ceil](#ceil)|
|[ceilf](#ceilf)|[cos](#cos)|[cosf](#cosf)|
|[cosh](#cosh)|[coshf](#coshf)|[exp](#exp)|
|[exp2](#exp2)|[exp2f](#exp2f)|[expf](#expf)|
|[fabs](#fabs)|[fabsf](#fabsf)|[floor](#floor)|
|[floorf](#floorf)|[fmax](#fmax)|[fmaxf](#fmaxf)|
|[fmin](#fmin)|[fminf](#fminf)|[fmod](#fmod)|
|[fmodf](#fmodf)|[frexp](#frexp)|[frexpf](#frexpf)|
|[isfinite](#isfinite)|[isinf](#isinf)|[isnan](#isnan)|
|[ldexp](#ldexp)|[ldexpf](#ldexpf)|[log](#log)|
|[log10](#log10)|[log10f](#log10f)|[log2](#log2)|
|[log2f](#log2f)|[logf](#logf)|[modf](#modf)|
|[modff](#modff)|[pow](#pow)|[powf](#powf)|
|[round](#round)|[roundf](#roundf)|[rsqrt](#rsqrt)|
|[rsqrtf](#rsqrtf)|[signbit](#signbit)|[signbitf](#signbitf)|
|[sin](#sin)|[sincos](#sincos)|[sincosf](#sincosf)|
|[sinf](#sinf)|[sinh](#sinh)|[sinhf](#sinhf)|
|[sqrt](#sqrt)|[sqrtf](#sqrtf)|[tan](#tan)|
|[tanf](#tanf)|[tanh](#tanh)|[tanhf](#tanhf)|
|[trunc](#trunc)|[truncf](#truncf)|

##  <a name="acos"></a> acos

Calcula o arco cosseno do argumento

```
inline float acos(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o valor do arco cosseno do argumento

##  <a name="acosf"></a>  acosf

Calcula o arco cosseno do argumento

```
inline float acosf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o valor do arco cosseno do argumento

##  <a name="asin"></a> asin

Calcula o arco seno do argumento

```
inline float asin(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o valor do arco seno do argumento

##  <a name="asinf"></a>  asinf

Calcula o arco seno do argumento

```
inline float asinf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o valor do arco seno do argumento

##  <a name="atan"></a> atan

Calcula o arco tangente do argumento

```
inline float atan(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o valor do arco tangente do argumento

##  <a name="atan2"></a> atan2

Calcula o arco tangente de x

```
inline float atan2(
    float _Y,
    float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Y*<br/>
Valor de ponto flutuante

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o valor do arco tangente de x

##  <a name="atan2f"></a>  atan2f

Calcula o arco tangente de x

```
inline float atan2f(
    float _Y,
    float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_Y*<br/>
Valor de ponto flutuante

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o valor do arco tangente de x

##  <a name="atanf"></a>  atanf

Calcula o arco tangente do argumento

```
inline float atanf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o valor do arco tangente do argumento

##  <a name="ceil"></a>  ceil

Calcula o teto do argumento

```
inline float ceil(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o teto do argumento

##  <a name="ceilf"></a>  ceilf

Calcula o teto do argumento

```
inline float ceilf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o teto do argumento

##  <a name="cosf"></a>  cosf

Calcula o cosseno do argumento

```
inline float cosf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o valor do cosseno do argumento

##  <a name="coshf"></a>  coshf

Calcula o valor do cosseno hiperbólico do argumento

```
inline float coshf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o valor do cosseno hiperbólico do argumento

##  <a name="cos"></a>  cos

Calcula o cosseno do argumento

```
inline float cos(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o valor do cosseno do argumento

##  <a name="cosh"></a>  cosh

Calcula o valor do cosseno hiperbólico do argumento

```
inline float cosh(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o valor do cosseno hiperbólico do argumento

##  <a name="exp"></a>  exp

Calcula o exponencial de base e do argumento

```
inline float exp(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o exponencial de base e do argumento

##  <a name="exp2"></a>  exp2

Calcula o exponencial na base 2 do argumento

```
inline float exp2(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o exponencial na base 2 do argumento

##  <a name="exp2f"></a>  exp2f

Calcula o exponencial na base 2 do argumento

```
inline float exp2f(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o exponencial na base 2 do argumento

##  <a name="expf"></a>  expf

Calcula o exponencial de base e do argumento

```
inline float expf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o exponencial de base e do argumento

##  <a name="fabs"></a>  fabs

Retorna o valor absoluto do argumento

```
inline float fabs(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor inteiro

### <a name="return-value"></a>Valor de retorno

Retorna o valor absoluto do argumento

##  <a name="fabsf"></a>  fabsf

Retorna o valor absoluto do argumento

```
inline float fabsf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o valor absoluto do argumento

##  <a name="floor"></a>  floor

Calcula a base do argumento

```
inline float floor(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna a base do argumento

##  <a name="floorf"></a>  floorf

Calcula a base do argumento

```
inline float floorf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna a base do argumento

##  <a name="fmax"></a>  fmax

Determinar o valor numérico máximo dos argumentos

```
inline float max(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor inteiro

*_Y*<br/>
Valor inteiro

### <a name="return-value"></a>Valor de retorno

Retorna o valor numérico máximo dos argumentos

##  <a name="fmaxf"></a>  fmaxf

Determinar o valor numérico máximo dos argumentos

```
inline float fmaxf(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o valor numérico máximo dos argumentos

##  <a name="fmin"></a>  fmin

Determinar o valor numérico mínimo dos argumentos

```
inline float min(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor inteiro

*_Y*<br/>
Valor inteiro

### <a name="return-value"></a>Valor de retorno

Retornar o valor numérico mínimo dos argumentos

##  <a name="fminf"></a>  fminf

Determinar o valor numérico mínimo dos argumentos

```
inline float fminf(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retornar o valor numérico mínimo dos argumentos

##  <a name="fmod"></a>  fmod

Calcula o restante de ponto flutuante de x/y

```
inline float fmod(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o restante de ponto flutuante de x/y

##  <a name="fmodf"></a>  fmodf

Calcula o restante de ponto flutuante de x/y.

```
inline float fmodf(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Y*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o restante de ponto flutuante de x/y

##  <a name="frexp"></a>  frexp

Obtém a mantissa e expoente de x

```
inline float frexp(
    float _X,
    _Out_ int* _Exp) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Exp*<br/>
Retorna o expoente inteiro de x no valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o x mantissa

##  <a name="frexpf"></a>  frexpf

Obtém a mantissa e expoente de x

```
inline float frexpf(
    float _X,
    _Out_ int* _Exp) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Exp*<br/>
Retorna o expoente inteiro de x no valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o x mantissa

##  <a name="isfinite"></a>  isfinite

Determina se o argumento tem um valor finito

```
inline int isfinite(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna um valor diferente de zero se e somente se o argumento tem um valor finito

##  <a name="isinf"></a>  isinf

Determina se o argumento é infinito

```
inline int isinf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna um valor diferente de zero se e somente se o argumento tem um valor infinito

##  <a name="isnan"></a>  isnan

Determina se o argumento é um NaN

```
inline int isnan(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna um valor diferente de zero se e somente se o argumento tem um valor NaN

##  <a name="ldexp"></a>  ldexp

Calcula um número real da mantissa e expoente

```
inline float ldexp(
    float _X,
    int _Exp) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante, mentissa

*_Exp*<br/>
Expoente inteiro

### <a name="return-value"></a>Valor de retorno

Returns _X \* 2^_Exp

##  <a name="ldexpf"></a>  ldexpf

Calcula um número real da mantissa e expoente

```
inline float ldexpf(
    float _X,
    int _Exp) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante, mentissa

*_Exp*<br/>
Expoente inteiro

### <a name="return-value"></a>Valor de retorno

Returns _X \* 2^_Exp

##  <a name="log"></a>  log

Calcula o logaritmo de base e do argumento

```
inline float log(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o logaritmo de base e do argumento

##  <a name="log10"></a>  log10

Calcula o logaritmo de base 10 do argumento

```
inline float log10(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o logaritmo de base 10 do argumento

##  <a name="log10f"></a>  log10f

Calcula o logaritmo de base 10 do argumento

```
inline float log10f(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o logaritmo de base 10 do argumento

##  <a name="log2"></a>  log2

Calcula o logaritmo de base 2 do argumento

```
inline float log2(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o logaritmo de base 2 do argumento

##  <a name="log2f"></a>  log2f

Calcula o logaritmo de base 2 do argumento

```
inline float log2f(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o logaritmo de base 10 do argumento

##  <a name="logf"></a>  logf

Calcula o logaritmo de base e do argumento

```
inline float logf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o logaritmo de base e do argumento

##  <a name="modf"></a>  modf

Divide x em fracionários e partes de inteiro.

```
inline float modf(
    float _X,
    float* _Ip) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Ip*<br/>
Recebe a parte inteira do valor

### <a name="return-value"></a>Valor de retorno

Retorna a parte fracionária com sinal de x

##  <a name="modff"></a>  modff

Divide x em fracionários e partes de inteiro.

```
inline float modff(
    float _X,
    float* _Ip) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_Ip*<br/>
Recebe a parte inteira do valor

### <a name="return-value"></a>Valor de retorno

Retorna a parte fracionária com sinal de x

##  <a name="pow"></a>  pow

Calcula o x elevado à potência de y

```
inline float pow(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante, base

*_Y*<br/>
Valor de ponto flutuante, expoente

### <a name="return-value"></a>Valor de retorno

Retorna o valor de x elevado à potência de y

##  <a name="powf"></a>  powf

Calcula o x elevado à potência de y

```
inline float powf(
    float _X,
    float _Y) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante, base

*_Y*<br/>
Valor de ponto flutuante, expoente

### <a name="return-value"></a>Valor de retorno

##  <a name="round"></a>  round

Arredonda o x para o inteiro mais próximo

```
inline float round(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o inteiro mais próximo de x

##  <a name="roundf"></a>  roundf

Arredonda o x para o inteiro mais próximo

```
inline float roundf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o inteiro mais próximo de x

##  <a name="rsqrt"></a>  rsqrt

Retorna o recíproco da raiz quadrada do argumento

```
inline float rsqrt(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o recíproco da raiz quadrada do argumento

##  <a name="rsqrtf"></a>  rsqrtf

Retorna o recíproco da raiz quadrada do argumento

```
inline float rsqrtf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o recíproco da raiz quadrada do argumento

##  <a name="signbit"></a>  signbit

Determina se o sinal de x é negativo

```
inline int signbit(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna um valor diferente de zero se e somente se o sinal de x for negativo

##  <a name="signbitf"></a>  signbitf

Determina se o sinal de x é negativo

```
inline int signbitf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna um valor diferente de zero se e somente se o sinal de x for negativo

##  <a name="sin"></a>  sin

Calcula o valor do seno do argumento

```
inline float sin(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o valor do seno do argumento

##  <a name="sinf"></a>  sinf

Calcula o valor do seno do argumento

```
inline float sinf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o valor do seno do argumento

##  <a name="sincos"></a>  sincos

Calcula o valor do seno e cosseno de x

```
inline void sincos(
    float _X,
    float* _S,
    float* _C) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_S*<br/>
Retorna o valor do seno de x

*_C*<br/>
Retorna o valor do cosseno de x

##  <a name="sincosf"></a>  sincosf

Calcula o valor do seno e cosseno de x

```
inline void sincosf(
    float _X,
    float* _S,
    float* _C) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

*_S*<br/>
Retorna o valor do seno de x

*_C*<br/>
Retorna o valor do cosseno de x

##  <a name="sinh"></a>  sinh

Calcula o valor do seno hiperbólico do argumento

```
inline float sinh(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o valor do seno hiperbólico do argumento

##  <a name="sinhf"></a>  sinhf

Calcula o valor do seno hiperbólico do argumento

```
inline float sinhf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o valor do seno hiperbólico do argumento

##  <a name="sqrt"></a>  sqrt

Calcula a raiz de squre do argumento

```
inline float sqrt(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna a raiz de squre do argumento

##  <a name="sqrtf"></a>  sqrtf

Calcula a raiz de squre do argumento

```
inline float sqrtf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna a raiz de squre do argumento

##  <a name="tan"></a> tan

Calcula o valor tangente do argumento

```
inline float tan(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o valor da tangente do argumento

##  <a name="tanf"></a>  tanf

Calcula o valor tangente do argumento

```
inline float tanf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o valor da tangente do argumento

##  <a name="tanh"></a>  tanh

Calcula o valor de tangente hiperbólico do argumento

```
inline float tanh(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o valor de tangente hiperbólico do argumento

##  <a name="tanhf"></a>  tanhf

Calcula o valor de tangente hiperbólico do argumento

```
inline float tanhf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o valor de tangente hiperbólico do argumento

##  <a name="trunc"></a>  trunc

Trunca o argumento para o componente inteiro

```
inline float trunc(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o componente de número inteiro do argumento

##  <a name="truncf"></a>  truncf

Trunca o argumento para o componente inteiro

```
inline float truncf(float _X) restrict(amp);
```

### <a name="parameters"></a>Parâmetros

*_X*<br/>
Valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno

Retorna o componente de número inteiro do argumento

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp_math. h **Namespace:** Concurrency::fast_math

## <a name="see-also"></a>Consulte também

[Namespace Concurrency::fast_math](concurrency-fast-math-namespace.md)
