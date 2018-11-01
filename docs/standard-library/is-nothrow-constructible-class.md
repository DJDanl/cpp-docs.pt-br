---
title: Classe is_nothrow_constructible
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_nothrow_constructible
helpviewer_keywords:
- is_nothrow_constructible
ms.assetid: 8be3f927-283e-4d67-95a5-8bf5dc4e7a3d
ms.openlocfilehash: 9ea11d54d49bf8f6ae6416f9663c2593cc66ea3e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50664120"
---
# <a name="isnothrowconstructible-class"></a>Classe is_nothrow_constructible

Testa se um tipo pode ser construído e não efetua lançamentos quando os tipos de argumento especificados são usados.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class... Args>
struct is_nothrow_constructible;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo a ser consultado.

*Args*<br/>
Os tipos de argumento para corresponder a um construtor *T*.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *T* é construível usando os tipos de argumento na *Args*e o construtor pelo compilador não efetua lançamentos; caso contrário, será falsa. Tipo de *T* pode ser construído se a definição da variável `T t(std::declval<Args>()...);` está bem formado. Ambos *T* e todos os tipos *Args* devem ser tipos completos, **void**, ou matrizes de limite desconhecido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
