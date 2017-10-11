---
title: C3375 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3375
dev_langs:
- C++
helpviewer_keywords:
- C3375
ms.assetid: f1df78c6-e6ca-48f3-8b29-4e1710002bf3
caps.latest.revision: 5
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 8c5fc1af314d5c48149365ab77b4b0b3d9da4915
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3375"></a>C3375 de erro do compilador
'function': função delegate ambígua  
  
 Uma instanciação de delegado poderia ter sido para uma função de membro estático, ou como um delegate não associado a uma função de instância, então o compilador emitido esse erro.  
  
 Para obter mais informações, consulte [delegado (extensões de componentes C++)](../../windows/delegate-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3375.  
  
```  
// C3375.cpp  
// compile with: /clr  
ref struct R {  
   static void f(R^) {}  
   void f() {}  
};  
  
delegate void Del(R^);  
  
int main() {  
   Del ^ a = gcnew Del(&R::f);   // C3375  
}  
```
