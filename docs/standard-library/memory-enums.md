---
title: Enumerações &lt;memory&gt;
ms.date: 11/04/2016
f1_keywords:
- memory/std::pointer_safety
ms.assetid: b9be0a7b-0beb-40b2-8183-911de371c6b9
ms.openlocfilehash: 507628628fcf8bbf8993ce5beb1e02c28ff82147
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222245"
---
# <a name="ltmemorygt-enums"></a>Enumerações &lt;memory&gt;

## <a name="pointer_safety-enumeration"></a><a name="pointer_safety"></a>Enumeração de pointer_safety

A enumeração dos possíveis valores retornados por `get_pointer_safety`.

```cpp
class pointer_safety {
   relaxed,
   preferred,
   strict
};
```

### <a name="remarks"></a>Comentários

O escopo **`enum`** define os valores que podem ser retornados por `get_pointer_safety()` :

`relaxed` – ponteiros não derivados de forma segura (obviamente ponteiros para objetos declarados ou alocados) são tratados da mesma maneira que os derivados de forma segura.

`preferred` – como antes, mas os ponteiros não derivados de forma segura não devem ser desreferenciados.

`strict` – os ponteiros não derivados de forma segura devem ser tratados de maneira diferente dos derivados de forma segura.
