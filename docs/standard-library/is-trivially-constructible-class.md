---
title: Classe is_trivially_constructible
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_trivially_constructible
helpviewer_keywords:
- is_trivially_constructible
ms.assetid: 3fa918c1-e66f-4d0e-a11b-be1fb2c02e7b
ms.openlocfilehash: 6f177463b985d3e7b2f7ab7783f9c3db0dcd5722
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68448009"
---
# <a name="istriviallyconstructible-class"></a>Classe is_trivially_constructible

Testa se um tipo pode ser construído de forma trivial quando os tipos de argumento especificados são usados.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class... Args>
struct is_trivially_constructible;
```

### <a name="parameters"></a>Parâmetros

*T*\
O tipo a ser consultado.

*Argumento*\
Os tipos de argumento a serem correspondentes em um construtor de *T*.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo fica true se o tipo *T* é trivialmente constructible usando os tipos de argumento em *args*, caso contrário, ele mantém false. O tipo *T* é trivialmente constructible se a definição `T t(std::declval<Args>()...);` da variável é bem formada e é conhecida por não chamar nenhuma operação não trivial. Tanto *T* quanto todos os tipos em *args* devem ser tipos completos, **void**ou matrizes de associação desconhecida.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)
