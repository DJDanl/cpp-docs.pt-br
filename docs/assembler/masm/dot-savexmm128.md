---
title: ".SAVEXMM128 | Microsoft Docs"
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
  - ".SAVEXMM128"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - ".SAVEXMM128 directive"
ms.assetid: 551eb472-b8d0-47b1-8d82-995d1f485723
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# .SAVEXMM128
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gera um um `UWOP_SAVE_XMM128` ou um `UWOP_SAVE_XMM128_FAR` desenrolar a entrada de código para o registro de XMM especificado e deslocamento usando o atual deslocamento de prólogo.  MASM escolherá a codificação mais eficiente.  
  
## Sintaxe  
  
```  
.savexmm128 xmmreg , offset  
```  
  
## Comentários  
 .SAVEXMM128 permite que os usuários ml64.exe especificar como uma função de quadro esvazia e só é permitida no prólogo, que se estende da [PROC](../../assembler/masm/proc.md) declaração de quadro para o [.ENDPROLOG](../Topic/.ENDPROLOG.md) diretiva.  Essas diretivas não geram código; eles apenas geram `.xdata` e `.pdata`.  .SAVEXMM128 deve ser precedido por instruções que realmente implementam as ações para ser organizado.  Ele é uma boa prática para encapsular as diretivas de desenrolamento e do código que eles se destinam à desenrolamento em uma macro para garantir que o contrato.  
  
 `offset`deve ser um múltiplo de 16.  
  
 Para obter mais informações, consulte [MASM for x64 \(ml64.exe\)](../../assembler/masm/masm-for-x64-ml64-exe.md).  
  
## Consulte também  
 [Directives Reference](../../assembler/masm/directives-reference.md)