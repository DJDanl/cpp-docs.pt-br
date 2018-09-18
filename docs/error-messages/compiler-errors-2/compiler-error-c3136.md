---
title: Erro do compilador C3136 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 0439aa157a683065ccf7fff5b5f9d6d4d85e2f12
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46054214"
---
# <a name="compiler-error-c3136"></a>Erro do compilador C3136

'interface': uma interface COM só pode herdar de outra interface COM, 'interface' não é uma interface COM

Uma interface para o qual você aplicou um [atributo interface](../../windows/interface-attributes.md) herda de uma interface que não é uma interface COM. Uma interface COM, por fim, herda `IUnknown`. Qualquer interface precedido por um atributo de interface é uma interface COM.

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