---
title: paralelo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- parallel
dev_langs:
- C++
helpviewer_keywords:
- parallel OpenMP directive
ms.assetid: b8e90073-e85b-4d39-8ed8-0364441794fb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 38b5bd4d277987be78cbd3714302c8b7f704b90f
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46405210"
---
# <a name="parallel"></a>parallel

Define uma região paralela, que é um código que será executado por vários threads em paralelo.

## <a name="syntax"></a>Sintaxe

```
#pragma omp parallel [clauses]
{
   code_block
}
```

## <a name="arguments"></a>Arguments

*Cláusula*<br/>
(Opcional) Zero ou mais cláusulas.  Consulte a seção comentários para obter uma lista das cláusulas com suporte pelo **paralela**.

## <a name="remarks"></a>Comentários

O **paralela** diretiva suporta as seguintes cláusulas OpenMP:

- [copyin](../../../parallel/openmp/reference/copyin.md)

- [default](../../../parallel/openmp/reference/default-openmp.md)

- [firstprivate](../../../parallel/openmp/reference/firstprivate.md)

- [if](../../../parallel/openmp/reference/if-openmp.md)

- [num_threads](../../../parallel/openmp/reference/num-threads.md)

- [private](../../../parallel/openmp/reference/private-openmp.md)

- [reduction](../../../parallel/openmp/reference/reduction.md)

- [shared](../../../parallel/openmp/reference/shared-openmp.md)

**Parallel** também pode ser usado com o [seções](../../../parallel/openmp/reference/sections-openmp.md) e [para](../../../parallel/openmp/reference/for-openmp.md) diretivas.

Para obter mais informações, consulte [2.3 construto parallel](../../../parallel/openmp/2-3-parallel-construct.md).

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como definir o número de threads e definir uma região paralela. Por padrão, o número de threads é igual ao número de processadores lógicos no computador. Por exemplo, se você tiver um computador com um processador físico que tem o hyperthreading habilitado, ele terá dois processadores lógicos e, portanto, dois threads.

```
// omp_parallel.cpp
// compile with: /openmp
#include <stdio.h>
#include <omp.h>

int main() {
   #pragma omp parallel num_threads(4)
   {
      int i = omp_get_thread_num();
      printf_s("Hello from thread %d\n", i);
   }
}
```

```Output
Hello from thread 0
Hello from thread 1
Hello from thread 2
Hello from thread 3
```

## <a name="comment"></a>Comentário

Observe que a ordem de saída pode variar em computadores diferentes.

## <a name="see-also"></a>Consulte também

[Diretivas](../../../parallel/openmp/reference/openmp-directives.md)