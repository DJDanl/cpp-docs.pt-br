---
title: C3255 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3255
dev_langs:
- C++
helpviewer_keywords:
- C3255
ms.assetid: 877ffca2-fd92-44b6-9060-6091b928b1c1
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 86052e8ffa7e9ba9627a290318dbe6115af3d36c
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3255"></a>C3255 de erro do compilador
tipo de valor: não é possível alocar dinamicamente este objeto de tipo value em heap nativo  
  
 Instâncias de um tipo de valor (consulte [Classes e estruturas](../../windows/classes-and-structs-cpp-component-extensions.md)) que contêm membros gerenciados podem ser criados na pilha, mas não no heap.  
  
 O exemplo a seguir gera C3255:  
  
```  
// C3255.cpp  
// compile with: /clr  
using namespace System;  
value struct V {  
   Object^ o;  
};  
  
value struct V2 {  
   int i;  
};  
  
int main() {  
   V* pv = new V;   // C3255  
   V2* pv2 = new V2;  
   V v2;  
}  
```  

