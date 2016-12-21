---
title: "Erro do Compilador C3854 | Microsoft Docs"
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
  - "C3854"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3854"
ms.assetid: 32a9ead0-c6c7-485a-8802-c7b1fe921d3a
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3854
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

a expressão à esquerda de “\=” avalia a uma função.Não pode ser atribuído a uma função \(uma função não é um valor l\-\)  
  
 Uma referência não pode ser reiniciada.  Desreferenciar uma referência a uma função produz uma função, que é um rvalue, que não é possível atribuir.  Consequentemente, você não pode atribuir a uma referência a uma função.  
  
 O seguinte exemplo gera C3854:  
  
```  
// C3854.cpp  
int afunc(int i)  
{  
   return i;  
}  
  
typedef int (& rFunc_t)(int);  
typedef int (* pFunc_t)(int);  
  
int main()  
{  
   rFunc_t rf = afunc;   // OK binding a reference to function  
   pFunc_t pf = &afunc;   // OK initializing a pointer to function  
  
   *pf = &afunc;   // C3854  
   // try the following line instead  
   // pf = &afunc;  
   *rf = &afunc;   // C3854  
}  
```