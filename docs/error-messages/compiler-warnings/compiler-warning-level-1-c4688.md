---
title: Compilador aviso (nível 1) C4688
ms.date: 11/04/2016
f1_keywords:
- C4688
helpviewer_keywords:
- C4688
ms.assetid: a027df3c-b2b8-4c49-8539-c2bc42db74e8
ms.openlocfilehash: f37b5ed43d375c5ee31eb233ce49f7ec88200155
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50559920"
---
# <a name="compiler-warning-level-1-c4688"></a>Compilador aviso (nível 1) C4688

'restrição de ': lista de restrições contém tipo private de assembly 'type'

Uma lista de restrição tem um tipo private de assembly, que significa que ele não estará disponível quando o tipo é acessado de fora do assembly. Para obter mais informações, consulte [Genéricos](../../windows/generics-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4688.

```
// C4688.cpp
// compile with: /clr /c /W1
ref struct A {};   // private type
public ref struct B {};

// Delete the following 3 lines to resolve.
generic <class T>
where T : A   // C4688
public ref struct M {};

generic <class T>
where T : B
public ref struct N {};
```