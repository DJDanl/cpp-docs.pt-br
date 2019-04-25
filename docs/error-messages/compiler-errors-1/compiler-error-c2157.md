---
title: Erro do compilador C2157
ms.date: 11/04/2016
f1_keywords:
- C2157
helpviewer_keywords:
- C2157
ms.assetid: babbca24-16dc-4b69-be14-a675029249c1
ms.openlocfilehash: 1338a0f0ceb1a42ed84fe74e4ed9a2d774979075
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62174855"
---
# <a name="compiler-error-c2157"></a>Erro do compilador C2157

'function': deve ser declarado antes de usar na lista de pragma

O nome da função não é declarado antes que está sendo referenciado na lista de funções para um [alloc_text](../../preprocessor/alloc-text.md) pragma.

O exemplo a seguir gera C2157:

```
// C2157.cpp
// compile with: /c
#pragma alloc_text( "func", func)   // C2157

// OK
extern "C" void func();
#pragma alloc_text( "func", func)
```