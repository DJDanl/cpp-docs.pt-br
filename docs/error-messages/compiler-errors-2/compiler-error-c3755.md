---
title: Erro do compilador C3755
ms.date: 11/04/2016
f1_keywords:
- C3755
helpviewer_keywords:
- C3755
ms.assetid: 9317b55e-a52e-4b87-b915-5a208d6eda38
ms.openlocfilehash: 0150693ae84b45dc62c11cfdc59369eb25a819cd
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757274"
---
# <a name="compiler-error-c3755"></a>Erro do compilador C3755

' delegate ': um delegado não pode ser definido

Um [delegado (C++ extensões de componente)](../../extensions/delegate-cpp-component-extensions.md) pode ser declarado mas não definido.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3755.

```cpp
// C3755.cpp
// compile with: /clr /c
delegate void MyDel() {};   // C3755
```

## <a name="example"></a>Exemplo

C3755 também pode ocorrer se você tentar criar um modelo de representante. O exemplo a seguir gera C3755.

```cpp
// C3755_b.cpp
// compile with: /clr /c
ref struct R {
   template<class T>
   delegate void D(int) {}   // C3755
};
```
