---
title: C2655 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2655
dev_langs:
- C++
helpviewer_keywords:
- C2655
ms.assetid: beaefa6e-51b3-4df9-9150-960f3fbf40e0
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 2d3c9199979d83c91e4c4d12dec648482c4999b3
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2655"></a>C2655 de erro do compilador
'Identificador': definição ou redeclaração inválida no escopo atual  
  
 Um identificador pode ser declarado novamente somente no escopo global.  
  
 O exemplo a seguir gera C2655:  
  
```  
// C2655.cpp  
class A {};  
class B {  
public:  
   static int i;  
};  
  
int B::i;  // OK  
  
int main() {  
   A B::i;  // C2655  
}  
```
