---
title: Erro do compilador C3153
ms.date: 11/04/2016
f1_keywords:
- C3153
helpviewer_keywords:
- C3153
ms.assetid: d775d97e-2480-484f-81f1-88406b10f947
ms.openlocfilehash: 54fa7de8eb3df8d4b3695544c5285cc202275492
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74745909"
---
# <a name="compiler-error-c3153"></a>Erro do compilador C3153

' interface ': não é possível criar uma instância de uma interface

Uma interface não pode ser instanciada. Para usar os membros de uma interface, derive uma classe da interface, implemente os membros da interface e, em seguida, use os membros.

O exemplo a seguir gera C3153:

```cpp
// C3153.cpp
// compile with: /clr
interface class A {
};

int main() {
   A^ a = gcnew A;   // C3153
}
```
