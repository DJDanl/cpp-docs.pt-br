---
title: 4.2 OMP_NUM_THREADS | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 49dd55dd-25d5-4a5a-a998-cc7f47b2dae2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9996a09661d962eb5e936fdb484c9dd534e46904
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46445185"
---
# <a name="42-ompnumthreads"></a>4.2 OMP_NUM_THREADS

O **OMP_NUM_THREADS** variável de ambiente define o número padrão de threads a serem usados durante a execução, a menos que esse número seja explicitamente alterado por meio da chamada a **omp_set_num_threads** rotina de biblioteca ou por um explícito **num_threads** cláusula em uma **paralela** diretiva.

O valor de **OMP_NUM_THREADS** variável de ambiente deve ser um inteiro positivo. Seu efeito depende se o ajuste dinâmico do número de threads está habilitado. Para um conjunto abrangente de regras sobre a interação entre o **OMP_NUM_THREADS** ambiente ajuste dinâmico e variável de threads, consulte a seção 2.3 na página de 8.

Se nenhum valor for especificado para o **OMP_NUM_THREADS** variável de ambiente, ou se o valor especificado não é um inteiro positivo, ou se o valor for maior que o número máximo de threads do sistema pode dar suporte, o número de threads a serem usados é definido pela implementação.

Exemplo:

```
setenv OMP_NUM_THREADS 16
```

## <a name="cross-references"></a>Entre as referências:

- **num_threads** cláusula, consulte [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página de 8.

- **omp_set_num_threads** , consulte [seção 3.1.1](../../parallel/openmp/3-1-1-omp-set-num-threads-function.md) na página de 36.

- **omp_set_dynamic** , consulte [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.