---
title: C2955 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 03/28/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2955
dev_langs:
- C++
helpviewer_keywords:
- C2955
ms.assetid: 77709fb6-d69b-46fd-a62f-e8564563d01b
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: af3f53545aa70e738f14c902a7a75afc48275b57
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2955"></a>C2955 de erro do compilador
'Identificador': uso do modelo de classe ou alias genérico requer o modelo ou a lista de argumentos genéricos  
  
 Você não pode usar uma classe genérica ou um modelo de classe como um identificador sem um modelo ou uma lista de argumentos genéricos.  
  
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
  
 C2955 também pode ocorrer durante a tentativa de uma definição de fora de linha para uma função declarada em um modelo de classe:  
  
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
  
 C2955 também pode ocorrer ao usar genéricos:  
  
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
**Visual Studio 2017 e posterior:** o compilador corretamente diagnostica listas de argumentos de modelo ausente quando o modelo é exibido em uma lista de parâmetros de modelo (por exemplo, como parte de um argumento de template padrão ou um parâmetro de modelo sem tipo). O código a seguir é compilado no Visual Studio 2015, mas produz um erro no Visual Studio 2017.

```
template <class T> class ListNode;
template <class T> using ListNodeMember = ListNode<T> T::*;
template <class T, ListNodeMember M> class ListHead; // C2955: 'ListNodeMember': use of alias 
                                                     // template requires template argument list

// correct:  template <class T, ListNodeMember<T> M> class ListHead;
```

