---
title: ".SETFRAME | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - ".SETFRAME"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - ".SETFRAME directive"
ms.assetid: eaa9b5ed-4daa-4f1e-bdb6-100758007ab3
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# .SETFRAME
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Preenchimentos no quadro de campo e deslocamento registram as informações de desenrolamento usando o registro especificado \(`reg`\) e deslocamento \(`offset`\).  O deslocamento deve ser um múltiplo de 16 e menor ou igual a 240.  Essa diretiva também gera uma `UWOP_SET_FPREG` desenrolar a entrada de código para registrar o especificado usando o atual deslocamento de prólogo.  
  
## Sintaxe  
  
```  
.SETFRAME reg, offset  
```  
  
## Comentários  
 .SETFRAME permite que os usuários ml64.exe especificar como uma função de quadro esvazia e só é permitida no prólogo, que se estende da [PROC](../../assembler/masm/proc.md) declaração de quadro para o [.ENDPROLOG](../Topic/.ENDPROLOG.md) diretiva.  Essas diretivas não geram código; eles apenas geram `.xdata` e `.pdata`.  .SETFRAME deve ser precedido por instruções que realmente implementam as ações para ser organizado.  Ele é uma boa prática para encapsular as diretivas de desenrolamento e do código que eles se destinam à desenrolamento em uma macro para garantir que o contrato.  
  
 Para obter mais informações, consulte [MASM for x64 \(ml64.exe\)](../../assembler/masm/masm-for-x64-ml64-exe.md).  
  
## Exemplo  
  
### Descrição  
 O exemplo a seguir mostra como usar um ponteiro de quadro:  
  
### Código  
  
```  
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
  
## Consulte também  
 [Directives Reference](../../assembler/masm/directives-reference.md)