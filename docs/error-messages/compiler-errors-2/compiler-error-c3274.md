---
title: Erro do compilador C3274
ms.date: 11/04/2016
f1_keywords:
- C3274
helpviewer_keywords:
- C3274
ms.assetid: 1f03f18e-b569-48eb-9249-11c70122a305
ms.openlocfilehash: c2c7de919181cd0e89526f8ffacabaec73fb8f89
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223428"
---
# <a name="compiler-error-c3274"></a>Erro do compilador C3274

__finally/finally sem tentativa de correspondência

Uma instrução [__finally](../../cpp/try-finally-statement.md) ou [finally](../../dotnet/finally.md) foi encontrada sem uma correspondência **`try`** . Para resolver isso, exclua a **`__finally`** instrução ou adicione uma **`try`** instrução para **`__finally`** .

O exemplo a seguir gera C3274:

```cpp
// C3274.cpp
// compile with: /clr
// C3274 expected
using namespace System;
int main() {
   try {
      try {
         throw gcnew ApplicationException();
      }
      catch(...) {
         Console::Error->WriteLine(L"Caught an exception");
      }
      finally {
         Console::WriteLine(L"In finally");
      }
   } finally {
      Console::WriteLine(L"In finally");
   }

   // Uncomment the following 3 lines to resolve.
   // try {
   //   throw gcnew ApplicationException();
   // }

   finally {
      Console::WriteLine(L"In finally");
   }
   Console::WriteLine(L"**FAIL**");
}
```
