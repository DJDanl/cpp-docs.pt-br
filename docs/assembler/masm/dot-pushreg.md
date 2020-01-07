---
title: .PUSHREG
ms.date: 12/16/2019
f1_keywords:
- .PUSHREG
helpviewer_keywords:
- .PUSHREG directive
ms.assetid: e0c83758-dfed-40ea-afe6-cb833c8d2d30
ms.openlocfilehash: de6ffd3668f47732144e8c632410f6dfde6b2f31
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75318287"
---
# <a name="pushreg"></a>.PUSHREG

Gera uma entrada de código de desenrolação `UWOP_PUSH_NONVOL` para o número de registro especificado usando o deslocamento atual no prólogo.

## <a name="syntax"></a>Sintaxe

> . *Registro* de pushreg

## <a name="remarks"></a>Comentários

**. O PUSHREG** permite que os usuários do ml64. exe especifiquem como a função de quadro se desenrola e só é permitida dentro do prólogo, que se estende da declaração de **quadro** [proc](proc.md) para o [. Diretiva endprólogo](dot-endprolog.md) . Essas diretivas não geram código; Eles geram apenas `.xdata` e `.pdata`. **. PUSHREG** deve ser precedido por instruções que realmente implementam as ações a serem rebobinadas. É uma boa prática encapsular as diretivas de desenrolamento e o código que elas devem desenrolar em uma macro para garantir o contrato.

*o registro* pode ser um de: \
RAX | RCX | RDX | RBX | RDI | RSI | RBP | R8 | R9 | R10 | R11 | R12 | R13 | R14 | R15.

Para obter mais informações, consulte [MASM para x64 (ml64. exe)](masm-for-x64-ml64-exe.md).

## <a name="sample"></a>Amostra

### <a name="description"></a>Descrição

O exemplo a seguir mostra como enviar por push registros não voláteis.

### <a name="code"></a>Código

```asm
; ml64 ex1.asm /link /entry:Example1 /SUBSYSTEM:CONSOLE
_text SEGMENT
Example1 PROC FRAME
   push r10
.pushreg r10
   push r15
.pushreg r15
   push rbx
.pushreg rbx
   push rsi
.pushreg rsi
.endprolog
   ; rest of function ...
   ret
Example1 ENDP
_text ENDS
END
```

## <a name="see-also"></a>Veja também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
