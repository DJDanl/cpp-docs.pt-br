---
title: Erro do compilador C2584
ms.date: 11/04/2016
f1_keywords:
- C2584
helpviewer_keywords:
- C2584
ms.assetid: 836e2c0a-86c0-4742-b432-beb0191ad20e
ms.openlocfilehash: 2c3b10ecd6808ccd864ecf877fe9f1d0e9f30a3a
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74748626"
---
# <a name="compiler-error-c2584"></a>Erro do compilador C2584

' Class ': base direta ' base2 ' está inacessível; Já é uma base de ' Base1 '

`Class` já deriva diretamente do `Base1`. `Base2` também deriva de `Base1`. `Class` não pode derivar de `Base2` porque isso significaria herdar (indiretamente) de `Base1` novamente, o que não é válido porque `Base1` já é uma classe base direta.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2584.

```cpp
// C2584.cpp
// compile with: /c
struct A1 {
   virtual int MyFunction();
};

struct A2 {
    virtual int MyFunction();
};

struct B1: public virtual A1, virtual A2 {
    virtual int MyFunction();
};

struct B2: public virtual A2, virtual A1 {
    virtual int MyFunction();
};

struct C: virtual B1, B2 {
    virtual int MyFunction();
};

struct Z : virtual B2, virtual C {   // C2584
// try the following line insted
// struct Z : virtual C {
    virtual int MyFunction();
};
```
