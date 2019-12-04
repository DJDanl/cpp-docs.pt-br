---
title: Erro do compilador C3163
ms.date: 11/04/2016
f1_keywords:
- C3163
helpviewer_keywords:
- C3163
ms.assetid: 17dcafa3-f416-4e04-a232-f9569218ba75
ms.openlocfilehash: 436fb112758dfdec9997ff7e6dd7ef8f9dcdc66e
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74761771"
---
# <a name="compiler-error-c3163"></a>Erro do compilador C3163

' Construct ': atributos inconsistentes com declaração anterior

Os atributos que são aplicados a uma definição estão em conflito com os atributos que são aplicados a uma declaração.

Uma maneira de resolver o C3163 é eliminar atributos na declaração de encaminhamento. Todos os atributos em uma declaração de encaminhamento devem ser menores que os atributos na definição ou, no máximo, iguais a eles.

Uma possível causa do erro C3163 envolve a linguagem de anotações de código-fonte da Microsoft (SAL). As macros SAL não se expandem, a menos que você compile seu projeto usando o sinalizador **/Analyze** . Um programa que compila corretamente sem/Analyze pode gerar C3163 se você tentar recompilá-lo com a opção/Analyze. Para obter mais informações sobre SAL, consulte [anotações sal](../../c-runtime-library/sal-annotations.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3163.

```cpp
// C3163.cpp
// compile with: /clr /c
using namespace System;

[CLSCompliant(true)] void f();
[CLSCompliant(false)] void f() {}   // C3163
// try the following line instead
// [CLSCompliant(true)] void f() {}
```

## <a name="see-also"></a>Consulte também

[Anotações de SAL](../../c-runtime-library/sal-annotations.md)
