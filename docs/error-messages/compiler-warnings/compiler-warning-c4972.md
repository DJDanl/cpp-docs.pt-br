---
title: Aviso do compilador C4972
ms.date: 11/04/2016
f1_keywords:
- C4972
helpviewer_keywords:
- C4972
ms.assetid: d18e8e65-b2ef-4d75-a207-fbd0c17c9060
ms.openlocfilehash: dcf08f26809c7c61e3e00c41c555416c95f4a0e0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50598825"
---
# <a name="compiler-warning-c4972"></a>Aviso do compilador C4972

Modificar diretamente ou tratar o resultado de uma operação de unbox como um lvalue não é verificável

Não é verificável desreferenciar um identificador para um tipo de valor, também conhecido como conversão unboxing e, em seguida, atribuí-lo.

Para obter mais informações, consulte [Boxing](../../windows/boxing-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4972.

```
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