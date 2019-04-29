---
title: Erro do compilador C3707
ms.date: 11/04/2016
f1_keywords:
- C3707
helpviewer_keywords:
- C3707
ms.assetid: ac63a5dd-7a4b-48d2-9f2a-be9cb090134c
ms.openlocfilehash: 8a1525539c84ea427815a03057bb6d2f9213fec7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62328517"
---
# <a name="compiler-error-c3707"></a>Erro do compilador C3707

'function': método dispinterface deve possuir um dispid

Se você usar um `dispinterface` método, você deve atribuí-lo um `dispid`. Para corrigir esse erro, atribua uma `dispid` para o `dispinterface` método, por exemplo, removendo o `id` atributo no método no exemplo a seguir. Para obter mais informações, consulte os atributos [dispinterface](../../windows/dispinterface.md) e [id](../../windows/id.md).

O exemplo a seguir gera C3707:

```
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