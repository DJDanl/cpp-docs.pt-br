---
title: C3535 de erro do compilador | Documentos do Microsoft
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
caps.latest.revision: 6
author: corob-msft
ms.author: corob
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: d7275b848504a57e16d72e25e3b3d0da44ce2edf
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3535"></a>C3535 de erro do compilador
não é possível deduzir o tipo de 'type1' de 'type2'  
  
 O tipo da variável declarada pelo `auto` palavra-chave não pode ser deduzido do tipo da expressão de inicialização. Por exemplo, este erro ocorre se a expressão de inicialização for avaliada como `void`, que não é um tipo.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Verifique se o tipo da expressão de inicialização não é `void`.  
  
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
 O exemplo a seguir produz C3535 porque a instrução declara a variável `x` como um ponteiro para um tipo deduzido, mas o tipo do inicializador do expression é duplo. Consequentemente, o compilador não pode deduzir o tipo da variável.  
  
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
