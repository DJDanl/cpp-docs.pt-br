---
title: Classe is_constructible
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_constructible
helpviewer_keywords:
- is_constructible
ms.assetid: 7cdec5ff-73cf-4f78-a9db-ced2e9c0fd7f
ms.openlocfilehash: dc0596ac7a3fc2bcbcbe49f5fa4b20a971e5e445
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68452856"
---
# <a name="isconstructible-class"></a>Classe is_constructible

Testa se um tipo pode ser construído quando os tipos de argumento especificados são usados.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class... Args>
struct is_constructible;
```

### <a name="parameters"></a>Parâmetros

*T*\
O tipo a ser consultado.

*Argumento*\
Os tipos de argumento a serem correspondentes em um construtor de *T*.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo se aplica true se o tipo *T* for constructible usando os tipos de argumento em *args*, caso contrário, será false. O tipo *T* será constructible se a definição `T t(std::declval<Args>()...);` da variável for bem formada. Tanto *T* quanto todos os tipos em *args* devem ser tipos completos, **void**ou matrizes de associação desconhecida.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)
