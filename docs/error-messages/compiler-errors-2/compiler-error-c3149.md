---
title: C3149 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: c243063a9770542f137d5950e8a269f771960f74
ms.openlocfilehash: 555b3a7ac8e0d1e5de8eacd763c9ee63101e5b78
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3149"></a>C3149 de erro do compilador
'type': não é possível usar esse tipo sem um nível superior 'char'  
  
 Uma declaração não foi especificada corretamente.  
  
 Por exemplo, você pode ter definido um tipo CLR no escopo global e tentou criar uma variável do tipo como parte da definição. Como variáveis globais de tipos CLR não são permitidas, o compilador irá gerar C3149.  
  
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

