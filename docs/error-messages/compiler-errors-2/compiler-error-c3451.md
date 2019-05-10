---
title: Erro do compilador C3451
ms.date: 11/04/2016
f1_keywords:
- C3451
helpviewer_keywords:
- C3451
ms.assetid: a4897a69-e3e7-40bb-bb1c-598644904012
ms.openlocfilehash: 07cfda76af26ddb285be4f77131aaf48a20a761f
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65447847"
---
# <a name="compiler-error-c3451"></a>Erro do compilador C3451

'attribute': não é possível aplicar o atributo não gerenciado para 'type'

Um atributo de C++ não pode ser aplicado a um tipo CLR. Ver [referência de atributos C++](../../windows/attributes/attributes-alphabetical-reference.md) para obter mais informações.

Para obter mais informações, consulte [atributos definidos pelo usuário](../../extensions/user-defined-attributes-cpp-component-extensions.md).

Esse erro pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio 2005: o [uuid](../../windows/uuid-cpp-attributes.md) atributo não é permitido em um atributo definido pelo usuário usando a programação de CLR. Use <xref:System.Runtime.InteropServices.GuidAttribute> em seu lugar.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3451.

```
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