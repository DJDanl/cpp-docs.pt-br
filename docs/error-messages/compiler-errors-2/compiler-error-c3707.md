---
title: Erro do compilador C3707
ms.date: 11/04/2016
f1_keywords:
- C3707
helpviewer_keywords:
- C3707
ms.assetid: ac63a5dd-7a4b-48d2-9f2a-be9cb090134c
ms.openlocfilehash: a09bf080c72e154a37cec5cdb75e714c12dd7150
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91507973"
---
# <a name="compiler-error-c3707"></a>Erro do compilador C3707

' function ': o método de dispinterface deve ter um DISPID

Se você usar um `dispinterface` método, deverá atribuí-lo a `dispid` . Para corrigir esse erro, atribua um `dispid` para o `dispinterface` método, por exemplo, removendo o comentário do `id` atributo no método no exemplo abaixo. Para obter mais informações, consulte os atributos [dispinterface](../../windows/attributes/dispinterface.md) e [ID](../../windows/attributes/id.md).

O exemplo a seguir gera C3707:

```cpp
// C3707.cpp
#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>

[module(name="xx")];
[dispinterface]
__interface IEvents : IDispatch
{
   HRESULT event1([in] int i);   // C3707
   // try the following line instead
   // [id(1)] HRESULT event1([in] int i);
};

int main() {
}
```
