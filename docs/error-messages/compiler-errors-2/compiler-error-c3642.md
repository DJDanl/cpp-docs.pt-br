---
title: "Erro do Compilador C3642 | Microsoft Docs"
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
  - "C3642"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3642"
ms.assetid: 429790c2-9614-4d85-b31c-687c8d8f83ff
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3642
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“return\_type\/args”: não pode chamar uma função com convenção de chamada de \_\_clrcall de código nativo  
  
 Uma função que é marcada com [\_\_clrcall](../../cpp/clrcall.md) que chama a convenção não pode ser chamado de código nativo \(não gerenciado\).  
  
 *return\_type\/args* é o nome da função ou o tipo da função de `__clrcall` que você está tentando chamar.  Um tipo é usado quando você está chamando por meio de um ponteiro de função.  
  
 Para chamar uma função gerenciada de um contexto nativo, você pode adicionar uma função de wrapper “” que chama a função de `__clrcall` .  Ou, você pode usar CLR que marshalling o mecanismo; consulte [Como realizar marshaling de ponteiros de função usando PInvoke](../../dotnet/how-to-marshal-function-pointers-using-pinvoke.md) para obter mais informações.  
  
 O seguinte exemplo gera C3642:  
  
```  
// C3642.cpp  
// compile with: /clr  
using namespace System;  
struct S {  
   void Test(String ^ s) {   // CLR type in signature, implicitly __clrcall  
      Console::WriteLine(s);  
   }  
   void Test2(char * s) {  
      Test(gcnew String(s));  
   }  
};  
  
#pragma unmanaged  
int main() {  
   S s;  
   s.Test("abc");   // C3642  
   s.Test2("abc");   // OK  
}  
```