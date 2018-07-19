---
title: Classe independent_bits_engine | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- random/std::independent_bits_engine
dev_langs:
- C++
helpviewer_keywords:
- independent_bits_engine class
ms.assetid: 889e9a82-f457-49a7-9d2e-26e0fc3cd907
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f802dc91c3429ba718778d122d1a787aad0dec87
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38964217"
---
# <a name="independentbitsengine-class"></a>Classe independent_bits_engine

Gera uma sequência aleatória de números com um número especificado de bits, recompactando bits de valores retornados pelo mecanismo básico.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Engine, size_t W, class UIntType>
class independent_bits_engine;
```

### <a name="parameters"></a>Parâmetros

*Mecanismo* o tipo de mecanismo de base.

*W* **tamanho da palavra**. Tamanho, em bits, de cada número gerado. **Pré-condição**: `0 < W ≤ numeric_limits<UIntType>::digits`

*UIntType* o tipo de resultado de inteiro sem sinal. Para encontrar os tipos possíveis, consulte [\<random>](../standard-library/random.md).

## <a name="members"></a>Membros

||||
|-|-|-|
|`independent_bits_engine::independent_bits_engine`|`independent_bits_engine::base`|`independent_bits_engine::discard`|
|`independent_bits_engine::operator()`|`independent_bits_engine::base_type`|`independent_bits_engine::seed`|

Para obter mais informações sobre membros do mecanismo, consulte [\<random>](../standard-library/random.md).

## <a name="remarks"></a>Comentários

Essa classe de modelo descreve uma *adaptador de mecanismo* que produz valores recompactando bits dos valores retornados pelo mecanismo básico, resultando em *W*-valores de bit.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<random>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[\<random>](../standard-library/random.md)<br/>
