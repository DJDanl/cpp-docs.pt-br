---
title: "Como capturar exce&#231;&#245;es em c&#243;digo nativo lan&#231;adas a partir de MSIL | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "capturando exceções, lançadas de MSIL"
  - "exceções, capturando"
  - "MSIL, capturando exceções no código nativo"
ms.assetid: c15afd2b-8505-43bf-8a4a-f1d41532a124
caps.latest.revision: 9
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como capturar exce&#231;&#245;es em c&#243;digo nativo lan&#231;adas a partir de MSIL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Em código nativo, você pode capturar a exceção C\+\+ nativo de MSIL.  Você pode capturar exceções de CLR com `__try` e `__except`.  
  
 Para obter mais informações, consulte [Tratamento de exceções estruturado](../cpp/structured-exception-handling-c-cpp.md) e [Tratamento de exceções C\+\+](../cpp/cpp-exception-handling.md).  
  
## Exemplo  
 O exemplo a seguir define um módulo com duas funções, uma que gerará uma exceção nativo, e outra que gerará uma exceção de MSIL.  
  
```  
// catch_MSIL_in_native.cpp  
// compile with: /clr /c  
void Test() {  
   throw ("error");  
}  
  
void Test2() {  
   throw (gcnew System::Exception("error2"));  
}  
```  
  
## Exemplo  
 O exemplo a seguir define um módulo que captura um nativo e a exceção de MSIL.  
  
```  
// catch_MSIL_in_native_2.cpp  
// compile with: /clr catch_MSIL_in_native.obj  
#include <iostream>  
using namespace std;  
void Test();  
void Test2();  
  
void Func() {  
   // catch any exception from MSIL  
   // should not catch Visual C++ exceptions like this  
   // runtime may not destroy the object thrown  
   __try {  
      Test2();  
   }  
   __except(1) {  
      cout << "caught an exception" << endl;  
   }  
  
}  
  
int main() {  
   // catch native C++ exception from MSIL  
   try {  
      Test();  
   }  
   catch(char * S) {  
      cout << S << endl;  
   }  
   Func();  
}  
```  
  
  **erro**  
**capturar uma exceção**   
## Consulte também  
 [Exception Handling](../windows/exception-handling-cpp-component-extensions.md)