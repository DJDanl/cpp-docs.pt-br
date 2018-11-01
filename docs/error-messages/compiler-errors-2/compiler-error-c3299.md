---
title: Erro do compilador C3299
ms.date: 11/04/2016
f1_keywords:
- C3299
helpviewer_keywords:
- C3299
ms.assetid: 7cabdf01-bceb-404f-9401-cdd9c7fc1641
ms.openlocfilehash: 4ad48ea0bc09e098a41cb9aa969a08e9ead48f73
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50484812"
---
# <a name="compiler-error-c3299"></a>Erro do compilador C3299

'member_function': não é possível especificar restrições, elas são herdadas do método base

Ao substituir uma função de membro genérico, você não pode especificar as cláusulas de restrição (das restrições implica que as restrições não são herdadas de repetição).

As cláusulas de restrição sobre a função genérica que você está substituindo serão herdadas.

Para obter mais informações, consulte [restrições em parâmetros de tipo genéricos (C + + / CLI)](../../windows/constraints-on-generic-type-parameters-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3299.

```
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