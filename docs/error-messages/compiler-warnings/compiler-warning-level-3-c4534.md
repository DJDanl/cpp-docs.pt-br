---
title: Compilador aviso (nível 3) C4534
ms.date: 11/04/2016
f1_keywords:
- c4534
helpviewer_keywords:
- C4534
ms.assetid: ec2adf3b-d7a1-4005-bb0c-5d219df78dc8
ms.openlocfilehash: a2af04502082f7fb30d59af5e6434161227c6d30
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50437233"
---
# <a name="compiler-warning-level-3-c4534"></a>Compilador aviso (nível 3) C4534

'construtor' não será um construtor padrão para classe 'class' devido ao argumento padrão

Uma classe não gerenciada pode ter um construtor com parâmetros que têm valores padrão e o compilador usará isso como o construtor padrão. Uma classe marcada com o `value` palavra-chave não usará um construtor com valores padrão para seus parâmetros como um construtor padrão.

Para obter mais informações, consulte [Classes e Structs](../../windows/classes-and-structs-cpp-component-extensions.md).

O exemplo a seguir gera C4534:

```
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