---
title: Aviso do compilador (nível 1) C4383
ms.date: 11/04/2016
f1_keywords:
- C4383
helpviewer_keywords:
- C4383
ms.assetid: 96c0e52d-874e-4b57-a154-0e49b6a00fae
ms.openlocfilehash: 1c4a7ca806430c73c8e8396e596782253cc06f09
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80162732"
---
# <a name="compiler-warning-level-1-c4383"></a>Aviso do compilador (nível 1) C4383

' instance_dereference_operator ': o significado de desreferenciar um identificador pode mudar, quando existe um operador ' operador ' definido pelo usuário; gravar o operador como uma função estática para ser explícito sobre o operando

Quando você adiciona uma substituição de instância definida pelo usuário do operador de desreferência em um tipo gerenciado, é possível substituir a capacidade do operador de desreferência do tipo para retornar o objeto do identificador. Considere escrever um operador de desreferência estático definido pelo usuário.

Para obter mais informações, consulte [manipulador para operador de objeto (^)](../../extensions/handle-to-object-operator-hat-cpp-component-extensions.md) e [operador de referência de rastreamento](../../extensions/tracking-reference-operator-cpp-component-extensions.md).

Além disso, um operador de instância não está disponível para outros compiladores de linguagem por meio de metadados referenciados. Para obter mais informações, consulte [operadores definidos pelo usuárioC++(/CLI)](../../dotnet/user-defined-operators-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4383.

```cpp
// C4383.cpp
// compile with: /clr /W1

ref struct S {
   int operator*() { return 0; }   // C4383
};

ref struct T {
   static int operator*(T%) { return 0; }
};

int main() {
   S s;
   S^ pS = %s;

   T t;
   T^ pT = %t;
   T% rT = *pT;
}
```
