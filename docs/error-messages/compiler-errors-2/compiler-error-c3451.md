---
title: Erro do compilador C3451
ms.date: 11/04/2016
f1_keywords:
- C3451
helpviewer_keywords:
- C3451
ms.assetid: a4897a69-e3e7-40bb-bb1c-598644904012
ms.openlocfilehash: 2e0122dd53ba5318077dd33f22a07492c52db26b
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756208"
---
# <a name="compiler-error-c3451"></a>Erro do compilador C3451

' attribute ': não é possível aplicar atributo não gerenciado a ' type '

Um C++ atributo não pode ser aplicado a um tipo CLR. Consulte [ C++ referência de atributos](../../windows/attributes/attributes-alphabetical-reference.md) para obter mais informações.

Para obter mais informações, consulte [atributos definidos pelo usuário](../../extensions/user-defined-attributes-cpp-component-extensions.md).

Esse erro pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio 2005: o atributo [UUID](../../windows/uuid-cpp-attributes.md) não é mais permitido em um atributo definido pelo usuário usando a programação CLR. Use <xref:System.Runtime.InteropServices.GuidAttribute> em seu lugar.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3451.

```cpp
// C3451.cpp
// compile with: /clr /c
using namespace System;
[ attribute(AttributeTargets::All) ]
public ref struct MyAttr {};

[ MyAttr, helpstring("test") ]   // C3451
// try the following line instead
// [ MyAttr ]
public ref struct ABC {};
```
