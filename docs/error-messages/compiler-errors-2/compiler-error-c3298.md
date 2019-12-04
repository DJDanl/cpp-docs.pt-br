---
title: Erro do compilador C3298
ms.date: 11/04/2016
f1_keywords:
- C3298
helpviewer_keywords:
- C3298
ms.assetid: 458c2680-95bb-4d5e-895f-ce4115844193
ms.openlocfilehash: d5e9586b026e0092491c80c23f55080354c9e465
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760069"
---
# <a name="compiler-error-c3298"></a>Erro do compilador C3298

' constraint_1 ': não é possível usar ' constraint_2 ' como uma restrição porque ' constraint_2 ' tem a restrição REF e ' constraint_1 ' tem a restrição Value

Você não pode especificar características mutuamente exclusivas para uma restrição. Por exemplo, um parâmetro de tipo genérico não pode ser restrito a um tipo de valor e um tipo de referência.

Confira mais informações em [Restrições em parâmetros de tipo genérico (C++/CLI)](../../extensions/constraints-on-generic-type-parameters-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3298.

```cpp
// C3298.cpp
// compile with: /clr /c
generic<class T, class U>
where T : ref class
where U : T, value class   // C3298
public ref struct R {};
```
