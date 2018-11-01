---
title: Enumerações &lt;memory&gt;
ms.date: 11/04/2016
f1_keywords:
- memory/std::pointer_safety
ms.assetid: b9be0a7b-0beb-40b2-8183-911de371c6b9
ms.openlocfilehash: 5c5f87905b772ef277a72ef11defef8cb1001661
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50494998"
---
# <a name="ltmemorygt-enums"></a>Enumerações &lt;memory&gt;

||
|-|
|[pointer_safety](#pointer_safety)|

## <a name="pointer_safety"></a> Enumeração pointer_safety

A enumeração dos possíveis valores retornados por `get_pointer_safety`.

class pointer_safety { relaxed, preferred, strict };

### <a name="remarks"></a>Comentários

Com escopo definido **enum** define os valores que podem ser retornados por `get_pointer_safety()`:

`relaxed` – ponteiros não derivados de forma segura (obviamente ponteiros para objetos declarados ou alocados) são tratados da mesma maneira que os derivados de forma segura.

`preferred` – como antes, mas os ponteiros não derivados de forma segura não devem ser desreferenciados.

`strict` – os ponteiros não derivados de forma segura devem ser tratados de maneira diferente dos derivados de forma segura.

## <a name="see-also"></a>Consulte também

[\<memory>](../standard-library/memory.md)<br/>
