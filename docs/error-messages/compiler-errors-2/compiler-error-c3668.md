---
title: C3668 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3668
dev_langs:
- C++
helpviewer_keywords:
- C3668
ms.assetid: 53a96698-bde4-4447-95b5-b5108291f60c
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 5db5144aac56112522f7ac707bd1b5f252929dc8
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3668"></a>C3668 de erro do compilador
'method': método com especificador de substituição 'override' não substituiu nenhum método de classe base  
  
 Uma função tentada substituir uma função não existente.  
  
 Para obter mais informações, consulte [substituições explícitas](../../windows/explicit-overrides-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3668.  
  
```  
// C3668.cpp  
// compile with: /c  
__interface I {  
   void f(int);   // virtual by default  
};  
  
class J {  
public:  
   void g(int);  
   virtual void h(int);  
};  
  
struct R : I,J {  
   virtual void f() override {}   // C3668  
   virtual void f(int) override {}   // OK  
  
   virtual void g(int) override {}   // C3668  
   virtual void h(int) override {}   // OK  
};  
```
