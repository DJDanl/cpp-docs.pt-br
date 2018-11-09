---
title: Suporte a expressões matemáticas complexas de C
ms.date: 03/30/2018
f1_keywords:
- c.complex
helpviewer_keywords:
- complex numbers, math routines
- math routines
- complex numbers
ms.openlocfilehash: 12ba858993d3712cbf390288df60faedc602c90a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50452605"
---
# <a name="c-complex-math-support"></a>Suporte a expressões matemáticas complexas de C

A Biblioteca de Tempo de Execução de C (CRT) da Microsoft fornece funções da biblioteca de expressões matemáticas complexas, incluindo todas as que são exigidas pela ISO C99. O compilador não dá suporte diretamente uma palavra-chave **complex** ou **_Complex**, portanto, a implementação da Microsoft usa tipos de estrutura para representar números complexos.

Essas funções são implementadas para equilibrar o desempenho com exatidão. Uma vez que produzir o resultado arredondado corretamente pode ter um custo proibitivo, essas funções foram criadas para produzir de forma eficiente um resultado próximo ao resultado arredondado corretamente. Na maioria dos casos, o resultado produzido está dentro de +/-1 ulp do resultado arredondado corretamente, embora possa haver casos em que a imprecisão é maior.

As rotinas de expressões matemáticas complexas dependem das funções da biblioteca de expressões matemáticas do ponto flutuante para sua implementação. Essas funções têm implementações diferentes para arquiteturas de CPU diferentes. Por exemplo, o CRT x86 de 32 bits pode ter uma implementação diferente do CRT x64 de 64 bits. Além disso, algumas das funções podem ter várias implementações para uma determinada arquitetura de CPU. A implementação mais eficiente é selecionada dinamicamente em tempo de execução dependendo dos conjuntos de instruções com suporte da CPU. Por exemplo, no CRT x86 de 32 bits, algumas funções têm uma implementação x87 e uma implementação SSE2. Quando executado em uma CPU com suporte para SSE2, é usada a implementação SSE2 mais rápida. Quando executado em uma CPU sem suporte para SSE2, é usada a implementação x87 mais lenta. Uma vez que diferentes implementações das funções da biblioteca de matemática podem usar diferentes instruções de CPU e diferentes algoritmos para produzir seus resultados, as funções podem produzir resultados diferentes entre as CPUs. Na maioria dos casos, os resultados são dentro de +/-1 ulp do resultado arredondado corretamente, mas os resultados reais podem variar entre CPUs.

## <a name="types-used-in-complex-math"></a>Tipos usados em expressões matemáticas complexas

A implementação da Microsoft do cabeçalho complex.h define esses tipos como equivalentes para os tipos complexos nativos do padrão C99:

|Tipo padrão|Tipo da Microsoft|
|-|-|
|**float complex** ou **float _Complex**|**_FComplex**|
|**double complex** ou **double _Complex**|**_DComplex**|
|**long double complex** ou **long double _Complex**|**_LComplex**|

O cabeçalho math.h define um tipo separado, **struct _complex**, usado para a função [_cabs](../c-runtime-library/reference/cabs.md). O tipo **struct _complex** não é usado pelas funções matemáticas complexas equivalentes [cabs, cabsf, cabsl](../c-runtime-library/reference/cabs-cabsf-cabsl.md).

## <a name="complex-constants-and-macros"></a>Constantes e macros complexas

**I** é definido como o tipo complexo **float** **_FComplex** inicializado pelo `{ 0.0f, 1.0f }`.

## <a name="trigonometric-functions"></a>Funções trigonométricas

|Função|Descrição|
|-|-|
|[cacos, cacosf, cacosl](../c-runtime-library/reference/cacos-cacosf-cacosl.md)|Calcular o arco cosseno complexo de um número complexo|
|[casin, casinf, casinl](../c-runtime-library/reference/casin-casinf-casinl.md)|Calcular o arco seno complexo de um número complexo|
|[catan, catanf, catanl](../c-runtime-library/reference/catan-catanf-catanl.md)|Calcular o arco tangente complexo de um número complexo|
|[ccos, ccosf, ccosl](../c-runtime-library/reference/ccos-ccosf-ccosl.md)|Calcular o cosseno complexo de um número complexo|
|[csin, csinf, csinl](../c-runtime-library/reference/csin-csinf-csinl.md)|Calcular o seno complexo de um número complexo|
|[ctan, ctanf, ctanl](../c-runtime-library/reference/ctan-ctanf-ctanl.md)|Calcular a tangente complexa de um número complexo|

## <a name="hyperbolic-functions"></a>Funções hiperbólicas

|Função|Descrição|
|-|-|
|[cacosh, cacoshf, cacoshl](../c-runtime-library/reference/cacosh-cacoshf-cacoshl.md)|Calcular o arco cosseno hiperbólico complexo de um número complexo|
|[casinh, casinhf, casinhl](../c-runtime-library/reference/casinh-casinhf-casinhl.md)|Calcular o arco seno hiperbólico complexo de um número complexo|
|[catanh, catanhf, catanhl](../c-runtime-library/reference/catanh-catanhf-catanhl.md)|Calcular o arco tangente hiperbólico complexo de um número complexo|
|[ccosh, ccoshf, ccoshl](../c-runtime-library/reference/ccosh-ccoshf-ccoshl.md)|Calcular o cosseno hiperbólico complexo de um número complexo|
|[csinh, csinhf, csinhl](../c-runtime-library/reference/csinh-csinhf-csinhl.md)|Calcular o seno hiperbólico complexo de um número complexo|
|[ctanh, ctanhf, ctanhl](../c-runtime-library/reference/ctanh-ctanhf-ctanhl.md)|Calcular a tangente hiperbólica complexa de um número complexo|

## <a name="exponential-and-logarithmic-functions"></a>Funções exponenciais e logarítmicas

|Função|Descrição|
|-|-|
|[cexp, cexpf, cexpl](../c-runtime-library/reference/cexp-cexpf-cexpl.md)|Calcular o exponencial de base complexo *e* de um número complexo|
|[clog, clogf, clogl](../c-runtime-library/reference/clog-clogf-clogl.md)|Calcular o complexo logaritmo natural (de base *e*) de um número complexo|
|[clog10, clog10f, clog10l](../c-runtime-library/reference/clog10-clog10f-clog10l.md)|Calcular o logaritmo de base 10 de um número complexo|

## <a name="power-and-absolute-value-functions"></a>Funções potência e valor absoluto

|Função|Descrição|
|-|-|
|[cabs, cabsf, cabsl](../c-runtime-library/reference/cabs-cabsf-cabsl.md)|Calcular o valor absoluto complexo (também chamado de norma, módulo ou magnitude) de um número complexo|
|[cpow, cpowf, cpowl](../c-runtime-library/reference/cpow-cpowf-cpowl.md)|Calcular a função potência complexa x<sup>y</sup>|
|[csqrt, csqrtf, csqrtl](../c-runtime-library/reference/csqrt-csqrtf-csqrtl.md)|Calcular a raiz quadrada complexa de um número complexo|

## <a name="manipulation-functions"></a>Funções de manipulação

|Função|Descrição|
|-|-|
|[_Cbuild, _FCbuild, _LCbuild](../c-runtime-library/reference/cbuild-fcbuild-lcbuild.md)|Elaborar um número complexo de partes reais e imaginárias|
|[carg, cargf, cargl](../c-runtime-library/reference/carg-cargf-cargl.md)|Calcular o argumento (também chamado de ângulo de fase) de um número complexo|
|[cimag, cimagf, cimagl](../c-runtime-library/reference/cimag-cimagf-cimagl.md)|Calcular a parte imaginária de um número complexo|
|[conj, conjf, conjl](../c-runtime-library/reference/conj-conjf-conjl.md)|Calcular o conjugado complexo de um número complexo|
|[cproj, cprojf, cprojl](../c-runtime-library/reference/cproj-cprojf-cprojl.md)|Calcular uma projeção de um número complexo na esfera de Reimann|
|[creal, crealf, creall](../c-runtime-library/reference/creal-crealf-creall.md)|Calcular a parte real de um número complexo|
|[norm, normf, norml](../c-runtime-library/reference/norm-normf-norml1.md)|Calcular a magnitude quadrada de um número complexo|

## <a name="operation-functions"></a>Funções de operação

Uma vez que os números complexos não são um tipo nativo no compilador da Microsoft, os operadores aritméticos padrão não são definidos em tipos complexos. Para sua conveniência, essas funções da biblioteca de funções matemáticas complexas são fornecidas para habilitar a manipulação limitada de números complexos no código do usuário:

|Função|Descrição|
|-|-|
|[_Cmulcc, _FCmulcc, _LCmulcc](../c-runtime-library/reference/cmulcc-fcmulcc-lcmulcc.md)|Multiplicar dois números complexos|
|[_Cmulcr, _FCmulcr, _LCmulcr](../c-runtime-library/reference/cmulcr-fcmulcr-lcmulcr.md)|Multiplicar um número complexo e um número de ponto flutuante|

## <a name="see-also"></a>Consulte também

[Rotinas de tempo de execução C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
