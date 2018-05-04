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
ms.openlocfilehash: ff3b9dd065b4bf1f64950f97237dec08b10d23cd
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="raw-pseudo-operations"></a>Pseudo-operações brutas
Este tópico lista as operações de pseudo.  
  
## <a name="remarks"></a>Comentários  
  
|Operação de pseudo|Descrição|  
|----------------------|-----------------|  
|QUADRO de PROC [: ehandler]|Causas MASM para gerar uma função de tabela de entrada. pData e desenrolar informações .xdata para uma função do estruturado comportamento de desenrolamento de tratamento de exceção.  Se ehandler estiver presente, esse procedimento é inserido no .xdata como o identificador específico da linguagem.<br /><br /> Quando o atributo de quadro é usado, ele deve ser seguido por um. Diretiva ENDPROLOG.  Se a função é uma função de folha (conforme definido em [tipos de função](../build/function-types.md)) o quadro é desnecessária, assim como o restante dessas operações pseudo.|  
|. Reg PUSHREG|Gera uma entrada de código de desenrolamento UWOP_PUSH_NONVOL para o número de registro especificado usando o atual deslocamento no prólogo.<br /><br /> Isso só deve ser usado com registros de inteiro não volátil.  Para verificações de registradores voláteis, use um. 8 ALLOCSTACK, em vez disso|  
|. Deslocamento do registro SETFRAME|Preenche o quadro de registrar o campo e o deslocamento nas informações de liberação usando o registro especificado e o deslocamento. O deslocamento deve ser um múltiplo de 16 e menor ou igual a 240. Essa diretiva também gera uma entrada de código de desenrolamento UWOP_SET_FPREG para o registro especificado usando o deslocamento de prólogo atual.|  
|. Tamanho ALLOCSTACK|Gera um UWOP_ALLOC_SMALL ou um UWOP_ALLOC_LARGE com o tamanho especificado para o deslocamento atual no prólogo.<br /><br /> O operando de tamanho deve ser um múltiplo de 8.|  
|. Deslocamento do registro SAVEREG|Gera um UWOP_SAVE_NONVOL ou uma entrada de código de desenrolamento UWOP_SAVE_NONVOL_FAR para o registro especificado e o deslocamento usando o deslocamento de prólogo atual. MASM escolherá a codificação mais eficiente.<br /><br /> Deslocamento deve ser positivo e um múltiplo de 8.  Deslocamento é relativo a base do quadro do procedimento, que é geralmente RSP, ou, se usar um ponteiro de quadro, o ponteiro de quadro fora de escala.|  
|. Deslocamento do registro de SAVEXMM128|Gera um UWOP_SAVE_XMM128 ou uma entrada de código de desenrolamento UWOP_SAVE_XMM128_FAR para o registrador XMM especificado e o deslocamento usando o deslocamento de prólogo atual. MASM escolherá a codificação mais eficiente.<br /><br /> Deslocamento deve ser positivo e um múltiplo de 16.  Deslocamento é relativo a base do quadro do procedimento, que é geralmente RSP, ou, se usar um ponteiro de quadro, o ponteiro de quadro fora de escala.|  
|. PUSHFRAME [código]|Gera uma entrada de código de desenrolamento UWOP_PUSH_MACHFRAME. Se o código opcional for especificado, a entrada de código de desenrolamento tem um modificador de 1. Caso contrário, o modificador é 0.|  
|.ENDPROLOG|Sinaliza o término das declarações de prólogo.  Deve ocorrer nos primeiros 255 bytes da função.|  
  
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