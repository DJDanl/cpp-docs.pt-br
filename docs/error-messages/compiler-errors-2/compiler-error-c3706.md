---
title: Erro do compilador C3706
ms.date: 11/04/2016
f1_keywords:
- C3706
helpviewer_keywords:
- C3706
ms.assetid: d20a33eb-d625-46c5-ac87-32075a590d07
ms.openlocfilehash: 2d474db5a4d50aed7b59e6f48fb5a3e8165f10c6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62400286"
---
# <a name="compiler-error-c3706"></a>Erro do compilador C3706

'function': deve ser uma interface COM para disparar eventos COM

A interface de eventos que você pode usar para disparar eventos COM deve ser uma interface COM. Nessa situação, a interface deve ser definida usando um Visual C++ atributo, ou usando importados [#import](../../preprocessor/hash-import-directive-cpp.md) de uma biblioteca de tipos com o atributo embedded_idl de #import.

Observe que o `#include` linhas dos arquivos de cabeçalho de ATL mostrados no exemplo a seguir são necessárias para usar eventos COM. Para corrigir esse erro, verifique `IEvents` (a interface de eventos) uma interface COM, aplicando um dos seguintes atributos à definição da interface: [objeto](../../windows/object-cpp.md), [duplo](../../windows/dual.md), ou [ dispinterface](../../windows/dispinterface.md).

Se uma interface for de um arquivo de cabeçalho gerado pelo MIDL, o compilador não o reconhecerão como uma interface COM.

O exemplo a seguir gera C3706:

```
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