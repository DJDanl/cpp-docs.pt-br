---
title: Referência de operadores MASM
ms.date: 07/15/2020
helpviewer_keywords:
- MASM (Microsoft Macro Assembler), operators reference
- operators [MASM]
ms.assetid: c069cab7-d6b0-4f82-a6ce-0ca3fc7e6428
ms.openlocfilehash: db79473f5d4264b869eeac334fa7957cfe553364
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88830937"
---
# <a name="masm-operators-reference"></a>Referência de operadores MASM

## <a name="arithmetic"></a>Aritmético

:::row:::
   :::column span="":::
      [`*` multiplicar](operator-multiply.md)\
      [`+` agrega](operator-add.md)\
      [`-` (subtrair ou negar)](operator-subtract-2.md)
   :::column-end:::
   :::column span="":::
      [`.` campo](operator-dot.md)\
      [`/` dividir](operator-subtract-1.md)
   :::column-end:::
   :::column span="":::
      [`[]` index](operator-brackets.md)\
      [`MOD` final](operator-mod.md)
   :::column-end:::
:::row-end:::

## <a name="control-flow"></a>Fluxo de Controle

:::row:::
   :::column span="":::
      [`!` (tempo de execução lógico não)](operator-logical-not-masm-run-time.md)\
      [`!=` (tempo de execução diferente de)](operator-not-equal-masm.md)\
      [`||` (tempo de execução lógico ou)](operator-logical-or.md)\
      [`&&` (tempo de execução lógico e)](operator-logical-and-masm-run-time.md)\
      [`<` (tempo de execução menor que)](operator-less-than-masm-run-time.md)
   :::column-end:::
   :::column span="":::
      [`<=` (tempo de execução menor ou igual a)](operator-less-or-equal-masm-run-time.md)\
      [`==` (tempo de execução igual)](operator-equal-masm-run-time.md)\
      [`>` (tempo de execução maior que)](operator-greater-than-masm-run-time.md)\
      [`>=` (tempo de execução maior ou igual a)](operator-greater-or-equal-masm-run-time.md)\
      [`&` (tempo de execução de e/ou bit)](operator-bitwise-and.md)
   :::column-end:::
   :::column span="":::
      [`CARRY?` (tempo de execução de teste)](operator-carry-q.md)\
      [`OVERFLOW?` (teste de estouro de tempo de execução)](operator-overflow-q.md)\
      [`PARITY?` (teste de paridade de tempo de execução)](operator-parity-q.md)\
      [`SIGN?` (teste de sinal de tempo de execução)](operator-sign-q.md)\
      [`ZERO?` (teste zero de tempo de execução)](operator-zero-q.md)
   :::column-end:::
:::row-end:::

## <a name="logical-and-shift"></a>Lógico e Shift

:::row:::
   :::column span="":::
      [`AND` (and e)](operator-and.md)\
      [`NOT` (não bits)](operator-not.md)
   :::column-end:::
   :::column span="":::
      [`OR` (OR-bit)](operator-or.md)\
      [`SHL` (mover bits para a esquerda)](operator-shl.md)
   :::column-end:::
   :::column span="":::
      [`SHR` (deslocar bits para a direita)](operator-shr.md)\
      [`XOR` (or exclusivo de or)](operator-xor.md)
   :::column-end:::
:::row-end:::

## <a name="macro"></a>Macro

:::row:::
   :::column span="":::
      [`!` (literal de caractere)](operator-logical-not-masm.md)\
      [`%` (tratar como texto)](operator-percent.md)
   :::column-end:::
   :::column span="":::
      [`;;` (tratar como comentário)](operator-semicolons.md)\
      [`< >` (tratar como um literal)](operator-literal.md)
   :::column-end:::
   :::column span="":::
      [`& &` (valor do parâmetro de substituição)](operator-logical-and-masm.md)
   :::column-end:::
:::row-end:::

## <a name="miscellaneous"></a>Diversos

:::row:::
   :::column span="":::
      [`' '` (tratar como cadeia de caracteres)](operator-single-quote.md)\
      [`" "` (tratar como cadeia de caracteres)](operator-double-quote.md)\
      `:` (definição de rótulo local)
   :::column-end:::
   :::column span="":::
      `::` (registrar segmento e deslocamento) \
      `::` (definição de rótulo global)
   :::column-end:::
   :::column span="":::
      [`;` (tratar como comentário)](operator-semicolon.md)\
      [`DUP` (declaração repeat)](operator-dup.md)
   :::column-end:::
:::row-end:::

## <a name="record"></a>Record

:::row:::
   :::column span="":::
      [`MASK` (obter registro ou bitmask de campo)](operator-mask.md)
   :::column-end:::
   :::column span="2":::
      [`WIDTH` (obter registro ou largura do campo)](operator-width.md)
   :::column-end:::
:::row-end:::

## <a name="relational"></a>Relacional

:::row:::
   :::column span="":::
      [`EQ` iguais](operator-eq.md)\
      [`GE` (maior ou igual a)](operator-ge.md)
   :::column-end:::
   :::column span="":::
      [`GT` (maior que)](operator-gt.md)\
      [`LE` (menor ou igual a)](operator-le.md)
   :::column-end:::
   :::column span="":::
      [`LT` (menor que)](operator-lt.md)\
      [`NE` (diferente de)](operator-ne.md)
   :::column-end:::
:::row-end:::

## <a name="segment"></a>Segment

:::row:::
   :::column span="":::
      [`:` (substituição de segmento)](operator-colon.md)\
      `::` (registrar segmento e deslocamento) \
      [`IMAGEREL` (deslocamento relativo da imagem)](operator-imagerel.md)
   :::column-end:::
   :::column span="":::
      [`LROFFSET` (deslocamento resolvido do carregador)](operator-lroffset.md)\
      [`OFFSET` (deslocamento relativo ao segmento)](operator-offset.md)
   :::column-end:::
   :::column span="":::
      [`SECTIONREL` (deslocamento relativo da seção)](operator-sectionrel.md)\
      [`SEG` (obter segmento)](operator-seg.md)
   :::column-end:::
:::row-end:::

## <a name="type"></a>Digite

:::row:::
   :::column span="":::
      [`HIGH` (alta de 8 bits dos 16 bits mais baixos)](operator-high.md)\
      [`HIGH32` (alto 32 bits de 64 bits)](operator-high32.md)\
      [`HIGHWORD` (16 bits altos de 32 bits inferiores)](operator-highword.md)\
      [`LENGTH` (número de elementos na matriz)](operator-length.md)\
      [`LENGTHOF` (número de elementos na matriz)](operator-lengthof.md)\
      [`LOW` (menos de 8 bits)](operator-low.md)
   :::column-end:::
   :::column span="":::
      [`LOW32` (bits de 32 Baixos)](operator-low32.md)\
      [`LOWWORD` (baixa de 16 bits)](operator-lowword.md)\
      [`OPATTR` (obter informações de tipo de argumento)](operator-opattr.md)\
      [`PTR` (ponteiro para ou como tipo)](operator-ptr.md)\
      [`SHORT` (marcar tipo de rótulo curto)](operator-short.md)
   :::column-end:::
   :::column span="":::
      [`SIZE` (tamanho do tipo ou variável)](operator-size.md)\
      [`SIZEOF` (tamanho do tipo ou variável)](operator-sizeof.md)\
      [`THIS` (local atual)](operator-this.md)\
      [`TYPE` (obter tipo de expressão)](operator-type.md)\
      [`.TYPE` (obter informações de tipo de argumento)](operator-dot-type.md)
   :::column-end:::
:::row-end:::

## <a name="see-also"></a>Confira também

[Referência do Microsoft Macro Assembler](microsoft-macro-assembler-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
