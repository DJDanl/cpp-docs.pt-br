---
title: C3703 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3703
dev_langs:
- C++
helpviewer_keywords:
- C3703
ms.assetid: 7e3677d9-f2be-4c26-998f-423564e9023c
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: e6ef53628f3a24dd3e6f7f387491fc959d70aa04
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3703"></a>C3703 de erro do compilador
'manipulador de eventos': um método de manipulador de eventos deve ter a mesma classe de armazenamento como a origem 'event'  
  
 Um [evento](../../cpp/event-handling.md) tem uma classe de armazenamento diferentes que o manipulador de eventos para o qual ele está conectado. Por exemplo, esse erro ocorre se o manipulador de eventos é uma função de membro estático e o evento não é estático. Para corrigir esse erro, forneça o evento e o manipulador de eventos a mesma classe de armazenamento.  
  
 O exemplo a seguir gera C3703:  
  
```  
// C3703.cpp  
// C3703 expected  
#include <stdio.h>  
  
[event_source(type=native)]  
class CEventSrc {  
public:  
   __event static void MyEvent();  
};  
  
[event_receiver(type=native)]  
class CEventHandler {  
public:  
   // delete the following line to resolve  
   void MyHandler() {}  
  
   // try the following line instead  
   // static void MyHandler() {}  
  
   void HookIt(CEventSrc* pSource) {  
      __hook(CEventSrc::MyEvent, pSource, &CEventHandler::MyHandler);  
   }  
  
   void UnhookIt(CEventSrc* pSource) {  
      __unhook(CEventSrc::MyEvent, pSource, &CEventHandler::MyHandler);  
   }  
};  
  
int main() {  
   CEventSrc src;  
   CEventHandler hnd;  
  
   hnd.HookIt(&src);  
   __raise src.MyEvent();  
   hnd.UnhookIt(&src);  
}  
```
