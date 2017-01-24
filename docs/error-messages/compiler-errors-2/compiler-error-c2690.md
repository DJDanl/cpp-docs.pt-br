---
title: "Erro do Compilador C2690 | Microsoft Docs"
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
  - "C2690"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2690"
ms.assetid: f165a806-14bd-4942-99b7-8a9fc7dea227
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2690
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'operator': não é possível executar operações aritméticas com gerenciada de ponteiro ou matriz de WinRT  
  
 Aritmética de ponteiro não é permitida em gerenciada ou WinRT matriz.  Use a notação de índice de matriz para percorrer a matriz.  
  
 **Extensões gerenciadas do C\+\+**  
  
 Aritmética de ponteiro não é permitida em uma [GC](../Topic/__gc.md) matriz.  Use a notação de índice de matriz para percorrer a matriz.  
  
 O exemplo a seguir gera C2690:  
  
```  
// C2690b.cpp  
// compile with: /clr:oldSyntax  
#using <mscorlib.dll>  
using namespace System;  
  
int main() {  
   String* x[] = new String*[10];  
   x[0] = "test";  
   Console::WriteLine(x[0]);  
   x++;   // C2690  
}  
```