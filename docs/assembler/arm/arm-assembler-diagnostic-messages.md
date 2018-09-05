---
title: Mensagens de diagnóstico do ARM Assembler | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- A2193
- A2196
- A2202
- A2513
- A2557
- A4228
- A4508
- A4509
helpviewer_keywords:
- A2193
- A2196
- A2202
- A2513
- A2557
- A4228
- A4508
- A4509
dev_langs:
- C++
ms.assetid: 52b38267-6023-4bdc-a0ef-863362f48eec
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 765a2c842d9e3714edd3303d3536efe603bd9c2c
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43684840"
---
# <a name="arm-assembler-diagnostic-messages"></a>Mensagens de diagnóstico do ARM Assembler

O assembler Microsoft ARM (*armasm*) emite erros e avisos de diagnóstico quando encontrá-las. Este artigo descreve as mensagens mais comumente encontrados.

## <a name="syntax"></a>Sintaxe

> <em>nome do arquivo</em>**(**<em>número de linha</em>**):** \[ **erro**|**aviso** ] **Um**<em>número</em>**:** *mensagem*

## <a name="diagnostic-messages---errors"></a>Mensagens de diagnóstico - erros

> A2193: essa instrução gera um comportamento imprevisível

A arquitetura ARM não garante que o que acontece quando essa instrução é executada.  Para obter detalhes sobre as formas bem definidas dessa instrução, consulte o [Manual de referência de arquitetura ARM](http://go.microsoft.com/fwlink/p/?linkid=246464).

```asm
    ADD r0, r8, pc         ; A2193: this instruction generates unpredictable behavior
```

> A2196: a instrução não pode ser codificada em 16 bits

A instrução especificada não pode ser codificada como uma instrução de prática de 16 bits.  Especifique uma instrução de 32 bits ou reorganizar o código para trazer o rótulo de destino para o intervalo de uma instrução de 16 bits.

O montador pode tentar codificar uma ramificação de 16 bits e falhar com este erro, mesmo que uma ramificação de 32 bits é pode ser codificada. Você pode resolver esse problema usando o `.W` especificador marcar explicitamente a ramificação de 32 bits.

```asm
    ADD.N r0, r1, r2      ; A2196: instruction cannot be encoded in 16 bits

    B.W label             ; OK
    B.N label             ; A2196: instruction cannot be encoded in 16 bits
    SPACE 10000
label
```

> A2202: Sintaxe de instrução de pré-UAL não é permitido na região do ELEVADOR

Código Thumb deve usar a sintaxe de Unificação Assembler linguagem UAL ().  A sintaxe antiga não será mais aceito

```asm
    ADDEQS r0, r1         ; A2202: Pre-UAL instruction syntax not allowed in THUMB region
    ADDSEQ r0, r1         ; OK
```

> A2513: Rotação deve ser par

No modo ARM, há uma sintaxe alternativa para especificar constantes.  Em vez de escrever `#<const>`, você pode escrever `#<byte>,#<rot>`, que representa o valor da constante que é obtido, o valor de girando `<byte>` direita em `<rot>`.  Quando você usa esta sintaxe, você deve fazer o valor de `<rot>` até mesmo.

```asm
    MOV r0, #4, #2       ; OK
    MOV r0, #4, #1       ; A2513: Rotation must be even
```

> A2557: O número incorreto de bytes a serem write-back

Na estrutura de NEON carregar e armazenar instruções (`VLDn`, `VSTn`), há uma sintaxe alternativa para especificar o write-back para o registro de base.  Em vez de colocar um ponto de exclamação (!) após o endereço, você pode especificar um valor de imediato que indica o deslocamento a ser adicionado ao registro de base.  Se você usar essa sintaxe, você deve especificar o número exato de bytes que foram carregados ou armazenados pela instrução.

```asm
    VLD1.8 {d0-d3}, [r0]!         ; OK
    VLD1.8 {d0-d3}, [r0], #32     ; OK
    VLD1.8 {d0-d3}, [r0], #100    ; A2557: Incorrect number of bytes to write back
```

## <a name="diagnostic-messages---warnings"></a>Mensagens de diagnóstico - avisos

> A4228: Alinhamento de área; excede o valor de alinhamento alinhamento não garantido

O alinhamento especificado em um `ALIGN` diretiva é maior que o alinhamento de fechamento `AREA`.  Como resultado, o assembler não pode garantir que o `ALIGN` diretiva será respeitada.

Para corrigir isso, você pode especificar o `AREA` diretiva um `ALIGN` atributo é igual ou maior que o alinhamento desejado.

```asm
AREA |.myarea1|
ALIGN 8           ; A4228: Alignment value exceeds AREA alignment; alignment not guaranteed

AREA |.myarea2|,ALIGN=3
ALIGN 8           ; OK
```

> A4508: O uso dessa constante girado foi preterido

No modo ARM, há uma sintaxe alternativa para especificar constantes.  Em vez de escrever `#<const>`, você pode escrever `#<byte>,#<rot>`, que representa o valor da constante que é obtido, o valor de girando `<byte>` direita em `<rot>`.  Em alguns contextos, ARM preteriu o uso de constantes girados. Nesses casos, usar o basic `#<const>` sintaxe em vez disso.

```asm
    ANDS r0, r0, #1                ; OK
    ANDS r0, r0, #4, #2            ; A4508: Use of this rotated constant is deprecated
```

> A4509: Este formulário da instrução condicional foi preterido

Essa forma da instrução condicional foi substituída pelo ARM na arquitetura ARMv8. É recomendável que você altere o código para usar ramificações condicionais. Para ver quais instruções condicionais ainda são suportadas, consulte o [Manual de referência de arquitetura ARM](http://go.microsoft.com/fwlink/p/?linkid=246464).

Esse aviso não é emitido quando o **- oldit** opção de linha de comando é usada.

```asm
    ADDEQ r0, r1, r8              ; A4509: This form of conditional instruction is deprecated
```

## <a name="see-also"></a>Consulte também

[Referência de linha de comando do assembler ARM](../../assembler/arm/arm-assembler-command-line-reference.md)<br/>
[Diretivas do assembler ARM](../../assembler/arm/arm-assembler-directives.md)<br/>
