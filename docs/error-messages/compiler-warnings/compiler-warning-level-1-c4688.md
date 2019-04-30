---
title: Compilador aviso (nível 1) C4688
ms.date: 11/04/2016
f1_keywords:
- C4688
helpviewer_keywords:
- C4688
ms.assetid: a027df3c-b2b8-4c49-8539-c2bc42db74e8
ms.openlocfilehash: 1c94198eca0a88174c8655e0d571c37f82a2df36
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62375087"
---
# <a name="compiler-warning-level-1-c4688"></a>Compilador aviso (nível 1) C4688

'restrição de ': lista de restrições contém tipo private de assembly 'type'

Uma lista de restrição tem um tipo private de assembly, que significa que ele não estará disponível quando o tipo é acessado de fora do assembly. Para obter mais informações, consulte [Genéricos](../../extensions/generics-cpp-component-extensions.md).

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