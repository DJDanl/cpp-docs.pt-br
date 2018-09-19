---
title: Compilador aviso (nível 1) C4441 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4441
dev_langs:
- C++
helpviewer_keywords:
- C4441
ms.assetid: 7fc540a5-e41f-47cf-aa37-b2b699c2685e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a505c47ea348175a16c91c309646428f1222d091
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46033427"
---
# <a name="compiler-warning-level-1-c4441"></a>Compilador aviso (nível 1) C4441

convenção de chamada de 'cc1' ignorado; 'cc2' usado em vez disso

Funções de membro em tipos gerenciados definidos pelo usuário e genéricos de função global devem usar o [clrcall](../../cpp/clrcall.md) convenção de chamada.  O compilador usado `__clrcall`.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4441.

```
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