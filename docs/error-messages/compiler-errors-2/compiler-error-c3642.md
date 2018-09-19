---
title: Erro do compilador C3642 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3642
dev_langs:
- C++
helpviewer_keywords:
- C3642
ms.assetid: 429790c2-9614-4d85-b31c-687c8d8f83ff
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: febd6f1a9a3b4bac8bbee59cbf8c5bead93c3fb3
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46047714"
---
# <a name="compiler-error-c3642"></a>Erro do compilador C3642

' return_type/args': não é possível chamar uma função com clrcall convenção de chamada do código nativo

Uma função que é marcada com o [clrcall](../../cpp/clrcall.md) convenção de chamada não pode ser chamada de código nativo (não gerenciado).

*args/return_type* é o nome da função ou o tipo do `__clrcall` função que você está tentando chamar.  Um tipo é usado ao chamar por meio de um ponteiro de função.

Para chamar uma função gerenciada de um contexto nativo, você pode adicionar uma função de "wrapper" que chamará o `__clrcall` função. Ou, você pode usar o mecanismo de empacotamento do CLR; ver [como: usar PInvoke de ponteiros de função marshaling](../../dotnet/how-to-marshal-function-pointers-using-pinvoke.md) para obter mais informações.

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