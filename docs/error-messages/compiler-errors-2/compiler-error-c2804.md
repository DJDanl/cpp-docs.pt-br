---
title: Erro do compilador C2804
ms.date: 11/04/2016
f1_keywords:
- C2804
helpviewer_keywords:
- C2804
ms.assetid: b066e563-cca4-450c-8ba7-3b0d7a89f3ea
ms.openlocfilehash: 1ebcfdc2f2555fa694ab8dfeabe77e5140ddace2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50481257"
---
# <a name="compiler-error-c2804"></a>Erro do compilador C2804

binário 'operator operador' possui muitos parâmetros

A função de membro de operador binário sobrecarregado foi declarada com mais de um parâmetro. O primeiro parâmetro do operando de uma função de membro de operador binário, cujo tipo é o operador tipo delimitador, está implícito.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2804 e mostra como corrigi-lo.

```
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

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2804 e mostra como corrigi-lo.

```
// C2804_2.cpp
// compile with: /clr /c
ref struct Y {
   Y^ operator +(Y^ hY, int i);   // C2804
   static Y^ operator +(Y^ hY, int i);   // OK
   Y^ operator +(int i);   // OK
};
```