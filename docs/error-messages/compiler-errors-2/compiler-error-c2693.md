---
title: "Erro do Compilador C2693 | Microsoft Docs"
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
  - "C2693"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2693"
ms.assetid: b7364ca8-b6be-48c0-97d6-6029787fb171
caps.latest.revision: 15
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2693
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'operator': comparação ilegal para referências a gerenciada ou uma matriz do WinRT  
  
 Você não pode testar um gerenciado ou matriz WinRT para qualquer tipo de desigualdade.  Por exemplo, você pode testar para ver se gerenciado matrizes são iguais, mas você não pode testar para ver se uma matriz é maior ou menor que outro conjunto.  
  
 **Extensões gerenciadas do C\+\+**  
  
 Não é possível testar uma [GC](../Topic/__gc.md) matriz para qualquer tipo de desigualdade.  Por exemplo, você pode testar para ver se gerenciado matrizes são iguais, mas você não pode testar para ver se uma matriz é maior ou menor que outro conjunto.  
  
 O exemplo a seguir gera C2693:  
  
```  
// C2693b.cpp  
// compile with: /clr:oldSyntax /c  
#using <mscorlib.dll>  
int func3(int a __gc[], int b __gc[]) {  
   return a < b;    // C2693  
}  
int func1(int a __gc[], int b __gc[]) {  
   return a != b;   // OK  
}  
  
int func2(int a __gc[], int b __gc[]) {  
   return a == b;   // OK  
}  
```