---
title: "Compilador C4130 de aviso (n&#237;vel 4) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C4130"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4130"
ms.assetid: 45e4c7b2-6b51-41c7-ba5e-941aa5c7d3dc
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4130 de aviso (n&#237;vel 4)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'operator': a operação lógica no endereço da constante de cadeia de caracteres  
  
 Usando o operador com o endereço de uma cadeia de caracteres literal produz código inesperado.  
  
 O exemplo a seguir gera C4130:  
  
```  
// C4130.cpp // compile with: /W4 int main() { char *pc; pc = "Hello"; if (pc == "Hello") // C4130 { } }  
```  
  
 O **se** instrução compara o valor armazenado no ponteiro `pc` para o endereço da cadeia de caracteres "Hello", que é alocada separadamente cada vez que a cadeia de caracteres ocorre no código. O **se** instrução compara a cadeia de caracteres apontada por `pc` com a cadeia de caracteres "Hello".  
  
 Para comparar cadeias de caracteres, use o `strcmp` função.