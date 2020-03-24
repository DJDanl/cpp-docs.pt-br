---
title: Aviso do compilador (nível 2) C4307
ms.date: 11/04/2016
f1_keywords:
- C4307
helpviewer_keywords:
- C4307
ms.assetid: 7cca11e9-be61-49e4-8b15-88b84f0cbf07
ms.openlocfilehash: f6e06acaf43708d6c0da6d67531b6c4b9f202971
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80161874"
---
# <a name="compiler-warning-level-2-c4307"></a>Aviso do compilador (nível 2) C4307

' operator ': estouro de constante integral

O operador é usado em uma expressão que resulta em uma constante de inteiro estourando o espaço alocado para ele. Talvez seja necessário usar um tipo maior para a constante. Um **int assinado** contém um valor menor que um `unsigned int` porque o **int assinado** usa um bit para representar o sinal.

O exemplo a seguir gera C4307:

```cpp
// C4307.cpp
// compile with: /W2
int i = 2000000000 + 2000000000;   // C4307
int j = (unsigned)2000000000 + 2000000000;   // OK

int main()
{
}
```
