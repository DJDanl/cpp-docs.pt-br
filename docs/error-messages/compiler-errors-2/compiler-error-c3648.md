---
title: Erro do compilador C3648
ms.date: 11/04/2016
f1_keywords:
- C3648
helpviewer_keywords:
- C3648
ms.assetid: 5d042989-41cb-4cd0-aa50-976b70146aaf
ms.openlocfilehash: f3ef949b2651631f30a9c614a0d21b2668b7239f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50653759"
---
# <a name="compiler-error-c3648"></a>Erro do compilador C3648

Essa sintaxe de substituição explícita requer /CLR: oldSyntax

Ao compilar para a sintaxe gerenciada mais recente, o compilador encontrou explícito substituem sintaxe para versões anteriores que não é mais suportada.

Para obter mais informações, consulte [substituições explícitas](../../windows/explicit-overrides-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3648:

```
// C3648.cpp
// compile with: /clr
public interface struct I {
   void f();
};

public ref struct R : I {
   virtual void I::f() {}   // C3648
   // try the following line instead
   // virtual void f() = I::f{}
};
```