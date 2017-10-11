---
title: C3185 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3185
dev_langs:
- C++
helpviewer_keywords:
- C3185
ms.assetid: 5bf96279-043c-4981-9d02-b4550071b192
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 10b25fa08693e4fc6c4e495c84944d79ab6e73ae
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3185"></a>C3185 de erro do compilador
'typeid' usado na gerenciados ou tipo de WinRT 'type', use 'operator' em vez disso  
  
 Não é possível aplicar o [typeid](../../cpp/typeid-operator.md) operador a ser gerenciada ou WinRT tipo; use [typeid](../../windows/typeid-cpp-component-extensions.md) em vez disso.  
  
 O exemplo a seguir gera C3185 e mostra como corrigi-lo:  
  
```  
// C3185a.cpp  
// compile with: /clr  
ref class Base {};  
ref class Derived : public Base {};  
  
int main() {  
   Derived ^ pd = gcnew Derived;  
   Base ^pb = pd;  
   const type_info & t1 = typeid(pb);   // C3185  
   System::Type ^ MyType = Base::typeid;   // OK  
};  
```  

