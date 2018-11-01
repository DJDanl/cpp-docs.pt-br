---
title: Classe is_trivially_constructible
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_trivially_constructible
helpviewer_keywords:
- is_trivially_constructible
ms.assetid: 3fa918c1-e66f-4d0e-a11b-be1fb2c02e7b
ms.openlocfilehash: c83bea8be5c88876ffa25337464caa62b998ab45
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50628833"
---
# <a name="istriviallyconstructible-class"></a>Classe is_trivially_constructible

Testa se um tipo pode ser construído de forma trivial quando os tipos de argumento especificados são usados.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class... Args>
struct is_trivially_constructible;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo a ser consultado.

*Args*<br/>
Os tipos de argumento para corresponder a um construtor *T*.

## <a name="remarks"></a>Comentários

Uma instância do predicado de tipo será verdadeira se o tipo *T* é trivialmente construível usando os tipos de argumento na *Args*, caso contrário, será falsa. Tipo de *T* trivialmente pode ser construído se a definição da variável `T t(std::declval<Args>()...);` está bem formado e é conhecido para chamar operações não triviais. Ambos *T* e todos os tipos *Args* devem ser tipos completos, **void**, ou matrizes de limite desconhecido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
