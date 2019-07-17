---
title: Classe de parallel_unsequenced_policy
ms.date: 04/18/2019
f1_keywords:
- execution/std::execution::parallel_unsequenced_policy
ms.openlocfilehash: 92b4e3ce3743fdd3d5ba112a333b2306829b95d4
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68268778"
---
# <a name="parallelunsequencedpolicy-class"></a>Classe de parallel_unsequenced_policy

Usado como um tipo exclusivo para resolver a ambiguidade de sobrecarga de algoritmo paralelo e indicam que a execução de um algoritmo paralelo pode ser colocados em paralelo e vetorizada.

## <a name="syntax"></a>Sintaxe

```cpp
class execution::parallel_unsequenced_policy;
```

## <a name="remarks"></a>Comentários

Durante a execução de um algoritmo paralelo com o `execution::parallel_unsequenced_policy` política, se a invocação de uma função de acesso de elemento sai por meio de uma exceção não percebida, `terminate()` deverá ser chamado.
