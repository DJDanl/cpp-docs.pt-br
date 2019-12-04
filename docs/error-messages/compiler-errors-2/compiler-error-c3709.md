---
title: Erro do compilador C3709
ms.date: 11/04/2016
f1_keywords:
- C3709
helpviewer_keywords:
- C3709
ms.assetid: d5576b04-2f93-420a-8f3e-8b8e987e8dab
ms.openlocfilehash: 47320c79dbbfc2152c126c80d1eb8c061f3ceb3a
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757911"
---
# <a name="compiler-error-c3709"></a>Erro do compilador C3709

' function ': sintaxe inadequada para especificar o evento no __hook/\__unhook

Quando você especifica uma origem de evento com [__hook](../../cpp/hook.md) ou [__unhook](../../cpp/unhook.md), o primeiro parâmetro deve ser um método de evento válido e o segundo parâmetro deve ser um objeto de origem de evento válido (não um método).

O exemplo a seguir gera C3709:

```cpp
// C3709.cpp
// compile with: /LD
[event_source(native)]
class CEventSrc
{
public:
   __event void event1();
};

[event_receiver(native)]
class CEventRec
{
public:
   void handler1()
   {
   }

   void HookEvents(CEventSrc* pSrc)
   {
      __hook(bad, pSrc, CEventRec::handler1);   // C3709
      // Try the following line instead:
      // __hook(&CEventSrc::event1, pSrc, CEventRec::handler1);
   }

   void UnhookEvents(CEventSrc* pSrc)
   {
      __unhook(&CEventSrc::event1, pSrc, CEventRec::handler1);
   }
};
```
