---
title: Erro do compilador C3642
ms.date: 11/04/2016
f1_keywords:
- C3642
helpviewer_keywords:
- C3642
ms.assetid: 429790c2-9614-4d85-b31c-687c8d8f83ff
ms.openlocfilehash: 7c3f9f05bf04c9a1c20fff7910836e7b50468a8e
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74742451"
---
# <a name="compiler-error-c3642"></a>Erro do compilador C3642

' return_type/args ': não é possível chamar uma função com __clrcall Convenção de chamada de código nativo

Uma função que é marcada com a Convenção de chamada [__clrcall](../../cpp/clrcall.md) não pode ser chamada de código nativo (não gerenciado).

*return_type/args* é o nome da função ou o tipo da função `__clrcall` que você está tentando chamar.  Um tipo é usado quando você está chamando por um ponteiro de função.

Para chamar uma função gerenciada de um contexto nativo, você pode adicionar uma função de "wrapper" que chamará a função `__clrcall`. Ou, você pode usar o mecanismo de Marshalling do CLR; consulte [como realizar marshaling de ponteiros de função usando o PInvoke](../../dotnet/how-to-marshal-function-pointers-using-pinvoke.md) para obter mais informações.

O exemplo a seguir gera C3642:

```cpp
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
