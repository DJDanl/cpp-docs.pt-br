---
title: Erro do compilador C3274 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3274
dev_langs:
- C++
helpviewer_keywords:
- C3274
ms.assetid: 1f03f18e-b569-48eb-9249-11c70122a305
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 424b6be69559932ac6f16dc83e39257e414a2120
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46088482"
---
# <a name="compiler-error-c3274"></a>Erro do compilador C3274

Finally/finally sem try correspondente

Um [Finally](../../cpp/try-finally-statement.md) ou [finalmente](../../dotnet/finally.md) instrução foi encontrada sem encontrar uma correspondência `try`. Para resolver esse problema, excluir o `__finally` instrução ou adicione uma `try` instrução para o `__finally`.

O exemplo a seguir gera C3274:

```
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