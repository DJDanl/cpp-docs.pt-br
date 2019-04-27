---
title: .SETFRAME
ms.date: 08/30/2018
f1_keywords:
- .SETFRAME
helpviewer_keywords:
- .SETFRAME directive
ms.assetid: eaa9b5ed-4daa-4f1e-bdb6-100758007ab3
ms.openlocfilehash: c2c35cdb2889350b27e9fb11c397b684506972c5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62178170"
---
# <a name="setframe"></a>.SETFRAME

Preenchimentos no quadro de campo e o deslocamento registrar as informações de desenrolamento usando o registro especificado (`reg`) e deslocamento (`offset`). O deslocamento deve ser um múltiplo de 16 e menor ou igual a 240. Essa diretiva também gera um `UWOP_SET_FPREG` entrada de código de desenrolamento para registrar especificado usando o deslocamento atual do prólogo.

## <a name="syntax"></a>Sintaxe

> . Reg SETFRAME, deslocamento

## <a name="remarks"></a>Comentários

. SETFRAME permite que os usuários de ml64.exe especificar como uma função de quadro é desenrolado e só é permitida dentro do prólogo, que se estende do [PROC](../../assembler/masm/proc.md) declaração de quadro para o [. ENDPROLOG](../../assembler/masm/dot-endprolog.md) diretiva. Essas diretivas não geram código; elas só geram `.xdata` e `.pdata`. . SETFRAME deve ser precedido por instruções que realmente implementam as ações a ser organizado. É uma boa prática para encapsular as diretivas de desenrolamento e o código que eles se destinam à desenrolamento em uma macro para garantir que o contrato.

Para obter mais informações, consulte [MASM para x64 (ml64.exe)](../../assembler/masm/masm-for-x64-ml64-exe.md).

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

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>