---
title: Erro do compilador C2394
ms.date: 11/04/2016
f1_keywords:
- C2394
helpviewer_keywords:
- C2394
ms.assetid: 653fa9a0-29b3-48aa-bc01-82f98f717a2b
ms.openlocfilehash: 2c8c23939298f5603b59636ede08b65acaa0f22b
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74744986"
---
# <a name="compiler-error-c2394"></a>Erro do compilador C2394

' your_type:: operator'op ' ": CLR ou WinRToperator não é válido. Pelo menos um parâmetro deve ser dos seguintes tipos: ' t ^ ', ' t ^% ', ' t ^ & ', em que T = ' your_type '

Um operador em um Windows Runtime ou tipo gerenciado não tinha pelo menos um parâmetro cujo tipo é o mesmo que o tipo do valor de retorno do operador.

O exemplo a seguir gera C2394:

```cpp
// C2394.cpp
// compile with: /clr /c
ref struct Y {
   static Y^ operator -(int i, char c);   // C2394

   // OK
   static Y^ operator -(Y^ hY, char c);
   // or
   static Y^ operator -(int i, Y^& rhY);
};
```
