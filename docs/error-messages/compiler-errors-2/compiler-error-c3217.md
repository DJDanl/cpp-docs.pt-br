---
title: Erro do compilador C3217
ms.date: 11/04/2016
f1_keywords:
- C3217
helpviewer_keywords:
- C3217
ms.assetid: 99070417-c23a-4d82-bdd2-04be1a07adea
ms.openlocfilehash: cb837a42841b2695941d4cd6122d186665d2d7e2
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74754574"
---
# <a name="compiler-error-c3217"></a>Erro do compilador C3217

' param ': o parâmetro genérico não pode ser restrito nesta declaração

Uma restrição estava mal formada; o parâmetro genérico de restrição deve concordar com o parâmetro de modelo de classe genérica.

O exemplo a seguir gera C3217:

```cpp
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

```cpp
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
