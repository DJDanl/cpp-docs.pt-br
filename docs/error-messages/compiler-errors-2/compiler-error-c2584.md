---
title: Erro do compilador C2584
ms.date: 11/04/2016
f1_keywords:
- C2584
helpviewer_keywords:
- C2584
ms.assetid: 836e2c0a-86c0-4742-b432-beb0191ad20e
ms.openlocfilehash: b61ad65555b5d5232468206f6170223c5f160a34
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50556683"
---
# <a name="compiler-error-c2584"></a>Erro do compilador C2584

'Class': direta base 'Base2' é inacessível; já é uma base de 'Base1'

`Class` já deriva diretamente de `Base1`. `Base2` também deriva de `Base1`. `Class` não é possível derivar `Base2` porque isso significaria herdando (indiretamente) `Base1` novamente, que não é legal porque `Base1` já é uma classe base direta.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2584.

```
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