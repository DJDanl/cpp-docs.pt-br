---
title: C3714 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3714
dev_langs:
- C++
helpviewer_keywords:
- C3714
ms.assetid: 17718f75-5a37-4e42-912b-487e91008a95
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 69f3f5c90524b02cad8a36babaceeb32544e7aff
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3714"></a>C3714 de erro do compilador
'method': um método de manipulador de eventos deve ter a mesma convenção de chamada como a origem 'method'  
  
 Você definiu um método de manipulador de eventos que não usa a mesma convenção de chamada como método de evento de origem. Para corrigir esse erro, conceda o método do manipulador de eventos as mesmas convenções de chamada que os do método de evento de origem. Por exemplo, no código a seguir, verifique as convenções de chamada de `handler1` e `event1` corresponder ([cdecl](../../cpp/cdecl.md) ou [stdcall](../../cpp/stdcall.md) ou outros). Remoção de palavras-chave de convenção de chamada de ambas as declarações também resolve o problema e causar `event1` e `handler1` como padrão o [thiscall](../../cpp/thiscall.md) convenção de chamada. Consulte [convenções de chamada](../../cpp/calling-conventions.md) para obter mais informações.  
  
 O exemplo a seguir gera C3714:  
  
```  
// C3714.cpp  
// compile with: /c  
// processor: x86  
[event_source(native)]  
class CEventSrc {  
public:  
   __event void __cdecl event1();  
   // try the following line instead  
   // __event void __stdcall event1();  
};  
  
[event_receiver(native)]  
class CEventRec {  
public:  
   void __stdcall handler1() {}  
  
   void HookEvents(CEventSrc* pSrc) {  
      __hook(&CEventSrc::event1, pSrc, &CEventRec::handler1);   // C3714  
   }  
  
   void UnhookEvents(CEventSrc* pSrc) {  
      __unhook(&CEventSrc::event1, pSrc, &CEventRec::handler1); // C3714  
   }  
};  
```