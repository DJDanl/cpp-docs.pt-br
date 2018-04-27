---
title: Classe discard_block_engine | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- random/std::discard_block_engine
dev_langs:
- C++
helpviewer_keywords:
- discard_block_engine class
ms.assetid: aa84808e-38fe-4fa0-9f73-d5b9a653345b
caps.latest.revision: 18
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 59136111b6d4f594d84040c02270b219ad55ae0f
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="discardblockengine-class"></a>Classe discard_block_engine

Gera uma sequência aleatória descartando valores retornados pelo mecanismo de base.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Engine, size_t P, size_t R>
class discard_block_engine;
```

### <a name="parameters"></a>Parâmetros

`Engine` O tipo de mecanismo de base.

`P` **Tamanho do bloco**. O número de valores em cada bloco.

`R` **Bloco usado**. O número de valores em cada bloco usado. O restante é descartado (`P` - `R`). **Pré-condição**: `0 < R ≤ P`

## <a name="members"></a>Membros

||||
|-|-|-|
|`discard_block_engine::discard_block_engine`|`discard_block_engine::base`|`discard_block_engine::discard`|
|`discard_block_engine::operator()`|`discard_block_engine::base_type`|`discard_block_engine::seed`|

Para obter mais informações sobre membros do mecanismo, consulte [\<random>](../standard-library/random.md).

## <a name="remarks"></a>Comentários

Essa classe de modelo descreve um adaptador de mecanismo que produz valores descartando alguns dos valores retornados pelo mecanismo de base.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<random>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[\<random>](../standard-library/random.md)<br/>
