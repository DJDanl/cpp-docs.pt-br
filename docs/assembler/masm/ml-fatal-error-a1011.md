---
title: "ML Fatal Error A1011 | Microsoft Docs"
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
  - "A1011"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "A1011"
ms.assetid: 7fbf092d-4189-4330-a884-dfa2268fc3dd
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ML Fatal Error A1011
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**diretiva deve ser no bloco de controle**  
  
 O montador encontrou uma diretriz de alto nível em que um não era esperado.  Uma das seguintes diretivas foi encontrada:  
  
-   [.OUTRA](../../assembler/masm/dot-else.md) sem  [.IF](../Topic/.IF.md)  
  
-   [.ENDIF](../../assembler/masm/dot-endif.md) sem  [.IF](../Topic/.IF.md)  
  
-   [.ENDW](../../assembler/masm/dot-endw.md) sem  [.ENQUANTO](../../assembler/masm/dot-while.md)  
  
-   [.UNTILCXZ](../../assembler/masm/dot-untilcxz.md) sem  [.Repetir](../../assembler/masm/dot-repeat.md)  
  
-   [.CONTINUAR](../Topic/.CONTINUE.md) sem  [.WHILE](../../assembler/masm/dot-while.md) or [.Repetir](../../assembler/masm/dot-repeat.md)  
  
-   [.QUEBRAR](../../assembler/masm/dot-break.md) sem  [.WHILE](../../assembler/masm/dot-while.md) or [.Repetir](../../assembler/masm/dot-repeat.md)  
  
-   [.OUTRA](../../assembler/masm/dot-else.md) seguinte`.ELSE`  
  
## Consulte também  
 [ML Error Messages](../../assembler/masm/ml-error-messages.md)