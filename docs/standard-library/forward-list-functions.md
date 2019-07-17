---
title: Funções &lt;forward_list&gt;
ms.date: 11/04/2016
f1_keywords:
- forward_list/std::swap
ms.assetid: 0d6bc656-7049-4651-a4bd-c9a805e47756
ms.openlocfilehash: 78b1eaa44ed464de67d8ec45fab3241179bb94b9
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68240677"
---
# <a name="ltforwardlistgt-functions"></a>Funções &lt;forward_list&gt;

## <a name="swap"></a> troca

Troca os elementos de duas listas de encaminhamento.

```cpp
void swap(forward_list <Type, Allocator>& left, forward_list <Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

*À esquerda*\
Um objeto do tipo `forward_list`.

*Certo*\
Um objeto do tipo `forward_list`.

### <a name="remarks"></a>Comentários

Esta função de modelo executa `left.swap(right)`.
