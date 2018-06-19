---
title: A. 9 usando único diretivas | Microsoft Docs
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
ms.openlocfilehash: bc0e0e08b0b7bdea05bf4c627ae33cc42298c6dc
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33690375"
---
# <a name="a9---using-single-directives"></a>A.9   Usando diretivas single
O exemplo a seguir demonstra o `single` diretiva ([seção 2.4.3](../../parallel/openmp/2-4-3-single-construct.md) na página 15). No exemplo, apenas um thread (normalmente o primeiro thread que encontra o `single` diretiva) imprime a mensagem de progresso. O usuário não deve fazer suposições de segmento que executará o `single` seção. Todos os outros segmentos ignorará o `single` seção e parar a barreira no final do `single` construir. Se outros threads podem prosseguir sem aguardar a execução do thread de `single` seção, uma `nowait` cláusula pode ser especificada no `single` diretiva.  
  
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