---
title: Enumerações &lt;memory&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- memory/std::pointer_safety
ms.assetid: b9be0a7b-0beb-40b2-8183-911de371c6b9
ms.openlocfilehash: 9b9ea485bb66292c3c0509036c22dd161a694dd3
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38961404"
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
