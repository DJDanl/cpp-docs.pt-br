---
title: Pesquisa de nome dependente de argumento (Koenig) em funções | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- Koenig lookup
- argument-dependent lookup [C++]
ms.assetid: c0928401-da2c-4658-942d-9ba4df149c35
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8e71a1fd5a795fb95520ec8d7859e70460a9372c
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46028812"
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