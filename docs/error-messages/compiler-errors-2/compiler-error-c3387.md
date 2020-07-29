---
title: Erro do compilador C3387
ms.date: 11/04/2016
f1_keywords:
- C3387
helpviewer_keywords:
- C3387
ms.assetid: c54d9925-ed14-4976-b8db-e8d4dc84e536
ms.openlocfilehash: 8218233bb7a92c699952f7a506f6728386af4d17
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221062"
---
# <a name="compiler-error-c3387"></a>Erro do compilador C3387

' member ': __declspec (dllexport)/ \_ _declspec (dllimport) não podem ser aplicados a um membro de um tipo gerenciado ou WinRT

Os `dllimport` modificadores e [dllexport](../../cpp/dllexport-dllimport.md) **`__declspec`** não são válidos em membros de um tipo gerenciado ou Windows Runtime.

O exemplo a seguir gera C3387 e mostra como corrigi-lo:

```cpp
// C3387a.cpp
// compile with: /clr /c
ref class X2 {
   void __declspec(dllexport) mf() {   // C3387
   // try the following line instead
   // void mf() {
   }
};
```
