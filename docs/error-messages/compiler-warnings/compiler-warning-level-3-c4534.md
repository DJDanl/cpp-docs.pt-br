---
title: Compilador aviso (nível 3) C4534
ms.date: 11/04/2016
f1_keywords:
- c4534
helpviewer_keywords:
- C4534
ms.assetid: ec2adf3b-d7a1-4005-bb0c-5d219df78dc8
ms.openlocfilehash: 81445ff42aca78a8e40e9c88eff4bb76a41a8669
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401872"
---
# <a name="compiler-warning-level-3-c4534"></a>Compilador aviso (nível 3) C4534

'construtor' não será um construtor padrão para classe 'class' devido ao argumento padrão

Uma classe não gerenciada pode ter um construtor com parâmetros que têm valores padrão e o compilador usará isso como o construtor padrão. Uma classe marcada com o `value` palavra-chave não usará um construtor com valores padrão para seus parâmetros como um construtor padrão.

Para obter mais informações, consulte [Classes e Structs](../../extensions/classes-and-structs-cpp-component-extensions.md).

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