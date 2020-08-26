---
title: Classe discard_block_engine
ms.date: 11/04/2016
f1_keywords:
- random/std::discard_block_engine
helpviewer_keywords:
- discard_block_engine class
ms.assetid: aa84808e-38fe-4fa0-9f73-d5b9a653345b
ms.openlocfilehash: 6f7b11c360f58e6a838b22fbf2c68366dce973a3
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88846284"
---
# <a name="discard_block_engine-class"></a>Classe discard_block_engine

Gera uma sequência aleatória descartando valores retornados pelo mecanismo de base.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Engine, size_t P, size_t R>
class discard_block_engine;
```

### <a name="parameters"></a>parâmetros

*Motores*\
O tipo de mecanismo de base.

*DTI*\
**Tamanho do bloco**. O número de valores em cada bloco.

*D*\
**Bloco usado**. O número de valores em cada bloco usado. O restante são descartados ( `P`  -  `R` ). **Pré-condição**: `0 < R ≤ P`

## <a name="members"></a>Membros

`discard_block_engine::discard_block_engine`\
`discard_block_engine::base`\
`discard_block_engine::base_type`\
`discard_block_engine::discard`\
`discard_block_engine::operator()`\
`discard_block_engine::seed`

Para obter mais informações sobre membros do mecanismo, consulte [\<random>](../standard-library/random.md) .

## <a name="remarks"></a>Comentários

Esse modelo de classe descreve um adaptador de mecanismo que produz valores descartando alguns dos valores retornados por seu mecanismo base.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<random>

**Namespace:** std

## <a name="see-also"></a>Confira também

[\<random>](../standard-library/random.md)
