---
title: Erro do compilador C2955
ms.date: 03/28/2017
f1_keywords:
- C2955
helpviewer_keywords:
- C2955
ms.assetid: 77709fb6-d69b-46fd-a62f-e8564563d01b
ms.openlocfilehash: c012e5189b9ca1d0b0e786cbddacedee7c6728d2
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51519991"
---
# <a name="compiler-error-c2955"></a>Erro do compilador C2955

'identifier': uso do modelo de classe ou alias genérico requer o modelo ou a lista de argumentos genéricos

Você não pode usar um modelo de classe ou a classe genérica como um identificador sem um modelo ou uma lista de argumentos genéricos.

Para obter mais informações, consulte [modelos de classe](../../cpp/class-templates.md).

O exemplo a seguir gera C2955 e mostra como corrigi-lo:

```
// C2955.cpp
// compile with: /c
template<class T>
class X {};

X x1;   // C2955
X<int> x2;   // OK - this is how to fix it.
```

C2955 também pode ocorrer durante a tentativa de uma definição fora de linha para uma função declarada em um modelo de classe:

```
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

C2955 também podem ocorrer ao usar genéricos:

```
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

**Visual Studio 2017 e posterior:** o compilador corretamente diagnostica listas de argumentos de modelo ausentes quando o modelo é exibido em uma lista de parâmetros de modelo (por exemplo, como parte de um argumento de modelo padrão ou um parâmetro de modelo sem tipo). O código a seguir é compilado no Visual Studio 2015, mas produz um erro no Visual Studio 2017.

```
template <class T> class ListNode;
template <class T> using ListNodeMember = ListNode<T> T::*;
template <class T, ListNodeMember M> class ListHead; // C2955: 'ListNodeMember': use of alias
                                                     // template requires template argument list

// correct:  template <class T, ListNodeMember<T> M> class ListHead;
```
