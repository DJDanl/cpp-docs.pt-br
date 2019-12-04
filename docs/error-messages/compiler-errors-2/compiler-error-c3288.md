---
title: Erro do compilador C3288
ms.date: 11/04/2016
f1_keywords:
- C3288
helpviewer_keywords:
- C3288
ms.assetid: ed08a540-9751-46e1-9cbe-c51d6a49ffab
ms.openlocfilehash: a7b87fdbd2e15906ebc0c669f0b9a74ebf97f0b3
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760173"
---
# <a name="compiler-error-c3288"></a>Erro do compilador C3288

' type ': desreferência inválida de um tipo de identificador

O compilador detectou uma desreferência ilegal de um tipo de identificador. Você pode desreferenciar um tipo de identificador e atribuí-lo a uma referência. Para obter mais informações, consulte [Control Reference Operator](../../extensions/tracking-reference-operator-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3288.

```cpp
// C3288.cpp
// compile with: /clr
ref class R {};
int main() {
   *(System::Object^) nullptr;   // C3288

// OK
   (System::Object^) nullptr;   // OK
   R^ r;
   R% pr = *r;
}
```
