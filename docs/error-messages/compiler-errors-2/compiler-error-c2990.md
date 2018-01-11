---
title: C2990 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2990
dev_langs: C++
helpviewer_keywords: C2990
ms.assetid: 674e9f6a-6743-4af0-a7ed-cbe11103a2f8
caps.latest.revision: "13"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 94b40071e08dd22c5382e310d27c125f76e1bd6b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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