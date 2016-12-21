---
title: "How to: Declare Pinning Pointers and Value Types | Microsoft Docs"
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
  - "value types, declaring"
  - "pinning pointers"
ms.assetid: 57c5ec8a-f85a-48c4-ba8b-a81268bcede0
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# How to: Declare Pinning Pointers and Value Types
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um tipo de valor pode ser implicitamente encaixotado.  Você pode declarar um ponteiro fixando\-se ao objeto do tipo de valor em si e usar **pin\_ptr** ao tipo de valor encaixotado.  
  
## Exemplo  
  
### Código  
  
```  
// pin_ptr_value.cpp  
// compile with: /clr  
value struct V {  
   int i;  
};  
  
int main() {  
   V ^ v = gcnew V;   // imnplicit boxing  
   v->i=8;  
   System::Console::WriteLine(v->i);  
   pin_ptr<V> mv = &*v;  
   mv->i = 7;  
   System::Console::WriteLine(v->i);  
   System::Console::WriteLine(mv->i);  
}  
```  
  
### Saída  
  
```  
8  
7  
7  
```  
  
## Consulte também  
 [pin\_ptr \(C\+\+\/CLI\)](../Topic/pin_ptr%20\(C++-CLI\).md)