---
title: 'Namespace Concurrency:: precise_math | Documentos do Microsoft'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- amp_math/Concurrency::precise_math
dev_langs:
- C++
ms.assetid: ba653308-dc28-4384-b2fd-6cd718a72f91
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: b64bd3e3702701ae2685d6688d88988dd91dc5d0
ms.lasthandoff: 02/25/2017

---
# <a name="concurrencyprecisemath-namespace"></a>Namespace Concurrency::precise_math
Funções no `precise_math` namespace são compatíveis com C99. Precisão única e versões de precisão dupla de cada função estão incluídas. Por exemplo, `acos` é a versão de precisão dupla e `acosf` é a versão de precisão única. Essas funções, incluindo as funções de precisão única, exigem suporte estendido de precisão dupla do Accelerator. Você pode usar o [Accelerator:: supports_double_precision membro de dados](accelerator-class.md#supports_double_precision) para determinar se você pode executar essas funções em um acelerador específico. 

  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
namespace precise_math;  
```  
  
#### <a name="parameters"></a>Parâmetros  
  
## <a name="members"></a>Membros  
  
### <a name="functions"></a>Funções  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Função ACOS](concurrency-precise-math-namespace-functions.md#acos)|Sobrecarregado. Calcula o arco cosseno do argumento|  
|[Função acosf](concurrency-precise-math-namespace-functions.md#acosf)|Calcula o arco cosseno do argumento|  
|[Função ACOSH](concurrency-precise-math-namespace-functions.md#acosh)|Sobrecarregado. Calcula o cosseno hiperbólico inverso do argumento|  
|[Função acoshf](concurrency-precise-math-namespace-functions.md#acoshf)|Calcula o cosseno hiperbólico inverso do argumento|  
|[Função ASIN](concurrency-precise-math-namespace-functions.md#asin)|Sobrecarregado. Calcula o arco seno do argumento|  
|[Função asinf](concurrency-precise-math-namespace-functions.md#asinf)|Calcula o arco seno do argumento|  
|[Função asinh](concurrency-precise-math-namespace-functions.md#asinh)|Sobrecarregado. Calcula o seno hiperbólico inverso do argumento|  
|[Função asinhf](concurrency-precise-math-namespace-functions.md#asinhf)|Calcula o seno hiperbólico inverso do argumento|  
|[Função ATAN](concurrency-precise-math-namespace-functions.md#atan)|Sobrecarregado. Calcula o arco tangente do argumento|  
|[Função ATAN2](concurrency-precise-math-namespace-functions.md#atan2)|Sobrecarregado. Calcula o arco tangente de y/x|  
|[Função atan2f](concurrency-precise-math-namespace-functions.md#atan2f)|Calcula o arco tangente de y/x|  
|[Função atanf](concurrency-precise-math-namespace-functions.md#atanf)|Calcula o arco tangente do argumento|  
|[Função ATANH](concurrency-precise-math-namespace-functions.md#atanh)|Sobrecarregado. Calcula a tangente hiperbólica inversa do argumento|  
|[Função atanhf](concurrency-precise-math-namespace-functions.md#atanhf)|Calcula a tangente hiperbólica inversa do argumento|  
|[Função cbrt](concurrency-precise-math-namespace-functions.md#cbrt)|Sobrecarregado. Calcula a raiz cúbica real do argumento|  
|[Função cbrtf](concurrency-precise-math-namespace-functions.md#cbrtf)|Calcula a raiz cúbica real do argumento|  
|[Função ceil](concurrency-precise-math-namespace-functions.md#ceil)|Sobrecarregado. Calcula o teto do argumento|  
|[Função ceilf](concurrency-precise-math-namespace-functions.md#ceilf)|Calcula o teto do argumento|  
|[Função copysign](concurrency-precise-math-namespace-functions.md#copysign)|Sobrecarregado. Produz um valor com magnitude de x e o sinal de y|  
|[Função copysignf](concurrency-precise-math-namespace-functions.md#copysignf)|Produz um valor com magnitude de x e o sinal de y|  
|[CoS função](concurrency-precise-math-namespace-functions.md#cos)|Sobrecarregado. Calcula o cosseno do argumento|  
|[Função cosf](concurrency-precise-math-namespace-functions.md#cosf)|Calcula o cosseno do argumento|  
|[Função COSH](concurrency-precise-math-namespace-functions.md#cosh)|Sobrecarregado. Calcula o valor cosseno hiperbólico do argumento|  
|[Função coshf](concurrency-precise-math-namespace-functions.md#coshf)|Calcula o valor cosseno hiperbólico do argumento|  
|[Função cospi](concurrency-precise-math-namespace-functions.md#cospi)|Sobrecarregado. Calcula o valor cosseno de pi * x|  
|[Função cospif](concurrency-precise-math-namespace-functions.md#cospif)|Calcula o valor cosseno de pi * x|  
|[Função ERF](concurrency-precise-math-namespace-functions.md#erf)|Sobrecarregado. Computa a função de erro de x|  
|[Função ERFC](concurrency-precise-math-namespace-functions.md#erfc)|Sobrecarregado. Calcula a função de erro complementar de x|  
|[Função erfcf](concurrency-precise-math-namespace-functions.md#erfcf)|Calcula a função de erro complementar de x|  
|[Função erfcinv](concurrency-precise-math-namespace-functions.md#erfcinv)|Sobrecarregado. Calcula a função de erro complementar inverso de x|  
|[Função erfcinvf](concurrency-precise-math-namespace-functions.md#erfcinvf)|Calcula a função de erro complementar inverso de x|  
|[Função erff](concurrency-precise-math-namespace-functions.md#erff)|Computa a função de erro de x|  
|[Função erfinv](concurrency-precise-math-namespace-functions.md#erfinv)|Sobrecarregado. Computa a função de erro inverso de x|  
|[Função erfinvf](concurrency-precise-math-namespace-functions.md#erfinvf)|Computa a função de erro inverso de x|  
|[Função Exp](concurrency-precise-math-namespace-functions.md#exp)|Sobrecarregado. Calcula a exponencial do argumento de base-e|  
|[Função exp10](concurrency-precise-math-namespace-functions.md#exp10)|Sobrecarregado. Calcula o exponencial do argumento de base-10|  
|[Função exp10f](concurrency-precise-math-namespace-functions.md#exp10f)|Calcula o exponencial do argumento de base-10|  
|[Função exp2](concurrency-precise-math-namespace-functions.md#exp2)|Sobrecarregado. Calcula o exponencial do argumento de base-2|  
|[Função exp2f](concurrency-precise-math-namespace-functions.md#exp2f)|Calcula o exponencial do argumento de base-2|  
|[Função expf](concurrency-precise-math-namespace-functions.md#expf)|Calcula a exponencial do argumento de base-e|  
|[Função expm1](concurrency-precise-math-namespace-functions.md#expm1)|Sobrecarregado. Calcula a exponencial de base e do argumento, menos 1|  
|[Função expm1f](concurrency-precise-math-namespace-functions.md#expm1f)|Calcula a exponencial de base e do argumento, menos 1|  
|[Função fabs](concurrency-precise-math-namespace-functions.md#fabs)|Sobrecarregado. Retorna o valor absoluto do argumento|  
|[Função fabsf](concurrency-precise-math-namespace-functions.md#fabsf)|Retorna o valor absoluto do argumento|  
|[Função fdim](concurrency-precise-math-namespace-functions.md#fdim)|Sobrecarregado. Determina a diferença positiva entre os argumentos|  
|[Função fdimf](concurrency-precise-math-namespace-functions.md#fdimf)|Determina a diferença positiva entre os argumentos|  
|[Função Floor](concurrency-precise-math-namespace-functions.md#floor)|Sobrecarregado. Calcula a base do argumento|  
|[Função floorf](concurrency-precise-math-namespace-functions.md#floorf)|Calcula a base do argumento|  
|[Função FMA](concurrency-precise-math-namespace-functions.md#fma)|Sobrecarregado. Computação ( x * y) + z, arredondado como uma operação ternária|  
|[Função fmaf](concurrency-precise-math-namespace-functions.md#fmaf)|Computação ( x * y) + z, arredondado como uma operação ternária|  
|[Função fmax](concurrency-precise-math-namespace-functions.md#fmax)|Sobrecarregado. Determinar o valor numérico máximo dos argumentos|  
|[Função fmaxf](concurrency-precise-math-namespace-functions.md#fmaxf)|Determinar o valor numérico máximo dos argumentos|  
|[Função fmin](concurrency-precise-math-namespace-functions.md#fmin)|Sobrecarregado. Determinar o valor numérico mínimo dos argumentos|  
|[Função fminf](concurrency-precise-math-namespace-functions.md#fminf)|Determinar o valor numérico mínimo dos argumentos|  
|[Função fmod (C++ AMP)](concurrency-precise-math-namespace-functions.md#fmod)|Sobrecarregado. Calcula o restante de ponto flutuante de x/y|  
|[Função fmodf](concurrency-precise-math-namespace-functions.md#fmodf)|Calcula o restante de ponto flutuante de x/y|  
|[Função fpclassify](concurrency-precise-math-namespace-functions.md#fpclassify)|Sobrecarregado. Classifica o valor do argumento como NaN, infinito, normal subnormal, zero|  
|[Função frexp](concurrency-precise-math-namespace-functions.md#frexp)|Sobrecarregado. Obtém a mantissa e expoente de x|  
|[Função frexpf](concurrency-precise-math-namespace-functions.md#frexpf)|Obtém a mantissa e expoente de x|  
|[Função hypot](concurrency-precise-math-namespace-functions.md#hypot)|Sobrecarregado. Calcula a raiz quadrada da soma dos quadrados de x e y|  
|[Função hypotf](concurrency-precise-math-namespace-functions.md#hypotf)|Calcula a raiz quadrada da soma dos quadrados de x e y|  
|[Função ilogb](concurrency-precise-math-namespace-functions.md#ilogb)|Sobrecarregado. Extraia o expoente de x como um valor inteiro assinado|  
|[Função ilogbf](concurrency-precise-math-namespace-functions.md#ilogbf)|Extraia o expoente de x como um valor inteiro assinado|  
|[Função isfinite](concurrency-precise-math-namespace-functions.md#isfinite)|Sobrecarregado. Determina se o argumento tem um valor finito|  
|[Função isinf](concurrency-precise-math-namespace-functions.md#isinf)|Sobrecarregado. Determina se o argumento for um infinito|  
|[Função isNaN](concurrency-precise-math-namespace-functions.md#isnan)|Sobrecarregado. Determina se o argumento é um NaN|  
|[Função isnormal](concurrency-precise-math-namespace-functions.md#isnormal)|Sobrecarregado. Determina se o argumento é um normal|  
|[Função ldexp](concurrency-precise-math-namespace-functions.md#ldexp)|Sobrecarregado. Calcula um número real de mantissa e expoente|  
|[Função ldexpf](concurrency-precise-math-namespace-functions.md#ldexpf)|Calcula um número real de mantissa e expoente|  
|[Função lgamma](concurrency-precise-math-namespace-functions.md#lgamma)|Sobrecarregado. Calcula o logaritmo natural do valor absoluto do gama do argumento|  
|[Função lgammaf](concurrency-precise-math-namespace-functions.md#lgammaf)|Calcula o logaritmo natural do valor absoluto do gama do argumento|  
|[Função log](concurrency-precise-math-namespace-functions.md#log)|Sobrecarregado. Calcula o logaritmo de base e do argumento|  
|[Função LOG10](concurrency-precise-math-namespace-functions.md#log10)|Sobrecarregado. Calcula o logaritmo de base&10; do argumento|  
|[Função log10f](concurrency-precise-math-namespace-functions.md#log10f)|Calcula o logaritmo de base&10; do argumento|  
|[Função log1p](concurrency-precise-math-namespace-functions.md#log1p)|Sobrecarregado. Calcula o logaritmo de base e de 1 mais o argumento|  
|[Função log1pf](concurrency-precise-math-namespace-functions.md#log1pf)|Calcula o logaritmo de base e de 1 mais o argumento|  
|[Função log2](concurrency-precise-math-namespace-functions.md#log2)|Sobrecarregado. Calcula o logaritmo de base&2; do argumento|  
|[Função log2f](concurrency-precise-math-namespace-functions.md#log2f)|Calcula o logaritmo de base&2; do argumento|  
|[Função logb](concurrency-precise-math-namespace-functions.md#logb)|Sobrecarregado. Extrai o expoente de x, como um valor inteiro em formato de ponto flutuante|  
|[Função logbf](concurrency-precise-math-namespace-functions.md#logbf)|Extrai o expoente de x, como um valor inteiro em formato de ponto flutuante|  
|[Função logf](concurrency-precise-math-namespace-functions.md#logf)|Calcula o logaritmo de base e do argumento|  
|[Função modf](concurrency-precise-math-namespace-functions.md#modf)|Sobrecarregado. Divide x em frações e partes do inteiro.|  
|[Função modff](concurrency-precise-math-namespace-functions.md#modff)|Divide x em frações e partes do inteiro.|  
|[Função NaN](concurrency-precise-math-namespace-functions.md#nan)|Retorna um NaN silencioso|  
|[Função nanf](concurrency-precise-math-namespace-functions.md#nanf)|Retorna um NaN silencioso|  
|[Função nearbyint](concurrency-precise-math-namespace-functions.md#nearbyint)|Sobrecarregado. Arredonda o argumento para um valor inteiro no formato de ponto flutuante, usando a direção de arredondamento atual.|  
|[Função nearbyintf](concurrency-precise-math-namespace-functions.md#nearbyintf)|Arredonda o argumento para um valor inteiro no formato de ponto flutuante, usando a direção de arredondamento atual.|  
|[Função nextafter](concurrency-precise-math-namespace-functions.md#nextafter)|Sobrecarregado. Determinar o próximo valor representável, o tipo de função, após x na direção do y|  
|[Função nextafterf](concurrency-precise-math-namespace-functions.md#nextafterf)|Determinar o próximo valor representável, o tipo de função, após x na direção do y|  
|[Função PHI](concurrency-precise-math-namespace-functions.md#phi)|Sobrecarregado. Retorna a função de distribuição cumulativa do argumento|  
|[Função phif](concurrency-precise-math-namespace-functions.md#phif)|Retorna a função de distribuição cumulativa do argumento|  
|[Função pow](concurrency-precise-math-namespace-functions.md#pow)|Sobrecarregado. Calcula x elevado à potência de y|  
|[Função powf](concurrency-precise-math-namespace-functions.md#powf)|Calcula x elevado à potência de y|  
|[Função probit](concurrency-precise-math-namespace-functions.md#probit)|Sobrecarregado. Retorna a função de distribuição cumulativa inversa do argumento|  
|[Função probitf](concurrency-precise-math-namespace-functions.md#probitf)|Retorna a função de distribuição cumulativa inversa do argumento|  
|[Função rcbrt](concurrency-precise-math-namespace-functions.md#rcbrt)|Sobrecarregado. Retorna o recíproco da raiz do cubo do argumento|  
|[Função rcbrtf](concurrency-precise-math-namespace-functions.md#rcbrtf)|Retorna o recíproco da raiz do cubo do argumento|  
|[Função Remainder](concurrency-precise-math-namespace-functions.md#remainder)|Sobrecarregado. Calcula o restante: y REM de x|  
|[Função remainderf](concurrency-precise-math-namespace-functions.md#remainderf)|Calcula o restante: y REM de x|  
|[Função remquo](concurrency-precise-math-namespace-functions.md#remquo)|Sobrecarregado. Calcula o restante mesmo como y REM de x. Também calcula 23 bits inferiores de x o quociente de y e retorna esse valor o mesmo sinal x/y. Ele armazena esse valor assinado no inteiro apontado por _Quo.|  
|[Função remquof](concurrency-precise-math-namespace-functions.md#remquof)|Calcula o restante mesmo como y REM de x. Também calcula 23 bits inferiores de x o quociente de y e retorna esse valor o mesmo sinal x/y. Ele armazena esse valor assinado no inteiro apontado por _Quo.|  
|[Função Round](concurrency-precise-math-namespace-functions.md#round)|Sobrecarregado. Arredonda x para o inteiro mais próximo|  
|[Função roundf](concurrency-precise-math-namespace-functions.md#roundf)|Arredonda x para o inteiro mais próximo|  
|[Função rsqrt](concurrency-precise-math-namespace-functions.md#rsqrt)|Sobrecarregado. Retorna o recíproco da raiz quadrada do argumento|  
|[Função rsqrtf](concurrency-precise-math-namespace-functions.md#rsqrtf)|Retorna o recíproco da raiz quadrada do argumento|  
|[Função scalb](concurrency-precise-math-namespace-functions.md#scalb)|Sobrecarregado. Multiplica x por FLT_RADIX para o y de energia|  
|[Função scalbf](concurrency-precise-math-namespace-functions.md#scalbf)|Multiplica x por FLT_RADIX para o y de energia|  
|[Função scalbn](concurrency-precise-math-namespace-functions.md#scalbn)|Sobrecarregado. Multiplica x por FLT_RADIX para o y de energia|  
|[Função scalbnf](concurrency-precise-math-namespace-functions.md#scalbnf)|Multiplica x por FLT_RADIX para o y de energia|  
|[Função signbit](concurrency-precise-math-namespace-functions.md#signbit)|Sobrecarregado. Determina se o sinal de x é negativo|  
|[Função signbitf](concurrency-precise-math-namespace-functions.md#signbitf)|Determina se o sinal de x é negativo|  
|[Função Sin](concurrency-precise-math-namespace-functions.md#sin)|Sobrecarregado. Calcula o valor do seno do argumento|  
|[Função sincos](concurrency-precise-math-namespace-functions.md#sincos)|Sobrecarregado. Calcula o seno e o cosseno o valor de x|  
|[Função sincosf](concurrency-precise-math-namespace-functions.md#sincosf)|Calcula o seno e o cosseno o valor de x|  
|[Função sinf](concurrency-precise-math-namespace-functions.md#sinf)|Calcula o valor do seno do argumento|  
|[Função SINH](concurrency-precise-math-namespace-functions.md#sinh)|Sobrecarregado. Calcula o valor do seno hiperbólico do argumento|  
|[Função sinhf](concurrency-precise-math-namespace-functions.md#sinhf)|Calcula o valor do seno hiperbólico do argumento|  
|[Função sinpi](concurrency-precise-math-namespace-functions.md#sinpi)|Sobrecarregado. Calcula o valor do seno de pi * x|  
|[Função sinpif](concurrency-precise-math-namespace-functions.md#sinpif)|Calcula o valor do seno de pi * x|  
|[Função Sqrt](concurrency-precise-math-namespace-functions.md#sqrt)|Sobrecarregado. Calcula a raiz squre do argumento|  
|[Função sqrtf](concurrency-precise-math-namespace-functions.md#sqrtf)|Calcula a raiz squre do argumento|  
|[Função TAN](concurrency-precise-math-namespace-functions.md#tan)|Sobrecarregado. Calcula o valor tangente do argumento|  
|[Função tanf](concurrency-precise-math-namespace-functions.md#tanf)|Calcula o valor tangente do argumento|  
|[Função tanh](concurrency-precise-math-namespace-functions.md#tanh)|Sobrecarregado. Calcula o valor de tangente hiperbólico do argumento|  
|[Função tanhf](concurrency-precise-math-namespace-functions.md#tanhf)|Calcula o valor de tangente hiperbólico do argumento|  
|[Função tanpi](concurrency-precise-math-namespace-functions.md#tanpi)|Sobrecarregado. Calcula o valor tangente de pi * x|  
|[Função tanpif](concurrency-precise-math-namespace-functions.md#tanpif)|Calcula o valor tangente de pi * x|  
|[Função tgamma](concurrency-precise-math-namespace-functions.md#tgamma)|Sobrecarregado. Calcula a função gama de x|  
|[Função tgammaf](concurrency-precise-math-namespace-functions.md#tgammaf)|Calcula a função gama de x|  
|[Função trunc](concurrency-precise-math-namespace-functions.md#trunc)|Sobrecarregado. Trunca o argumento para o componente inteiro|  
|[Função truncf](concurrency-precise-math-namespace-functions.md#truncf)|Trunca o argumento para o componente inteiro|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp_math. h  
  
 **Namespace:** Simultaneidade  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)

