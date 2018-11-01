---
title: Compilador aviso (nível 3) C4570
ms.date: 11/04/2016
f1_keywords:
- C4570
helpviewer_keywords:
- C4570
ms.assetid: feec1225-e6ad-4995-8d96-c22e864a77bd
ms.openlocfilehash: 1c92bd7f632ea6662c3cee1bcaa1dd0c917fb2a1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50661299"
---
# <a name="compiler-warning-level-3-c4570"></a>Compilador aviso (nível 3) C4570

'type': não é declarado explicitamente como abstract, mas possui funções abstract

Um tipo que contém [abstrata](../../windows/abstract-cpp-component-extensions.md) funções devem ser em si marcado como abstrato.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4570.

```
// C4570.cpp
// compile with: /clr /W3 /c
ref struct X {   // C4570
// try the following line instead
// ref class X abstract {
   virtual void f() abstract;
};
```