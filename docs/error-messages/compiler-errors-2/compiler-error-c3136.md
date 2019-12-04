---
title: Erro do compilador C3136
ms.date: 10/03/2018
f1_keywords:
- C3136
helpviewer_keywords:
- C3136
ms.assetid: c77103cd-00f7-408e-b74b-4f8562039d31
ms.openlocfilehash: 75862f3b80d617b607a7b3e735cb3e16e9a40bb7
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757378"
---
# <a name="compiler-error-c3136"></a>Erro do compilador C3136

' interface ': uma interface COM só pode herdar de outra interface COM, ' interface ' não é uma interface COM

Uma interface à qual você aplicou um [atributo de interface](../../windows/attributes/interface-attributes.md) herda de uma interface que não é uma interface com. Uma interface COM, por fim, herda de `IUnknown`. Qualquer interface precedida por um atributo de interface é uma interface COM.

O exemplo a seguir gera C3136:

```cpp
// C3136.cpp
#include "unknwn.h"

__interface A   // C3136
// try the following line instead
// _interface A : IUnknown
{
   int a();
};

[object]
__interface B : A
{
   int aa();
};
```
