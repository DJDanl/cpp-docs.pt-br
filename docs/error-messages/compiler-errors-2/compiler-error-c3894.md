---
title: "Erro do Compilador C3894 | Microsoft Docs"
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
  - "C3894"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3894"
ms.assetid: 6d5ac903-1dea-431d-8e3a-cebca4342983
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3894
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

var “”: o uso de l\- valor do membro de dados initonly estático é permitido apenas ao construtor de classe das classes das classes  
  
 Os membros de dados estáticos de [initonly](../../dotnet/initonly-cpp-cli.md) só podem ser usados como l\- valores em seu ponto de declaração, ou em um construtor estático.  
  
 Os membros de dados de instância \(não estático\) initonly só podem ser usados como l\- valores em seu ponto de declaração, ou construtores de instância \(não estático\).  
  
 O seguinte exemplo gera C3894:  
  
```  
// C3894.cpp  
// compile with: /clr  
ref struct Y1 {  
   initonly static int data_var = 0;  
  
public:  
   // class constructor  
   static Y1() {  
      data_var = 99;   // OK  
      System::Console::WriteLine("in static constructor");  
   }  
  
   // not the class constructor  
   Y1(int i) {  
      data_var = i;   // C3894  
   }  
  
   static void Test() {}  
  
};  
  
int main() {  
   Y1::data_var = 88;   // C3894  
   int i = Y1::data_var;  
   Y1 ^ MyY1 = gcnew Y1(99);  
   Y1::Test();  
}  
```