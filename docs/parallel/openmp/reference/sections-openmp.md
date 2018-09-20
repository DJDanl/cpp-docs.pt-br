---
title: seções (OpenMP) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- section
- SECTIONS
dev_langs:
- C++
helpviewer_keywords:
- sections OpenMP directive
ms.assetid: 4cd1d776-e198-470e-930a-01fb0ab0a0bd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 32dab6784e4265432f596b585e098f6a77687117
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46421538"
---
# <a name="sections-openmp"></a>sections (OpenMP)

Identifica as seções de código a ser dividida entre todos os threads.

## <a name="syntax"></a>Sintaxe

```
#pragma omp [parallel] sections [clauses]
{
   #pragma omp section
   {
      code_block
   } 
}
```

## <a name="arguments"></a>Arguments

*Cláusula*<br/>
(Opcional) Zero ou mais cláusulas. Consulte a seção comentários para obter uma lista das cláusulas com suporte pelo **seções**.

## <a name="remarks"></a>Comentários

O **seções** diretiva pode conter zero ou mais **seção** diretivas.

O **seções** diretiva suporta as seguintes cláusulas OpenMP:

- [firstprivate](../../../parallel/openmp/reference/firstprivate.md)

- [lastprivate](../../../parallel/openmp/reference/lastprivate.md)

- [nowait](../../../parallel/openmp/reference/nowait.md)

- [private](../../../parallel/openmp/reference/private-openmp.md)

- [reduction](../../../parallel/openmp/reference/reduction.md)

Se **paralela** também for especificado, `clause` pode ser qualquer cláusula aceitos pela **paralela** ou **seções** diretivas, exceto `nowait`.

Para obter mais informações, consulte [2.4.2 constructo sections](../../../parallel/openmp/2-4-2-sections-construct.md).

## <a name="example"></a>Exemplo

```
// omp_sections.cpp
// compile with: /openmp
#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel sections num_threads(4)
    {
        printf_s("Hello from thread %d\n", omp_get_thread_num());
        #pragma omp section
        printf_s("Hello from thread %d\n", omp_get_thread_num());
    }
}
```

```Output
Hello from thread 0
Hello from thread 0
```

## <a name="see-also"></a>Consulte também

[Diretivas](../../../parallel/openmp/reference/openmp-directives.md)