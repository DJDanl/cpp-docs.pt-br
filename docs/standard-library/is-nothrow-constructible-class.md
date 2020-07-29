---
title: Classe is_nothrow_constructible
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_nothrow_constructible
helpviewer_keywords:
- is_nothrow_constructible
ms.assetid: 8be3f927-283e-4d67-95a5-8bf5dc4e7a3d
ms.openlocfilehash: e52b16965d849f992731c4ff4254fd218b944269
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217747"
---
# <a name="is_nothrow_constructible-class"></a>Classe is_nothrow_constructible

Testa se um tipo pode ser construído e não efetua lançamentos quando os tipos de argumento especificados são usados.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class... Args>
struct is_nothrow_constructible;
```

### <a name="parameters"></a>parâmetros

*T*\
O tipo a ser consultado.

*Argumento*\
Os tipos de argumento a serem correspondentes em um construtor de *T*.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se aplica true se o tipo *T* for constructible usando os tipos de argumento em *args*, e o Construtor for conhecido pelo compilador para não gerar; caso contrário, ele conterá false. O tipo *T* será constructible se a definição da variável `T t(std::declval<Args>()...);` for bem formada. Tanto *T* quanto todos os tipos em *args* devem ser tipos completos, **`void`** ou matrizes de associação desconhecida.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<type_traits>

**Namespace:** std

## <a name="see-also"></a>Confira também

[<type_traits>](../standard-library/type-traits.md)
