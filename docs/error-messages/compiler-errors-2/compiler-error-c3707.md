---
title: Erro do compilador C3707 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3707
dev_langs:
- C++
helpviewer_keywords:
- C3707
ms.assetid: ac63a5dd-7a4b-48d2-9f2a-be9cb090134c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d18d4a82d06018cdba6147ba6756b1718648847a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46052771"
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