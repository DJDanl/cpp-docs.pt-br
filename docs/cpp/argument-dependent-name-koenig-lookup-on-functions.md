---
title: Pesquisa de nome dependente do argumento (Koenig) em funções
ms.date: 11/04/2016
helpviewer_keywords:
- Koenig lookup
- argument-dependent lookup [C++]
ms.assetid: c0928401-da2c-4658-942d-9ba4df149c35
ms.openlocfilehash: d979b79c0f712ed35a42a44047dd1091010c72bf
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62184458"
---
# <a name="argument-dependent-name-koenig-lookup-on-functions"></a>Pesquisa de nome dependente do argumento (Koenig) em funções

O compilador pode usar a pesquisa por nome dependente de argumento para localizar a definição de uma chamada de função não qualificada. A pesquisa por nome dependente de argumento também é chamada de pesquisa de Koenig. O tipo de cada argumento em uma chamada de função é definido dentro de uma hierarquia de namespaces, classes, estruturas, uniões ou modelos. Quando você especifica um não-qualificados [sufixo](../cpp/postfix-expressions.md) chamada de função, o compilador pesquisa para a definição de função na hierarquia associada a cada tipo de argumento.

## <a name="example"></a>Exemplo

No exemplo, o compilador nota que a função `f()` pega um argumento `x`. O argumento `x` é do tipo `A::X`, que é definido no namespace `A`. O compilador pesquisa o namespace `A` e encontra uma definição para a função `f()`, que usa um argumento do tipo `A::X`.

```cpp
// argument_dependent_name_koenig_lookup_on_functions.cpp
namespace A
{
   struct X
   {
   };
   void f(const X&)
   {
   }
}
int main()
{
// The compiler finds A::f() in namespace A, which is where
// the type of argument x is defined. The type of x is A::X.
   A::X x;
   f(x);
}
```