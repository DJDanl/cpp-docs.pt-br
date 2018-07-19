---
title: Classe shuffle_order_engines | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- random/std::shuffle_order_engine
- random/std::shuffle_order_engine::base
- random/std::shuffle_order_engine::discard
- random/std::shuffle_order_engine::operator()
- random/std::shuffle_order_engine::base_type
- random/std::shuffle_order_engine::seed
dev_langs:
- C++
helpviewer_keywords:
- std::shuffle_order_engine [C++]
- std::shuffle_order_engine [C++], base
- std::shuffle_order_engine [C++], discard
- std::shuffle_order_engine [C++], base_type
- std::shuffle_order_engine [C++], seed
ms.assetid: 0bcd1fb0-44d7-4e59-bb1b-4a9b673a960d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 13b46bcd29624d696ae22494c394fa028d58fa8a
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38961968"
---
# <a name="shuffleorderengine-class"></a>Classe shuffle_order_engine

Gera uma sequência aleatória reordenando os valores retornados pelo mecanismo de base.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Engine, size_t K>
class shuffle_order_engine;
```

### <a name="parameters"></a>Parâmetros

*Mecanismo* o tipo de mecanismo de base.

*K* **tamanho da tabela**. Número de elementos no buffer (tabela). **Pré-condição**: `0 < K`

## <a name="members"></a>Membros

||||
|-|-|-|
|`shuffle_order_engine::shuffle_order_engine`|`shuffle_order_engine::base`|`shuffle_order_engine::discard`|
|`shuffle_order_engine::operator()`|`shuffle_order_engine::base_type`|`shuffle_order_engine::seed`|

Para obter mais informações sobre membros do mecanismo, consulte [\<random>](../standard-library/random.md).

## <a name="remarks"></a>Comentários

Essa classe de modelo descreve um *adaptador de mecanismo* que produz valores ao reorganizar os valores retornados por seu mecanismo básico. Cada construtor preenche a tabela interna com *K* valores retornados pelo mecanismo de base e um elemento aleatório é selecionado da tabela quando um valor é solicitado.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<random>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[\<random>](../standard-library/random.md)<br/>
