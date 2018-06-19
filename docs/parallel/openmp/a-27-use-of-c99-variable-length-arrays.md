---
title: Use A.27 de matrizes de comprimento variável de C99 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 8e542701-39f9-4f28-ab3a-840e8e669723
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 96391aa7403a54160cb6ab83b9b28c1527a3e353
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33690085"
---
# <a name="a27---use-of-c99-variable-length-arrays"></a>A.27   Uso de C99 matrizes de comprimento variável
O exemplo a seguir demonstra como usar matrizes de comprimento variável de C99 (VLAs) em um `firstprivate` diretiva ([seção 2.7.2.2](../../parallel/openmp/2-7-2-2-firstprivate.md) na página 26).  
  
> [!NOTE]
>  Matrizes de comprimento variável atualmente não têm suporte no Visual C++.  
  
```  
void f(int m, int C[m][m])  
{  
    double v1[m];  
    ...  
    #pragma omp parallel firstprivate(C, v1)  
    ...  
}  
```