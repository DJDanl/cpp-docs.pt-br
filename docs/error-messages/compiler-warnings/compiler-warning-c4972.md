---
title: Aviso do compilador C4972
ms.date: 11/04/2016
f1_keywords:
- C4972
helpviewer_keywords:
- C4972
ms.assetid: d18e8e65-b2ef-4d75-a207-fbd0c17c9060
ms.openlocfilehash: 785d845c3dce556c4d3182ddec07a42a666154f0
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73626331"
---
# <a name="compiler-warning-c4972"></a>Aviso do compilador C4972

Modificar diretamente ou tratar o resultado de uma operação unbox como um lvalue não é verificável

Desreferenciar um identificador para um tipo de valor, também conhecido como unboxing, e depois atribuir a ele não é verificável.

Para obter mais informações, consulte [Boxing](../../extensions/boxing-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4972.

```cpp
// C4972.cpp
// compile with: /clr:safe
using namespace System;
ref struct R {
   int ^ p;   // a value type
};

int main() {
   R ^ r = gcnew R;
   *(r->p) = 10;   // C4972

   // OK
   r->p = 10;
   Console::WriteLine( r->p );
   Console::WriteLine( *(r->p) );
}
```