---
title: Aviso do compilador (nível 3) C4580
ms.date: 11/04/2016
f1_keywords:
- C4580
helpviewer_keywords:
- C4580
ms.assetid: fef6e8e0-0d6a-44fa-b22a-2fe7ba2ef379
ms.openlocfilehash: 28d8534dad5fc1b234c180b879ad0645f05cfd65
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80198608"
---
# <a name="compiler-warning-level-3-c4580"></a>Aviso do compilador (nível 3) C4580

[attribute] é preterido; em vez disso, especifique System:: Attribute ou Platform:: Metadata como uma classe base

[[Attribute](../../windows/attributes/attribute.md)] não é mais a sintaxe preferida para a criação de atributos definidos pelo usuário. Para obter mais informações, consulte [atributos definidos pelo usuário](../../extensions/user-defined-attributes-cpp-component-extensions.md). Para código CLR, derive atributos de `System::Attribute`. Para Windows Runtime código, derive os atributos de `Platform::Metadata`.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3454 e mostra como corrigi-lo.

```cpp
// C4580.cpp
// compile with: /W3 /c /clr
[attribute]   // C4580
public ref class Attr {
public:
   int m_t;
};

public ref class Attr2 : System::Attribute {
public:
   int m_t;
};
```
