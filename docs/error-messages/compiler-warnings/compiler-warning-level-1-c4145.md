---
title: Aviso do compilador (nível 1) C4145
ms.date: 11/04/2016
f1_keywords:
- C4145
helpviewer_keywords:
- C4145
ms.assetid: 0440777a-cca2-4159-aff5-e67a254ad64a
ms.openlocfilehash: 19d2d1a018c7ee981f83aa6fa0914f1241c55538
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220100"
---
# <a name="compiler-warning-level-1-c4145"></a>Aviso do compilador (nível 1) C4145

' expression1 ': expressão relacional como expressão de comutador; possível confusão com ' expression2 '

Uma **`switch`** instrução usa uma expressão relacional como sua expressão de controle, o que resulta em um valor booliano para as **`case`** instruções. Você quis dizer a *expression2*?

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4145:

```cpp
// C4145.cpp
// compile with: /W1
int main() {
   int i = 0;
   switch(i == 1) {   // C4145, use i instead of i == 1 to resolve
      case 1:
         break;
      default:
         break;
   }
}
```
