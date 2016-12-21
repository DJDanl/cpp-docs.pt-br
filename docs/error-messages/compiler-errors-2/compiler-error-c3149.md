---
title: "Erro do Compilador C3149 | Microsoft Docs"
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
  - "C3149"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3149"
ms.assetid: cf6e2616-2f06-46da-8a8a-d449cb481c51
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3149
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“tipo”: não pode usar esse tipo aqui sem um “char de nível superior”  
  
 Uma declaração não foi especificado corretamente.  
  
 Por exemplo, você pode ter definido um tipo CLR no escopo global e que ele seja tentado criar uma variável de tipo como parte da definição.  Como as variáveis globais de tipos CLR não são permitidos, o compilador gerará C3149.  
  
 Para resolver este erro, declarar variáveis de tipos CLR dentro de uma função ou de uma definição do tipo.  
  
 O seguinte exemplo gera C3149:  
  
```  
// C3149.cpp  
// compile with: /clr  
using namespace System;  
int main() {  
   // declare an array of value types   
   array< Int32 ^> IntArray;   // C3149  
   array< Int32>^ IntArray2;   // OK  
}  
```  
  
 O seguinte exemplo gera C3149:  
  
```  
// C3149b.cpp  
// compile with: /clr /c  
delegate int MyDelegate(const int, int);  
void Test1(MyDelegate m) {}   // C3149  
void Test2(MyDelegate ^ m) {}   // OK  
```  
  
 **Extensões gerenciadas para C\+\+**  
  
 Um objeto gerenciado não foi usada corretamente.  
  
 O seguinte exemplo gera C3149:  
  
```  
// C3149c.cpp  
// compile with: /clr:oldSyntax  
__gc class A {};  
  
int main() {  
   A a = new A;   // C3149  
   A *a = new A;   // OK  
}  
```