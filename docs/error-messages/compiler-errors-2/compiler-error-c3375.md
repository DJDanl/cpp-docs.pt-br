---
title: Erro do compilador C3375
ms.date: 11/04/2016
f1_keywords:
- C3375
helpviewer_keywords:
- C3375
ms.assetid: f1df78c6-e6ca-48f3-8b29-4e1710002bf3
ms.openlocfilehash: cf92f0fabecfa7292a4d6a8644746c489cbf139f
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759744"
---
# <a name="compiler-error-c3375"></a>Erro do compilador C3375

' function ': função delegate ambígua

Uma instanciação de delegado poderia ter sido uma função membro estática ou como um delegado não associado a uma função de instância, portanto, o compilador emitiu esse erro.

Para obter mais informações, consulte [delegar (extensõesC++ de componente)](../../extensions/delegate-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3375.

```cpp
// C3375.cpp
// compile with: /clr
ref struct R {
   static void f(R^) {}
   void f() {}
};

delegate void Del(R^);

int main() {
   Del ^ a = gcnew Del(&R::f);   // C3375
}
```
