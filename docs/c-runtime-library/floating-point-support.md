---
title: Suporte matemático e de ponto flutuante
ms.date: 01/31/2019
f1_keywords:
- c.math
helpviewer_keywords:
- floating-point numbers, math routines
- math routines
- floating-point numbers
ms.assetid: e4fcaf69-5c8e-4854-a9bb-1f412042131e
ms.openlocfilehash: 1d03333dee12989af5897c34ba96484930a39673
ms.sourcegitcommit: e98671a4f741b69d6277da02e6b4c9b1fd3c0ae5
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/04/2019
ms.locfileid: "55703123"
---
# <a name="math-and-floating-point-support"></a>Suporte matemático e de ponto flutuante

A biblioteca em UCRT (Tempo de Execução C Universal) fornece muitas funções de biblioteca de matemática de ponto flutuante e integral, incluindo todas as que são exigidas pelo ISO C99. As funções de ponto flutuante são implementadas para equilibrar o desempenho com exatidão. Uma vez que produzir o resultado arredondado corretamente pode ter um custo proibitivo, essas funções foram criadas para produzir de forma eficiente um resultado próximo ao resultado arredondado corretamente. Na maioria dos casos, o resultado produzido está dentro de +/-1 ulp do resultado arredondado corretamente, embora possa haver casos em que a imprecisão é maior.

Muitas das funções da biblioteca de matemática de ponto flutuante têm implementações diferentes para diferentes arquiteturas de CPU. Por exemplo, o CRT x86 de 32 bits pode ter uma implementação diferente do CRT x64 de 64 bits. Além disso, algumas das funções podem ter várias implementações para uma determinada arquitetura de CPU. A implementação mais eficiente é selecionada dinamicamente em tempo de execução dependendo dos conjuntos de instruções com suporte da CPU. Por exemplo, no CRT x86 de 32 bits, algumas funções têm uma implementação x87 e uma implementação SSE2. Quando executado em uma CPU com suporte para SSE2, é usada a implementação SSE2 mais rápida. Quando executado em uma CPU sem suporte para SSE2, é usada a implementação x87 mais lenta. Uma vez que diferentes implementações das funções da biblioteca de matemática podem usar diferentes instruções de CPU e diferentes algoritmos para produzir seus resultados, as funções podem produzir resultados diferentes entre as CPUs. Na maioria dos casos, os resultados são dentro de +/-1 ulp do resultado arredondado corretamente, mas os resultados reais podem variar entre CPUs.

Versões de 16 bits anteriores do Microsoft C/C++ e do Microsoft Visual C++ davam suporte ao tipo **long double** como um tipo de dados de ponto flutuante com precisão de 80 bits. Nas versões posteriores do Visual C++, o tipo de dados **long double** é um tipo de dados de ponto flutuante com precisão de 64 bits idêntico ao tipo **double**. O compilador trata **long double** e **double** como tipos diferentes, mas as funções **long double** são idênticas às suas contrapartes de **double**. O CRT fornece versões de **long double** das funções matemáticas para compatibilidade com o código-fonte da ISO C99, mas observe que a representação binária pode ser diferente de outros compiladores.

## <a name="supported-math-and-floating-point-routines"></a>Rotinas matemáticas de ponto flutuante compatíveis

|Rotina|Use|
|-|-|
[abs, labs, llabs, _abs64](../c-runtime-library/reference/abs-labs-llabs-abs64.md)|Calcula o valor absoluto de um tipo inteiro
[acos, acosf, acosl](../c-runtime-library/reference/acos-acosf-acosl.md)|Calcula o arco cosseno
[acosh, acoshf, acoshl](../c-runtime-library/reference/acosh-acoshf-acoshl.md)|Calcula o arco cosseno hiperbólico
[asin, asinf, asinl](../c-runtime-library/reference/asin-asinf-asinl.md)|Calcula o arco seno
[asinh, asinhf, asinhl](../c-runtime-library/reference/asinh-asinhf-asinhl.md)|Calcula o arco seno hiperbólico
[atan, atanf, atanl, atan2, atan2f, atan2l](../c-runtime-library/reference/atan-atanf-atanl-atan2-atan2f-atan2l.md)|Calcula o arco tangente
[atanh, atanhf, atanhl](../c-runtime-library/reference/atanh-atanhf-atanhl.md)|Calcula o arco tangente hiperbólico
[_atodbl, _atodbl_l](../c-runtime-library/reference/atodbl-atodbl-l-atoldbl-atoldbl-l-atoflt-atoflt-l.md)|Converte uma cadeia de caracteres específica da localidade em um **double**
[atof, _atof_l](../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)|Converte uma cadeia de caracteres em um inteiro **double**
[_atoflt, _atoflt_l, _atoldbl, _atoldbl_l](../c-runtime-library/reference/atodbl-atodbl-l-atoldbl-atoldbl-l-atoflt-atoflt-l.md)|Converte uma cadeia de caracteres específica da localidade em um **float** ou **long double**
[cbrt, cbrtf, cbrtl](../c-runtime-library/reference/cbrt-cbrtf-cbrtl.md)|Calcula a raiz cúbica
[ceil, ceilf, ceill](../c-runtime-library/reference/ceil-ceilf-ceill.md)|Calcula o limite
[_chgsign, _chgsignf, _chgsignl](../c-runtime-library/reference/chgsign-chgsignf-chgsignl.md)|Calcula o inverso de aditivo
[_clear87, _clearfp](../c-runtime-library/reference/clear87-clearfp.md)|Obtém e limpa o registro de status de ponto flutuante
[_control87, \__control87_2, _controlfp](../c-runtime-library/reference/control87-controlfp-control87-2.md)|Obtém e define a palavra de controle de ponto flutuante
[_controlfp_s](../c-runtime-library/reference/controlfp-s.md)|Versão segura de **_controlfp**
[copysign, copysignf, copysignl, _copysign, _copysignf, _copysignl](../c-runtime-library/reference/copysign-copysignf-copysignl-copysign-copysignf-copysignl.md)|Retorna um valor que tem a magnitude de um argumento e o sinal de outro
[cos, cosf, cosl](../c-runtime-library/reference/cos-cosf-cosl.md)|Calcula o seno
[cosh, coshf, coshl](../c-runtime-library/reference/cosh-coshf-coshl.md)|Calcula o seno hiperbólico
[div, ldiv, lldiv](../c-runtime-library/reference/div.md)|Calcula o quociente e o resto de dois valores inteiros
[_ecvt](../c-runtime-library/reference/ecvt.md), [ecvt](../c-runtime-library/reference/posix-ecvt.md)|Converte um **double** em uma cadeia de caracteres
[_ecvt_s](../c-runtime-library/reference/ecvt-s.md)|Versão segura de **_ecvt**
[erf, erff, erfl](../c-runtime-library/reference/erf-erff-erfl-erfc-erfcf-erfcl.md)|Calcula a função de erro
[erfc, erfcf, erfcl](../c-runtime-library/reference/erf-erff-erfl-erfc-erfcf-erfcl.md)|Calcula a função de erro complementar
[exp, expf, expl](../c-runtime-library/reference/exp-expf.md)|Calcula o *e*<sup>x</sup> exponencial
[exp2, exp2f, exp2l](../c-runtime-library/reference/exp2-exp2f-exp2l.md)|Calcula o 2<sup>x</sup> exponencial
[expm1, expm1f, expm1l](../c-runtime-library/reference/expm1-expm1f-expm1l.md)|Calcula o *e*<sup>x</sup>-1
[fabs, fabsf, fabsl](../c-runtime-library/reference/fabs-fabsf-fabsl.md)|Calcula o valor absoluto de um tipo de ponto flutuante
[_fcvt](../c-runtime-library/reference/fcvt.md), [fcvt](../c-runtime-library/reference/posix-fcvt.md)|Converte um número de ponto flutuante em uma cadeia de caracteres
[_fcvt_s](../c-runtime-library/reference/fcvt-s.md)|Versão segura de **_fcvt**
[fdim, fdimf, fdiml](../c-runtime-library/reference/fdim-fdimf-fdiml.md)|Determina a diferença positiva entre dois valores
[feclearexcept](../c-runtime-library/reference/feclearexcept1.md)|Limpa as exceções de ponto flutuante especificadas
[fegetenv](../c-runtime-library/reference/fegetenv1.md)|Armazena o ambiente atual de ponto flutuante
[fegetexceptflag](../c-runtime-library/reference/fegetexceptflag2.md)|Gera o status de exceção de ponto flutuante especificado
[fegetround](../c-runtime-library/reference/fegetround-fesetround2.md)|Obtém o modo de arredondamento de ponto flutuante
[feholdexcept](../c-runtime-library/reference/feholdexcept2.md)|Define o modo de exceção de ponto flutuante contínuo
[feraiseexcept](../c-runtime-library/reference/feraiseexcept.md)|Aciona as exceções de ponto flutuante especificadas
[fesetenv](../c-runtime-library/reference/fesetenv1.md)|Define o ambiente atual de ponto flutuante
[fesetexceptflag](../c-runtime-library/reference/fesetexceptflag2.md)|Define os sinalizadores do status de ponto flutuante especificados
[fesetround](../c-runtime-library/reference/fegetround-fesetround2.md)|Define o modo de arredondamento de ponto flutuante especificado
[fetestexcept](../c-runtime-library/reference/fetestexcept1.md)|Determina quais sinalizadores do status de exceção de ponto flutuante são definidos
[feupdateenv](../c-runtime-library/reference/feupdateenv.md)|Restaura um ambiente de ponto flutuante, em seguida, aciona exceções anteriores
[floor, floorf, floorl](../c-runtime-library/reference/floor-floorf-floorl.md)|Calcula a base
[fma, fmaf, fmal](../c-runtime-library/reference/fma-fmaf-fmal.md)|Calcula uma adição múltipla mesclada
[fmax, fmaxf, fmaxl](../c-runtime-library/reference/fmax-fmaxf-fmaxl.md)|Calcula o máximo de argumentos
[fmin, fminf, fminl](../c-runtime-library/reference/fmin-fminf-fminl.md)|Calcula o mínimo de argumentos
[fmod, fmodf, fmodl](../c-runtime-library/reference/fmod-fmodf.md)|Calcula o restante do ponto flutuante
[_fpclass, _fpclassf](../c-runtime-library/reference/fpclass-fpclassf.md)|Retorna a classificação de um valor do ponto flutuante
[fpclassify](../c-runtime-library/reference/fpclassify.md)|Retorna a classificação de um valor do ponto flutuante
[_fpieee_flt](../c-runtime-library/reference/fpieee-flt.md)|Define um manipulador para exceções de ponto flutuante
[_fpreset](../c-runtime-library/reference/fpreset.md)|Redefine o ambiente de ponto flutuante
[frexp, frexpf, frexpl](../c-runtime-library/reference/frexp.md)|Obtém a mantissa e o expoente de um número de ponto flutuante
[_gcvt](../c-runtime-library/reference/gcvt.md), [gcvt](../c-runtime-library/reference/posix-gcvt.md)|Converte um número de ponto flutuante em uma cadeia de caracteres
[_gcvt_s](../c-runtime-library/reference/gcvt-s.md)|Versão segura de **_gcvt**
[_get_FMA3_enable, _set_FMA3_enable](../c-runtime-library/reference/get-fma3-enable-set-fma3-enable.md)|Obtém ou define um sinalizador para o uso de instruções FMA3 em x64
[hypot, hypotf, hypotl, _hypot, _hypotf, _hypotl](../c-runtime-library/reference/hypot-hypotf-hypotl-hypot-hypotf-hypotl.md)|Calcula a hipotenusa
[ilogb, ilogbf, ilogbl](../c-runtime-library/reference/ilogb-ilogbf-ilogbl2.md)|Calcula o expoente de base 2 do inteiro
[imaxabs](../c-runtime-library/reference/imaxabs.md)|Calcula o valor absoluto de um tipo inteiro
[imaxdiv](../c-runtime-library/reference/imaxdiv.md)|Calcula o quociente e o resto de dois valores inteiros
[isfinite, _finite, _finitef](../c-runtime-library/reference/finite-finitef.md)|Determina se um valor é finito
[isgreater, isgreaterequal, isless, islessequal, islessgreater, isunordered](../c-runtime-library/reference/floating-point-ordering.md)|Compara a ordem dos dois valores de ponto flutuante
[isinf](../c-runtime-library/reference/isinf.md)|Determina se um valor de ponto flutuante é infinito
[isnan, _isnan, _isnanf](../c-runtime-library/reference/isnan-isnan-isnanf.md)|Testa um valor de ponto flutuante para NaN
[isnormal](../c-runtime-library/reference/isnormal.md)|Testa se um valor de ponto flutuante é finito e não subnormal
[_j0, _j1, _jn](../c-runtime-library/reference/bessel-functions-j0-j1-jn-y0-y1-yn.md)|Calcula a função Bessel
[ldexp, ldexpf, ldexpl](../c-runtime-library/reference/ldexp.md)|Calcula x*2<sup>n</sup>
[lgamma, lgammaf, lgammal](../c-runtime-library/reference/lgamma-lgammaf-lgammal.md)|Calcula o logaritmo natural do valor absoluto da função gama
[llrint, llrintf, llrintl](../c-runtime-library/reference/lrint-lrintf-lrintl-llrint-llrintf-llrintl.md)|Arredonda um valor de ponto flutuante para o valor **long long** mais próximo
[llround, llroundf, llroundl](../c-runtime-library/reference/lround-lroundf-lroundl-llround-llroundf-llroundl.md)|Arredonda um valor de ponto flutuante para o valor **long long** mais próximo
[log, logf, logl, log10, log10f, log10l](../c-runtime-library/reference/log-logf-log10-log10f.md)|Calcular o logaritmo natural ou de base 10
[log1p, log1pf, log1pl](../c-runtime-library/reference/log1p-log1pf-log1pl2.md)|Calcula o logaritmo natural de 1+x
[log2, log2f, log2l](../c-runtime-library/reference/log2-log2f-log2l.md)|Calcula o logaritmo de base 2
[logb, logbf, logbl, _logb, _logbf](../c-runtime-library/reference/logb-logbf-logbl-logb-logbf.md)|Retorna o expoente de um valor de ponto flutuante
[lrint, lrintf, lrintl](../c-runtime-library/reference/lrint-lrintf-lrintl-llrint-llrintf-llrintl.md)|Arredonda um valor de ponto flutuante para o valor **long** mais próximo
[_lrotl, _lrotr](../c-runtime-library/reference/lrotl-lrotr.md)|Gira um valor inteiro para a esquerda ou direita
[lround, lroundf, lroundl](../c-runtime-library/reference/lround-lroundf-lroundl-llround-llroundf-llroundl.md)|Arredonda um valor de ponto flutuante para o valor **long** mais próximo
[_matherr](../c-runtime-library/reference/matherr.md)|O manipulador de erro de matemática padrão
[__max](../c-runtime-library/reference/max.md)|Macro que retorna o maior de dois valores
[__min](../c-runtime-library/reference/min.md)|Macro que retorna o menor de dois valores
[modf, modff, modfl](../c-runtime-library/reference/modf-modff-modfl.md)|Divide um valor de ponto flutuante em partes inteiras e fracionárias
[nan, nanf, nanl](../c-runtime-library/reference/nan-nanf-nanl.md)|Retorna um valor NaN silencioso
[nearbyint, nearbyintf, nearbyintl](../c-runtime-library/reference/nearbyint-nearbyintf-nearbyintl1.md)|Retorna o valor arredondado
[nextafter, nextafterf, nextafterl, _nextafter, _nextafterf](../c-runtime-library/reference/nextafter-functions.md)|Retorna o próximo valor de ponto flutuante representável
[nexttoward, nexttowardf, nexttowardl](../c-runtime-library/reference/nextafter-functions.md)|Retorna o próximo valor de ponto flutuante representável
[pow, powf, powl](../c-runtime-library/reference/pow-powf-powl.md)|Retorna o valor de *x*<sup>*y*</sup>
[remainder, remainderf, remainderl](../c-runtime-library/reference/remainder-remainderf-remainderl.md)|Calcula o restante do quociente de dois valores de ponto flutuante
[remquo, remquof, remquol](../c-runtime-library/reference/remquo-remquof-remquol.md)|Calcula o resto de dois valores inteiros
[rint, rintf, rintl](../c-runtime-library/reference/rint-rintf-rintl.md)|Arredonda um valor de ponto flutuante
[_rotl, _rotl64, _rotr, _rotr64](../c-runtime-library/reference/rotl-rotl64-rotr-rotr64.md)|Gira bits em tipos de inteiros
[round, roundf, roundl](../c-runtime-library/reference/round-roundf-roundl.md)|Arredonda um valor de ponto flutuante
[_scalb, _scalbf](../c-runtime-library/reference/scalb.md)|Dimensiona o argumento por uma potência de 2
[scalbn, scalbnf, scalbnl, scalbln, scalblnf, scalblnl](../c-runtime-library/reference/scalbn-scalbnf-scalbnl-scalbln-scalblnf-scalblnl.md)|Multiplica um número de ponto flutuante por uma potência integral de **FLT_RADIX**
[_set_controlfp](../c-runtime-library/reference/set-controlfp.md)|Define a palavra de controle de ponto flutuante
[_set_SSE2_enable](../c-runtime-library/reference/set-sse2-enable.md)|Habilita ou desabilita instruções SSE2
[signbit](../c-runtime-library/reference/signbit.md)|Testa o bit de sinal de um valor de ponto flutuante
[sin, sinf, sinl](../c-runtime-library/reference/sin-sinf-sinl.md)|Calcula o seno
[sinh, sinhf, sinhl](../c-runtime-library/reference/sinh-sinhf-sinhl.md)|Calcula o seno hiperbólico
[sqrt, sqrtf, sqrtl](../c-runtime-library/reference/sqrt-sqrtf-sqrtl.md)|Calcula a raiz quadrada
[_status87, _statusfp, _statusfp2](../c-runtime-library/reference/status87-statusfp-statusfp2.md)|Define a palavra de status de ponto flutuante
[strtof, _strtof_l](../c-runtime-library/reference/strtof-strtof-l-wcstof-wcstof-l.md)|Converte uma cadeia de caracteres em um **float**
[strtold, _strtold_l](../c-runtime-library/reference/strtold-strtold-l-wcstold-wcstold-l.md)|Converte uma cadeia de caracteres em um **long** **double**
[tan, tanf, tanl](../c-runtime-library/reference/tan-tanf-tanl.md)|Calcula a tangente
[tanh, tanhf, tanhl](../c-runtime-library/reference/tanh-tanhf-tanhl.md)|Calcula a tangente hiperbólica
[tgamma, tgammaf, tgammal](../c-runtime-library/reference/tgamma-tgammaf-tgammal.md)|Calcula a função gama
[trunc, truncf, truncl](../c-runtime-library/reference/trunc-truncf-truncl.md)|Trunca a parte fracionária
[_wtof, _wtof_l](../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)|Converte uma cadeia de caracteres larga em um **double**
[_y0, _y1, _yn](../c-runtime-library/reference/bessel-functions-j0-j1-jn-y0-y1-yn.md)|Calcula a função Bessel

## <a name="see-also"></a>Consulte também

[Rotinas de tempo de execução C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)<br/>
[Primitivos de ponto flutuante](../c-runtime-library/reference/floating-point-primitives.md)<br/>
