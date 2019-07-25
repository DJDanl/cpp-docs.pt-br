---
title: Classe make_unsigned
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::make_unsigned
helpviewer_keywords:
- make_unsigned class
- make_unsigned
ms.assetid: 7a6a3c4f-1a4c-47e8-9ee2-ac1f7b669353
ms.openlocfilehash: 4c0224bd5fd7dc8c6589ae474bb9acb9a8f09cf6
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68456320"
---
# <a name="makeunsigned-class"></a>Classe make_unsigned

Cria o tipo ou o menor tipo sem sinal maior ou igual em tamanho ao tipo.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct make_unsigned;

template <class T>
using make_unsigned_t = typename make_unsigned<T>::type;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*T*|O tipo a ser modificado.|

## <a name="remarks"></a>Comentários

Uma instância do modificador de tipo contém um tipo modificado que é *T* se `is_unsigned<T>` for verdadeiro. Caso contrário, será o menor tipo com sinal `ST` para `sizeof (T) <= sizeof (ST)`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)
