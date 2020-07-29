---
title: Erro do compilador C2178
ms.date: 05/08/2017
f1_keywords:
- C2178
helpviewer_keywords:
- C2178
ms.assetid: 79a14158-17f3-4221-bd06-9d675c49cef4
ms.openlocfilehash: 4904c7009151748b4585060c816e0bd5c407be33
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225547"
---
# <a name="compiler-error-c2178"></a>Erro do compilador C2178

'*Identifier*' não pode ser declarado com o especificador '*especificador*'

Um **`mutable`** especificador foi usado em uma declaração, mas o especificador não é permitido neste contexto.

O **`mutable`** especificador só pode ser aplicado a nomes de membros de dados de classe e não pode ser aplicado a nomes declarados **`const`** ou **`static`** e não pode ser aplicado a membros de referência.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como C2178 pode ocorrer e como corrigi-lo.

```cpp
// C2178.cpp
// compile with: cl /c /W4 C2178.cpp

class S {
    mutable const int i; // C2178
    // To fix, declare either const or mutable, not both.
};

mutable int x = 4; // C2178
// To fix, remove mutable keyword
```
