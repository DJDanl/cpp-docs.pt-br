---
title: 2.6.6 Constructo ordered
ms.date: 11/04/2016
ms.assetid: 5b3c1ba5-cfb8-4b05-865b-f446ae1c9f7c
ms.openlocfilehash: fe6ad4adf2a4fcccfefe3c3585d9c88c0a118931
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50615794"
---
# <a name="266-ordered-construct"></a>2.6.6 Constructo ordered

O seguinte bloco estruturado uma **ordenados** diretiva é executada na ordem em que iterações seriam executadas em um loop sequencial. A sintaxe do **ordenados** diretiva é da seguinte maneira:

```
#pragma omp ordered new-linestructured-block
```

Uma **ordenados** diretiva deve estar dentro da extensão dinâmica de uma **para** ou **paralela para** construir. O **para** ou **paralela para** diretiva para o qual o **ordenados** associa constructo deve ter uma **ordenados** cláusula especificada conforme descrito em [Seção 2.4.1](../../parallel/openmp/2-4-1-for-construct.md) na página de 11. Na execução de um **para** ou **paralela para** construir com um **ordenados** cláusula, **ordenados** construções são executadas de forma estritamente no ordem em que eles fossem executados em uma execução sequencial do loop.

Restrições para o **ordenados** diretiva são da seguinte maneira:

- Uma iteração de um loop com um **para** constructo não deve executar a mesma diretiva ordenada mais de uma vez e não devem executar mais de uma **ordenados** diretiva.