---
title: Classe is_trivially_default_constructible
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_trivially_default_constructible
helpviewer_keywords:
- is_trivially_default_constructible
ms.assetid: 653ecd73-909f-4dd8-b95a-d1164d1c2da4
ms.openlocfilehash: 19a5e8afedf3e59d5dafa937af4f7d35343eb7d9
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68459648"
---
# <a name="istriviallydefaultconstructible-class"></a>Classe is_trivially_default_constructible

Testa se um tipo tem um construtor padrão trivial.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_trivially_default_constructible;
```

### <a name="parameters"></a>Parâmetros

*Ty*\
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se aplica true se o tipo *Ty* é uma classe que tem um Construtor trivial, caso contrário, ela mantém false.

Um construtor padrão para uma classe *Ty* é trivial se:

- for um construtor padrão declarado implicitamente

- a classe *Ty* não tem nenhuma função virtual

- a classe *Ty* não tem bases virtuais

- todas as bases diretas da classe *Ty* têm construtores triviais

- as classes de todos os membros de dados não estáticos do tipo de classe tiverem construtores triviais

- as classes de todos os membros de dados não estáticos da matriz de tipo de classe tiverem construtores triviais

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)
