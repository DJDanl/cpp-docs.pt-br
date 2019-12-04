---
title: Erro do compilador C3707
ms.date: 11/04/2016
f1_keywords:
- C3707
helpviewer_keywords:
- C3707
ms.assetid: ac63a5dd-7a4b-48d2-9f2a-be9cb090134c
ms.openlocfilehash: 6faf035c0f4f68b10b187c56bea4cafc776998cf
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757948"
---
# <a name="compiler-error-c3707"></a>Erro do compilador C3707

' function ': o método de dispinterface deve ter um DISPID

Se você usar um método `dispinterface`, deverá atribuir a ele um `dispid`. Para corrigir esse erro, atribua um `dispid` ao método `dispinterface`, por exemplo, removendo o comentário do atributo `id` no método no exemplo a seguir. Para obter mais informações, consulte os atributos [dispinterface](../../windows/dispinterface.md) e [ID](../../windows/id.md).

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
