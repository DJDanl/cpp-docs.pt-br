---
title: Classe discard_block_engine
ms.date: 11/04/2016
f1_keywords:
- random/std::discard_block_engine
helpviewer_keywords:
- discard_block_engine class
ms.assetid: aa84808e-38fe-4fa0-9f73-d5b9a653345b
ms.openlocfilehash: a0df754f53b52c134b9eb1126f90882ceaaf1e2f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386194"
---
# <a name="discardblockengine-class"></a>Classe discard_block_engine

Gera uma sequência aleatória descartando valores retornados pelo mecanismo de base.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Engine, size_t P, size_t R>
class discard_block_engine;
```

### <a name="parameters"></a>Parâmetros

*mecanismo*<br/>
O tipo de mecanismo de base.

*P*<br/>
**Tamanho do bloco**. O número de valores em cada bloco.

*R*<br/>
**Bloco usado**. O número de valores em cada bloco usado. O restante é descartado (`P` - `R`). **Pré-condição**: `0 < R ≤ P`

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
