---
title: Pseudo-operações brutas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 4def1a0e-ec28-4736-91fb-fac95fba1f36
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7b05a4f9d109809161df7cde643439c281121f62
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45703255"
---
# <a name="raw-pseudo-operations"></a>Pseudo-operações brutas

Este tópico lista pseudo-operações.

## <a name="remarks"></a>Comentários

|Operação de pseudo|Descrição|
|----------------------|-----------------|
|QUADRO de PROC [: ehandler]|Causas MASM para gerar uma função de tabela de entrada no registro. pData e. XData informações de desenrolamento para uma função do estruturado comportamento de desenrolamento de manipulação de exceção.  Se ehandler estiver presente, esse procedimento é inserido no. XData como o identificador específico da linguagem.<br /><br /> Quando o atributo de quadro é usado, ele deve ser seguido por um. Diretiva ENDPROLOG.  Se a função é uma função de folha (conforme definido em [tipos de função](../build/function-types.md)) o atributo de quadro é desnecessário, assim como o restante dessas operações pseudo.|
|. Reg PUSHREG|Gera uma entrada de código de desenrolamento UWOP_PUSH_NONVOL para o número do registro especificado usando as atuais no prólogo de deslocamento.<br /><br /> Isso só deve ser usado com registros inteiros não volátil.  Para envios por push de registros voláteis, use um. 8 ALLOCSTACK, em vez disso|
|. Reg SETFRAME, deslocamento|Preenchimentos no quadro de registrar o campo e o deslocamento nas informações de desenrolamento usando o registro especificado e o deslocamento. O deslocamento deve ser um múltiplo de 16 e menor ou igual a 240. Essa diretiva também gera uma entrada de código de desenrolamento UWOP_SET_FPREG para o registro especificado usando o deslocamento atual do prólogo.|
|. Tamanho ALLOCSTACK|Gera um UWOP_ALLOC_SMALL ou um UWOP_ALLOC_LARGE com o tamanho especificado para o deslocamento atual no prólogo.<br /><br /> O operando de tamanho deve ser um múltiplo de 8.|
|. Reg SAVEREG, deslocamento|Gera um UWOP_SAVE_NONVOL ou uma entrada de código de desenrolamento UWOP_SAVE_NONVOL_FAR para o registro especificado e o deslocamento usando o deslocamento atual do prólogo. MASM escolherá a codificação mais eficiente.<br /><br /> Deslocamento deve ser positivo e um múltiplo de 8.  Deslocamento é relativo a base do quadro do procedimento, que é geralmente em RSP, ou, se usando um ponteiro de quadro, o ponteiro de quadro fora de escala.|
|. Reg SAVEXMM128, deslocamento|Gera um UWOP_SAVE_XMM128 ou uma entrada de código de desenrolamento UWOP_SAVE_XMM128_FAR para o registro de registros de MMX especificado e o deslocamento usando o deslocamento atual do prólogo. MASM escolherá a codificação mais eficiente.<br /><br /> Deslocamento deve ser positivo e um múltiplo de 16.  Deslocamento é relativo a base do quadro do procedimento, que é geralmente em RSP, ou, se usando um ponteiro de quadro, o ponteiro de quadro fora de escala.|
|. PUSHFRAME [código]|Gera uma entrada de código de desenrolamento UWOP_PUSH_MACHFRAME. Se o código opcional é especificado, a entrada de código de desenrolamento receberá um modificador de 1. Caso contrário, o modificador é 0.|
|.ENDPROLOG|Sinaliza o término das declarações do prólogo.  Deve ocorrer nos primeiros 255 bytes da função.|

Aqui está um prólogo da função de exemplo com o uso correto da maioria dos opcodes:

```
sample PROC FRAME
   db      048h; emit a REX prefix, to enable hot-patching
push rbp
.pushreg rbp
sub rsp, 040h
.allocstack 040h
lea rbp, [rsp+020h]
.setframe rbp, 020h
movdqa [rbp], xmm7
.savexmm128 xmm7, 020h;the offset is from the base of the frame
;not the scaled offset of the frame
mov [rbp+018h], rsi
.savereg rsi, 038h
mov [rsp+010h], rdi
.savereg rdi, 010h; you can still use RSP as the base of the frame
; or any other register you choose
.endprolog

; you can modify the stack pointer outside of the prologue (similar to alloca)
; because we have a frame pointer.
; if we didn’t have a frame pointer, this would be illegal
; if we didn’t make this modification,
; there would be no need for a frame pointer

sub rsp, 060h

; we can unwind from the following AV because of the frame pointer

mov rax, 0
mov rax, [rax] ; AV!

; restore the registers that weren’t saved with a push
; this isn’t part of the official epilog, as described in section 2.5

movdqa xmm7, [rbp]
mov rsi, [rbp+018h]
mov rdi, [rbp-010h]

; Here’s the official epilog

lea rsp, [rbp-020h]
pop rbp
ret
sample ENDP
```

## <a name="see-also"></a>Consulte também

[Desenrolar auxiliares para MASM](../build/unwind-helpers-for-masm.md)