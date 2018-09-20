---
title: 4.3 OMP_DYNAMIC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: a15edefb-1f85-4f06-a427-beb3cfc4434f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c15fa9d8c9d86b736bfc577a3b17e9809ec9baaf
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46439192"
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