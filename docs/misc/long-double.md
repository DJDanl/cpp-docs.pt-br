---
title: "Duplo longo | Microsoft Docs"
ms.custom: ""
ms.date: "11/17/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "c.types"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "10 bytes duplos longos"
  - "Windows de 16 bits"
  - "Windows de 32 bits"
  - "8 bytes duplos longos"
  - "precisão de 80 bits"
  - "precisão de 80 bits"
  - "8 bytes duplos longos"
  - "duplo longo"
ms.assetid: bb581e20-b5c2-4079-8ee8-ac6739a37852
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Duplo longo
As versões de 16 bits anteriores do Microsoft C\/C\+\+ e Microsoft Visual C\+\+ com suporte `long double`, tipo de dados de precisão de 80 bits.  No Win32 que programas, no entanto, os mapas a `double`, tipo de dados de 64 bits do tipo de dados de `long double` de precisão.  A biblioteca de tempo de execução Microsoft fornece versões de `long double` das funções matemáticas somente para compatibilidade com versões anteriores.  Os protótipos de função de `long double` são idênticos aos protótipos para suas contrapartes de `double` , exceto que o tipo de dados de `long``double` substitui o tipo de dados de `double` .  As versões de `long double` dessas funções não devem ser usadas no novo código.  
  
### Funções duplas e suas contrapartes duplas demoradas  
  
|Função|Double longo<br /><br /> contrapartes|Função|Double longo<br /><br /> contrapartes|  
|------------|-----------------------------------|------------|-----------------------------------|  
|[acos](../c-runtime-library/reference/acos-acosf-acosl.md)|`acosl`|[frexp](../c-runtime-library/reference/frexp.md)|`frexpl`|  
|[asin](../c-runtime-library/reference/asin-asinf-asinl.md)|`asinl`|[\_hypot](../c-runtime-library/reference/hypot-hypotf-hypotl-hypot-hypotf-hypotl.md)|`_hypotl`|  
|[atan](../c-runtime-library/reference/atan-atanf-atanl-atan2-atan2f-atan2l.md)|`atanl`|[ldexp](../c-runtime-library/reference/ldexp.md)|`ldexpl`|  
|[atan2](../c-runtime-library/reference/atan-atanf-atanl-atan2-atan2f-atan2l.md)|`atan2l`|[log](../Topic/log,%20logf,%20log10,%20log10f.md)|`logl`|  
|[atof](../c-runtime-library/reference/atof-atof-l-wtof-wtof-l.md)|`_atold`|[log10](../Topic/log,%20logf,%20log10,%20log10f.md)|`log10l`|  
|[Funções de Bessel j0, j1, jn](../misc/bessel-functions-j0-j1-jn.md)|`j0l, j1l, jnl`|[\_matherr](../c-runtime-library/reference/matherr.md)|`_matherrl`|  
|[Funções de Bessel YO, y1, yn](../Topic/Bessel%20Functions:%20_y0,%20_y1,%20_yn.md)|`y0l, y1l, ynl`|[modf](../c-runtime-library/reference/modf-modff-modfl.md)|`modfl`|  
|[\_cabs](../Topic/_cabs.md)|`_cabsl`|[prisioneiro de guerra](../Topic/pow,%20powf,%20powl.md)|`powl`|  
|[ceil](../c-runtime-library/reference/ceil-ceilf-ceill.md)|`ceill`|[sin](../c-runtime-library/reference/sin-sinf-sinl-sinh-sinhf-sinhl.md)|`sinl`|  
|[cos](../c-runtime-library/reference/cos-cosf-cosl-cosh-coshf-coshl.md)|`cosl`|[sinh](../c-runtime-library/reference/sin-sinf-sinl-sinh-sinhf-sinhl.md)|`sinhl`|  
|[moca](../c-runtime-library/reference/cos-cosf-cosl-cosh-coshf-coshl.md)|`coshl`|[SQRT](../c-runtime-library/reference/sqrt-sqrtf-sqrtl.md)|`sqrtl`|  
|[EXP](../c-runtime-library/reference/exp-expf.md)|`expl`|[strtod](../c-runtime-library/reference/strtod-strtod-l-wcstod-wcstod-l.md)|`_strtold`|  
|[fabs](../c-runtime-library/reference/fabs-fabsf-fabsl.md)|`fabsl`|[tan](../c-runtime-library/reference/tan-tanf-tanl-tanh-tanhf-tanhl.md)|`tanl`|  
|[floor](../c-runtime-library/reference/floor-floorf-floorl.md)|`floorl`|[tanh](../c-runtime-library/reference/tan-tanf-tanl-tanh-tanhf-tanhl.md)|`tanhl`|  
|[fmod](../Topic/fmod,%20fmodf.md)|`fmodl`|||  
  
## Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)