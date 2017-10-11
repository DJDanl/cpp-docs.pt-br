---
title: C2804 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2804
dev_langs:
- C++
helpviewer_keywords:
- C2804
ms.assetid: b066e563-cca4-450c-8ba7-3b0d7a89f3ea
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 42669f02fb687c35ee159cb28b852e13281a83f1
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2804"></a>C2804 de erro do compilador
binário 'operator operador' possui muitos parâmetros  
  
 A função de membro do operador binário sobrecarregado é declarada com mais de um parâmetro. O primeiro parâmetro de operando de uma função de membro do operador binário, cujo tipo é o operador tipo delimitador, indicado.  
  
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
