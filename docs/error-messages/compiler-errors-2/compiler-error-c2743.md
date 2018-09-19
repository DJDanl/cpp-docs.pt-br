---
title: Erro do compilador C2743 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2743
dev_langs:
- C++
helpviewer_keywords:
- C2743
ms.assetid: 644cd444-21d2-471d-a176-f5f52c5a0b73
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4217a1e7a8475362c654ac34b6a345846341ec35
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46056477"
---
# <a name="compiler-error-c2743"></a>Erro do compilador C2743

'type': não é possível capturar um tipo nativo com clrcall destruidor ou Construtor de cópia

Um módulo compilado com **/clr** tentou capturar uma exceção de tipo nativo e onde o tipo destruidor ou Construtor de cópia usa `__clrcall` convenção de chamada.

Quando compilado com **/clr**, manipulação de exceção espera que as funções de membro em um tipo nativo seja [cdecl](../../cpp/cdecl.md) e não [clrcall](../../cpp/clrcall.md). Tipos nativos com funções de membro usando `__clrcall` convenção de chamada não pode ser capturada em um módulo compilado com **/clr**.

Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2743.

```
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