---
title: Erro do compilador C3073
ms.date: 11/04/2016
f1_keywords:
- C3073
helpviewer_keywords:
- C3073
ms.assetid: b24b9b8b-f9fb-4c3c-a1a0-97fad2081bfc
ms.openlocfilehash: 0b53e704c14746579a32550726364c062a9ade6f
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756741"
---
# <a name="compiler-error-c3073"></a>Erro do compilador C3073

' type ': a classe ref não tem um construtor de cópia definido pelo usuário

Em uma compilação [/CLR (Common Language Runtime compilação)](../../build/reference/clr-common-language-runtime-compilation.md) , o compilador não gerará um construtor de cópia para um tipo de referência. Em qualquer compilação **/CLR** , você deve definir seu próprio construtor de cópia para um tipo de referência se você espera que uma instância do tipo seja copiada.

Para obter mais informações, consulte [ C++ semântica de pilha para tipos de referência](../../dotnet/cpp-stack-semantics-for-reference-types.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3073.

```cpp
// C3073.cpp
// compile with: /clr
ref class R {
public:
   R(int) {}
};

ref class S {
public:
   S(int) {}
   S(const S %rhs) {}   // copy constructor
};

void f(R) {}
void f2(S) {}
void f3(R%){}

int main() {
   R r(1);
   f(r);   // C3073
   f3(r);   // OK

   S s(1);
   f2(s);   // OK
}
```
