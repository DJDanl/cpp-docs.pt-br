---
title: Erro do compilador C2804
ms.date: 11/04/2016
f1_keywords:
- C2804
helpviewer_keywords:
- C2804
ms.assetid: b066e563-cca4-450c-8ba7-3b0d7a89f3ea
ms.openlocfilehash: bdd1b4155d30dd2513d87ac217ca20ca7baabd8a
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90743159"
---
# <a name="compiler-error-c2804"></a>Erro do compilador C2804

o ' operator Operator ' binário tem muitos parâmetros

A função de membro de operador binário sobrecarregado é declarada com mais de um parâmetro. O primeiro parâmetro de operando de uma função de membro de operador binário, cujo tipo é o tipo de delimitador do operador, é implícito.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C2804 e mostra como corrigi-lo.

```cpp
// C2804.cpp
// compile by using: cl /c /W4 C2804.cpp
class X {
public:
   X& operator+= (const X &left, const X &right);   // C2804
   X& operator+= (const X &right);   // OK - left operand implicitly *this
};

int main() {
   X x, y;
   x += y;   // equivalent to x.operator+=(y)
}
```

O exemplo a seguir gera C2804 e mostra como corrigi-lo.

```cpp
// C2804_2.cpp
// compile with: /clr /c
ref struct Y {
   Y^ operator +(Y^ hY, int i);   // C2804
   static Y^ operator +(Y^ hY, int i);   // OK
   Y^ operator +(int i);   // OK
};
```
