---
title: "Aviso do compilador (n&#237;vel 2) C4356 | Microsoft Docs"
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
  - "C4356"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4356"
ms.assetid: 3af3defe-de33-43b6-bd6c-2c2e09e34f3f
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 2) C4356
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“membro”: o membro estático de dados não pode ser iniciado pela classe derivada  
  
 A inicialização de um membro estático de dados estava incorreto formado.  O compilador aceitou a inicialização.  
  
 Essa é uma alteração no compilador do Visual C\+\+ .NET 2003.  
  
 Para o código que funciona da mesma maneira em todas as versões do Visual C\+\+, inicializar o membro pela classe base.  
  
 Use o pragma de [warning](../../preprocessor/warning.md) para suprimir o aviso.  
  
 O seguinte exemplo gera C4356:  
  
```  
// C4356.cpp  
// compile with: /W2 /EHsc  
#include <iostream>  
  
template <class T>  
class C {  
   static int n;  
};  
  
class D : C<int> {};  
  
int D::n = 0; // C4356  
// try the following line instead  
// int C<int>::n = 0;  
  
class A {  
public:  
   static int n;  
};  
  
class B : public A {};  
  
int B::n = 10;   // C4356  
// try the following line instead  
// int A::n = 99;  
  
int main() {  
   using namespace std;  
   cout << B::n << endl;  
}  
```