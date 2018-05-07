---
title: C3149 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3149
dev_langs:
- C++
helpviewer_keywords:
- C3149
ms.assetid: cf6e2616-2f06-46da-8a8a-d449cb481c51
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9c0441a7aebf86139aedbd5e45a7645db0a90b37
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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
