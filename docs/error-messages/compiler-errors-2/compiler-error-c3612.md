---
title: Erro do compilador C3612
ms.date: 11/04/2016
f1_keywords:
- C3612
helpviewer_keywords:
- C3612
ms.assetid: aa6e3a2b-4afa-481c-98c1-1b6d1f82f869
ms.openlocfilehash: 499c31b0c02bd72695cd6118612609a70316f0ae
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74755740"
---
# <a name="compiler-error-c3612"></a>Erro do compilador C3612

' type ': uma classe sealed não pode ser abstract

Os tipos definidos usando `value` são lacrados por padrão, e uma classe é abstrata, a menos que ele implemente todos os métodos de sua base. Uma classe sealed abstract não pode ser uma classe base nem pode ser instanciada.

Para obter mais informações, confira [Classes e structs](../../extensions/classes-and-structs-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3612:

```cpp
// C3612.cpp
// compile with: /clr /c
value struct V: public System::ICloneable {};   // C3612

// OK
value struct V2: public System::ICloneable {
   Object^ Clone();
};
```
