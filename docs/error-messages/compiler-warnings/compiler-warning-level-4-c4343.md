---
title: Aviso do compilador (nível 4) C4343
ms.date: 11/04/2016
f1_keywords:
- C4343
helpviewer_keywords:
- C4343
ms.assetid: a721b710-e04f-4d15-b678-e4a2c8fd0181
ms.openlocfilehash: 59803440966b8396ba231dc5a7265620c37f9cc1
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74991191"
---
# <a name="compiler-warning-level-4-c4343"></a>Aviso do compilador (nível 4) C4343

\#pragma Optimize ("g", off) substitui a opção/og

Este aviso, somente válido no compilador da família de processadores Itanium (IPF), relata que um pragma [Optimize](../../preprocessor/optimize.md) substituiu uma opção de compilador [/og](../../build/reference/og-global-optimizations.md) .

O exemplo a seguir gera C4343:

```cpp
// C4343.cpp
// compile with: /Og /W4 /LD
// processor: IPF
#pragma optimize ("g", off)   // C4343
```
