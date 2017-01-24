---
title: "Pseudo-opera&#231;&#245;es brutas | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 4def1a0e-ec28-4736-91fb-fac95fba1f36
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Pseudo-opera&#231;&#245;es brutas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico lista as operações pseudo\-.  
  
## Comentários  
  
|Operação pseudo\-|Descrição|  
|-----------------------|---------------|  
|QUADRO \\ PROC \[: ehandler\]|As causas MASM gerar uma entrada de tabela de função em .pdata e desenrolar informações em .xdata para tratamento de exceção estruturada de uma função desenrolam o comportamento.  Se o ehandler estiver presente, este é proc inseriu em .xdata como o tratador específico de linguagem.<br /><br /> Quando o atributo de QUADRO é usado, deve ser seguido por uma diretiva de .ENDPROLOG.  Se a função é uma função de folha \(como definido em [Tipos de função](../build/function-types.md)\) o atributo de QUADRO é desnecessário, como é o restante dessas pseudo de operações.|  
|Registro de .PUSHREG|Gera um UWOP\_PUSH\_NONVOL desenrolam a entrada de código para o número especificado do registro usando o deslocamento atual no prólogo.<br /><br /> Isso deve ser usado somente com registros permanentes inteiro.  Para envia de registros voláteis, use um .ALLOCSTACK 8, em vez disso|  
|Registro de .SETFRAME, deslocamento|Preenche o campo e o deslocamento de registro do quadro em informações de desenrolamento usando o registro e o deslocamento especificados.  O deslocamento deve ser um múltiplas de 16 e menor ou igual a 240.  Essa diretiva também gera um UWOP\_SET\_FPREG desenrola a entrada de código para o registro especificado usando o deslocamento atual de prólogo.|  
|Tamanho de .ALLOCSTACK|Gera um UWOP\_ALLOC\_SMALL ou um UWOP\_ALLOC\_LARGE com o tamanho especificado para o deslocamento atual no prólogo.<br /><br /> O operando de tamanho deve ser um múltiplas de 8.|  
|Registro de .SAVEREG, deslocamento|Gera ou um UWOP\_SAVE\_NONVOL ou um UWOP\_SAVE\_NONVOL\_FAR desenrola a entrada de código para o registro e o deslocamento especificados usando o deslocamento atual de prólogo.  MASM escolherá a codificação mais eficiente.<br /><br /> O deslocamento deve ser positivo, e um múltiplas de 8.  O deslocamento é relativo à base do quadro do procedimento, que é geralmente em RSP, ou, se usando um ponteiro de quadro, ponteiro não sofrem escala de quadro.|  
|.SAVEXMM128 registro, deslocamento|Gera ou um UWOP\_SAVE\_XMM128 ou um UWOP\_SAVE\_XMM128\_FAR desenrola a entrada de código para o registro especificado e o deslocamento de MMX usando o deslocamento atual de prólogo.  MASM escolherá a codificação mais eficiente.<br /><br /> O deslocamento deve ser positivo, e um múltiplas de 16.  O deslocamento é relativo à base do quadro do procedimento, que é geralmente em RSP, ou, se usando um ponteiro de quadro, ponteiro não sofrem escala de quadro.|  
|.PUSHFRAME Código \[\]|Gera um UWOP\_PUSH\_MACHFRAME desenrolam a entrada de código.  Se o código opcional é especificado, a entrada de código de desenrolamento é dada um modificador de 1.  Se não o modificador é 0.|  
|.ENDPROLOG|Sinaliza o final de declarações de prólogo.  Deve ocorrer nos primeiros 255 bytes de função.|  
  
 Aqui está um prólogo de função de exemplo com uso adequado da maioria dos opcodes:  
  
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
  
## Consulte também  
 [Auxiliares desenrolados para MASM](../build/unwind-helpers-for-masm.md)