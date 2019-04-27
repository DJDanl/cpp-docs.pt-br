---
title: Classe is_nothrow_default_constructible
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_nothrow_default_constructible
helpviewer_keywords:
- is_nothrow_default_constructible
ms.assetid: c576fcc9-5be1-43aa-b93a-64d3f1848887
ms.openlocfilehash: d635c8a06d3acc45d214dbe7cb1eb7800f56dc86
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62148478"
---
# <a name="isnothrowdefaultconstructible-class"></a>Classe is_nothrow_default_constructible

Testa se o tipo tem um construtor padrão que não efetua lançamentos.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_nothrow_default_constructible;
```

### <a name="parameters"></a>Parâmetros

*Ty*<br/>
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *Ty* tem um construtor padrão nothrow; caso contrário, será falsa. Uma instância do predicado de tipo é equivalente a `is_nothrow_constructible<Ty>`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
