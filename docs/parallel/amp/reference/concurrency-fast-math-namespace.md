---
title: Namespace Concurrency::fast_math
ms.date: 11/04/2016
f1_keywords:
- amp_math/Concurrency::fast_math
ms.assetid: 54fed939-9902-49db-9f29-e98fd9821508
ms.openlocfilehash: 57e2134a2254dc4bc34d515e65e2ec629efeff33
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77139508"
---
# <a name="concurrencyfast_math-namespace"></a>Namespace Concurrency::fast_math

As funções no namespace `fast_math` têm menor precisão, dão suporte apenas a precisão simples (`float`) e chamam os intrínsecos do DirectX. Há duas versões de cada função, por exemplo `cos` e `cosf`. Ambas as versões levam e retornam uma `float`, mas cada uma chama o mesmo intrínseco do DirectX.

## <a name="syntax"></a>Sintaxe

```cpp
namespace fast_math;
```

## <a name="members"></a>Membros

### <a name="functions"></a>{1&gt;Funções&lt;1}

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[cos](concurrency-fast-math-namespace-functions.md#cos)|Calcula o arco cosseno do argumento|
|[cosf](concurrency-fast-math-namespace-functions.md#cosf)|Calcula o arco cosseno do argumento|
|[asin](concurrency-fast-math-namespace-functions.md#asin)|Calcula o arco seno do argumento|
|[asinf](concurrency-fast-math-namespace-functions.md#asinf)|Calcula o arco seno do argumento|
|[atan](concurrency-fast-math-namespace-functions.md#atan)|Calcula o tangente do arco do argumento|
|[atan2](concurrency-fast-math-namespace-functions.md#atan2)|Calcula o arco tangente de _Y/_X|
|[atan2f](concurrency-fast-math-namespace-functions.md#atan2f)|Calcula o arco tangente de _Y/_X|
|[atanf](concurrency-fast-math-namespace-functions.md#atanf)|Calcula o tangente do arco do argumento|
|[ceil](concurrency-fast-math-namespace-functions.md#ceil)|Calcula o teto do argumento|
|[ceilf](concurrency-fast-math-namespace-functions.md#ceilf)|Calcula o teto do argumento|
|[cos](concurrency-fast-math-namespace-functions.md#cos)|Calcula o cosseno do argumento|
|[cosf](concurrency-fast-math-namespace-functions.md#cosf)|Calcula o cosseno do argumento|
|[cosh](concurrency-fast-math-namespace-functions.md#cosh)|Calcula o valor cosseno hiperbólico do argumento|
|[coshf](concurrency-fast-math-namespace-functions.md#coshf)|Calcula o valor cosseno hiperbólico do argumento|
|[exp](concurrency-fast-math-namespace-functions.md#exp)|Calcula o exponencial de base e do argumento|
|[exp2](concurrency-fast-math-namespace-functions.md#exp2)|Calcula o exponencial de base 2 do argumento|
|[exp2f](concurrency-fast-math-namespace-functions.md#exp2f)|Calcula o exponencial de base 2 do argumento|
|[expf](concurrency-fast-math-namespace-functions.md#expf)|Calcula o exponencial de base e do argumento|
|[fabs](concurrency-fast-math-namespace-functions.md#fabs)|Retorna o valor absoluto do argumento|
|[fabsf](concurrency-fast-math-namespace-functions.md#fabsf)|Retorna o valor absoluto do argumento|
|[floor](concurrency-fast-math-namespace-functions.md#floor)|Calcula o piso do argumento|
|[floorf](concurrency-fast-math-namespace-functions.md#floorf)|Calcula o piso do argumento|
|[fmax](concurrency-fast-math-namespace-functions.md#fmax)|Determinar o valor numérico máximo dos argumentos|
|[fmaxf](concurrency-fast-math-namespace-functions.md#fmaxf)|Determinar o valor numérico máximo dos argumentos|
|[fmin](concurrency-fast-math-namespace-functions.md#fmin)|Determinar o valor numérico mínimo dos argumentos|
|[fminf](concurrency-fast-math-namespace-functions.md#fminf)|Determinar o valor numérico mínimo dos argumentos|
|[fmod](concurrency-fast-math-namespace-functions.md#fmod)|Calcula o restante de ponto flutuante de _X/_Y|
|[fmodf](concurrency-fast-math-namespace-functions.md#fmodf)|Calcula o restante de ponto flutuante de _X/_Y|
|[frexp](concurrency-fast-math-namespace-functions.md#frexp)|Obtém o mantissa e o expoente de _X|
|[frexpf](concurrency-fast-math-namespace-functions.md#frexpf)|Obtém o mantissa e o expoente de _X|
|[isfinito](concurrency-fast-math-namespace-functions.md#isfinite)|Determina se o argumento tem um valor finito|
|[isinf](concurrency-fast-math-namespace-functions.md#isinf)|Determina se o argumento é um infinito|
|[isnan](concurrency-fast-math-namespace-functions.md#isnan)|Determina se o argumento é um NaN|
|[ldexp](concurrency-fast-math-namespace-functions.md#ldexp)|Computa um número real do mantissa e do expoente|
|[ldexpf](concurrency-fast-math-namespace-functions.md#ldexpf)|Computa um número real do mantissa e do expoente|
|[log](concurrency-fast-math-namespace-functions.md#log)|Calcula o logaritmo de base-e do argumento|
|[log10](concurrency-fast-math-namespace-functions.md#log10)|Calcula o logaritmo de base 10 do argumento|
|[log10f](concurrency-fast-math-namespace-functions.md#log10f)|Calcula o logaritmo de base 10 do argumento|
|[log2](concurrency-fast-math-namespace-functions.md#log2)|Calcula o logaritmo de base 2 do argumento|
|[log2f](concurrency-fast-math-namespace-functions.md#log2f)|Calcula o logaritmo de base 2 do argumento|
|[logf](concurrency-fast-math-namespace-functions.md#logf)|Calcula o logaritmo de base-e do argumento|
|[modf](concurrency-fast-math-namespace-functions.md#modf)|Divide _X em partes fracionárias e de inteiros.|
|[modff](concurrency-fast-math-namespace-functions.md#modff)|Divide _X em partes fracionárias e de inteiros.|
|[pow](concurrency-fast-math-namespace-functions.md#pow)|Calcula _X elevado à potência de _Y|
|[powf](concurrency-fast-math-namespace-functions.md#powf)|Calcula _X elevado à potência de _Y|
|[round](concurrency-fast-math-namespace-functions.md#round)|Arredonda _X para o número inteiro mais próximo|
|[roundf](concurrency-fast-math-namespace-functions.md#roundf)|Arredonda _X para o número inteiro mais próximo|
|[rsqrt](concurrency-fast-math-namespace-functions.md#rsqrt)|Retorna o recíproco da raiz quadrada do argumento|
|[rsqrtf](concurrency-fast-math-namespace-functions.md#rsqrtf)|Retorna o recíproco da raiz quadrada do argumento|
|[signbit](concurrency-fast-math-namespace-functions.md#signbit)|Retorna o sinal do argumento|
|[signbitf](concurrency-fast-math-namespace-functions.md#signbitf)|Retorna o sinal do argumento|
|[sin](concurrency-fast-math-namespace-functions.md#sin)|Calcula o valor do seno do argumento|
|[sincos](concurrency-fast-math-namespace-functions.md#sincos)|Calcula o valor do seno e do cosseno de _X|
|[sincosf](concurrency-fast-math-namespace-functions.md#sincosf)|Calcula o valor do seno e do cosseno de _X|
|[sinf](concurrency-fast-math-namespace-functions.md#sinf)|Calcula o valor do seno do argumento|
|[sinh](concurrency-fast-math-namespace-functions.md#sinh)|Calcula o valor seno hiperbólico do argumento|
|[sinhf](concurrency-fast-math-namespace-functions.md#sinhf)|Calcula o valor seno hiperbólico do argumento|
|[sqrt](concurrency-fast-math-namespace-functions.md#sqrt)|Calcula a raiz quadrada do argumento|
|[sqrtf](concurrency-fast-math-namespace-functions.md#sqrtf)|Calcula a raiz quadrada do argumento|
|[tan](concurrency-fast-math-namespace-functions.md#tan)|Calcula o valor da tangente do argumento|
|[tanf](concurrency-fast-math-namespace-functions.md#tanf)|Calcula o valor da tangente do argumento|
|[tanh](concurrency-fast-math-namespace-functions.md#tanh)|Calcula o valor tangente hiperbólico do argumento|
|[tanhf](concurrency-fast-math-namespace-functions.md#tanhf)|Calcula o valor tangente hiperbólico do argumento|
|[trunc](concurrency-fast-math-namespace-functions.md#trunc)|Trunca o argumento para o componente de inteiro|
|[truncf](concurrency-fast-math-namespace-functions.md#truncf)|Trunca o argumento para o componente de inteiro|

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** amp_math. h

**Namespace:** Simultaneidade:: fast_math

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
