---
title: C3252 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3252
dev_langs:
- C++
helpviewer_keywords:
- C3252
ms.assetid: aa9ad096-e9ac-41c7-8ad9-b966751c7c75
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 2123ad376530868afa1bacc987341905617e766b
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3252"></a>C3252 de erro do compilador
'method': não é possível reduzir acessibilidade de um método virtual em um gerenciado ou um tipo WinRT  
  
 Uma classe que implementa um método virtual de uma classe base ou qualquer método de interface não pode reduzir o acesso do método.  
  
 Observe que todos os métodos em uma interface públicos.  
  
 O exemplo a seguir gera C3252 e mostra como corrigi-lo:  
  
```  
// C3252.cpp  
// compile with: /clr /c  
ref class A {  
public:  
   virtual void f1() {}  
};  
  
ref class B : public A {  
// To fix, uncomment the following line:   
// public:      
   virtual void f1() override sealed {}   // C3252, make this method public  
};  
```
