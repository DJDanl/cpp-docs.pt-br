---
title: Erro do compilador C2669
ms.date: 11/04/2016
f1_keywords:
- C2669
helpviewer_keywords:
- C2669
ms.assetid: f9cb8111-bcdc-484b-a863-2c42e15a0496
ms.openlocfilehash: 7944ced947ba1d7c8b10172560ce6237a554e236
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62300785"
---
# <a name="compiler-error-c2669"></a>Erro do compilador C2669

função de membro não permitida em union anônima

[Uniões anônimas](../../cpp/unions.md#anonymous_unions) não pode ter funções de membro.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2669:

```cpp
// C2669.cpp
struct X {
   union {
      int i;
      void f() {   // C2669, remove function
         i = 0;
      }
   };
};
```
