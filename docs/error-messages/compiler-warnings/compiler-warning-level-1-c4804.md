---
title: "Aviso do compilador (n&#237;vel 1) C4804 | Microsoft Docs"
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
  - "C4804"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4804"
ms.assetid: 069e8f44-3ef6-43bb-8524-4116fc6eea83
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4804
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“operação”: uso não segura do tipo “bool” na operação  
  
 Esse aviso é para quando você usou uma variável ou um valor de `bool` de uma maneira inesperada.  Por exemplo, C4804 será gerado se você usar operadores como o operador unário \(negativo\) ou**\-**o operador de complemento \(`~`\).  O compilador avalia a expressão.  
  
## Exemplo  
 O seguinte exemplo gera C4804:  
  
```  
// C4804.cpp  
// compile with: /W1  
  
int main()  
{  
   bool i = true;  
   if (-i)   // C4804, remove the '-' to resolve  
   {  
      i = false;  
   }  
}  
```