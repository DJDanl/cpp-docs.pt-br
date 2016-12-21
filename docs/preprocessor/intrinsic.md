---
title: "Intr&#237;nseco  | Microsoft Docs"
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
  - "intrinsic_CPP"
  - "vc-pragma.intrinsic"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "pragma intrínseco"
  - "pragmas, Intrínseco "
ms.assetid: 25c86ac7-ef40-47b7-a2c0-fada9c5dc3c5
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Intr&#237;nseco 
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica que as chamadas para as funções especificadas na lista de argumentos do pragma são intrínsecas.  
  
## Sintaxe  
  
```  
  
#pragma intrinsic( function1 [, function2, ...] )  
```  
  
## Comentários  
 O pragma **intrinsic** diz ao compilador que uma função tem um comportamento conhecido.  O compilador pode chamar a função e não substituir a chamada de função pelas instruções embutidas, se isso resultar em um melhor desempenho.  
  
 As funções da biblioteca com formas intrínsecas estão listadas abaixo.  Após um pragma **intrinsic** ser considerado, ele entra em vigor na primeira definição de função que contém uma função intrínseca especificada.  O efeito continua até o final do arquivo de origem ou até o aparecimento de um pragma **function** que especifica a mesma função intrínseca.  O pragma **intrinsic** pode ser usado apenas para uma definição de função — no nível global.  
  
 As seguintes funções têm formas intrínsecas e as formas intrínsecas são usadas quando você especifica [\/Oi](../Topic/-Oi%20\(Generate%20Intrinsic%20Functions\).md):  
  
|||||  
|-|-|-|-|  
|[\_disable](../intrinsics/disable.md)|[\_outp](../Topic/_outp,%20_outpw,%20_outpd.md)|[fabs](../c-runtime-library/reference/fabs-fabsf-fabsl.md)|[strcmp](../Topic/strcmp,%20wcscmp,%20_mbscmp.md)|  
|[\_enable](../intrinsics/enable.md)|[\_outpw](../Topic/_outp,%20_outpw,%20_outpd.md)|[labs](../misc/labs-llabs.md)|[strcpy](../c-runtime-library/reference/strcpy-wcscpy-mbscpy.md)|  
|[\_inp](../c-runtime-library/inp-inpw-inpd.md)|[\_rotl](../c-runtime-library/reference/rotl-rotl64-rotr-rotr64.md)|[memcmp](../c-runtime-library/reference/memcmp-wmemcmp.md)|[strlen](../Topic/strlen,%20wcslen,%20_mbslen,%20_mbslen_l,%20_mbstrlen,%20_mbstrlen_l.md)|  
|[\_inpw](../c-runtime-library/inp-inpw-inpd.md)|[\_rotr](../c-runtime-library/reference/rotl-rotl64-rotr-rotr64.md)|[memcpy](../c-runtime-library/reference/memcpy-wmemcpy.md)||  
|[\_lrotl](../c-runtime-library/reference/lrotl-lrotr.md)|[\_strset](../c-runtime-library/reference/strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)|[memset](../c-runtime-library/reference/memset-wmemset.md)||  
|[\_lrotr](../c-runtime-library/reference/lrotl-lrotr.md)|[abs](../c-runtime-library/reference/abs-labs-llabs-abs64.md)|[strcat](../c-runtime-library/reference/strcat-wcscat-mbscat.md)||  
  
 Os programas que usam funções intrínsecas são mais rápidos porque não têm a sobrecarga das chamadas de função, mas podem ser maiores devido ao código adicional gerado.  
  
 **Específico para x86**  
  
 Os intrínsecos \_disable e \_enable geram instruções no modo kernel para desabilitar\/habilitar interrupções e podem ser úteis nos drivers do modo kernel.  
  
## Exemplo  
 Compile o código a seguir na linha de comando com "cl \-c \-FAs sample.c" e verifique sample.asm para ver que eles se transformam em CLI e STI de instruções x86:  
  
```  
// pragma_directive_intrinsic.cpp  
// processor: x86  
#include <dos.h>   // definitions for _disable, _enable  
#pragma intrinsic(_disable)  
#pragma intrinsic(_enable)  
void f1(void) {  
   _disable();  
   // do some work here that should not be interrupted  
   _enable();  
}  
int main() {  
}  
```  
  
 **Fim de Específico para x86**  
  
 As funções de ponto flutuante listadas abaixo não têm formas intrínsecas reais.  Elas têm versões que passam argumentos diretamente para o chip de ponto flutuante em vez enviá\-los para a pilha do programa:  
  
|||||  
|-|-|-|-|  
|[acos](../c-runtime-library/reference/acos-acosf-acosl.md)|[cosh](../c-runtime-library/reference/cos-cosf-cosl-cosh-coshf-coshl.md)|[pow](../Topic/pow,%20powf,%20powl.md)|[tanh](../c-runtime-library/reference/tan-tanf-tanl-tanh-tanhf-tanhl.md)|  
|[asin](../c-runtime-library/reference/asin-asinf-asinl.md)|[fmod](../Topic/fmod,%20fmodf.md)|[sinh](../c-runtime-library/reference/sin-sinf-sinl-sinh-sinhf-sinhl.md)||  
  
 As funções de ponto flutuante listadas abaixo têm formas intrínsecas reais quando você especifica [\/Oi](../Topic/-Oi%20\(Generate%20Intrinsic%20Functions\).md), [\/Og](../build/reference/og-global-optimizations.md) e [\/fp:fast](../build/reference/fp-specify-floating-point-behavior.md) \(ou qualquer opção que incluir \/Og: [\/Ox](../build/reference/ox-full-optimization.md), [\/O1](../build/reference/o1-o2-minimize-size-maximize-speed.md) e \/O2\):  
  
|||||  
|-|-|-|-|  
|[atan](../c-runtime-library/reference/atan-atanf-atanl-atan2-atan2f-atan2l.md)|[exp](../c-runtime-library/reference/exp-expf.md)|[log10](../Topic/log,%20logf,%20log10,%20log10f.md)|[sqrt](../c-runtime-library/reference/sqrt-sqrtf-sqrtl.md)|  
|[atan2](../c-runtime-library/reference/atan-atanf-atanl-atan2-atan2f-atan2l.md)|[log](../Topic/log,%20logf,%20log10,%20log10f.md)|[sin](../c-runtime-library/reference/sin-sinf-sinl-sinh-sinhf-sinhl.md)|[tan](../c-runtime-library/reference/tan-tanf-tanl-tanh-tanhf-tanhl.md)|  
|[cos](../c-runtime-library/reference/cos-cosf-cosl-cosh-coshf-coshl.md)||||  
  
 Você pode usar [\/fp:strict](../build/reference/fp-specify-floating-point-behavior.md) ou [\/Za](../build/reference/za-ze-disable-language-extensions.md) para substituir a geração de opções de ponto flutuante intrínsecas reais.  Nesse caso, as funções são geradas como rotinas de biblioteca que passam argumentos diretamente para o chip de ponto flutuante em vez de enviá\-los para a pilha do programa.  
  
 Consulte [Função \# pragma](../preprocessor/function-c-cpp.md) para obter informações e um exemplo de como habilitar\/desabilitar intrínsecos para um bloco de texto de origem.  
  
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)