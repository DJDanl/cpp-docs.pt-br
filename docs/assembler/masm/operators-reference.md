---
title: Referência de operadores (MASM) | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- MASM (Microsoft Macro Assembler), operators reference
- operators [MASM]
ms.assetid: c069cab7-d6b0-4f82-a6ce-0ca3fc7e6428
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e4708af3c0fa272a1ca803f549ce8953caccaa27
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43688170"
---
# <a name="masm-operators-reference"></a>Referência de operadores (MASM)

## <a name="arithmetic"></a>aritmética

||||
|-|-|-|
|[* (multiplicação)](operator-multiply.md)|[+ (adição)](operator-add.md)|[-(subtrair ou negar)](operator-subtract-2.md)|
|[. (campo)](operator-dot.md)|[/ (divisão)](operator-subtract-1.md)|[&#91;&#93;(índice)](operator-brackets.md)|
|[MOD (resto)](operator-mod.md)|||

## <a name="control-flow"></a>Fluxo de controle

||||
|-|-|-|
|[! (not lógico de tempo de execução)](operator-logical-not-masm-run-time.md)|[! = (tempo de execução não igual)](operator-not-equal-masm.md)|[&#124;&#124;(tempo de execução de lógico ou)](operator-logical-or.md)|
|[& & (tempo de execução lógico e)](operator-logical-and-masm-run-time.md)|[< (tempo de execução menor que)](operator-less-than-masm-run-time.md)|[\<= (tempo de execução menor ou igual a)](operator-less-or-equal-masm-run-time.md)|
|[= = (tempo de execução igual)](operator-equal-masm-run-time.md)|[> (tempo de execução maior que)](operator-greater-than-masm-run-time.md)|[> = (tempo de execução maior ou igual)](operator-greater-or-equal-masm-run-time.md)|
|[& (tempo de execução do bit a bit e)](operator-bitwise-and.md)|||
|[CARREGAR? (teste de realização de tempo de execução)](operator-carry-q.md)|[ESTOURO? (teste de estouro de tempo de execução)](operator-overflow-q.md)|[PARIDADE? (teste de paridade de tempo de execução)](operator-parity-q.md)|
|[ENTRAR? (tempo de execução de teste de sinal)](operator-sign-q.md)|[ZERO? (zero em tempo de execução teste)](operator-zero-q.md)||

## <a name="logical-and-shift"></a>Lógico- and -Shift

||||
|-|-|-|
|[E (bit a bit e)](operator-and.md)|[NÃO (not bit a bit)](operator-not.md)|[OR (bit a bit ou)](operator-or.md)|
|[SHL (bits de deslocamento à esquerda)](operator-shl.md)|[SHR (bits de deslocamento à direita)](operator-shr.md)|[XOR (exclusivo bit a bit ou)](operator-xor.md)|

## <a name="macro"></a>Macro

||||
|-|-|-|
|[! (o caractere literal)](operator-logical-not-masm.md)|[% (trate como texto)](operator-percent.md)||
|[;; (trate como comentário)](operator-semicolons.md)|[&lt; &gt; (trate como um literal)](operator-literal.md)|[& & (substitua o valor do parâmetro)](operator-logical-and-masm.md)|

## <a name="miscellaneous"></a>Diversos

||||
|-|-|-|
|[' ' (trate como cadeia de caracteres)](operator-single-quote.md)|["" (tratar como cadeia de caracteres)](operator-double-quote.md)||
|: (definição de rótulo de local)|:: (registrar o segmento e o deslocamento)|:: (definição de rótulo global)|
|[; (trate como comentário)](operator-semicolon.md)|[DUP (declaração de repetição)](operator-dup.md)||

## <a name="record"></a>Registro

|||
|-|-|
|[MÁSCARA (obter o registro ou do campo de máscara de bits)](operator-mask.md)|[LARGURA (obter a largura do registro ou do campo)](operator-width.md)|

## <a name="relational"></a>Relacional

||||
|-|-|-|
|[EQ (igual)](operator-eq.md)|[GE (maior ou igual)](operator-ge.md)|[GT (maior que)](operator-gt.md)|
|[LE (menor ou igual)](operator-le.md)|[LT (menor que)](operator-lt.md)|[NE (não igual)](operator-ne.md)|

## <a name="segment"></a>Segmento

|||
|-|-|
|[: (substituição de segmento)](operator-colon.md)|:: (registrar o segmento e o deslocamento)|
|[IMAGEREL (deslocamento relativo da imagem)](operator-imagerel.md)|[LROFFSET (carregador resolvido deslocamento)](operator-lroffset.md)|
|[DESLOCAMENTO (deslocamento relativo do segmento)](operator-offset.md)|[SECTIONREL (deslocamento relativo de seção)](operator-sectionrel.md)|
|[SEG (segmento get)](operator-seg.md)||

## <a name="type"></a>Tipo

||||
|-|-|-|
|[ALTA (alta 8 bits de 16 bits mais baixas)](operator-high.md)|[HIGH32 (32 bits altos de 64 bits)](operator-high32.md)|[HIGHWORD (16 bits altos de 32 bits mais baixas)](operator-highword.md)|
|[TAMANHO (número de elementos na matriz)](operator-length.md)|[LENGTHOF (número de elementos na matriz)](operator-lengthof.md)|[LOW (baixa 8 bits)](operator-low.md)|
|[LOW32 (32 bits baixos)](operator-low32.md)|[LOWWORD (16 bits baixos)](operator-lowword.md)|[OPATTR (informações de tipo de argumento get)](operator-opattr.md)|
|[PTR (ponteiro para ou como tipo)](operator-ptr.md)|[SHORT (tipo de marca de rótulos curtos)](operator-short.md)|[TAMANHO (de tipo ou variável)](operator-size.md)|
|[SIZEOF (tamanho do tipo ou variável)](operator-sizeof.md)|[Esse (local atual)](operator-this.md)|[TIPO (tipo de expressão de get)](operator-type.md)|
|[. TIPO (informações de tipo de argumento get)](operator-dot-type.md)|||

## <a name="see-also"></a>Consulte também

[Referência do Microsoft Macro Assembler](microsoft-macro-assembler-reference.md)<br/>