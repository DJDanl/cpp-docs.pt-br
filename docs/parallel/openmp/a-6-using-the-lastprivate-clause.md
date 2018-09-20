---
title: A.6 usando a cláusula lastprivate | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: cf3bf0cc-aa46-4e44-9433-e2969e3be2c1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 03d18d3aaf5c5d1cbe03282710ae4f4e2bb613f3
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46390572"
---
# <a name="a6---using-the-lastprivate-clause"></a>A.6   Usando a cláusula lastprivate

Às vezes, a execução correta depende do valor que a última iteração de um loop atribui a uma variável. Esses programas devem listar todas as variáveis como argumentos para um `lastprivate` cláusula ([seção 2.7.2.3](../../parallel/openmp/2-7-2-3-lastprivate.md) na página 27) para que os valores das variáveis são o mesmo que quando o loop é executado em sequência.

```
#pragma omp parallel
{
   #pragma omp for lastprivate(i)
      for (i=0; i<n-1; i++)
         a[i] = b[i] + b[i+1];
}
a[i]=b[i];
```

No exemplo anterior, o valor de `i` será igual ao final da região paralela `n-1`, como no caso sequencial.