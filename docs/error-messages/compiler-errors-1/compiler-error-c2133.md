---
title: Erro do compilador C2133
ms.date: 11/04/2016
f1_keywords:
- C2133
helpviewer_keywords:
- C2133
ms.assetid: 8942f9e8-9818-468f-97db-09dbd124fcae
ms.openlocfilehash: b51b556ea576e02b85a5c2ee5032909af39c7b2f
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74758431"
---
# <a name="compiler-error-c2133"></a>Erro do compilador C2133

' identifier ': tamanho desconhecido

Uma matriz sem tamanho é declarada como membro de uma classe, estrutura, União ou enumeração. A opção/Za (ANSI C) não permite matrizes de membros sem tamanho.

O exemplo a seguir gera C2133:

```cpp
// C2133.cpp
// compile with: /Za
struct X {
   int a[0];   // C2133 unsized array
};
```

Resolução possível:

```cpp
// C2133b.cpp
// compile with: /c
struct X {
   int a[0];   // no /Za
};
```
