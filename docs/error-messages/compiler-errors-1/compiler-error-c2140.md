---
title: Erro do compilador C2140
ms.date: 11/04/2016
f1_keywords:
- C2140
helpviewer_keywords:
- C2140
ms.assetid: d44a0500-002c-4632-9e5e-c71c3a473ec4
ms.openlocfilehash: 0329872ff0baee595bf32486a53d6abf91d208d4
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756520"
---
# <a name="compiler-error-c2140"></a>Erro do compilador C2140

' type ': um tipo que é dependente de um parâmetro de tipo genérico não é permitido como um argumento para a característica de tipo intrínseco do compilador ' poformable '

Um especificador de tipo inválido foi passado para uma característica de tipo.

Saiba mais em [Suporte para compilador de traços de tipo](../../extensions/compiler-support-for-type-traits-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2140.

```cpp
// C2140.cpp
// compile with: /clr /c
template <class T>

struct is_polymorphic {
   static const bool value = __is_polymorphic(T);
};

class x {};

generic <class T>
ref class C {
   void f() {
      System::Console::WriteLine(__is_polymorphic(T));   // C2140
      System::Console::WriteLine(is_polymorphic<T>::value);   // C2140

      System::Console::WriteLine(__is_polymorphic(x));   // OK
      System::Console::WriteLine(is_polymorphic<x>::value);   // OK
   }
};
```
