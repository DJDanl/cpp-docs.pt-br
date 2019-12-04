---
title: Erro do compilador C2743
ms.date: 11/04/2016
f1_keywords:
- C2743
helpviewer_keywords:
- C2743
ms.assetid: 644cd444-21d2-471d-a176-f5f52c5a0b73
ms.openlocfilehash: d679ce0df0d43772a6c32aa8e00869ac1a4a082b
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759640"
---
# <a name="compiler-error-c2743"></a>Erro do compilador C2743

' type ': não é possível capturar um tipo nativo com destruidor __clrcall ou construtor de cópia

Um módulo compilado com **/CLR** tentou capturar uma exceção de tipo nativo e onde o destruidor do tipo ou construtor de cópia usa `__clrcall` Convenção de chamada.

Quando compilado com **/CLR**, a manipulação de exceção espera que as funções de membro em um tipo nativo sejam [__cdecl](../../cpp/cdecl.md) e não [__clrcall](../../cpp/clrcall.md). Tipos nativos com funções de membro usando `__clrcall` Convenção de chamada não podem ser capturados em um módulo compilado com **/CLR**.

Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2743.

```cpp
// C2743.cpp
// compile with: /clr
public struct S {
   __clrcall ~S() {}
};

public struct T {
   ~T() {}
};

int main() {
   try {}
   catch(S) {}   // C2743
   // try the following line instead
   // catch(T) {}

   try {}
   catch(S*) {}   // OK
}
```
