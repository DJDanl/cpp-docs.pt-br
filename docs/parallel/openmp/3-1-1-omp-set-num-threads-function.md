---
title: 3.1.1 função omp_set_num_threads | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: b94cf2b5-8011-4a3b-ba56-676982642857
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 85f7ff733583e531b449caf2039817b71165da52
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46426790"
---
# <a name="311-ompsetnumthreads-function"></a>3.1.1 função omp_set_num_threads

O `omp_set_num_threads` função define o número padrão de threads a serem usados para regiões em paralelo subsequente que não especificam um `num_threads` cláusula. O formato é o seguinte:

```
#include <omp.h>
void omp_set_num_threads(int num_threads);
```

O valor do parâmetro *num_threads* deve ser um inteiro positivo. Seu efeito depende se o ajuste dinâmico do número de threads está habilitado. Para um conjunto abrangente de regras sobre a interação entre o `omp_set_num_threads` função e o ajuste dinâmico de threads, consulte a seção 2.3 na página de 8.

Essa função tem os efeitos descritos acima, quando chamado a partir de uma parte do programa em que o `omp_in_parallel` função retorna zero. Se ele é chamado de uma parte do programa em que o `omp_in_parallel` função retorna um valor diferente de zero, o comportamento dessa função é indefinido.

Essa chamada tem precedência sobre o `OMP_NUM_THREADS` variável de ambiente. O valor padrão para o número de threads, o que pode ser estabelecida chamando `omp_set_num_threads` ou definindo o `OMP_NUM_THREADS` variável de ambiente podem ser substituídos explicitamente em uma única **paralela** diretiva especificando o `num_threads` cláusula.

## <a name="cross-references"></a>Entre as referências:

- `omp_set_dynamic` função, consulte [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.

- `omp_get_dynamic` função, consulte [seção 3.1.8](../../parallel/openmp/3-1-8-omp-get-dynamic-function.md) na página de 40.

- `OMP_NUM_THREADS` Consulte de variável de ambiente [4.2 seção](../../parallel/openmp/4-2-omp-num-threads.md) página 48, e a seção 2.3 na página de 8.

- `num_threads` cláusula, consulte [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página 8