---
title: C2990 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2990
dev_langs:
- C++
helpviewer_keywords:
- C2990
ms.assetid: 674e9f6a-6743-4af0-a7ed-cbe11103a2f8
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 9a2433bec7992c73fb7e9b7f358e89b7e75da384
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2990"></a>C2990 de erro do compilador
'class': tipo de classe não como já foi declarado como um tipo de classe  
  
 A classe de modelo ou não genérica redefine uma classe genérica ou modelo. Verifique os arquivos de cabeçalho de conflitos.  
  
 O exemplo a seguir gera C2990:  
  
```  
// C2990.cpp  
// compile with: /c  
template <class T>  
class C{};  
class C{};   // C2990  
```  
  
 C2990 também pode ocorrer ao usar genéricos:  
  
```  
// C2990b.cpp  
// compile with: /clr /c  
generic <class T>  
ref struct GC;  
  
ref struct GC {};   // C2990  
```  
  
 C2990 também pode ocorrer devido a uma alteração significativa no compilador do Visual C++ para Visual C++ 2005; o compilador agora requer que várias declarações para o mesmo tipo seja idêntico em relação à especificação de modelo.  
  
 O exemplo a seguir gera C2990:  
  
```  
// C2990c.cpp  
// compile with: /c  
template<class T>  
class A;  
  
template<class T>  
struct A2 {  
   friend class A;   // C2990  
};  
  
// OK  
template<class T>  
struct B {  
   template<class T>  
   friend class A;  
};  
```
