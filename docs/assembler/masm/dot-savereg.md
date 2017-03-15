---
title: ".SAVEREG | Microsoft Docs"
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
  - ".SAVEREG"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - ".SAVEREG directive"
ms.assetid: 1dbc2ef6-a197-40e7-9e55-fddcae8cef29
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# .SAVEREG
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gera um um `UWOP_SAVE_NONVOL` ou um `UWOP_SAVE_NONVOL_FAR` desenrolar a entrada de código para o registro especificado \(`reg`\) e deslocamento \(`offset`\) usando o atual deslocamento de prólogo.  MASM escolherá a codificação mais eficiente.  
  
## Sintaxe  
  
```  
.SAVEREG reg, offset  
```  
  
## Comentários  
 .SAVEREG permite que os usuários ml64.exe especificar como uma função de quadro esvazia e só é permitida no prólogo, que estende a partir do [PROC](../../assembler/masm/proc.md) declaração de quadro para o [.ENDPROLOG](../Topic/.ENDPROLOG.md) diretiva.  Essas diretivas não geram código; eles apenas geram `.xdata` e `.pdata`.  .SAVEREG deve ser precedido por instruções que realmente implementam as ações para ser organizado.  Ele é uma boa prática para encapsular as diretivas de desenrolamento e do código que eles se destinam à desenrolamento em uma macro para garantir que o contrato.  
  
 Para obter mais informações, consulte [MASM for x64 \(ml64.exe\)](../../assembler/masm/masm-for-x64-ml64-exe.md).  
  
## Consulte também  
 [Directives Reference](../../assembler/masm/directives-reference.md)