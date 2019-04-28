---
title: Erro do compilador C3217
ms.date: 11/04/2016
f1_keywords:
- C3217
helpviewer_keywords:
- C3217
ms.assetid: 99070417-c23a-4d82-bdd2-04be1a07adea
ms.openlocfilehash: bcb63c7025f0addda546379947e2e1f5c3afc545
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62311651"
---
# <a name="compiler-error-c3217"></a>Erro do compilador C3217

'param': parâmetro genérico não pode ser restringido nesta declaração

Uma restrição foi mal formada; a restrição de parâmetro genérico deve concordar com o parâmetro de modelo de classe genérica.

O exemplo a seguir gera C3217:

```
// C3217.cpp
// compile with: /clr
interface struct A {};

generic <class T>
ref class C {
   generic <class T1>
   where T : A   // C3217
   void f();
};
```

O exemplo a seguir demonstra uma possível resolução:

```
// C3217b.cpp
// compile with: /clr /c
interface struct A {};

generic <class T>
ref class C {
   generic <class T1>
   where T1 : A
   void f();
};
```