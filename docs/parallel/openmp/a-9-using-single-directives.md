---
title: "A. 9 usando único diretivas | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 0c0f9495-5794-4db9-883b-a12e3a9f1328
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 11d41d62448d41d7a11ef747e65cc6ac47e4bd7f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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