---
title: Erro do compilador C3149
ms.date: 11/04/2016
f1_keywords:
- C3149
helpviewer_keywords:
- C3149
ms.assetid: cf6e2616-2f06-46da-8a8a-d449cb481c51
ms.openlocfilehash: 263eb03b7a9f45458f8d8b586adc6f1cfc5805be
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74745974"
---
# <a name="compiler-error-c3149"></a>Erro do compilador C3149

' type ': não é possível usar este tipo aqui sem um ' char ' de nível superior

Uma declaração não foi especificada corretamente.

Por exemplo, você pode ter definido um tipo CLR no escopo global e tentou criar uma variável do tipo como parte da definição. Como as variáveis globais dos tipos CLR não são permitidas, o compilador irá gerar C3149.

Para resolver esse erro, declare variáveis de tipos CLR dentro de uma função ou definição de tipo.

O exemplo a seguir gera C3149:

```cpp
// C3149.cpp
// compile with: /clr
using namespace System;
int main() {
   // declare an array of value types
   array< Int32 ^> IntArray;   // C3149
   array< Int32>^ IntArray2;   // OK
}
```

O exemplo a seguir gera C3149:

```cpp
// C3149b.cpp
// compile with: /clr /c
delegate int MyDelegate(const int, int);
void Test1(MyDelegate m) {}   // C3149
void Test2(MyDelegate ^ m) {}   // OK
```
