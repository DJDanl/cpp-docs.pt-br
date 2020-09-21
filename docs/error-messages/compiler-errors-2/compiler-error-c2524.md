---
title: Erro do compilador C2524
ms.date: 11/04/2016
f1_keywords:
- C2524
helpviewer_keywords:
- C2524
ms.assetid: e71d17f5-2fc2-416b-8dbd-e9bed85eb33a
ms.openlocfilehash: 57445fec5ee5bb55ac3d16ee21a0e29eb4b21ed1
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90743341"
---
# <a name="compiler-error-c2524"></a>Erro do compilador C2524

' destruidor ': um destruidor/finalizador deve ter uma lista de parâmetros ' void '

O destruidor ou finalizador tinha uma lista de parâmetros que não é [nula](../../cpp/void-cpp.md). Outros tipos de parâmetro não são permitidos.

## <a name="examples"></a>Exemplos

O código a seguir reproduz C2524.

```cpp
// C2524.cpp
// compile with: /c
class A {
   A() {}
   ~A(int i) {}    // C2524
   // try the following line instead
   // ~A() {}
};
```

O código a seguir reproduz C2524.

```cpp
// C2524_b.cpp
// compile with: /clr /c
ref struct I1 {
protected:
   !I1(int i);   // C2524
   // try the following line instead
   // !I1();
};
```
