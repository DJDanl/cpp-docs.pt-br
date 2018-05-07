---
title: C3670 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3670
dev_langs:
- C++
helpviewer_keywords:
- C3670
ms.assetid: d0fa9c6e-8f90-48c7-9066-31b4fa5942eb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ed70f364ad72160ddc3b9e875d8b1f3b6ee67e3b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3670"></a>C3670 de erro do compilador
'override': não é possível substituir o método de classe base inacessível 'method'  
  
 Uma substituição só podem ocorrer em uma função cujo nível de acesso disponibiliza em um tipo derivado. Para obter mais informações, consulte [substituições explícitas](../../windows/explicit-overrides-cpp-component-extensions.md).  
  
 O exemplo a seguir gera C3670:  
  
```  
// C3670.cpp  
// compile with: /clr /c  
public ref class C {  
// Uncomment the following line to resolve.  
// public:  
   virtual void g() { }  
};  
  
public ref class D : public C {  
public:  
   virtual void f() new sealed = C::g {};   // C3670  
};  
```