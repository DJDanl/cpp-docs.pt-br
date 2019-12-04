---
title: Erro do compilador C3769
ms.date: 11/04/2016
f1_keywords:
- C3769
helpviewer_keywords:
- C3769
ms.assetid: 341675e1-7428-4da6-8275-1b2f0a70dacc
ms.openlocfilehash: 03f51ae589c56b28eb7a1484669d5982cd8f5dcb
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757183"
---
# <a name="compiler-error-c3769"></a>Erro do compilador C3769

' type ': uma classe aninhada não pode ter o mesmo nome que a classe de circunscrição imediata

Uma classe aninhada não pode ter o mesmo nome que a classe que está sendo fechada imediatamente.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3769.

```cpp
// C3769.cpp
// compile with: /c
class x {
   class x {};   // C3769
   class y {
      class x{};   // OK
   };
};
```
