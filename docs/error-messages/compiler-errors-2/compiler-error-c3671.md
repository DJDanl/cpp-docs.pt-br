---
title: Erro do compilador C3671
ms.date: 11/04/2016
f1_keywords:
- C3671
helpviewer_keywords:
- C3671
ms.assetid: d684e4ae-87e2-4424-80bb-6f346652c831
ms.openlocfilehash: c4534b11f3aedf638f69337fb6a7af778e086bb4
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62215011"
---
# <a name="compiler-error-c3671"></a>Erro do compilador C3671

'function_1': função não substitui 'function_2'

Ao usar a sintaxe de substituição explícita, o compilador gera um erro se uma função não é substituída.  Ver [substituições explícitas](../../extensions/explicit-overrides-cpp-component-extensions.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3671.

```
// C3671.cpp
// compile with: /clr /c
ref struct S {
   virtual void f();
};

ref struct S1 : S {
   virtual void f(int) new sealed = S::f;   // C3671
   virtual void f() new sealed = S::f;
};
```