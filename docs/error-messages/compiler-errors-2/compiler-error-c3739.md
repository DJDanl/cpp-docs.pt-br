---
title: C3739 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3739
dev_langs:
- C++
helpviewer_keywords:
- C3739
ms.assetid: acffe894-08b8-4bf2-9249-9501e6e2bad3
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: b3fa62f908f152e127669d1cd935fafdb75d413f
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3739"></a>C3739 de erro do compilador
'class': sintaxe só tem suporte quando o parâmetro ' layout_dependent ' de event_receiver é verdadeiro  
  
 Você tentou conectar-se com uma interface inteira de eventos, mas `layout_dependent` na [event_receiver](../../windows/event-receiver.md) atributo não é válido; você deve conectar-se com um único evento de cada vez.  
  
 O exemplo a seguir gera C3739:  
  
```  
// C3739.cpp  
struct A  
{  
   __event void e();  
};  
  
// event_receiver is implied  
// [ event_receiver(layout_dependent=false)]  
  
// use the following line instead  
// [event_receiver(com, layout_dependent=true), coclass ]  
struct B  
{  
   void f();  
   B(A* a)  
   {  
      __hook(A, a, &B::f);   // C3739  
      // use the following line instead to hook a single event  
      // __hook(&A::e, a, &B::f);  
   }  
};  
  
int main()  
{  
}  
```
