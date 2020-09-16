---
title: Aviso do compilador (nível 4) C4634
ms.date: 11/04/2016
f1_keywords:
- C4634
helpviewer_keywords:
- C4634
ms.assetid: 3e3496ce-2ac7-43d0-a48a-f514c950e81d
ms.openlocfilehash: 86ac95fbd030ecf35a85eba153a449511ee7a535
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90683878"
---
# <a name="compiler-warning-level-4-c4634"></a>Aviso do compilador (nível 4) C4634

Comentário de documento XML: não pode ser aplicado: motivo

As marcas de documentação XML não podem ser aplicadas a todas as construções de C++.  Por exemplo, você não pode adicionar um comentário de documentação a um namespace ou modelo.

Para obter mais informações, consulte a [documentação XML](../../build/reference/xml-documentation-visual-cpp.md).

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C4634.

```cpp
// C4634.cpp
// compile with: /W4 /doc /c
/// This is a namespace.   // C4634
namespace hello {
   class MyClass  {};
};
```

O exemplo a seguir gera C4634.

```cpp
// C4634_b.cpp
// compile with: /W4 /doc /c
/// This is a template.   // C4634
template <class T>
class MyClass  {};
```
