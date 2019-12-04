---
title: Erro do compilador C3705
ms.date: 11/04/2016
f1_keywords:
- C3705
helpviewer_keywords:
- C3705
ms.assetid: 8361017d-5782-4214-a9d7-e9825fd29bc8
ms.openlocfilehash: c4f77457be95ae22b2a67214207d361ca105811d
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757924"
---
# <a name="compiler-error-c3705"></a>Erro do compilador C3705

' function ': não é possível encontrar a interface de eventos

Você deve definir uma interface de evento para usar eventos COM. Observe que as linhas de `#include` dos arquivos de cabeçalho ATL mostrados no exemplo abaixo são necessárias para o uso de eventos COM. Para corrigir esse erro, remova o comentário da definição da interface `IEvents` no código de exemplo.

O exemplo a seguir gera C3705:

```cpp
// C3705.cpp
// compile with: /c
#define _ATL_ATTRIBUTES 1
#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>

[module(dll, name="idid", uuid="12341234-1234-1234-1234-123412341234")];

// Uncomment the following 4 lines to resolve.
// [object, uuid("00000000-0000-0000-0000-000000000003")]
// __interface IEvents : IUnknown {
//    HRESULT event1([in] int i);
// };

[dual, uuid("00000000-0000-0000-0000-000000000001")]
__interface IBase {
   HRESULT fireEvents();
};

[coclass, event_source(com), uuid("00000000-0000-0000-0000-000000000002")]
class CEventSrc : public IBase {
public:
   __event __interface IEvents;   // C3705 uncomment IEvents to resolve
   HRESULT fireEvents() {
      HRESULT hr = IEvents_event1(123);
      return hr;
   }
};
```
