---
title: Enumerações &lt;atomic&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- atomic/std::memory_order
ms.assetid: cd3a81c5-a19e-448f-952a-c34c717f21a9
helpviewer_keywords:
- std::memory_order
ms.openlocfilehash: c30e7ca78533b0b4c2a4eb49bd99bd13483d2b8d
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="ltatomicgt-enums"></a>Enumerações &lt;atomic&gt;

## <a name="memory_order_enum"></a>  memory_order Enum

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

### <a name="enumeration-members"></a>Membros de enumeração

|||
|-|-|
|`memory_order_relaxed`|Nenhuma ordenação é necessária.|
|`memory_order_consume`|Uma operação de carregar atua como uma operação de consumir no local da memória.|
|`memory_order_acquire`|Uma operação de carregar atua como uma operação de adquirir no local da memória.|
|`memory_order_release`|Uma operação de armazenar atua como uma operação de liberar no local da memória.|
|`memory_order_acq_rel`|Combina `memory_order_acquire` e `memory_order_release`.|
|`memory_order_seq_cst`|Combina `memory_order_acquire` e `memory_order_release`. Acessos à memória marcados como `memory_order_seq_cst` devem ser sequencialmente consistentes.|

## <a name="see-also"></a>Consulte também

[\<atomic>](../standard-library/atomic.md)<br/>
