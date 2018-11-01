---
title: Erro do compilador C3668
ms.date: 11/04/2016
f1_keywords:
- C3668
helpviewer_keywords:
- C3668
ms.assetid: 53a96698-bde4-4447-95b5-b5108291f60c
ms.openlocfilehash: 7bc03050518055bb3167ee2ce9d1e1fcd88b59b0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50504553"
---
# <a name="compiler-error-c3668"></a>Erro do compilador C3668

'method': método com especificador de substituição 'override' não substituiu nenhum método de classe base

Uma função de tentativa de substituir uma função não existente.

Para obter mais informações, consulte [substituições explícitas](../../windows/explicit-overrides-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3668.

```
// C3668.cpp
// compile with: /c
__interface I {
   void f(int);   // virtual by default
};

class J {
public:
   void g(int);
   virtual void h(int);
};

struct R : I,J {
   virtual void f() override {}   // C3668
   virtual void f(int) override {}   // OK

   virtual void g(int) override {}   // C3668
   virtual void h(int) override {}   // OK
};
```