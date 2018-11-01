---
title: Classe is_trivially_copyable
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_trivially_copyable
helpviewer_keywords:
- is_trivially_copyable
ms.assetid: 89a53bf8-036c-4108-91e1-fe34adbde8b3
ms.openlocfilehash: 181152bff1d7c2e4f97678b48310f744080822ce
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50554356"
---
# <a name="istriviallycopyable-class"></a>Classe is_trivially_copyable

Testa se o tipo pode ser copiado de forma trivial.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
struct is_trivially_copyable;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo a ser consultado.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *T* é um tipo facilmente copiado, de outra forma, será falsa. Tipos que podem ser copiados de forma trivial não têm operações de cópia não triviais, operações de movimentação ou destruidores. De modo geral, uma operação de cópia será considerada trivial se puder ser implementada como uma cópia bit a bit. Tipos internos e matrizes de tipos que podem ser copiados de forma trivial.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
