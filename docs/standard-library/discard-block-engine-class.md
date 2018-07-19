---
title: Classe discard_block_engine | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- random/std::discard_block_engine
dev_langs:
- C++
helpviewer_keywords:
- discard_block_engine class
ms.assetid: aa84808e-38fe-4fa0-9f73-d5b9a653345b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1b65cfbe156ba462af9e87abf82d63023cfdc44b
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38957432"
---
# <a name="discardblockengine-class"></a>Classe discard_block_engine

Gera uma sequência aleatória descartando valores retornados pelo mecanismo de base.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Engine, size_t P, size_t R>
class discard_block_engine;
```

### <a name="parameters"></a>Parâmetros

*Mecanismo* o tipo de mecanismo de base.

*P* **tamanho do bloco**. O número de valores em cada bloco.

*R* **bloco usado**. O número de valores em cada bloco usado. O restante é descartado (`P` - `R`). **Pré-condição**: `0 < R ≤ P`

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
