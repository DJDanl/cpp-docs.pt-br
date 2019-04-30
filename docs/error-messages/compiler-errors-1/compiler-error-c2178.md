---
title: Erro do compilador C2178
ms.date: 05/08/2017
f1_keywords:
- C2178
helpviewer_keywords:
- C2178
ms.assetid: 79a14158-17f3-4221-bd06-9d675c49cef4
ms.openlocfilehash: cd153bb5b331872bfe35b046d41612998bd0eff7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62385999"
---
# <a name="compiler-error-c2178"></a>Erro do compilador C2178

'*identificador*'não pode ser declarada com'*especificador*' especificador

Um `mutable` especificador foi usado em uma declaração, mas o especificador não é permitido neste contexto.

O `mutable` especificador pode ser aplicado somente aos nomes de membros de dados de classe e não pode ser aplicado a nomes declarados `const` ou `static`e não pode ser aplicado para fazer referência a membros.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como C2178 podem ocorrer e como corrigi-lo.

```
// C2178.cpp
// compile with: cl /c /W4 C2178.cpp

class S {
    mutable const int i; // C2178
    // To fix, declare either const or mutable, not both.
};

mutable int x = 4; // C2178
// To fix, remove mutable keyword
```
