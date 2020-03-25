---
title: Aviso do compilador (nível 1) C4382
ms.date: 11/04/2016
f1_keywords:
- C4382
helpviewer_keywords:
- C4382
ms.assetid: 34be9ad3-bae6-411a-8f80-0c8fd0d2c092
ms.openlocfilehash: 7b8dbf77defab2a711ad931057c740193908474b
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80186966"
---
# <a name="compiler-warning-level-1-c4382"></a>Aviso do compilador (nível 1) C4382

> lançando '*Type*': um tipo com __clrcall destruidor ou construtor de cópia só pode ser capturado no módulo/CLR: Pure

## <a name="remarks"></a>Comentários

A opção de compilador **/CLR: Pure** foi preterida no visual Studio 2015 e não tem suporte no visual Studio 2017.

Quando compilado com **/CLR** (não **/CLR: Pure**), a manipulação de exceção espera que as funções de membro em um tipo nativo sejam [__cdecl](../../cpp/cdecl.md) e não [__clrcall](../../cpp/clrcall.md). Tipos nativos com funções de membro usando `__clrcall` Convenção de chamada não podem ser capturados em um módulo compilado com **/CLR**.

Se a exceção for capturada em um módulo compilado com **/CLR: Pure**, você poderá ignorar esse aviso.

Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4382.

```cpp
// C4382.cpp
// compile with: /clr /W1 /c
struct S {
   __clrcall ~S() {}
};

struct T {
   ~T() {}
};

int main() {
   S s;
   throw s;   // C4382

   S * ps = &s;
   throw ps;   // OK

   T t;
   throw t;   // OK
}
```
