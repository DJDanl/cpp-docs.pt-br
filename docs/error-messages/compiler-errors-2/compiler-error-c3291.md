---
title: Erro do compilador C3291
ms.date: 11/04/2016
f1_keywords:
- C3291
helpviewer_keywords:
- C3291
ms.assetid: ed2e9f89-8dbc-4387-bc26-cc955e840858
ms.openlocfilehash: 4e8bc312bc10fb5ddc82d811f686004f08603d06
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228863"
---
# <a name="compiler-error-c3291"></a>Erro do compilador C3291

' default ': não pode ser o nome de uma propriedade trivial

Uma propriedade trivial não pode ser nomeada **`default`** . Consulte a [Propriedade](../../extensions/property-cpp-component-extensions.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3291.

```cpp
// C3291.cpp
// compile with: /clr /c
ref struct C {
   property System::String ^ default;   // C3291
   property System::String ^ Default;   // OK
};
```
