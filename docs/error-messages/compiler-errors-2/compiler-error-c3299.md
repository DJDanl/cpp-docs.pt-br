---
title: Erro do compilador C3299
ms.date: 11/04/2016
f1_keywords:
- C3299
helpviewer_keywords:
- C3299
ms.assetid: 7cabdf01-bceb-404f-9401-cdd9c7fc1641
ms.openlocfilehash: 148433f0d959985eb5a874f588f8cbf9d377e8b7
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74735951"
---
# <a name="compiler-error-c3299"></a>Erro do compilador C3299

' member_function ': não é possível especificar restrições, elas são herdadas do método base

Ao substituir uma função de membro genérico, você não pode especificar cláusulas de restrição (repetir as restrições implica que as restrições não são herdadas).

As cláusulas de restrição na função genérica que você está substituindo serão herdadas.

Confira mais informações em [Restrições em parâmetros de tipo genérico (C++/CLI)](../../extensions/constraints-on-generic-type-parameters-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3299.

```cpp
// C3299.cpp
// compile with: /clr /c
public ref struct R {
   generic<class T>
   where T : R
   virtual void f();
};

public ref struct S : R {
   generic<class T>
   where T : R   // C3299
   virtual void f() override;
};
```
