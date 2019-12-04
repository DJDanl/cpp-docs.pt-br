---
title: Erro do compilador C3706
ms.date: 11/04/2016
f1_keywords:
- C3706
helpviewer_keywords:
- C3706
ms.assetid: d20a33eb-d625-46c5-ac87-32075a590d07
ms.openlocfilehash: 810ec59a814b04349913648fb49a03eb63912cd9
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757976"
---
# <a name="compiler-error-c3706"></a>Erro do compilador C3706

' function ': deve ser uma interface COM para disparar eventos COM

A interface de evento que você usa para disparar eventos COM deve ser uma interface COM. Nessa situação, a interface deve ser definida usando um atributo Visual C++ ou importada usando [#import](../../preprocessor/hash-import-directive-cpp.md) de uma biblioteca de tipos com o atributo embedded_idl do #import.

Observe que as linhas de `#include` dos arquivos de cabeçalho ATL mostrados no exemplo abaixo são necessárias para o uso de eventos COM. Para corrigir esse erro, torne `IEvents` (a interface de eventos) uma interface COM aplicando um dos seguintes atributos à definição de interface: [Object](../../windows/object-cpp.md), [Dual](../../windows/dual.md)ou [dispinterface](../../windows/dispinterface.md).

Se uma interface for de um arquivo de cabeçalho gerado pelo MIDL, o compilador não o reconhecerá como uma interface COM.

O exemplo a seguir gera C3706:

```cpp
// C3706.cpp
// compile with: /c
// C3706 expected
#define _ATL_ATTRIBUTES 1
#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>

[module(dll, name="idid", uuid="12341234-1234-1234-1234-123412341234")];

// Uncomment the following line to resolve.
// [object, uuid="12341234-1234-1234-1234-123412341237"]
__interface IEvents : IUnknown {
   HRESULT event1(/*[in]*/ int i);   // uncomment [in]
};

[dual, uuid="12341234-1234-1234-1234-123412341235"]
__interface IBase {
   HRESULT fireEvents();
};

[coclass, event_source(com), uuid="12341234-1234-1234-1234-123412341236"]
class CEventSrc : public IBase {
   public:
   __event __interface IEvents;

   HRESULT fireEvents() {
      HRESULT hr = IEvents_event1(123);
      return hr;
   }
};
```
