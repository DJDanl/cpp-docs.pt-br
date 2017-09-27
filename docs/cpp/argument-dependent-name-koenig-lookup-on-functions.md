---
title: "Pesquisa de nome dependente do argumento (Koenig) em funções | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- Koenig lookup
- argument-dependent lookup [C++]
ms.assetid: c0928401-da2c-4658-942d-9ba4df149c35
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: a27b75a8be6b250e27a667a8aebf4e399fdd3f1f
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="argument-dependent-name-koenig-lookup-on-functions"></a>Pesquisa de nome dependente do argumento (Koenig) em funções
O compilador pode usar a pesquisa por nome dependente de argumento para localizar a definição de uma chamada de função não qualificada. A pesquisa por nome dependente de argumento também é chamada de pesquisa de Koenig. O tipo de cada argumento em uma chamada de função é definido dentro de uma hierarquia de namespaces, classes, estruturas, uniões ou modelos. Quando você especifica um não qualificado [sufixo](../cpp/postfix-expressions.md) chamada de função, o compilador procura a definição da função na hierarquia associada a cada tipo de argumento.  
  
## <a name="example"></a>Exemplo  
 No exemplo, o compilador nota que a função `f()` pega um argumento `x`. O argumento `x` é do tipo `A::X`, que é definido no namespace `A`. O compilador pesquisa o namespace `A` e encontra uma definição para a função `f()`, que usa um argumento do tipo `A::X`.  
  
```  
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

