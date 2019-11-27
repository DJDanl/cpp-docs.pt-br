---
title: Referência de operadores MASM
ms.date: 08/30/2018
helpviewer_keywords:
- MASM (Microsoft Macro Assembler), operators reference
- operators [MASM]
ms.assetid: c069cab7-d6b0-4f82-a6ce-0ca3fc7e6428
ms.openlocfilehash: 5295307ad668b76e5ff39882ce2613f2042f914a
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74395206"
---
# <a name="masm-operators-reference"></a>Referência de operadores MASM

## <a name="arithmetic"></a>Operações

||||
|-|-|-|
|[* (multiplicar)](operator-multiply.md)|[+ (Adicionar)](operator-add.md)|[-(subtrair ou negar)](operator-subtract-2.md)|
|[. campo](operator-dot.md)|[/(divisão)](operator-subtract-1.md)|[&#91;&#93;index](operator-brackets.md)|
|[MOD (restante)](operator-mod.md)|||

## <a name="control-flow"></a>Fluxo de controle

||||
|-|-|-|
|[\! (tempo de execução lógico não)](operator-logical-not-masm-run-time.md)|[\!= (tempo de execução não igual)](operator-not-equal-masm.md)|[&#124;&#124;(tempo de execução lógico ou)](operator-logical-or.md)|
|[& & (tempo de execução lógico e)](operator-logical-and-masm-run-time.md)|[< (tempo de execução menor que)](operator-less-than-masm-run-time.md)|[\<= (tempo de execução menor ou igual)](operator-less-or-equal-masm-run-time.md)|
|[= = (tempo de execução igual)](operator-equal-masm-run-time.md)|[> (tempo de execução maior que)](operator-greater-than-masm-run-time.md)|[> = (tempo de execução maior ou igual)](operator-greater-or-equal-masm-run-time.md)|
|[& (tempo de execução bit e](operator-bitwise-and.md)|||
|[LEVAM? (tempo de execução de teste)](operator-carry-q.md)|[CONTRA? (teste de estouro de tempo de execução)](operator-overflow-q.md)|[PARIDADE? (teste de paridade de tempo de execução)](operator-parity-q.md)|
|[Assine? (teste de sinal de tempo de execução)](operator-sign-q.md)|[ZERO? (teste zero de tempo de execução)](operator-zero-q.md)||

## <a name="logical-and-shift"></a>Lógico e Shift

||||
|-|-|-|
|[AND (and-bit e)](operator-and.md)|[Não (não é)](operator-not.md)|[OU (or](operator-or.md)|
|[SHL (mover bits para a esquerda)](operator-shl.md)|[SHR (mover bits para a direita)](operator-shr.md)|[XOR (or exclusivo de or)](operator-xor.md)|

## <a name="macro"></a>Macro

||||
|-|-|-|
|[\! (literal de caractere)](operator-logical-not-masm.md)|[% (tratar como texto)](operator-percent.md)||
|[;; (tratar como comentário)](operator-semicolons.md)|[&lt; &gt; (tratar como um literal)](operator-literal.md)|[& & (valor de parâmetro de substituição)](operator-logical-and-masm.md)|

## <a name="miscellaneous"></a>Diversos

||||
|-|-|-|
|[' ' (tratar como cadeia de caracteres)](operator-single-quote.md)|["" (tratar como cadeia de caracteres)](operator-double-quote.md)||
|: (definição de rótulo local)|:: (registrar segmento e deslocamento)|:: (definição de rótulo global)|
|[; (tratar como comentário)](operator-semicolon.md)|[DUP (declaração de repetição)](operator-dup.md)||

## <a name="record"></a>Registro

|||
|-|-|
|[MASK (obter registro ou bitmask de campo)](operator-mask.md)|[LARGURA (obter registro ou largura do campo)](operator-width.md)|

## <a name="relational"></a>Relacional

||||
|-|-|-|
|[EQ (igual)](operator-eq.md)|[GE (maior ou igual)](operator-ge.md)|[GT (maior que)](operator-gt.md)|
|[LE (menor ou igual)](operator-le.md)|[LT (menor que)](operator-lt.md)|[NE (diferente de)](operator-ne.md)|

## <a name="segment"></a>Segment

|||
|-|-|
|[: (substituição de segmento)](operator-colon.md)|:: (registrar segmento e deslocamento)|
|[IMAGEREL (deslocamento relativo da imagem)](operator-imagerel.md)|[LROFFSET (deslocamento resolvido do carregador)](operator-lroffset.md)|
|[DESLOCAMENTO (deslocamento relativo ao segmento)](operator-offset.md)|[SECTIONREL (deslocamento relativo da seção)](operator-sectionrel.md)|
|[SEG (obter segmento)](operator-seg.md)||

## <a name="type"></a>Tipo

||||
|-|-|-|
|[ALTA (mais de 8 bits de 16 bits)](operator-high.md)|[HIGH32 (alta 32 bits de 64 bits)](operator-high32.md)|[HIGHWORD (16 bits altos de 32 bits inferiores)](operator-highword.md)|
|[COMPRIMENTO (número de elementos na matriz)](operator-length.md)|[LENGTHOF (número de elementos na matriz)](operator-lengthof.md)|[BAIXO (menos de 8 bits)](operator-low.md)|
|[LOW32 (bits baixa 32)](operator-low32.md)|[LOWWORD (baixa de 16 bits)](operator-lowword.md)|[OPATTR (obter informações de tipo de argumento)](operator-opattr.md)|
|[PTR (ponteiro para ou como tipo)](operator-ptr.md)|[SHORT (marcar tipo de rótulo curto)](operator-short.md)|[TAMANHO (tamanho do tipo ou variável)](operator-size.md)|
|[SIZEOF (tamanho do tipo ou variável)](operator-sizeof.md)|[ISSO (local atual)](operator-this.md)|[TYPE (obter tipo de expressão)](operator-type.md)|
|[. TIPO (obter informações de tipo de argumento)](operator-dot-type.md)|||

## <a name="see-also"></a>Consulte também

[Referência do Microsoft Macro Assembler](microsoft-macro-assembler-reference.md)<br/>
