---
title: Erro do compilador C3896
ms.date: 11/04/2016
f1_keywords:
- C3896
helpviewer_keywords:
- C3896
ms.assetid: eb8be0f6-5b4e-4d71-8285-8a2a94f8ba29
ms.openlocfilehash: f15cd73465f4210ed5e5e34bebe2122c0b88f722
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74749263"
---
# <a name="compiler-error-c3896"></a>Erro do compilador C3896

' member ': inicializador inadequado: Este membro de dados literal só pode ser inicializado com ' nullptr '

Um membro de dados [literal](../../extensions/literal-cpp-component-extensions.md) foi inicializado incorretamente.  Consulte [nullptr](../../extensions/nullptr-cpp-component-extensions.md) para obter mais informações.

O exemplo a seguir gera C3896:

```cpp
// C3896.cpp
// compile with: /clr /c
ref class R{};

value class V {
   literal R ^ r = "test";   // C3896
   literal R ^ r2 = nullptr;   // OK
};
```
