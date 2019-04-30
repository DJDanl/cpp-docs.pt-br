---
title: 'Exemplo de chamada: Chamada e o protótipo de função'
ms.date: 11/04/2016
helpviewer_keywords:
- calling conventions, examples [C++]
- examples [C++], calling conventions
ms.assetid: e4275d1f-df2e-4bfc-a162-eb43ec69554a
ms.openlocfilehash: f89f4f1917810baa585dd1661428e0809b93cca0
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64345106"
---
# <a name="calling-example-function-prototype-and-call"></a>Exemplo de chamada: Chamada e o protótipo de função

## <a name="microsoft-specific"></a>Específico da Microsoft

O exemplo a seguir mostra os resultados de fazer uma chamada de função usando várias convenções de chamada.

Este exemplo é baseado no seguinte esqueleto da função. Substituir `calltype` com a convenção de chamada apropriada.

```
void    calltype MyFunc( char c, short s, int i, double f );
.
.
.
void    MyFunc( char c, short s, int i, double f )
    {
    .
    .
    .
    }
.
.
.
MyFunc ('x', 12, 8192, 2.7183);
```

Para obter mais informações, consulte [resultados do exemplo de chamada](../cpp/results-of-calling-example.md).

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Convenções de chamada](../cpp/calling-conventions.md)