---
title: "Erro do Compilador C2675 | Microsoft Docs"
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
  - "C2675"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2675"
ms.assetid: 4b92a12b-bff8-4dd5-a109-620065fc146c
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2675
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“operador unário”: o tipo “” não define esse operador ou uma conversão de em um tipo aceitável para o operador predefinido  
  
 C2675 também pode ocorrer ao usar um operador unário, e o tipo não define o operador ou a conversão em um tipo aceitável para o operador predefinido.  Para usar o operador, você deve sobrecarregá\-la do tipo especificado ou definir uma conversão de em um tipo para o qual o operador está definido.  
  
## Exemplo  
 O exemplo a seguir produz C2675.  
  
```  
// C2675.cpp  
struct C {   
   C(){}  
} c;  
  
struct D {   
   D(){}  
   void operator-(){}  
} d;  
  
int main() {  
   -c;   // C2675  
   -d;   // OK  
}  
```