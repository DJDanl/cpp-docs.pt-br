---
title: Erro do compilador C3612
ms.date: 11/04/2016
f1_keywords:
- C3612
helpviewer_keywords:
- C3612
ms.assetid: aa6e3a2b-4afa-481c-98c1-1b6d1f82f869
ms.openlocfilehash: ab18381d3f263e3207662e1667ac5c835983412f
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64344501"
---
# <a name="compiler-error-c3612"></a>Erro do compilador C3612

'type': uma classe selada não pode ser abstrata

Tipos definidos usando `value` são lacradas por padrão, e uma classe é abstrata, a menos que ele implementa todos os métodos de sua base. Uma classe sealed abstract não pode ser uma classe base nem pode ser instanciado.

Para obter mais informações, consulte [Classes e Structs](../../extensions/classes-and-structs-cpp-component-extensions.md).

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