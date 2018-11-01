---
title: A.6   Usando a cláusula lastprivate
ms.date: 11/04/2016
ms.assetid: cf3bf0cc-aa46-4e44-9433-e2969e3be2c1
ms.openlocfilehash: 7d5ba1413827590b7fb3afa0847b9aa1da3c41e1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50579797"
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