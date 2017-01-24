---
title: "Erro do Compilador C3166 | Microsoft Docs"
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
  - "C3166"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3166"
ms.assetid: ec3e330d-c15d-4158-8268-09101486c566
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3166
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“ponteiro”: não pode declarar um ponteiro para um ponteiro dentro de \_\_gc como um membro de “tipo”  
  
 O compilador encontrou uma declaração do ponteiro inválido \(um ponteiro de [\_\_nogc](../../misc/nogc.md) a um ponteiro de [\_\_gc](../Topic/__gc.md) .\).  Essa sintaxe pode ser suporte em uma versão futura.  
  
 C3166 é somente **\/clr:oldSyntax**de utilização possível acessá\-lo.  
  
 O seguinte exemplo gera C3166:  
  
```  
// C3166.cpp  
// compile with: /clr:oldSyntax  
#using <mscorlib.dll>  
using namespace System;  
  
__gc struct G {  
   int __gc* __nogc* p;   // C3166  
};  
  
public __gc class H {  
public:  
   Int32 __gc* __nogc* p;   // C3166  
};  
  
public __value struct I {  
   int __gc* __nogc* p;   // C3166  
};  
  
public __value class J {  
public:  
   int __gc* __nogc* p;   // C3166  
};  
  
int main() {  
   G* pG = new G;  
   H* pH = new H;  
}  
```