---
title: C2070 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2070
dev_langs:
- C++
helpviewer_keywords:
- C2070
ms.assetid: 4c8dea63-1227-4aba-be26-2462537f86fb
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 0923caf84c3980c4ee1b4eaa832752f34a447cc1
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2070"></a>C2070 de erro do compilador
'type': operando de sizeof inválido  
  
 O [sizeof](../../cpp/sizeof-operator.md) operador requer um nome de tipo ou expressão.  
  
 O exemplo a seguir gera C2070:  
  
```  
// C2070.cpp  
void func() {}  
int main() {  
   int a;  
   a = sizeof(func);   // C2070  
}  
```  
  
 Possível solução:  
  
```  
// C2070b.cpp  
void func() {}  
int main() {  
   int a;  
   a = sizeof(a);  
}  
```
