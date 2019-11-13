---
title: Aviso do compilador (nível 1) C4945
ms.date: 11/04/2016
f1_keywords:
- C4945
helpviewer_keywords:
- C4945
ms.assetid: 6d2079ea-dc59-4611-bc68-9a22c06f7587
ms.openlocfilehash: 6a20effcebe1a36fa1356fffefa3a23a0056a0f0
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74052257"
---
# <a name="compiler-warning-level-1-c4945"></a>Aviso do compilador (nível 1) C4945

' Symbol ': não é possível importar o símbolo de ' Assembly2 ': como ' Symbol ' já foi importado de outro assembly ' Assembly1 '

Um símbolo foi importado de um assembly referenciado, mas esse símbolo já foi importado de outro assembly referenciado. Não faça referência a um dos assemblies ou obtenha o nome do símbolo alterado em um dos assemblies.

Os exemplos a seguir geram C4945.

```csharp
// C4945a.cs
// compile with: /target:library
// C# source code to create a dll
public class ClassA {
   public int i;
}
```

E, em seguida,

```csharp
// C4945b.cs
// compile with: /target:library
// C# source code to create a dll
public class ClassA {
   public int i;
}
```

E, em seguida,

```cpp
// C4945c.cpp
// compile with: /clr /LD /W1
#using "C4945a.dll"
#using "C4945b.dll"   // C4945
```