---
title: Erro do compilador C3073
ms.date: 11/04/2016
f1_keywords:
- C3073
helpviewer_keywords:
- C3073
ms.assetid: b24b9b8b-f9fb-4c3c-a1a0-97fad2081bfc
ms.openlocfilehash: 8a4a2011124056af7064c8241450e1f3613776a9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62406698"
---
# <a name="compiler-error-c3073"></a>Erro do compilador C3073

'type': classe ref não tem um construtor de cópia definido pelo usuário

Em um [/clr (compilação de tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md) compilação, o compilador não gerará um construtor de cópia para um tipo de referência. Em qualquer **/clr** compilação, você deve definir seu próprio construtor de cópia para um tipo de referência se você espera que uma instância do tipo a ser copiado.

Para obter mais informações, consulte [semântica da pilha do C++ para tipos de referência](../../dotnet/cpp-stack-semantics-for-reference-types.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3073.

```
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