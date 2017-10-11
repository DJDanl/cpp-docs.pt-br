---
title: C3142 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3142
dev_langs:
- C++
helpviewer_keywords:
- C3142
ms.assetid: 795137ad-d00a-4a9c-9665-0cd8bfb5da8b
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 56322d31f7a90612957ab82cd238b83e1789028a
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3142"></a>C3142 de erro do compilador
'property_name': não é possível definir o endereço de uma propriedade  
  
 O endereço de uma propriedade não está disponível para o desenvolvedor.  
  
 O exemplo a seguir gera C3142:  
  
```  
// C3142_2.cpp  
// compile with: /clr  
using namespace System;  
ref class CSize {  
private:  
   property int Size {  
      int get();  
   }  
};  
  
int main() {  
    &CSize::Size; // C3142  
}  
```  

