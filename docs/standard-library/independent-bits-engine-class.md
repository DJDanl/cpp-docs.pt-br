---
title: Classe independent_bits_engine
ms.date: 11/04/2016
f1_keywords:
- random/std::independent_bits_engine
helpviewer_keywords:
- independent_bits_engine class
ms.assetid: 889e9a82-f457-49a7-9d2e-26e0fc3cd907
ms.openlocfilehash: f9c1c97795e6d4eeff64ba8be8f22602f4f3fbd6
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88845764"
---
# <a name="independent_bits_engine-class"></a>Classe independent_bits_engine

Gera uma sequência aleatória de números com um número especificado de bits, recompactando bits de valores retornados pelo mecanismo básico.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Engine, size_t W, class UIntType>
class independent_bits_engine;
```

### <a name="parameters"></a>parâmetros

*Motores*\
O tipo de mecanismo de base.

*Mostrar*\
**Tamanho da palavra**. Tamanho, em bits, de cada número gerado. **Pré-condição**: `0 < W ≤ numeric_limits<UIntType>::digits`

*UInttype*\
O tipo de resultado inteiro sem sinal. Para possíveis tipos, consulte [\<random>](../standard-library/random.md) .

## <a name="members"></a>Membros

`independent_bits_engine::independent_bits_engine`\
`independent_bits_engine::base`\
`independent_bits_engine::base_type`\
`independent_bits_engine::discard`\
`independent_bits_engine::operator()`\
`independent_bits_engine::seed`

Para obter mais informações sobre membros do mecanismo, consulte [\<random>](../standard-library/random.md) .

## <a name="remarks"></a>Comentários

Este modelo de classe descreve um *adaptador de mecanismo* que produz valores ao reempacotar bits de valores retornados por seu mecanismo base, resultando em valores de bit *W*.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<random>

**Namespace:** std

## <a name="see-also"></a>Confira também

[\<random>](../standard-library/random.md)
