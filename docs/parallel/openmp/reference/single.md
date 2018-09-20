---
title: único | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- Single
dev_langs:
- C++
helpviewer_keywords:
- single OpenMP directive
ms.assetid: 85cf94fb-cb9c-4d82-8609-adffa9f552e1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2fadd4f9789dc834c1bae0477c828892fed94b5c
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46413361"
---
# <a name="single"></a>single

Permite que você especifique que uma seção de código deve ser executada em um único thread, não necessariamente o thread mestre.

## <a name="syntax"></a>Sintaxe

```
#pragma omp single [clauses] 
{
   code_block
}
```

#### <a name="parameters"></a>Parâmetros

*Cláusula*<br/>
(Opcional) Zero ou mais cláusulas. Consulte a seção comentários para obter uma lista das cláusulas com suporte pelo **único**.

## <a name="remarks"></a>Comentários

O **único** diretiva suporta as seguintes cláusulas OpenMP:

- [copyprivate](../../../parallel/openmp/reference/copyprivate.md)

- [firstprivate](../../../parallel/openmp/reference/firstprivate.md)

- [nowait](../../../parallel/openmp/reference/nowait.md)

- [private](../../../parallel/openmp/reference/private-openmp.md)

O [mestre](../../../parallel/openmp/reference/master.md) diretiva permite que você especifique que uma seção de código deve ser executada somente no thread mestre.

Para obter mais informações, consulte [2.4.3 único construir](../../../parallel/openmp/2-4-3-single-construct.md).

## <a name="example"></a>Exemplo

```cpp
// omp_single.cpp
// compile with: /openmp
#include <stdio.h>
#include <omp.h>

int main() {
   #pragma omp parallel num_threads(2)
   {
      #pragma omp single
      // Only a single thread can read the input.
      printf_s("read input\n");

      // Multiple threads in the team compute the results.
      printf_s("compute results\n");

      #pragma omp single
      // Only a single thread can write the output.
      printf_s("write output\n");
    }
}
```

```Output
read input
compute results
compute results
write output
```

## <a name="see-also"></a>Consulte também

[Diretivas](../../../parallel/openmp/reference/openmp-directives.md)