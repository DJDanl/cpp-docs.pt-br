---
title: C3149 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3149
dev_langs:
- C++
helpviewer_keywords:
- C3149
ms.assetid: cf6e2616-2f06-46da-8a8a-d449cb481c51
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: dc5abf02a3210ca3d7bd858662e0c02d4f42d75d
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3149"></a>C3149 de erro do compilador
'type': não é possível usar este tipo aqui sem um nível superior 'char'  
  
 Uma declaração não foi especificada corretamente.  
  
 Por exemplo, você pode ter definido um tipo CLR no escopo global e tentou criar uma variável do tipo como parte da definição. Como variáveis globais de tipos CLR não são permitidas, o compilador gerará C3149.  
  
 Para resolver esse erro, declare variáveis de tipos CLR dentro de uma definição de função ou tipo.  
  
 O exemplo a seguir gera C3149:  
  
```  
// C3149.cpp  
// compile with: /clr  
using namespace System;  
int main() {  
   // declare an array of value types   
   array< Int32 ^> IntArray;   // C3149  
   array< Int32>^ IntArray2;   // OK  
}  
```  
  
 O exemplo a seguir gera C3149:  
  
```  
// C3149b.cpp  
// compile with: /clr /c  
delegate int MyDelegate(const int, int);  
void Test1(MyDelegate m) {}   // C3149  
void Test2(MyDelegate ^ m) {}   // OK  
```  

