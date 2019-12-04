---
title: Erro do compilador C2691
ms.date: 11/04/2016
f1_keywords:
- C2691
helpviewer_keywords:
- C2691
ms.assetid: 6925f8f3-ea60-4909-91e6-b781492c645d
ms.openlocfilehash: 73fd3188fd1ee4c95d8444bea0f3c05beefa478f
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760213"
---
# <a name="compiler-error-c2691"></a>Erro do compilador C2691

' tipo de dados ': um WinRTarray ou gerenciado não pode ter este tipo de elemento

O tipo de um elemento de matriz gerenciado ou WinRT pode ser um tipo de valor ou um tipo de referência.

O exemplo a seguir gera C2691:

```cpp
// C2691a.cpp
// compile with: /clr
class A {};

int main() {
   array<A>^ a1 = gcnew array<A>(20);   // C2691
   array<int>^ a2 = gcnew array<int>(20);   // value type OK
}
```
