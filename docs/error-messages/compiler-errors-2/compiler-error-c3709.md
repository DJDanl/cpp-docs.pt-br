---
title: Erro do compilador C3709
ms.date: 11/04/2016
f1_keywords:
- C3709
helpviewer_keywords:
- C3709
ms.assetid: d5576b04-2f93-420a-8f3e-8b8e987e8dab
ms.openlocfilehash: 3eb2963916cbbcbd925f755f9162ce59e9bff569
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50432750"
---
# <a name="compiler-error-c3709"></a>Erro do compilador C3709

'function': sintaxe inadequada ao especificar evento em hook /\__unhook

Quando você especifica uma origem de evento com [hook](../../cpp/hook.md) ou [unhook](../../cpp/unhook.md), o primeiro parâmetro deve ser um método de evento válido e o segundo parâmetro deve ser um objeto de fonte de evento válido (não um método).

O exemplo a seguir gera C3709:

```
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