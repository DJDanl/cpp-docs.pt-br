---
title: Variáveis de escopo A.21 com a cláusula privada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 7cdb4a7f-af24-44ac-9d33-e43840bc8f3d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9ad2258da592bb68c5eae9e52e85e63a161a24b5
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="a21---scoping-variables-with-the-private-clause"></a>A.21   Variáveis de escopo com a cláusula private
Os valores de `i` e `j` no exemplo a seguir não estão definidos na saída da região paralela:  
  
```  
int i, j;  
i = 1;  
j = 2;  
#pragma omp parallel private(i) firstprivate(j)  
{  
  i = 3;  
  j = j + 2;  
}  
printf_s("%d %d\n", i, j);  
```  
  
 Para obter mais informações sobre o `private` cláusula, consulte [seção 2.7.2.1](../../parallel/openmp/2-7-2-1-private.md) na página 25.