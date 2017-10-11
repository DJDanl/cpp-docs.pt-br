---
title: C2715 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2715
dev_langs:
- C++
helpviewer_keywords:
- C2715
ms.assetid: c81567a7-5b65-468f-aaf9-835f91e468e4
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 8d396830b31e0d46781c3f008847f4cc9bd7bcc5
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2715"></a>C2715 de erro do compilador
'type': não é possível usar throw ou catch com este tipo  
  
 Tipos de valor não são argumentos válidos quando usar tratamento de exceção no código gerenciado (consulte [tratamento de exceção](../../windows/exception-handling-cpp-component-extensions.md) para obter mais informações).  
  
```  
// C2715a.cpp  
// compile with: /clr  
using namespace System;  
  
value struct V {  
   int i;  
};  
  
void f1() {  
   V v;  
   v.i = 10;  
   throw v;   // C2715  
   // try the following line instead  
   // throw ((V^)v);  
}  
  
int main() {  
   try {  
      f1();  
   }  
  
   catch(V v) { if ( v.i == 10 ) {   // C2715  
   // try the following line instead  
   // catch(V^ pv) { if ( pv->i == 10 ) {  
         Console::WriteLine("caught 10 - looks OK");  
      }   
      else {  
         Console::WriteLine("catch looks bad");  
      }  
   }  
   catch(...) {  
      Console::WriteLine("catch looks REALLY bad");  
   }  
}  
```  

