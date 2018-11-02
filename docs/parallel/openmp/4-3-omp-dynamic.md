---
title: 4.3 OMP_DYNAMIC
ms.date: 11/04/2016
ms.assetid: a15edefb-1f85-4f06-a427-beb3cfc4434f
ms.openlocfilehash: 0ea6784159a11fc194d0c1cd16d2316a80b9cd37
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50488552"
---
# <a name="43-ompdynamic"></a>4.3 OMP_DYNAMIC

O **OMP_DYNAMIC** variável de ambiente habilita ou desabilita o ajuste dinâmico do número de threads disponíveis para a execução de regiões em paralelo, a menos que o ajuste dinâmico está habilitado ou desabilitado chamando o explicitamente**omp_set_dynamic** rotina da biblioteca. Seu valor deve ser **verdadeira** ou **falso**.

Se definido como **verdadeira**, o número de threads que são usados para a execução de regiões em paralelo pode ser ajustado pelo ambiente de tempo de execução melhor usar recursos do sistema.  Se definido como **falsos**, ajuste dinâmico está desabilitado. A condição padrão é definido pela implementação.

Exemplo:

```
setenv OMP_DYNAMIC TRUE
```

## <a name="cross-references"></a>Entre as referências:

- Para obter mais informações sobre regiões em paralelo, consulte [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página de 8.

- **omp_set_dynamic** , consulte [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.