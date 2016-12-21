---
title: "Suporte de ponto flutuante | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "c.math"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "números de ponto flutuante"
  - "números de ponto flutuante, rotinas de matemática"
  - "rotinas de matemática"
ms.assetid: e4fcaf69-5c8e-4854-a9bb-1f412042131e
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Suporte de ponto flutuante
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Biblioteca do Microsoft C Runtime \(CRT\) fornece muitas funções de biblioteca de matemática de ponto, incluindo todos aqueles exigido pela ISO C99 de flutuante. Essas funções são implementadas para equilibrar o desempenho com a correção. Como produzir o resultado arredondado corretamente pode ser proibitivamente cara, essas funções são projetadas para produzir uma aproximação ao resultado arredondado corretamente com eficiência. Na maioria dos casos, o resultado produzido é dentro de \+ \/\-1 ulp do resultado arredondado corretamente, embora possa haver casos onde há imprecisão maior.  
  
 Muitas das flutuante ponto, as funções de biblioteca de matemática tem implementações diferentes para diferentes arquiteturas de CPU. Por exemplo, x86 de 32 bits CRT pode ter uma implementação diferente de 64 bits x64 CRT. Além disso, algumas das funções podem ter várias implementações para uma determinada arquitetura de CPU. A implementação mais eficiente é selecionada dinamicamente em tempo de execução dependendo os conjuntos de instruções com suporte pela CPU. Por exemplo, em x86 de 32 bits CRT, algumas funções possuem dois x87 uma implementação e uma implementação de SSE2. Quando executado em uma CPU que dá suporte a SSE2, é usada a SSE2 uma implementação mais rápida. Quando executado em uma CPU que não suportam SSE2, a implementação é usada de x87 mais lento. Como diferentes implementações das funções de biblioteca de matemática podem usar diferentes instruções de CPU e algoritmos diferentes para produzir seus resultados, as funções podem produzir resultados diferentes entre CPUs. Na maioria dos casos, os resultados são dentro de \+ \/\-1 ulp do resultado arredondado corretamente, mas os resultados reais podem variar entre CPUs.  
  
 Versões anteriores de 16 bits do Microsoft C\/C\+\+ e Microsoft Visual C\+\+ tem suporte a `long double` tipo como um tipo de dados de ponto flutuante de precisão de 80 bits. Em versões posteriores do Visual C\+\+, o `long double` tipo de dados é um tipo de dados de ponto flutuante de precisão de 64 bits idêntico do `double` tipo. O compilador trata `long double` e `double` como tipos distintos, mas o `long double` funções são idênticas às suas `double` correspondentes. Fornece o CRT `long double` versões das funções matemáticas para ISO C99 compatibilidade do código de origem, mas observe que a representação binária pode ser diferente de outros compiladores.  
  
 A CRT oferece suporte a essas funções de ponto de flutuante:  
  
 [abs, \_abs64](../c-runtime-library/reference/abs-labs-llabs-abs64.md)  
  
 [acos, acosf, acosl](../c-runtime-library/reference/acos-acosf-acosl.md)  
  
 [acosh, acoshf, acoshl](../c-runtime-library/reference/acosh-acoshf-acoshl.md)  
  
 [asin, asinf, asinl](../c-runtime-library/reference/asin-asinf-asinl.md)  
  
 [asinh, asinhf, asinhl](../c-runtime-library/reference/asinh-asinhf-asinhl.md)  
  
 [atan, atanf, atanl, atan2, atan2f, atan2l](../c-runtime-library/reference/atan-atanf-atanl-atan2-atan2f-atan2l.md)  
  
 [atanh, atanhf, atanhl](../Topic/atanh,%20atanhf,%20atanhl.md)  
  
 [atodbl, atodbl\_l](../c-runtime-library/reference/atodbl-atodbl-l-atoldbl-atoldbl-l-atoflt-atoflt-l.md)  
  
 [atof, atof\_l](../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)  
  
 [atoflt, atoflt\_l, atoldbl, atoldbl\_l](../c-runtime-library/reference/atodbl-atodbl-l-atoldbl-atoldbl-l-atoflt-atoflt-l.md)  
  
 [cbrt, cbrtf, cbrtl](../c-runtime-library/reference/cbrt-cbrtf-cbrtl.md)  
  
 [ceil, ceilf, ceill](../c-runtime-library/reference/ceil-ceilf-ceill.md)  
  
 [\_chgsign, \_chgsignf, \_chgsignl](../c-runtime-library/reference/chgsign-chgsignf-chgsignl.md)  
  
 [\_clear87, \_clearfp](../c-runtime-library/reference/clear87-clearfp.md)  
  
 [compl](../c-runtime-library/reference/compl.md)  
  
 [Conj, conjf, conjl](../c-runtime-library/reference/conj-conjf-conjl.md)  
  
 [control87 \_\_control87\_2, controlfp](../Topic/_control87,%20_controlfp,%20__control87_2.md)  
  
 [\_controlfp\_s](../c-runtime-library/reference/controlfp-s.md)  
  
 [copysign, copysignf, copysignl, \_copysign, \_copysignf, \_copysignl](../c-runtime-library/reference/copysign-copysignf-copysignl-copysign-copysignf-copysignl.md)  
  
 [CoS, cosf, cosl](../c-runtime-library/reference/cos-cosf-cosl-cosh-coshf-coshl.md)  
  
 [COSH, coshf, coshl](../c-runtime-library/reference/cos-cosf-cosl-cosh-coshf-coshl.md)  
  
 [div](../c-runtime-library/reference/div.md)  
  
 [\_ecvt](../c-runtime-library/reference/ecvt.md)  
  
 [ecvt](../c-runtime-library/reference/posix-ecvt.md)  
  
 [\_ecvt\_s](../Topic/_ecvt_s.md)  
  
 [erf, erff, erfl, erfc, erfcf, erfcl](../c-runtime-library/reference/erf-erff-erfl-erfc-erfcf-erfcl.md)  
  
 [exp, expf](../c-runtime-library/reference/exp-expf.md)  
  
 [exp2, exp2f, exp2l](../c-runtime-library/reference/exp2-exp2f-exp2l.md)  
  
 [expm1, expm1f, expm1l](../c-runtime-library/reference/expm1-expm1f-expm1l.md)  
  
 [fabs, fabsf](../c-runtime-library/reference/fabs-fabsf-fabsl.md)  
  
 [\_fcvt](../Topic/_fcvt.md)  
  
 [fcvt](../Topic/fcvt.md)  
  
 [\_fcvt\_s](../c-runtime-library/reference/fcvt-s.md)  
  
 [fdim, fdimf, fdiml](../c-runtime-library/reference/fdim-fdimf-fdiml.md)  
  
 [feclearexcept](../c-runtime-library/reference/feclearexcept1.md)  
  
 [fegetenv](../c-runtime-library/reference/fegetenv1.md)  
  
 [fegetexceptflag](../Topic/fegetexceptflag2.md)  
  
 [fegetround](../Topic/fegetround,%20fesetround2.md)  
  
 [feholdexcept](../c-runtime-library/reference/feholdexcept2.md)  
  
 [feraiseexcept](../c-runtime-library/reference/feraiseexcept.md)  
  
 [ferror](../c-runtime-library/reference/ferror.md)  
  
 [fesetenv](../c-runtime-library/reference/fesetenv1.md)  
  
 [fesetexceptflag](../Topic/fesetexceptflag2.md)  
  
 [fesetround](../Topic/fegetround,%20fesetround2.md)  
  
 [fetestexcept](../Topic/fetestexcept1.md)  
  
 [feupdateenv](../Topic/feupdateenv.md)  
  
 [Finitas, \_finitef](../c-runtime-library/reference/finite-finitef.md)  
  
 [floor, floorf, floorl](../c-runtime-library/reference/floor-floorf-floorl.md)  
  
 [FMA, fmaf, fmal](../c-runtime-library/reference/fma-fmaf-fmal.md)  
  
 [fmax, fmaxf, fmaxl](../c-runtime-library/reference/fmax-fmaxf-fmaxl.md)  
  
 [fmin, fminf, fminl](../c-runtime-library/reference/fmin-fminf-fminl2.md)  
  
 [fmod, fmodf](../Topic/fmod,%20fmodf.md)  
  
 [fpclass, \_fpclassf](../c-runtime-library/reference/fpclass-fpclassf.md)  
  
 [fpclassify](../Topic/fpclassify.md)  
  
 [\_fpieee\_flt](../c-runtime-library/reference/fpieee-flt.md)  
  
 [\_fpreset](../c-runtime-library/reference/fpreset.md)  
  
 [frexp](../c-runtime-library/reference/frexp.md)  
  
 [gcvt](../c-runtime-library/reference/posix-gcvt.md)  
  
 [\_gcvt](../c-runtime-library/reference/gcvt.md)  
  
 [\_gcvt\_s](../c-runtime-library/reference/gcvt-s.md)  
  
 [hypot, hypotf, hypotl, \_hypot, \_hypotf, \_hypotl](../c-runtime-library/reference/hypot-hypotf-hypotl-hypot-hypotf-hypotl.md)  
  
 [ilogb, ilogbf, ilogbl](../c-runtime-library/reference/ilogb-ilogbf-ilogbl2.md)  
  
 [imaxabs](../Topic/imaxabs.md)  
  
 [imaxdiv](../c-runtime-library/reference/imaxdiv.md)  
  
 [isNaN isNaN, \_isnanf](../c-runtime-library/reference/isnan-isnan-isnanf.md)  
  
 [j0, J1, Jn](../c-runtime-library/reference/bessel-functions-j0-j1-jn-y0-y1-yn.md)  
  
 [labs, llabs](../c-runtime-library/reference/abs-labs-llabs-abs64.md)  
  
 [ldexp](../c-runtime-library/reference/ldexp.md)  
  
 [ldiv, lldiv](../Topic/ldiv,%20lldiv.md)  
  
 [lgamma, lgammaf, lgammal](../c-runtime-library/reference/lgamma-lgammaf-lgammal.md)  
  
 [llrint, llrintf, llrintl](../Topic/lrint,%20lrintf,%20lrintl,%20llrint,%20llrintf,%20llrintl.md)  
  
 [llround, llroundf, llroundl](../c-runtime-library/reference/lround-lroundf-lroundl-llround-llroundf-llroundl.md)  
  
 [log, logf, log10, log10f](../Topic/log,%20logf,%20log10,%20log10f.md)  
  
 [log1p, log1pf, log1pl](../Topic/log1p,%20log1pf,%20log1pl2.md)  
  
 [log2, log2f, log2l](../c-runtime-library/reference/log2-log2f-log2l.md)  
  
 [logb, logbf, logbl, \_logb, \_logbf](../c-runtime-library/reference/logb-logbf-logbl-logb-logbf.md)  
  
 [lrint, lrintf, lrintl](../Topic/lrint,%20lrintf,%20lrintl,%20llrint,%20llrintf,%20llrintl.md)  
  
 [\_lrotl, \_lrotr](../c-runtime-library/reference/lrotl-lrotr.md)  
  
 [lround, lroundf, lroundl](../c-runtime-library/reference/lround-lroundf-lroundl-llround-llroundf-llroundl.md)  
  
 [\_matherr](../c-runtime-library/reference/matherr.md)  
  
 [\_\_max](../c-runtime-library/reference/max.md)  
  
 [\_\_min](../c-runtime-library/reference/min.md)  
  
 [modf, modff](../c-runtime-library/reference/modf-modff-modfl.md)  
  
 [nan, nanf, nanl](../c-runtime-library/reference/nan-nanf-nanl.md)  
  
 [nanf](../c-runtime-library/reference/nan-nanf-nanl.md)  
  
 [nanl](../c-runtime-library/reference/nan-nanf-nanl.md)  
  
 [nearbyint, nearbyintf, nearbyintl](../c-runtime-library/reference/nearbyint-nearbyintf-nearbyintl1.md)  
  
 [nextafter, nextafterf, nextafterl, nextafter, \_nextafterf, nexttoward, nexttowardf, nexttowardl](../c-runtime-library/reference/nextafter-functions.md)  
  
 [norma, normf, norml](../Topic/norm,%20normf,%20norml1.md)  
  
 [pow, powf, powl](../Topic/pow,%20powf,%20powl.md)  
  
 [remainder, remainderf, remainderl](../c-runtime-library/reference/remainder-remainderf-remainderl.md)  
  
 [remquo, remquof, remquol](../Topic/remquo,%20remquof,%20remquol.md)  
  
 [rint, rintf, rintl](../c-runtime-library/reference/rint-rintf-rintl.md)  
  
 [\_rotl, \_rotl64, \_rotr, \_rotr64](../c-runtime-library/reference/rotl-rotl64-rotr-rotr64.md)  
  
 [round, roundf, roundl](../c-runtime-library/reference/round-roundf-roundl.md)  
  
 [\_scalb](../c-runtime-library/reference/scalb.md)  
  
 [scalbn, scalbnf, scalbnl, scalbln, scalblnf, scalblnl](../c-runtime-library/reference/scalbn-scalbnf-scalbnl-scalbln-scalblnf-scalblnl.md)  
  
 [\_set\_controlfp](../c-runtime-library/reference/set-controlfp.md)  
  
 [\_set\_SSE2\_enable](../Topic/_set_SSE2_enable.md)  
  
 [sin, sinf, sinl](../c-runtime-library/reference/sin-sinf-sinl-sinh-sinhf-sinhl.md)  
  
 [SINH, sinhf, sinhl](../c-runtime-library/reference/sin-sinf-sinl-sinh-sinhf-sinhl.md)  
  
 [sqrt, sqrtf, sqrtl](../c-runtime-library/reference/sqrt-sqrtf-sqrtl.md)  
  
 [\_status87, \_statusfp, \_statusfp2](../c-runtime-library/reference/status87-statusfp-statusfp2.md)  
  
 [strtof, strtof\_l](../c-runtime-library/reference/strtof-strtof-l-wcstof-wcstof-l.md)  
  
 [strtold, \_strtold\_l](../c-runtime-library/reference/strtold-strtold-l-wcstold-wcstold-l.md)  
  
 [tan, tanf, tanl](../c-runtime-library/reference/tan-tanf-tanl-tanh-tanhf-tanhl.md)  
  
 [TANH, tanhf, tanhl](../c-runtime-library/reference/tan-tanf-tanl-tanh-tanhf-tanhl.md)  
  
 [tgamma, tgammaf, tgammal](../c-runtime-library/reference/tgamma-tgammaf-tgammal.md)  
  
 [trunc, truncf, truncl](../c-runtime-library/reference/trunc-truncf-truncl.md)  
  
 [wtof, wtof\_l](../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)  
  
 [y0, y1, Yn](../c-runtime-library/reference/bessel-functions-j0-j1-jn-y0-y1-yn.md)  
  
## Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)