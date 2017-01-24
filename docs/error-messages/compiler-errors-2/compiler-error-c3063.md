---
title: "Erro do Compilador C3063 | Microsoft Docs"
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
  - "C3063"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3063"
ms.assetid: 0ecf6f1f-e4a7-487a-9fd5-79d8ac470001
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3063
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

operador “operador”: todos os operandos devem ter o mesmo tipo de enumeração  
  
 Ao usar operadores em enumeradores, ambos os operandos devem ser do tipo de enumeração.  Para obter mais informações, consulte [Usando operadores e enumerações](../Topic/Operators%20and%20Enumerations.md).  
  
 O seguinte exemplo gera C3063:  
  
```  
// C3063.cpp  
// compile with: /clr  
enum class E { a, b } e, mask;  
int main() {  
   if ( ( e & mask ) != 0 ) ;   // C3063 no operator!= (E, int)  
  
   if ( ( e & mask ) != E() )   // OK  
      ;  
}  
```