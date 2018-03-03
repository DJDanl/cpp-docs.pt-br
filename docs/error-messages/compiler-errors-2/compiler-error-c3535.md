---
title: C3535 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3535
dev_langs:
- C++
helpviewer_keywords:
- C3535
ms.assetid: 24449c98-f681-484d-a00b-32533dca3a88
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5797d644ec13ed89bad3ddcda23be109df067b03
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3535"></a>C3535 de erro do compilador
não é possível deduzir o tipo para 'type1' de 'type2'  
  
 O tipo da variável declarada com o `auto` palavra-chave não pode ser deduzido do tipo da expressão de inicialização. Por exemplo, esse erro ocorre se a expressão de inicialização for avaliada como `void`, que não é um tipo.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Certifique-se de que o tipo da expressão de inicialização não é `void`.  
  
2.  Certifique-se de que a declaração não é um ponteiro para um tipo fundamental. Para obter mais informações, consulte [tipos fundamentais](../../cpp/fundamental-types-cpp.md).  
  
3.  Certifique-se de que, se a declaração é um ponteiro para um tipo, a expressão de inicialização é um tipo de ponteiro.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir produz C3535 porque avalia a expressão de inicialização para `void`.  
  
```  
// C3535a.cpp  
// Compile with /Zc:auto  
void f(){}  
int main()  
{  
   auto x = f();   //C3535  
   return 0;  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir produz C3535 porque a instrução Declare a variável `x` como um ponteiro para um tipo deduzido, mas o tipo do inicializador de expressão é double. Consequentemente, o compilador não é possível deduzir o tipo da variável.  
  
```  
// C3535b.cpp  
// Compile with /Zc:auto  
int main()  
{  
   auto* x = 123.0;   // C3535  
   return 0;  
}  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir produz C3535 porque variável `p` declara um ponteiro para um tipo deduzido, mas a expressão de inicialização não é um tipo de ponteiro.  
  
```  
// C3535c.cpp  
// Compile with /Zc:auto  
class A { };  
A x;  
auto *p = x;  // C3535  
```  
  
## <a name="see-also"></a>Consulte também  
 [palavra-chave auto](../../cpp/auto-keyword.md)   
 [Tipos fundamentais](../../cpp/fundamental-types-cpp.md)