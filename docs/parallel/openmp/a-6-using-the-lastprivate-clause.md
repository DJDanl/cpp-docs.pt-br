---
title: "A.6 usando a cláusula lastprivate | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: cf3bf0cc-aa46-4e44-9433-e2969e3be2c1
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1744787e1dfb90fa9af93db5dba4eecd600b4334
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="a6---using-the-lastprivate-clause"></a>A.6   Usando a cláusula lastprivate
Execução correta, às vezes, dependendo do valor que a última iteração de um loop atribui a uma variável. Esses programas devem listar todas as variáveis como argumentos para um `lastprivate` cláusula ([seção 2.7.2.3](../../parallel/openmp/2-7-2-3-lastprivate.md) na página 27) para que os valores das variáveis são os mesmos quando o loop é executado em sequência.  
  
```  
#pragma omp parallel  
{  
   #pragma omp for lastprivate(i)  
      for (i=0; i<n-1; i++)  
         a[i] = b[i] + b[i+1];  
}  
a[i]=b[i];  
```  
  
 No exemplo anterior, o valor de `i` será igual ao final da região parallel `n-1`, como no caso de sequencial.