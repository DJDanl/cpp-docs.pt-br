---
title: C3703 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3703
dev_langs:
- C++
helpviewer_keywords:
- C3703
ms.assetid: 7e3677d9-f2be-4c26-998f-423564e9023c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 344554875e771a1a5c3412613fd77307651a5c7d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33264784"
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