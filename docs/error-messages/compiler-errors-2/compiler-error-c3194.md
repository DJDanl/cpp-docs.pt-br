---
title: Erro do compilador C3194
ms.date: 11/04/2016
f1_keywords:
- C3194
helpviewer_keywords:
- C3194
ms.assetid: 49d3ffc6-eff6-4b46-865b-18811692a8bb
ms.openlocfilehash: 83c07da5383740ca14c9b9de6224f47cf844d5fa
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757638"
---
# <a name="compiler-error-c3194"></a>Erro do compilador C3194

' member ': um tipo de valor não pode ter um operador de atribuição

Funções de membro especiais que exigem invocação automática pelo compilador, como um construtor de cópia ou operador de atribuição de cópia, não têm suporte em uma classe de valor.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3194.

```cpp
// C3194.cpp
// compile with: /clr /c
value struct MyStruct {
   MyStruct& operator= (const MyStruct& i) { return *this; }   // C3194
};

ref struct MyStruct2 {
   MyStruct2% operator= (const MyStruct2% i) { return *this; }   // OK
};
```
