---
title: Aviso do compilador (nível 1) C4556
ms.date: 08/27/2018
f1_keywords:
- C4556
helpviewer_keywords:
- C4556
ms.assetid: e4c0e296-b747-4db1-9608-30b8b74feac2
ms.openlocfilehash: 501d79a8a86fcd3e2d8ba08dc2f03488f9abb827
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80162303"
---
# <a name="compiler-warning-level-1-c4556"></a>Aviso do compilador (nível 1) C4556

> o valor do argumento imediato intrínseco '*Value*' está fora do intervalo '*lowerbound* - *máximo*'

## <a name="remarks"></a>Comentários

Um intrínseco corresponde a uma instrução de hardware. A instrução de hardware tem um número fixo de bits para codificar a constante. Se o *valor* estiver fora do intervalo, ele não será codificado corretamente. O compilador trunca os bits adicionais.

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
