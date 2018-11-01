---
title: A.8   Especificando seções em paralelo
ms.date: 11/04/2016
ms.assetid: cf399304-121e-4c07-9829-47e0dbc2ef10
ms.openlocfilehash: 81eaed920e77b23052ac58c2d0e18fee83c00565
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50461432"
---
# <a name="a8---specifying-parallel-sections"></a>A.8   Especificando seções em paralelo

No exemplo a seguir (para [seção 2.4.2](../../parallel/openmp/2-4-2-sections-construct.md) na página 14) funções *numérica de xaxis*, *yaxis*, e *zaxis* podem ser executadas simultaneamente. A primeira `section` diretiva é opcional.  Observe que todos os `section` diretivas precisam aparecer na extensão de léxico o `parallel sections` construir.

```
#pragma omp parallel sections
{
    #pragma omp section
        xaxis();
    #pragma omp section
        yaxis();
    #pragma omp section
        zaxis();
}
```