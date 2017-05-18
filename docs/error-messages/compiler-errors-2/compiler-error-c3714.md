---
title: C3714 de erro do compilador | Documentos do Microsoft
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
caps.latest.revision: 10
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 44caee95ba84535f5b34f1bae1e69d02deccdf48
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3714"></a>C3714 de erro do compilador
'method': um método de manipulador de eventos deve ter a mesma convenção de chamada como a origem 'method'  
  
 Você definiu um método de manipulador de eventos que não usa a mesma convenção de chamada como o método de evento do código-fonte. Para corrigir esse erro, dê o método do manipulador de eventos as mesmas convenções de chamada que aquelas o método de evento do código-fonte. Por exemplo, no código a seguir, verifique as convenções de chamada de `handler1` e `event1` corresponder ([cdecl](../../cpp/cdecl.md) ou [stdcall](../../cpp/stdcall.md) ou outros). Remover palavras-chave de convenção de chamada de ambas as declarações também resolve o problema e causar `event1` e `handler1` padrão para o [thiscall](../../cpp/thiscall.md) convenção de chamada. Consulte [convenções de chamada](../../cpp/calling-conventions.md) para obter mais informações.  
  
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
