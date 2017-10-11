---
title: C3217 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3217
dev_langs:
- C++
helpviewer_keywords:
- C3217
ms.assetid: 99070417-c23a-4d82-bdd2-04be1a07adea
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: b9122fc9c829ff017f717c2cec2d80dd254103ba
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3217"></a>C3217 de erro do compilador
'param': parâmetro genérico não pode ser restringido nesta declaração  
  
 Uma restrição de preenchimento foi formada; a restrição de parâmetro genérico deve concordar com o parâmetro de modelo de classe genérica.  
  
 O exemplo a seguir gera C3217:  
  
```  
// C3217.cpp  
// compile with: /clr  
interface struct A {};  
  
generic <class T>  
ref class C {  
   generic <class T1>  
   where T : A   // C3217  
   void f();  
};  
```  
  
 O exemplo a seguir demonstra uma possível resolução:  
  
```  
// C3217b.cpp  
// compile with: /clr /c  
interface struct A {};  
  
generic <class T>  
ref class C {  
   generic <class T1>  
   where T1 : A  
   void f();  
};  
```
