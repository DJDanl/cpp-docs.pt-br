---
title: 3.1.7 função omp_set_dynamic | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 1fba961b-b82c-4a1e-ab0f-e4be826e50ab
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 807e5739c571f7aa8e9f723a0a48c8c46f1e6d09
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46441558"
---
# <a name="317-ompsetdynamic-function"></a>3.1.7 função omp_set_dynamic

O **omp_set_dynamic** função ativa ou desativa o ajuste dinâmico do número de threads disponíveis para a execução de regiões em paralelo. O formato é o seguinte:

```
#include <omp.h>
void omp_set_dynamic(int dynamic_threads);
```

Se *dynamic_threads* é avaliada como um valor diferente de zero, o número de threads que são usados para a execução de regiões em paralelo subsequente pode ser ajustado automaticamente pelo ambiente de tempo de execução melhor usar recursos do sistema. Como consequência, o número de threads especificado pelo usuário é a contagem máxima de threads. O número de threads na execução de uma região parallel equipe permanece fixo para a duração da região paralela e é reportado pelo **omp_get_num_threads** função.

Se *dynamic_threads* é avaliada como 0, o ajuste dinâmico está desabilitado.

Essa função tem os efeitos descritos acima, quando chamado a partir de uma parte do programa em que o **omp_in_parallel** função retorna zero. Se ele é chamado de uma parte do programa em que o **omp_in_parallel** função retorna um valor diferente de zero, o comportamento dessa função é indefinido.

Uma chamada para **omp_set_dynamic** tem precedência sobre o **OMP_DYNAMIC** variável de ambiente.

O padrão para o ajuste dinâmico de threads é definido pela implementação. Como resultado, os códigos de usuário que dependem de um número específico de threads para execução correta devem desabilitar explicitamente threads dinâmicos. Implementações não são necessárias para fornecer a capacidade de ajustar dinamicamente o número de threads, mas eles são necessários para fornecer a interface para dar suporte à portabilidade entre todas as plataformas.

## <a name="cross-references"></a>Entre as referências:

- **omp_get_num_threads** , consulte [seção 3.1.2](../../parallel/openmp/3-1-2-omp-get-num-threads-function.md) na página 37.

- **OMP_DYNAMIC** consulte de variável de ambiente [seção 4.3](../../parallel/openmp/4-3-omp-dynamic.md) na página 49.

- **omp_in_parallel** , consulte [seção 3.1.6](../../parallel/openmp/3-1-6-omp-in-parallel-function.md) na página de 38.