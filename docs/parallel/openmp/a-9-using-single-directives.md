---
title: A.9   Usando diretivas single
ms.date: 11/04/2016
ms.assetid: 0c0f9495-5794-4db9-883b-a12e3a9f1328
ms.openlocfilehash: 51a2a3438ae5abc9d24c160a986c8ea04b77c4bf
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50501280"
---
# <a name="a9---using-single-directives"></a>A.9   Usando diretivas single

O exemplo a seguir demonstra a `single` diretiva ([seção 2.4.3](../../parallel/openmp/2-4-3-single-construct.md) na página 15). No exemplo, apenas um thread (normalmente, o primeiro thread que encontra o `single` diretiva) imprime a mensagem de progresso. O usuário não deve fazer suposições para qual thread executará o `single` seção. Todos os outros segmentos ignorará a `single` seção e parar na barreira no final do `single` construir. Se outros threads podem prosseguir sem aguardar o thread em execução a `single` seção, uma `nowait` cláusula pode ser especificada no `single` diretiva.

```
#pragma omp parallel
{
    #pragma omp single
        printf_s("Beginning work1.\n");
    work1();
    #pragma omp single
        printf_s("Finishing work1.\n");
    #pragma omp single nowait
        printf_s("Finished work1 and beginning work2.\n");
    work2();
}
```