---
title: Erro do compilador C3375
ms.date: 11/04/2016
f1_keywords:
- C3375
helpviewer_keywords:
- C3375
ms.assetid: f1df78c6-e6ca-48f3-8b29-4e1710002bf3
ms.openlocfilehash: ba1dbf08fb56364d2ab5b8c40847ab89484dc005
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "58781387"
---
# <a name="compiler-error-c3375"></a>Erro do compilador C3375

'function': função delegate ambígua

Uma instanciação de delegado poderia ter sido para uma função de membro estático, ou como um delegate não associado a uma função de instância, portanto, o compilador emitiu esse erro.

Para obter mais informações, consulte [delegado (extensões de componentes C++)](../../extensions/delegate-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3375.

```
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