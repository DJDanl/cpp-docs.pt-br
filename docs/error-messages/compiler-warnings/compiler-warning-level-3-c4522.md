---
title: Compilador aviso (nível 3) C4522
ms.date: 11/04/2016
f1_keywords:
- C4522
helpviewer_keywords:
- C4522
ms.assetid: 7065dc27-0b6c-4e68-a345-c51cdb99a20b
ms.openlocfilehash: de163f0a3925b711f2f3437b700f75bbe994b3e7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50622957"
---
# <a name="compiler-warning-level-3-c4522"></a>Compilador aviso (nível 3) C4522

'class': vários operadores de atribuição especificadas

A classe tem vários operadores de atribuição de um único tipo. Esse aviso é informativo; os construtores são que pode ser chamados em seu programa.

Use o [aviso](../../preprocessor/warning.md) pragma para suprimir este aviso.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4522.

```
// C4522.cpp
// compile with: /EHsc /W3
#include <iostream>

using namespace std;
class A {
public:
   A& operator=( A & o ) { cout << "A&" << endl; return *this; }
   A& operator=( const A &co ) { cout << "const A&" << endl; return *this; }   // C4522
};

int main() {
   A o1, o2;
   o2 = o1;
   const A o3;
   o1 = o3;
}
```