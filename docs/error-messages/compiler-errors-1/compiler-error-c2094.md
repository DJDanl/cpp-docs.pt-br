---
title: Erro do compilador C2094 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2094
dev_langs:
- C++
helpviewer_keywords:
- C2094
ms.assetid: 9e4f8f88-f189-46e7-91c9-481bacc7af87
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6e3591fef423bc24562a2f2edf18f7f2774cfcc4
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46073519"
---
# <a name="compiler-error-c2094"></a>Erro do compilador C2094

rótulo 'identifier' foi redefinido

O rótulo usado por um [goto](../../cpp/goto-statement-cpp.md) instrução não existe na função.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2094:

```cpp
// C2094.c
int main() {
   goto test;
}   // C2094
```

Solução possível:

```cpp
// C2094b.c
int main() {
   goto test;
   test:
   {
   }
}
```