---
title: Pragma intrinsic
description: O pragma intrínseco de MSVC é usado para especificar as funções intrínsecas com suporte a serem usadas como intrínsecas.
ms.date: 07/08/2020
f1_keywords:
- intrinsic_CPP
- vc-pragma.intrinsic
helpviewer_keywords:
- intrinsic pragma
- pragmas, intrinsic
ms.assetid: 25c86ac7-ef40-47b7-a2c0-fada9c5dc3c5
ms.openlocfilehash: 31f4ebc2fdd4c5c984160d441b4e0a723c686a46
ms.sourcegitcommit: 80c8a512b361bd84e38958beb1a1bf6db7434021
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/09/2020
ms.locfileid: "86180949"
---
# <a name="intrinsic-pragma"></a>Pragma `intrinsic`

Especifica que as chamadas para as funções especificadas na lista de argumentos do pragma são intrínsecas.

## <a name="syntax"></a>Syntax

> **`#pragma intrinsic(`** *`function1`* [**`,`** _`function2`_ ... ] **`)`**

## <a name="remarks"></a>Comentários

O **`intrinsic`** pragma informa ao compilador que uma função tem um comportamento conhecido. O compilador pode chamar a função e não substituir a chamada de função pelas instruções embutidas, se isso resultar em um melhor desempenho.

As funções da biblioteca com formas intrínsecas estão listadas abaixo. Depois que um **`intrinsic`** pragma é visto, ele entra em vigor na primeira definição de função que contém uma função intrínseca especificada. O efeito continua no final do arquivo de origem ou na aparência de um `function` pragma especificando a mesma função intrínseca. O **`intrinsic`** pragma só pode ser usado fora de uma definição de função, no nível global.

As funções a seguir têm formulários intrínsecos, e os formulários intrínsecos são usados quando você especifica [`/Oi`](../build/reference/oi-generate-intrinsic-functions.md) :

|  |  |  |  |
|--|--|--|--|
| [`_disable`](../intrinsics/disable.md) | [`_outp`](../c-runtime-library/outp-outpw-outpd.md) | [`fabs`](../c-runtime-library/reference/fabs-fabsf-fabsl.md) | [`strcmp`](../c-runtime-library/reference/strcmp-wcscmp-mbscmp.md) |
| [`_enable`](../intrinsics/enable.md) | [`_outpw`](../c-runtime-library/outp-outpw-outpd.md) | [`labs`](../c-runtime-library/reference/abs-labs-llabs-abs64.md) | [`strcpy`](../c-runtime-library/reference/strcpy-wcscpy-mbscpy.md) |
| [`_inp`](../c-runtime-library/inp-inpw-inpd.md) | [`_rotl`](../c-runtime-library/reference/rotl-rotl64-rotr-rotr64.md) | [`memcmp`](../c-runtime-library/reference/memcmp-wmemcmp.md) | [`strlen`](../c-runtime-library/reference/strlen-wcslen-mbslen-mbslen-l-mbstrlen-mbstrlen-l.md) |
| [`_inpw`](../c-runtime-library/inp-inpw-inpd.md) | [`_rotr`](../c-runtime-library/reference/rotl-rotl64-rotr-rotr64.md) | [`memcpy`](../c-runtime-library/reference/memcpy-wmemcpy.md) |  |
| [`_lrotl`](../c-runtime-library/reference/lrotl-lrotr.md) | [`_strset`](../c-runtime-library/reference/strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md) | [`memset`](../c-runtime-library/reference/memset-wmemset.md) |  |
| [`_lrotr`](../c-runtime-library/reference/lrotl-lrotr.md) | [`abs`](../c-runtime-library/reference/abs-labs-llabs-abs64.md) | [`strcat`](../c-runtime-library/reference/strcat-wcscat-mbscat.md) |  |

Programas que usam funções intrínsecas são mais rápidos porque não têm a sobrecarga de chamadas de função. No entanto, eles podem ser maiores devido ao código adicional gerado.

### <a name="x86-specific-example"></a>exemplo específico de x86

O `_disable` e `_enable` intrínsecos geram instruções do modo kernel para desabilitar ou habilitar interrupções e podem ser úteis em drivers de modo kernel.

Compile o código a seguir na linha de comando com `cl -c -FAs sample.c` e examine *`sample.asm`* para ver que eles se transformam em instruções x86 CLI e STI:

```cpp
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

### <a name="intrinsic-floating-point-functions"></a>Funções intrínsecas de ponto flutuante

Essas funções de ponto flutuante não têm formulários intrínsecos verdadeiros. Em vez disso, eles têm versões que passam argumentos diretamente para o chip de ponto flutuante, em vez de enviá-los na pilha:

|  |  |  |  |
|--|--|--|--|
| [`acos`](../c-runtime-library/reference/acos-acosf-acosl.md) | [`cosh`](../c-runtime-library/reference/cosh-coshf-coshl.md) | [`pow`](../c-runtime-library/reference/pow-powf-powl.md) | [`tanh`](../c-runtime-library/reference/tanh-tanhf-tanhl.md) |
| [`asin`](../c-runtime-library/reference/asin-asinf-asinl.md) | [`fmod`](../c-runtime-library/reference/fmod-fmodf.md) | [`sinh`](../c-runtime-library/reference/sinh-sinhf-sinhl.md) |  |

Essas funções de ponto flutuante têm formulários intrínsecos verdadeiros quando você especifica [`/Oi`](../build/reference/oi-generate-intrinsic-functions.md) e [`/fp:fast`](../build/reference/fp-specify-floating-point-behavior.md) (ou qualquer opção que inclua **`/Oi`** : [`/Ox`](../build/reference/ox-full-optimization.md) , [`/O1`](../build/reference/o1-o2-minimize-size-maximize-speed.md) e [`/O2`](../build/reference/o1-o2-minimize-size-maximize-speed.md) ):

|  |  |  |  |
|--|--|--|--|
| [`atan`](../c-runtime-library/reference/atan-atanf-atanl-atan2-atan2f-atan2l.md) | [`exp`](../c-runtime-library/reference/exp-expf.md) | [`log10`](../c-runtime-library/reference/log-logf-log10-log10f.md) | [`sqrt`](../c-runtime-library/reference/sqrt-sqrtf-sqrtl.md) |
| [`atan2`](../c-runtime-library/reference/atan-atanf-atanl-atan2-atan2f-atan2l.md) | [`log`](../c-runtime-library/reference/log-logf-log10-log10f.md) | [`sin`](../c-runtime-library/reference/sin-sinf-sinl.md) | [`tan`](../c-runtime-library/reference/tan-tanf-tanl.md) |
| [`cos`](../c-runtime-library/reference/cos-cosf-cosl.md) |  |  |  |

Você pode usar [`/fp:strict`](../build/reference/fp-specify-floating-point-behavior.md) ou [`/Za`](../build/reference/za-ze-disable-language-extensions.md) para substituir a geração de opções de ponto flutuante verdadeiro intrínseco. Nesse caso, as funções são geradas como rotinas de biblioteca que passam argumentos diretamente para o chip de ponto flutuante em vez de enviá-los para a pilha do programa.

Consulte [`#pragma function`](../preprocessor/function-c-cpp.md) para obter informações e um exemplo de como habilitar e desabilitar intrínsecos para um bloco de texto de origem.

## <a name="see-also"></a>Veja também

[Diretivas pragma e a `__pragma` palavra-chave](../preprocessor/pragma-directives-and-the-pragma-keyword.md)\
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
