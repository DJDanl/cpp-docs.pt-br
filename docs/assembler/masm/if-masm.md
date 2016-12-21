---
title: "IF (MASM) | Microsoft Docs"
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
  - "if"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "IF directive"
ms.assetid: 82e43712-4f0c-4bf6-90ce-0663e81af707
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# IF (MASM)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Concede a montagem do  *ifstatements* se  *Expressão1* é verdadeiro \(diferente de zero\) ou  *elseifstatements* se  *Expressão1* for false \(0\) e  *Expressão2* é verdadeiro.  
  
## Sintaxe  
  
```  
  
   IF expression1  
ifstatements  
[[ELSEIF expression2  
   elseifstatements]]  
[[ELSE  
   elsestatements]]  
ENDIF  
```  
  
## Comentários  
 As seguintes diretivas podem ser substituídas por  [ELSEIF](../../assembler/masm/elseif-masm.md):  **ELSEIFB**,  **ELSEIFDEF**,  **ELSEIFDIF**,  **ELSEIFDIFI**,  **ELSEIFE**,  **ELSEIFIDN**,  **ELSEIFIDNI**,  **ELSEIFNB**, e  **ELSEIFNDEF**.  Opcionalmente, monta  *elsestatements* se a expressão anterior for falsa.  Observe que as expressões são avaliadas no momento do assembly.  
  
## Consulte também  
 [Directives Reference](../../assembler/masm/directives-reference.md)