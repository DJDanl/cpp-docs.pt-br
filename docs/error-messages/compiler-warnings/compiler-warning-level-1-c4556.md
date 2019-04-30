---
title: Compilador aviso (nível 1) C4556
ms.date: 08/27/2018
f1_keywords:
- C4556
helpviewer_keywords:
- C4556
ms.assetid: e4c0e296-b747-4db1-9608-30b8b74feac2
ms.openlocfilehash: c31602766261a8d6d0c4f0bb0a880ee34ee1ed45
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62397309"
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