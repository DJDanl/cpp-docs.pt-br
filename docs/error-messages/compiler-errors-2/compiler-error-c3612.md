---
title: Erro do compilador C3612
ms.date: 11/04/2016
f1_keywords:
- C3612
helpviewer_keywords:
- C3612
ms.assetid: aa6e3a2b-4afa-481c-98c1-1b6d1f82f869
ms.openlocfilehash: a6084632ac0a84cc058ea73eb3c2b632208792eb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50475927"
---
# <a name="compiler-error-c3612"></a>Erro do compilador C3612

'type': uma classe selada não pode ser abstrata

Tipos definidos usando `value` são lacradas por padrão, e uma classe é abstrata, a menos que ele implementa todos os métodos de sua base. Uma classe sealed abstract não pode ser uma classe base nem pode ser instanciado.

Para obter mais informações, consulte [Classes e Structs](../../windows/classes-and-structs-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3612:

```
// C3612.cpp
// compile with: /clr /c
value struct V: public System::ICloneable {};   // C3612

// OK
value struct V2: public System::ICloneable {
   Object^ Clone();
};
```