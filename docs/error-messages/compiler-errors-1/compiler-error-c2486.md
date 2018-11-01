---
title: Erro do compilador C2486
ms.date: 11/04/2016
f1_keywords:
- C2486
helpviewer_keywords:
- C2486
ms.assetid: 436da349-6461-4e32-bfca-4f3e620108e2
ms.openlocfilehash: 8d745c03530f331da83b45c765a2cb4bb7d76d8e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50555643"
---
# <a name="compiler-error-c2486"></a>Erro do compilador C2486

Local_size' permitido apenas em função com o atributo 'naked'

Em funções de assembly embutido, o nome `__LOCAL_SIZE` é reservado para as funções declaradas com o [naked](../../cpp/naked-cpp.md) atributo.

O exemplo a seguir gera C2486:

```
// C2486.cpp
// processor: x86
void __declspec(naked) f1() {
   __asm {
      mov   eax,   __LOCAL_SIZE
   }
}
void f2() {
   __asm {
      mov   eax,   __LOCAL_SIZE   // C2486
   }
}
```