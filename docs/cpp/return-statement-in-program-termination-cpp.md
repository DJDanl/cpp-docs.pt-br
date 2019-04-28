---
title: Instrução return no término do programa (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- data types [C++], function return types
- function return types [C++], return statement
- return keyword [C++], syntax
ms.assetid: 66d002ab-5625-4b68-8446-71e1b8fcdbd8
ms.openlocfilehash: 9c7b6130ee1a0b49ab75a70d84764d3a1f8c5ef0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62267605"
---
# <a name="return-statement-in-program-termination-c"></a>Instrução return no término do programa (C++)

Emitir uma **retornar** instrução from `main` é funcionalmente equivalente a chamar o `exit` função. Considere o exemplo a seguir:

```cpp
// return_statement.cpp
#include <stdlib.h>
int main()
{
    exit( 3 );
    return 3;
}
```

O `exit` e **retornar** instruções no exemplo anterior são funcionalmente idênticas. No entanto, o C++ requer que funções que têm tipos de retorno diferente de **void** retornam um valor. O **retornar** instrução permite que você retorne um valor de `main`.

## <a name="see-also"></a>Consulte também

[Término do programa](../cpp/program-termination.md)