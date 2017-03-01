---
title: "Funções de namespace Concurrency:: fast_math | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: f5763d62-795b-4de6-a7a5-c7115f158708
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 4a01f48a7d087281ab1e9222d1077e92ab8b0d6c
ms.openlocfilehash: 0545a57c492f5c1872c71c04c99b54f86b644102
ms.lasthandoff: 02/25/2017

---
# <a name="concurrencyfastmath-namespace-functions"></a>Funções de namespace Concurrency:: fast_math
||||  
|-|-|-|  
|[Função ACOS](#acos)|[Função acosf](#acosf)|[Função ASIN](#asin)|  
|[Função asinf](#asinf)|[Função ATAN](#atan)|[Função ATAN2](#atan2)|  
|[Função atan2f](#atan2f)|[Função atanf](#atanf)|[Função ceil](#ceil)|  
|[Função ceilf](#ceilf)|[CoS função](#cos)|[Função cosf](#cosf)|  
|[Função COSH](#cosh)|[Função coshf](#coshf)|[Função Exp](#exp)|  
|[Função exp2](#exp2)|[Função exp2f](#exp2f)|[Função expf](#expf)|  
|[Função fabs](#fabs)|[Função fabsf](#fabsf)|[Função Floor](#floor)|  
|[Função floorf](#floorf)|[Função fmax](#fmax)|[Função fmaxf](#fmaxf)|  
|[Função fmin](#fmin)|[Função fminf](#fminf)|[Função fmod](#fmod)|  
|[Função fmodf](#fmodf)|[Função frexp](#frexp)|[Função frexpf](#frexpf)|  
|[Função isfinite](#isfinite)|[Função isinf](#isinf)|[Função isNaN](#isnan)|  
|[Função ldexp](#ldexp)|[Função ldexpf](#ldexpf)|[Função log](#log)|  
|[Função LOG10](#log10)|[Função log10f](#log10f)|[Função log2](#log2)|  
|[Função log2f](#log2f)|[Função logf](#logf)|[Função modf](#modf)|  
|[Função modff](#modff)|[Função pow](#pow)|[Função powf](#powf)|  
|[Função Round](#round)|[Função roundf](#roundf)|[Função rsqrt](#rsqrt)|  
|[Função rsqrtf](#rsqrtf)|[Função signbit](#signbit)|[Função signbitf](#signbitf)|  
|[Função Sin](#sin)|[Função sincos](#sincos)|[Função sincosf](#sincosf)|  
|[Função sinf](#sinf)|[Função SINH](#sinh)|[Função sinhf](#sinhf)|  
|[Função Sqrt](#sqrt)|[Função sqrtf](#sqrtf)|[Função TAN](#tan)|  
|[Função tanf](#tanf)|[Função tanh](#tanh)|[Função tanhf](#tanhf)|  
|[Função trunc](#trunc)|[Função truncf](#truncf)|  
  
##  <a name="a-nameacosa--acos-function"></a><a name="acos"></a>Função ACOS  
 Calcula o arco cosseno do argumento  
  
```  
inline float acos(float _X) restrict(amp);
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
  
##  <a name="a-nameasina--asin-function"></a><a name="asin"></a>Função ASIN  
 Calcula o arco seno do argumento  
  
```  
inline float asin(float _X) restrict(amp);
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
  
##  <a name="a-nameatana--atan-function"></a><a name="atan"></a>Função ATAN  
 Calcula o arco tangente do argumento  
  
```  
inline float atan(float _X) restrict(amp);
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
  
##  <a name="a-nameceila--ceil-function"></a><a name="ceil"></a>Função ceil  
 Calcula o teto do argumento  
  
```  
inline float ceil(float _X) restrict(amp);
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
  
##  <a name="a-namecosa--cos-function"></a><a name="cos"></a>CoS função   
 Calcula o cosseno do argumento  
  
```  
inline float cos(float _X) restrict(amp);
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
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor cosseno hiperbólico do argumento  
  
##  <a name="a-nameexpa--exp-function"></a><a name="exp"></a>Função Exp  
 Calcula a exponencial do argumento de base-e  
  
```  
inline float exp(float _X) restrict(amp);
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
  
##  <a name="a-namefabsa--fabs-function"></a><a name="fabs"></a>Função fabs  
 Retorna o valor absoluto do argumento  
  
```  
inline float fabs(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor inteiro  
  
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
  
##  <a name="a-namefloora--floor-function"></a><a name="floor"></a>Função Floor  
 Calcula a base do argumento  
  
```  
inline float floor(float _X) restrict(amp);
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
  
##  <a name="a-namefmaxa--fmax-function"></a><a name="fmax"></a>Função fmax  
 Determinar o valor numérico máximo dos argumentos  
  
```  
inline float max(
    float _X,  
    float _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor inteiro  
  
 `_Y`  
 Valor inteiro  
  
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
inline float min(
    float _X,  
    float _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor inteiro  
  
 `_Y`  
 Valor inteiro  
  
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
  
##  <a name="a-namefmoda--fmod-function"></a><a name="fmod"></a>Função fmod  
 Calcula o restante de ponto flutuante de x/y  
  
```  
inline float fmod(
    float _X,  
    float _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Y`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o resto de ponto flutuante de x/y  
  
##  <a name="a-namefmodfa--fmodf-function"></a><a name="fmodf"></a>Função fmodf  
 Calcula o restante de ponto flutuante de x/y.  
  
```  
inline float fmodf(
    float _X,  
    float _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Y`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o resto de ponto flutuante de x/y  
  
##  <a name="a-namefrexpa--frexp-function"></a><a name="frexp"></a>Função frexp  
 Obtém a mantissa e expoente de x  
  
```  
inline float frexp(
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
  
##  <a name="a-nameisfinitea--isfinite-function"></a><a name="isfinite"></a>Função isfinite  
 Determina se o argumento tem um valor finito  
  
```  
inline int isfinite(float _X) restrict(amp);
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
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor diferente de zero, se e somente se o argumento possui um valor NaN  
  
##  <a name="a-nameldexpa--ldexp-function"></a><a name="ldexp"></a>Função ldexp  
 Calcula um número real de mantissa e expoente  
  
```  
inline float ldexp(
    float _X,  
    int _Exp) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante, mentissa  
  
 `_Exp`  
 Expoente inteiro  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna x * 2 ^ _Exp  
  
##  <a name="a-nameldexpfa--ldexpf-function"></a><a name="ldexpf"></a>Função ldexpf  
 Calcula um número real de mantissa e expoente  
  
```  
inline float ldexpf(
    float _X,  
    int _Exp) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante, mentissa  
  
 `_Exp`  
 Expoente inteiro  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna x * 2 ^ _Exp  
  
##  <a name="a-nameloga--log-function"></a><a name="log"></a>Função log  
 Calcula o logaritmo de base e do argumento  
  
```  
inline float log(float _X) restrict(amp);
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
  
##  <a name="a-namelog2a--log2-function"></a><a name="log2"></a>Função log2  
 Calcula o logaritmo de base&2; do argumento  
  
```  
inline float log2(float _X) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o logaritmo de base&2; do argumento  
  
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
 Divide x em frações e partes do inteiro.  
  
```  
inline float modf(
    float _X,  
    float* _Ip) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Ip`  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a parte fracionária assinada de x  
  
##  <a name="a-namemodffa--modff-function"></a><a name="modff"></a>Função modff  
 Divide x em frações e partes do inteiro.  
  
```  
inline float modff(
    float _X,  
    float* _Ip) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante  
  
 `_Ip`  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a parte fracionária assinada de x  
  
##  <a name="a-namepowa--pow-function"></a><a name="pow"></a>Função pow  
 Calcula x elevado à potência de y  
  
```  
inline float pow(
    float _X,  
    float _Y) restrict(amp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_X`  
 Valor de ponto flutuante, base  
  
 `_Y`  
 Valor de ponto flutuante, expoente  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor de x elevado à potência de y  
  
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
  
##  <a name="a-namerounda--round-function"></a><a name="round"></a>Função Round  
 Arredonda x para o inteiro mais próximo  
  
```  
inline float round(float _X) restrict(amp);
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
  
##  <a name="a-namesignbita--signbit-function"></a><a name="signbit"></a>Função signbit  
 Determina se o sinal de x é negativo  
  
```  
inline int signbit(float _X) restrict(amp);
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
    float* _S,  
    float* _C) restrict(amp);
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
    float* _S,  
    float* _C) restrict(amp);
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
  
##  <a name="a-namesqrta--sqrt-function"></a><a name="sqrt"></a>Função Sqrt  
 Calcula a raiz squre do argumento  
  
```  
inline float sqrt(float _X) restrict(amp);
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
  
##  <a name="a-nametrunca--trunc-function"></a><a name="trunc"></a>Função trunc  
 Trunca o argumento para o componente inteiro  
  
```  
inline float trunc(float _X) restrict(amp);
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
 [Namespace Concurrency:: fast_math](concurrency-fast-math-namespace.md)

