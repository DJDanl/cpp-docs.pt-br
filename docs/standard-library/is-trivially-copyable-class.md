---
title: Classe is_trivially_copyable
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_trivially_copyable
helpviewer_keywords:
- is_trivially_copyable
ms.assetid: 89a53bf8-036c-4108-91e1-fe34adbde8b3
ms.openlocfilehash: d3062ae311b63be76ba07185f4f8173afa4229cc
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68459756"
---
# <a name="istriviallycopyable-class"></a>Classe is_trivially_copyable

Testa se o tipo pode ser copiado de forma trivial.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_trivially_copyable;
```

### <a name="parameters"></a>Parâmetros

*T*\
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se manterá true se o tipo *T* for um tipo trivialmente copiável, caso contrário, será false. Tipos que podem ser copiados de forma trivial não têm operações de cópia não triviais, operações de movimentação ou destruidores. De modo geral, uma operação de cópia será considerada trivial se puder ser implementada como uma cópia bit a bit. Tipos internos e matrizes de tipos que podem ser copiados de forma trivial.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)
