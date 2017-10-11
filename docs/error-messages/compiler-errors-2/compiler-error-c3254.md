---
title: C3254 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3254
dev_langs:
- C++
helpviewer_keywords:
- C3254
ms.assetid: 93427b10-fa72-4e43-80d1-1a6e122f9f40
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 104ee89c45d8a1134611535ab6aa9c62f09e139c
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3254"></a>C3254 de erro do compilador
'substituição explícita': classe contém substituição explícita 'override', mas não deriva de uma interface que contém a declaração da função  
  
 Quando você [substituir explicitamente](../../cpp/explicit-overrides-cpp.md) um método, a classe que contém a substituição deve derivar, direta ou indiretamente, do tipo que contém a função que você está substituindo.  
  
 O exemplo a seguir gera C3254:  
  
```  
// C3254.cpp  
__interface I  
{  
   void f();  
};  
  
__interface I1 : I  
{  
};  
  
struct A /* : I1 */  
{  
   void I1::f()  
   {   // C3254, uncomment : I1 to resolve this C3254  
   }  
};  
  
int main()  
{  
}  
```
