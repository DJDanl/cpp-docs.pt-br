---
title: Erro do compilador C3714
ms.date: 11/04/2016
f1_keywords:
- C3714
helpviewer_keywords:
- C3714
ms.assetid: 17718f75-5a37-4e42-912b-487e91008a95
ms.openlocfilehash: 1078bf8a97f6cb7afeaf7046489fe262c0bb0199
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74753322"
---
# <a name="compiler-error-c3714"></a>Erro do compilador C3714

' method ': um método de manipulador de eventos deve ter a mesma convenção de chamada que o ' método ' de origem

Você definiu um método de manipulador de eventos que não usou a mesma convenção de chamada que o método de evento de origem. Para corrigir esse erro, dê ao método manipulador de eventos as mesmas convenções de chamada que as do método de evento de origem. Por exemplo, no código a seguir, faça as convenções de chamada de `handler1` e `event1` correspondência ([__cdecl](../../cpp/cdecl.md) ou [__stdcall](../../cpp/stdcall.md) ou outras). A remoção de palavras-chave de Convenção de chamada de ambas as declarações também resolverá o problema e fará com que `event1` e `handler1` como padrão para a Convenção de chamada [thiscall](../../cpp/thiscall.md) . Consulte [convenções de chamada](../../cpp/calling-conventions.md) para obter mais informações.

O exemplo a seguir gera C3714:

```cpp
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
