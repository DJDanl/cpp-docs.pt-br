---
title: ".PUSHFRAME | Microsoft Docs"
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
  - ".PUSHFRAME"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - ".PUSHFRAME directive"
ms.assetid: 17b123d0-4c6d-4fd2-85eb-798e8ad0a73c
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# .PUSHFRAME
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gera um `UWOP_PUSH_MACHFRAME` desenrolar a entrada de código.  Se o opcional `code` for especificado, a entrada de código de desenrolamento é fornecida um modificador de 1.  Caso contrário, o modificador é 0.  
  
## Sintaxe  
  
```  
.PUSHFRAME [code]  
```  
  
## Comentários  
 .PUSHFRAME permite que os usuários ml64.exe especificar como uma função de quadro esvazia e só é permitida no prólogo, que estende a partir do [PROC](../../assembler/masm/proc.md) declaração de quadro para o [.ENDPROLOG](../Topic/.ENDPROLOG.md) diretiva.  Essas diretivas não geram código; eles apenas geram `.xdata` e `.pdata`.  .PUSHFRAME deve ser precedido por instruções que realmente implementam as ações para ser organizado.  Ele é uma boa prática para encapsular as diretivas de desenrolamento e do código que eles se destinam à desenrolamento em uma macro para garantir que o contrato.  
  
 Para obter mais informações, consulte [MASM for x64 \(ml64.exe\)](../../assembler/masm/masm-for-x64-ml64-exe.md).  
  
## Consulte também  
 [Directives Reference](../../assembler/masm/directives-reference.md)