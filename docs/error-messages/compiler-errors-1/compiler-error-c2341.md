---
title: Erro do compilador C2341
ms.date: 11/04/2016
f1_keywords:
- C2341
helpviewer_keywords:
- C2341
ms.assetid: aa2a7da5-e1c8-4225-9939-5bdc50158f31
ms.openlocfilehash: 4356182758398fa7ed1ec6a069affa4bb99ace1a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50631680"
---
# <a name="compiler-error-c2341"></a>Erro do compilador C2341

'nome da seção': segmento deve ser definido usando #pragma data_seg, code_seg ou section antes de usar

Uma [alocar](../../cpp/allocate.md) declaração se refere a um segmento que ainda não foi definido pela [code_seg](../../preprocessor/code-seg.md), [data_seg](../../preprocessor/data-seg.md), ou [seção](../../preprocessor/section.md) pragmas.

O exemplo a seguir gera C2341:

```
// C2341.cpp
// compile with: /c
__declspec(allocate(".test"))   // C2341
int j = 1;
```

Solução possível:

```
// C2341b.cpp
// compile with: /c
#pragma data_seg(".test")
__declspec(allocate(".test"))
int j = 1;
```