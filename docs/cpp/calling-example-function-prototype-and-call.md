---
title: 'Exemplo de chamada: Protótipo de função e chamada | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- calling conventions, examples [C++]
- examples [C++], calling conventions
ms.assetid: e4275d1f-df2e-4bfc-a162-eb43ec69554a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 04e681560854be4c93b1c93786d38771c07244ea
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46099571"
---
# <a name="calling-example-function-prototype-and-call"></a>Exemplo de chamada: protótipo de função e chamada

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