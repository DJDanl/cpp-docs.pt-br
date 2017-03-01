---
title: "Funções de namespace Concurrency:: precise_math | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: fae53ab4-d1c5-45bb-a6a0-a74258e9aea3
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 73273a58f73860c77810a6ab59def560962f9539
ms.lasthandoff: 02/25/2017

---
# <a name="concurrencyprecisemath-namespace-functions"></a>Funções de namespace Concurrency:: precise_math
||||  
|-|-|-|  
|[Função ACOS](#acos)|[Função acosf](#acosf)|[Função ACOSH](#acosh)|  
|[Função acoshf](#acoshf)|[Função ASIN](#asin)|[Função asinf](#asinf)|  
|[Função asinh](#asinh)|[Função asinhf](#asinhf)|[Função ATAN](#atan)|  
|[Função ATAN2](#atan2)|[Função atan2f](#atan2f)|[Função atanf](#atanf)|  
|[Função ATANH](#atanh)|[Função atanhf](#atanhf)|[Função cbrt](#cbrt)|  
|[Função cbrtf](#cbrtf)|[Função ceil](#ceil)|[Função ceilf](#ceilf)|  
|[Função copysign](#copysign)|[Função copysignf](#copysignf)|[CoS função](#cos)|  
|[Função cosf](#cosf)|[Função COSH](#cosh)|[Função coshf](#coshf)|  
|[Função cospi](#cospi)|[Função cospif](#cospif)|[Função ERF](#erf)|  
|[Função ERFC](#erfc)|[Função erfcf](#erfcf)|[Função erfcinv](#erfcinv)|  
|[Função erfcinvf](#erfcinvf)|[Função erff](#erff)|[Função erfinv](#erfinv)|  
|[Função erfinvf](#erfinvf)|[Função Exp](#exp)|[Função exp10](#exp10)|  
|[Função exp10f](#exp10f)|[Função exp2](#exp2)|[Função exp2f](#exp2f)|  
|[Função expf](#expf)|[Função expm1](#expm1)|[Função expm1f](#expm1f)|  
|[Função fabs](#fabs)|[Função fabsf](#fabsf)|[Função Floor](#floor)| 
|[Função fdim](#fdim)|[Função fdimf](#fdimf)|| 
|[Função floorf](#floorf)|[Função FMA](#fma)|[Função fmaf](#fmaf)|
[Função fmax](#fmax)|[Função fmaxf](#fmaxf)|| 
|[Função fmin](#fmin)|[Função fminf](#fminf)|[Função fmod](#fmod)|  
|[Função fmodf](#fmodf)|[Função fpclassify](#fpclassify)|[Função frexp](#frexp)|  
|[Função frexpf](#frexpf)|[Função hypot](#hypot)|[Função hypotf](#hypotf)|  
|[Função ilogb](#ilogb)|[Função ilogbf](#ilogbf)|[Função isfinite](#isfinite)|  
|[Função isinf](#isinf)|[Função isNaN](#isnan)|[Função isnormal](#isnormal)|  
|[Função ldexp](#ldexp)|[Função ldexpf](#ldexpf)|[Função lgamma](#lgamma)|  
|[Função lgammaf](#lgammaf)|[Função log](#log)|[Função LOG10](#log10)|  
|[Função log10f](#log10f)|[Função log1p](#log1p)|[Função log1pf](#log1pf)|  
|[Função log2](#log2)|[Função log2f](#log2f)|[Função logb](#logb)|  
|[Função logbf](#logbf)|[Função logf](#logf)|[Função modf](#modf)|  
|[Função modff](#modff)|[Função NaN](#nan)|[Função nanf](#nanf)|  
|[Função nearbyint](#nearbyint)|[Função nearbyintf](#nearbyintf)|[Função nextafter](#nextafter)|  
|[Função nextafterf](#nextafterf)|[Função PHI](#phi)|[Função phif](#phif)|  
|[Função pow](#pow)|[Função powf](#powf)|[Função probit](#probit)|  
|[Função probitf](#probitf)|[Função rcbrt](#rcbrt)|[Função rcbrtf](#rcbrtf)|  
|[Função Remainder](#remainder)|[Função remainderf](#remainderf)|[Função remquo](#remquo)|  
|[Função remquof](#remquof)|[Função Round](#round)|[Função roundf](#roundf)|  
|[Função rsqrt](#rsqrt)|[Função rsqrtf](#rsqrtf)|[Função scalb](#scalb)|  
|[Função scalbf](#scalbf)|[Função scalbn](#scalbn)|[Função scalbnf](#scalbnf)|  
|[Função signbit](#signbit)|[Função signbitf](#signbitf)|[Função Sin](#sin)|  
|[Função sincos](#sincos)|[Função sincosf](#sincosf)|[Função sinf](#sinf)|  
|[Função SINH](#sinh)|[Função sinhf](#sinhf)|[Função sinpi](#sinpi)|  
|[Função sinpif](#sinpif)|[Função Sqrt](#sqrt)|[Função sqrtf](#sqrtf)|  
|[Função TAN](#tan)|[Função tanf](#tanf)|[Função tanh](#tanh)|  
|[Função tanhf](#tanhf)|[Função tanpi](#tanpi)|[Função tanpif](#tanpif)|  
|[Função tgamma](#tgamma)|[Função tgammaf](#tgammaf)|[Função trunc](#trunc)|  
|[Função truncf](#truncf)|  
  
##  <a name="a-nameacosa--acos-function"></a><a name="acos"></a>Função ACOS  
 Calcula o arco cosseno do argumento  
  
```  
inline float acos(float _X) restrict(amp);

 
inline double acos(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor de arco cosseno do argumento  
  
##  <a name="a-nameacosfa--acosf-function"></a><a name="acosf"></a>Função acosf  
 Calcula o arco cosseno do argumento  
  
```  
inline float acosf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor de arco cosseno do argumento  
  
##  <a name="a-nameacosha--acosh-function"></a><a name="acosh"></a>Função ACOSH  
 Calcula o cosseno hiperbólico inverso do argumento  
  
```  
inline float acosh(float _X) restrict(amp);

 
inline double acosh(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor cosseno hiperbólico inverso do argumento  
  
##  <a name="a-nameacoshfa--acoshf-function"></a><a name="acoshf"></a>Função acoshf  
 Calcula o cosseno hiperbólico inverso do argumento  
  
```  
inline float acoshf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor cosseno hiperbólico inverso do argumento  
  
##  <a name="a-nameasina--asin-function"></a><a name="asin"></a>Função ASIN  
 Calcula o arco seno do argumento  
  
```  
inline float asin(float _X) restrict(amp);

 
inline double asin(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor do seno do argumento  
  
##  <a name="a-nameasinfa--asinf-function"></a><a name="asinf"></a>Função asinf  
 Calcula o arco seno do argumento  
  
```  
inline float asinf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor do seno do argumento  
  
##  <a name="a-nameasinha--asinh-function"></a><a name="asinh"></a>Função asinh  
 Calcula o seno hiperbólico inverso do argumento  
  
```  
inline float asinh(float _X) restrict(amp);

 
inline double asinh(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor do seno hiperbólico inverso do argumento  
  
##  <a name="a-nameasinhfa--asinhf-function"></a><a name="asinhf"></a>Função asinhf  
 Calcula o seno hiperbólico inverso do argumento  
  
```  
inline float asinhf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor do seno hiperbólico inverso do argumento  
  
##  <a name="a-nameatana--atan-function"></a><a name="atan"></a>Função ATAN  
 Calcula o arco tangente do argumento  
  
```  
inline float atan(float _X) restrict(amp);

 
inline double atan(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor de arco tangente do argumento  
  
##  <a name="a-nameatan2a--atan2-function"></a><a name="atan2"></a>Função ATAN2  
 Calcula o arco tangente de y/x  
  
```  
inline float atan2(
    float _Y,  
    float _X) restrict(amp);

 
inline double atan2(
    double _Y,  
    double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Y`  
 Valor de ponto flutuante  
  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor de y/x arctangent  
  
##  <a name="a-nameatan2fa--atan2f-function"></a><a name="atan2f"></a>Função atan2f  
 Calcula o arco tangente de y/x  
  
```  
inline float atan2f(
    float _Y,  
    float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Y`  
 Valor de ponto flutuante  
  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor de y/x arctangent  
  
##  <a name="a-nameatanfa--atanf-function"></a><a name="atanf"></a>Função atanf  
 Calcula o arco tangente do argumento  
  
```  
inline float atanf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor de arco tangente do argumento  
  
##  <a name="a-nameatanha--atanh-function"></a><a name="atanh"></a>Função ATANH  
 Calcula a tangente hiperbólica inversa do argumento  
  
```  
inline float atanh(float _X) restrict(amp);

 
inline double atanh(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor de tangente hiperbólico inverso do argumento  
  
##  <a name="a-nameatanhfa--atanhf-function"></a><a name="atanhf"></a>Função atanhf  
 Calcula a tangente hiperbólica inversa do argumento  
  
```  
inline float atanhf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor de tangente hiperbólico inverso do argumento  
  
##  <a name="a-namecbrta--cbrt-function"></a><a name="cbrt"></a>Função cbrt  
 Calcula a raiz cúbica real do argumento  
  
```  
inline float cbrt(float _X) restrict(amp);

 
inline double cbrt(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a raiz cúbica real do argumento  
  
##  <a name="a-namecbrtfa--cbrtf-function"></a><a name="cbrtf"></a>Função cbrtf  
 Calcula a raiz cúbica real do argumento  
  
```  
inline float cbrtf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a raiz cúbica real do argumento  
  
##  <a name="a-nameceila--ceil-function"></a><a name="ceil"></a>Função ceil  
 Calcula o teto do argumento  
  
```  
inline float ceil(float _X) restrict(amp);

 
inline double ceil(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o teto do argumento  
  
##  <a name="a-nameceilfa--ceilf-function"></a><a name="ceilf"></a>Função ceilf  
 Calcula o teto do argumento  
  
```  
inline float ceilf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o teto do argumento  
  
##  <a name="a-namecopysigna--copysign-function"></a><a name="copysign"></a>Função copysign  
 Produz um valor com magnitude de x e o sinal de y  
  
```  
inline float copysign(
    float _X,  
    float _Y) restrict(amp);

 
inline double copysign(
    double _X,  
    double _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Y`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor com magnitude de x e o sinal de y  
  
##  <a name="a-namecopysignfa--copysignf-function"></a><a name="copysignf"></a>Função copysignf  
 Produz um valor com magnitude de x e o sinal de y  
  
```  
inline float copysignf(
    float _X,  
    float _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Y`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor com magnitude de x e o sinal de y  
  
##  <a name="a-namecosa--cos-function"></a><a name="cos"></a>CoS função  
 Calcula o cosseno do argumento  
  
```  
inline float cos(float _X) restrict(amp);

 
inline double cos(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor cosseno do argumento  
  
##  <a name="a-namecosfa--cosf-function"></a><a name="cosf"></a>Função cosf  
 Calcula o cosseno do argumento  
  
```  
inline float cosf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor cosseno do argumento  
  
##  <a name="a-namecosha--cosh-function"></a><a name="cosh"></a>Função COSH  
 Calcula o valor cosseno hiperbólico do argumento  
  
```  
inline float cosh(float _X) restrict(amp);

 
inline double cosh(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor cosseno hiperbólico do argumento  
  
##  <a name="a-namecoshfa--coshf-function"></a><a name="coshf"></a>Função coshf  
 Calcula o valor cosseno hiperbólico do argumento  
  
```  
inline float coshf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor cosseno hiperbólico do argumento  
  
##  <a name="a-namecospia--cospi-function"></a><a name="cospi"></a>Função cospi  
 Calcula o valor cosseno de pi * x  
  
```  
inline float cospi(float _X) restrict(amp);

 
inline double cospi(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor cosseno de pi * x  
  
##  <a name="a-namecospifa--cospif-function"></a><a name="cospif"></a>Função cospif  
 Calcula o valor cosseno de pi * x  
  
```  
inline float cospif(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor cosseno de pi * x  
  
##  <a name="a-nameerfa--erf-function"></a><a name="erf"></a>Função ERF  
 Computa a função de erro de x  
  
```  
inline float erf(float _X) restrict(amp);

 
inline double erf(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a função de erro de x  
  
##  <a name="a-nameerfca--erfc-function"></a><a name="erfc"></a>Função ERFC  
 Calcula a função de erro complementar de x  
  
```  
inline float erfc(float _X) restrict(amp);

 
inline double erfc(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a função de erro complementar de x  
  
##  <a name="a-nameerfcfa--erfcf-function"></a><a name="erfcf"></a>Função erfcf  
 Calcula a função de erro complementar de x  
  
```  
inline float erfcf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a função de erro complementar de x  
  
##  <a name="a-nameerfcinva--erfcinv-function"></a><a name="erfcinv"></a>Função erfcinv  
 Calcula a função de erro complementar inverso de x  
  
```  
inline float erfcinv(float _X) restrict(amp);

 
inline double erfcinv(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a função de erro complementar inverso de x  
  
##  <a name="a-nameerfcinvfa--erfcinvf-function"></a><a name="erfcinvf"></a>Função erfcinvf  
 Calcula a função de erro complementar inverso de x  
  
```  
inline float erfcinvf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a função de erro complementar inverso de x  
  
##  <a name="a-nameerffa--erff-function"></a><a name="erff"></a>Função erff  
 Computa a função de erro de x  
  
```  
inline float erff(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a função de erro de x  
  
##  <a name="a-nameerfinva--erfinv-function"></a><a name="erfinv"></a>Função erfinv  
 Computa a função de erro inverso de x  
  
```  
inline float erfinv(float _X) restrict(amp);

 
inline double erfinv(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a função de erro inverso de x  
  
##  <a name="a-nameerfinvfa--erfinvf-function"></a><a name="erfinvf"></a>Função erfinvf  
 Computa a função de erro inverso de x  
  
```  
inline float erfinvf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a função de erro inverso de x  
  
##  <a name="a-nameexp10a--exp10-function"></a><a name="exp10"></a>Função exp10  
 Calcula o exponencial do argumento de base-10  
  
```  
inline float exp10(float _X) restrict(amp);

 
inline double exp10(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o exponencial do argumento de base-10  
  
##  <a name="a-nameexp10fa--exp10f-function"></a><a name="exp10f"></a>Função exp10f  
 Calcula o exponencial do argumento de base-10  
  
```  
inline float exp10f(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o exponencial do argumento de base-10  
  
##  <a name="a-nameexpm1a--expm1-function"></a><a name="expm1"></a>Função expm1  
 Calcula a exponencial de base e do argumento, menos 1  
  
```  
inline float expm1(float exponent) restrict(amp);

 
inline double expm1(double exponent) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `exponent`  
 O termo exponencial *n* da expressão matemática `e` <sup>n</sup>, onde `e` é a base do logaritmo natural.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a exponencial de base e do argumento, menos 1  
  
##  <a name="a-nameexpm1fa--expm1f-function"></a><a name="expm1f"></a>Função expm1f  
 Calcula a exponencial de base e do argumento, menos 1  
  
```  
inline float expm1f(float exponent) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `exponent`  
 O termo exponencial *n* da expressão matemática `e` <sup>n</sup>, onde `e` é a base do logaritmo natural.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a exponencial de base e do argumento, menos 1  
  
##  <a name="a-nameexpa--exp-function"></a><a name="exp"></a>Função Exp  
 Calcula a exponencial do argumento de base-e  
  
```  
inline float exp(float _X) restrict(amp);

 
inline double exp(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o exponencial do argumento de base-e  
  
##  <a name="a-nameexpfa--expf-function"></a><a name="expf"></a>Função expf  
 Calcula a exponencial do argumento de base-e  
  
```  
inline float expf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o exponencial do argumento de base-e  
  
##  <a name="a-nameexp2a--exp2-function"></a><a name="exp2"></a>Função exp2  
 Calcula o exponencial do argumento de base-2  
  
```  
inline float exp2(float _X) restrict(amp);

 
inline double exp2(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o exponencial do argumento de base-2  
  
##  <a name="a-nameexp2fa--exp2f-function"></a><a name="exp2f"></a>Função exp2f  
 Calcula o exponencial do argumento de base-2  
  
```  
inline float exp2f(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o exponencial do argumento de base-2  
  
##  <a name="a-namefabsa--fabs-function"></a><a name="fabs"></a>Função fabs  
 Retorna o valor absoluto do argumento  
  
```  
inline float fabs(float _X) restrict(amp);

 
inline double fabs(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor absoluto do argumento  
  
##  <a name="a-namefabsfa--fabsf-function"></a><a name="fabsf"></a>Função fabsf  
 Retorna o valor absoluto do argumento  
  
```  
inline float fabsf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor absoluto do argumento  

## <a name="a-namefdima-fdim-function"></a><a name="fdim"></a>Função fdim  
Calcula a diferença positiva entre os argumentos.
```  
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
`_X`Valor de ponto flutuante `_Y` valor de ponto flutuante


### <a name="return-value"></a>Valor de retorno
A diferença entre x e y se x for maior que y; Caso contrário, +&0;.
 
## <a name="a-namefdimfa-fdimf-function"></a><a name="fdimf"></a>Função fdimf
Calcula a diferença positiva entre os argumentos.
```
inline float fdimf(
   float _X,
   float _Y
) restrict(amp);
```
### <a name="parameters"></a>Parâmetros
`_X`Valor de ponto flutuante `_Y` valor de ponto flutuante

### <a name="return-value"></a>Valor de retorno
A diferença entre x e y se x for maior que y; Caso contrário, +&0;. 
  
##  <a name="a-namefloora--floor-function"></a><a name="floor"></a>Função Floor  
 Calcula a base do argumento  
  
```  
inline float floor(float _X) restrict(amp);

 
inline double floor(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o piso do argumento  
  
##  <a name="a-namefloorfa--floorf-function"></a><a name="floorf"></a>Função floorf  
 Calcula a base do argumento  
  
```  
inline float floorf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o piso do argumento  

## <a name="a-namefma-fma-function"></a><a name="fma">Função FMA  
Calcula o produto dos argumentos especificados primeiro e segundo, em seguida, adiciona o terceiro argumento especificado para o resultado; a computação inteira é executada como uma única operação.
```
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
`_X`O primeiro argumento de ponto flutuante.
`_Y`O segundo argumento de ponto flutuante.
`_Z`O terceiro argumento de ponto flutuante.

### <a name="return-value"></a>Valor de retorno
O resultado da expressão ( x * y) + z. A computação inteira é executada como uma única operação; ou seja, as subexpressões são calculadas para precisão infinito, e apenas o resultado final é arredondado. 

## <a name="a-namefmafa-fmaf-function"></a><a name="fmaf"></a>Função fmaf  
Calcula o produto dos argumentos especificados primeiro e segundo, em seguida, adiciona o terceiro argumento especificado para o resultado; a computação inteira é executada como uma única operação.
```
inline float fmaf(
   float _X,
   float _Y,
   float _Z
) restrict(amp);
```  
### <a name="parameters"></a>Parâmetros
`_X`O primeiro argumento de ponto flutuante.
`_Y`O segundo argumento de ponto flutuante.
`_Z`O terceiro argumento de ponto flutuante.

### <a name="return-value"></a>Valor de retorno
O resultado da expressão ( x * y) + z. A computação inteira é executada como uma única operação; ou seja, as subexpressões são calculadas para precisão infinito, e apenas o resultado final é arredondado.
  
##  <a name="a-namefmaxa--fmax-function"></a><a name="fmax"></a>Função fmax  
 Determinar o valor numérico máximo dos argumentos  
  
```  
inline float fmax(
    float _X,  
    float _Y) restrict(amp);

 
inline double fmax(
    double _X,  
    double _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Y`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor numérico máximo dos argumentos  
  
##  <a name="a-namefmaxfa--fmaxf-function"></a><a name="fmaxf"></a>Função fmaxf  
 Determinar o valor numérico máximo dos argumentos  
  
```  
inline float fmaxf(
    float _X,  
    float _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Y`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor numérico máximo dos argumentos  
  
##  <a name="a-namefmina--fmin-function"></a><a name="fmin"></a>Função fmin  
 Determinar o valor numérico mínimo dos argumentos  
  
```  
inline float fmin(
    float _X,  
    float _Y) restrict(amp);

 
inline double fmin(
    double _X,  
    double _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Y`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor numérico mínimo dos argumentos  
  
##  <a name="a-namefminfa--fminf-function"></a><a name="fminf"></a>Função fminf  
 Determinar o valor numérico mínimo dos argumentos  
  
```  
inline float fminf(
    float _X,  
    float _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Y`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor numérico mínimo dos argumentos  
  
##  <a name="a-namefmoda--fmod-function-c-amp"></a><a name="fmod"></a>Função fmod (C++ AMP)  
 Calcula o restante do primeiro argumento especificado dividido pelo segundo argumento especificado.  
  
```  
inline float fmod(
    float _X,  
    float _Y) restrict(amp);

 
inline double fmod(
    double _X,  
    double _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 O primeiro argumento de ponto flutuante.  
  
 `_Y`  
 O segundo argumento de ponto flutuante.  
  
### <a name="return-value"></a>Valor de retorno  
 O restante do `_X` dividido por `_Y`; ou seja, o valor de `_X`  -  `_Y` *n*, onde *n* é um inteiro, de modo que a magnitude do `_X`  -  `_Y` *n* é menor que a magnitude do `_Y`.  
  
##  <a name="a-namefmodfa--fmodf-function"></a><a name="fmodf"></a>Função fmodf  
 Calcula o restante do primeiro argumento especificado dividido pelo segundo argumento especificado.  
  
```  
inline float fmodf(
    float _X,  
    float _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 O primeiro argumento de ponto flutuante.  
  
 `_Y`  
 O segundo argumento de ponto flutuante.  
  
### <a name="return-value"></a>Valor de retorno  
 O restante do `_X` dividido por `_Y`; ou seja, o valor de `_X`  -  `_Y` *n*, onde *n* é um inteiro, de modo que a magnitude do `_X`  -  `_Y` *n* é menor que a magnitude do `_Y`.  
  
##  <a name="a-namefpclassifya--fpclassify-function"></a><a name="fpclassify"></a>Função fpclassify  
 Classifica o valor do argumento como NaN, infinito, normal subnormal, zero  
  
```  
inline int fpclassify(float _X) restrict(amp);

 
inline int fpclassify(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor da macro classificação numérica apropriada para o valor do argumento.  
  
##  <a name="a-namefrexpa--frexp-function"></a><a name="frexp"></a>Função frexp  
 Obtém a mantissa e expoente de x  
  
```  
inline float frexp(
    float _X,  
    _Out_ int* _Exp) restrict(amp);

 
inline double frexp(
    double _X,  
    _Out_ int* _Exp) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Exp`  
 Retorna o expoente inteiro de x no valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o x mantissa  
  
##  <a name="a-namefrexpfa--frexpf-function"></a><a name="frexpf"></a>Função frexpf  
 Obtém a mantissa e expoente de x  
  
```  
inline float frexpf(
    float _X,  
    _Out_ int* _Exp) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Exp`  
 Retorna o expoente inteiro de x no valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o x mantissa  
  
##  <a name="a-namehypota--hypot-function"></a><a name="hypot"></a>Função hypot  
 Calcula a raiz quadrada da soma dos quadrados de x e y  
  
```  
inline float hypot(
    float _X,  
    float _Y) restrict(amp);

 
inline double hypot(
    double _X,  
    double _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Y`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a raiz quadrada da soma dos quadrados de x e y  
  
##  <a name="a-namehypotfa--hypotf-function"></a><a name="hypotf"></a>Função hypotf  
 Calcula a raiz quadrada da soma dos quadrados de x e y  
  
```  
inline float hypotf(
    float _X,  
    float _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Y`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a raiz quadrada da soma dos quadrados de x e y  
  
##  <a name="a-nameilogba--ilogb-function"></a><a name="ilogb"></a>Função ilogb  
 Extraia o expoente de x como um valor inteiro assinado  
  
```  
inline int ilogb(float _X) restrict(amp);

 
inline int ilogb(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o expoente de x como um valor inteiro assinado  
  
##  <a name="a-nameilogbfa--ilogbf-function"></a><a name="ilogbf"></a>Função ilogbf  
 Extraia o expoente de x como um valor inteiro assinado  
  
```  
inline int ilogbf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o expoente de x como um valor inteiro assinado  
  
##  <a name="a-nameisfinitea--isfinite-function"></a><a name="isfinite"></a>Função isfinite  
 Determina se o argumento tem um valor finito  
  
```  
inline int isfinite(float _X) restrict(amp);

 
inline int isfinite(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor diferente de zero, se e somente se o argumento possui um valor finito  
  
##  <a name="a-nameisinfa--isinf-function"></a><a name="isinf"></a>Função isinf  
 Determina se o argumento for um infinito  
  
```  
inline int isinf(float _X) restrict(amp);

 
inline int isinf(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor diferente de zero, se e somente se o argumento possui um valor infinito  
  
##  <a name="a-nameisnana--isnan-function"></a><a name="isnan"></a>Função isNaN  
 Determina se o argumento é um NaN  
  
```  
inline int isnan(float _X) restrict(amp);

 
inline int isnan(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor diferente de zero, se e somente se o argumento possui um valor NaN  
  
##  <a name="a-nameisnormala--isnormal-function"></a><a name="isnormal"></a>Função isnormal  
 Determina se o argumento é um normal  
  
```  
inline int isnormal(float _X) restrict(amp);

 
inline int isnormal(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor diferente de zero, se e somente se o argumento possui um valor normal  
  
##  <a name="a-nameldexpa--ldexp-function"></a><a name="ldexp"></a>Função ldexp  
 Calcula um número real de especificado mantissa e expoente.  
  
```  
inline float ldexp(
    float _X,  
    int _Exp) restrict(amp);

 
inline double ldexp(
    double _X,  
    double _Exp) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante, mantissa  
  
 `_Exp`  
 Valor inteiro, expoente  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna x * 2 ^ _Exp  
  
##  <a name="a-nameldexpfa--ldexpf-function"></a><a name="ldexpf"></a>Função ldexpf  
 Calcula um número real de especificado mantissa e expoente.  
  
```  
inline float ldexpf(
    float _X,  
    int _Exp) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante, mantissa  
  
 `_Exp`  
 Valor inteiro, expoente  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna x * 2 ^ _Exp  
  
##  <a name="a-namelgammaa--lgamma-function"></a><a name="lgamma"></a>Função lgamma  
 Calcula o logaritmo natural do valor absoluto do gama do argumento  
  
```  
inline float lgamma(
    float _X,  
    _Out_ int* _Sign) restrict(amp);

 
inline double lgamma(
    double _X,  
    _Out_ int* _Sign) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Sign`  
 Retorna o sinal  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o logaritmo natural do valor absoluto do gama do argumento  
  
##  <a name="a-namelgammafa--lgammaf-function"></a><a name="lgammaf"></a>Função lgammaf  
 Calcula o logaritmo natural do valor absoluto do gama do argumento  
  
```  
inline float lgammaf(
    float _X,  
    _Out_ int* _Sign) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Sign`  
 Retorna o sinal  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o logaritmo natural do valor absoluto do gama do argumento  
  
##  <a name="a-nameloga--log-function"></a><a name="log"></a>Função log  
 Calcula o logaritmo de base e do argumento  
  
```  
inline float log(float _X) restrict(amp);

 
inline double log(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o logaritmo de base e do argumento  
  
##  <a name="a-namelog10a--log10-function"></a><a name="log10"></a>Função LOG10  
 Calcula o logaritmo de base&10; do argumento  
  
```  
inline float log10(float _X) restrict(amp);

 
inline double log10(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o logaritmo de base&10; do argumento  
  
##  <a name="a-namelog10fa--log10f-function"></a><a name="log10f"></a>Função log10f  
 Calcula o logaritmo de base&10; do argumento  
  
```  
inline float log10f(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o logaritmo de base&10; do argumento  
  
##  <a name="a-namelog1pa--log1p-function"></a><a name="log1p"></a>Função log1p  
 Calcula o logaritmo de base e de 1 mais o argumento  
  
```  
inline float log1p(float _X) restrict(amp);

 
inline double log1p(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o logaritmo de base e de 1 mais o argumento  
  
##  <a name="a-namelog1pfa--log1pf-function"></a><a name="log1pf"></a>Função log1pf  
 Calcula o logaritmo de base e de 1 mais o argumento  
  
```  
inline float log1pf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o logaritmo de base e de 1 mais o argumento  
  
##  <a name="a-namelog2a--log2-function"></a><a name="log2"></a>Função log2  
 Calcula o logaritmo de base&2; do argumento  
  
```  
inline float log2(float _X) restrict(amp);

 
inline double log2(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o logaritmo de base&10; do argumento  
  
##  <a name="a-namelog2fa--log2f-function"></a><a name="log2f"></a>Função log2f  
 Calcula o logaritmo de base&2; do argumento  
  
```  
inline float log2f(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o logaritmo de base&10; do argumento  
  
##  <a name="a-namelogba--logb-function"></a><a name="logb"></a>Função logb  
 Extrai o expoente de x, como um valor inteiro em formato de ponto flutuante  
  
```  
inline float logb(float _X) restrict(amp);

 
inline double logb(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o expoente assinado de x  
  
##  <a name="a-namelogbfa--logbf-function"></a><a name="logbf"></a>Função logbf  
 Extrai o expoente de x, como um valor inteiro em formato de ponto flutuante  
  
```  
inline float logbf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o expoente assinado de x  
  
##  <a name="a-namelogfa--logf-function"></a><a name="logf"></a>Função logf  
 Calcula o logaritmo de base e do argumento  
  
```  
inline float logf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o logaritmo de base e do argumento  
  
##  <a name="a-namemodfa--modf-function"></a><a name="modf"></a>Função modf  
 Divide o argumento especificado em frações e partes do inteiro.  
  
```  
inline float modf(
    float _X,  
    _Out_ float* _Iptr) restrict(amp);

 
inline double modf(
    double _X,  
    _Out_ double* _Iptr) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Iptr`(parâmetro out)  
 A parte inteira de `_X`, como um valor de ponto flutuante.  
  
### <a name="return-value"></a>Valor de retorno  
 A parte fracionária assinada de `_X`.  
  
##  <a name="a-namemodffa--modff-function"></a><a name="modff"></a>Função modff  
 Divide o argumento especificado em frações e partes do inteiro.  
  
```  
inline float modff(
    float _X,  
    _Out_ float* _Iptr) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Iptr`  
 A parte inteira de `_X`, como um valor de ponto flutuante.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a parte fracionária assinada de `_X`.  
  
##  <a name="a-namenana--nan-function"></a><a name="nan"></a>Função NaN  
 Retorna um NaN silencioso  
  
```  
inline double nan(int _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor inteiro  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um NaN silencioso, se disponível, com o conteúdo indicado no x  
  
##  <a name="a-namenanfa--nanf-function"></a><a name="nanf"></a>Função nanf  
 Retorna um NaN silencioso  
  
```  
inline float nanf(int _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor inteiro  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um NaN silencioso, se disponível, com o conteúdo indicado no x  
  
##  <a name="a-namenearbyinta--nearbyint-function"></a><a name="nearbyint"></a>Função nearbyint  
 Arredonda o argumento para um valor inteiro no formato de ponto flutuante, usando a direção de arredondamento atual.  
  
```  
inline float nearbyint(float _X) restrict(amp);

 
inline double nearbyint(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor inteiro arredondado.  
  
##  <a name="a-namenearbyintfa--nearbyintf-function"></a><a name="nearbyintf"></a>Função nearbyintf  
 Arredonda o argumento para um valor inteiro no formato de ponto flutuante, usando a direção de arredondamento atual.  
  
```  
inline float nearbyintf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor inteiro arredondado.  
  
##  <a name="a-namenextaftera--nextafter-function"></a><a name="nextafter"></a>Função nextafter  
 Determinar o próximo valor representável, o tipo de função, após x na direção do y  
  
```  
inline float nextafter(
    float _X,  
    float _Y) restrict(amp);

 
inline double nextafter(
    double _X,  
    double _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Y`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o próximo valor representável no tipo de função, após x na direção do y  
  
##  <a name="a-namenextafterfa--nextafterf-function"></a><a name="nextafterf"></a>Função nextafterf  
 Determinar o próximo valor representável, o tipo de função, após x na direção do y  
  
```  
inline float nextafterf(
    float _X,  
    float _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Y`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o próximo valor representável no tipo de função, após x na direção do y  
  
##  <a name="a-namephia--phi-function"></a><a name="phi"></a>Função PHI  
 Retorna a função de distribuição cumulativa do argumento  
  
```  
inline float phi(float _X) restrict(amp);

 
inline double phi(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a função de distribuição cumulativa do argumento  
  
##  <a name="a-namephifa--phif-function"></a><a name="phif"></a>Função phif  
 Retorna a função de distribuição cumulativa do argumento  
  
```  
inline float phif(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a função de distribuição cumulativa do argumento  
  
##  <a name="a-namepowa--pow-function"></a><a name="pow"></a>Função pow  
 Calcula x elevado à potência de y  
  
```  
inline float pow(
    float _X,  
    float _Y) restrict(amp);

 
inline double pow(
    double _X,  
    double _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante, base  
  
 `_Y`  
 Valor de ponto flutuante, expoente  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="a-namepowfa--powf-function"></a><a name="powf"></a>Função powf  
 Calcula x elevado à potência de y  
  
```  
inline float powf(
    float _X,  
    float _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante, base  
  
 `_Y`  
 Valor de ponto flutuante, expoente  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="a-nameprobita--probit-function"></a><a name="probit"></a>Função probit  
 Retorna a função de distribuição cumulativa inversa do argumento  
  
```  
inline float probit(float _X) restrict(amp);

 
inline double probit(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a função de distribuição cumulativa inversa do argumento  
  
##  <a name="a-nameprobitfa--probitf-function"></a><a name="probitf"></a>Função probitf  
 Retorna a função de distribuição cumulativa inversa do argumento  
  
```  
inline float probitf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a função de distribuição cumulativa inversa do argumento  
  
##  <a name="a-namercbrta--rcbrt-function"></a><a name="rcbrt"></a>Função rcbrt  
 Retorna o recíproco da raiz do cubo do argumento  
  
```  
inline float rcbrt(float _X) restrict(amp);

 
inline double rcbrt(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o recíproco da raiz do cubo do argumento  
  
##  <a name="a-namercbrtfa--rcbrtf-function"></a><a name="rcbrtf"></a>Função rcbrtf  
 Retorna o recíproco da raiz do cubo do argumento  
  
```  
inline float rcbrtf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o recíproco da raiz do cubo do argumento  
  
##  <a name="a-nameremaindera--remainder-function"></a><a name="remainder"></a>Função Remainder  
 Calcula o restante: y REM de x  
  
```  
inline float remainder(
    float _X,  
    float _Y) restrict(amp);

 
inline double remainder(
    double _X,  
    double _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Y`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna y REM de x  
  
##  <a name="a-nameremainderfa--remainderf-function"></a><a name="remainderf"></a>Função remainderf  
 Calcula o restante: y REM de x  
  
```  
inline float remainderf(
    float _X,  
    float _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Y`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna y REM de x  
  
##  <a name="a-nameremquoa--remquo-function"></a><a name="remquo"></a>Função remquo  
 Calcula o restante do primeiro argumento especificado dividido pelo segundo argumento especificado. Também computa o quociente do significando do primeiro argumento especificado dividido por significando do segundo argumento especificado e retorna o quociente usando o local especificado no terceiro argumento.  
  
```  
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
 `_X`  
 O primeiro argumento de ponto flutuante.  
  
 `_Y`  
 O segundo argumento de ponto flutuante.  
  
 `_Quo`(parâmetro out)  
 O endereço de um inteiro que é usado para retornar o quociente dos bits frações de `_X` dividido por bits de frações de `_Y`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o resto de `_X` dividido por `_Y`.  
  
##  <a name="a-nameremquofa--remquof-function"></a><a name="remquof"></a>Função remquof  
 Calcula o restante do primeiro argumento especificado dividido pelo segundo argumento especificado. Também computa o quociente do significando do primeiro argumento especificado dividido por significando do segundo argumento especificado e retorna o quociente usando o local especificado no terceiro argumento.  
  
```  
inline float remquof(
    float _X,  
    float _Y,  
    _Out_ int* _Quo) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 O primeiro argumento de ponto flutuante.  
  
 `_Y`  
 O segundo argumento de ponto flutuante.  
  
 `_Quo`(parâmetro out)  
 O endereço de um inteiro que é usado para retornar o quociente dos bits frações de `_X` dividido por bits de frações de `_Y`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o resto de `_X` dividido por `_Y`.  
  
##  <a name="a-namerounda--round-function"></a><a name="round"></a>Função Round  
 Arredonda x para o inteiro mais próximo  
  
```  
inline float round(float _X) restrict(amp);

 
inline double round(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o inteiro mais próximo de x  
  
##  <a name="a-nameroundfa--roundf-function"></a><a name="roundf"></a>Função roundf  
 Arredonda x para o inteiro mais próximo  
  
```  
inline float roundf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o inteiro mais próximo de x  
  
##  <a name="a-namersqrta--rsqrt-function"></a><a name="rsqrt"></a>Função rsqrt  
 Retorna o recíproco da raiz quadrada do argumento  
  
```  
inline float rsqrt(float _X) restrict(amp);

 
inline double rsqrt(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o recíproco da raiz quadrada do argumento  
  
##  <a name="a-namersqrtfa--rsqrtf-function"></a><a name="rsqrtf"></a>Função rsqrtf  
 Retorna o recíproco da raiz quadrada do argumento  
  
```  
inline float rsqrtf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o recíproco da raiz quadrada do argumento  
  
##  <a name="a-namescalba--scalb-function"></a><a name="scalb"></a>Função scalb  
 Multiplica x por FLT_RADIX para o y de energia  
  
```  
inline float scalb(
    float _X,  
    float _Y) restrict(amp);

 
inline double scalb(
    double _X,  
    double _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Y`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna x * (FLT_RADIX ^ y)  
  
##  <a name="a-namescalbfa--scalbf-function"></a><a name="scalbf"></a>Função scalbf  
 Multiplica x por FLT_RADIX para o y de energia  
  
```  
inline float scalbf(
    float _X,  
    float _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Y`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna x * (FLT_RADIX ^ y)  
  
##  <a name="a-namescalbna--scalbn-function"></a><a name="scalbn"></a>Função scalbn  
 Multiplica x por FLT_RADIX para o y de energia  
  
```  
inline float scalbn(
    float _X,  
    int _Y) restrict(amp);

 
inline double scalbn(
    double _X,  
    int _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Y`  
 Valor inteiro  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna x * (FLT_RADIX ^ y)  
  
##  <a name="a-namescalbnfa--scalbnf-function"></a><a name="scalbnf"></a>Função scalbnf  
 Multiplica x por FLT_RADIX para o y de energia  
  
```  
inline float scalbnf(
    float _X,  
    int _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Y`  
 Valor inteiro  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna x * (FLT_RADIX ^ y)  
  
##  <a name="a-namesignbita--signbit-function"></a><a name="signbit"></a>Função signbit  
 Determina se o sinal de x é negativo  
  
```  
inline int signbit(float _X) restrict(amp);

 
inline int signbit(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor diferente de zero, se e somente se o sinal de x for negativo  
  
##  <a name="a-namesignbitfa--signbitf-function"></a><a name="signbitf"></a>Função signbitf  
 Determina se o sinal de x é negativo  
  
```  
inline int signbitf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor diferente de zero, se e somente se o sinal de x for negativo  
  
##  <a name="a-namesina--sin-function"></a><a name="sin"></a>Função Sin  
 Calcula o valor do seno do argumento  
  
```  
inline float sin(float _X) restrict(amp);

 
inline double sin(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor do seno do argumento  
  
##  <a name="a-namesinfa--sinf-function"></a><a name="sinf"></a>Função sinf  
 Calcula o valor do seno do argumento  
  
```  
inline float sinf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor do seno do argumento  
  
##  <a name="a-namesincosa--sincos-function"></a><a name="sincos"></a>Função sincos  
 Calcula o seno e o cosseno o valor de x  
  
```  
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
 `_X`  
 Valor de ponto flutuante  
  
 `_S`  
 Retorna o valor do seno de x  
  
 `_C`  
 Retorna o valor do x cosseno  
  
##  <a name="a-namesincosfa--sincosf-function"></a><a name="sincosf"></a>Função sincosf  
 Calcula o seno e o cosseno o valor de x  
  
```  
inline void sincosf(
    float _X,  
    _Out_ float* _S,  
    _Out_ float* _C) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_S`  
 Retorna o valor do seno de x  
  
 `_C`  
 Retorna o valor do x cosseno  
  
##  <a name="a-namesinha--sinh-function"></a><a name="sinh"></a>Função SINH  
 Calcula o valor do seno hiperbólico do argumento  
  
```  
inline float sinh(float _X) restrict(amp);

 
inline double sinh(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor do seno hiperbólico do argumento  
  
##  <a name="a-namesinhfa--sinhf-function"></a><a name="sinhf"></a>Função sinhf  
 Calcula o valor do seno hiperbólico do argumento  
  
```  
inline float sinhf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor do seno hiperbólico do argumento  
  
##  <a name="a-namesinpia--sinpi-function"></a><a name="sinpi"></a>Função sinpi  
 Calcula o valor do seno de pi * x  
  
```  
inline float sinpi(float _X) restrict(amp);

 
inline double sinpi(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor do seno de pi * x  
  
##  <a name="a-namesinpifa--sinpif-function"></a><a name="sinpif"></a>Função sinpif  
 Calcula o valor do seno de pi * x  
  
```  
inline float sinpif(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor do seno de pi * x  
  
##  <a name="a-namesqrta--sqrt-function"></a><a name="sqrt"></a>Função Sqrt  
 Calcula a raiz squre do argumento  
  
```  
inline float sqrt(float _X) restrict(amp);

 
inline double sqrt(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a raiz squre do argumento  
  
##  <a name="a-namesqrtfa--sqrtf-function"></a><a name="sqrtf"></a>Função sqrtf  
 Calcula a raiz squre do argumento  
  
```  
inline float sqrtf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a raiz squre do argumento  
  
##  <a name="a-nametana--tan-function"></a><a name="tan"></a>Função TAN  
 Calcula o valor tangente do argumento  
  
```  
inline float tan(float _X) restrict(amp);

 
inline double tan(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor tangente do argumento  
  
##  <a name="a-nametanfa--tanf-function"></a><a name="tanf"></a>Função tanf  
 Calcula o valor tangente do argumento  
  
```  
inline float tanf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor tangente do argumento  
  
##  <a name="a-nametanha--tanh-function"></a><a name="tanh"></a>Função tanh  
 Calcula o valor de tangente hiperbólico do argumento  
  
```  
inline float tanh(float _X) restrict(amp);

 
inline double tanh(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor de tangente hiperbólico do argumento  
  
##  <a name="a-nametanhfa--tanhf-function"></a><a name="tanhf"></a>Função tanhf  
 Calcula o valor de tangente hiperbólico do argumento  
  
```  
inline float tanhf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor de tangente hiperbólico do argumento  
  
##  <a name="a-nametanpia--tanpi-function"></a><a name="tanpi"></a>Função tanpi  
 Calcula o valor tangente de pi * x  
  
```  
inline float tanpi(float _X) restrict(amp);

 
inline double tanpi(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor tangente de pi * x  
  
##  <a name="a-nametanpifa--tanpif-function"></a><a name="tanpif"></a>Função tanpif  
 Calcula o valor tangente de pi * x  
  
```  
inline float tanpif(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor tangente de pi * x  
  
##  <a name="a-nametgammaa--tgamma-function"></a><a name="tgamma"></a>Função tgamma  
 Calcula a função gama de x  
  
```  
inline float tgamma(float _X) restrict(amp);

 
inline double tgamma(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o resultado da função gama de x  
  
##  <a name="a-nametgammafa--tgammaf-function"></a><a name="tgammaf"></a>Função tgammaf  
 Calcula a função gama de x  
  
```  
inline float tgammaf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o resultado da função gama de x  
  
##  <a name="a-nametrunca--trunc-function"></a><a name="trunc"></a>Função trunc  
 Trunca o argumento para o componente inteiro  
  
```  
inline float trunc(float _X) restrict(amp);

 
inline double trunc(double _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o componente inteiro do argumento  
  
##  <a name="a-nametruncfa--truncf-function"></a><a name="truncf"></a>Função truncf  
 Trunca o argumento para o componente inteiro  
  
```  
inline float truncf(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o componente inteiro do argumento  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency:: precise_math](concurrency-precise-math-namespace.md)

