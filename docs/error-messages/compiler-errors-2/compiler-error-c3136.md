---
title: Erro do compilador C3136 | Microsoft Docs
ms.custom: ''
ms.date: 10/03/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3136
dev_langs:
- C++
helpviewer_keywords:
- C3136
ms.assetid: c77103cd-00f7-408e-b74b-4f8562039d31
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 082a89b69092a8320f6bb4b930d01a7fd2de10c8
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48788377"
---
# <a name="compiler-error-c3136"></a>Erro do compilador C3136

'interface': uma interface COM só pode herdar de outra interface COM, 'interface' não é uma interface COM

Uma interface para o qual você aplicou um [atributo interface](../../windows/attributes/interface-attributes.md) herda de uma interface que não é uma interface COM. Uma interface COM, por fim, herda `IUnknown`. Qualquer interface precedido por um atributo de interface é uma interface COM.

O exemplo a seguir gera C3136:

```
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