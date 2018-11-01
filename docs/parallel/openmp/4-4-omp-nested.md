---
title: 4.4 OMP_NESTED
ms.date: 11/04/2016
ms.assetid: fd17b6f4-84e8-44c0-a96a-3a9e5ba33688
ms.openlocfilehash: e45b8901c56923ab37ca387a5f057c5b41af21f3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50453608"
---
# <a name="44-ompnested"></a>4.4 OMP_NESTED

O `OMP_NESTED` variável de ambiente habilita ou desabilita o paralelismo aninhado, a menos que o paralelismo aninhado está habilitado ou desabilitado chamando o `o` **mp_set_nested** rotina da biblioteca. Se definido como **verdadeira**, paralelismo aninhado está habilitado; se ele for definido como **FALSE**aninhada paralelismo está desativado. O valor padrão é **falsos**.

Exemplo:

```
setenv OMP_NESTED TRUE
```

## <a name="cross-reference"></a>Referência cruzada:

- `omp_set_nested` função, consulte [seção 3.1.9](../../parallel/openmp/3-1-9-omp-set-nested-function.md) na página de 40.