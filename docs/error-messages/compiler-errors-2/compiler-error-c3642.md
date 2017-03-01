---
title: C3642 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3642
dev_langs:
- C++
helpviewer_keywords:
- C3642
ms.assetid: 429790c2-9614-4d85-b31c-687c8d8f83ff
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 4e6a949e6fc0aeca2785826747637137ea49cb8b
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3642"></a>C3642 de erro do compilador
' return_type/args': não é possível chamar uma função com a convenção de chamada de código nativo de clrcall  
  
 Uma função que é marcada com o [clrcall](../../cpp/clrcall.md) convenção de chamada não pode ser chamada de código nativo (não gerenciado).  
  
 *return_type/args* é o nome da função ou o tipo do `__clrcall` função que você está tentando chamar.  Um tipo é usado quando você estiver chamando por meio de um ponteiro de função.  
  
 Para chamar uma função gerenciada de um contexto nativo, você pode adicionar uma função de "wrapper" chamará o `__clrcall` função. Ou, você pode usar o mecanismo de empacotamento do CLR; consulte [como: usar PInvoke de ponteiros de função marshaling](../../dotnet/how-to-marshal-function-pointers-using-pinvoke.md) para obter mais informações.  
  
 O exemplo a seguir gera C3642:  
  
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
