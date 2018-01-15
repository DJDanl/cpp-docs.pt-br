---
title: "intrínseco | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- intrinsic_CPP
- vc-pragma.intrinsic
dev_langs: C++
helpviewer_keywords:
- intrinsic pragma
- pragmas, intrinsic
ms.assetid: 25c86ac7-ef40-47b7-a2c0-fada9c5dc3c5
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d44a347f8f6cf6e502d3cc22435ed441a000f894
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="intrinsic"></a>intrinsic
Especifica que as chamadas para as funções especificadas na lista de argumentos do pragma são intrínsecas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#pragma intrinsic( function1 [, function2, ...] )  
```  
  
## <a name="remarks"></a>Comentários  
 O **intrínseco** pragma informa ao compilador que uma função tem conhecidos comportamento.  O compilador pode chamar a função e não substituir a chamada de função pelas instruções embutidas, se isso resultar em um melhor desempenho.  
  
 As funções da biblioteca com formas intrínsecas estão listadas abaixo. Uma vez um **intrínseco** pragma é visto, ele entra em vigor na primeira definição de função que contém uma função intrínseca especificada. O efeito continuará até o final do arquivo de origem ou a aparência de um **função** pragma especificando a mesma função intrínseca. O **intrínseco** pragma pode ser usado somente fora de uma definição de função — no nível global.  
  
 As funções a seguir têm intrínsecos formulários e os formulários intrínsecos são usados quando você especificar [/Oi](../build/reference/oi-generate-intrinsic-functions.md):  
  
|||||  
|-|-|-|-|  
|[_disable](../intrinsics/disable.md)|[_outp](../c-runtime-library/outp-outpw-outpd.md)|[fabs](../c-runtime-library/reference/fabs-fabsf-fabsl.md)|[strcmp](../c-runtime-library/reference/strcmp-wcscmp-mbscmp.md)|  
|[_enable](../intrinsics/enable.md)|[_outpw](../c-runtime-library/outp-outpw-outpd.md)|[labs](../c-runtime-library/reference/abs-labs-llabs-abs64.md)|[strcpy](../c-runtime-library/reference/strcpy-wcscpy-mbscpy.md)|  
|[_inp](../c-runtime-library/inp-inpw-inpd.md)|[_rotl](../c-runtime-library/reference/rotl-rotl64-rotr-rotr64.md)|[memcmp](../c-runtime-library/reference/memcmp-wmemcmp.md)|[strlen](../c-runtime-library/reference/strlen-wcslen-mbslen-mbslen-l-mbstrlen-mbstrlen-l.md)|  
|[_inpw](../c-runtime-library/inp-inpw-inpd.md)|[_rotr](../c-runtime-library/reference/rotl-rotl64-rotr-rotr64.md)|[memcpy](../c-runtime-library/reference/memcpy-wmemcpy.md)||  
|[_lrotl](../c-runtime-library/reference/lrotl-lrotr.md)|[_strset](../c-runtime-library/reference/strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)|[memset](../c-runtime-library/reference/memset-wmemset.md)||  
|[_lrotr](../c-runtime-library/reference/lrotl-lrotr.md)|[abs](../c-runtime-library/reference/abs-labs-llabs-abs64.md)|[strcat](../c-runtime-library/reference/strcat-wcscat-mbscat.md)||  
  
 Os programas que usam funções intrínsecas são mais rápidos porque não têm a sobrecarga das chamadas de função, mas podem ser maiores devido ao código adicional gerado.  
  
 **x86 específico**  
  
 Os intrínsecos _disable e _enable geram instruções no modo kernel para desabilitar/habilitar interrupções e podem ser úteis nos drivers do modo kernel.  
  
## <a name="example"></a>Exemplo  
 Compile o código a seguir na linha de comando com "cl -c -FAs sample.c" e verifique sample.asm para ver que eles se transformam em CLI e STI de instruções x86:  
  
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
  
 **Término x86 específico**  
  
 As funções de ponto flutuante listadas abaixo não têm formas intrínsecas reais. Elas têm versões que passam argumentos diretamente para o chip de ponto flutuante em vez enviá-los para a pilha do programa:  
  
|||||  
|-|-|-|-|  
|[acos](../c-runtime-library/reference/acos-acosf-acosl.md)|[cosh](../c-runtime-library/reference/cos-cosf-cosl-cosh-coshf-coshl.md)|[pow](../c-runtime-library/reference/pow-powf-powl.md)|[tanh](../c-runtime-library/reference/tan-tanf-tanl-tanh-tanhf-tanhl.md)|  
|[asin](../c-runtime-library/reference/asin-asinf-asinl.md)|[fmod](../c-runtime-library/reference/fmod-fmodf.md)|[sinh](../c-runtime-library/reference/sin-sinf-sinl-sinh-sinhf-sinhl.md)||  
  
 As funções de ponto flutuantes listadas abaixo têm formulários intrínsecos true quando você especificar [/Oi](../build/reference/oi-generate-intrinsic-functions.md), [/Og](../build/reference/og-global-optimizations.md), e [Fast](../build/reference/fp-specify-floating-point-behavior.md) (ou qualquer opção que inclui /Og: [/ OX](../build/reference/ox-full-optimization.md), [/O1](../build/reference/o1-o2-minimize-size-maximize-speed.md)e /O2):  
  
|||||  
|-|-|-|-|  
|[atan](../c-runtime-library/reference/atan-atanf-atanl-atan2-atan2f-atan2l.md)|[exp](../c-runtime-library/reference/exp-expf.md)|[log10](../c-runtime-library/reference/log-logf-log10-log10f.md)|[sqrt](../c-runtime-library/reference/sqrt-sqrtf-sqrtl.md)|  
|[atan2](../c-runtime-library/reference/atan-atanf-atanl-atan2-atan2f-atan2l.md)|[log](../c-runtime-library/reference/log-logf-log10-log10f.md)|[sin](../c-runtime-library/reference/sin-sinf-sinl-sinh-sinhf-sinhl.md)|[tan](../c-runtime-library/reference/tan-tanf-tanl-tanh-tanhf-tanhl.md)|  
|[cos](../c-runtime-library/reference/cos-cosf-cosl-cosh-coshf-coshl.md)||||  
  
 Você pode usar [/fp: strict](../build/reference/fp-specify-floating-point-behavior.md) ou [/Za](../build/reference/za-ze-disable-language-extensions.md) para substituir a geração das opções de ponto flutuantes intrínsecas true. Nesse caso, as funções são geradas como rotinas de biblioteca que passam argumentos diretamente para o chip de ponto flutuante em vez de enviá-los para a pilha do programa.  
  
 Consulte [função do # pragma](../preprocessor/function-c-cpp.md) para obter informações e um exemplo de como habilitar/desabilitar intrínsecos de um bloco de texto de origem.  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas pragma e a palavra-chave pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)