---
title: Erro do compilador C2486 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2486
dev_langs:
- C++
helpviewer_keywords:
- C2486
ms.assetid: 436da349-6461-4e32-bfca-4f3e620108e2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 106d70c031a6981157875c86b1332bbe3be8a668
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46081722"
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