---
title: Erro do compilador C3714
ms.date: 11/04/2016
f1_keywords:
- C3714
helpviewer_keywords:
- C3714
ms.assetid: 17718f75-5a37-4e42-912b-487e91008a95
ms.openlocfilehash: 9bfdf8b26ab599ef1a28483af7ebc28f0dbc1912
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62328335"
---
# <a name="compiler-error-c3714"></a>Erro do compilador C3714

'method': um método de manipulador de eventos deve ter a mesma convenção de chamada como a origem 'method'

Você definiu um método de manipulador de eventos que não usou a mesma convenção de chamada como método de evento de origem. Para corrigir esse erro, dê o método de manipulador de eventos as mesmas convenções de chamada que os do método de evento de origem. Por exemplo, no código a seguir, verifique as convenções de chamada de `handler1` e `event1` corresponder ([cdecl](../../cpp/cdecl.md) ou [stdcall](../../cpp/stdcall.md) ou outros). Removendo palavras-chave de convenção de chamada de ambas as declarações serão também resolve o problema e causar `event1` e `handler1` padrão para o [thiscall](../../cpp/thiscall.md) convenção de chamada. Ver [convenções de chamada](../../cpp/calling-conventions.md) para obter mais informações.

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