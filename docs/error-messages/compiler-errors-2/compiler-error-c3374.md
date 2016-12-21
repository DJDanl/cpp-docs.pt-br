---
title: "Erro do Compilador C3374 | Microsoft Docs"
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
  - "C3374"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3374"
ms.assetid: 41431299-bd20-47d4-a0c8-1334dd79018b
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3374
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não é possível obter o endereço de 'função', a menos que a criação represente a instância  
  
 O endereço de uma função foi executado em um contexto diferente do de criação de uma instância representada.  
  
 O seguinte exemplo gera C3374:  
  
```  
// C3374.cpp  
// compile with: /clr  
public delegate void MyDel(int i);  
  
ref class A {  
public:  
   void func1(int i) {  
      System::Console::WriteLine("in func1 {0}", i);  
   }  
};  
  
int main() {  
   &A::func1;   // C3374  
  
   // OK  
   A ^ a = gcnew A;  
   MyDel ^ StaticDelInst = gcnew MyDel(a, &A::func1);  
}  
```  
  
## Consulte também  
 [Como definir e usar delegados](../Topic/How%20to:%20Define%20and%20Use%20Delegates%20\(C++-CLI\).md)