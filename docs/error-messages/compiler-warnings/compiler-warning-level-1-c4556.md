---
title: Compilador aviso (nível 1) C4556
ms.date: 08/27/2018
f1_keywords:
- xml
- C4556
helpviewer_keywords:
- C4556
ms.assetid: e4c0e296-b747-4db1-9608-30b8b74feac2
ms.openlocfilehash: 53261b97249340ce56ce6ae0f5cc0eab7e97a107
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50538483"
---
# <a name="compiler-warning-level-1-c4556"></a>Compilador aviso (nível 1) C4556

> valor do argumento imediato intrínseco '*valor*'está fora do intervalo'*lowerbound* - *máximo*'

## <a name="remarks"></a>Comentários

Um intrínseco corresponde a uma instrução de hardware. A instrução de hardware tem um número fixo de bits para codificar a constante. Se *valor* está fora do intervalo, ele será não codificar corretamente. O compilador trunca os bits extras.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4556:

```cpp
// C4556.cpp
// compile with: /W1
// processor: x86 IPF
#include <xmmintrin.h>

void test()
{
   __m64 m;
   _m_pextrw(m, 5);   // C4556
}

int main()
{
}
```