---
title: Compilador aviso (nível 1) C4382
ms.date: 11/04/2016
f1_keywords:
- C4382
helpviewer_keywords:
- C4382
ms.assetid: 34be9ad3-bae6-411a-8f80-0c8fd0d2c092
ms.openlocfilehash: cca2f8cc13cc8317bac3736e142ef58e126ed994
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50629210"
---
# <a name="compiler-warning-level-1-c4382"></a>Compilador aviso (nível 1) C4382

> Lançando '*tipo*': um tipo com clrcall destruidor ou Construtor de cópia só pode ser capturado em /clr: pure módulo

## <a name="remarks"></a>Comentários

O **/clr: pure** opção do compilador é preterida no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Quando compilado com **/clr** (não **/clr: pure**), tratamento de exceção espera que as funções de membro em um tipo nativo seja [cdecl](../../cpp/cdecl.md) e não [clrcall](../../cpp/clrcall.md). Tipos nativos com funções de membro usando `__clrcall` convenção de chamada não pode ser capturada em um módulo compilado com **/clr**.

Se a exceção será capturada em um módulo compilado com **/clr: pure**, você pode ignorar este aviso.

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