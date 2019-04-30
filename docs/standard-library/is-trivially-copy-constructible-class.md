---
title: Classe is_trivially_copy_constructible
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_trivially_copy_constructible
helpviewer_keywords:
- is_trivially_copy_constructible
ms.assetid: 4274cef5-afdd-4f2d-bc83-7562e7944ddf
ms.openlocfilehash: aa6d6b19ae2bd5d6967c57db61c5697c0c6153e9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62413431"
---
# <a name="istriviallycopyconstructible-class"></a>Classe is_trivially_copy_constructible

Testa se o tipo tem um construtor de cópia trivial.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_trivially_copy_constructible;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *T* é uma classe que tem um construtor de cópia trivial, caso contrário, será falsa.

Um construtor de cópia para uma classe *T* será trivial se ele é declarado implicitamente, a classe *T* não tem funções virtuais ou bases virtuais, todas as bases diretas da classe *T* ter construtores triviais de cópia, as classes de todos os membros de dados não estáticos do tipo de classe tiverem construtores triviais de cópia e as classes de todos os membros de dados não estáticos da matriz de tipo de classe tiverem construtores triviais de cópia.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
