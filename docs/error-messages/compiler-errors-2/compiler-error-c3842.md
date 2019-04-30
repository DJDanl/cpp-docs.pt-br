---
title: Erro do compilador C3842
ms.date: 11/04/2016
f1_keywords:
- C3842
helpviewer_keywords:
- C3842
ms.assetid: 41a1a44a-c618-40a2-8d26-7da27d14095d
ms.openlocfilehash: a61a69aca53f7f8996d0261a57b749930ecc01cc
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62385505"
---
# <a name="compiler-error-c3842"></a>Erro do compilador C3842

'function': qualificadores 'const' e 'volatile' em funções de membro de WinRT ou tipos gerenciados não são suportados

[Const](../../cpp/const-cpp.md) e [volátil](../../cpp/volatile-cpp.md) não têm suporte em funções membro de tempo de execução do Windows ou tipos gerenciados.

O exemplo a seguir gera C3842:

```
// C3842a.cpp
// compile with: /clr /c
public ref struct A {
   void f() const {}   // C3842
   void f() volatile {}   // C3842

   void f() {}
};
```