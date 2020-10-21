---
title: Funções &lt;forward_list&gt;
ms.date: 11/04/2016
f1_keywords:
- forward_list/std::swap
ms.assetid: 0d6bc656-7049-4651-a4bd-c9a805e47756
ms.openlocfilehash: 78b1eaa44ed464de67d8ec45fab3241179bb94b9
ms.sourcegitcommit: 19016630f9d35f365e9ba249e0f3617515d7ca33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/20/2020
ms.locfileid: "92274569"
---
# <a name="ltforward_listgt-functions"></a>Funções &lt;forward_list&gt;

## <a name="swap"></a><a name="swap"></a> permuta

Troca os elementos de duas listas de encaminhamento.

```cpp
void swap(forward_list <Type, Allocator>& left, forward_list <Type, Allocator>& right);
```

### <a name="parameters"></a>Parâmetros

*mantida*\
Um objeto do tipo `forward_list`.

*Certo*\
Um objeto do tipo `forward_list`.

### <a name="remarks"></a>Comentários

Esta função de modelo executa `left.swap(right)`.
