---
title: "Erro do Compilador C2845 | Microsoft Docs"
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
  - "C2845"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2845"
ms.assetid: 31b28ee9-978f-403b-94d8-dbaacd24cce0
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2845
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

operador “”: aritmética do ponteiro não permitida neste tipo  
  
 Não é possível incrementar o ponteiro para uma classe gerenciada.  
  
 **Extensões gerenciadas para C\+\+**  
  
 Não é possível incrementar o ponteiro para uma classe de [\_\_gc](../Topic/__gc.md) .  Além disso, os operadores de cadeia de caracteres só são válidos com **\/clr** \(não **\/clr:oldSyntax**\).  
  
 O seguinte exemplo gera C2845:  
  
```  
// C2845b.cpp  
// compile with: /clr:oldSyntax  
using namespace System;  
__gc class X {};  
  
int main() {  
   X *pX = new X;  
   pX++;   // C2845  
  
   String * a = new String("abc");  
   String * b = new String("def");  
   Console::WriteLine(a + b);   // C2845 not with /clr:oldSyntax  
}  
```