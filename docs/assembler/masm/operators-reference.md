---
title: Referência de operadores MASM
ms.date: 07/15/2020
helpviewer_keywords:
- MASM (Microsoft Macro Assembler), operators reference
- operators [MASM]
ms.assetid: c069cab7-d6b0-4f82-a6ce-0ca3fc7e6428
ms.openlocfilehash: c29b173a1dcf29c297e41f136044599fbd5218a5
ms.sourcegitcommit: e15b46ea7888dbdd7e0bb47da76aeed680c3c1f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/17/2020
ms.locfileid: "86446457"
---
# <a name="masm-operators-reference"></a>Referência de operadores MASM

## <a name="arithmetic"></a>Aritmético

:::row:::
   :::column span="":::
      [`*`multiplicar](operator-multiply.md)<br/>[`+`agrega](operator-add.md)<br/>[`-`(subtrair ou negar)](operator-subtract-2.md)
   :::column-end:::
   :::column span="":::
      [`.`campo](operator-dot.md)<br/>[`/`dividir](operator-subtract-1.md)
   :::column-end:::
   :::column span="":::
      [`[]`index](operator-brackets.md)<br/>[`MOD`final](operator-mod.md)
   :::column-end:::
:::row-end:::

## <a name="control-flow"></a>Fluxo de controle

:::row:::
   :::column span="":::
      [`!`(tempo de execução lógico não)](operator-logical-not-masm-run-time.md)<br/>[`!=`(tempo de execução diferente de)](operator-not-equal-masm.md)<br/>[`||`(tempo de execução lógico ou)](operator-logical-or.md)<br/>[`&&`(tempo de execução lógico e)](operator-logical-and-masm-run-time.md)<br/>[`<`(tempo de execução menor que)](operator-less-than-masm-run-time.md)
   :::column-end:::
   :::column span="":::
      [`<=`(tempo de execução menor ou igual a)](operator-less-or-equal-masm-run-time.md)<br/>[`==`(tempo de execução igual)](operator-equal-masm-run-time.md)<br/>[`>`(tempo de execução maior que)](operator-greater-than-masm-run-time.md)<br/>[`>=`(tempo de execução maior ou igual a)](operator-greater-or-equal-masm-run-time.md)<br/>[`&`(tempo de execução de e/ou bit)](operator-bitwise-and.md)
   :::column-end:::
   :::column span="":::
      [`CARRY?`(tempo de execução de teste)](operator-carry-q.md)<br/>[`OVERFLOW?`(teste de estouro de tempo de execução)](operator-overflow-q.md)<br/>[`PARITY?`(teste de paridade de tempo de execução)](operator-parity-q.md)<br/>[`SIGN?`(teste de sinal de tempo de execução)](operator-sign-q.md)<br/>[`ZERO?`(teste zero de tempo de execução)](operator-zero-q.md)
   :::column-end:::
:::row-end:::

## <a name="logical-and-shift"></a>Lógico e Shift

:::row:::
   :::column span="":::
      [`AND`(and e)](operator-and.md)<br/>[`NOT`(não bits)](operator-not.md)
   :::column-end:::
   :::column span="":::
      [`OR`(OR-bit)](operator-or.md)<br/>[`SHL`(mover bits para a esquerda)](operator-shl.md)
   :::column-end:::
   :::column span="":::
      [`SHR`(deslocar bits para a direita)](operator-shr.md)<br/>[`XOR`(or exclusivo de or)](operator-xor.md)
   :::column-end:::
:::row-end:::

## <a name="macro"></a>Macro

:::row:::
   :::column span="":::
      [`!`(literal de caractere)](operator-logical-not-masm.md)<br/>[`%`(tratar como texto)](operator-percent.md)
   :::column-end:::
   :::column span="":::
      [`;;`(tratar como comentário)](operator-semicolons.md)<br/>[`< >`(tratar como um literal)](operator-literal.md)
   :::column-end:::
   :::column span="":::
      [`& &`(valor do parâmetro de substituição)](operator-logical-and-masm.md)
   :::column-end:::
:::row-end:::

## <a name="miscellaneous"></a>Diversos

:::row:::
   :::column span="":::
      [`' '`(tratar como cadeia de caracteres)](operator-single-quote.md)<br/>[`" "`(tratar como cadeia de caracteres)](operator-double-quote.md)<br/>`:`(definição de rótulo local)
   :::column-end:::
   :::column span="":::
      `::`(registrar segmento e deslocamento)<br/>`::`(definição de rótulo global)
   :::column-end:::
   :::column span="":::
      [`;`(tratar como comentário)](operator-semicolon.md)<br/>[`DUP`(declaração repeat)](operator-dup.md)
   :::column-end:::
:::row-end:::

## <a name="record"></a>Record

:::row:::
   :::column span="":::
      [`MASK`(obter registro ou bitmask de campo)](operator-mask.md)
   :::column-end:::
   :::column span="2":::
      [`WIDTH`(obter registro ou largura do campo)](operator-width.md)
   :::column-end:::
:::row-end:::

## <a name="relational"></a>Relacional

:::row:::
   :::column span="":::
      [`EQ`iguais](operator-eq.md)<br/>[`GE`(maior ou igual a)](operator-ge.md)
   :::column-end:::
   :::column span="":::
      [`GT`(maior que)](operator-gt.md)<br/>[`LE`(menor ou igual a)](operator-le.md)
   :::column-end:::
   :::column span="":::
      [`LT`(menor que)](operator-lt.md)<br/>[`NE`(diferente de)](operator-ne.md)
   :::column-end:::
:::row-end:::

## <a name="segment"></a>Segment

:::row:::
   :::column span="":::
      [`:`(substituição de segmento)](operator-colon.md)<br/>`::`(registrar segmento e deslocamento)<br/>[`IMAGEREL`(deslocamento relativo da imagem)](operator-imagerel.md)
   :::column-end:::
   :::column span="":::
      [`LROFFSET`(deslocamento resolvido do carregador)](operator-lroffset.md)<br/>[`OFFSET`(deslocamento relativo ao segmento)](operator-offset.md)
   :::column-end:::
   :::column span="":::
      [`SECTIONREL`(deslocamento relativo da seção)](operator-sectionrel.md)<br/>[`SEG`(obter segmento)](operator-seg.md)
   :::column-end:::
:::row-end:::

## <a name="type"></a>Type

:::row:::
   :::column span="":::
      [`HIGH`(alta de 8 bits dos 16 bits mais baixos)](operator-high.md)<br/>[`HIGH32`(alto 32 bits de 64 bits)](operator-high32.md)<br/>[`HIGHWORD`(16 bits altos de 32 bits inferiores)](operator-highword.md)<br/>[`LENGTH`(número de elementos na matriz)](operator-length.md)<br/>[`LENGTHOF`(número de elementos na matriz)](operator-lengthof.md)<br/>[`LOW`(menos de 8 bits)](operator-low.md)
   :::column-end:::
   :::column span="":::
      [`LOW32`(bits de 32 Baixos)](operator-low32.md)<br/>[`LOWWORD`(baixa de 16 bits)](operator-lowword.md)<br/>[`OPATTR`(obter informações de tipo de argumento)](operator-opattr.md)<br/>[`PTR`(ponteiro para ou como tipo)](operator-ptr.md)<br/>[`SHORT`(marcar tipo de rótulo curto)](operator-short.md)
   :::column-end:::
   :::column span="":::
      [`SIZE`(tamanho do tipo ou variável)](operator-size.md)<br/>[`SIZEOF`(tamanho do tipo ou variável)](operator-sizeof.md)<br/>[`THIS`(local atual)](operator-this.md)<br/>[`TYPE`(obter tipo de expressão)](operator-type.md)<br/>[`.TYPE`(obter informações de tipo de argumento)](operator-dot-type.md)
   :::column-end:::
:::row-end:::

## <a name="see-also"></a>Confira também

[Referência do Microsoft Macro Assembler](microsoft-macro-assembler-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
