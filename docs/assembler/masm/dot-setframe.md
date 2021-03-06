---
title: .SETFRAME
ms.date: 12/17/2019
f1_keywords:
- .SETFRAME
helpviewer_keywords:
- .SETFRAME directive
ms.assetid: eaa9b5ed-4daa-4f1e-bdb6-100758007ab3
ms.openlocfilehash: 8c491a811634995398a37aa001cc1c93f8434114
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75318235"
---
# <a name="setframe"></a>.SETFRAME

Preenche o campo de registro de quadro e o deslocamento nas informações de desenrolamento usando o registro (*reg*) e o deslocamento (*deslocamento*) especificados. O deslocamento deve ser um múltiplo de 16 e menor ou igual a 240. Essa diretiva também gera uma entrada de código de desenrolação `UWOP_SET_FPREG` para o registro especificado usando o deslocamento de prólogo atual.

## <a name="syntax"></a>Sintaxe

> **.**  *Reg*frame, *deslocamento*

## <a name="remarks"></a>Comentários

**. SETFRAME** permite que os usuários de ml64. exe especifiquem como uma função de quadro se desenrola e só é permitido dentro do prólogo, que se estende da declaração de quadro [proc](proc.md) para o [. Diretiva endprólogo](dot-endprolog.md) . Essas diretivas não geram código; Eles geram apenas `.xdata` e `.pdata`. **. SETFRAME** deve ser precedido por instruções que realmente implementam as ações a serem rebobinadas. É uma boa prática encapsular as diretivas de desenrolamento e o código que elas devem desenrolar em uma macro para garantir o contrato.

Para obter mais informações, consulte [MASM para x64 (ml64. exe)](masm-for-x64-ml64-exe.md).

## <a name="sample"></a>Amostra

### <a name="description"></a>Descrição

O exemplo a seguir mostra como usar um ponteiro de quadro:

### <a name="code"></a>Código

```asm
; ml64 frmex2.asm /link /entry:frmex2 /SUBSYSTEM:CONSOLE
_text SEGMENT
frmex2 PROC FRAME
   push rbp
.pushreg rbp
   sub rsp, 010h
.allocstack 010h
   mov rbp, rsp
.setframe rbp, 0
.endprolog
   ; modify the stack pointer outside of the prologue (similar to alloca)
   sub rsp, 060h

   ; we can unwind from the following AV because of the frame pointer
   mov rax, 0
   mov rax, [rax] ; AV!

   add rsp, 060h
   add rsp, 010h
   pop rbp
   ret
frmex2 ENDP
_text ENDS
END
```

## <a name="see-also"></a>Veja também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
