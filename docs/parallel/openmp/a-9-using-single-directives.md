---
title: A.9 usando diretivas single | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 0c0f9495-5794-4db9-883b-a12e3a9f1328
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5a3a201450d54355aa96f0ea712ad9fa0f70f63f
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46448084"
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