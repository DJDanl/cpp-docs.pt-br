---
title: Erro do compilador C3842
ms.date: 11/04/2016
f1_keywords:
- C3842
helpviewer_keywords:
- C3842
ms.assetid: 41a1a44a-c618-40a2-8d26-7da27d14095d
ms.openlocfilehash: 881165a1100d1c8791ecd5f50eda6a2e9f1650eb
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74754908"
---
# <a name="compiler-error-c3842"></a>Erro do compilador C3842

' function ': não há suporte para qualificadores ' const ' e ' volatile ' em funções membro de tipos de WinRT ou gerenciados

[const](../../cpp/const-cpp.md) e [volatile](../../cpp/volatile-cpp.md) não têm suporte em funções membro de Windows Runtime ou tipos gerenciados.

O exemplo a seguir gera C3842:

```cpp
// C3842a.cpp
// compile with: /clr /c
public ref struct A {
   void f() const {}   // C3842
   void f() volatile {}   // C3842

   void f() {}
};
```
