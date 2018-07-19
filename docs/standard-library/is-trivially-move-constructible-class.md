---
title: Classe is_trivially_move_constructible | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- type_traits/std::is_trivially_move_constructible
dev_langs:
- C++
helpviewer_keywords:
- is_trivially_move_constructible
ms.assetid: 740bdec7-65e5-47b3-b94f-a2479ceac3ec
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 316ffdee4905ff8a35baef7137ff7f28a2846786
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38958186"
---
# <a name="istriviallymoveconstructible-class"></a>Classe is_trivially_move_constructible

Testa se o tipo tem construtor de movimentação trivial.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_trivially_move_constructible;
```

### <a name="parameters"></a>Parâmetros

*Ty* o tipo de consulta.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *Ty* é uma classe que tem um construtor de movimentação trivial caso contrário, será falsa.

Um construtor de movimentação de uma classe *Ty* é trivial se:

for implicitamente declarado

seus tipos de parâmetro forem equivalentes aos de uma declaração implícita

a classe *Ty* não tiver funções virtuais

a classe *Ty* não tiver bases virtuais

a classe não tiver membros de dados não estáticos voláteis

todas as bases diretas da classe *Ty* tiverem construtores de movimentação trivial

as classes de todos os membros de dados não estáticos do tipo de classe tiverem construtores de movimentação trivial

as classes de todos os membros de dados não estáticos da matriz de tipo de classe tiverem construtores de movimentação trivial

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
