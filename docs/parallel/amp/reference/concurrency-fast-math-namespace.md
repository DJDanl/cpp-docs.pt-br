---
title: 'Namespace Concurrency:: fast_math | Documentos do Microsoft'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- amp_math/Concurrency::fast_math
dev_langs:
- C++
ms.assetid: 54fed939-9902-49db-9f29-e98fd9821508
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 293452bf0a01f7f83a8a41bcb511bc57c9d45f26
ms.lasthandoff: 02/25/2017

---
# <a name="concurrencyfastmath-namespace"></a>Namespace Concurrency::fast_math
Funções no `fast_math` namespace tiver menos precisão, só preciso de suporte (`float`) e chamar os intrínsecos do DirectX. Há duas versões de cada função, por exemplo `cos` e `cosf`. Ambas as versões levar e retornar um `float`, mas cada chama o DirectX mesmo intrínseco.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
namespace fast_math;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="functions"></a>Funções  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CoS função (fast_math)](concurrency-fast-math-namespace-functions.md#cos)|Calcula o arco cosseno do argumento|  
|[Função cosf (fast_math)](concurrency-fast-math-namespace-functions.md#cosf)|Calcula o arco cosseno do argumento|  
|[Função ASIN (fast_math)](concurrency-fast-math-namespace-functions.md#asin)|Calcula o arco seno do argumento|  
|[Função asinf (fast_math)](concurrency-fast-math-namespace-functions.md#asinf)|Calcula o arco seno do argumento|  
|[Função ATAN (fast_math)](concurrency-fast-math-namespace-functions.md#atan)|Calcula o arco tangente do argumento|  
|[Função ATAN2 (fast_math)](concurrency-fast-math-namespace-functions.md#atan2)|Calcula o arco tangente de y/x|  
|[Função atan2f (fast_math)](concurrency-fast-math-namespace-functions.md#atan2f)|Calcula o arco tangente de y/x|  
|[Função atanf (fast_math)](concurrency-fast-math-namespace-functions.md#atanf)|Calcula o arco tangente do argumento|  
|[Função ceil (fast_math)](concurrency-fast-math-namespace-functions.md#ceil)|Calcula o teto do argumento|  
|[Função ceilf (fast_math)](concurrency-fast-math-namespace-functions.md#ceilf)|Calcula o teto do argumento|  
|[CoS função (fast_math)](concurrency-fast-math-namespace-functions.md#cos)|Calcula o cosseno do argumento|  
|[Função cosf (fast_math)](concurrency-fast-math-namespace-functions.md#cosf)|Calcula o cosseno do argumento|  
|[Função COSH (fast_math)](concurrency-fast-math-namespace-functions.md#cosh)|Calcula o valor cosseno hiperbólico do argumento|  
|[Função coshf (fast_math)](concurrency-fast-math-namespace-functions.md#coshf)|Calcula o valor cosseno hiperbólico do argumento|  
|[Função Exp (fast_math)](concurrency-fast-math-namespace-functions.md#exp)|Calcula a exponencial do argumento de base-e|  
|[Função exp2 (fast_math)](concurrency-fast-math-namespace-functions.md#exp2)|Calcula o exponencial do argumento de base-2|  
|[Função exp2f (fast_math)](concurrency-fast-math-namespace-functions.md#exp2f)|Calcula o exponencial do argumento de base-2|  
|[Função expf (fast_math)](concurrency-fast-math-namespace-functions.md#expf)|Calcula a exponencial do argumento de base-e|  
|[Função fabs (fast_math)](concurrency-fast-math-namespace-functions.md#fabs)|Retorna o valor absoluto do argumento|  
|[Função fabsf (fast_math)](concurrency-fast-math-namespace-functions.md#fabsf)|Retorna o valor absoluto do argumento|  
|[Função Floor (fast_math)](concurrency-fast-math-namespace-functions.md#floor)|Calcula a base do argumento|  
|[Função floorf (fast_math)](concurrency-fast-math-namespace-functions.md#floorf)|Calcula a base do argumento|  
|[Função fmax (fast_math)](concurrency-fast-math-namespace-functions.md#fmax)|Determinar o valor numérico máximo dos argumentos|  
|[Função fmaxf (fast_math)](concurrency-fast-math-namespace-functions.md#fmaxf)|Determinar o valor numérico máximo dos argumentos|  
|[Função fmin (fast_math)](concurrency-fast-math-namespace-functions.md#fmin)|Determinar o valor numérico mínimo dos argumentos|  
|[Função fminf (fast_math)](concurrency-fast-math-namespace-functions.md#fminf)|Determinar o valor numérico mínimo dos argumentos|  
|[Função fmod (fast_math)](concurrency-fast-math-namespace-functions.md#fmod)|Calcula o restante de ponto flutuante de x/y|  
|[Função fmodf (fast_math)](concurrency-fast-math-namespace-functions.md#fmodf)|Calcula o restante de ponto flutuante de x/y|  
|[Função frexp (fast_math)](concurrency-fast-math-namespace-functions.md#frexp)|Obtém a mantissa e expoente de x|  
|[Função frexpf (fast_math)](concurrency-fast-math-namespace-functions.md#frexpf)|Obtém a mantissa e expoente de x|  
|[Função isfinite (fast_math)](concurrency-fast-math-namespace-functions.md#isfinite)|Determina se o argumento tem um valor finito|  
|[Função isinf (fast_math)](concurrency-fast-math-namespace-functions.md#isinf)|Determina se o argumento for um infinito|  
|[Função isNaN (fast_math)](concurrency-fast-math-namespace-functions.md#isnan)|Determina se o argumento é um NaN|  
|[Função ldexp (fast_math)](concurrency-fast-math-namespace-functions.md#ldexp)|Calcula um número real de mantissa e expoente|  
|[Função ldexpf (fast_math)](concurrency-fast-math-namespace-functions.md#ldexpf)|Calcula um número real de mantissa e expoente|  
|[Função log (fast_math)](concurrency-fast-math-namespace-functions.md#log)|Calcula o logaritmo de base e do argumento|  
|[Função LOG10 (fast_math)](concurrency-fast-math-namespace-functions.md#log10)|Calcula o logaritmo de base&10; do argumento|  
|[Função log10f (fast_math)](concurrency-fast-math-namespace-functions.md#log10f)|Calcula o logaritmo de base&10; do argumento|  
|[Função log2 (fast_math)](concurrency-fast-math-namespace-functions.md#log2)|Calcula o logaritmo de base&2; do argumento|  
|[Função log2f (fast_math)](concurrency-fast-math-namespace-functions.md#log2f)|Calcula o logaritmo de base&2; do argumento|  
|[Função logf (fast_math)](concurrency-fast-math-namespace-functions.md#logf)|Calcula o logaritmo de base e do argumento|  
|[Função modf (fast_math)](concurrency-fast-math-namespace-functions.md#modf)|Divide x em frações e partes do inteiro.|  
|[Função modff (fast_math)](concurrency-fast-math-namespace-functions.md#modff)|Divide x em frações e partes do inteiro.|  
|[pow função (fast_math)](concurrency-fast-math-namespace-functions.md#pow)|Calcula x elevado à potência de y|  
|[Função powf (fast_math)](concurrency-fast-math-namespace-functions.md#powf)|Calcula x elevado à potência de y|  
|[Função Round (fast_math)](concurrency-fast-math-namespace-functions.md#round)|Arredonda x para o inteiro mais próximo|  
|[Função roundf (fast_math)](concurrency-fast-math-namespace-functions.md#roundf)|Arredonda x para o inteiro mais próximo|  
|[Função rsqrt (fast_math)](concurrency-fast-math-namespace-functions.md#rsqrt)|Retorna o recíproco da raiz quadrada do argumento|  
|[Função rsqrtf (fast_math)](concurrency-fast-math-namespace-functions.md#rsqrtf)|Retorna o recíproco da raiz quadrada do argumento|  
|[Função signbit (fast_math)](concurrency-fast-math-namespace-functions.md#signbit)|Retorna o sinal do argumento|  
|[Função signbitf (fast_math)](concurrency-fast-math-namespace-functions.md#signbitf)|Retorna o sinal do argumento|  
|[Função sin (fast_math)](concurrency-fast-math-namespace-functions.md#sin)|Calcula o valor do seno do argumento|  
|[Função sincos (fast_math)](concurrency-fast-math-namespace-functions.md#sincos)|Calcula o seno e o cosseno o valor de x|  
|[Função sincosf (fast_math)](concurrency-fast-math-namespace-functions.md#sincosf)|Calcula o seno e o cosseno o valor de x|  
|[Função sinf (fast_math)](concurrency-fast-math-namespace-functions.md#sinf)|Calcula o valor do seno do argumento|  
|[Função SINH (fast_math)](concurrency-fast-math-namespace-functions.md#sinh)|Calcula o valor do seno hiperbólico do argumento|  
|[Função sinhf (fast_math)](concurrency-fast-math-namespace-functions.md#sinhf)|Calcula o valor do seno hiperbólico do argumento|  
|[Função Sqrt (fast_math)](concurrency-fast-math-namespace-functions.md#sqrt)|Calcula a raiz quadrada do argumento|  
|[Função sqrtf (fast_math)](concurrency-fast-math-namespace-functions.md#sqrtf)|Calcula a raiz quadrada do argumento|  
|[Função TAN (fast_math)](concurrency-fast-math-namespace-functions.md#tan)|Calcula o valor tangente do argumento|  
|[Função tanf (fast_math)](concurrency-fast-math-namespace-functions.md#tanf)|Calcula o valor tangente do argumento|  
|[Função TANH (fast_math)](concurrency-fast-math-namespace-functions.md#tanh)|Calcula o valor de tangente hiperbólico do argumento|  
|[Função tanhf (fast_math)](concurrency-fast-math-namespace-functions.md#tanhf)|Calcula o valor de tangente hiperbólico do argumento|  
|[Função trunc (fast_math)](concurrency-fast-math-namespace-functions.md#trunc)|Trunca o argumento para o componente inteiro|  
|[Função truncf (fast_math)](concurrency-fast-math-namespace-functions.md#truncf)|Trunca o argumento para o componente inteiro|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amp_math. h  
  
 **Namespace:** Concurrency:: fast_math  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)

