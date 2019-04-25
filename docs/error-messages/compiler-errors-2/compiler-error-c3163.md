---
title: Erro do compilador C3163
ms.date: 11/04/2016
f1_keywords:
- C3163
helpviewer_keywords:
- C3163
ms.assetid: 17dcafa3-f416-4e04-a232-f9569218ba75
ms.openlocfilehash: eda3910c99f4c8ea96568f2d475c5d6a1e4cdc7c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62174211"
---
# <a name="compiler-error-c3163"></a>Erro do compilador C3163

'Criar': atributos inconsistentes com declaração anterior

Os atributos que são aplicados a uma definição em conflito com os atributos que são aplicados a uma declaração.

Uma maneira de resolver C3163 é eliminar atributos na declaração de encaminhamento. Todos os atributos em uma declaração de encaminhamento devem ser menor do que os atributos na definição ou, no máximo, igual a eles.

Uma possível causa do erro C3163 envolve a linguagem de anotação de código do código-fonte Microsoft (SAL). As macros SAL não expanda, a menos que você compila seu projeto usando o **/ANALYZE** sinalizador. Um programa que é compilado corretamente sem /ANALYZE pode lançar C3163 se você tentar recompilá-lo com a opção /Analyze. Para obter mais informações sobre o SAL, consulte [anotações de SAL](../../c-runtime-library/sal-annotations.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3163.

```
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