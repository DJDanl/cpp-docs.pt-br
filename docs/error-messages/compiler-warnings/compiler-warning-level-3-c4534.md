---
title: Aviso do compilador (nível 3) C4534
ms.date: 11/04/2016
f1_keywords:
- c4534
helpviewer_keywords:
- C4534
ms.assetid: ec2adf3b-d7a1-4005-bb0c-5d219df78dc8
ms.openlocfilehash: 7d8ff442e84aa7563b1787e5a030297c034e1871
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74992060"
---
# <a name="compiler-warning-level-3-c4534"></a>Aviso do compilador (nível 3) C4534

' constructor ' não será um construtor padrão para a classe ' class ' devido ao argumento padrão

Uma classe não gerenciada pode ter um construtor com parâmetros com valores padrão e o compilador usará isso como o construtor padrão. Uma classe marcada com a palavra-chave `value` não usará um construtor com valores padrão para seus parâmetros como um construtor padrão.

Para obter mais informações, confira [Classes e structs](../../extensions/classes-and-structs-cpp-component-extensions.md).

O exemplo a seguir gera C4534:

```cpp
// C4534.cpp
// compile with: /W3 /clr /WX
value class MyClass {
public:
   int ii;
   MyClass(int i = 9) {   // C4534, will not be the default constructor
      i++;
   }
};

int main() {
   MyClass ^ xx = gcnew MyClass;
   xx->ii = 0;
}
```
