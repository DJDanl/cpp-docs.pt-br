---
title: Erro do compilador C3367
ms.date: 11/04/2016
f1_keywords:
- C3367
helpviewer_keywords:
- C3367
ms.assetid: e675d42b-f5b0-4d43-aab1-1f5024233102
ms.openlocfilehash: f53312fa9225270ef79d50d2ad351adce790d6fa
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62300525"
---
# <a name="compiler-error-c3367"></a>Erro do compilador C3367

'static_member_function': não é possível usar função static para criar um delegate não associado

Quando você chama um delegate não associado, você deve passar uma instância de um objeto. Uma vez que uma função de membro estático é chamada pelo nome da classe, você só pode instanciar um delegate não associado com uma função de membro de instância.

Para obter mais informações sobre delegados não associados, consulte [como: Definir e usar delegados (C++/CLI)](../../dotnet/how-to-define-and-use-delegates-cpp-cli.md).

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