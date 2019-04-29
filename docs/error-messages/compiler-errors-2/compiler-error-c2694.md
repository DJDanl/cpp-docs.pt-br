---
title: Erro do compilador C2694
ms.date: 11/04/2016
f1_keywords:
- C2694
helpviewer_keywords:
- C2694
ms.assetid: 8dc2cec2-67ae-4e16-8c0c-374425aca8bc
ms.openlocfilehash: 4897512f6bd27465b7281d7a27757918128202d2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62367740"
---
# <a name="compiler-error-c2694"></a>Erro do compilador C2694

'override': função virtual de substituição possui especificação de exceção menos restritiva do que a classe base membro virtual função 'base'

Uma função virtual foi substituída, mas em [/Za](../../build/reference/za-ze-disable-language-extensions.md), a função de substituição tinha menos restritivo [especificação de exceção](../../cpp/exception-specifications-throw-cpp.md).

O exemplo a seguir gera C2694:

```
// C2694.cpp
// compile with: /Za /c
class MyBase {
public:
   virtual void f(void) throw(int) {
   }
};

class Derived : public MyBase {
public:
   void f(void) throw(...) {}   // C2694
   void f2(void) throw(int) {}   // OK
};
```