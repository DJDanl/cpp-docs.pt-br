---
title: Classe is_trivially_copy_constructible
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_trivially_copy_constructible
helpviewer_keywords:
- is_trivially_copy_constructible
ms.assetid: 4274cef5-afdd-4f2d-bc83-7562e7944ddf
ms.openlocfilehash: f8c4026da424e77b57555dd4c342c9ac7a386591
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68447985"
---
# <a name="istriviallycopyconstructible-class"></a>Classe is_trivially_copy_constructible

Testa se o tipo tem um construtor de cópia trivial.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_trivially_copy_constructible;
```

### <a name="parameters"></a>Parâmetros

*T*\
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se manterá true se o tipo *T* for uma classe que tem um construtor de cópia trivial, caso contrário, será false.

Um construtor de cópia para uma classe *t* é trivial se declarado implicitamente, a classe *t* não tem nenhuma função virtual ou base virtual, todas as bases diretas da classe *t* têm construtores de cópia trivial, as classes de todos os membros de dados não estáticos do tipo de classe têm construtores de cópia trivial, e as classes de todos os membros de dados não estáticos do tipo matriz de classe têm construtores de cópia trivial.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)
