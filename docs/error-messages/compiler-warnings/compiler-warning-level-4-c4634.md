---
title: Compilador aviso (nível 4) C4634
ms.date: 11/04/2016
f1_keywords:
- C4634
helpviewer_keywords:
- C4634
ms.assetid: 3e3496ce-2ac7-43d0-a48a-f514c950e81d
ms.openlocfilehash: 7d0e2af13128a201d96aa905d85621e14441a673
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57818252"
---
# <a name="compiler-warning-level-4-c4634"></a>Compilador aviso (nível 4) C4634

Comentário de documento XML: não pode ser aplicado: motivo

Marcas de documentação XML não podem ser aplicadas ao C++ todas as construções.  Por exemplo, você não pode adicionar um comentário de documentação para um namespace ou o modelo.

Para obter mais informações, consulte [documentação XML](../../build/reference/xml-documentation-visual-cpp.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4634.

```
// C4634.cpp
// compile with: /W4 /doc /c
/// This is a namespace.   // C4634
namespace hello {
   class MyClass  {};
};
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4634.

```
// C4634_b.cpp
// compile with: /W4 /doc /c
/// This is a template.   // C4634
template <class T>
class MyClass  {};
```