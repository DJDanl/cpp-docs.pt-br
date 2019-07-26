---
title: Classe discard_block_engine
ms.date: 11/04/2016
f1_keywords:
- random/std::discard_block_engine
helpviewer_keywords:
- discard_block_engine class
ms.assetid: aa84808e-38fe-4fa0-9f73-d5b9a653345b
ms.openlocfilehash: 76a78a2f47bd160c6b2b981b1ccdda2ef3a90575
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68454390"
---
# <a name="discardblockengine-class"></a>Classe discard_block_engine

Gera uma sequência aleatória descartando valores retornados pelo mecanismo de base.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Engine, size_t P, size_t R>
class discard_block_engine;
```

### <a name="parameters"></a>Parâmetros

*Motores*\
O tipo de mecanismo de base.

*DTI*\
**Tamanho do bloco**. O número de valores em cada bloco.

*R*\
**Bloco usado**. O número de valores em cada bloco usado. O restante são descartados (`P` - `R`). **Pré-condição**: `0 < R ≤ P`

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

[\<random>](../standard-library/random.md)
