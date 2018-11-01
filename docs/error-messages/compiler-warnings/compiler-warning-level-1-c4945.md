---
title: Compilador aviso (nível 1) C4945
ms.date: 11/04/2016
f1_keywords:
- C4945
helpviewer_keywords:
- C4945
ms.assetid: 6d2079ea-dc59-4611-bc68-9a22c06f7587
ms.openlocfilehash: 62dfbaed28f1afcdedb41d83158dfe4e8e0f61b6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50653850"
---
# <a name="compiler-warning-level-1-c4945"></a>Compilador aviso (nível 1) C4945

'symbol': não é possível importar símbolo de 'assembly2': como 'symbol' já foi importado de outro assembly 'assembly1'

Um símbolo foi importado de um assembly referenciado, mas esse símbolo já foi importado de outro assembly referenciado. Não fazer referência a um dos assemblies ou obter o nome do símbolo alterado em um dos assemblies.

Os exemplos a seguir geram C4945.

```
// C4945a.cs
// compile with: /target:library
// C# source code to create a dll
public class ClassA {
   public int i;
}
```

E, em seguida,

```
// C4945b.cs
// compile with: /target:library
// C# source code to create a dll
public class ClassA {
   public int i;
}
```

E, em seguida,

```
// C4945c.cpp
// compile with: /clr /LD /W1
#using "C4945a.dll"
#using "C4945b.dll"   // C4945
```