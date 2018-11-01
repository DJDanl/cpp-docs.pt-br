---
title: Compilador aviso (nível 1) C4683
ms.date: 08/27/2018
f1_keywords:
- C4683
helpviewer_keywords:
- C4683
ms.assetid: e6e77364-dba1-46dd-ae1d-03da23070bce
ms.openlocfilehash: 264753ece6cbabded21df8e6b9dbb463f811e8a2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50598923"
---
# <a name="compiler-warning-level-1-c4683"></a>Compilador aviso (nível 1) C4683

> '*função*': origem do evento tem um 'out'-parâmetro; tome cuidado ao capturar vários manipuladores de eventos

## <a name="remarks"></a>Comentários

Se mais de um coletor de eventos é escutando uma origem de evento COM, o valor de um parâmetro de saída pode ser ignorado.

Lembre-se de que um vazamento de memória ocorrerá nas seguintes situações:

1. Se um método tem um parâmetro de saída que é internamente alocada, por exemplo um BSTR *.

2. Se o evento tiver mais de um manipulador (é um evento multicast).

O motivo para a perda é que o parâmetro de saída será definido por mais de um manipulador, mas retornado para o site de chamada somente pelo último manipulador.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4683 e mostra como corrigi-lo:

```cpp
// C4683.cpp
// compile with: /W1 /LD
#define _ATL_ATTRIBUTES 1
#include "atlbase.h"
#include "atlcom.h"

[ module(name="xx") ];

[ object ]
__interface I {
   HRESULT f([out] int* pi);
   // try the following line instead
   // HRESULT f(int* pi);
};

[ coclass, event_source(com) ]
struct E {
   __event __interface I;   // C4683
};
```