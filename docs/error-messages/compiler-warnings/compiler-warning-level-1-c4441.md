---
title: Aviso do compilador (nível 1) C4441
ms.date: 11/04/2016
f1_keywords:
- C4441
helpviewer_keywords:
- C4441
ms.assetid: 7fc540a5-e41f-47cf-aa37-b2b699c2685e
ms.openlocfilehash: 6f45288e1e52d157e5c135a45c0801a909fccfbc
ms.sourcegitcommit: e5192a25c084eda9eabfa37626f3274507e026b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2019
ms.locfileid: "73966032"
---
# <a name="compiler-warning-level-1-c4441"></a>Aviso do compilador (nível 1) C4441

Convenção de chamada de ' cc1 ' ignorada; ' cc2 ' usado em vez disso

Funções de membro em tipos gerenciados definidos pelo usuário e genéricos de funções globais devem usar a Convenção de chamada [__clrcall](../../cpp/clrcall.md) .  O compilador usou `__clrcall`.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4441.

```cpp
// C4441.cpp
// compile with: /clr /W1 /c
generic <class ItemType>
void __cdecl Test(ItemType item) {}   // C4441
// try the following line instead
// void Test(ItemType item) {}

ref struct MyStruct {
   void __cdecl Test(){}   // C4441
   void Test2(){}   // OK
};
```