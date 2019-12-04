---
title: Erro do compilador C2955
ms.date: 03/28/2017
f1_keywords:
- C2955
helpviewer_keywords:
- C2955
ms.assetid: 77709fb6-d69b-46fd-a62f-e8564563d01b
ms.openlocfilehash: 8afdeaf43c0c9789753b9165f1e8a8287aaac76d
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74742867"
---
# <a name="compiler-error-c2955"></a>Erro do compilador C2955

' identifier ': o uso de template de classe ou alias genérico requer template ou lista de argumentos genéricos

Você não pode usar um modelo de classe ou uma classe genérica como um identificador sem um modelo ou uma lista de argumentos genéricos.

Para obter mais informações, consulte [modelos de classe](../../cpp/class-templates.md).

O exemplo a seguir gera C2955 e mostra como corrigi-lo:

```cpp
// C2955.cpp
// compile with: /c
template<class T>
class X {};

X x1;   // C2955
X<int> x2;   // OK - this is how to fix it.
```

C2955 também pode ocorrer ao tentar uma definição fora de linha para uma função declarada em um modelo de classe:

```cpp
// C2955_b.cpp
// compile with: /c
template <class T>
class CT {
public:
   void CTFunc();
   void CTFunc2();
};

void CT::CTFunc() {}   // C2955

// OK - this is how to fix it
template <class T>
void CT<T>::CTFunc2() {}
```

C2955 também pode ocorrer ao usar genéricos:

```cpp
// C2955_c.cpp
// compile with: /clr
generic <class T>
ref struct GC {
   T t;
};

int main() {
   GC^ g;   // C2955
   GC <int>^ g;
}
```

## <a name="example"></a>Exemplo

**Visual Studio 2017 e posterior:** O compilador diagnostica corretamente as listas de argumentos de modelo ausentes quando o modelo é exibido em uma lista de parâmetros de modelo (por exemplo, como parte de um argumento de modelo padrão ou um parâmetro de modelo sem tipo). O código a seguir é compilado no Visual Studio 2015, mas produz um erro no Visual Studio 2017.

```
template <class T> class ListNode;
template <class T> using ListNodeMember = ListNode<T> T::*;
template <class T, ListNodeMember M> class ListHead; // C2955: 'ListNodeMember': use of alias
                                                     // template requires template argument list

// correct:  template <class T, ListNodeMember<T> M> class ListHead;
```
