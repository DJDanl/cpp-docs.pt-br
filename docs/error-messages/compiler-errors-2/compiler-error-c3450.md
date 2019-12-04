---
title: Erro do compilador C3450
ms.date: 11/04/2016
f1_keywords:
- C3450
helpviewer_keywords:
- C3450
ms.assetid: 78892cf7-0b82-4589-90d0-e06666247003
ms.openlocfilehash: 7b57b67e8f4542266818ad5b3d90d78a1a943d55
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756221"
---
# <a name="compiler-error-c3450"></a>Erro do compilador C3450

' type ': não é um atributo; Não é possível especificar [System:: AttributeUsageAttribute] ou [Windows:: Foundation:: Metadata:: AttributeUsageAttribute]

Um atributo gerenciado definido pelo usuário deve herdar de <xref:System.ComponentModel.AttributeCollection.%23ctor%2A>. Um atributo de Windows Runtime deve ser definido no namespace `Windows::Foundation::Metadata`.

Para obter mais informações, consulte [atributos definidos pelo usuário](../../extensions/user-defined-attributes-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3450 e mostra como corrigi-lo.

```cpp
// C3450.cpp
// compile with: /clr
// C3450 expected
using namespace System;
using namespace System::Security;
using namespace System::Security::Permissions;

public ref class MyClass {};

class MyClass2 {};

[attribute(AttributeTargets::All)]
ref struct AtClass {
   AtClass(Type ^) {}
};

[attribute(AttributeTargets::All)]
ref struct AtClass2 {
   AtClass2() {}
};

// Apply the AtClass and AtClass2 attributes to class B
[AtClass(MyClass::typeid), AtClass2]
[AttributeUsage(AttributeTargets::All)]
// Delete the following line to resolve.
ref class B {};
// Uncomment the following line to resolve.
// ref class B : Attribute {};
```
