---
title: "Erro do Compilador C3265 | Microsoft Docs"
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
  - "C3265"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3265"
ms.assetid: 10ab3e17-4a9f-4120-bab5-21473869b70f
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3265
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não pode declarar um gerenciado “na construção” em uma construção não gerenciado não gerenciado”  
  
 Você não pode incluir um objeto gerenciado em um contexto não gerenciado.  
  
 O exemplo C3265 reproduz:  
  
```  
// C3265_2.cpp  
// compile with: /clr /LD  
#include <vcclr.h>  
  
ref class A { };  
  
class B  
// try the following line instead  
// ref class B   
{  
   A ^a;   // C3265  
   // or embed the managed handle using gcroot  
   // try the following line instead  
   // gcroot<A^> a;  
};  
```  
  
 O exemplo C3265 reproduz:  
  
```  
// C3265.cpp  
// compile with: /clr:oldSyntax /LD  
#using <mscorlib.dll>  
__gc class A { };  
  
__nogc class B  
// try the following line instead  
// __gc class B   
{  
   A *a;   // C3265  
};  
```  
  
 C3265 também poderá ocorrer se você inserir um ponteiro gerenciado diretamente dentro de uma classe não gerenciado.  Para corrigir esse erro, use `gcroot`:  
  
```  
// C3265b.cpp  
// compile with: /clr:oldSyntax  
#include <vcclr.h>  
#using <mscorlib.dll>  
  
namespace TestNS {  
   __gc public class Test{};  
}  
  
template<class T>  
struct Container {  
  T* m_px;   // C3265  
};  
__gc public class ClassA {  
public:  
  ClassA (){}  
   ~ClassA(){}  
  
private:  
   Container<TestNS::Test*>  vctTest;  
   // try the following line instead  
   Container<gcroot<TestNS::Test* > > vctTest2;  
};  
```