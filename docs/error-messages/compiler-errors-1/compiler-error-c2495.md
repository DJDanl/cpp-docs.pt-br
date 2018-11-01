---
title: Erro do compilador C2495
ms.date: 11/04/2016
f1_keywords:
- C2495
helpviewer_keywords:
- C2495
ms.assetid: bb7066fe-3549-4901-97e4-157f3c04dd57
ms.openlocfilehash: 83a0359fce175b12dd18e2500d63d7a86bed9f0b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50436030"
---
# <a name="compiler-error-c2495"></a>Erro do compilador C2495

'identifier': 'nothrow' só pode ser aplicado a declarações de função ou definições

O [nothrow](../../cpp/nothrow-cpp.md) atributo estendido pode ser aplicado a declarações de função ou apenas definições.

O exemplo a seguir gera C2495:

```
// C2495.cpp
// compile with: /c
__declspec(nothrow) class X {   // C2495
   int m_data;
} x;

__declspec(nothrow) void test();   // OK
```