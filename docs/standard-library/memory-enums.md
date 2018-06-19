---
title: Enumerações &lt;memory&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- memory/std::pointer_safety
ms.assetid: b9be0a7b-0beb-40b2-8183-911de371c6b9
ms.openlocfilehash: 4d33cf941341f26c88f3a73c5a3d9ac0326db545
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33859261"
---
# <a name="ltmemorygt-enums"></a>Enumerações &lt;memory&gt;

||
|-|
|[pointer_safety](#pointer_safety)|

## <a name="pointer_safety"></a> Enumeração pointer_safety

A enumeração dos possíveis valores retornados por `get_pointer_safety`.

class pointer_safety { relaxed, preferred, strict };

### <a name="remarks"></a>Comentários

O `enum` de escopo define os valores que podem ser retornados por `get_pointer_safety()`:

`relaxed` – ponteiros não derivados de forma segura (obviamente ponteiros para objetos declarados ou alocados) são tratados da mesma maneira que os derivados de forma segura.

`preferred` – como antes, mas os ponteiros não derivados de forma segura não devem ser desreferenciados.

`strict` – os ponteiros não derivados de forma segura devem ser tratados de maneira diferente dos derivados de forma segura.

## <a name="see-also"></a>Consulte também

[\<memory>](../standard-library/memory.md)<br/>
