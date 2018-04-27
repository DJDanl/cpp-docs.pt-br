---
title: Enumerações &lt;memory&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- memory/std::pointer_safety
ms.assetid: b9be0a7b-0beb-40b2-8183-911de371c6b9
caps.latest.revision: 11
manager: ghogen
ms.openlocfilehash: 035175b2fea506fa341e260f042ae426e85421e4
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
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
