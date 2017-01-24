---
title: "Aviso do compilador (n&#237;vel 3) C4334 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C4334"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4334"
ms.assetid: d845857f-bc95-4faf-a079-626a0cf935ba
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 3) C4334
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

operador “”: resultado do turno de 32 bits convertido implicitamente em 64 bits \(era o turno de 64 bits para?\)  
  
 O resultado do turno de 32 bits foi convertido implicitamente em de 64 bits, e o compilador suspeita que uma troca de 64 bits esteve pretendida.  Para resolver esse aviso, ou usar a tecla SHIFT de 64 bits, ou convertido explicitamente o resultado do turno um de 64 bits.  
  
## Exemplo  
 O exemplo a seguir produz C4334.  
  
```  
// C4334.cpp  
// compile with: /W3 /c  
void SetBit(unsigned __int64 *p, int i) {  
   *p |= (1 << i);   // C4334  
   *p |= (1i64 << i);   // OK  
}  
```