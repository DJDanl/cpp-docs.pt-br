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
ms.openlocfilehash: 45a5a13f3bda3657b93e1a89e7a842a4465b01d5
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90041101"
---
# <a name="intrinsic-pragma"></a>Pragma `intrinsic`

Especifica que as chamadas para as funções especificadas na lista de argumentos do pragma são intrínsecas.

## <a name="syntax"></a>Sintaxe

> **`#pragma intrinsic(`** *`function1`* [**`,`** _`function2`_ ... ] **`)`**

## <a name="remarks"></a>Comentários

O **`intrinsic`** pragma informa ao compilador que uma função tem um comportamento conhecido. O compilador pode chamar a função e não substituir a chamada de função pelas instruções embutidas, se isso resultar em um melhor desempenho.

As funções da biblioteca com formas intrínsecas estão listadas abaixo. Depois que um **`intrinsic`** pragma é visto, ele entra em vigor na primeira definição de função que contém uma função intrínseca especificada. O efeito continua no final do arquivo de origem ou na aparência de um `function` pragma especificando a mesma função intrínseca. O **`intrinsic`** pragma só pode ser usado fora de uma definição de função, no nível global.

As funções a seguir têm formulários intrínsecos, e os formulários intrínsecos são usados quando você especifica [`/Oi`](../build/reference/oi-generate-intrinsic-functions.md) :

:::row:::
   :::column span="":::
      [`abs`](../c-runtime-library/reference/abs-labs-llabs-abs64.md)\
      [`_disable`](../intrinsics/disable.md)\
      [`_enable`](../intrinsics/enable.md)\
      [`fabs`](../c-runtime-library/reference/fabs-fabsf-fabsl.md)\
      [`_inp`](../c-runtime-library/inp-inpw-inpd.md)\
      [`_inpw`](../c-runtime-library/inp-inpw-inpd.md)\
   :::column-end:::
   :::column span="":::
      [`labs`](../c-runtime-library/reference/abs-labs-llabs-abs64.md)\
      [`_lrotl`](../c-runtime-library/reference/lrotl-lrotr.md)\
      [`_lrotr`](../c-runtime-library/reference/lrotl-lrotr.md)\
      [`memcmp`](../c-runtime-library/reference/memcmp-wmemcmp.md)\
      [`memcpy`](../c-runtime-library/reference/memcpy-wmemcpy.md)\
   :::column-end:::
   :::column span="":::
      [`memset`](../c-runtime-library/reference/memset-wmemset.md)\
      [`_outp`](../c-runtime-library/outp-outpw-outpd.md)\
      [`_outpw`](../c-runtime-library/outp-outpw-outpd.md)\
      [`_rotl`](../c-runtime-library/reference/rotl-rotl64-rotr-rotr64.md)\
      [`_rotr`](../c-runtime-library/reference/rotl-rotl64-rotr-rotr64.md)\
   :::column-end:::
   :::column span="":::
      [`strcat`](../c-runtime-library/reference/strcat-wcscat-mbscat.md)\
      [`strcmp`](../c-runtime-library/reference/strcmp-wcscmp-mbscmp.md)\
      [`strcpy`](../c-runtime-library/reference/strcpy-wcscpy-mbscpy.md)\
      [`strlen`](../c-runtime-library/reference/strlen-wcslen-mbslen-mbslen-l-mbstrlen-mbstrlen-l.md)\
      [`_strset`](../c-runtime-library/reference/strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)\
   :::column-end:::
:::row-end:::

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

:::row:::
   :::column span="":::
      [`acos`](../c-runtime-library/reference/acos-acosf-acosl.md)\
      [`asin`](../c-runtime-library/reference/asin-asinf-asinl.md)\
   :::column-end:::
   :::column span="":::
      [`cosh`](../c-runtime-library/reference/cosh-coshf-coshl.md)\
      [`fmod`](../c-runtime-library/reference/fmod-fmodf.md)\
   :::column-end:::
   :::column span="":::
      [`pow`](../c-runtime-library/reference/pow-powf-powl.md)\
      [`sinh`](../c-runtime-library/reference/sinh-sinhf-sinhl.md)\
   :::column-end:::
   :::column span="":::
      [`tanh`](../c-runtime-library/reference/tanh-tanhf-tanhl.md)\
   :::column-end:::
:::row-end:::

Essas funções de ponto flutuante têm formulários intrínsecos verdadeiros quando você especifica [`/Oi`](../build/reference/oi-generate-intrinsic-functions.md) e [`/fp:fast`](../build/reference/fp-specify-floating-point-behavior.md) (ou qualquer opção que inclua **`/Oi`** : [`/Ox`](../build/reference/ox-full-optimization.md) , [`/O1`](../build/reference/o1-o2-minimize-size-maximize-speed.md) e [`/O2`](../build/reference/o1-o2-minimize-size-maximize-speed.md) ):

:::row:::
   :::column span="":::
      [`atan`](../c-runtime-library/reference/atan-atanf-atanl-atan2-atan2f-atan2l.md)\
      [`atan2`](../c-runtime-library/reference/atan-atanf-atanl-atan2-atan2f-atan2l.md)\
      [`cos`](../c-runtime-library/reference/cos-cosf-cosl.md)\
   :::column-end:::
   :::column span="":::
      [`exp`](../c-runtime-library/reference/exp-expf.md)\
      [`log`](../c-runtime-library/reference/log-logf-log10-log10f.md)\
   :::column-end:::
   :::column span="":::
      [`log10`](../c-runtime-library/reference/log-logf-log10-log10f.md)\
      [`sin`](../c-runtime-library/reference/sin-sinf-sinl.md)\
   :::column-end:::
   :::column span="":::
      [`sqrt`](../c-runtime-library/reference/sqrt-sqrtf-sqrtl.md)\
      [`tan`](../c-runtime-library/reference/tan-tanf-tanl.md)\
   :::column-end:::
:::row-end:::

Você pode usar [`/fp:strict`](../build/reference/fp-specify-floating-point-behavior.md) ou [`/Za`](../build/reference/za-ze-disable-language-extensions.md) para substituir a geração de opções de ponto flutuante verdadeiro intrínseco. Nesse caso, as funções são geradas como rotinas de biblioteca que passam argumentos diretamente para o chip de ponto flutuante em vez de enviá-los para a pilha do programa.

Consulte [`#pragma function`](../preprocessor/function-c-cpp.md) para obter informações e um exemplo de como habilitar e desabilitar intrínsecos para um bloco de texto de origem.

## <a name="see-also"></a>Confira também

[Diretivas pragma e a `__pragma` palavra-chave](../preprocessor/pragma-directives-and-the-pragma-keyword.md)\
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
