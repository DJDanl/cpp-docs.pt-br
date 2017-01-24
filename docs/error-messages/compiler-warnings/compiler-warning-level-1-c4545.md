---
title: "Aviso do compilador (n&#237;vel 1) C4545 | Microsoft Docs"
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
  - "C4545"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4545"
ms.assetid: 43f8f34f-ed46-4661-95c0-c588c577ff73
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4545
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

expressão antes que a vírgula avaliar a uma função que está faltando uma lista de argumentos  
  
 O compilador detectou uma expressão doente\- formada de vírgula.  
  
 Esse aviso é desativada por padrão.  Para obter mais informações, consulte [Avisos do compilador que estão por padrão](../Topic/Compiler%20Warnings%20That%20Are%20Off%20by%20Default.md).  
  
 O seguinte exemplo gera C4545:  
  
```  
// C4545.cpp  
// compile with: /W1  
#pragma warning (default : 4545)  
  
void f() { }  
  
int main()  
{  
   *(&f), 10;   // C4545  
   // try the following line instead  
   // (*(&f))(), 10;  
}  
```