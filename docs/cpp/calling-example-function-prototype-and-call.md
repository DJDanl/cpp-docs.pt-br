---
title: 'Exemplo de chamada: protótipo de função e chamada'
ms.date: 11/04/2016
helpviewer_keywords:
- calling conventions, examples [C++]
- examples [C++], calling conventions
ms.assetid: e4275d1f-df2e-4bfc-a162-eb43ec69554a
ms.openlocfilehash: c41d7679be8b7faa3c8df1368d14815a1b840284
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80190164"
---
# <a name="calling-example-function-prototype-and-call"></a>Exemplo de chamada: protótipo de função e chamada

**Seção específica da Microsoft**

O exemplo a seguir mostra os resultados de fazer uma chamada de função usando várias convenções de chamada.

Este exemplo é baseado no seguinte esqueleto da função. Substituir `calltype` com a convenção de chamada apropriada.

```cpp
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

## <a name="see-also"></a>Confira também

[Convenções de chamada](../cpp/calling-conventions.md)
