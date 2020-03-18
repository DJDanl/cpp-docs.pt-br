---
title: Classe sequenced_policy
ms.date: 04/18/2019
f1_keywords:
- execution/std::execution::sequenced_policy
ms.openlocfilehash: 5647f20b560828016231a9bbd38977c51211e6bb
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79444921"
---
# <a name="sequenced_policy-class"></a>Classe sequenced_policy

Usado como um tipo exclusivo para desambiguar a sobrecarga de algoritmo paralelo e exigir que a execução de um algoritmo paralelo não seja paralelizada.

## <a name="syntax"></a>Sintaxe

```cpp
class execution::sequenced_policy;
```

## <a name="remarks"></a>Comentários

Durante a execução de um algoritmo paralelo com a política de `execution::sequenced_policy`, se a invocação de uma função de acesso de elemento sair por meio de uma exceção não capturada, `terminate()` deverá ser chamado.
