---
title: C3185 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translationtype: Machine Translation
ms.sourcegitcommit: c243063a9770542f137d5950e8a269f771960f74
ms.openlocfilehash: 8772b939def79269dd46375c1e8db5d5dacc5f74
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3185"></a>C3185 de erro do compilador
'typeid' usado na gerenciados ou tipo WinRT 'type' use 'operator' em vez disso  
  
 Não é possível aplicar o [typeid](../../cpp/typeid-operator.md) operador gerenciada ou WinRT digite; use [typeid](../../windows/typeid-cpp-component-extensions.md) em vez disso.  
  
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

