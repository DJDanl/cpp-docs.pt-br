---
title: Aviso do compilador C4972
ms.date: 11/04/2016
f1_keywords:
- C4972
helpviewer_keywords:
- C4972
ms.assetid: d18e8e65-b2ef-4d75-a207-fbd0c17c9060
ms.openlocfilehash: 7c58258298fb91d04014e719732135a1f33f13b6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62280692"
---
# <a name="compiler-warning-c4972"></a>Aviso do compilador C4972

Modificar diretamente ou tratar o resultado de uma operação de unbox como um lvalue não é verificável

Não é verificável desreferenciar um identificador para um tipo de valor, também conhecido como conversão unboxing e, em seguida, atribuí-lo.

Para obter mais informações, consulte [Boxing](../../extensions/boxing-cpp-component-extensions.md).

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