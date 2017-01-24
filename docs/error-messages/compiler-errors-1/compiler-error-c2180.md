---
title: "Erro do Compilador C2180 | Microsoft Docs"
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
  - "C2180"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2180"
ms.assetid: ea71b39e-b977-48a7-b7bd-af68ef5e263b
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2180
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Controlando a expressão tem o tipo 'type'  
  
 A expressão de controle em um `if`, `while`, `for`, ou `do` instrução é uma expressão convertida em `void`.  Para corrigir esse problema, altere a expressão de controle para uma que produza um `bool` ou um tipo que pode ser convertido em `bool`.  
  
 O exemplo a seguir gera C2180:  
  
```  
// C2180.c  
  
int main() {  
   while ((void)1)   // C2180  
      return 1;  
   while (1)         // OK  
      return 0;  
}  
```