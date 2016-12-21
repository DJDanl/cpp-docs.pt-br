---
title: "Erro do Compilador C2425 | Microsoft Docs"
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
  - "C2425"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2425"
ms.assetid: 0ce59404-9aff-4e01-aa8d-27d23e92eb30
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2425
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

"token": expressão não constante no "contexto"  
  
 O token faz parte de uma expressão não constante neste contexto.  
  
 Para corrigir esse problema, substitua o token por uma constante literal ou um cálculo.  
  
 O seguinte exemplo gera C2425:  
  
```  
// C2425.cpp  
// processor: x86  
int main() {  
   int i = 3;  
   __asm {  
      mov eax, [ebp - i]   // C2425  
      mov eax, [ebp - 3]   // OK  
   }  
}  
```