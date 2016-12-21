---
title: "Aviso do compilador (n&#237;vel 4) C4242 | Microsoft Docs"
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
  - "C4242"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4242"
ms.assetid: 8df742e1-fbf1-42f3-8e93-c0e1c222dc7e
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4242
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“identificador”: conversão do tipo “\- 1 " para o tipo “\- 2 ", possível perda de dados  
  
 Os tipos forem diferentes.  A conversão de tipos pode resultar na perda de dados.  O compilador faz a conversão de tipos.  
  
 Esse aviso é desativada por padrão.  Consulte [Avisos do compilador que estão por padrão](../Topic/Compiler%20Warnings%20That%20Are%20Off%20by%20Default.md) para obter mais informações.  
  
 Para obter informações adicionais sobre como C4242, consulte [Erros comuns do compilador](http://msdn.microsoft.com/library/windows/desktop/aa384160).  
  
 O seguinte exemplo gera C4242:  
  
```  
// C4242.cpp  
// compile with: /W4  
#pragma warning(4:4242)  
int func() {  
   return 0;  
}  
  
int main() {  
   char a;  
   a = func();   // C4242, return type and variable type do not match  
}  
```