---
title: "Erro do Compilador C2617 | Microsoft Docs"
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
  - "C2617"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2617"
ms.assetid: d6a435d2-7d95-4dbf-ad4a-abe4744f63e8
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2617
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: instrução de retorno inconsistente  
  
 A função especificada não tiver um tipo de retorno declarado, e uma instrução de retorno anterior não forneceu um valor.  
  
 O seguinte exemplo gera C2617:  
  
```  
// C2617.cpp  
int i;  
func() {   // no return type prototype  
   if( i ) return;   // no return value  
   else return( 1 );   // C2617 detected on this line  
}  
```  
  
 Solução possível:  
  
```  
// C2617b.cpp  
// compile with: /c  
int i;  
int MyF() {  
   if (i)  
      return 0;  
   else   
      return (1);  
}  
```