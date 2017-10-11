---
title: C2691 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2691
dev_langs:
- C++
helpviewer_keywords:
- C2691
ms.assetid: 6925f8f3-ea60-4909-91e6-b781492c645d
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 84babddf11901649b602ee1a2d005fd1133be2b2
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2691"></a>C2691 de erro do compilador
'data type': gerenciada ou WinRTarray não pode ter esse tipo de elemento  
  
 O tipo de um gerenciado ou um elemento de matriz de WinRT pode ser um tipo de valor ou um tipo de referência.  
  
 O exemplo a seguir gera C2691:  
  
```  
// C2691a.cpp  
// compile with: /clr  
class A {};  
  
int main() {  
   array<A>^ a1 = gcnew array<A>(20);   // C2691  
   array<int>^ a2 = gcnew array<int>(20);   // value type OK  
}  
```  

