---
title: C3642 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3642
dev_langs: C++
helpviewer_keywords: C3642
ms.assetid: 429790c2-9614-4d85-b31c-687c8d8f83ff
caps.latest.revision: "13"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 4b5d73344b99a42dfc4caf2b9f6b8cf7c9dc18bc
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c3642"></a>C3642 de erro do compilador
' return_type/args': não é possível chamar uma função com clrcall convenção de chamada do código nativo  
  
 Uma função que está marcada com o [clrcall](../../cpp/clrcall.md) convenção de chamada não pode ser chamada de código nativo (não gerenciado).  
  
 *return_type/args* é o nome da função ou o tipo do `__clrcall` função que você está tentando chamar.  Um tipo é usado quando você estiver chamando por meio de um ponteiro de função.  
  
 Para chamar uma função gerenciada em um contexto nativo, você pode adicionar uma função de "wrapper" chamará o `__clrcall` função. Ou, você pode usar o mecanismo de empacotamento do CLR; consulte [como: usando PInvoke de ponteiros de função marshaling](../../dotnet/how-to-marshal-function-pointers-using-pinvoke.md) para obter mais informações.  
  
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