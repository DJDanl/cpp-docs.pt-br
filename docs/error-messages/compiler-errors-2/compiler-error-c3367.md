---
title: Erro do compilador C3367
ms.date: 11/04/2016
f1_keywords:
- C3367
helpviewer_keywords:
- C3367
ms.assetid: e675d42b-f5b0-4d43-aab1-1f5024233102
ms.openlocfilehash: bedc94039f8621a93672c0dfa0cad5a54aad796e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80201156"
---
# <a name="compiler-error-c3367"></a>Erro do compilador C3367

' static_member_function ': não é possível usar a função static para criar um delegado não associado

Ao chamar um delegado não associado, você deve passar uma instância de um objeto. Como uma função de membro estático é chamada por meio do nome de classe, você só pode instanciar um delegado não associado com uma função de membro de instância.

Para obter mais informações sobre delegados não associados, consulte [How to: define and use delegatesC++(/CLI)](../../dotnet/how-to-define-and-use-delegates-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3367.

```cpp
// C3367.cpp
// compile with: /clr
ref struct R {
   void b() {}
   static void f() {}
};

delegate void Del(R^);

int main() {
   Del ^ a = gcnew Del(&R::b);   // OK
   Del ^ b = gcnew Del(&R::f);   // C3367
}
```
