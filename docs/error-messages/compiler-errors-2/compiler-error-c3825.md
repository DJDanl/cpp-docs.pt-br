---
title: Erro do compilador C3825
ms.date: 11/04/2016
f1_keywords:
- C3825
helpviewer_keywords:
- C3825
ms.assetid: 18e204a1-f26e-42c6-8d74-2b49cc95f940
ms.openlocfilehash: 98d9dbee8b3d290af0ddd1851380758290a21d4a
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74741710"
---
# <a name="compiler-error-c3825"></a>Erro do compilador C3825

' class ': um Managed ou WinRTclass pode dar suporte apenas a Managed ou WinRTevents

Somente eventos .NET têm suporte em classes gerenciadas. Somente Windows Runtime eventos têm suporte em classes Windows Runtime. Para corrigir esse erro em código gerenciado, altere o parâmetro de tipo de `event_source` e `event_receiver` de `native` para `managed`. Como alternativa, remova o atributo.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3825 e mostra como corrigi-lo:

```cpp
// C3825a.cpp
// compile with: /clr
public delegate void del1();

[event_source(native)]           // To fix, change 'native' to 'managed' or delete this line
ref class CEventSrc
{
public:
   event del1^ event1;       // C3825

   void FireEvents() {
      event1();
   }
};

[event_receiver(native)]         // To fix, change 'native' to 'managed' or delete this line
ref class CEventRec
{
public:
   void handler1()
   {
      System::Console::WriteLine("Executing handler1().\n");
   }
   void HookEvents(CEventSrc^ pSrc)
   {
      pSrc->event1 += gcnew del1(this, &CEventRec::handler1);
   }
   void UnhookEvents(CEventSrc^ pSrc)
   {
      pSrc->event1 -= gcnew del1(this, &CEventRec::handler1);
   }
};

int main()
{
   CEventSrc^ pEventSrc = gcnew CEventSrc;
   CEventRec^ pEventRec = gcnew CEventRec;
   pEventRec->HookEvents(pEventSrc);
   pEventSrc->FireEvents();
   pEventRec->UnhookEvents(pEventSrc);
}
```
