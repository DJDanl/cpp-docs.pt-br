---
title: Erro do compilador C3628
ms.date: 11/04/2016
f1_keywords:
- C3628
helpviewer_keywords:
- C3628
ms.assetid: 0ff5a4a4-fcc9-47a0-a4d8-8af9cf2815f6
ms.openlocfilehash: 9976cb2425f8f855ffb2903c07de22822c781e20
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74755818"
---
# <a name="compiler-error-c3628"></a>Erro do compilador C3628

' classe base ': somente gerenciado ou WinRTclasses dão suporte à herança pública

Foi feita uma tentativa de usar uma classe gerenciada ou WinRT como uma classe base [privada](../../cpp/private-cpp.md) ou [protegida](../../cpp/protected-cpp.md) . Uma classe gerenciada ou WinRT só pode ser usada como uma classe base com acesso [público](../../cpp/public-cpp.md) .

O exemplo a seguir gera C3628 e mostra como corrigi-lo:

```cpp
// C3628a.cpp
// compile with: /clr
ref class B {
};

ref class D : private B {   // C3628

// The following line resolves the error.
// ref class D : public B {
};

int main() {
}
```
