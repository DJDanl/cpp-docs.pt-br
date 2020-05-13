---
title: Enumerações &lt;atomic&gt;
ms.date: 11/04/2016
f1_keywords:
- atomic/std::memory_order
ms.assetid: cd3a81c5-a19e-448f-952a-c34c717f21a9
helpviewer_keywords:
- std::memory_order
ms.openlocfilehash: f41c5b238f74e85bc18e9ff5c3aa6a0050fe27e1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376917"
---
# <a name="ltatomicgt-enums"></a>Enumerações &lt;atomic&gt;

## <a name="memory_order-enum"></a><a name="memory_order_enum"></a>memory_order Enum

Fornece nomes simbólicos para operações de sincronização em locais na memória. Essas operações afetam como atribuições em um thread se tornam visíveis em outro.

```cpp
typedef enum memory_order {
    memory_order_relaxed,
    memory_order_consume,
    memory_order_acquire,
    memory_order_release,
    memory_order_acq_rel,
    memory_order_seq_cst,
} memory_order;
```

### <a name="enumeration-members"></a>Membros da enumeração

|||
|-|-|
|`memory_order_relaxed`|Nenhuma ordenação é necessária.|
|`memory_order_consume`|Uma operação de carregar atua como uma operação de consumir no local da memória.|
|`memory_order_acquire`|Uma operação de carregar atua como uma operação de adquirir no local da memória.|
|`memory_order_release`|Uma operação de armazenar atua como uma operação de liberar no local da memória.|
|`memory_order_acq_rel`|Combina `memory_order_acquire` e `memory_order_release`.|
|`memory_order_seq_cst`|Combina `memory_order_acquire` e `memory_order_release`. Acessos à memória marcados como `memory_order_seq_cst` devem ser sequencialmente consistentes.|

## <a name="see-also"></a>Confira também

[\<>atômica](../standard-library/atomic.md)
