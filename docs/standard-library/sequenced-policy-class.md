---
title: Classe de sequenced_policy
ms.date: 04/18/2019
f1_keywords:
- execution/std::execution::parallel_policy
ms.openlocfilehash: 63be7166b84fa452f53baf6b6de16831eb657a23
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68269188"
---
# <a name="sequencedpolicy-class"></a>Classe de sequenced_policy

Usado como um tipo exclusivo para resolver a ambiguidade de sobrecarga de algoritmo paralelo e exigem a execução de um algoritmo paralelo não pode ser paralelizada.

## <a name="syntax"></a>Sintaxe

```cpp
class execution::sequenced_policy;
```

## <a name="remarks"></a>Comentários

Durante a execução de um algoritmo paralelo com o `execution::sequenced_policy` política, se a invocação de uma função de acesso de elemento sai por meio de uma exceção não percebida, `terminate()` deverá ser chamado.
