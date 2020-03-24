---
title: Aviso do compilador (nível 1) C4683
ms.date: 08/27/2018
f1_keywords:
- C4683
helpviewer_keywords:
- C4683
ms.assetid: e6e77364-dba1-46dd-ae1d-03da23070bce
ms.openlocfilehash: f86cf8f6d894d6efaa1b49977634956dc1979a98
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80175423"
---
# <a name="compiler-warning-level-1-c4683"></a>Aviso do compilador (nível 1) C4683

> '*Function*': a origem do evento tem um parâmetro ' parâmetro '; tenha cuidado ao conectar vários manipuladores de eventos

## <a name="remarks"></a>Comentários

Se mais de um coletor de eventos estiver ouvindo uma origem de evento COM, o valor de um parâmetro out poderá ser ignorado.

Lembre-se de que um vazamento de memória ocorrerá nas seguintes situações:

1. Se um método tiver um parâmetro out alocado internamente, por exemplo, um BSTR *.

2. Se o evento tiver mais de um manipulador (é um evento de multicast).

O motivo do vazamento é que o parâmetro out será definido por mais de um manipulador, mas retornado para o site de chamada somente pelo último manipulador.

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
