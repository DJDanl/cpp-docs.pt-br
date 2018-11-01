---
title: Erro do compilador C3149
ms.date: 11/04/2016
f1_keywords:
- C3149
helpviewer_keywords:
- C3149
ms.assetid: cf6e2616-2f06-46da-8a8a-d449cb481c51
ms.openlocfilehash: 8238dcec821256dad8101cd7ad59b2d85882c218
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50622866"
---
# <a name="compiler-error-c3149"></a>Erro do compilador C3149

'type': não é possível usar este tipo aqui sem um nível superior 'char'

Uma declaração não foi especificada corretamente.

Por exemplo, você pode ter definido um tipo CLR no escopo global e tentou criar uma variável do tipo como parte da definição. Porque as variáveis globais de tipos CLR não são permitidas, o compilador irá gerar C3149.

Para resolver esse erro, declare as variáveis de tipos CLR dentro de uma definição de função ou tipo.

O exemplo a seguir gera C3149:

```
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

```
// C3149b.cpp
// compile with: /clr /c
delegate int MyDelegate(const int, int);
void Test1(MyDelegate m) {}   // C3149
void Test2(MyDelegate ^ m) {}   // OK
```
