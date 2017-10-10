---
title: C2694 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2694
dev_langs:
- C++
helpviewer_keywords:
- C2694
ms.assetid: 8dc2cec2-67ae-4e16-8c0c-374425aca8bc
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: b81a6ee838a1d30928e8cebb8ef581c23644afcf
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2694"></a>C2694 de erro do compilador
'override': função virtual de substituição possui especificação de exceção menos restritiva do que a classe base membro virtual função 'base'  
  
 Uma função virtual foi substituída, mas em [/Za](../../build/reference/za-ze-disable-language-extensions.md), a função substituição tinha menos restritivo [especificação de exceção](../../cpp/exception-specifications-throw-cpp.md).  
  
 O exemplo a seguir gera C2694:  
  
```  
// C2694.cpp  
// compile with: /Za /c  
class MyBase {  
public:  
   virtual void f(void) throw(int) {  
   }  
};  
  
class Derived : public MyBase {  
public:  
   void f(void) throw(...) {}   // C2694  
   void f2(void) throw(int) {}   // OK  
};  
```
