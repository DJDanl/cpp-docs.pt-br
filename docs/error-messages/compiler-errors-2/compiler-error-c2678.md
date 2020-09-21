---
title: Erro do compilador C2678
ms.date: 11/04/2016
f1_keywords:
- C2678
helpviewer_keywords:
- C2678
ms.assetid: 1f0a4e26-b429-44f5-9f94-cb66441220c8
ms.openlocfilehash: c8f5b06e6c2f9966d714f4a360525617dbff400f
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90743172"
---
# <a name="compiler-error-c2678"></a>Erro do compilador C2678

' operator ' binário: nenhum operador definido que recebe um operando esquerdo do tipo ' type ' (ou não há uma conversão aceitável)

Para usar o operador, você deve sobrecarregar para o tipo especificado ou definir uma conversão para um tipo para o qual o operador é definido.

C2678 pode ocorrer quando o operando à esquerda é qualificado como const, mas o operador é definido para pegar um argumento não const.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C2678 e mostra como corrigi-lo:

```cpp
// C2678a.cpp
// Compile by using: cl /EHsc /W4 C2678a.cpp
struct Combo {
   int number;
   char letter;
};

inline Combo& operator+=(Combo& lhs, int rhs) {
   lhs.number += rhs;
   return lhs;
}

int main() {
   Combo const combo1{ 42, 'X' };
   Combo combo2{ 13, 'Z' };

   combo1 += 6; // C2678
   combo2 += 9; // OK - operator+= matches non-const Combo
}
```

C2678 também pode ocorrer se você não fixar um membro nativo antes de chamar uma função de membro nele.

O exemplo a seguir gera C2678 e mostra como corrigi-lo.

```cpp
// C2678.cpp
// compile with: /clr /c
struct S { int _a; };

ref class C {
public:
   void M( S param ) {
      test = param;   // C2678

      // OK
      pin_ptr<S> ptest = &test;
      *ptest = param;
   }
   S test;
};
```
