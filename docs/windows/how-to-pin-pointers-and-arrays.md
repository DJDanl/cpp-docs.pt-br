---
title: "How to: Pin Pointers and Arrays | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "pointers, pinning"
  - "arrays [C++], pinning"
ms.assetid: ee783260-e676-46b8-a38e-11a06f1d57b0
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# How to: Pin Pointers and Arrays
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Fixar um novo objeto definido em um objeto gerenciado tem o efeito de fixar o objeto inteiro.  Por exemplo, se qualquer elemento de uma matriz é fixado, a matriz inteira é fixado também.  Não há nenhuma extensão para o idioma para declarar uma matriz fixada.  Para fixar uma matriz, declarar um ponteiro fixando\-se ao tipo de elemento, e para fixar um de seus elementos.  
  
## Exemplo  
  
### Código  
  
```  
// pin_ptr_array.cpp  
// compile with: /clr  
#include <stdio.h>  
using namespace System;  
  
int main() {  
   array<Byte>^ arr = gcnew array<Byte>(4);  
   arr[0] = 'C';  
   arr[1] = '+';  
   arr[2] = '+';  
   arr[3] = '\0';  
   pin_ptr<Byte> p = &arr[1];   // entire array is now pinned  
   unsigned char * cp = p;  
  
   printf_s("%s\n", cp); // bytes pointed at by cp  
                         // will not move during call  
}  
```  
  
### Saída  
  
```  
++  
```  
  
## Consulte também  
 [pin\_ptr \(C\+\+\/CLI\)](../Topic/pin_ptr%20\(C++-CLI\).md)